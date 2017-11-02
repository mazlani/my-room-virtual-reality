#include "Scene.hpp"
#include <OpenSG/OSGSceneFileHandler.h>
#include <OpenSG/OSGMaterialGroup.h>
#include <OpenSG/OSGImage.h>
#include <OpenSG/OSGSimpleTexturedMaterial.h>
#include <OpenSG/OSGSimpleGeometry.h>
#include <magicvr/ComponentTransformNode.hpp>
#include <PathSettings.hpp>
#include <OpenSG/OSGPointLight.h>
#include <OpenSG/OSGSpotLight.h>
#include <OpenSG/OSGSceneFileHandler.h>

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
    root()->addChild(
            ComponentTransformNode()
                    .scale(140)
                    .addChild(OSG::SceneFileHandler::the()->read(Path_Model_TableNew))
                    .node()
    );
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
