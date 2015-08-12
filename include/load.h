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
#include <boost/shared_ptr.hpp>

#include "Ogre.h"
#include "SDL.h"

#include "tinyxml2.h"

#include "courtdata.h"
#include "gamestate.h"
#include "offenseplays.h"
#include "userinput.h"

using namespace std;

class loader
{
public:
    //static loader *Instance();
    static boost::shared_ptr<loader> Instance();

	std::vector<std::string> pathSplit(const std::string paths);
    string findFile(string fileName);
//	string * pathArray;

    std::vector<std::string> getPlayerFiles();    // returns list of player xml files
    void setPlayerFiles(std::vector<std::string> files);     // sets list of player xml files

    std::vector<std::string> getTeamFiles();    // returns list of player xml files
    void setTeamFiles(std::vector<std::string> files);    // sets list of player xml files

    std::vector<std::string> getOffensePlayFiles();    // returns list of offense play xml files
    void setOffensePlayFiles(std::vector<std::string> files);     // sets list of offense play xml files

    std::vector<std::string> getCourtFiles();   // returns list of court xml files
    void setCourtFiles(std::vector<std::string> set);  // sets list of court xml files

    std::vector<std::string> getUserInputFiles();   // returns list of user input xml files
    void setUserInputFiles(std::vector<std::string> set);  // sets list of user input xml files

    bool loadXMLFile(string fileName);

    int readFile(const char *sourceFile, char **destination);

    SDL_RWops *readBinaryFile(const char *sourceFile);

//    int readFile(const char *sourceFile, std:string *destination);

    // Teams
    std::vector<teamData> loadTeams();   // loads team data from XML files
    bool loadTeamListFile(string fileName); // loads list of team files from teams.xml
    teamData loadTeamFile(string fileName); // loads data from the team XML files

    // Players
    std::vector<playerData> loadPlayers(); // loads player data from XML files
    bool loadPlayerListFile(string fileName);   // loads list of player files from players.xml
    playerData loadPlayerFile(string fileName);   // loads data from the player XML files

    //Offense
    std::vector<offensePlays> loadOffensePlays();	// load offense plays from XML files
    bool loadOffensePlayListFile(string fileName);	// loads the list of offense play files from plays.xml
    offensePlays loadOffensePlayFile(string fileName);	// loads data from the offense play XML files

    // courts
    std::vector<courtData> loadCourts();	// load court XML files
    bool loadCourtListFile(string fileName);	// load the list of courts from courts.xml
    courtData loadCourtFile(string fileName);	// loads data from the court XML files.

    // user input
    std::vector<userInput> loadUserInputs();    // load user input XML files
    bool loadUserInputListFile(string fileName);    // load the list of user input configs from userinputs.xml
    userInput loadUserInputFile(string fileName);   // loads data from the user input XML files.

protected:
    loader();
    loader(const loader&);
    loader& operator= (const loader&);

private:
//    static loader *pInstance;
    static boost::shared_ptr<loader> pInstance;

//	static string *pathArray;
    std::vector<std::string> playerFiles; // stores list of player xml files
    std::vector<std::string> teamFiles;	// stores list of team xml files
    std::vector<std::string> offensePlayFiles;	// stores list of offense play xml files
    std::vector<std::string> courtFiles;	// stores list of court xml files
    std::vector<std::string> userInputFiles;    // stores list of court xml files


};


#endif

