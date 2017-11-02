#ifndef MYROOM_SPIRAL_HPP
#define MYROOM_SPIRAL_HPP

#include <vector>
#include <OpenSG/OSGVector.h>


class Spiral {
public:
    std::vector<OSG::Vec3f> sample() const;
};


#endif //MYROOM_SPIRAL_HPP
