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

#ifndef _PLAYERSTATE_H_
#define _PLAYERSTATE_H_

#include "Ogre.h"
#include "OgreVector3.h"

#include <vector>
#include <string>
#include <boost/shared_ptr.hpp>

// physics
#include "BtOgrePG.h"
#include "BtOgreGP.h"
#include "BtOgreExtras.h"
#include "BulletDynamics/Dynamics/btRigidBody.h"

#include "enums.h"

#include "playersteer.h"

#include "playerphysics.h"

class playerState
{
    public:

        playerState();
        ~playerState();

//        Ogre::Vector3 getNodePosition();  // retrieves the position of player node

        size_t getPlayerID();  // retrieves the value of playerID
        void setPlayerID(size_t set);  // sets the value of playerID

        teamTypes getTeamType();  // retrieves the value of teamType
        void setTeamType(teamTypes set);  // sets the value of teamType
        
        bool getNetworkControlled();  // retrieves the value of networkControlled
        void setNetworkControlled(bool set);  // sets the value of networkControlled

        std::string getFirstName(void);  // retrieves the value of firstName
        void setFirstName(std::string set);  // sets the value of firstName

        std::string getLastName(void);  // retrieves the value of lastName
        void setLastName(std::string set);  // sets the value of lastName

        std::string getPlayerName(void);  // retrieves the value of playerName
        void setPlayerName(std::string set);  // sets the value of playerName

        size_t getAge(void);  // retrieves the value of age
        void setAge(size_t set); // sets the value of age

        size_t getHeight(void); // retrieves the value of height
        void setHeight(size_t set);  // sets the value of height

        size_t getWeight(void);  // retrieves the value of weight
        void setWeight(size_t set);  // sets the value of weight

        playerPositions getPrimaryPosition();  // retrieves the value of primaryPosition
        void setPrimaryPosition(playerPositions set);  // sets the value of primaryPosition

        playerPositions getSecondaryPosition();  // retrieves the value of secondaryPosition
        void setSecondaryPosition(playerPositions set);  // sets the value of secondaryPosition

        playerPositions getActivePosition();  // retrieves the value of activePosition
        void setActivePosition(playerPositions set);  // sets the value of activePosition

        bool getIsActive(); // retrieves the value of isActive
        void setIsActive(bool set); // sets the value of isActive

        bool getModelLoaded();  // retrieves the value of modelLoaded
        void setModelLoaded(bool set); // sets the value of modelLoaded

        size_t getOffDef();  // retrieves the value of offDef
        void setOffDef(size_t set);  // sets the value of offDef

        size_t getDefending();  // reetrieves the value of defending
        void setDefending(size_t set);  // sets the value of defending

        bool getUserControlled();  // retrieves the value of userControlled
        void setUserControlled(bool set);  // sets the value of userControlled

        size_t getUser();  // retrieves the value of user
        void setUser(size_t set);  // sets the value of user

        size_t getPoints();  // gets the value of points
        void setPoints(size_t set);  // sets the value of points

        size_t getFouls();  // retrieves the value of fouls
        void setFoulds(size_t set);  // sets the value of fouls;

        size_t getOffensiveRebounds();  // retrieves the value of offensiveRebounds
        void setOffensiveRebounds(size_t set);  // sets the value of offensiveRebounds

        size_t getDefensiveRebounds();  // retrieves the value of defensiveRebounds
        void setDefensiveRebounds(size_t set);  // sets the value of defensiveRebounds

        size_t getTotalRebounds();  // retrieves the value of totalRebounds
        void setTotalReboundS(size_t set);  // sets the value of totalRebounds

        size_t getStamina();  // retrieves the value of stamina
        void setStamina(size_t set);  // sets the value of stamina

        size_t getSteals();  // retrieves the value of steals
        void setSteals(size_t set);  // sets the value of steals

        size_t getBlocks();  // retrieves the value of blocks
        void setBlocks(size_t set);  // sets the value of blocks

        size_t getTurnovers();  // retrieves the value of turnovers
        void setTurnovers(size_t set);  // sets the value of turnovers

        size_t getAssists();  // retrieves the values of assists
        void setAssists(size_t set);  // sets the value of assists

        size_t getFieldGoalsAttemped();  // retrieves the value of fieldGoalsAttempted
        void setFieldGoalsAttempted(size_t set);  // sets the value of fieldGoalsAttempted

        size_t getFieldGoalsMade();  // retrieves the value of fieldGoalsMade
        void setFieldGoalsmade(size_t set);  // sets the value of fieldGoalsMade

        size_t getThreePointersAttempted();  // retrieves the value of threePointersMade
        void setThreePointersAttempted(size_t set);  // sets the value of threePointersAttempted

        size_t getThreePointersMade();  // retrieves the value of threePointersMade
        void setThreePointersMade(size_t set);  // sests the value of threePointersMade

        size_t getFreeThrowsAttempted();  // retrieves the value of freeThrowsAttempted
        void setFreeThrowsAttempted(size_t set);  // sets the value of freeThrowsAttempted

        size_t getFreeThrowsMade();  // retrieves the value of freeThrowsMade
        void setFreeThrowsMade(size_t set);  // sest the value of freeThrowsMade

        std::string getModelName();  // retrieves the value of modelName
        void setModelName(std::string set);  // sets the value of modelName

        Ogre::Entity *getModel();  // retrieves the value of model
        void setModel(Ogre::Entity *set);  // sets the value of model

        Ogre::SceneNode *getNode();  // retrieves the value of node
        void setNode(Ogre::SceneNode *set); // sets the value of node

        btRigidBody *getPhysBody();	// retrieves the value of physBody
        void setPhysBody(btRigidBody *set);  // sets the value of physBody

        playerPhysics getPhysics();  // retrieves the value of physics
        void setPhysics(playerPhysics set);  // sets the value of physics 
        
        playerSteer *getSteer(); // retrieves the steering instance
        void setSteer(playerSteer *set); // sets the steering instance

        bool getMovement();	// retrieves the value of movement
        void setMovement(bool set);	// sets the value of movement

        directions getDirection();	// retrieves the value of direction
        void setDirection(directions set);	// sets the value of direction

        directions getOldDirection();	// retrieves the value of oldDirection
        void setOldDirection(directions set);	// sets the value of oldDirection

        Ogre::Vector3 getPosChange();	// retrieves the value of posChange
        void setPosChange(Ogre::Vector3 set);	// sets the value of posChange

        bool getStartPosReached();  // retrieves the value of startPosReached
        void setStartPosReached(bool set);  // sets the value of startPosReached
        
        bool getShootBlock();  // retrieves the value of shootBlock
        void setShootBlock(bool set);   // sets the value of shootBlock

        bool getPassSteal();  // retrieves the value of passSteal
        void setPassSteal(bool set); // sets the value of passSteal

        bool getPassBall();	// retrieves the value of passBall
        void setPassBall(bool set);	// sets the value of passBall

        bool getPassCalculated();	// retrieves the value of passCalculated
        void setPassCalculated(bool set);	// sets the value of passCalculated

        bool getPassCompleted();	// retrieves the value of passCompleted
        void setPassCompleted(bool set);	// sets the value of passCompleted

        size_t getPassToPlayer();	// retrieves the value of passToPlayer
        void setPassToPlayer(size_t set);	// sets the value of passToPlayer

        bool getShotTaken();		// retrieves the value of shotTaken
        void setShotTaken(bool set);	// sets the value of shotTaken
        
        bool getShotSet(); // retrieves the value of shotSet
        void setShotSet(bool set);  // sets the value of shotSet
        
        bool getShotComplete();	// retrieves the value of shotComplete
        void setShotComplete(bool set);	// sets the value of shotComplete

        Ogre::Vector3 getJumpBeginPos();  // retrieves the value of playerJumpBeginPos
        void setJumpBeginPos(Ogre::Vector3 set);  // sets the value of playerJumpBeginPos

        Ogre::Vector3 getJumpEndPos();  // retrieves the value of playerJumpEndPos
        void setJumpEndPos(Ogre::Vector3 set);  // sets the value of playerJumpEndPos

        bool getJumpSet();  // retrieves the value of jumpSet
        void setJumpSet(bool set);  // sets the value of jumpSet

        bool getJumpComplete();  // retrieves the value of jumpComplete
        void setJumpComplete(bool set);  // sets the value of jumpComplete

		bool getOffenseSet(void); // retrieves the value of offenseSet
		void setOffenseSet(bool set);  // sets the value of offenseSet

		bool getDefenseSet(void); // retrieves the value of defenseSet
		void setDefenseSet(bool set);  // sets the value of defenseSet

        Ogre::Vector3 getCourtPosition(); // retrieves the value of courtPosition
        void setCourtPosition(Ogre::Vector3 set);  // sets the value of courtPosition

        Ogre::Vector3 getNewCourtPosition(); // retrieves the value of newCourtPosition
        void setNewCourtPosition(Ogre::Vector3 set);  // sets the value of newCourtPosition

        bool getCourtPositionChanged();  // retrieves the value of courtPositionChanged
        void setCourtPositionChanged(bool set);  // sets the value of courtPositionChanged

        positionChangedTypes getCourtPositionChangedType();  // retrieves the value of courtPositionChangedType
        void setCourtPositionChangedType(positionChangedTypes set);  // sets the value of courtPositionChangedType

        bool getStateSet();  // retrieves the value of stateSet
        void setStateSet(bool set);  // sets the value of stateSet
        
        bool getInitialized(void); // retreives the value of initialized
        void setInitialized(bool set); // sets the value of initialized




        void updateState();	// updates the state of the object

        bool loadModel();   // loads the 3D model from file specified in modelName

        bool updateCourtPosition();  // updates the X, Y and Z coordinates of the 3D model

        void updateMovement();	// updates the movement status of the player

        void updateDirection();  // updates the direction players the player is facing

        void calculatePass();	// calculates which player to pass the ball to

        void shotLogic(Ogre::Vector3 playerPos);   // carries out basketball shot logic

    private:

        size_t playerID;  // stores the ID of the player which is unique to each player in the game

        teamTypes teamType;  // stores which of the two teams the player belongs to
        
        bool networkControlled;	// if true player is controlled by a network client.

        std::string firstName;   // stores the first name of the player

        std::string lastName;    // stores the last name of the player
        std::string playerName;	// string which stores the player's full name

        size_t age;    // stores the age of the player

        size_t height; // stores the height in centimeters of the player

        size_t weight; // stores the weight of the player in pounds.

        size_t ID; // stores the unique ID of the player.

        playerPositions primaryPosition; // stores the primary position of the player
        
        playerPositions secondaryPosition; // stores the secondary position of the player

        playerPositions activePosition; // stores the active position of the player

        bool isActive;  // stores whether or not the player is on the court.

        bool modelLoaded; // stores whether or not the player's model has been loaded from disk


        // determines whether player is on offense or defense
        size_t offDef;
        // holds value of which offensive player defender is gaurding
        size_t defending;

        // Sets whether or not a player is user controlled
        bool userControlled;

        // Sets which player a user is controlled by if userControlled is set
        size_t user;

        // Tracks how many points the player has scored
        size_t points;

        // Tracks how many fouls the player has
        size_t fouls;

        // Tracks how many rebounds the player has on offense
        size_t offensiveRebounds;

        // Tracks how many rebounds the player has on defense
        size_t defensiveRebounds;

        // Tracks how many total rebounds the player has
        size_t totalRebounds;

        // Tracks how much stamina the player has remaining
        size_t stamina;

        // Tracks how many steals the player has
        size_t steals;

        // Tracks how many blocks the player has
        size_t blocks;

        // Tracks how many turnovers the player has
        size_t turnovers;

        // Tracks how many assists the player has
        size_t assists;

        // Tracks how many field goals the player has attempted
        size_t fieldGoalsAttemped;

        // Tracks how many field goals the player has made
        size_t fieldGoalsMade;

        // Tracks how many three pointers the player has attempted
        size_t threePointersAttempted;

        // Tracks how many three pointers the player has made
        size_t threePointersMade;

        // Tracks how many free throws the player has attempted
        size_t freeThrowsAttempted;

        // Tracks how many fere throws the player has made
        size_t freeThrowsMade;

        // stores the name of the 3D model representing the player
        std::string modelName;

        bool movement; // if true then player is moving

        directions direction;	// stores direction player is moving
        directions oldDirection; // stores the previous player direction.

        // stores value of players' position changes during logic updates
        Ogre::Vector3 posChange;

        bool startPosReached;  // stores whether a player is in the starting position for tipoff
        // variables for offense and defense;
        bool shootBlock;  // stores whether or not a player attempts to shoot or block a shot
        bool passSteal;  // stores whether a player attempts to pass or steal the ball

        // Passing variables
        bool passBall;	// stores whether a player is to pass the ball to another player or not.
        bool passCalculated;	// stores whether or not the player to pass ball to has been calculated
        bool passCompleted;	// stores whether or not the pass has been completed
        int passToPlayer;	// stores the value of the player to be passed to.

        // Shooting variables
        bool shotTaken;	// Determines whether or not a player has shot the ball
        bool shotSet;  // Determines if shot has been setup
        bool shotComplete;	// Determine whether or not a player's shot is complete

        // player Jump variables
        Ogre::Vector3 jumpBeginPos;  // stores the coordinates of the player at the beginning of the jump
        Ogre::Vector3 jumpEndPos;  // stores the coordinates the player should reach at the end of the jump
        bool jumpSet; // determines whether or not the playerJumpBeginPos has been set
        bool jumpComplete;  // determines whether or not the jump has been completed

        bool offenseSet;  // tracks state of player's offense
		bool defenseSet;  // tracks state of player's defense

        // Stores the 3D model that represents the player
        Ogre::Entity *model;

        // stores the Scene Node that represents the player
        Ogre::SceneNode *node;

        // stores the physics object that represents the player
        btRigidBody *physBody;

        // stores the playerPhysics object
        playerPhysics physics;
        
        // stores the steering objerct taht represents the player
        playerSteer *steer;

        // stores the position of the player on the court in an Ogre::Vector3
        Ogre::Vector3 courtPosition;

        // stores the upfated position of the player on the court in an Ogre::Vector3
        Ogre::Vector3 newCourtPosition;
        
        // if the court position has changed then this flag is set
        bool courtPositionChanged;

        // stores what subsystem changed the position of the player
        positionChangedTypes courtPositionChangedType;

        bool stateSet;  // if true the playerState object has been set to initial state
        // temporary hack
        bool initialized;
        
        // tempory hack to count the number of times player position changes
        size_t posChangeAmount;
};


#endif // _PLAYERSTATE_H_
