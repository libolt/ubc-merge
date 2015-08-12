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
 *
 *   You should have received a copy of the GNU General Public License     *
 *   along with this program; if not, write to the                         *
 *   Free Software Foundation, Inc.,                                       *
 *   59 Temple Place - Suite 330, Boston, MA  02111-1307, USA.             *
 ***************************************************************************/

 
#ifdef __ANDROID__
#include "android-config.h"
#else
#include "config.h"
#endif

#include "conversion.h"
#include "load.h"
#include "load.h"
#include "logging.h"
#include "playerdata.h"
#include "players.h"
#include "renderengine.h"
#include "teams.h"

#if OGRE_PLATFORM == OGRE_PLATFORM_ANDROID
#include "android.h"
#endif

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


//loader* loader::pInstance = 0;
boost::shared_ptr<loader> loader::pInstance;

//loader* loader::Instance()
boost::shared_ptr<loader> loader::Instance()
{
    if (pInstance == 0)  // is it the first call?
    {
//        pInstance = new loader; // create sole instance
        boost::shared_ptr<loader> tInstance(new loader);
        pInstance = tInstance;

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

std::vector<std::string> loader::getOffensePlayFiles()
{
	return (offensePlayFiles);
}
void loader::setOffensePlayFiles(std::vector<std::string> files)
{
	offensePlayFiles = files;
}

std::vector<std::string> loader::getCourtFiles()   // returns list of court xml files
{
	return (courtFiles);
}
void loader::setCourtFiles(std::vector<std::string> set)  // sets list of court xml files
{
	courtFiles = set;
}

std::vector<std::string> loader::getUserInputFiles()   // returns list of user input xml files
{
    return (userInputFiles);
}
void loader::setUserInputFiles(std::vector<std::string> set)  // sets list of user input xml files
{
    userInputFiles = set;
}

// loads an xml file using SDL so that it can
// be passed to TinyXML
int loader::readFile(const char *sourceFile, char **destination)
//int loader::readFile(const char *sourceFile, std::string *destination)
{
    //conversion *convert = conversion::Instance();
    boost::shared_ptr<conversion> convert = conversion::Instance();
    boost::shared_ptr<renderEngine> render = renderEngine::Instance();
	int BLOCK_SIZE = 8;
	int MAX_BLOCKS = 1024;

///#if OGRE_PLATFORM == OGRE_PLATFORM_ANDROID
//	Ogre::DataStreamPtr fileData = render->openAPKFile("teamd.xml");
//	destination = new std::string;
///	destination = (char**)fileData->getAsString().c_str();
//#else
//    char *contents = NULL;
//	readFile(fileName.c_str(), &contents);
//	fileContents = toString(contents);
//#endif
    // Open the file
//    SDL_RWops *file;
    logMsg("sourceFile = " +convert->toString(sourceFile));
//	logMsg(SDL_AndroidGetInternalStoragePath());
//    file = SDL_RWFromFile("teamd.xml", "rb");

    SDL_RWops *file;
	file = SDL_RWFromFile(sourceFile, "r");
//	SDL_RWops *file = openAPKFile(filename);
//	if (SDL_RWFromFile(name.c_str(), "r") != 0)
/*	{
		fprintf(stderr,
                "\nUnable to load file:  %s\n",
                SDL_GetError()
               );
	}*/
    logMsg("Seek to beginning of file");
	size_t fileLength = SDL_RWseek(file, 0, SEEK_END);
	(*destination) = new char[fileLength + 1]; // allow an extra characterfor '\0'

//    ASSERT(file, "Opening file using SDL_RWops");
	// resets the file to beginnin
	SDL_RWseek(file, 0, SEEK_SET);
    // Read text from file
	std::string *contents = new std::string;
    int n_blocks = SDL_RWread(file, (*destination), 1, fileLength+1);
    logMsg("contents = " +convert->toString(contents));
    (*destination)[fileLength] = '\0';
    logMsg("destination = " +convert->toString((*destination)));
//    exit(0);
#if OGRE_PLATFORM == OGRE_PLATFORM_ANDROID
    logMsg("destination = " +convert->toString(destination));
#endif

    // BLOCK_SIZE = 8, MAX_BLOCKS = 1024
    SDL_RWclose(file);

    // Make sure the operation was successful
 //   ASSERT(n_blocks >= 0, "Reading blocks of data from SDL_RWops");
//    WARN_IF(n_blocks == MAX_BLOCKS, "Reading data from SDL_RWops","Buffer full so may be too small for data");
//#endif
    // Success!
    return EXIT_SUCCESS;
}

SDL_RWops *loader::readBinaryFile(const char *sourceFile)  // reads in a binary file
{
    //conversion *convert = conversion::Instance();
    boost::shared_ptr<conversion> convert = conversion::Instance();
    
    int BLOCK_SIZE = 8;
	int MAX_BLOCKS = 1024;
    
    logMsg("sourceFile = " +convert->toString(sourceFile));

    SDL_RWops *file;
    file = SDL_RWFromFile(sourceFile, "rb");

    return (file);
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
    string filePath = "";        // stores path to a file
    std::vector<std::string> pathArray;

#if OGRE_PLATFORM == OGRE_PLATFORM_ANDROID
    string dataPath = "";
#else
    string dataPath = UBC_DATADIR;
#endif

    logMsg("dataPath = " +dataPath);
#if OGRE_PLATFORM == OGRE_PLATFORM_ANDROID
    filePath = fileName;
#else
    dataPath += "/";

    pathArray = pathSplit(dataPath);

    logMsg("pathArray[0] = " +pathArray[0]);
 //   logMsg("pathArray[1] = " +pathArray[1]);


    for (int x = 0; x < 3; x++)
    {
        if (!fileLoaded)
        {
            filePath.clear();
            // builds path to players.txt
//            if (x == 1)
//            {
//               filePath.append(":");
//            }

                filePath.append(pathArray[x]);
                logMsg("pathArray == " + pathArray[x]);

				filePath.append(fileName);
                logMsg("filePath = " +filePath);
                fstream fileOpen;
                //      if (!(lineupFont = TTF_OpenFont(file.c_str(), 20)));
                fileOpen.open(filePath.c_str(), ios::in);
                if (!fileOpen)
                {
                    logMsg("failed to load " + filePath);
        //                              exit(0);
                }

                else
                {
    //                             logMsg("File Exists at: " +filePath);
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
        logMsg("failed to find file: " + fileName);
        exit(0);
    }
#endif
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
//             logMsg(pKey);
            string pText=pElem->GetText();
//           logMsg(pText);
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
//            logMsg(pKey);
            string pText=pElem->GetText();
//            logMsgpText);
//			exit(0);
//			m_connection.ip=pElem->Attribute("ip");
//			pElem->QueryDoubleAttribute("timeout",&m_connection.timeout);
        }
    }
    return false;
}

std::vector<teamData> loader::loadTeams()     // load court settings from XML files
{
    boost::shared_ptr<conversion> convert = conversion::Instance();
    std::vector<teamData> teams;
#if OGRE_PLATFORM == OGRE_PLATFORM_ANDROID
        string teamList = "data/teams/teams.xml";
#else
    string teamList = findFile("teams/teams.xml");
#endif
        loadTeamListFile(teamList);
//    std::vector<std::string> playerFiles = load->getPlayerFiles();

    logMsg("teamFiles.size() = " +convert->toString(teamFiles.size()));

//    exit(0);
    std::vector<std::string>::iterator it;
    for (it = teamFiles.begin(); it != teamFiles.end(); ++it)
    {
                logMsg("teamFile = " +*it);

#if OGRE_PLATFORM == OGRE_PLATFORM_ANDROID
                teams.push_back(loadTeamFile("data/teams/" + *it));
#else
        teams.push_back(loadTeamFile(findFile("teams/" + *it)));
#endif
//        exit(0);
    }

        return (teams);
}


bool loader::loadTeamListFile(string fileName)
{
    //conversion *convert = conversion::Instance();
    boost::shared_ptr<conversion> convert = conversion::Instance();
    
    boost::shared_ptr<renderEngine> render = renderEngine::Instance();
    teams *team = teams::Instance();

    std::vector<std::string> teamName;
    std::vector<std::string> files;

//	players::playerData player;
//#if OGRE_PLATFORM == OGRE_PLATFORM_ANDROID
//    const char *file = "teams.xml";
//#else
//	const char *file = fileName.c_str();
//#endif 

//	char *fileContents = NULL;
    std::string fileContents;
    //TiXmlDocument doc;
    tinyxml2::XMLDocument doc;
    logMsg(fileName);
	logMsg("bate");
//#if OGRE_PLATFORM == OGRE_PLATFORM_ANDROID
//	Ogre::DataStreamPtr fileData = render->openAPKFile(fileName);
//	fileContents = fileData->getAsString();
//#else
    char *contents = NULL;
	readFile(fileName.c_str(), &contents);
//	logMsg("read contents = " +contents);
//	exit(0);
    fileContents = convert->toString(contents);
//#endif
//    readFile(fileName.c_str(), &fileContents);
	logMsg("barf");
	logMsg("fileContents == " +fileContents);
//	exit(0);
//	if (!doc.Parse(fileData->getAsString().c_str()))
    static const char* xml = "<element/>";
    doc.Parse(contents);
    if (doc.Error())
    {
        logMsg("Unable to parse teams.xml file");
        logMsg("Error ID = " +convert->toString(doc.ErrorID()));
        logMsg(convert->toString(doc.GetErrorStr1()));
        logMsg(convert->toString(doc.GetErrorStr2()));
        exit(0);
    }
	//TiXmlHandle hDoc(&doc);
    tinyxml2::XMLHandle hDoc(&doc);
    //TiXmlElement* pElem;
    tinyxml2::XMLElement *pElem;
    //TiXmlHandle hRoot(0);
    tinyxml2::XMLHandle hRoot(0);
    //tinyxml2::XMLText *textNode = doc.FirstChildElement("Teams")->FirstChildElement("TeamFile")->ToText();
    //logMsg("first element = " +convert->toString(textNode->Value()));
    pElem=hDoc.FirstChildElement().ToElement();
    // should always have a valid root but handle gracefully if it does
    if (!pElem)
    {
        logMsg("Unable to find a valid teamListFile root!");
        exit(0);
    } 

    // save this for later
    //hRoot=TiXmlHandle(pElem);
    hRoot = tinyxml2::XMLHandle(pElem);
    
    //pElem=hRoot.FirstChild("TeamFile").Element();
    pElem=hRoot.FirstChild().ToElement();
    
    for( pElem; pElem; pElem=pElem->NextSiblingElement())
    {
//		string pText=pElem->GetText();
        files.push_back(pElem->GetText());
        logMsg("teamFile = " +convert->toString(pElem->GetText()));
    }

    std::vector<std::string>::iterator it;
    for (it = files.begin(); it != files.end(); ++it)
    {
        logMsg("team file = " +*it);
    }

    logMsg("files.size() = " +convert->toString(files.size()));
    teamFiles = files;  // sets teamFiles = to the std::vector data in files

    setTeamFiles(teamFiles);

    return true;
}


teamData loader::loadTeamFile(string fileName)
{
//    teams *team = teams::Instance();
    //conversion *convert = conversion::Instance();
    boost::shared_ptr<conversion> convert = conversion::Instance();
    //gameState *gameS = gameState::Instance();
    boost::shared_ptr<gameState> gameS = gameState::Instance();
    boost::shared_ptr<renderEngine> render = renderEngine::Instance();
	std::vector<teamData> teamDataInstance = gameS->getTeamDataInstance();
    teamData teamD;

    int ID;
    string City;
    string Name;
    string Coach;
    string Initials;
    string Logo;

//    TiXmlDocument doc(fileName.c_str());
//    if (!doc.LoadFile()) return(false);
//	const char *fileContents = NULL;
	std::string fileContents;
	//TiXmlDocument doc;
    tinyxml2::XMLDocument doc;
	//    Ogre::LogManager::getSingletonPtr()->logMessage("file = " +file);
//	readFile(fileName.c_str(), &fileContents);
/*#if OGRE_PLATFORM == OGRE_PLATFORM_ANDROID
	Ogre::DataStreamPtr fileData = render->openAPKFile(fileName);
	fileContents = fileData->getAsString();
#else*/
    char *contents = NULL;
	readFile(fileName.c_str(), &contents);
    fileContents = convert->toString(contents);
//#endif
/*	if (!doc.Parse(contents))
	{
	    logMsg("Unable to parse team file");
		//exit(0);
	}
*/
    doc.Parse(contents);
    if (doc.Error())
    {
        logMsg("Unable to parse teams.xml file");
        logMsg("Error ID = " +convert->toString(doc.ErrorID()));
        logMsg(convert->toString(doc.GetErrorStr1()));
        logMsg(convert->toString(doc.GetErrorStr2()));
        exit(0);
    }
    //TiXmlHandle hDoc(&doc);
    tinyxml2::XMLHandle hDoc(&doc);
    
    //TiXmlElement* pElem;
    tinyxml2::XMLElement *pElem;
    
    //TiXmlHandle hRoot(0);
    tinyxml2::XMLHandle hRoot(0);
    
    //pElem=hDoc.FirstChildElement().Element();
    pElem=hDoc.FirstChildElement().ToElement();
    
    // should always have a valid root but handle gracefully if it does
    if (!pElem)
    {
        logMsg("Unable to find valid root. Exiting!");
        exit(0);
    } 

    // save this for later
    //hRoot=TiXmlHandle(pElem);
    hRoot = tinyxml2::XMLHandle(pElem);
    
    //pElem=hRoot.FirstChild("ID").Element();
    pElem=hRoot.FirstChild().ToElement();
    if (pElem)
    {
        ID = convert->toInt(pElem->GetText());
        logMsg("ID == " +convert->toString(ID));
    }

    //pElem=hRoot.FirstChild("City").Element();
    pElem=pElem->NextSiblingElement()->ToElement();
    if (pElem)
    {
        City = pElem->GetText();
        logMsg("City == " +City);
    }

    //pElem=hRoot.FirstChild("Name").Element();
    pElem=pElem->NextSiblingElement()->ToElement();
    if (pElem)
    {
        Name = pElem->GetText();
        logMsg("Name == " +Name);
    }

    //pElem=hRoot.FirstChild("Coach").Element();
    pElem=pElem->NextSiblingElement()->ToElement();
    if (pElem)
    {
        Coach = pElem->GetText();
        logMsg("Coach == " +Coach);
    }

    //pElem=hRoot.FirstChild("Initials").Element();
    pElem=pElem->NextSiblingElement()->ToElement();
    if (pElem)
    {
        Initials = pElem->GetText();
        logMsg("Initials == " +Initials);
    }

    //pElem=hRoot.FirstChild("Logo").Element();
    pElem=pElem->NextSiblingElement()->ToElement();
    if (pElem)
    {
        Logo = pElem->GetText();
        logMsg("Logo == " +Logo);
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
//   teamDataInstance.push_back(teamD);
//   gameS->setTeamDataInstance(teamDataInstance);

    return (teamD);
}

std::vector<playerData> loader::loadPlayers()
{
    std::vector<playerData> players;
#if OGRE_PLATFORM == OGRE_PLATFORM_ANDROID
	string playerList = "data/players/players.xml";
#else
    string playerList = findFile("players/players.xml");
#endif
	loadPlayerListFile(playerList);
//    std::vector<std::string> playerFiles = load->getPlayerFiles();

    std::vector<std::string>::iterator it;
    for (it = playerFiles.begin(); it != playerFiles.end(); ++it)
    {
		logMsg("playerFile = " +*it);
#if OGRE_PLATFORM == OGRE_PLATFORM_ANDROID
        players.push_back(loadPlayerFile("data/players/" + *it));
#else
        players.push_back(loadPlayerFile(findFile("players/" + *it)));
#endif
    }
    return (players);
}

// loads XML file containing list of players and the files representing them
bool loader::loadPlayerListFile( string fileName)
{
    //conversion *convert = conversion::Instance();
    boost::shared_ptr<conversion> convert = conversion::Instance();
    boost::shared_ptr<renderEngine> render = renderEngine::Instance();
    std::vector<std::string> playerFiles;
    players *player = players::Instance();

//	char *fileContents = NULL;
	std::string fileContents;
	//TiXmlDocument doc;
	tinyxml2::XMLDocument doc;
	//    Ogre::LogManager::getSingletonPtr()->logMessage("file = " +file);
//	readFile(fileName.c_str(), &fileContents);
    logMsg(fileName);
/*#if OGRE_PLATFORM == OGRE_PLATFORM_ANDROID
	Ogre::DataStreamPtr fileData = render->openAPKFile(fileName);
	fileContents = fileData->getAsString();
#else*/
    char *contents = NULL;
	readFile(fileName.c_str(), &contents);
    fileContents = convert->toString(contents);
//#endif

/*    TiXmlDocument doc(fileName.c_str());
    if (!doc.LoadFile()) return(false);
*/

/*	if (!doc.Parse(contents))
	{
		logMsg("Unable to parse players.xml file");
//		exit(0);
	}
*/
    doc.Parse(contents);
    if (doc.Error())
    {
        logMsg("Unable to parse teams.xml file");
        logMsg("Error ID = " +convert->toString(doc.ErrorID()));
        logMsg(convert->toString(doc.GetErrorStr1()));
        logMsg(convert->toString(doc.GetErrorStr2()));
        exit(0);
    }
    //TiXmlHandle hDoc(&doc);
    tinyxml2::XMLHandle hDoc(&doc);

    //TiXmlElement* pElem;
    tinyxml2::XMLElement *pElem;
    
    //TiXmlHandle hRoot(0);
    tinyxml2::XMLHandle hRoot(0);

    pElem=hDoc.FirstChildElement().ToElement();
    // should always have a valid root but handle gracefully if it does
    if (!pElem) return(false);

    // save this for later
    //hRoot=TiXmlHandle(pElem);
    hRoot = tinyxml2::XMLHandle(pElem);

    //pElem=hRoot.FirstChild("PlayerFile").ToElement();
    pElem=hRoot.FirstChild().ToElement();
    for( pElem; pElem; pElem=pElem->NextSiblingElement())
    {
        string pKey=pElem->Value();
//		cout << pKey << endl;
        string pText=pElem->GetText();
        logMsg("pText == " +pText);
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

playerData loader::loadPlayerFile(string fileName)
{
    //conversion *convert = conversion::Instance();
    boost::shared_ptr<conversion> convert = conversion::Instance();
    //gameState *gameS = gameState::Instance();
	boost::shared_ptr<gameState> gameS = gameState::Instance();
    boost::shared_ptr<renderEngine> render = renderEngine::Instance();

    playerData playerD;;
    std::vector<playerData> playerDataInstance = gameS->getPlayerDataInstance();
    string firstName;
    string lastName;
    string model;
    string position;
    int ID = 0;
    int teamID = 0;
    int age = 0;
    int height = 0;
    int weight = 0;
    int shooting = 0;
    int freeThrow = 0;
    int layup = 0;
    int dunk = 0;
    int inside = 0;
    int midRange = 0;
    int threePoint = 0;
    int ballHandling = 0;
    int ballSecurity = 0;
    int passing = 0;
    int pickSetting = 0;
    int offenseAwareness = 0;
    int defenseAwareness = 0;
    int offenseRebound = 0;
    int defenseRebound = 0;
    int blocking = 0;
    int stealing = 0;
    int interiorDefense = 0;
    int midRangeDefense = 0;
    int perimeterDefense = 0;
    int hustle = 0;
    int speed = 0;
    int quickness = 0;
    int fatigue = 0;
    int durability = 0;
    int demeanor = 0;
    int improvability = 0;

    playerData player;

//    TiXmlDocument doc(fileName.c_str());
//    if (!doc.LoadFile()) return(false);

//	char *fileContents = NULL;
	std::string fileContents;
	//TiXmlDocument doc;
	tinyxml2::XMLDocument doc;
	//    Ogre::LogManager::getSingletonPtr()->logMessage("file = " +file);
//	readFile(fileName.c_str(), &fileContents);

/*#if OGRE_PLATFORM == OGRE_PLATFORM_ANDROID
	Ogre::DataStreamPtr fileData = render->openAPKFile(fileName);
	fileContents = fileData->getAsString();
#else*/
    char *contents = NULL;
	readFile(fileName.c_str(), &contents);
    logMsg("loading: "+fileName);
    fileContents = convert->toString(contents);
    logMsg("fileContents = " +fileContents);
//#endif
/*	if (!doc.Parse(contents))
	{
		logMsg("Unable to parse player file");
//		exit(0);
	}
*/
    doc.Parse(contents);
    if (doc.Error())
    {
        logMsg("Unable to parse teams.xml file");
        logMsg("Error ID = " +convert->toString(doc.ErrorID()));
        logMsg(convert->toString(doc.GetErrorStr1()));
        logMsg(convert->toString(doc.GetErrorStr2()));
        exit(0);
    }
    //TiXmlHandle hDoc(&doc);
    tinyxml2::XMLHandle hDoc(&doc);
    
    //TiXmlElement* pElem;
    tinyxml2::XMLElement *pElem;
    tinyxml2::XMLElement *rootElement;
    tinyxml2::XMLElement *childElement;

    //TiXmlHandle hRoot(0);
    tinyxml2::XMLHandle hRoot(0);


    //pElem=hRoot.FirstChild("ID").Element();
    pElem=hDoc.FirstChildElement().ToElement();
    // should always have a valid root but handle gracefully if it does
    if (!pElem)
    {
        logMsg("Unable to find a valid player file root!");
        exit(0);
    }

    hRoot = tinyxml2::XMLHandle(pElem);

    pElem=hRoot.FirstChild().ToElement();
    if(pElem)
    {
        ID = convert->toInt(pElem->GetText());
        logMsg("PlayerID == " +convert->toString(ID));
    }

    //pElem=hRoot.FirstChild("Name").FirstChild().ToElement();
    pElem=pElem->NextSiblingElement()->ToElement();
    if (pElem)
    {
        teamID = convert->toInt(pElem->GetText());
        logMsg("teamID == " +convert->toString(teamID));
    }
    logMsg("pElem.Name() = " +convert->toString(pElem->GetText()));
    pElem=pElem->NextSiblingElement()->ToElement();
    if(pElem)
    {
        childElement=pElem->FirstChildElement()->ToElement();
        string pKey=childElement->Value();
        if (pKey == "First")
        {
            firstName = childElement->GetText();
            logMsg("First Name: " +firstName);
        }
        childElement=childElement->NextSiblingElement()->ToElement();
        pKey=childElement->Value();
        if (pKey == "Last")
        {
            lastName = childElement->GetText();
            logMsg("Last Name: " +lastName);
        }

    }

    //pElem=hRoot.FirstChild("Age").ToElement();
    pElem=pElem->NextSiblingElement()->ToElement();
    if (pElem)
    {
        age = convert->toInt(pElem->GetText());
        logMsg("Age = " +convert->toString(age));
    }

    //pElem=hRoot.FirstChild("Height").ToElement();
    pElem=pElem->NextSiblingElement()->ToElement();
    if (pElem)
    {
        height = convert->toInt(pElem->GetText());
        logMsg("Height = " +convert->toString(height));
    }

    //pElem=hRoot.FirstChild("Weight").ToElement();
    pElem=pElem->NextSiblingElement()->ToElement();
    if (pElem)
    {
        weight = convert->toInt(pElem->GetText());
        logMsg("Weight = " +convert->toString(weight));
    }

    //pElem=hRoot.FirstChild("Model").ToElement();
    pElem=pElem->NextSiblingElement()->ToElement();
    if (pElem)
    {
        model = pElem->GetText();
        logMsg("Model = " +model);
    }

    //pElem=hRoot.FirstChild("Position").ToElement();
    pElem=pElem->NextSiblingElement()->ToElement();
    if (pElem)
    {
        position = pElem->GetText();
        logMsg("position = " +position);
    }

	//pElem=hRoot.FirstChild("Shooting").ToElement();
    pElem=pElem->NextSiblingElement()->ToElement();
    if (pElem)
    {
        shooting = convert->toInt(pElem->GetText());
        logMsg("shooting = " +convert->toString(shooting));
    }

	//pElem=hRoot.FirstChild("FreeThrow").ToElement();
    pElem=pElem->NextSiblingElement()->ToElement();
    if (pElem)
    {
        freeThrow = convert->toInt(pElem->GetText());
//        cout << "Team Initials = " << teamInitials << endl;
    }

	//pElem=hRoot.FirstChild("Layup").ToElement();
    pElem=pElem->NextSiblingElement()->ToElement();
    if (pElem)
    {
        layup = convert->toInt(pElem->GetText());
//        cout << "Team Initials = " << teamInitials << endl;
    }

	//pElem=hRoot.FirstChild("Dunk").ToElement();
    pElem=pElem->NextSiblingElement()->ToElement();
    if (pElem)
    {
        dunk = convert->toInt(pElem->GetText());
//        cout << "Team Initials = " << teamInitials << endl;
    }

	//pElem=hRoot.FirstChild("Inside").ToElement();
    pElem=pElem->NextSiblingElement()->ToElement();
    if (pElem)
    {
        inside = convert->toInt(pElem->GetText());
//        cout << "Team Initials = " << teamInitials << endl;
    }

	//pElem=hRoot.FirstChild("Midrange").ToElement();
    pElem=pElem->NextSiblingElement()->ToElement();
    if (pElem)
    {
        midRange = convert->toInt(pElem->GetText());
//        cout << "Team Initials = " << teamInitials << endl;
    }

	//pElem=hRoot.FirstChild("ThreePoint").ToElement();
    pElem=pElem->NextSiblingElement()->ToElement();
    if (pElem)
    {
        threePoint = convert->toInt(pElem->GetText());
//        cout << "Team Initials = " << teamInitials << endl;
    }

	//pElem=hRoot.FirstChild("BallHandling").ToElement();
    pElem=pElem->NextSiblingElement()->ToElement();
    if (pElem)
    {
        ballHandling = convert->toInt(pElem->GetText());
//        cout << "Team Initials = " << teamInitials << endl;
    }

	//pElem=hRoot.FirstChild("BallSecurity").ToElement();
    pElem=pElem->NextSiblingElement()->ToElement();
    if (pElem)
    {
        ballSecurity = convert->toInt(pElem->GetText());
//        cout << "Team Initials = " << teamInitials << endl;
    }

	//pElem=hRoot.FirstChild("Passing").ToElement();
    pElem=pElem->NextSiblingElement()->ToElement();
    if (pElem)
    {
        passing = convert->toInt(pElem->GetText());
//        cout << "Team Initials = " << teamInitials << endl;
    }

	//pElem=hRoot.FirstChild("PickSetting").ToElement();
    pElem=pElem->NextSiblingElement()->ToElement();
    if (pElem)
    {
        pickSetting = convert->toInt(pElem->GetText());
//        cout << "Team Initials = " << teamInitials << endl;
    }

	//pElem=hRoot.FirstChild("offenseAwareness").ToElement();
    pElem=pElem->NextSiblingElement()->ToElement();
    if (pElem)
    {
        offenseAwareness = convert->toInt(pElem->GetText());
//        cout << "Team Initials = " << teamInitials << endl;
    }

	//pElem=hRoot.FirstChild("DefenseAwareness").ToElement();
    pElem=pElem->NextSiblingElement()->ToElement();
    if (pElem)
    {
        defenseAwareness = convert->toInt(pElem->GetText());
//        cout << "Team Initials = " << teamInitials << endl;
    }

	//pElem=hRoot.FirstChild("OffenseRebound").Element();
    pElem=pElem->NextSiblingElement()->ToElement();
    if (pElem)
    {
        offenseRebound = convert->toInt(pElem->GetText());
//        cout << "Team Initials = " << teamInitials << endl;
    }

	//pElem=hRoot.FirstChild("DefenseRebound").ToElement();
    pElem=pElem->NextSiblingElement()->ToElement();
    if (pElem)
    {
        defenseRebound = convert->toInt(pElem->GetText());
//        cout << "Team Initials = " << teamInitials << endl;
    }

	//pElem=hRoot.FirstChild("Blocking").ToElement();
    pElem=pElem->NextSiblingElement()->ToElement();
    if (pElem)
    {
        blocking = convert->toInt(pElem->GetText());
//        cout << "Team Initials = " << teamInitials << endl;
    }

	//pElem=hRoot.FirstChild("Stealing").ToElement();
    pElem=pElem->NextSiblingElement()->ToElement();
    if (pElem)
    {
        stealing = convert->toInt(pElem->GetText());
//        cout << "Team Initials = " << teamInitials << endl;
    }

	//pElem=hRoot.FirstChild("InteriorDefense").ToElement();
    pElem=pElem->NextSiblingElement()->ToElement();
    if (pElem)
    {
        interiorDefense = convert->toInt(pElem->GetText());
//        cout << "Team Initials = " << teamInitials << endl;
    }

	//pElem=hRoot.FirstChild("MidrangeDefense").ToElement();
    pElem=pElem->NextSiblingElement()->ToElement();
    if (pElem)
    {
        midRangeDefense = convert->toInt(pElem->GetText());
//        cout << "Team Initials = " << teamInitials << endl;
    }

	//pElem=hRoot.FirstChild("PerimeterDefense").ToElement();
    pElem=pElem->NextSiblingElement()->ToElement();
    if (pElem)
    {
        perimeterDefense = convert->toInt(pElem->GetText());
//        cout << "Team Initials = " << teamInitials << endl;
    }

	//pElem=hRoot.FirstChild("Hustle").ToElement();
    pElem=pElem->NextSiblingElement()->ToElement();
    if (pElem)
    {
        hustle = convert->toInt(pElem->GetText());
//        cout << "Team Initials = " << teamInitials << endl;
    }

	//pElem=hRoot.FirstChild("Speed").ToElement();
    pElem=pElem->NextSiblingElement()->ToElement();
    if (pElem)
    {
        speed = convert->toInt(pElem->GetText());
//        cout << "Team Initials = " << teamInitials << endl;
    }

	//pElem=hRoot.FirstChild("Quickness").ToElement();
    pElem=pElem->NextSiblingElement()->ToElement();
    if (pElem)
    {
        quickness = convert->toInt(pElem->GetText());
//        cout << "Team Initials = " << teamInitials << endl;
    }

	//pElem=hRoot.FirstChild("Fatigue").ToElement();
    pElem=pElem->NextSiblingElement()->ToElement();
    if (pElem)
    {
        fatigue = convert->toInt(pElem->GetText());
//        cout << "Team Initials = " << teamInitials << endl;
    }

	//pElem=hRoot.FirstChild("Durability").ToElement();
    pElem=pElem->NextSiblingElement()->ToElement();
    if (pElem)
    {
        durability = convert->toInt(pElem->GetText());
//        cout << "Team Initials = " << teamInitials << endl;
    }

	//pElem=hRoot.FirstChild("Demeanor").ToElement();
    pElem=pElem->NextSiblingElement()->ToElement();
    if (pElem)
    {
        demeanor = convert->toInt(pElem->GetText());
//        cout << "Team Initials = " << teamInitials << endl;
    }

	//pElem=hRoot.FirstChild("Improvability").ToElement();
    pElem=pElem->NextSiblingElement()->ToElement();
    if (pElem)
    {
        improvability = convert->toInt(pElem->GetText());
//        cout << "Team Initials = " << teamInitials << endl;
    }
/*
	pElem=hRoot.FirstChild("TeamInitials").ToElement();
    if (pElem)
    {
        teamInitials = convert->toInt(pElem->GetText());
//        cout << "Team Initials = " << teamInitials << endl;
    }

	pElem=hRoot.FirstChild("TeamInitials").ToElement();
    if (pElem)
    {
        teamInitials = convert->toInt(pElem->GetText());
//        cout << "Team Initials = " << teamInitials << endl;
    }
*/
    playerD.setFirstName(firstName);
    playerD.setLastName(lastName);
    playerD.setAge(age);
    playerD.setHeight(height);
    playerD.setWeight(weight);
	playerD.setID(ID);
	playerD.setTeamID(teamID);
    playerD.setModel(model);
//    playerD.setTeamInits(teamInitials);
    playerD.setPosition(position);
    playerD.setShooting(shooting);
    playerD.setFreeThrow(freeThrow);
    playerD.setLayup(layup);
    playerD.setDunk(dunk);
    playerD.setInside(inside);
    playerD.setMidRange(midRange);
    playerD.setThreePoint(threePoint);
    playerD.setBallHandling(ballHandling);
    playerD.setBallSecurity(ballSecurity);
    playerD.setPassing(passing);
    playerD.setPickSetting(pickSetting);
    playerD.setOffenseAwareness(offenseAwareness);
    playerD.setDefenseAwareness(defenseAwareness);
    playerD.setOffenseRebound(offenseRebound);
    playerD.setDefenseRebound(defenseRebound);
    playerD.setBlocking(blocking);
    playerD.setStealing(stealing);
    playerD.setInteriorDefense(interiorDefense);
    playerD.setMidRangeDefense(midRangeDefense);
    playerD.setPerimeterDefense(perimeterDefense);
    playerD.setHustle(hustle);
    playerD.setSpeed(speed);
    playerD.setQuickness(quickness);
    playerD.setFatigue(fatigue);
    playerD.setDurability(durability);
    playerD.setDemeanor(demeanor);
    playerD.setImprovability(improvability);
    playerD.calculateOverallRating();
    playerDataInstance.push_back(playerD);

    //gameS->setPlayerDataInstances(playerDataInstance);
    //	vector<players::playerData> playerN = playerG->getPlayer();

    return (playerD);
}

//Offense
std::vector<offensePlays> loader::loadOffensePlays()	// load offense plays from XML files
{
	std::vector<offensePlays> plays;
#if OGRE_PLATFORM == OGRE_PLATFORM_ANDROID
	string playList = "data/offense/plays/plays.xml";
#else
    string playList = findFile("offense/plays/plays.xml");
#endif
	loadOffensePlayListFile(playList);
//    std::vector<std::string> playerFiles = load->getPlayerFiles();

    std::vector<std::string>::iterator it;
    for (it = offensePlayFiles.begin(); it != offensePlayFiles.end(); ++it)
    {
		logMsg("offensePlayFile = " +*it);
#if OGRE_PLATFORM == OGRE_PLATFORM_ANDROID
		plays.push_back(loadOffensePlayFile("data/offense/plays/" + *it));
#else
        plays.push_back(loadOffensePlayFile(findFile("offense/plays/" + *it)));
#endif
    }

	return (plays);
}
bool loader::loadOffensePlayListFile(string fileName)	// loads the list of offense play files from plays.xml
{
    //conversion *convert = conversion::Instance();
    boost::shared_ptr<conversion> convert = conversion::Instance();
    boost::shared_ptr<renderEngine> render = renderEngine::Instance();

    std::vector<std::string> playFiles;


//	char *fileContents = NULL;
	std::string fileContents;
    //TiXmlDocument doc;
    tinyxml2::XMLDocument doc;
    //    Ogre::LogManager::getSingletonPtr()->logMessage("file = " +file);
//	readFile(fileName.c_str(), &fileContents);
    logMsg(fileName);
/*#if OGRE_PLATFORM == OGRE_PLATFORM_ANDROID
	Ogre::DataStreamPtr fileData = render->openAPKFile(fileName);
	fileContents = fileData->getAsString();
#else*/
    char *contents = NULL;
	readFile(fileName.c_str(), &contents);
    fileContents = convert->toString(contents);
//#endif

/*    TiXmlDocument doc(fileName.c_str());
    if (!doc.LoadFile()) return(false);
*/

    doc.Parse(contents);
    if (doc.Error())
    {
        logMsg("Unable to parse teams.xml file");
        logMsg("Error ID = " +convert->toString(doc.ErrorID()));
        logMsg(convert->toString(doc.GetErrorStr1()));
        logMsg(convert->toString(doc.GetErrorStr2()));
        exit(0);
    }

    //TiXmlHandle hDoc(&doc);
    tinyxml2::XMLHandle hDoc(&doc);

    //TiXmlElement* pElem;
    tinyxml2::XMLElement *pElem;

    //TiXmlHandle hRoot(0);
    tinyxml2::XMLHandle hRoot(0);

    //pElem=hDoc.FirstChildElement().Element();
    pElem=hDoc.FirstChildElement().ToElement();
    // should always have a valid root but handle gracefully if it does
//    if (!pElem) return(false);
    if (!pElem)
    {
        logMsg("Unable to find a valid offense play list file root!");
        exit(0);
    }
    // save this for later
//    hRoot=TiXmlHandle(pElem);
    hRoot = tinyxml2::XMLHandle(pElem);
    pElem=hRoot.FirstChildElement().ToElement();
    for( pElem; pElem; pElem=pElem->NextSiblingElement())
    {
        string pKey=pElem->Value();
//		cout << pKey << endl;
        string pText=pElem->GetText();
//		cout << pText << endl;
        playFiles.push_back(pText);

    }

/*    std::vector<std::string>::iterator it;
    for (it = playerFiles.begin(); it != playerFiles.end(); ++it)
    {
        cout << *it << endl;
    }
    */

    setOffensePlayFiles(playFiles);

	return true;
}

offensePlays loader::loadOffensePlayFile(string fileName)	// loads data from the offense play XML files
{
    //conversion *convert = conversion::Instance();
    boost::shared_ptr<conversion> convert = conversion::Instance();
    
    offensePlays play;
    std::string playName;
    int variation;
    std::string title;
    std::vector<playerDesignations> playerDesignation;
    std::vector<std::string> type;
    std::vector<float> xCoord;
    std::vector<float> yCoord;
    std::vector<float> zCoord;
    std::vector<Ogre::Vector3> startCoords;
    std::vector< std::vector<Ogre::Vector3> > executeCoords;
    std::vector<offensePlays::playerDirectives> playerDirective;

    // stores values read from XML files
    std::string pPlayName;
    int pVariation;
    std::string pTitle;
    std::string pPlayerDesignation;
    std::string pType;
    float pXCoord;
    float pYCoord;
    float pZCoord;
    Ogre::Vector3 pCoords;
    std::vector<Ogre::Vector3> pExecuteCoords;
    offensePlays::playerDirectives pPlayerDirective;
    playerDesignations pPlayerDirectiveDesignation;

//    TiXmlDocument doc(fileName.c_str());
//    if (!doc.LoadFile()) return(false);

//	char *fileContents = NULL;
    std::string fileContents;
	//TiXmlDocument doc;
    tinyxml2::XMLDocument doc;
	//    Ogre::LogManager::getSingletonPtr()->logMessage("file = " +file);
//	readFile(fileName.c_str(), &fileContents);

/*#if OGRE_PLATFORM == OGRE_PLATFORM_ANDROID
	Ogre::DataStreamPtr fileData = render->openAPKFile(fileName);
	fileContents = fileData->getAsString();
#else*/
    char *contents = NULL;
    readFile(fileName.c_str(), &contents);
    fileContents = convert->toString(contents);
//#endif

    doc.Parse(contents);
    if (doc.Error())
    {
        logMsg("Unable to parse teams.xml file");
        logMsg("Error ID = " +convert->toString(doc.ErrorID()));
        logMsg(convert->toString(doc.GetErrorStr1()));
        logMsg(convert->toString(doc.GetErrorStr2()));
        exit(0);
    }

    //TiXmlHandle hDoc(&doc);
    tinyxml2::XMLHandle hDoc(&doc);

    //TiXmlElement *rootElement;
    tinyxml2::XMLElement *rootElement;

    //TiXmlElement* pElem;
    tinyxml2::XMLElement *pElem;

    //TiXmlElement *child;
    tinyxml2::XMLElement *child;

    //TiXmlNode *rootNode;
    tinyxml2::XMLNode *rootNode;

    //TiXmlNode *childNode;
    tinyxml2::XMLNode *childNode;

    //TiXmlHandle hRoot(0);
    tinyxml2::XMLHandle hRoot(0);

//    pElem=hDoc.FirstChildElement().Element();
//    rootElement = doc.FirstChildElement("Play");
    rootElement=hDoc.FirstChildElement().ToElement();

// should always have a valid root but handle gracefully if it does
    if (!rootElement)
    {
    	logMsg("Unable to load offense play element");
    	exit(0);
    }

    //child = rootElement->FirstChild()->ToElement();
    child = rootElement->FirstChildElement()->ToElement();
    if (child)
    {
        string cKey = child->Value();
        if (cKey == "PlayName")
        {
            pPlayName = child->GetText();
            logMsg("pPlayName = " +playName);
            playName = pPlayName;
        }
    	//child = child->NextSiblingElement("Variation");
        child = child->NextSiblingElement()->ToElement();
	if (child)
        {
            pVariation = convert->toInt(child->GetText());
            logMsg("pVariation = " +convert->toString(pVariation));
            variation = pVariation;
        } 
        //child = child->NextSiblingElement("Title");
        child = child->NextSiblingElement()->ToElement(); 
	if (child)
        {
            pTitle = child->GetText();
            logMsg("pTitle = " +pTitle);
            title = pTitle;
        }
        int numPlayers = 0;
        //for (TiXmlElement *e = child->NextSiblingElement("Player"); e != NULL; e = e->NextSiblingElement() )
        for (tinyxml2::XMLElement *e = child->NextSiblingElement(); e != NULL; e = e->NextSiblingElement())
	{
            //TiXmlElement *f;
	    tinyxml2::XMLElement *f;

            logMsg ("nums = " +convert->toString(numPlayers));
            numPlayers += 1;
            //f = e->FirstChildElement("Name");
            f = e->FirstChildElement()->ToElement();
	    if (f)
            {
                pPlayerDesignation = f->GetText();
                logMsg("name = " +pPlayerDesignation);
//                playerName.push_back(pPlayerName);

                if (pPlayerDesignation == "PG")
                {
                    playerDesignation.push_back(PG);
                    pPlayerDirectiveDesignation = PG;
                }
                else if (pPlayerDesignation == "SG")
                {
                    playerDesignation.push_back(SG);
                    pPlayerDirectiveDesignation = SG;
                }
                else if (pPlayerDesignation == "SF")
                {
                    playerDesignation.push_back(SF);
                    pPlayerDirectiveDesignation = SF;
                }
                else if (pPlayerDesignation == "PF")
                {
                    playerDesignation.push_back(PF);
                    pPlayerDirectiveDesignation = PF;
                }
                else if (pPlayerDesignation == "C")
                {
                    playerDesignation.push_back(C);
                    pPlayerDirectiveDesignation = C;
                }
                else
               {

                }
            }
            //f = f->NextSiblingElement("Positions");
            f = f->NextSiblingElement()->ToElement();
	    if (f)
            {
                int numPos = 0;
                pExecuteCoords.clear(); // clears the vector for each player
                //for (TiXmlElement *g = f->FirstChildElement("Position"); g != NULL; g = g->NextSiblingElement("Position"))
		for (tinyxml2::XMLElement *g = f->FirstChildElement(); g != NULL; g = g->NextSiblingElement())

                {
                    logMsg("numPos = " +convert->toString(numPos));
                    numPos += 1;
                    //TiXmlElement *h;
		    tinyxml2::XMLElement *h;

                    //h = g->FirstChildElement("Type");
                    h = g->FirstChildElement()->ToElement();
		    if (h)
                    {
                        pType = h->GetText();
                        logMsg("pType = " +pType);
                        type.push_back(pType);
                    }
                    //h = h->NextSiblingElement("X");
                    h = h->NextSiblingElement()->ToElement();
		    if (h)
                    {
                        pXCoord = convert->toFloat(h->GetText());
                        logMsg("pXCoord = " +convert->toString(pXCoord));
                        xCoord.push_back(pXCoord);
                    }
                    //h = h->NextSiblingElement("Y");
                    h = h->NextSiblingElement()->ToElement();
		    if (h)
                    {
                        pYCoord = convert->toFloat(h->GetText());
                        logMsg("pYCoord = " +convert->toString(pYCoord));
                        yCoord.push_back(pYCoord);
                    }
                    //h = h->NextSiblingElement("Z");
                    h = h->NextSiblingElement()->ToElement();
		    if (h)
                    {
                        pZCoord = convert->toFloat(h->GetText());
                        logMsg("pZCoord = " +convert->toString(pZCoord));
                        zCoord.push_back(pZCoord);
                    }

                    pCoords.x = pXCoord;
                    pCoords.y = pYCoord;
                    pCoords.z = pZCoord;

                    if (pType == "Start")
                    {
                        startCoords.push_back(pCoords);
                    }
                    else
                    {
                        pExecuteCoords.push_back(pCoords);
                        logMsg("pExecuteCoords.size = " +convert->toString(pExecuteCoords.size()));
                    }
                }
                // checks if there are execute coords and puts them in the vector
                if (pExecuteCoords.size() > 0)
                {
                    executeCoords.push_back(pExecuteCoords);
                }
            }
            //f = f->NextSiblingElement("Directives");
            f = f->NextSiblingElement()->ToElement();
	    if (f)
            {
                int numDirectives = 0;
                //for (TiXmlElement *g = f->FirstChildElement("Directive"); g != NULL; g = g->NextSiblingElement("Directive"))
                for (tinyxml2::XMLElement *g = f->FirstChildElement(); g != NULL; g = g->NextSiblingElement())
		{
                    numDirectives += 1;
                    //TiXmlElement *h;
                    tinyxml2::XMLElement *h;
                    pPlayerDirective.setPlayerDesignation(pPlayerDirectiveDesignation);
                    //h = g->FirstChildElement("Type");
                    h = g->FirstChildElement()->ToElement();
                    if (h)
                    {
                        string hKey = h->GetText();
                        logMsg("hKey = " +hKey);
                        if (hKey == "Wait")
                        {
                            pPlayerDirective.setType(WAIT);
                            //h = h->NextSiblingElement("WaitFor");
                            h = h->NextSiblingElement()->ToElement();
			    if (h)
                            {
                                logMsg("WaitFor");
                                hKey = h->GetText();
                                if (hKey == "PlayerPositionSet")
                                {
                                    pPlayerDirective.setWaitFor(PLAYERPOSITIONSET);
                                    logMsg("PlayerPositionSet");

                                    //h = h->NextSiblingElement("PlayerSet");
                                    h = h->NextSiblingElement()->ToElement();
				    if (h)
                                    {
                                        hKey = h->GetText();
                                        logMsg("PlayerSet = " +hKey);

                                        if (hKey == "PG")
                                        {
                                            pPlayerDirective.setPlayerSet(PG);
                                        }
                                        if (hKey == "SG")
                                        {
                                            pPlayerDirective.setPlayerSet(SG);
                                        }
                                        if (hKey == "SF")
                                        {
                                            pPlayerDirective.setPlayerSet(SF);
                                        }
                                        if (hKey == "PF")
                                        {
                                            pPlayerDirective.setPlayerSet(PF);
                                        }
                                        if (hKey == "C")
                                        {
                                            pPlayerDirective.setPlayerSet(C);
                                        }
                                    }
                                    //h = h->NextSiblingElement("PositionType");
                                    h = h->NextSiblingElement()->ToElement();
				    if (h)
                                    {
                                        logMsg("PositionType");
                                        hKey = h->GetText();
                                        if (hKey == "Start")
                                        {
                                            logMsg("Start");
                                            pPlayerDirective.setPositionType(START);
                                        }
                                        else if (hKey == "Execute")
                                        {
                                            logMsg("Execute");
                                            pPlayerDirective.setPositionType(EXECUTE);

                                            h = h->NextSiblingElement("Position");
                                            if (h)
                                            {
                                                logMsg("Position");
                                                hKey = h->GetText();
                                                pPlayerDirective.setPosition(convert->toInt(hKey.c_str()));
                                            }
                                        }
                                    }
                                }
                            }
                        }
                    }
                }
                playerDirective.push_back(pPlayerDirective);
                logMsg("numDirectives = " +convert->toString(numDirectives));
            }
        }
    }


    play.setPlayName(playName);
    play.setVariation(variation);
    play.setTitle(title);
    play.setPlayerDesignation(playerDesignation);
    play.setStartPositions(startCoords);
    play.setExecutePositions(executeCoords);
    play.setPlayerDirective(playerDirective);

	return (play);
}

// Courts
std::vector<courtData> loader::loadCourts()	// load court settings from XML files
{
	std::vector<courtData> courts;
#if OGRE_PLATFORM == OGRE_PLATFORM_ANDROID
	string courtList = "data/courts/courts.xml";
#else
    string courtList = findFile("courts/courts.xml");
#endif
	loadCourtListFile(courtList);
//    std::vector<std::string> playerFiles = load->getPlayerFiles();

    std::vector<std::string>::iterator it;
    for (it = courtFiles.begin(); it != courtFiles.end(); ++it)
    {
		logMsg("courtFile = " +*it);
#if OGRE_PLATFORM == OGRE_PLATFORM_ANDROID
		courts.push_back(loadCourtFile("data/courts/" + *it));
#else
        courts.push_back(loadCourtFile(findFile("courts/" + *it)));
#endif
    }

	return (courts);
}

bool loader::loadCourtListFile(string fileName)	// loads the list of court files from courts.xml
{
    //conversion *convert = conversion::Instance();
    boost::shared_ptr<conversion> convert = conversion::Instance();
    
    boost::shared_ptr<renderEngine> render = renderEngine::Instance();
    std::vector<std::string> courtFile;


//	char *fileContents = NULL;
	std::string fileContents;
	TiXmlDocument doc;
	//    Ogre::LogManager::getSingletonPtr()->logMessage("file = " +file);
//	readFile(fileName.c_str(), &fileContents);
    logMsg(fileName);
/*#if OGRE_PLATFORM == OGRE_PLATFORM_ANDROID
	Ogre::DataStreamPtr fileData = render->openAPKFile(fileName);
	fileContents = fileData->getAsString();
#else*/
    char *contents = NULL;
    readFile(fileName.c_str(), &contents);
    fileContents = convert->toString(contents);
    logMsg("fileContents = " +fileContents);
    //exit(0);
//#endif

/*    TiXmlDocument doc(fileName.c_str());
    if (!doc.LoadFile()) return(false);
*/

	if (!doc.Parse(contents))
	{
		logMsg("Unable to parse courts.xml file");
		//exit(0);
	}

    TiXmlHandle hDoc(&doc);
    TiXmlElement* pElem;
    TiXmlHandle hRoot(0);

    pElem=hDoc.FirstChildElement().Element();
    // should always have a valid root but handle gracefully if it does
    if (!pElem) return(false);

    // save this for later
    hRoot=TiXmlHandle(pElem);

    pElem=hRoot.FirstChild("CourtFile").Element();
    for( pElem; pElem; pElem=pElem->NextSiblingElement())
    {
        string pKey=pElem->Value();
//		cout << pKey << endl;
        string pText=pElem->GetText();
//		cout << pText << endl;
        courtFile.push_back(pText);

    }

/*    std::vector<std::string>::iterator it;
    for (it = playerFiles.begin(); it != playerFiles.end(); ++it)
    {
        cout << *it << endl;
    }
    */

    setCourtFiles(courtFile);

	return true;
}

courtData loader::loadCourtFile(string fileName)	// loads data from the offense play XML files
{
    //conversion *convert = conversion::Instance();
    boost::shared_ptr<conversion> convert = conversion::Instance();
    
	courtData court;
	std::string name;
	std::string modelName;
    float length = 0;
    float width = 0;
    float boundaryLength = 0;
    float boundaryWidth = 0;
    float boundaryXPos = 0;
    float boundaryZPos = 0;
    float centerCourt = 0;
    float centerJumpRadius = 0;
    float keyLength = 0;
    float keyWidth = 0;
    float keyJumpRadius = 0;
    float threePointSideLength = 0;
    float threePointSideZPos = 0;
    float threePointArcRadius = 0;
    float baselineInboundXPos = 0;
    float baselineInboundZPos = 0;
    float sidelineInboundXPos = 0;
    float sidelineInboundZPos = 0;
/*
	// stores values read from XML files
	std::string pPlayName;
    int pVariation;
    std::string pTitle;
    std::string pPlayerDesignation;
    std::string pType;
    //float pXCoord;
    float pYCoord;
    float pZCoord;
    Ogre::Vector3 pCoords;
	std::vector<Ogre::Vector3> pExecuteCoords;
    offensePlays::playerDirectives pPlayerDirective;
    playerDesignations pPlayerDirectiveDesignation;
*/
//    TiXmlDocument doc(fileName.c_str());
//    if (!doc.LoadFile()) return(false);

//	char *fileContents = NULL;
	std::string fileContents;
	TiXmlDocument doc;
	//    Ogre::LogManager::getSingletonPtr()->logMessage("file = " +file);
//	readFile(fileName.c_str(), &fileContents);

/*#if OGRE_PLATFORM == OGRE_PLATFORM_ANDROID
	Ogre::DataStreamPtr fileData = render->openAPKFile(fileName);
	fileContents = fileData->getAsString();
#else*/
    char *contents = NULL;
	readFile(fileName.c_str(), &contents);
    fileContents = convert->toString(contents);
//#endif
	if (!doc.Parse(contents))
	{
		logMsg("Unable to parse court file");
		//exit(0);
	}

    TiXmlHandle hDoc(&doc);
    TiXmlElement *rootElement;
//    TiXmlElement* pElem;
    TiXmlElement *child;
//    TiXmlNode *rootNode;
//    TiXmlNode *childNode;
    TiXmlHandle hRoot(0);

//    pElem=hDoc.FirstChildElement().Element();
    rootElement = doc.FirstChildElement("Court");
    // should always have a valid root but handle gracefully if it does
    if (!rootElement)
    {
    	logMsg("Unable to load court element");
    	//exit(0);
    }

    child = rootElement->FirstChild()->ToElement();
    if (child)
    {
    	string cKey = child->Value();
    	if (cKey == "Name")
    	{
    		name = child->GetText();
    		logMsg("name = " +name);
    	}
    	child = child->NextSiblingElement("Model");
  		if (child)
    	{
  			modelName = child->GetText();
    		logMsg("modelName = " +modelName);
    	}
  		child = child->NextSiblingElement("Length");
		if (child)
		{
            length = convert->toFloat(child->GetText());
            logMsg("Length = " +convert->toString(length));
		} //      exit(0);
  		child = child->NextSiblingElement("Width");
		if (child)
		{
            length = convert->toFloat(child->GetText());
            logMsg("Width = " +convert->toString(width));
		} //      exit(0);
  		child = child->NextSiblingElement("BoundaryLength");
		if (child)
		{
            boundaryLength = convert->toFloat(child->GetText());
            logMsg("Boundary Length = " +convert->toString(boundaryLength));
		} //      exit(0);
  		child = child->NextSiblingElement("BoundaryWidth");
		if (child)
		{
            boundaryWidth = convert->toFloat(child->GetText());
            logMsg("Boundary Width = " +convert->toString(boundaryWidth));
		} //      exit(0);
  		child = child->NextSiblingElement("BoundaryXPos");
		if (child)
		{
            boundaryXPos = convert->toFloat(child->GetText());
            logMsg("Boundary X Pos = " +convert->toString(boundaryXPos));
		} //      exit(0);
  		child = child->NextSiblingElement("BoundaryZPos");
		if (child)
		{
            boundaryZPos = convert->toFloat(child->GetText());
            logMsg("Boundary Z Pos = " +convert->toString(boundaryZPos));
		} //      exit(0);
  		child = child->NextSiblingElement("CenterCourt");
		if (child)
		{
            centerCourt = convert->toFloat(child->GetText());
            logMsg("Center Court = " +convert->toString(centerCourt));
		} //      exit(0);
  		child = child->NextSiblingElement("CenterJumpRadius");
		if (child)
		{
            centerJumpRadius = convert->toFloat(child->GetText());
            logMsg("Center Jump Radius = " +convert->toString(centerJumpRadius));
		} //      exit(0);
  		child = child->NextSiblingElement("KeyLength");
		if (child)
		{
            keyLength = convert->toFloat(child->GetText());
            logMsg("Key Length = " +convert->toString(keyLength));
		} //      exit(0);
  		child = child->NextSiblingElement("KeyWidth");
		if (child)
		{
            keyWidth = convert->toFloat(child->GetText());
            logMsg("Key Width = " +convert->toString(keyWidth));
		} //      exit(0);
  		child = child->NextSiblingElement("KeyJumpRadius");
		if (child)
		{
            keyJumpRadius = convert->toFloat(child->GetText());
            logMsg("Key Jump RAdius = " +convert->toString(keyJumpRadius));
		} //      exit(0);
  		child = child->NextSiblingElement("ThreePointSideLength");
		if (child)
		{
            threePointSideLength = convert->toFloat(child->GetText());
            logMsg("Three Point Side Length = " +convert->toString(threePointSideLength));
		} //      exit(0);
  		child = child->NextSiblingElement("ThreePointSideZPos");
		if (child)
		{
            threePointSideZPos = convert->toFloat(child->GetText());
            logMsg("Three Point Side Z Pos = " +convert->toString(threePointSideZPos));
		} //      exit(0);
  		child = child->NextSiblingElement("ThreePointArcRadius");
		if (child)
		{
            threePointArcRadius = convert->toFloat(child->GetText());
            logMsg("Three Point Arc Radius = " +convert->toString(threePointArcRadius));
		} //      exit(0);
  		child = child->NextSiblingElement("BaselineInboundXPos");
		if (child)
		{
            baselineInboundXPos = convert->toFloat(child->GetText());
            logMsg("Baseline Inbound X Pos = " +convert->toString(baselineInboundXPos));
		} //      exit(0);
  		child = child->NextSiblingElement("BaselineInboundZPos");
		if (child)
		{
            baselineInboundZPos = convert->toFloat(child->GetText());
            logMsg("Baseline Inbound Z Pos = " +convert->toString(baselineInboundZPos));
		} //      exit(0);
  		child = child->NextSiblingElement("SidelineInboundXPos");
		if (child)
		{
            sidelineInboundXPos = convert->toFloat(child->GetText());
            logMsg("Sideline Inbound X Pos = " +convert->toString(sidelineInboundXPos));
		} //      exit(0);
  		child = child->NextSiblingElement("SidelineInboundZPos");
		if (child)
		{
            sidelineInboundZPos = convert->toFloat(child->GetText());
            logMsg("Sideline Inbound Z Pos = " +convert->toString(sidelineInboundZPos));
		} //      exit(0);

    }

    Ogre::Vector2 boundary = Ogre::Vector2(length,width);
    Ogre::Vector2 boundaryPos = Ogre::Vector2(boundaryXPos,boundaryZPos);
    Ogre::Vector2 keyDimensions = Ogre::Vector2(keyLength,keyWidth);
    Ogre::Vector2 baselineInboundPos = Ogre::Vector2(baselineInboundXPos,baselineInboundZPos);
    Ogre::Vector2 sidelineInboundPos = Ogre::Vector2(sidelineInboundXPos,sidelineInboundZPos);

    court.setName(name);
    court.setModelName(modelName);
    court.setBoundary(boundary);
    court.setBoundaryPos(boundaryPos);
    court.setCenterCourt(centerCourt);
    court.setCenterJumpRadius(centerJumpRadius);
    court.setKeyDimensions(keyDimensions);
    court.setKeyJumpRadius(keyJumpRadius);
    court.setThreePointSideLength(threePointSideLength);
    court.setThreePointZPos(threePointSideZPos);
    court.setThreePointArcRadius(threePointArcRadius);
    court.setBaselineInboundPos(baselineInboundPos);
    court.setSidelineInboundPos(sidelineInboundPos);

	return (court);
}


// User input
std::vector<userInput> loader::loadUserInputs() // load user input settings from XML files
{
    std::vector<userInput> userInputs;
#if OGRE_PLATFORM == OGRE_PLATFORM_ANDROID
    string userInputList = "data/users/inputlist.xml";
#else
    string userInputList = findFile("users/inputlist.xml");
#endif
    loadUserInputListFile(userInputList);
//    std::vector<std::string> playerFiles = load->getPlayerFiles();

    std::vector<std::string>::iterator it;
    for (it = userInputFiles.begin(); it != userInputFiles.end(); ++it)
    {
        logMsg("userInputFile = " +*it);
#if OGRE_PLATFORM == OGRE_PLATFORM_ANDROID
        userInputs.push_back(loadUserInputFile("data/users/" + *it));
#else
        userInputs.push_back(loadUserInputFile(findFile("users/" + *it)));
#endif
    }

    return (userInputs);
}

bool loader::loadUserInputListFile(string fileName) // loads the list of offense play files from plays.xml
{
    //conversion *convert = conversion::Instance();
    boost::shared_ptr<conversion> convert = conversion::Instance();
    
    boost::shared_ptr<renderEngine> render = renderEngine::Instance();
    std::vector<std::string> userInputFile;


//  char *fileContents = NULL;
    std::string fileContents;
    TiXmlDocument doc;
    //    Ogre::LogManager::getSingletonPtr()->logMessage("file = " +file);
//  readFile(fileName.c_str(), &fileContents);
    logMsg(fileName);
/*#if OGRE_PLATFORM == OGRE_PLATFORM_ANDROID
    Ogre::DataStreamPtr fileData = render->openAPKFile(fileName);
    fileContents = fileData->getAsString();
#else*/
    char *contents = NULL;
    readFile(fileName.c_str(), &contents);
    fileContents = convert->toString(contents);
//#endif

/*    TiXmlDocument doc(fileName.c_str());
    if (!doc.LoadFile()) return(false);
*/

    if (!doc.Parse(contents))
    {
        logMsg("Unable to parse inputlist.xml file");
//        exit(0);
    }

    TiXmlHandle hDoc(&doc);
    TiXmlElement* pElem;
    TiXmlHandle hRoot(0);

    pElem=hDoc.FirstChildElement().Element();
    // should always have a valid root but handle gracefully if it does
    if (!pElem) return(false);

    // save this for later
    hRoot=TiXmlHandle(pElem);

    pElem=hRoot.FirstChild("UserInputFile").Element();
    for( pElem; pElem; pElem=pElem->NextSiblingElement())
    {
        string pKey=pElem->Value();
//      cout << pKey << endl;
        string pText=pElem->GetText();
//      cout << pText << endl;
        userInputFile.push_back(pText);

    }

/*    std::vector<std::string>::iterator it;
    for (it = playerFiles.begin(); it != playerFiles.end(); ++it)
    {
        cout << *it << endl;
    }
    */

    setUserInputFiles(userInputFile);

    return true;
}

userInput loader::loadUserInputFile(string fileName)    // loads data from the user input XML files
{
    //conversion *convert = conversion::Instance();
    boost::shared_ptr<conversion> convert = conversion::Instance();
    
    logMsg("Load UserInput File");
    userInput uInput;
    std::string inputName;
    std::string type;
    std::string up;
    std::string down;
    std::string left;
    std::string right;
    std::string upLeft;
    std::string upRight;
    std::string downLeft;
    std::string downRight;
    std::string shootBlock;
    std::string passSteal;
    std::string pause;
    std::string startSelect;
    std::string quit;
    
//  char *fileContents = NULL;
    std::string fileContents;
    TiXmlDocument doc;

    char *contents = NULL;
   
    readFile(fileName.c_str(), &contents);
    fileContents = convert->toString(contents);
   
    if (!doc.Parse(contents))
    {
        logMsg("Unable to parse user input file");
        exit(0);
    }
//    exit(0);
    TiXmlHandle hDoc(&doc);
    TiXmlElement *rootElement;
//    TiXmlElement* pElem;
    TiXmlElement *child;
    TiXmlElement *nextChild;
//    TiXmlNode *rootNode;
//    TiXmlNode *childNode;
    TiXmlHandle hRoot(0);

    rootElement = doc.FirstChildElement("UserInput");
    // should always have a valid root but handle gracefully if it does
    if (!rootElement)
    {
        logMsg("Unable to load user input element");
        exit(0);
    }
    
    child = rootElement->FirstChild()->ToElement();
    if (child)
    {
        string cKey = child->Value();
        if (cKey == "Name")
        {
            inputName = child->GetText();
            logMsg("name = " +inputName);
        }
        
        bool inputTag = false;
        while (!inputTag)
        {
            child = child->NextSiblingElement("Input");
            if (child)
            {
                nextChild = child->FirstChildElement("Type");

                inputTag = true;
                for( nextChild; nextChild; nextChild=nextChild->NextSiblingElement())
                {
                    
                    string pKey=nextChild->Value();
                    logMsg("pKey = " +pKey);
//                    exit(0);
                    if (pKey == "Type")
                    {
                        type = nextChild->GetText();
                        logMsg("type = " +type);
//                        exit(0);
                    }
                    if (pKey == "Up")
                    {
                        up = nextChild->GetText();
                        logMsg("up = " +up);

                    }
                    if (pKey == "Down")
                    {
                        down = nextChild->GetText();
                    }
                    if (pKey == "Left")
                    {
                        left = nextChild->GetText();
                    }
                    if (pKey == "Right")
                    {
                        right = nextChild->GetText();
                    }
                    if (pKey == "UpLeft")
                    {
                        upLeft = nextChild->GetText();
                    }
                    if (pKey == "UpRight")
                    {
                        upRight = nextChild->GetText();
                    }
                    if (pKey == "DownLeft")
                    {
                        downLeft = nextChild->GetText();
                    }
                    if (pKey == "DownRight")
                    {
                        downRight = nextChild->GetText();
                    }
                    if (pKey == "ShootBlock")
                    {
                        shootBlock = nextChild->GetText();
                    }
                    if (pKey == "PassSteal")
                    {
                        passSteal = nextChild->GetText();
                    }
                    if (pKey == "Pause")
                    {
                        pause = nextChild->GetText();
                    }
                    if (pKey == "StartSelect")
                    {
                        startSelect = nextChild->GetText();
//                        exit(0);
                    }
                    if (pKey == "Quit")
                    {
                        quit = nextChild->GetText();
//                        exit(0);
                    }
                }
                
            }
            else
            {
                inputTag = false;
            }
//            modelName = child->GetText();
//            logMsg("modelName = " +modelName);
            if (type == "Keyboard")
            {
                uInput.setKeyUp(up);
                uInput.setKeyDown(down);
                uInput.setKeyLeft(left);
                uInput.setKeyRight(right);
                uInput.setKeyUpLeft(upLeft);
                uInput.setKeyUpRight(upRight);
                uInput.setKeyDownLeft(downLeft);
                uInput.setKeyDownRight(downRight);
                uInput.setKeyShootBlock(shootBlock);
                uInput.setKeyPassSteal(passSteal);
                uInput.setKeyPause(pause);
                uInput.setKeyStartSelect(startSelect);
                uInput.setKeyQuit(quit);
            }
            else if (type == "Joystick")
            {
                uInput.setJoyUp(up);
                uInput.setJoyDown(down);
                uInput.setJoyLeft(left);
                uInput.setJoyRight(right);
                uInput.setJoyUpLeft(upLeft);
                uInput.setJoyUpRight(upRight);
                uInput.setJoyDownLeft(downLeft);
                uInput.setJoyDownRight(downRight);
                uInput.setJoyShootBlock(shootBlock);
                uInput.setJoyPassSteal(passSteal);
                uInput.setJoyPause(pause);
                uInput.setJoyStartSelect(startSelect);

            }
            else
            {

            }

        }
    }

    return (uInput);
}

