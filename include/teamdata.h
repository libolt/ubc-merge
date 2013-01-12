#ifndef _TEAMDATA_H_
#define _TEAMDATA_H_

#include <string>
#include <vector>

using namespace std;

class teamData
{
    public:
    teamData(); // constructor
    ~teamData();    // destructor

    string getName(void);   // gets the value of name
    void setName(string Name);  // sets the value of name

    string getCity(void);   // gets the value of city
    void setCity(string City);  // sets the value of city

    string getCoach(void);  // gets the value of coach
    void setCoach(string Coach);    // sets the value of coach

    std::vector<int> getRoster(void);    // gets the value of roster
    void setRoster(std::vector<int> Roster); // sets the value of roster

    int getPlayerNum(void); // gets the value of playerNum
    void setPlayerNum(int num); // sets the value of playerNum

    std::vector<int> getStarters(void);  // gets the value of starters
    void setStarters(std::vector<int> Starters); // sets the value of starters

    int getID(void);    // gets the value of ID
    void setID(int teams);  // sets the value of ID

    string getInits(void);  // gets the value of inits
    void setInits(string Inits);    // sets the vlaue of inits

    string getLogoFile(void);   // gets the value of logoFile
    void setLogoFile(string file);  // sets the value of logoFile


private:
    string name;	// stores team name
    string city;    //  stores home city for team
    string coach;   // stores team's coach name
    string inits;   // stores initials used for team
    string logoFile;    // stores the name of the file used for team logo
    int ID; // stores the team's ID number

    std::vector<int> roster; // stores the list of player IDs associated with the team.
    int playerNum;  // stores total number of players on the team

    std::vector<int> starters;   // store the IDs of the starting players

};


#endif // _TEAMDATA_H_
