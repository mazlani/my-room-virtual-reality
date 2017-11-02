#ifndef MYROOM_UTIL_COLOR_HPP
#define MYROOM_UTIL_COLOR_HPP

#include <OpenSG/OSGBaseTypes.h>
#include <OpenSG/OSGSimpleMaterial.h>

namespace myroom { namespace util {
    OSG::SimpleMaterialTransitPtr
    materialColor(const OSG::Real32 red,
                  const OSG::Real32 green,
                  const OSG::Real32 blue,
                  const OSG::Real32 transparency = 0);

    OSG::SimpleMaterialTransitPtr
    defaultMaterialColor();
}}

#endif //TUTORIALS_COLOR_HPP
