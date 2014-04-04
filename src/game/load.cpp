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
#include "renderengine.h"
#include "teams.h"

#if OGRE_PLATFORM == OGRE_PLATFORM_ANDROID
#include "android.h"
#endif

//#include "ubcapp.h"

//#include "boost/shared_ptr.hpp"

#include "SDL.h"

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

// loads an xml file using SDL so that it can
// be passed to TinyXML
int loader::readFile(const char *sourceFile, char **destination)
//int loader::readFile(const char *sourceFile, Ogre::String *destination)
{
	renderEngine *renderE = renderEngine::Instance();
	int BLOCK_SIZE = 8;
	int MAX_BLOCKS = 1024;

#if OGRE_PLATFORM == OGRE_PLATFORM_ANDROID
	Ogre::DataStreamPtr fileData = renderE->openAPKFile("teamd.xml");
//	destination = new Ogre::String;
	(*destination) = (char**)fileData->getAsString().c_str();
#else
//    char *contents = NULL;
//	readFile(fileName.c_str(), &contents);
//	fileContents = Ogre::StringConverter::toString(contents);
//#endif
    // Open the file
//    SDL_RWops *file;
	Ogre::LogManager::getSingletonPtr()->logMessage("sourceFile = ");
    Ogre::LogManager::getSingletonPtr()->logMessage(sourceFile);
//	Ogre::LogManager::getSingletonPtr()->logMessage(SDL_AndroidGetInternalStoragePath());
//    file = SDL_RWFromFile("teamd.xml", "rb");
	string filename = "/teamd.xml";
    SDL_RWops *file;
//	file = SDL_RWFromFile(filename.c_str(), "r");
	file = SDL_RWFromFile(sourceFile, "r");

//	SDL_RWops *file = openAPKFile(filename);
/*	if (file = SDL_RWFromFile(name.c_str(), "r") != 0)
	{
		fprintf(stderr,
                "\nUnable to load file:  %s\n",
                SDL_GetError()
               );
	}*/
	Ogre::LogManager::getSingletonPtr()->logMessage("Seek to beginning of file");
	size_t fileLength = SDL_RWseek(file, 0, SEEK_END);
	std::cout << "fileLength = " << fileLength << endl;
	(*destination) = new char[fileLength + 1]; // allow an extra characterfor '\0'

//    ASSERT(file, "Opening file using SDL_RWops");
	// resets the file to beginnin
	SDL_RWseek(file, 0, SEEK_SET);
    // Read text from file
    int n_blocks = SDL_RWread(file, (*destination), 1, fileLength);
    // BLOCK_SIZE = 8, MAX_BLOCKS = 1024
    SDL_RWclose(file);
    (*destination)[fileLength] = '\0';
	Ogre::LogManager::getSingletonPtr()->logMessage("File Contents = " +Ogre::StringConverter::toString(destination));

    // Make sure the operation was successful
 //   ASSERT(n_blocks >= 0, "Reading blocks of data from SDL_RWops");
//    WARN_IF(n_blocks == MAX_BLOCKS, "Reading data from SDL_RWops","Buffer full so may be too small for data");
#endif
    // Success!
    return EXIT_SUCCESS;
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

    Ogre::LogManager::getSingletonPtr()->logMessage("dataPath = " +dataPath);
#if OGRE_PLATFORM == OGRE_PLATFORM_ANDROID
    filePath = fileName;
#else
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
//            if (x == 1)
//            {
//               filePath.append(":");
//            }

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
//	exit(0);
#if OGRE_PLATFORM == OGRE_PLATFORM_ANDROID
//    string teamList = findFile("teams.xml");
    string teamList = "data/teams/teams.xml";
#else
    string teamList = findFile("teams/teams.xml");
#endif
    Ogre::LogManager::getSingletonPtr()->logMessage("teamList = " +teamList);
//#if OGRE_PLATFORM == OGRE_PLATFORM_ANDROID
//  cout << "teamList = " << teamList << endl;
// Ogre::LogManager::getSingletonPtr()->logMessage("dah");
    loadTeamListFile(teamList);
//    Ogre::LogManager::getSingletonPtr()->logMessage("tem = " +teamFiles[0]);
//    std::vector<std::string> teamFiles = load->getTeamFiles();
    std::vector<std::string>::iterator it;
    for (it = teamFiles.begin(); it != teamFiles.end(); ++it)
    {
#if OGRE_PLATFORM == OGRE_PLATFORM_ANDROID
		loadTeamFile("data/teams/" + *it);
#else
        loadTeamFile(findFile("teams/" + *it));
#endif
		Ogre::LogManager::getSingletonPtr()->logMessage("team = " +*it);

    }
//#endif
    return true;
}

bool loader::loadTeamListFile(string fileName)
{
	renderEngine *renderE = renderEngine::Instance();
    teams *team = teams::Instance();

    std::vector<std::string> teamName;
    std::vector<std::string> files;

//	players::playerData player;
/*#if OGRE_PLATFORM == OGRE_PLATFORM_ANDROID
    const char *file = "teams.xml";
#else
	const char *file = fileName.c_str();
#endif */

//	char *fileContents = NULL;
    Ogre::String fileContents;
    TiXmlDocument doc;
    Ogre::LogManager::getSingletonPtr()->logMessage(fileName);
	Ogre::LogManager::getSingletonPtr()->logMessage("bate");
#if OGRE_PLATFORM == OGRE_PLATFORM_ANDROID
	Ogre::DataStreamPtr fileData = renderE->openAPKFile(fileName);
	fileContents = fileData->getAsString();
#else
    char *contents = NULL;
	readFile(fileName.c_str(), &contents);
	fileContents = Ogre::StringConverter::toString(contents);
#endif
//    readFile(fileName.c_str(), &fileContents);
	Ogre::LogManager::getSingletonPtr()->logMessage("barf");
	Ogre::LogManager::getSingletonPtr()->logMessage(fileContents);
//	exit(0);
/*
	Ogre::LogManager::getSingletonPtr()->logMessage("fileName = " +fileName);
//    TiXmlDocument doc(fileName.c_str());
    TiXmlDocument doc("/data/teams/teams.xml");
    if (!doc.LoadFile())
	{
		Ogre::LogManager::getSingletonPtr()->logMessage("Unable to load " +fileName);
		return(false);
    }
*/
//	if (!doc.Parse(fileData->getAsString().c_str()))
    if (!doc.Parse(fileContents.c_str()))
    {
		Ogre::LogManager::getSingletonPtr()->logMessage("Unable to parse fart file");
//		exit(0);
	}

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
        Ogre::LogManager::getSingletonPtr()->logMessage(pElem->GetText());
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
    renderEngine *renderE = renderEngine::Instance();
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
	Ogre::String fileContents;
	TiXmlDocument doc;
	//    Ogre::LogManager::getSingletonPtr()->logMessage("file = " +file);
//	readFile(fileName.c_str(), &fileContents);
#if OGRE_PLATFORM == OGRE_PLATFORM_ANDROID
	Ogre::DataStreamPtr fileData = renderE->openAPKFile(fileName);
	fileContents = fileData->getAsString();
#else
    char *contents = NULL;
	readFile(fileName.c_str(), &contents);
	fileContents = Ogre::StringConverter::toString(contents);
	std::cout << "file contents = " << fileContents << endl;
#endif
	if (!doc.Parse(fileContents.c_str()))
	{
		Ogre::LogManager::getSingletonPtr()->logMessage("Unable to parse team file");
		exit(0);
	}

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
		Ogre::LogManager::getSingletonPtr()->logMessage("playerFile = " +*it);
#if OGRE_PLATFORM == OGRE_PLATFORM_ANDROID
		loadPlayerFile("data/players/" + *it);
#else
        loadPlayerFile(findFile("players/" + *it));
#endif
    }
    return true;
}

// loads XML file containing list of players and the files representing them
bool loader::loadPlayerListFile( string fileName)
{
	renderEngine *renderE = renderEngine::Instance();
    std::vector<std::string> playerFiles;
    players *player = players::Instance();

//	char *fileContents = NULL;
	Ogre::String fileContents;
	TiXmlDocument doc;
	//    Ogre::LogManager::getSingletonPtr()->logMessage("file = " +file);
//	readFile(fileName.c_str(), &fileContents);
    Ogre::LogManager::getSingletonPtr()->logMessage(fileName);
#if OGRE_PLATFORM == OGRE_PLATFORM_ANDROID
	Ogre::DataStreamPtr fileData = renderE->openAPKFile(fileName);
	fileContents = fileData->getAsString();
#else
    char *contents = NULL;
	readFile(fileName.c_str(), &contents);
	fileContents = Ogre::StringConverter::toString(contents);
#endif

/*    TiXmlDocument doc(fileName.c_str());
    if (!doc.LoadFile()) return(false);
*/

	if (!doc.Parse(fileContents.c_str()))
	{
		Ogre::LogManager::getSingletonPtr()->logMessage("Unable to parse players.xml file");
		exit(0);
	}

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
	renderEngine *renderE = renderEngine::Instance();
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

//    TiXmlDocument doc(fileName.c_str());
//    if (!doc.LoadFile()) return(false);

//	char *fileContents = NULL;
	Ogre::String fileContents;
	TiXmlDocument doc;
	//    Ogre::LogManager::getSingletonPtr()->logMessage("file = " +file);
//	readFile(fileName.c_str(), &fileContents);

#if OGRE_PLATFORM == OGRE_PLATFORM_ANDROID
	Ogre::DataStreamPtr fileData = renderE->openAPKFile(fileName);
	fileContents = fileData->getAsString();
#else
    char *contents = NULL;
	readFile(fileName.c_str(), &contents);
	fileContents = Ogre::StringConverter::toString(contents);
#endif
	if (!doc.Parse(fileContents.c_str()))
	{
		Ogre::LogManager::getSingletonPtr()->logMessage("Unable to parse file");
		exit(0);
	}

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

