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

#ifndef _PLAYERSTATE_H_
#define _PLAYERSTATE_H_

#include "Ogre.h"
#include "OgreVector3.h"

#include <vector>
#include <string>

#include "enums.h"

class playerState
    {
    public:

        playerState();
        ~playerState();


        virtual int getPlayerID();								// returns playerID variable
        virtual void setPlayerID(int id);						// sets playerID variable

        virtual bool getNetworkControlled();					// returns networkControlled variable
        virtual void setNetworkControlled(bool controlled);		// sets networkControlled variable

        virtual Ogre::String getFirstName(void);				// returns firstName variable
        virtual void setFirstName(Ogre::String first);			// sets firstName variable

        virtual Ogre::String getLastName(void);					// returns lastName variable
        virtual void setLastName(Ogre::String last);			// sets lastName variable

        virtual Ogre::String getPlayerName(void);				// returns playerName variable
        virtual void setPlayerName(Ogre::String name);			// sets playerName variable

        virtual int getAge(void);
        virtual void setAge(int age);

        virtual int getHeight(void);
        virtual void setHeight(int height);

        virtual int getWeight(void);
        virtual void setWeight(int weight);

        virtual int getPlayerXCoord();
        virtual void setPlayerXCoord(int XCoord);

        virtual int getPlayerYCoord();
        virtual void setPlayerYCoord(int YCoord);


        virtual int getOffDef();
        virtual void setOffDef(int set);

        virtual int getDefending();
        virtual void setDefending(int set);

        virtual int getPosition();
        virtual void setPosition(int set);

        virtual bool getUserControlled();
        virtual void setUserControlled(bool set);

        virtual int getUser();
        virtual void setUser(int set);

        virtual int getPoints();
        virtual void setPoints(int total);

        virtual int getFouls();
        virtual void setFoulds(int total);

        virtual int getOffensiveRebounds();
        virtual void setOffensiveRebounds(int rebounds);

        virtual int getDefensiveRebounds();
        virtual void setDefensiveRebounds(int rebounds);

        virtual int getTotalRebounds();
        virtual void setTotalReboundS(int rebounds);

        virtual int getStamina();
        virtual void setStamina(int total);

        virtual int getSteals();
        virtual void setSteals(int total);

        virtual int getBlocks();
        virtual void setBlocks(int total);

        virtual int getTurnovers();
        virtual void setTurnovers(int total);

        virtual int getAssists();
        virtual void setAssists(int total);

        virtual int getFieldGoalsAttemped();
        virtual void setFieldGoalsAttempted(int attempted);

        virtual int getFieldGoalsMade();
        virtual void setFieldGoalsmade(int made);

        virtual int getThreePointersAttempted();
        virtual void setThreePointersAttempted(int attempted);

        virtual int getThreePointersMade();
        virtual void setThreePointersMade(int made);

        virtual int getFreeThrowsAttempted();
        virtual void setFreeThrowsAttempted(int attempted);

        virtual int getFreeThrowsMade();
        virtual void setFreeThrowsMade(int made);

        virtual std::string getModelName();
        virtual void setModelName(std::string name);

        virtual Ogre::Entity *getModel();
        virtual void setModel(Ogre::Entity *Model);

        virtual Ogre::SceneNode *getNode();
        virtual void setNode(Ogre::SceneNode *Node);

        virtual bool loadModel();   // loads the 3D model from file specified in modelName

        virtual bool updatePosition();  // updates the X, Y and Z coordinates of the 3D model

        virtual bool getMovement();	// returns movement variable
        virtual void setMovement(bool move);	// sets movement variable

        virtual directions getDirection();	// returns direction variable
        virtual void setDirection(directions direct);	// sets direction variable

        virtual Ogre::Vector3 getPosChange();	// returns value of posChange
        void setPosChange(Ogre::Vector3 change);	// sets value of posChange

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

        int playerXCoord;
        int playerYCoord;

        // determines whether player is on offense or defense
        int offDef;
        // holds value of which offensive player defender is gaurding
        int defending;

        // position player plays: 0 PG, 1 SG; 2 SF; 3 PF; 4 C;
        int position;

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

        // stores value of players' position changes during logic updates
        Ogre::Vector3 posChange;


        // Stores the 3D model that represents the player
        Ogre::Entity *model;

        // stores the Scene Node that represents the player
        Ogre::SceneNode *node;

    };


#endif // _PLAYERSTATE_H_
