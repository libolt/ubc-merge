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

#ifndef _PLAYERDATA_H_
#define _PLAYERDATA_H_

#include <string>

using namespace std;

class playerData
{

    public:

        playerData();
        ~playerData();

        string getFirstName(void);	// retrieves the value for the firstName variable
        void setFirstName(string first);	// sets the value for the firstName variable

        string getLastName(void);	// retrieves the value for the lastName variable
        void setLastName(string last);	// sets the value for the lastName variable

        int getAge(void);	// retrieves the value for the age variable
        void setAge(int age);	// sets the value for the age variable

        int getHeight(void);	// retrieves the value for the height variable
        void setHeight(int height);	// sets the value for the height variable

        int getWeight(void);		// retrieves the value for the weight variable
        void setWeight(int weight);	// sets the value for the weight variable

        int getID(void);	// retrieves the value for the ID variable.
        void setID(int id);	// sets the value for the ID variable.

        int getTeamID(void);	// retrieves the value for the teamID variable
        void setTeamID(int id);	// sets the value for the teamID variable

        bool getActive(void);	// retrieves the value of the active variable
        void setActive(bool active);	// sets the value of the active variable

        string getTeamInits(void);  // retrieves the value of the teamInits variable
        void setTeamInits(string inits);    // sets the value of the teamInits variable

        string getPosition();   // retrieves the value of the position variable
        virtual void setPosition(string Position); // sets the value of the position variable

        string getModel();  // retrieves the value of the model variable
        virtual void setModel(string Model);    // sets the value of the model variable

        int getFieldGoalRating(void);
        void setFieldGoalRating(int rating);

        int getThreePointRating(void);
        void setThreePointRating(int rating);

        int getDunkRating(void);
        void setDunkGoalRating(int rating);

        int getFreeThrowRating(void);
        void setFreeThrowRating(int rating);

        int getPassRating(void);
        void setPassRating(int rating);

        int getStealRating(void);
        void setStealRating(int rating);

        int getOffensiveReboundRating(void);
        void setOffensiveReboundRating(int rating);

        int getDefensiveReboundRating(void);
        void setDefensiveReboundRating(int rating);

        int getBlockRating(void);
        void setBlockRating(int rating);

        int getStaminaRating(void);
        void setStaminaRating(int rating);

        int getClutchRating(void);
        void setClutchRating(int rating);

        int getSpeedRating(void);
        void setSpeedRating(int rating);

        int getQuicknessRating(void);
        void setQuicknessRating(int rating);

        int getInjuryRating(void);
        void setInjuryRating(int rating);

    private:

        string firstName;   // stores the first name of the player
        string lastName;    // stores the last name of the player
        int age;    // stores the age of the player
        int height; // stores the height in centimeters of the player
        int weight; // stores the weight of the player in pounds.
        int ID; // stores the unique ID of the player.
        int teamID;	// stores the unique ID of the team the player plays for.

        // if player is playing this is true
        bool active;

        string position;    // stores which position the plaer plays

        string teamInits;   // stores the initials of the team the player plays for

        string model;   // stores the name of the 3D model to load for the player
        // Ratigns

        int fieldGoalRating;
        int threePointRating;
        int dunkRating;
        int freeThrowRating;
        int passRating;
        int stealRating;
        int offensiveReboundRating;
        int defensiveReboundRating;
        int blockRating;
        int staminaRating;
        int clutchRating;
        int speedRating;
        int quicknessRating;
        int injuryRating;


};


#endif // _PLAYERDATA_H_
