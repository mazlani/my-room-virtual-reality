#include <myroom/ExitGlut.hpp>
#include "myroom/MyRoomCaveGlutFramework.hpp"

void MyRoomCaveGlutFramework::keyboardDown(unsigned char key, int x, int y) {
    glutFramework::GlutFramework::keyboardDown(key, x, y);
    app.keyboardDown(key, x, y);
    Real32 ed;
    switch (key) {
        case 'q':
        case 27:
            throw ExitGlut();
        case 'e':
            ed = mgr.getEyeSeparation() * .9f;
            std::cout << "Eye distance: " << ed << '\n';
            mgr.setEyeSeparation(ed);
            break;
        case 'E':
            ed = mgr.getEyeSeparation() * 1.1f;
            std::cout << "Eye distance: " << ed << '\n';
            mgr.setEyeSeparation(ed);
            break;
        case 'h':
            cfg.setFollowHead(!cfg.getFollowHead());
            std::cout << "following head: " << std::boolalpha << cfg.getFollowHead() << '\n';
            break;
        case 'i':
            remoteManager.print_tracker();
            break;
        default:
            std::cout << "Key '" << key << "' ignored\n";
    }
}

MyRoomCaveGlutFramework::MyRoomCaveGlutFramework(OSGCSM::CAVEConfig &cfg, OSGCSM::CAVESceneManager &mgr,
                                           input::RemoteManager &remoteManager, AppController &app,
                                           DirectionalLightRecPtr mainLight)
        : cfg(cfg), mgr(mgr), remoteManager(remoteManager),
          app(app), mainLight(mainLight) {
    title("MyRoom Control Window");
}

void MyRoomCaveGlutFramework::reshape(int width, int height) {
    mgr.resize(width, height);
    clearControlWindow();
}

void MyRoomCaveGlutFramework::idle() {
    glutFramework::GlutFramework::idle();
    remoteManager.check_tracker();

    const auto speed = 1.f;
    auto head = remoteManager.head;
    mgr.setUserTransform(head.position, head.orientation);
    mgr.setTranslation(mgr.getTranslation() + speed * remoteManager.analog_values);

    // head light fix (2/3)
//    Matrix4f mat;
//    mat.setRotate(head.orientation);
//    auto dir = mat * Vec3f(0.f, 0.f, 1.f);
//    mainLight->setDirection(dir);

    commitChanges();
    mgr.redraw();
    // the changelist should be cleared - else things could be copied multiple times
    OSG::Thread::getCurrentChangeList()->clear();
}

void MyRoomCaveGlutFramework::display(OSG::Time dTime) {
    app.display(dTime);
    commitChanges();
    mgr.idle();
    mgr.redraw();
    // the changelist should be cleared - else things could be copied multiple times
    OSG::Thread::getCurrentChangeList()->clear();
}

int MyRoomCaveGlutFramework::createWindow() {
    const auto windowId = glutFramework::GlutFramework::createWindow();
    clearControlWindow();
    return windowId;
}

void MyRoomCaveGlutFramework::clearControlWindow() const {
    glClearColor(0.0, 0.0, 0.0, 1.0);
    glClear(GL_COLOR_BUFFER_BIT);
    glutSwapBuffers();
}
