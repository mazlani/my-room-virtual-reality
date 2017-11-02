//
// Created by vr2017 on 05.10.17.
//

#ifndef MYROOM_BEZIERTRANSLATIONANIMATION_HPP
#define MYROOM_BEZIERTRANSLATIONANIMATION_HPP

#include <OpenSG/OSGVector.h>
#include <OpenSG/OSGRefCountPtr.h>
#include <OpenSG/OSGComponentTransform.h>
#include <OpenSG/OSGTime.h>
#include <myroom/animation/FracTimeAnimation.hpp>
#include <myroom/animation/BezierCurve.hpp>

namespace myroom { namespace animation {

    class BezierTranslationAnimation : public FracTimeAnimation {

        const OSG::ComponentTransformRecPtr _trans;
        const BezierCurve<> _bezier;

    public:

        BezierTranslationAnimation(const OSG::ComponentTransformRecPtr trans,
                                   BezierCurve<> bezier,
                                   OSG::Time duration);

        void animateFracTime(OSG::Time fracTime) override;
    };

}}

#endif //MYROOM_BEZIERTRANSLATIONANIMATION_HPP
