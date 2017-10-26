#include "Scene.hpp"
#include <OpenSG/OSGSceneFileHandler.h>
#include <OpenSG/OSGMaterialGroup.h>
#include <OpenSG/OSGImage.h>
#include <OpenSG/OSGSimpleTexturedMaterial.h>
#include <OpenSG/OSGSimpleGeometry.h>
#include <magicvr/ComponentTransformNode.hpp>

void Scene::build() {
    root()->addChild(
            ComponentTransformNode()
                    .addChild(OSG::makeBox(10, 10, 10, true, true, true))
                    .translate(10, 0, -10)
                    .node()
    );
    root()->addChild(
            ComponentTransformNode()
                    .addChild(OSG::makeBox(10, 10, 10, true, true, true))
                    .translate(-10, 0, -10)
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
