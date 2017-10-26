
#include <renderNode.h>
#include <GL/glut.h>
#include "GL/gl.h"
#include <synchObject.h>

#define LOG(expr) \
    std::cout << #expr << ": " << expr << std::endl;

synchlib::renderNode *node;


void displayFunction() {

    glm::mat4 pvmatL, pvmatR;
    node->getProjectionMatrices(pvmatL, pvmatR);
    glm::mat4 viewMat;
    node->getSceneTrafo(viewMat);


    glDrawBuffer(GL_BACK_LEFT);
    {
        glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
        glClearColor(1.,1.,1.,1.);
        //draw call

    }
    glDrawBuffer(GL_BACK_RIGHT);
    {
        glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
        //draw call
    }

    glutSwapBuffers();

    glFinish();
    if(!node->synchFrame()){
       return;
   }





}

//void keyboardDown(unsigned char key, int mouseX, int mouseY) {
//    switch (key) {
//        case 27: // ESC
//            exit(0);
//        default:
//            break;
//    }
//}

int main(int argc, char **argv) {
    std::cout << "Hello Main 2\n";
    LOG("Hello");
    std::string file = argv[2];
    node = new synchlib::renderNode(file, argc, argv);
    LOG("Hello 2");

    //std::shared_ptr<synchlib::SynchObject<float> > timeSyncher = synchlib::SynchObject<float>::create();
    //node->addSynchObject(timeSyncher,synchlib::renderNode::RECEIVER);
    glutInit(&argc, argv);
    glutInitDisplayMode(GLUT_RGB | GLUT_DOUBLE | GLUT_DEPTH);
    glutInitWindowPosition(0, 0);
    glutInitWindowSize(640, 480);

    int windowId = glutCreateWindow("demo Control Window");
    LOG(windowId);

    glutFullScreen();
    glutShowWindow();
//    glutReshapeFunc(reshapeFunc);
//    glutMouseFunc();
//    glutMotionFunc();
//    glutKeyboardFunc(keyboardDown);
//        glutKeyboardUpFunc();
//    glutSetKeyRepeat(GLUT_KEY_REPEAT_OFF);

    node->init();
    node->startSynching();
    glutDisplayFunc(&displayFunction);
    glutIdleFunc(&displayFunction);


    glutMainLoop();
    node->stopSynching();

}











