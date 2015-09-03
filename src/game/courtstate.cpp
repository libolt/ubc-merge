/***************************************************************************
 *   Copyright (C) 1999 - 2015 by Mike McLean   *
 *   libolt@libolt.net   *
 *                                                                         *
 *   This program is free software; you can redistribute it and/or modify  *
 *   it under the terms of the GNU General Public License as published by  *
 *   the Free Software Foundation; either version 2 of the License, or     *
 *   (at your option) any later version.                                   *
 *                                                                         *
 *   This program is distributed in the hope that it will be useful,       *
 *   but WITHOUT ANY WARRANTY; without even the implied warranty of        *
 *   MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the         *
 *   GNU General Public License for more details.                          *
 *                                                                         *
 *   You should have received a copy of the GNU General Public License     *
 *   along with this program; if not, write to the                         *
 *   Free Software Foundation, Inc.,                                       *
 *   59 Temple Place - Suite 330, Boston, MA  02111-1307, USA.             *
 ***************************************************************************/

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

btRigidBody *courtState::getPhysBody()	// retrieves physBody variable
{
	return (physBody);
}

void courtState::setPhysBody(btRigidBody *body)	// sets physBody variable
{
	physBody = body;

}

Ogre::Vector3 courtState::getNodePosition()  // returns the value of nodePosition
{
    return (nodePosition);
}
void courtState::setNodePosition(Ogre::Vector3 set)  // sets the value of nodePosition
{
    nodePosition = set;
}

// loads the 3D Model and attaches it to the node as well as sets coordinates
bool courtState::loadModel()
{
    boost::shared_ptr<renderEngine> render = renderEngine::Instance();

    model = render->getMSceneMgr()->createEntity("courtModel", modelName);	// loads the Court model

    // creates the courtNode
    node = render->getMSceneMgr()->getRootSceneNode()->createChildSceneNode("courtSceneNode");

    // attaches the court model to the courtNode
    node->attachObject(model);
    // sets the position of courtNode
//    node->setPosition(0.0f,-20.0f,400.0f);
    node->setScale(1.0f,1.0f,1.0f);

    return true;
}
