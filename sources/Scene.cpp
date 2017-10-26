#include "Scene.hpp"
#include <OpenSG/OSGSceneFileHandler.h>
#include <OpenSG/OSGMaterialGroup.h>
#include <OpenSG/OSGImage.h>
#include <OpenSG/OSGSimpleTexturedMaterial.h>
#include <OpenSG/OSGSimpleGeometry.h>

void Scene::build() {
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
