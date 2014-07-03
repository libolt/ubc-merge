/***************************************************************************
 *   Copyright (C) 2014 by Mike McLean   *
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

hoop::hoop()
{
}

hoop::~hoop()
{
}

// gets and sets modelName
std::string hoop::getModelName()
{
    return (modelName);
}
void hoop::setModelName(std::string name)
{
    modelName = name;
}

// gets and sets model
Ogre::Entity *hoop::getModel()
{
    return (model);
}
void hoop::setModel(Ogre::Entity *Model)
{
    model = Model;
}

// gets and sets node
Ogre::SceneNode *hoop::getNode()
{
    return (node);
}
void hoop::setNode(Ogre::SceneNode *Node)
{
    node = Node;
}

btRigidBody *hoop::getPhysBody()	// retrieves physBody variable
{
	return (physBody);
}

void hoop::setPhysBody(btRigidBody *body)	// sets physBody variable
{
	physBody = body;

}


// loads the 3D Model and attaches it to the node as well as sets coordinates
bool hoop::loadModel()
{
    renderEngine *render = renderEngine::Instance();

    model = render->getMSceneMgr()->createEntity("hoopModel", modelName);	// loads the hoop model

    // creates the hoopNode
    node = render->getMSceneMgr()->getRootSceneNode()->createChildSceneNode("hoopSceneNode");

    // attaches the hoop model to the hoopNode
    node->attachObject(model);
    // sets the position of hoopNode
//    node->setPosition(0.0f,-20.0f,400.0f);
    node->setScale(0.25f,0.25f,0.25f);

    return true;
}
