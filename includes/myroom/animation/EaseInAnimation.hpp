#ifndef MYROOM_EASEINANIMATION_HPP
#define MYROOM_EASEINANIMATION_HPP


#include "BezierAnimation.hpp"

class EaseInAnimation : public BezierAnimation {
public:
    EaseInAnimation(OSG::Time duration,
                    const std::shared_ptr<Animation> &animation);
};


#endif //MYROOM_EASEINANIMATION_HPP
