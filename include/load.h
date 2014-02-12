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

#ifndef _LOAD_H_
#define _LOAD_H_

#include <string>
#include <vector>

#include "Ogre.h"
#include "tinyxml.h"

#include "gamestate.h"

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

