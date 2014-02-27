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

#include "config.h"
#include "load.h"
#include "playerdata.h"
#include "players.h"
#include "teams.h"

//#include "ubcapp.h"

//#include "boost/shared_ptr.hpp"

using namespace std;

loader::loader()
{

        //      cout << dah << endl;

//        pathArray = pathSplit(dataPath);
//      cout << pathArray[2] << endl;
//      exit(0);
}


loader* loader::pInstance = 0;
loader* loader::Instance()
{
    if (pInstance == 0)  // is it the first call?
    {
        pInstance = new loader; // create sole instance
    }
    return pInstance; // address of sole instance
}

// gets and sets playerFiles
std::vector<std::string> loader::getPlayerFiles()
{
    return(playerFiles);
}

void loader::setPlayerFiles(std::vector<string> files)
{
    playerFiles = files;
}

// gets and sets playerFiles
std::vector<std::string> loader::getTeamFiles()
{
    return(teamFiles);
}

void loader::setTeamFiles(std::vector<string> files)
{
    teamFiles = files;
}


// splits the path data into separate strings
std::vector<std::string> loader::pathSplit(const std::string paths)
{

    int x = 0;
//    string *stringArray = new string[1];
    std::vector<std::string> stringArray;
    const char delim = ':';
//        const string foo("./data:~/.ubc:/home/libolt/stuff/share/ubc:/usr/local/stuff/ubc");
    string::const_iterator p = paths.begin(), q;
    std::vector<std::string>::iterator it;

    while (true)
    {
        q = find(p, paths.end(), delim);

        stringArray.push_back(paths.substr(p - paths.begin(), q - p));

        std::vector<std::string> tempArray;

        for (it = stringArray.begin(); it != stringArray.end(); ++it)
        {
            tempArray.push_back(*it);
        }
        if (q == paths.end()) break;
        p = ++q;
        x++;
    }

    return(stringArray);
}

string loader::findFile(string fileName)
{
    // tries to load file from locations specified in the pathArray
    bool fileLoaded = false;
    string filePath;        // stores path to a file
    std::vector<std::string> pathArray;

#if OGRE_PLATFORM == OGRE_PLATFORM_ANDROID
    string dataPath = "";
#else
    string dataPath = UBC_DATADIR;
#endif

    Ogre::LogManager::getSingletonPtr()->logMessage("dataPath = " +dataPath);

    dataPath += "/";
    pathArray = pathSplit(dataPath);
    Ogre::LogManager::getSingletonPtr()->logMessage("pathArray[0] = " +pathArray[0]);
 //   LogManager::getSingletonPtr()->logMessage("pathArray[1] = " +pathArray[1]);


    for (int x = 0; x < 3; x++)
    {
        if (!fileLoaded)
        {
            filePath.clear();
            // builds path to players.txt
/*            if (x == 1)
            {
               filePath.append(":");
            }
            */
                filePath.append(pathArray[x]);
                Ogre::LogManager::getSingletonPtr()->logMessage("pathArray == " + pathArray[x]);

                filePath.append(fileName);
                Ogre::LogManager::getSingletonPtr()->logMessage("filePath = " +filePath);
                fstream fileOpen;
                //      if (!(lineupFont = TTF_OpenFont(file.c_str(), 20)));
                fileOpen.open(filePath.c_str(), ios::in);
                if (!fileOpen)
                {
                        Ogre::LogManager::getSingletonPtr()->logMessage("failed to load " + filePath);
        //                              exit(0);
                }

                else
                {
    //                              cout << "File Exists at: " << filePath << endl;
                    // opens players.txt
                    fileLoaded = true;
                }

        }
        else
        {
            return(filePath);
        }
    }
    if (!fileLoaded)
    {
        Ogre::LogManager::getSingletonPtr()->logMessage("failed to find file: " + fileName);
//FIXME        exit(0);
    }
    return ("");
}

bool loader::loadXMLFile(string fileName)
{
    TiXmlDocument doc(fileName.c_str());
    if (!doc.LoadFile()) return(false);

    TiXmlHandle hDoc(&doc);
    TiXmlElement* pElem;
    TiXmlHandle hRoot(0);

    string m_name, m_messages, WindowSettings;
	// block: name
    {
        pElem=hDoc.FirstChildElement().Element();
        // should always have a valid root but handle gracefully if it does
        if (!pElem) return(false);
        m_name=pElem->Value();
//        cout << m_name << endl;
//		exit(0);
        // save this for later
        hRoot=TiXmlHandle(pElem);
    }

    // block: string table
    {
        m_messages.clear(); // trash existing table

        pElem=hRoot.FirstChild( "Name" ).FirstChild().Element();
        for( pElem; pElem; pElem=pElem->NextSiblingElement())
        {
            string pKey=pElem->Value();
//            cout << pKey << endl;
            string pText=pElem->GetText();
//            cout << pText << endl;
            if (pKey.length() > 0 && pText.length() > 0)
            {
//				m_messages[pKey]=pText;
            }
        }
    }


    // block: connection
    {
        pElem=hRoot.FirstChild("Age").Element();
        if (pElem)
        {
            string pKey=pElem->Value();
//            cout << pKey << endl;
            string pText=pElem->GetText();
//            cout << pText << endl;
//			exit(0);
//			m_connection.ip=pElem->Attribute("ip");
//			pElem->QueryDoubleAttribute("timeout",&m_connection.timeout);
        }
    }
    return false;
}

bool loader::loadTeams()
{
#if OGRE_PLATFORM == OGRE_PLATFORM_ANDROID
    string teamList = findFile("teams.xml");
#else

    string teamList = findFile("teams/teams.xml");
#endif	
    Ogre::LogManager::getSingletonPtr()->logMessage("teamList = " +teamList);

//  cout << "teamList = " << teamList << endl;
    loadTeamListFile(teamList);

//    std::vector<std::string> teamFiles = load->getTeamFiles();
    std::vector<std::string>::iterator it;
    for (it = teamFiles.begin(); it != teamFiles.end(); ++it)
    {
        loadTeamFile(findFile("teams/" + *it));
        Ogre::LogManager::getSingletonPtr()->logMessage("team = " +*it);

    }

    return true;
}

bool loader::loadTeamListFile(string fileName)
{
    teams *team = teams::Instance();
    std::vector<std::string> teamName;
    std::vector<std::string> files;

//	players::playerData player;
    TiXmlDocument doc(fileName.c_str());

    if (!doc.LoadFile()) return(false);

    TiXmlHandle hDoc(&doc);
    TiXmlElement* pElem;
    TiXmlHandle hRoot(0);

    pElem=hDoc.FirstChildElement().Element();

    // should always have a valid root but handle gracefully if it does
    if (!pElem) return(false);

    // save this for later
    hRoot=TiXmlHandle(pElem);

    pElem=hRoot.FirstChild("TeamFile").Element();

    for( pElem; pElem; pElem=pElem->NextSiblingElement())
    {
//		string pText=pElem->GetText();
        files.push_back(pElem->GetText());

    }

/*    std::vector<std::string>::iterator it;
    for (it = files.begin(); it != files.end(); ++it)
    {
        cout << "team file = " << *it<< endl;
    }
*/

    teamFiles = files;  // sets teamFiles = to the std::vector data in files

//    setTeamFiles(teamFiles);

    return true;
}

bool loader::loadTeamFile(string fileName)
{
//    teams *team = teams::Instance();
	gameState *gameS = gameState::Instance();

	std::vector<teamData> teamDataInstance = gameS->getTeamDataInstance();
    teamData teamD;

    int ID;
    string City;
    string Name;
    string Coach;
    string Initials;
    string Logo;

    TiXmlDocument doc(fileName.c_str());

    if (!doc.LoadFile()) return(false);

    TiXmlHandle hDoc(&doc);

    TiXmlElement* pElem;

    TiXmlHandle hRoot(0);

    pElem=hDoc.FirstChildElement().Element();

    // should always have a valid root but handle gracefully if it does
    if (!pElem) return(false);

    // save this for later
    hRoot=TiXmlHandle(pElem);

    pElem=hRoot.FirstChild("ID").Element();
    if (pElem)
    {
        ID = atoi(pElem->GetText());
    }

    pElem=hRoot.FirstChild("City").Element();
    if (pElem)
    {
        City = pElem->GetText();
    }

    pElem=hRoot.FirstChild("Name").Element();
    if (pElem)
    {
        Name = pElem->GetText();
    }

    pElem=hRoot.FirstChild("Coach").Element();
    if (pElem)
    {
        Coach = pElem->GetText();
    }

    pElem=hRoot.FirstChild("Initials").Element();
    if (pElem)
    {
        Initials = pElem->GetText();
    }

    pElem=hRoot.FirstChild("Logo").Element();
    if (pElem)
    {
        Logo = pElem->GetText();
    }
//    Ogre::LogManager::getSingletonPtr()->logMessage("team name = " +Name);
//    Ogre::LogManager::getSingletonPtr()->logMessage("team city = " +City);


    teamD.setID(ID);
    teamD.setCity(City);
    teamD.setName(Name);
    teamD.setCoach(Coach);
    teamD.setInits(Initials);
    teamD.setLogoFile(Logo);

//    team->setTeamArray(teamD);
   teamDataInstance.push_back(teamD);
   gameS->setTeamDataInstances(teamDataInstance);

    return true;
}

bool loader::loadPlayers()
{
    string playerList = findFile("players/players.xml");
    loadPlayerListFile(playerList);
//    std::vector<std::string> playerFiles = load->getPlayerFiles();

    std::vector<std::string>::iterator it;
    for (it = playerFiles.begin(); it != playerFiles.end(); ++it)
    {

        loadPlayerFile(findFile("players/" + *it));
    }
    return true;
}

// loads XML file containing list of players and the files representing them
bool loader::loadPlayerListFile( string fileName)
{
    std::vector<std::string> playerFiles;
    players *player = players::Instance();
    TiXmlDocument doc(fileName.c_str());


    if (!doc.LoadFile()) return(false);

    TiXmlHandle hDoc(&doc);
    TiXmlElement* pElem;
    TiXmlHandle hRoot(0);

    pElem=hDoc.FirstChildElement().Element();
    // should always have a valid root but handle gracefully if it does
    if (!pElem) return(false);

    // save this for later
    hRoot=TiXmlHandle(pElem);

    pElem=hRoot.FirstChild("PlayerFile").Element();
    for( pElem; pElem; pElem=pElem->NextSiblingElement())
    {
        string pKey=pElem->Value();
//		cout << pKey << endl;
        string pText=pElem->GetText();
//		cout << pText << endl;
        playerFiles.push_back(pText);

    }

/*    std::vector<std::string>::iterator it;
    for (it = playerFiles.begin(); it != playerFiles.end(); ++it)
    {
        cout << *it << endl;
    }
    */

    setPlayerFiles(playerFiles);

    return true;
}

bool loader::loadPlayerFile(string fileName)
{
	gameState *gameS = gameState::Instance();
    playerData playerD;;
    std::vector<playerData> playerDataInstance = gameS->getPlayerDataInstance();
    string firstName;
    string lastName;
    int ID;
    int teamID;
    int age;
    int height;
    int weight;
    string model;
    string position;
    string teamInitials;
    playerData player;
    TiXmlDocument doc(fileName.c_str());


    if (!doc.LoadFile()) return(false);

    TiXmlHandle hDoc(&doc);
    TiXmlElement* pElem;
    TiXmlHandle hRoot(0);

    pElem=hDoc.FirstChildElement().Element();
    // should always have a valid root but handle gracefully if it does
    if (!pElem) return(false);

    // save this for later
    hRoot=TiXmlHandle(pElem);

    pElem=hRoot.FirstChild("Name").FirstChild().Element();

    for( pElem; pElem; pElem=pElem->NextSiblingElement())
    {
        string pKey=pElem->Value();
        if (pKey == "First")
        {
            firstName = pElem->GetText();
//            cout << "first name = " << firstName << endl;
        }
        if (pKey == "Last")
        {
            lastName = pElem->GetText();
//            cout << "last name = " << lastName << endl;
        }
    }

    pElem=hRoot.FirstChild("Age").Element();
    if (pElem)
    {
        age = atoi(pElem->GetText());
//        cout << "Age = " << age << endl;
    }

    pElem=hRoot.FirstChild("Height").Element();
    if (pElem)
    {
        height = atoi(pElem->GetText());
//        cout << "Height = " << height << endl;
    }

    pElem=hRoot.FirstChild("Weight").Element();
    if (pElem)
    {
        weight = atoi(pElem->GetText());
//        cout << "weight = " << weight << endl;
    }

    pElem=hRoot.FirstChild("Model").Element();
    if (pElem)
    {
        model = pElem->GetText();
//        cout << "model = " << model << endl;
    }

    pElem=hRoot.FirstChild("TeamInitials").Element();
    if (pElem)
    {
        teamInitials = pElem->GetText();
//        cout << "Team Initials = " << teamInitials << endl;
    }

    pElem=hRoot.FirstChild("Position").Element();
    if (pElem)
    {
        position = pElem->GetText();
//        cout << "Position = " << position << endl;
    }

    pElem=hRoot.FirstChild("ID").Element();
    if (pElem)
    {
        ID = atoi(pElem->GetText());
//        cout << "ID = " << ID << endl;
    }

    pElem=hRoot.FirstChild("TeamID").Element();
    if (pElem)
    {
        teamID = atoi(pElem->GetText());
//        cout << "ID = " << ID << endl;
    }

    playerD.setFirstName(firstName);
    playerD.setLastName(lastName);
    playerD.setAge(age);
    playerD.setHeight(height);
    playerD.setWeight(weight);
	playerD.setID(ID);
	playerD.setTeamID(teamID);
    playerD.setModel(model);
    playerD.setTeamInits(teamInitials);
    playerD.setPosition(position);

    playerDataInstance.push_back(playerD);

    gameS->setPlayerDataInstances(playerDataInstance);
    //	vector<players::playerData> playerN = playerG->getPlayer();

    return true;
}
bool loader::loadUserFile(string fileName)
{
    TiXmlDocument doc(fileName.c_str());
    if (!doc.LoadFile()) return(false);

    TiXmlHandle hDoc(&doc);
    TiXmlElement* pElem;
    TiXmlHandle hRoot(0);

    string m_name, m_messages, WindowSettings;
    // block: name
    {
        pElem=hDoc.FirstChildElement().Element();
    	// should always have a valid root but handle gracefully if it does
        if (!pElem) return(false);
        m_name=pElem->Value();
//        cout << m_name << endl;
//		exit(0);
        // save this for later
        hRoot=TiXmlHandle(pElem);
    }

    // block: string table
    {
        m_messages.clear(); // trash existing table

        pElem=hRoot.FirstChild( "Name" ).FirstChild().Element();
        for( pElem; pElem; pElem=pElem->NextSiblingElement())
        {
            string pKey=pElem->Value();
//            cout << pKey << endl;
            string pText=pElem->GetText();
//            cout << pText << endl;
            if (pKey.length() > 0 && pText.length() > 0)
            {
//				m_messages[pKey]=pText;
            }
        }
    }


    // block: connection
    {
        pElem=hRoot.FirstChild("Age").Element();
        if (pElem)
        {
            string pKey=pElem->Value();
//            cout << pKey << endl;
            string pText=pElem->GetText();
//            cout << pText << endl;
//			exit(0);
//			m_connection.ip=pElem->Attribute("ip");
//			pElem->QueryDoubleAttribute("timeout",&m_connection.timeout);
        }
    }
    return true;
}

