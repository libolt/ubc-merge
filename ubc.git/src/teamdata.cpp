#include "teamdata.h"

// teamData constructor
teamData::teamData()
{

    name = '\0';	// string array of team names
    city = '\0';
    coach = '\0';
    inits = '\0';
    logoFile = '\0';

    ID = 0;

    playerNum = 0;

    for (int x = 0; x < 5; ++x)
    {
        starters.push_back(-1);
    }
}

teamData::~teamData()
{
//	delete [] teamStarters;
}

string teamData::getCity(void)
{
    return(city);
}

void teamData::setCity(string City)
{
    city = City;
}

string teamData::getName(void)
{
    return(name);
}

void teamData::setName(string Name)
{
    name = Name;
}

string teamData::getCoach(void)
{
    return(coach);
}

void teamData::setCoach(string Coach)
{
    coach = Coach;
}

vector<int> teamData::getRoster(void)
{
    return(roster);
}

void teamData::setRoster(std::vector<int> Roster)
{
    roster = Roster;
}

int teamData::getPlayerNum(void)
{
    return(playerNum);
}

void teamData::setPlayerNum(int num)
{
    playerNum = num;
}

vector<int> teamData::getStarters(void)
{
    return(starters);
}

void teamData::setStarters(std::vector<int> Starters)
{
    starters = Starters;
}

int teamData::getID(void)
{
    return(ID);
}
void teamData::setID(int teams)
{
    ID = teams;
}

string teamData::getInits(void)
{
    return(inits);
}

void teamData::setInits(string Inits)
{
    inits = Inits;
}

// gets and sets file storing team logo
string teamData::getLogoFile(void)
{
    return(logoFile);
}

void teamData::setLogoFile(string file)
{
    logoFile = file;
}

