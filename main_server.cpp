#include <functional>
#include <iostream>




#include <renderServer.h>
#include <synchObject.h>


//
///home/ab123cd/demo/demo_server /sw/config/mlib/cave_1_multicast.conf
///home/ab123cd/demo/demo


int main( int argc, char **argv )
{
    std::string cfile = argv[1];
    synchlib::caveConfig conf(cfile);// "/sw/config/mlib/cave_1_multicast.conf"

//    GLenum err = glewInit();
//    if (GLEW_OK != err)
//    {
//      /* Problem: glewInit failed, something is seriously wrong. */
//      fprintf(stderr, "Error: %s\n", glewGetErrorString(err));
//
//    }
  //  std::shared_ptr<synchlib::SynchObject<float> > timeSyncher = synchlib::SynchObject<float>::create();


    {
       synchlib::renderServer server(cfile,argc,argv);

//    server.addSynchObject(timeSyncher,synchlib::renderServer::SENDER,0);
//    server.addSynchObject(&swapSyncher,cavelib::renderServer::SENDER,0,50001);
    server.init();
    server.startSynching();



    while(1){

    }
    server.stopSynching();
    }

        return 0;
}


















