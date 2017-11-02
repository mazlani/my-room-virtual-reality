#include "myroom/MyRoomDesktopGlutFramework.hpp"
#include <myroom/ComponentTransformNode.hpp>
#include <OpenSG/OSGGLUTWindow.h>
#include <myroom/background.hpp>

using namespace glutFramework;

int MyRoomDesktopGlutFramework::createWindow() {
    auto winid = GlutFramework::createWindow();
    OSG::GLUTWindowRecPtr gwin = OSG::GLUTWindowBase::create();
    gwin->setGlutId(winid);
    gwin->init();
    mgr = OSG::SimpleSceneManager::create();
    mgr->setWindow(gwin);
    mgr->setRoot(root());
    //mgr->showAll();
    mgr->setHeadlight(false);
    mgr->setBackground(loadBackground(SKYBOX_RES_1024)); // 256 | 512 | 1024 | 2048
    _navigator.simpleSceneManager(mgr);
    return winid;
}

OSG::Node *MyRoomDesktopGlutFramework::root() {
    return _root;
}

void MyRoomDesktopGlutFramework::keyboardDown(unsigned char key, int x, int y) {
    GlutFramework::keyboardDown(key, x, y);
    mgr->key(key, x, y);
    app.keyboardDown(key, x, y);
    _navigator.keyboardDown(key);
}

void MyRoomDesktopGlutFramework::keyboardUp(unsigned char key, int x, int y) {
    GlutFramework::keyboardUp(key, x, y);
    app.keyboardUp(key, x, y);
    _navigator.keyboardUp(key);
}

void MyRoomDesktopGlutFramework::mouseButtonPress(int button, int state, int x, int y) {
    // react to mouse button presses
    if (state) {
        mgr->mouseButtonRelease(button, x, y);
    } else {
        mgr->mouseButtonPress(button, x, y);
    }
    glutPostRedisplay();
}

void MyRoomDesktopGlutFramework::mouseMove(int x, int y) {
    mgr->mouseMove(x, y);
    glutPostRedisplay();
}

void MyRoomDesktopGlutFramework::display(OSG::Time dTime) {
    app.display(dTime);
    _navigator.update();
    commitChanges();
    mgr->idle();
    mgr->redraw();
    // the changelist should be cleared - else things could be copied multiple times
    OSG::Thread::getCurrentChangeList()->clear();
}

MyRoomDesktopGlutFramework::MyRoomDesktopGlutFramework(AppController &app)
        : app(app),
          _navigator(),
         _root(
                 ComponentTransformNode()
                         .addChild(app.root())
                         .translate(0, -170, -170)
                         .node()
         ){
    title("MyRoom");
}

void MyRoomDesktopGlutFramework::reshape(int width, int height) {
    mgr->resize(width, height);
}
