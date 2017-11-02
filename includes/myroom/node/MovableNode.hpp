#ifndef MYROOM_NODE_MOVABLE_NODE_HPP
#define MYROOM_NODE_MOVABLE_NODE_HPP

#include <OpenSG/OSGComponentTransform.h>
#include <OpenSG/OSGNode.h>

namespace myroom { namespace node {

    class MovableNode {
    public:
        OSG::NodeTransitPtr node();
        OSG::NodeTransitPtr node(const OSG::NodeRecPtr);

        void moveTo(const OSG::Vec3f &newPosition);

    protected:
        OSG::NodeTransitPtr defaultChild();;

    private:
        OSG::ComponentTransformRecPtr _transformer;
        OSG::NodeRecPtr _node;
    };

}}

#endif //MYROOM_NODE_MOVABLE_NODE_HPP
