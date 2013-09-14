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
   class playerState
    {
    public:

        playerState();
        ~playerState();

        virtual int getPlayerID();								// retrieves playerID variable
        virtual void setPlayerID(int id);						// sets playerID variable

        virtual bool getNetworkControlled();					// retrieves networkControlled variable
        virtual void setNetworkControlled(bool controlled);		// sets networkControlled variable
        std::string getFirstName(void);
        void setFirstName(std::string first);

        std::string getLastName(void);
        void setLastName(std::string last);

        int getAge(void);
        void setAge(int age);

        int getHeight(void);
        void setHeight(int height);

        int getWeight(void);
        void setWeight(int weight);



        int getPlayerXCoord();
        virtual void setPlayerXCoord(int XCoord);

        int getPlayerYCoord();
        virtual void setPlayerYCoord(int YCoord);


        int getOffDef();
        virtual void setOffDef(int set);

        int getDefending();
        virtual void setDefending(int set);

        int getPosition();
        virtual void setPosition(int set);

        bool getUserControlled();
        virtual void setUserControlled(bool set);

        int getUser();
        virtual void setUser(int set);

        int getPoints();
        virtual void setPoints(int total);

        int getFouls();
        virtual void setFoulds(int total);

        int getOffensiveRebounds();
        virtual void setOffensiveRebounds(int rebounds);

        int getDefensiveRebounds();
        virtual void setDefensiveRebounds(int rebounds);

        int getTotalRebounds();
        virtual void setTotalReboundS(int rebounds);

        int getStamina();
        virtual void setStamina(int total);

        int getSteals();
        virtual void setSteals(int total);

        int getBlocks();
        virtual void setBlocks(int total);

        int getTurnovers();
        virtual void setTurnovers(int total);

        int getAssists();
        virtual void setAssists(int total);

        int getFieldGoalsAttemped();
        virtual void setFieldGoalsAttempted(int attempted);

        int getFieldGoalsMade();
        virtual void setFieldGoalsmade(int made);

        int getThreePointersAttempted();
        virtual void setThreePointersAttempted(int attempted);

        int getThreePointersMade();
        virtual void setThreePointersMade(int made);

        int getFreeThrowsAttempted();
        virtual void setFreeThrowsAttempted(int attempted);

        int getFreeThrowsMade();
        virtual void setFreeThrowsMade(int made);

        std::string getModelName();
        virtual void setModelName(std::string name);

        Ogre::Entity *getModel();
        virtual void setModel(Ogre::Entity *Model);

        Ogre::SceneNode *getNode();
        virtual void setNode(Ogre::SceneNode *Node);

        bool loadModel();   // loads the 3D model from file specified in modelName

        bool updatePosition();  // updates the X, Y and Z coordinates of the 3D model

        Ogre::Vector3 getPosChange();	// retrieves value of posChange
        void setPosChange(Ogre::Vector3 change);	// sets value of posChange

    private:

        int playerID;

        bool networkControlled;	// if true player is controlled by a nework client.

        std::string firstName;   // stores the first name of the player

        std::string lastName;    // stores the last name of the player

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

        // stores value of players' position changes during logic updates
        Ogre::Vector3 posChange;

        // Stores the 3D model that represents the player
        Ogre::Entity *model;

        // stores the Scene Node that represents the player
        Ogre::SceneNode *node;
    };


#endif // _PLAYERSTATE_H_
