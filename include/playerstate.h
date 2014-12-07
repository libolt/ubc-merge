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

#ifndef _PLAYERSTATE_H_
#define _PLAYERSTATE_H_

#include "Ogre.h"
#include "OgreVector3.h"

#include <vector>
#include <string>

// physics
#include "BtOgrePG.h"
#include "BtOgreGP.h"
#include "BtOgreExtras.h"

#include "enums.h"

#include "playersteer.h"

class playerState
{
    public:

        playerState();
        ~playerState();

        Ogre::Vector3 getNodePosition();  // returns the position of player node

        int getPlayerID();								// returns playerID variable
        void setPlayerID(int id);						// sets playerID variable

        bool getNetworkControlled();					// returns networkControlled variable
        void setNetworkControlled(bool controlled);		// sets networkControlled variable

        Ogre::String getFirstName(void);				// returns firstName variable
        void setFirstName(Ogre::String first);			// sets firstName variable

        Ogre::String getLastName(void);					// returns lastName variable
        void setLastName(Ogre::String last);			// sets lastName variable

        Ogre::String getPlayerName(void);				// returns playerName variable
        void setPlayerName(Ogre::String name);			// sets playerName variable

        int getAge(void);
        void setAge(int age);

        int getHeight(void);
        void setHeight(int height);

        int getWeight(void);
        void setWeight(int weight);

        std::string getPosition();
        void setPosition(std::string set);

        bool getIsActive(); // retrieves the value of isActive
        void setIsActive(bool set); // sets the value of isActive

        bool getModelLoaded();  // retrieves the value of modelLoaded
        void setModelLoaded(bool set); // sets the value of modelLoaded

        int getPlayerXCoord();
        void setPlayerXCoord(int XCoord);

        int getPlayerYCoord();
        void setPlayerYCoord(int YCoord);

        int getOffDef();
        void setOffDef(int set);

        int getDefending();
        void setDefending(int set);

        bool getUserControlled();
        void setUserControlled(bool set);

        int getUser();
        void setUser(int set);

        int getPoints();
        void setPoints(int total);

        int getFouls();
        void setFoulds(int total);

        int getOffensiveRebounds();
        void setOffensiveRebounds(int rebounds);

        int getDefensiveRebounds();
        void setDefensiveRebounds(int rebounds);

        int getTotalRebounds();
        void setTotalReboundS(int rebounds);

        int getStamina();
        void setStamina(int total);

        int getSteals();
        void setSteals(int total);

        int getBlocks();
        void setBlocks(int total);

        int getTurnovers();
        void setTurnovers(int total);

        int getAssists();
        void setAssists(int total);

        int getFieldGoalsAttemped();
        void setFieldGoalsAttempted(int attempted);

        int getFieldGoalsMade();
        void setFieldGoalsmade(int made);

        int getThreePointersAttempted();
        void setThreePointersAttempted(int attempted);

        int getThreePointersMade();
        void setThreePointersMade(int made);

        int getFreeThrowsAttempted();
        void setFreeThrowsAttempted(int attempted);

        int getFreeThrowsMade();
        void setFreeThrowsMade(int made);

        std::string getModelName();
        void setModelName(std::string name);

        Ogre::Entity *getModel();
        void setModel(Ogre::Entity *Model);

        Ogre::SceneNode *getNode();
        void setNode(Ogre::SceneNode *Node);

        btRigidBody *getPhysBody();	// returns physBody variable
        void setPhysBody(btRigidBody *body);

		playerSteer *getSteer(); // returns the steering instance
		void setSteer(playerSteer *instance); // sets the steering instance

        bool getMovement();	// returns movement variable
        void setMovement(bool move);	// sets movement variable

        directions getDirection();	// returns direction variable
        void setDirection(directions direct);	// sets direction variable

        directions getOldDirection();	// returns the value of the oldDirection variable
        void setOldDirection(directions direct);	// sets the value of the oldDirection variable

        Ogre::Vector3 getPosChange();	// returns the value of the posChange variable
        void setPosChange(Ogre::Vector3 change);	// sets the value of the posChange variable

        bool getPassBall();	// returns the value of the passBall variable
        void setPassBall(bool ball);	// sets the value of the passBall variable

        bool getPassCalculated();	// returns the value of the passCalculated variable
        void setPassCalculated(bool calc);	// sets the value of the passCalculatedvariable

        bool getPassCompleted();	// returns the value of the passCompleted variable
        void setPassCompleted(bool completed);	// sets the value of the passCompleted variable

        int getPassToPlayer();	// returns the value of the passToPlayer variable
        void setPassToPlayer(int player);	// sets the value of the passToPlayer variable

        bool getShotTaken(void);		// retrieves the value of the shotTaken variable
        void setShotTaken(bool taken);	// sets the value of the shotTaken variable

        bool getShotComplete(void);	// retrieves the value of the shotComplete variable
        void setShotComplete(bool complete);	// sets the value of the shotComplete variable

		bool getOffenseSet(void); // retrieves the value of offenseState
		void setOffenseSet(bool set);  // sets the value of offenseState

		bool getDefenseSet(void); // retrieves the value of defenseState
		void setDefenseSet(bool set);  // sets the value of defenseState

        void updateState();	// updates the state of the object

        bool loadModel();   // loads the 3D model from file specified in modelName

        bool updatePosition();  // updates the X, Y and Z coordinates of the 3D model

        void calculatePass();	// calculates which player to pass the ball to

        void shotLogic(Ogre::Vector3 playerPos);   // carries out basketball shot logic

    private:

        int playerID;

        bool networkControlled;	// if true player is controlled by a network client.

        Ogre::String firstName;   // stores the first name of the player

        Ogre::String lastName;    // stores the last name of the player
        Ogre::String playerName;	// string which stores the player's full name

        int age;    // stores the age of the player

        int height; // stores the height in centimeters of the player

        int weight; // stores the weight of the player in pounds.

        int ID; // stores the unique ID of the player.

        std::string position;    // stores which position the player plays


        bool isActive;  // stores whether or not the player is on the court.

        bool modelLoaded; // stores whether or not the player's model has been loaded from disk

        int playerXCoord;
        int playerYCoord;

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

        // Passing variables
        bool passBall;	// stores whether a player is to pass the ball to another player or not.
        bool passCalculated;	// stores whether or not the player to pass ball to has been calculated
        bool passCompleted;	// stores whether or not the pass has been completed
        int passToPlayer;	// stores the value of the player to be passed to.

        // Shooting variables
        bool shotTaken;	// Determines whether or not a player has shot the ball
        bool shotComplete;	// Determine whether or not a player's shot is complete

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
};


#endif // _PLAYERSTATE_H_
