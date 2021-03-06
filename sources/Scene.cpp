#include "Scene.hpp"
#include <OpenSG/OSGSceneFileHandler.h>
#include <OpenSG/OSGQuaternion.h>
#include <OpenSG/OSGVector.h>
#include <OpenSG/OSGMaterialGroup.h>
#include <OpenSG/OSGImage.h>
#include <OpenSG/OSGSimpleTexturedMaterial.h>
#include <OpenSG/OSGSimpleGeometry.h>
#include <myroom/ComponentTransformNode.hpp>
#include <PathSettings.hpp>
#include <OpenSG/OSGPointLight.h>
#include <OpenSG/OSGSpotLight.h>
#include <OpenSG/OSGSceneFileHandler.h>
#include <OpenSG/OSGNameAttachment.h>

void Scene::build() {

    PointLightRecPtr pLight = PointLight::create();
    NodeRecPtr pLightTransformNode = Node::create();
    TransformRecPtr pLightTransform = Transform::create();
    NodeRecPtr pLightNode = Node::create();

    pLightNode->setCore(Group::create());

    Matrix m;
    m.setIdentity();
    m.setTranslate(10, 10, 10);

    pLightTransform->setMatrix(m);

    //we add a little sphere that will represent the light source
    GeometryRecPtr sphere = makeSphereGeo(0.5, 0.5);
    SimpleMaterialRecPtr sm = SimpleMaterial::create();

    sm->setLit(false);
    sm->setDiffuse(Color3f(1, 1, 1));

    sphere->setMaterial(sm);

    NodeRecPtr sphereNode = Node::create();
    sphereNode->setCore(sphere);

    pLightTransformNode->setCore(pLightTransform);
    pLightTransformNode->addChild(pLightNode);
    pLightTransformNode->addChild(sphereNode);

    pLight->setPosition(Pnt3f(0, 270 / 2, 0));

    //Attenuation parameters
    pLight->setConstantAttenuation(1);
    pLight->setLinearAttenuation(0);
    pLight->setQuadraticAttenuation(0);

    //color information
    pLight->setDiffuse(Color4f(1, 1, 1, 1));
    pLight->setAmbient(Color4f(0.2, 0.2, 0.2, 1));
    pLight->setSpecular(Color4f(1, 1, 1, 1));

    //set the beacon
    pLight->setBeacon(pLightNode);
    root()->setCore(pLight);

    buildRoom(root());
    root()->addChild(pLightTransformNode);
    root()->addChild(_movableObjects.node());
    root()->addChild(
            ComponentTransformNode()
                    .scale(120)
                    .translate(-20,0,0)
                    .addChild(OSG::SceneFileHandler::the()->read(Path_Model_TableNew))
                    .node()
    );
    root()->addChild(
            ComponentTransformNode()
                    .addChild(
                            ComponentTransformNode()
                                    .scale(0.07)
                                    .addChild(OSG::SceneFileHandler::the()->read(Path_Model_Chair))
                                    .node()
                    )
                    .translate(-20, 45, 0)
                    .rotate(OSG::Quaternion(OSG::Vec3f(0, 0, -1), OSG::Vec3f(-1, 0, 0)))
                    .node()
    );

    const NodeRecPtr coffeeModel = OSG::SceneFileHandler::the()->read(Path_Model_Coffee);
    _coffeeCup
            .scale(3)
            .translate(10,85.5,-60)
            .addChild(coffeeModel);
    _movableObjects.addChild(_coffeeCup.node());
    OSG::setName(OSG::NodeRecPtr(_coffeeCup.node()), "CoffeeCup");

/*    _movableObjects.addChild(
            ComponentTransformNode()
                    .addChild(
                            ComponentTransformNode()
                                    .scale(9)
                                    .addChild(OSG::SceneFileHandler::the()->read(Path_Model_Laptop))
                                    .node()
                    )
                    .translate(10,85,-30)
                    .rotate(OSG::Quaternion(OSG::Vec3f(-1, 0, 0), OSG::Vec3f(0, 0, -1)))
                    .node()
    );*/

    _laptop
            .addChild(
                    ComponentTransformNode()
                            .scale(9)
                            .addChild(OSG::SceneFileHandler::the()->read(Path_Model_Laptop))
                            .node()
            )
            .translate(10,85,-30)
            .rotate(OSG::Quaternion(OSG::Vec3f(-1, 0, 0), OSG::Vec3f(0, 0, -1)))
            .node();
    OSG::setName(OSG::NodeRecPtr(_laptop.node()), "Laptop");
    _movableObjects.addChild(_laptop.node());

    root()->addChild(
            ComponentTransformNode()
                    .scale(0.7)
                    .translate(10,160,-132)
                    .addChild(OSG::SceneFileHandler::the()->read(Path_Model_Clock))
                    .node()
    );

    _coffeeMachine
            .addChild(
                    ComponentTransformNode()
                            .scale(13)
                            .addChild(OSG::SceneFileHandler::the()->read(Path_Model_CoffeeMachine))
                            .node()
            )
            .translate(60,85.3,-60)
            .rotate(OSG::Quaternion(OSG::Vec3f(-1, 0, 0), OSG::Vec3f(0, 0, -1)));
    OSG::setName(OSG::NodeRecPtr(_coffeeMachine.node()), "CoffeeMachine");
    _movableObjects.addChild(_coffeeMachine.node());
}

void Scene::buildRoom(NodeRecPtr parent) {
    const auto size = 270;
    // single box
//    parent->addChild(
//            ComponentTransformNode()
//                    .addChild(OSG::makeBox(size, size, size, true, true, true))
//                    .translate(0, size / 2, 0)
//                    .node()
//    );
    // add multiple boxes as walls of room
    parent->addChild(
            ComponentTransformNode()
                    .addChild(makeBox(size, size, size, true, true, true))
                    .translate(0, size / 2, -size)
                    .node()
    );
    parent->addChild(
            ComponentTransformNode()
                    .addChild(makeBox(size, size, size, true, true, true))
                    .translate(-size, size / 2, 0)
                    .node()
    );
    parent->addChild(
            ComponentTransformNode()
                    .addChild(makeBox(size, size, size, true, true, true))
                    .translate(size, size / 2, 0)
                    .node()
    );
    parent->addChild(
            ComponentTransformNode()
                    .addChild(makeBox(size, size, size, true, true, true))
                    .translate(0, -size / 2, 0)
                    .node()
    );
    parent->addChild(
            ComponentTransformNode()
                    .addChild(makeBox(size, size, size, true, true, true))
                    .translate(0, size + size / 2, 0)
                    .node()
    );
}

void Scene::update(OSG::Time dTime) {
}

Scene::Scene()
        : _root(makeNodeFor(Group::create())) {
    build();
    update(0);
}

const NodeRecPtr &Scene::root() const {
    return _root;
}

const NodeRecPtr Scene::movableObjects() const {
    return _movableObjects.node();
}
