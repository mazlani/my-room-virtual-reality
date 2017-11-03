#include "myroom/AppControllerWithWandSupport.hpp"
#include <OpenSG/OSGSimpleGeometry.h>
#include <OpenSG/OSGSimpleTexturedMaterial.h>
#include <OpenSG/OSGSimpleTexturedMaterialBase.h>
#include <input/Tracker.hpp>
#include <OpenSG/OSGIntersectAction.h>
#include <OpenSG/OSGNameAttachment.h>

namespace myroom {
    AppControllerWithWandSupport::AppControllerWithWandSupport(
            input::RemoteManager &wand)
            : _wand(wand) {
        root()->addChild(_wandNode.node().node());
        root()->addChild(_trajectoryNode.node());
    }


    void AppControllerWithWandSupport::display(OSG::Time dTime) {
        static auto lastWandPosition = _wand.wand.position;
        static bool _hasBeenRecordingTrajectory = false;
        const bool _isRecordingTrajectory = _wand.buttons[input::RemoteManager::BACK];
        if (lastWandPosition != _wand.wand.position) {
            lastWandPosition = _wand.wand.position;
            _wandNode.node().translate(_wand.wand.position);
            if (_isRecordingTrajectory) {
                _trajectoryNode.add(_wand.wand.position);
            } else if (_hasBeenRecordingTrajectory) {
                _trajectoryNode.clear();
            }
        }
        handleSelectObject();
        moveSelectedObject(dTime);
        AppController::display(dTime);
        _hasBeenRecordingTrajectory = _isRecordingTrajectory;
    }

    void AppControllerWithWandSupport::keyboardDown(unsigned char key, int x,
                                                    int y) {
        AppController::keyboardDown(key, x, y);
    }

    void AppControllerWithWandSupport::handleSelectObject() {
        static bool _hasBeenSelectAction = false;
        const bool _isSelectAction = _wand.buttons[input::RemoteManager::MIDDLE];
        if (!_hasBeenSelectAction && _isSelectAction) {
            OSG::Vec3f wandDirection(0, 0, -1);
            _wand.wand.orientation.multVec(wandDirection, wandDirection);
            std::cout << "wand direction: " << wandDirection << std::endl;
            OSG::Line l(_wand.wand.position, wandDirection);

            OSG::IntersectActionRefPtr act = OSG::IntersectAction::create();

            act->setLine(l);
            act->apply(scene().movableObjects());

            if (act->didHit()) {
                const auto hitObject = act->getHitObject();
                const auto hitObjectName = OSG::getName(hitObject);
                std::cerr << " object " << hitObject
                          << " tri " << act->getHitTriangle()
                          << " at " << act->getHitPoint()
                          << " name " << (hitObjectName == nullptr ? "unknown" : hitObjectName)
                          << " core-type " << hitObject->getCore()->getTypeName()
                          << std::endl;
                OSG::NodeRecPtr current = hitObject;
                while (current != nullptr) {
                    std::cout << "traverse parents: type=" << current->getTypeName()
                              << " name=" << (OSG::getName(current) == nullptr ? "unknown" : OSG::getName(current))
                              << std::endl;
                    if (OSG::getName(current) != nullptr) {
                        selectObjectByName(OSG::getName(current));
                    }
                    current = current->getParent();
                }
            } else {
                std::cerr << "Nothing hit" << std::endl;
            }

            OSG::commitChanges();
        }
        _hasBeenSelectAction = _isSelectAction;
    }

    void AppControllerWithWandSupport::selectObjectByName(std::string name) {
        _selectedObjectName = name;
    }

    void AppControllerWithWandSupport::moveSelectedObject(Time dTime) {
        if (_selectedObjectName == "CoffeeMachine") {
            const auto oldPos = scene()._coffeeMachine.trans()->getTranslation();
            scene()._coffeeMachine.translate(oldPos + _wand.analog_values);
        } else if (_selectedObjectName == "CoffeeCup") {
            const auto oldPos = scene()._coffeeCup.trans()->getTranslation();
            scene()._coffeeCup.translate(oldPos + _wand.analog_values);
        }
    }

}