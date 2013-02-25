/***************************************************************************
 *   Copyright (C) 2013 by Mike McLean   *
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

#include "playerstate.h"
#include "renderengine.h"
#include "Ogre.h"

using namespace std;

playerState::playerState()
{
    playerID = 0;
    playerXCoord = 0;
    playerYCoord = 0;
    offDef = 0;
    defending = -1;
    position = -1;
    userControlled = false;
    user = -1;
    points = 0;
    fouls = 0;
    offensiveRebounds = 0;
    defensiveRebounds = 0;
    totalRebounds = 0;
    stamina = 0;
    steals = 0;
    blocks = 0;
    turnovers = 0;
    assists = 0;
    fieldGoalsAttemped = 0;
    fieldGoalsMade = 0;
    threePointersAttempted = 0;
    threePointersMade = 0;
    freeThrowsAttempted = 0;
    freeThrowsMade = 0;
    posChange = Ogre::Vector3(0.0f,0.0f,0.0f);
}

playerState::~playerState()
{
}

int playerState::getPlayerID(void)
{
    return(playerID);
}

void playerState::setPlayerID(int id)
{
    playerID = id;
}

string playerState::getFirstName(void)
{
    return(firstName);
}

void playerState::setFirstName(string first)
{
    firstName = first;
}

string playerState::getLastName(void)
{
    return(lastName);
}

void playerState::setLastName(string last)
{
    lastName = last;
}

int playerState::getAge(void)
{
    return(age);
}

void playerState::setAge(int playerAge)
{
    age = playerAge;
}

int playerState::getHeight(void)
{
    return(height);
}

void playerState::setHeight(int playerHeight)
{
    height = playerHeight;
}

int playerState::getWeight(void)
{
    return(weight);
}

void playerState::setWeight(int playerWeight)
{
    weight = playerWeight;
}

// gets and sets player X and Y positions

int playerState::getPlayerXCoord(void)
{
//	cout << "dee" << endl;

//	cout << "playerXCoord = " << playerXCoord << endl;
//	cout << "dah" << endl;
    return(playerXCoord);
}

void playerState::setPlayerXCoord(int XCoord)
{
    playerXCoord = XCoord;
}

int playerState::getPlayerYCoord(void)
{
    return (playerYCoord);
}

void playerState::setPlayerYCoord(int YCoord)
{
    playerYCoord = YCoord;
}

int playerState::getOffDef(void)
{
    return(offDef);
}

void playerState::setOffDef(int set)
{
    offDef = set;
}

int playerState::getDefending(void)
{
    return (defending);
}

void playerState::setDefending(int set)
{
    defending = set;
}

int playerState::getPosition(void)
{
    return(position);
}

void playerState::setPosition(int set)
{
    position = set;
}

bool playerState::getUserControlled(void)
{
    return(userControlled);
}

void playerState::setUserControlled(bool set)
{
    userControlled = set;
}

int playerState::getUser(void)
{
    return(user);
}

void playerState::setUser(int set)
{
    user = set;
}

int playerState::getPoints(void)
{
    return(points);
}
void playerState::setPoints(int total)
{
    points = total;
}

int playerState::getFouls(void)
{
    return(fouls);
}

void playerState::setFoulds(int total)
{
    fouls = total;
}

int playerState::getOffensiveRebounds(void)
{
    return(offensiveRebounds);
}

void playerState::setOffensiveRebounds(int rebounds)
{
    offensiveRebounds = rebounds;
}

int playerState::getDefensiveRebounds(void)
{
    return(defensiveRebounds);
}

void playerState::setDefensiveRebounds(int rebounds)
{
    defensiveRebounds = rebounds;
}

int playerState::getTotalRebounds(void)
{
    return(totalRebounds);
}

void playerState::setTotalReboundS(int rebounds)
{
    totalRebounds = rebounds;
}

int playerState::getStamina(void)
{
    return(stamina);
}

void playerState::setStamina(int total)
{
    stamina = total;
}

int playerState::getSteals(void)
{
    return(steals);
}

void playerState::setSteals(int total)
{
    steals = total;
}

int playerState::getBlocks(void)
{
    return(blocks);
}

void playerState::setBlocks(int total)
{
    blocks = total;
}

int playerState::getTurnovers(void)
{
    return(turnovers);
}

void playerState::setTurnovers(int total)
{
    turnovers = total;
}

int playerState::getAssists(void)
{
    return(assists);
}

void playerState::setAssists(int total)
{
    assists = total;
}

int playerState::getFieldGoalsAttemped(void)
{
    return(fieldGoalsAttemped);
}

void playerState::setFieldGoalsAttempted(int attempted)
{
    fieldGoalsAttemped = attempted;
}

int playerState::getFieldGoalsMade(void)
{
    return(fieldGoalsMade);
}
void playerState::setFieldGoalsmade(int made)
{
    fieldGoalsMade = made;
}

int playerState::getThreePointersAttempted(void)
{
    return(threePointersAttempted);
}

void playerState::setThreePointersAttempted(int attempted)
{
    threePointersAttempted = attempted;
}

int playerState::getThreePointersMade(void)
{
    return(threePointersMade);
}

void playerState::setThreePointersMade(int made)
{
    threePointersMade = made;
}

int playerState::getFreeThrowsAttempted(void)
{
    return(freeThrowsAttempted);
}

void playerState::setFreeThrowsAttempted(int attempted)
{
    freeThrowsAttempted = attempted;
}

int playerState::getFreeThrowsMade(void)
{
    return(freeThrowsMade);
}

void playerState::setFreeThrowsMade(int made)
{
    freeThrowsMade = made;
}

string playerState::getModelName()
{
    return (modelName);
}

void playerState::setModelName(string name)
{
    modelName = name;
}

Ogre::Entity *playerState::getModel()
{
    return (model);
}

void playerState::setModel(Ogre::Entity *Model)
{
    model = Model;
}

Ogre::SceneNode *playerState::getNode()
{
    return (node);
}

void playerState::setNode(Ogre::SceneNode *Node)
{
    node = Node;
}

bool playerState::loadModel()   // loads the player's 3D model from the file specified in modelName
{

    renderEngine *render = renderEngine::Instance();
    Ogre::String playerName;	// string which stores the player's name
    playerName += firstName;    // adds the first name to playerName string
    playerName += lastName;     // adds the last name to the playerName string

//        playerName += Ogre::StringConverter::toString(playerNum);
    LogManager::getSingletonPtr()->logMessage("playerName == ");
    // creates and instantiates the playerNode object
    node = render->getMSceneMgr()->getRootSceneNode()->createChildSceneNode(playerName);
    // sets the player model
    LogManager::getSingletonPtr()->logMessage("modelName = " + modelName);
    model = render->getMSceneMgr()->createEntity(playerName, modelName);

    // attaches the model to the playerNode
    node->attachObject(model);
    // sets the size of playerNode
    node->setScale(0.28f,0.28f,0.28f);
    // sets the direction of playerNode
    node->yaw ( Degree (-270));

    return true;
}

bool playerState::updatePosition()  // updates the XYZ coordinates of the 3D model
{
     node->translate(posChange);

    return true;
}

// gets and sets posChange
Ogre::Vector3 playerState::getPosChange()
{
    return (posChange);
}
void playerState::setPosChange(Ogre::Vector3 change)
{
    posChange = change;
}
