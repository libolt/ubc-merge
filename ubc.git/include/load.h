//
// C++ Interface: load
//
// Description:
//
//
// Author: Mike McLean <libolt@libolt.net>, (C) 2006
//
// Copyright: See COPYING file that comes with this distribution
//
//

#ifndef _LOAD_H_
#define _LOAD_H_

#include <string>
#include <vector>

using namespace std;

class loader
{
public:


    // loads all sprites
    int loadSprites(void);

    // loads player sprites
    int loadPlayerSprites(void);

    // loads court sprites
    int loadCourtSprites();

    std::vector<std::string> pathSplit(const std::string paths);
    string findFile(string fileName);
//	string * pathArray;
    static loader *Instance();

    // returns list of player xml files
    std::vector<std::string> getPlayerFiles();
    // sets list of player xml files
    virtual void setPlayerFiles(std::vector<std::string> files);

    // returns list of player xml files
    std::vector<std::string> getTeamFiles();
    // sets list of player xml files
    virtual void setTeamFiles(std::vector<std::string> files);

    virtual bool loadXMLFile(string fileName);

    virtual bool loadTeams();   // loads team data from XML files
    virtual bool loadTeamListFile(string fileName); // loads list of team files from teams.xml
    virtual bool loadTeamFile(string fileName); // loads data out of team XML files

    virtual bool loadPlayers(); // loads player dat form XML files
    virtual bool loadPlayerListFile(string fileName);   // loads list of player files from players.xml
    virtual bool loadPlayerFile(string fileName);   // loads data out of player XML files
    virtual bool loadUserFile(string fileName); // loads user file data from XML file(s)

protected:
    loader();
    loader(const loader&);
    loader& operator= (const loader&);

private:
    static loader *pInstance;
//	static string *pathArray;
    std::vector<std::string> playerFiles; // stores list of player xml files
    std::vector<std::string> teamFiles;	// stores list of team xml files


};


#endif

