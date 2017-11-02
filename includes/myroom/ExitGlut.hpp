#ifndef MYROOM_EXITGLUT_HPP
#define MYROOM_EXITGLUT_HPP

#include <stdexcept>

/**
 * Throw this exception to exit the Glut main loop without exit of application.
 */
class ExitGlut : public std::exception {

};


#endif //MYROOM_EXITGLUT_HPP
