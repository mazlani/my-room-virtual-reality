#ifndef MYROOM_EASEOUTANIMATION_HPP
#define MYROOM_EASEOUTANIMATION_HPP


#include "BezierAnimation.hpp"

class EaseOutAnimation : public BezierAnimation {
public:
    EaseOutAnimation(OSG::Time duration,
                     const std::shared_ptr<Animation> &animation);
};

#endif //MYROOM_EASEOUTANIMATION_HPP
