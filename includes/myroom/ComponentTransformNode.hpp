#ifndef MAGICVR_COMPONENTTRANSFORMNODE_HPP
#define MAGICVR_COMPONENTTRANSFORMNODE_HPP


#include <OpenSG/OSGBaseTypes.h>
#include <OpenSG/OSGQuaternion.h>
#include <OpenSG/OSGComponentTransform.h>
#include <OpenSG/OSGComponentTransformBase.h>
#include <OpenSG/OSGComponentTransformFields.h>

class ComponentTransformNode {
    OSG::ComponentTransformRecPtr _trans;
    OSG::NodeRecPtr _node;
public:
    ComponentTransformNode();

    ComponentTransformNode(OSG::ComponentTransformRecPtr _trans);

    ComponentTransformNode &translate(OSG::Real32 x, OSG::Real32 y, OSG::Real32 z);

    ComponentTransformNode &rotate(const OSG::QuaternionBase<OSG::Real32> &value);

    ComponentTransformNode &scale(OSG::Real32 s);

    ComponentTransformNode &scale(OSG::Real32 x, OSG::Real32 y, OSG::Real32 z);

    ComponentTransformNode &addChild(OSG::NodeTransitPtr child);

    ComponentTransformNode &addChild(OSG::NodeRecPtr child);

    ComponentTransformNode &removeChild(OSG::NodeTransitPtr child);

    ComponentTransformNode &removeChild(OSG::NodeRecPtr child);

    const OSG::NodeTransitPtr node() const;

    const OSG::ComponentTransformTransitPtr trans() const;

    ComponentTransformNode &translate(OSG::Vec3f vector);
};


#endif //MAGICVR_COMPONENTTRANSFORMNODE_HPP
