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

#ifndef _LOAD_H_
#define _LOAD_H_

#include <string>
#include <vector>

#include "Ogre.h"
#include "tinyxml.h"

#include "gamestate.h"
#include "offenseplays.h"

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

    std::vector<std::string> getPlayerFiles();    // returns list of player xml files
    void setPlayerFiles(std::vector<std::string> files);     // sets list of player xml files

    std::vector<std::string> getTeamFiles();    // returns list of player xml files
    void setTeamFiles(std::vector<std::string> files);    // sets list of player xml files

    std::vector<std::string> getOffensePlayFiles();    // returns list of offense play xml files
    void setOffensePlayFiles(std::vector<std::string> files);     // sets list of offense play xml files

    std::vector<std::string> getCourtFiles();   // returns list of court xml files
    void setCourtFiles(std::vector<std::string> set);  // sets list of court xml files

    bool loadXMLFile(string fileName);
    int readFile(const char *sourceFile, char **destination);
//    int readFile(const char *sourceFile, Ogre::String *destination);

    // Teams
    bool loadTeams();   // loads team data from XML files
    bool loadTeamListFile(string fileName); // loads list of team files from teams.xml
    bool loadTeamFile(string fileName); // loads data from the team XML files

    // Players
    bool loadPlayers(); // loads player data from XML files
    bool loadPlayerListFile(string fileName);   // loads list of player files from players.xml
    bool loadPlayerFile(string fileName);   // loads data from the player XML files
    bool loadUserFile(string fileName); // loads user file data from XML file(s)

    //Offense
    std::vector<offensePlays> loadOffensePlays();	// load offense plays from XML files
    bool loadOffensePlayListFile(string fileName);	// loads the list of offense play files from plays.xml
    offensePlays loadOffensePlayFile(string fileName);	// loads data from the offense play XML files


protected:
    loader();
    loader(const loader&);
    loader& operator= (const loader&);

private:
    static loader *pInstance;
//	static string *pathArray;
    std::vector<std::string> playerFiles; // stores list of player xml files
    std::vector<std::string> teamFiles;	// stores list of team xml files
    std::vector<std::string> offensePlayFiles;	// stores list of offense play xml files


};


#endif

