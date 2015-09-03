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

#include "hoop.h"

#include "renderengine.h"

hoopState::hoopState()
{
}

hoopState::~hoopState()
{
}

// gets and sets modelName
std::string hoopState::getModelName()
{
    return (modelName);
}
void hoopState::setModelName(std::string name)
{
    modelName = name;
}

// gets and sets entityName
std::string hoopState::getEntityName()
{
    return (entityName);
}
void hoopState::setEntityName(std::string name)
{
    entityName = name;
}

// gets and sets nodeName
std::string hoopState::getNodeName()
{
    return (nodeName);
}
void hoopState::setNodeName(std::string name)
{
    nodeName = name;
}

// gets and sets model
Ogre::Entity *hoopState::getModel()
{
    return (model);
}
void hoopState::setModel(Ogre::Entity *Model)
{
    model = Model;
}

// gets and sets node
Ogre::SceneNode *hoopState::getNode()
{
    return (node);
}
void hoopState::setNode(Ogre::SceneNode *Node)
{
    node = Node;
}

btRigidBody *hoopState::getPhysBody()	// retrieves physBody variable
{
	return (physBody);
}

void hoopState::setPhysBody(btRigidBody *body)	// sets physBody variable
{
	physBody = body;

}


// loads the 3D Model and attaches it to the node as well as sets coordinates
bool hoopState::loadModel()
{
    boost::shared_ptr<renderEngine> render = renderEngine::Instance();

    model = render->getMSceneMgr()->createEntity(entityName, modelName);	// loads the hoop model

    // creates the hoopNode
    node = render->getMSceneMgr()->getRootSceneNode()->createChildSceneNode(nodeName);

    // attaches the hoop model to the hoopNode
    node->attachObject(model);
    // sets the position of hoopNode
//    node->setPosition(0.0f,-20.0f,400.0f);
    node->setScale(0.8f,0.8f,0.8f);

    return true;
}
