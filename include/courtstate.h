#ifndef COURTSTATE_H_INCLUDED
#define COURTSTATE_H_INCLUDED

#include "Ogre.h"

class courtState
{
    public:

    courtState();   // constructor
    virtual ~courtState();  // destructor

    // gets and sets modelName
    std::string getModelName();
    virtual void setModelName(std::string name);

    // gets and sets model
    Ogre::Entity *getModel();
    virtual void setModel(Ogre::Entity *Model);

    // gets and sets node
    Ogre::SceneNode *getNode();
    virtual void setNode(Ogre::SceneNode *Node);

    // loads the 3D Model and attaches it to the node as well as sets coordinates
    virtual bool loadModel();

    private:

    std::string modelName;   // stores the file name of the 3D Model

    Ogre::Entity *model;    // stores the 3D Model representing the court

    Ogre::SceneNode *node;  // stores the node the 3D Model is attached to
};

#endif // COURTSTATE_H_INCLUDED
