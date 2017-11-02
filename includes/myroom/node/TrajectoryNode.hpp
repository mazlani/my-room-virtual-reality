#ifndef MYROOM_NODE_TRAJECTORY_NODE_HPP
#define MYROOM_NODE_TRAJECTORY_NODE_HPP

#include <OpenSG/OSGBaseTypes.h>
#include <OpenSG/OSGNode.h>

namespace myroom { namespace node {

    class TrajectoryNode {
    public:
        void add(const OSG::Vec3f &point);

        void clear();

        OSG::NodeTransitPtr node();

    private:
        OSG::NodeRecPtr _node;
        OSG::Vec3f _previousPoint;
    };

}}

#endif //MYROOM_NODE_TRAJECTORY_NODE_HPP
