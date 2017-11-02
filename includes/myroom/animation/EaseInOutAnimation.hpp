#ifndef MYROOM_EASEINOUTANIMATION_HPP
#define MYROOM_EASEINOUTANIMATION_HPP


#include "BezierAnimation.hpp"

class EaseInOutAnimation : public BezierAnimation {
public:
    EaseInOutAnimation(OSG::Time duration,
                       const std::shared_ptr<Animation> &animation);
};


#endif //MYROOM_EASEINOUTANIMATION_HPP
