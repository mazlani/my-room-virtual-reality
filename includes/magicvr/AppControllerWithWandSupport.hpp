#ifndef MAGICVR_APPCONTROLLERWITHWANDSUPPORT_HPP
#define MAGICVR_APPCONTROLLERWITHWANDSUPPORT_HPP


#include <magicvr/node/MovableNode.hpp>
#include <magicvr/node/TrajectoryContainerNode.hpp>
#include <input/RemoteManager.hpp>
#include <magicvr/node/WandNode.hpp>
#include "AppController.hpp"

namespace magicvr {
    class AppControllerWithWandSupport : public AppController {
        node::WandNode _wandNode;
        node::TrajectoryContainerNode _trajectoryNode;
        input::RemoteManager &_wand;

    public:
        explicit AppControllerWithWandSupport(input::RemoteManager &wand);

        void display(OSG::Time dTime) override;

        void keyboardDown(unsigned char key, int x, int y) override;

    };
}

#endif //MAGICVR_APPCONTROLLERWITHWANDSUPPORT_HPP
