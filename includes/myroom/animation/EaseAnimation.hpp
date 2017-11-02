#ifndef MYROOM_EASEANIMATION_HPP
#define MYROOM_EASEANIMATION_HPP


#include "BezierAnimation.hpp"

class EaseAnimation : public BezierAnimation {
public:
    EaseAnimation(OSG::Time duration,
                  const std::shared_ptr<Animation> &animation);
};


#endif //MYROOM_EASEANIMATION_HPP
