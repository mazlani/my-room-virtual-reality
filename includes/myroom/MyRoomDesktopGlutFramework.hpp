#ifndef MYROOM_MYROOMDESKTOPGLUTFRAMEWORK_HPP
#define MYROOM_MYROOMDESKTOPGLUTFRAMEWORK_HPP

#include "GlutFramework.hpp"
#include <OpenSG/OSGSimpleSceneManager.h>
#include "AppController.hpp"
#include "SimpleSceneManagerNavigator.hpp"
#include <OpenSG/OSGTime.h>

class MyRoomDesktopGlutFramework : public glutFramework::GlutFramework {
    OSG::SimpleSceneManagerRefPtr mgr; // gets created in createWindow
    AppController &app;
    myroom::SimpleSceneManagerNavigator _navigator;
    const OSG::NodeRecPtr _root;

public:
    MyRoomDesktopGlutFramework(AppController &app);

    int createWindow() override;

    void keyboardDown(unsigned char key, int x, int y) override;

    OSG::Node *root();

    void mouseButtonPress(int button, int state, int x, int y) override;

    void mouseMove(int x, int y) override;

    void display(OSG::Time dTime) override;

    void reshape(int width, int height) override;

    void keyboardUp(unsigned char key, int x, int y) override;

};


#endif //MYROOM_MYROOMDESKTOPGLUTFRAMEWORK_HPP
