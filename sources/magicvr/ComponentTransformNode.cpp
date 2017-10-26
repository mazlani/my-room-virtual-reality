#include "magicvr/ComponentTransformNode.hpp"

ComponentTransformNode::ComponentTransformNode() : ComponentTransformNode(OSG::ComponentTransformBase::create()) {}

ComponentTransformNode::ComponentTransformNode(
        OSG::ComponentTransformRecPtr _trans) : _trans(_trans),
                                                      _node(OSG::makeNodeFor(
                                                              _trans)) {}

const OSG::NodeTransitPtr ComponentTransformNode::node() const {
    return OSG::NodeTransitPtr(_node);
}

const OSG::ComponentTransformTransitPtr ComponentTransformNode::trans() const {
    return OSG::ComponentTransformTransitPtr(_trans);
}

ComponentTransformNode &ComponentTransformNode::scale(OSG::Real32 s) {
    return scale(s, s, s);
}

ComponentTransformNode &ComponentTransformNode::scale(OSG::Real32 x, OSG::Real32 y, OSG::Real32 z) {
    trans()->setScale(OSG::Vec3f(x, y, z));
    return *this;
}

ComponentTransformNode &ComponentTransformNode::rotate(const OSG::QuaternionBase<OSG::Real32> &value) {
    trans()->setRotation(value);
    return *this;
}

ComponentTransformNode &ComponentTransformNode::translate(OSG::Vec3f vector) {
    trans()->setTranslation(vector);
    return *this;
}

ComponentTransformNode &ComponentTransformNode::translate(OSG::Real32 x, OSG::Real32 y, OSG::Real32 z) {
    return translate(OSG::Vec3f(x, y, z));
}

ComponentTransformNode &ComponentTransformNode::addChild(OSG::NodeTransitPtr child) {
    node()->addChild(child);
    return *this;
}

ComponentTransformNode &ComponentTransformNode::addChild(OSG::NodeRecPtr child) {
    node()->addChild(child);
    return *this;
}

ComponentTransformNode &ComponentTransformNode::removeChild(OSG::NodeTransitPtr child) {
    return removeChild(OSG::NodeRecPtr(child));
}

ComponentTransformNode &ComponentTransformNode::removeChild(OSG::NodeRecPtr child) {
    node()->subChild(child);
    return *this;
}
