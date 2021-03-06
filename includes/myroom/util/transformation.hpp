#ifndef MYROOM_UTIL_TRANSFORMATION_HPP
#define MYROOM_UTIL_TRANSFORMATION_HPP

#include <OpenSG/OSGNode.h>

namespace myroom { namespace util {
    OSG::NodeTransitPtr
    translateNode(const OSG::NodeRecPtr node, const OSG::Vec3f translation);
}}

#endif //TUTORIALS_TRANSFORMATION_HPP
