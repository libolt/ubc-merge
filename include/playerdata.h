#ifndef _PLAYERDATA_H_
#define _PLAYERDATA_H_

#include <string>

using namespace std;

class playerData
{

    public:

        playerData();
        ~playerData();

        string getFirstName(void);
        void setFirstName(string first);

        string getLastName(void);
        void setLastName(string last);

        int getAge(void);
        void setAge(int age);

        int getHeight(void);
        void setHeight(int height);

        int getWeight(void);
        void setWeight(int weight);

        int getID(void);
        void setID(int id);

        bool getActive(void);
        void setActive(bool active);

        string getTeamInits(void);  // gets the value of teamInits
        void setTeamInits(string inits);    // sets the value of teamInits

        string getPosition();   // gets the vlaue of position
        virtual void setPosition(string Position); // sets the value of position

        string getModel();  // gets the value of model
        virtual void setModel(string Model);    // sets the value of model

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
