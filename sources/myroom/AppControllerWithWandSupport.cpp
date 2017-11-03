#include "myroom/AppControllerWithWandSupport.hpp"
#include <OpenSG/OSGSimpleGeometry.h>
#include <OpenSG/OSGSimpleTexturedMaterial.h>
#include <OpenSG/OSGSimpleTexturedMaterialBase.h>
#include <input/Tracker.hpp>
#include <OpenSG/OSGIntersectAction.h>

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
            OSG::Line l(_wand.wand.position, OSG::Vec3f(0, 0, -1)); // TODO

            OSG::IntersectActionRefPtr act = OSG::IntersectAction::create();

            act->setLine(l);
            act->apply(scene().movableObjects());

            if (act->didHit()) {
                std::cerr << " object " << act->getHitObject()
                          << " tri " << act->getHitTriangle()
                          << " at " << act->getHitPoint()
                          << std::endl;
            } else {
                std::cerr << "Nothing hit" << std::endl;
            }

            OSG::commitChanges();
        }
        _hasBeenSelectAction = _isSelectAction;
    }

}