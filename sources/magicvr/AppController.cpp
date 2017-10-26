#include "magicvr/AppController.hpp"

void AppController::display(OSG::Time dTime) {
    _scene.update(dTime);
}

void AppController::keyboardDown(unsigned char key, int x, int y) {
}

const NodeRecPtr &AppController::root() const {
    return _scene.root();
}

void AppController::keyboardUp(unsigned char key, int x, int y) {
}

Scene &AppController::scene() {
    return _scene;
}
