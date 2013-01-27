#include "courtstate.h"
#include "renderengine.h"

courtState::courtState()
{
}

courtState::~courtState()
{
}

// gets and sets modelName
std::string courtState::getModelName()
{
    return (modelName);
}
void courtState::setModelName(std::string name)
{
    modelName = name;
}

// gets and sets model
Ogre::Entity *courtState::getModel()
{
    return (model);
}
void courtState::setModel(Ogre::Entity *Model)
{
    model = Model;
}

// gets and sets node
Ogre::SceneNode *courtState::getNode()
{
    return (node);
}
void courtState::setNode(Ogre::SceneNode *Node)
{
    node = Node;
}

// loads the 3D Model and attaches it to the node as well as sets coordinates
bool courtState::loadModel()
{
    renderSystems *render = renderSystems::Instance();

    model = render->getMSceneMgr()->createEntity("Court", modelName);	// loads the Court model

    // creates the courtNode
    node = render->getMSceneMgr()->getRootSceneNode()->createChildSceneNode("court");
    // attaches the court model to the courtNode
    node->attachObject(model);
    // sets the position of courtNode
    node->setPosition(0.0f,-20.0f,400.0f);

    return true;
}
