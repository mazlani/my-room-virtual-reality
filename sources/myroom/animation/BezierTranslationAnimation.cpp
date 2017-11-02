//
// Created by vr2017 on 05.10.17.
//

#include "myroom/animation/BezierTranslationAnimation.hpp"

namespace myroom { namespace animation {

    void BezierTranslationAnimation::animateFracTime(OSG::Time fracTime) {
        _trans->setTranslation(_bezier.atPercentage(fracTime));


    }

    BezierTranslationAnimation::BezierTranslationAnimation(
            const OSG::ComponentTransformRecPtr trans, BezierCurve<> bezier,
            OSG::Time duration) : FracTimeAnimation(duration, false),
                                  _trans(trans), _bezier(bezier) {}

}}
