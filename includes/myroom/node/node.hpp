#ifndef MAGICVR_NODE_NODE_HPP
#define MAGICVR_NODE_NODE_HPP

#include <iterator>

#include <OpenSG/OSGBaseTypes.h>
#include <OpenSG/OSGComponentTransform.h>
#include <OpenSG/OSGGroup.h>
#include <OpenSG/OSGNode.h>
#include <OpenSG/OSGMaterial.h>
#include <myroom/util/color.hpp>


namespace myroom { namespace node {
    OSG::NodeTransitPtr
    pointNode(const OSG::Vec3f &pos,
              const OSG::Real32 size = 1,
              const OSG::MaterialRecPtr material = myroom::util::defaultMaterialColor());

    OSG::NodeTransitPtr
    lineNode(const OSG::Vec3f &start,
             const OSG::Vec3f &end,
             const OSG::Real32 size = 1,
             const OSG::MaterialRecPtr material = myroom::util::defaultMaterialColor());

    OSG::NodeTransitPtr
    segmentNode(const OSG::Vec3f &start,
                const OSG::Vec3f &end,
                const OSG::Real32 size = 1,
                const OSG::MaterialRecPtr material = myroom::util::defaultMaterialColor());
}}

#endif //MAGICVR_NODE_NODE_HPP
