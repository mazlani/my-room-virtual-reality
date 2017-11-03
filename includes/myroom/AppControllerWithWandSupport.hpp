#ifndef MYROOM_APPCONTROLLERWITHWANDSUPPORT_HPP
#define MYROOM_APPCONTROLLERWITHWANDSUPPORT_HPP


#include <myroom/node/MovableNode.hpp>
#include <myroom/node/TrajectoryContainerNode.hpp>
#include <input/RemoteManager.hpp>
#include <myroom/node/WandNode.hpp>
#include "AppController.hpp"

namespace myroom {
    class AppControllerWithWandSupport : public AppController {
        node::WandNode _wandNode;
        node::TrajectoryContainerNode _trajectoryNode;
        input::RemoteManager &_wand;
        std::string _selectedObjectName;

    public:
        explicit AppControllerWithWandSupport(input::RemoteManager &wand);

        void display(OSG::Time dTime) override;

        void keyboardDown(unsigned char key, int x, int y) override;

        void handleSelectObject();

        void selectObjectByName(std::string name);

        void moveSelectedObject(Time dTime);
    };
}

#endif //MYROOM_APPCONTROLLERWITHWANDSUPPORT_HPP
