#include "myroom/animation/SharedRefAnimationContainer.hpp"

namespace myroom { namespace animation {

    SharedRefAnimationContainer::SharedRefAnimationContainer(
            std::shared_ptr<Animation> _animation)
            : _animation(_animation) {}

    void SharedRefAnimationContainer::animate(OSG::Time dTime) {
        _animation->animate(dTime);
        if (_animation->isStopped()) {
            stop();
        }
    }

    void SharedRefAnimationContainer::stop() {
        Animation::stop();
        _animation->stop();
    }

}}
