#ifndef MYROOM_ANIMATIONCONTAINER_HPP
#define MYROOM_ANIMATIONCONTAINER_HPP


#include "Animation.hpp"

class AnimationContainer : public Animation {
protected:
    Animation & _animation;
public:
    AnimationContainer(Animation &_animation);

    void animate(OSG::Time dTime) override;

    void stop() override;
};


#endif //MYROOM_ANIMATIONCONTAINER_HPP
