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

class playerState
{
    public:

        playerState();
        ~playerState();

//        Ogre::Vector3 getNodePosition();  // retrieves the position of player node

        int getPlayerID();  // retrieves the value of playerID
        void setPlayerID(int id);  // sets the value of playerID

        int getTeamNumber();  // retrieves the value of teamNumber
        void setTeamNumber(int set);  // sets the value of teamNumber
        
        bool getNetworkControlled();  // retrieves the value of networkControlled
        void setNetworkControlled(bool controlled);  // sets the value of networkControlled

        std::string getFirstName(void);  // retrieves the value of firstName
        void setFirstName(std::string first);  // sets the value of firstName

        std::string getLastName(void);  // retrieves the value of lastName
        void setLastName(std::string last);  // sets the value of lastName

        std::string getPlayerName(void);  // retrieves the value of playerName
        void setPlayerName(std::string name);  // sets the value of playerName

        int getAge(void);  // retrieves the value of age
        void setAge(int age); // sets the value of age

        int getHeight(void); // retrieves the value of height
        void setHeight(int height);  // sets the value of height

        int getWeight(void);  // retrieves the value of weight
        void setWeight(int weight);  // sets the value of weight

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

        int getOffDef();  // retrieves the value of offDef
        void setOffDef(int set);  // sets the value of offDef

        int getDefending();  // reetrieves the value of defending
        void setDefending(int set);  // sets the value of defending

        bool getUserControlled();  // retrieves the value of userControlled
        void setUserControlled(bool set);  // sets the value of userControlled

        int getUser();  // retrieves the value of user
        void setUser(int set);  // sets the value of user

        int getPoints();  // gets the value of points
        void setPoints(int total);  // sets the value of points

        int getFouls();  // retrieves the value of fouls
        void setFoulds(int total);  // sets the value of fouls;

        int getOffensiveRebounds();  // retrieves the value of offensiveRebounds
        void setOffensiveRebounds(int rebounds);  // sets the value of offensiveRebounds

        int getDefensiveRebounds();  // retrieves the value of defensiveRebounds
        void setDefensiveRebounds(int rebounds);  // sets the value of defensiveRebounds

        int getTotalRebounds();  // retrieves the value of totalRebounds
        void setTotalReboundS(int rebounds);  // sets the value of totalRebounds

        int getStamina();  // retrieves the value of stamina
        void setStamina(int total);  // sets the value of stamina

        int getSteals();  // retrieves the value of steals
        void setSteals(int total);  // sets the value of steals

        int getBlocks();  // retrieves the value of blocks
        void setBlocks(int total);  // sets the value of blocks

        int getTurnovers();  // retrieves the value of turnovers
        void setTurnovers(int total);  // sets the value of turnovers

        int getAssists();  // retrieves the values of assists
        void setAssists(int total);  // sets the value of assists

        int getFieldGoalsAttemped();  // retrieves the value of fieldGoalsAttempted
        void setFieldGoalsAttempted(int attempted);  // sets the value of fieldGoalsAttempted

        int getFieldGoalsMade();  // retrieves the value of fieldGoalsMade
        void setFieldGoalsmade(int made);  // sets the value of fieldGoalsMade

        int getThreePointersAttempted();  // retrieves the value of threePointersMade
        void setThreePointersAttempted(int attempted);  // sets the value of threePointersAttempted

        int getThreePointersMade();  // retrieves the value of threePointersMade
        void setThreePointersMade(int made);  // sests the value of threePointersMade

        int getFreeThrowsAttempted();  // retrieves the value of freeThrowsAttempted
        void setFreeThrowsAttempted(int attempted);  // sets the value of freeThrowsAttempted

        int getFreeThrowsMade();  // retrieves the value of freeThrowsMade
        void setFreeThrowsMade(int made);  // sest the value of freeThrowsMade

        std::string getModelName();  // retrieves the value of modelName
        void setModelName(std::string name);  // sets the value of modelName

        Ogre::Entity *getModel();  // retrieves the value of model
        void setModel(Ogre::Entity *Model);  // sets the value of model

        Ogre::SceneNode *getNode();  // retrieves the value of node
        void setNode(Ogre::SceneNode *Node); // sets the value of node

        btRigidBody *getPhysBody();	// retrieves the value of physBody
        void setPhysBody(btRigidBody *body);  // sets the value of physBody

        playerSteer *getSteer(); // retrieves the steering instance
        void setSteer(playerSteer *instance); // sets the steering instance

        bool getMovement();	// retrieves the value of movement
        void setMovement(bool move);	// sets the value of movement

        directions getDirection();	// retrieves the value of direction
        void setDirection(directions direct);	// sets the value of direction

        directions getOldDirection();	// retrieves the value of oldDirection
        void setOldDirection(directions direct);	// sets the value of oldDirection

        Ogre::Vector3 getPosChange();	// retrieves the value of posChange
        void setPosChange(Ogre::Vector3 change);	// sets the value of posChange

        bool getStartPosReached();  // retrieves the value of startPosReached
        void setStartPosReached(bool set);  // sets the value of startPosReached
        
        bool getShootBlock();  // retrieves the value of shootBlock
        void setShootBlock(bool set);   // sets the value of shootBlock

        bool getPassSteal();  // retrieves the value of passSteal
        void setPassSteal(bool set); // sets the value of passSteal

        bool getPassBall();	// retrieves the value of passBall
        void setPassBall(bool ball);	// sets the value of passBall

        bool getPassCalculated();	// retrieves the value of passCalculated
        void setPassCalculated(bool calc);	// sets the value of passCalculated

        bool getPassCompleted();	// retrieves the value of passCompleted
        void setPassCompleted(bool completed);	// sets the value of passCompleted

        int getPassToPlayer();	// retrieves the value of passToPlayer
        void setPassToPlayer(int player);	// sets the value of passToPlayer

        bool getShotTaken();		// retrieves the value of shotTaken
        void setShotTaken(bool taken);	// sets the value of shotTaken
        
        bool getShotSet(); // retrieves the value of shotSet
        void setShotSet(bool set);  // sets the value of shotSet
        
        bool getShotComplete();	// retrieves the value of shotComplete
        void setShotComplete(bool complete);	// sets the value of shotComplete

        Ogre::Vector3 getJumpBeginPos();  // retrieves the value of playerJumpBeginPos
        void setJumpBeginPos(Ogre::Vector3 jumpBegin);  // sets the value of playerJumpBeginPos

        Ogre::Vector3 getJumpEndPos();  // retrieves the value of playerJumpEndPos
        void setJumpEndPos(Ogre::Vector3 set);  // sets the value of playerJumpEndPos

        bool getJumpSet();  // retrieves the value of jumpSet
        void setJumpSet(bool set);  // sets the value of jumpSet

        bool getJumpComplete();  // retrieves the value of jumpComplete
        void setJumpComplete(bool set);  // sets the value of jumpComplete

		bool getOffenseSet(void); // retrieves the value of offenseState
		void setOffenseSet(bool set);  // sets the value of offenseState

		bool getDefenseSet(void); // retrieves the value of defenseState
		void setDefenseSet(bool set);  // sets the value of defenseState

        Ogre::Vector3 getCourtPosition(); // retrieves the value of courtPosition
        void setCourtPosition(Ogre::Vector3 set);  // sets the value of courtPosition

        Ogre::Vector3 getNewCourtPosition(); // retrieves the value of newCourtPosition
        void setNewCourtPosition(Ogre::Vector3 set);  // sets the value of newCourtPosition

        bool getCourtPositionChanged();  // retrieves the value of courtPositionChanged
        void setCourtPositionChanged(bool set);  // sets the value of courtPositionChanged

        positionChangedTypes getCourtPositionChangedType();  // retrieves the value of courtPositionChangedType
        void setCourtPositionChangedType(positionChangedTypes set);  // sets the value of courtPositionChangedType

        bool getInitialized(void); // retreives the value of initialized
        void setInitialized(bool set); // sets the value of initialized




        void updateState();	// updates the state of the object

        bool loadModel();   // loads the 3D model from file specified in modelName

        bool updateCourtPosition();  // updates the X, Y and Z coordinates of the 3D model

        void updatePlayerDirections();  // updates the direction players are facing

        void calculatePass();	// calculates which player to pass the ball to

        void shotLogic(Ogre::Vector3 playerPos);   // carries out basketball shot logic

    private:

        int playerID;  // stores the ID of the player which is unique to each player in the game

        int teamNumber;  // stores which of the two teams the player belongs to
        
        bool networkControlled;	// if true player is controlled by a network client.

        std::string firstName;   // stores the first name of the player

        std::string lastName;    // stores the last name of the player
        std::string playerName;	// string which stores the player's full name

        int age;    // stores the age of the player

        int height; // stores the height in centimeters of the player

        int weight; // stores the weight of the player in pounds.

        int ID; // stores the unique ID of the player.

        playerPositions primaryPosition; // stores the primary position of the player
        
        playerPositions secondaryPosition; // stores the secondary position of the player

        playerPositions activePosition; // stores the active position of the player

        bool isActive;  // stores whether or not the player is on the court.

        bool modelLoaded; // stores whether or not the player's model has been loaded from disk


        // determines whether player is on offense or defense
        int offDef;
        // holds value of which offensive player defender is gaurding
        int defending;

        // Sets whether or not a player is user controlled
        bool userControlled;

        // Sets which player a user is controlled by if userControlled is set
        int user;

        // Tracks how many points the player has scored
        int points;

        // Tracks how many fouls the player has
        int fouls;

        // Tracks how many rebounds the player has on offense
        int offensiveRebounds;

        // Tracks how many rebounds the player has on defense
        int defensiveRebounds;

        // Tracks how many total rebounds the player has
        int totalRebounds;

        // Tracks how much stamina the player has remaining
        int stamina;

        // Tracks how many steals the player has
        int steals;

        // Tracks how many blocks the player has
        int blocks;

        // Tracks how many turnovers the player has
        int turnovers;

        // Tracks how many assists the player has
        int assists;

        // Tracks how many field goals the player has attempted
        int fieldGoalsAttemped;

        // Tracks how many field goals the player has made
        int fieldGoalsMade;

        // Tracks how many three pointers the player has attempted
        int threePointersAttempted;

        // Tracks how many three pointers the player has made
        int threePointersMade;

        // Tracks how many free throws the player has attempted
        int freeThrowsAttempted;

        // Tracks how many fere throws the player has made
        int freeThrowsMade;

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

        // temporary hack
        bool initialized;
        
        // tempory hack to count the number of times player position changes
        int posChangeAmount;
};


#endif // _PLAYERSTATE_H_
