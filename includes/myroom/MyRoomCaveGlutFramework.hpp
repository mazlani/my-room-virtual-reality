#ifndef MYPROJECT_MYROOMGLUTFRAMEWORK_HPP
#define MYPROJECT_MYROOMGLUTFRAMEWORK_HPP

#include <OSGCSM/OSGCAVESceneManager.h>
#include <OpenSG/OSGTime.h>
#include "AppController.hpp"
#include "GlutFramework.hpp"
#include "input/RemoteManager.hpp"

class MyRoomCaveGlutFramework : public glutFramework::GlutFramework {
    OSGCSM::CAVEConfig &cfg;

    OSGCSM::CAVESceneManager &mgr;

    input::RemoteManager &remoteManager;

    AppController &app;

    // head light fix (1/3)
    DirectionalLightRecPtr mainLight;

    int createWindow() override;

    void clearControlWindow() const;

public:
    MyRoomCaveGlutFramework(OSGCSM::CAVEConfig &cfg, OSGCSM::CAVESceneManager &mgr,
                         input::RemoteManager &remoteManager, AppController &app,
                         DirectionalLightRecPtr mainLight);

    void keyboardDown(unsigned char key, int x, int y) override;

    void idle() override;

    void reshape(int width, int height) override;

    void display(OSG::Time dTime) override;
};


#endif //MYPROJECT_MYROOMGLUTFRAMEWORK_HPP
