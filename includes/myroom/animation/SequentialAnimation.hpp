#ifndef MYROOM_SEQUENTIALANIMATION_HPP
#define MYROOM_SEQUENTIALANIMATION_HPP


#include <myroom/animation/Animation.hpp>
#include <memory>
#include <queue>

class SequentialAnimation : public Animation {
    std::queue<std::shared_ptr<Animation>> _animations;
    const bool _stopIfNoAnimations;
public:
    static const bool STOP_IF_NO_ANIMATIONS = true;
    static const bool DO_NOT_STOP_IF_NO_ANIMATIONS = false;
    static const bool STOP_IF_NO_ANIMATIONS_DEFAULT = STOP_IF_NO_ANIMATIONS;

    SequentialAnimation();

    SequentialAnimation(bool stopIfNoAnimations);

    SequentialAnimation(bool stopIfNoAnimations,
                      std::initializer_list<std::shared_ptr<Animation>> animations);

    SequentialAnimation(
            std::initializer_list<std::shared_ptr<Animation>> animations);

    void add(std::shared_ptr<Animation> animation);

    void animate(OSG::Time dTime) override;
};


#endif //MYROOM_SEQUENTIALANIMATION_HPP
