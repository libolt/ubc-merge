/***************************************************************************
 *   Copyright (C) 2006 by Mike McLean   *
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

#include "OgrePrerequisites.h"
#include "games.h"
#include "gamestate.h"
#include "ubcapp.h"



gameObjects::gameObjects()
{
}

gameObjects::~ gameObjects()
{
}


UBC* UBC::pInstance = 0;
UBC* UBC::Instance()
{
    if (pInstance == 0)  // is it the first call?
    {
        pInstance = new UBC; // create sole instance
    }
    return pInstance; // address of sole instance
}


//-------------------------------------------------------------------------------------
UBC::UBC()
//    : player[0](0),
 // playerNode[0](0)
{
    for (int it = 0; it < 10; it++)
    {
        playerDirection[it] = 0;
        oldPlayerDirection[it] = 0;
    }

    x = 0;
    y = 0;
    i = 0;
    j = 0;
    loopTime.reset();
    oldTime = 0;

    menuActive = false;
    quitGame = false;
}
//-------------------------------------------------------------------------------------
UBC::~UBC()
{
}

// gets and sets menuActive
bool UBC::getMenuActive()
{
    return(menuActive);
}
void UBC::setMenuActive(bool active)
{
    menuActive = active;
}


/*void UBC::loads(string pFilename)
{
    TiXmlDocument doc(pFilename);
    if (!doc.LoadFile()) return;

    TiXmlHandle hDoc(&doc);
    TiXmlElement* pElem;
    TiXmlHandle hRoot(0);
    cout << "dee" << endl;
    string m_name, m_messages, WindowSettings;
    // block: name
    {
        pElem=hDoc.FirstChildElement().Element();
        // should always have a valid root but handle gracefully if it does
        if (!pElem) return;
        m_name=pElem->Value();
        cout << m_name << endl;
        //		exit(0);
        // save this for later
        hRoot=TiXmlHandle(pElem);
    }

    pElem=hRoot.FirstChild("PlayerFile").Element();
    {
        string pKey=pElem->Value();
        cout << pKey << endl;
        string pText=pElem->GetText();
        cout << pText << endl;
//        exit(0);
//        m_connection.ip=pElem->Attribute("ip");
//        pElem->QueryDoubleAttribute("timeout",&m_connection.timeout);
	}

//      TiXmlElement* child2;
//      child2 =pElem->NextSiblingElement( "PlayerFile" );
//      do
//      {
//              pElem=hRoot.FirstChild("PlayerFile").Element();
//              child2->ToElement();        basketballs *basketball = basketballs::Instance();

    for( pElem; pElem; pElem=pElem->NextSiblingElement())
    {
        string pKey=pElem->Value();
        cout << pKey << endl;
        string pText=pElem->GetText();
        cout << pText << endl;
//        exit(0);
//        m_connection.ip=pElem->Attribute("ip");
//        pElem->QueryDoubleAttribute("timeout",&m_connection.timeout);
    }

//      } while (1);

}
*/
//-------------------------------------------------------------------------------------
bool UBC::frameStarted()
{

    GUISystem *gui = GUISystem::Instance();
    games *game = games::Instance();
    inputSystem *input = inputSystem::Instance();
    players *player = players::Instance();
    renderSystems * render = renderSystems::Instance();

    float lastFPS = render->getMWindow()->getLastFPS();
    String currFPS = StringConverter::toString(lastFPS);
//    cout << "FPS = " << currFPS << endl;

    int newTime = loopTime.getMilliseconds();   // gets the elapsed time since the last reset of the timer
    float changeInTime = newTime - oldTime;

    LogManager::getSingletonPtr()->logMessage("FPS = " +currFPS);

//    std::cout << "oldTime = " << oldTime << std::endl;
//    std::cout << "newTime = " << newTime << std::endl;
//    std::cout << "change in time = " << (newTime - oldTime) << std::endl;


//    event = new OIS::MouseEvent[1];
//    gui->mouseMoved(*event);
//    const OIS::MouseState &ms = input->getMMouse()->getMouseState();
//    mGUIManager->injectMouseMove( ms.X.rel, ms.Y.rel );
    gui->updateTime(changeInTime);
//    exit(0);
    gui->update();
    Ogre::Real times;
    Ogre::FrameEvent evt;
    times = 0.01f;
//    cout << "time since last frame = " << times << endl;

    if ((newTime - oldTime) >= 70)
    {

        game->setTipOffComplete(true);
        game->setGameStarted(true);
        // checks to see if a game has been started
        if (game->getGameStarted() && game->getTipOffComplete())
        {
            game->logic();    // executes the game logic
        //    player->mAnimationState2->addTime(changeInTime);
        }
        else
        {
            game->executeTipOff();	// executes the game Tip Off
        }


        oldTime = newTime;

    }

        if (input->processInput() == false)
        {
            quitGame = true;
        }

//	std::cout << "Loop Time = " << loopTime.getMilliseconds() << std::endl;

//    return OgreApplication::frameStarted(evt);
    return true;
}

bool UBC::frameEnded()
{
//	mWindow->update();
//	mRoot->renderOneFrame();

    return true;
}

void UBC::createSceneManager()
{
    renderSystems *render = renderSystems::Instance();

    // Create the SceneManager, in this case a generic one
    render->setMSceneMgr(render->getMRoot()->createSceneManager(ST_EXTERIOR_CLOSE));

}

void UBC::createScene()
{
    GUISystem *gui = GUISystem::Instance();
    teams *team = teams::Instance();
    players *player = players::Instance();
//    basketballs *basketball = basketballs::Instance();
    renderSystems *render = renderSystems::Instance();


    // basketball
//    bballInstance[0].setNode(render->getMSceneMgr()->getRootSceneNode()->createChildSceneNode("bball"));

    // Player
//    for (int x = 0; x < 10; ++x)
//    {
//        SceneNode *playerNode = player->getNode(x);
//        playerNode = render->getMSceneMgr()->getRootSceneNode()->createChildSceneNode();
//        player->setNode(x, playerNode);
    //		playerNode[x]->pitch ( Degree (-90));
//    }
//	mSceneMgr->setWorldGeometry( "terrain.cfg" );

    // Set up GUI system
//    gui->setupGUI();

    // loads the Main Menu GUI
//    gui->loadMainMenu();

    // sets up the event handlers for main menu buttons
//    gui->setupMainMenuEventHandlers();

//    setMenuActive(true);

//    startGame();
//	setGameStarted(true);
//	bballInstance[0].setDribbling(true);

/*	vector<players::playerData> playerN = player->getPlayer();
//		exit(0);

	cout << "size = " << playerN.size() << endl;
	for (int i = 0; i < playerN.size(); i++)
	{
		cout << "FIRST name = " << playerN[i].getPlayerFirstName() << endl;
	}
*/
//	load->loadPlayerFile(
//	exit(0);
    startGame();

}

bool UBC::startGame()
{
    games *game = games::Instance();

    game->setupState();

    return true;
}


void UBC::quit()
{
    using namespace OIS;
    inputSystem *input = inputSystem::Instance();
    input->destroy();

}

//-------------------------------------------------------------------------------------

#if OGRE_PLATFORM == OGRE_PLATFORM_WIN32
#define WIN32_LEAN_AND_MEAN
#define NOMINMAX
#include "windows.h"
#endif

#ifdef __cplusplus
extern "C" {
#endif

#if OGRE_PLATFORM == OGRE_PLATFORM_WIN32
INT WINAPI WinMain( HINSTANCE hInst, HINSTANCE, LPSTR strCmdLine, INT )
#else
int main(int argc, char *argv[])
#endif
{
   // Create application object
    UBC *ubc = UBC::Instance();

    inputSystem *input = inputSystem::Instance();
    renderSystems *render = renderSystems::Instance();
    GUISystem *gui = GUISystem::Instance();
//    SoundSystem *sound = SoundSystem::Instance();
//    gui->setupGUI();

    ubc->createScene();
//    ubc->startGame();

    while (!ubc->quitGame)
    {
//        ubc->processUnbufferedKeyInput();

        ubc->frameStarted();
		// run the message pump (Eihort)
		Ogre::WindowEventUtilities::messagePump();

		render->getMRoot()->renderOneFrame();

    }

    input->destroy();

   return 0;
}


#ifdef __cplusplus
}
#endif

