#pragma once

#include <OpenSG/OSGVector.h>
#include <OpenSG/OSGRefCountPtr.h>
#include <OpenSG/OSGComponentTransform.h>
#include <OpenSG/OSGTime.h>
#include <myroom/animation/FracTimeAnimation.hpp>
#include <myroom/animation/BezierCurve.hpp>
#include <myroom/ComponentTransformNode.hpp>
#include "BezierTranslationAnimation.hpp"
#include "AnimationNode.hpp"

namespace myroom { namespace animation {

    class BezierTranslationAnimationNode
            : public BezierTranslationAnimation, public AnimationNode {
        ComponentTransformNode _ctNode;

    public:

        BezierTranslationAnimationNode(ComponentTransformNode ctNode,
                                   BezierCurve<> bezier,
                                   OSG::Time duration);

        OSG::NodeRecPtr node() override;

        const OSG::NodeRecPtr node() const override;

        Animation &animation() override;
    };

}}
