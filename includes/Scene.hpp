#ifndef MYPROJECT_BASESCENE_H
#define MYPROJECT_BASESCENE_H


#include <OpenSG/OSGGL.h>
#include <OpenSG/OSGComponentTransform.h>
#include <OpenSG/OSGComponentTransformBase.h>
#include <OpenSG/OSGComponentTransformFields.h>

OSG_USING_NAMESPACE

class Scene {
    const NodeRecPtr _root;

    void build();

    void buildRoom(NodeRecPtr parent);

public:

    Scene();

    void update(OSG::Time dTime);

    const NodeRecPtr &root() const;
};


#endif //MYPROJECT_BASESCENE_H
