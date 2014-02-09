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

// #include "main.h"
#include "gamestate.h"
#include "players.h"

using namespace std;

players* players::pInstance = 0;
players* players::Instance()
{
    if (pInstance == 0)  // is it the first call?
    {
        pInstance = new players; // create sole instance
    }
    return pInstance; // address of sole instance
}

players::players()
{
    // initializes and sets player coordinate variables to zero
    for (int x = 0; x <10;++x)
    {
//      playerXCoords[x] = 0;
//      playerYCoords[x] = 0;
        playerAnimationMode[x] = 0;
        playerDirection.push_back(0);
        oldPlayerDirection.push_back(0);
//      playerTeam[x] = 0;
        playerAI[x] = false;
        playerJump[x] = false;
        playerJumped[x] = false;
        playerJumpMaxHeight[x] = 0; //playerYCoords[x] + 10;
        playerJumpMinHeight[x] = 0;  //playerYCoords[x];
    }

        // initalizes playerHasBasketall setting the value to -1 to indicate no player controls the basketball
//      playerHasBasketball = -1;

    // initializes basketball player that's under control to that of 1st players center
    playerUnderControl = 4;

    playerControlBasketball = -1;

}



players::~players()
{
}

int players::getPlayerAnimationMode(int player)
{
    return (playerAnimationMode[player]);
}

void players::setPlayerAnimationMode(int player, int animationMode)
{
    playerAnimationMode[player] = animationMode;
}

// gets and sets which player controls basketball
int players::getPlayerControlBasketball(void)
{
    return(playerControlBasketball);
}

void players::setPlayerControlBasketball(int player)
{
    playerControlBasketball = player;
}

vector<int> players::getPlayerDirection()
{
    return(playerDirection);
}

void players::setPlayerDirection(std::vector<int> direction)
{
    playerDirection = direction;
}

vector<int> players::getOldPlayerDirection()
{
    return (oldPlayerDirection);
}
void players::setOldPlayerDirection(std::vector<int> direction)
{
    oldPlayerDirection = direction;
}
// // gets and sets playerHasBasketball
// int players::getPlayerHasBasketball(void)
// {
// 	return(playerHasBasketball);
// }
//
// void players::setPlayerHasBasketball(int player)
// {
// 	playerHasBasketball = player;
// }

// returns array of player
vector<playerData> players::getPlayer()
{
    return(player);
}

// adds to array of player;
void players::addPlayer(playerData data)
{
    player.push_back(data);
}
// gets and sets playerUnderControl
int players::getPlayerUnderControl(void)
{
    return(playerUnderControl);
}

void players::setPlayerUnderControl(int player)
{
    playerUnderControl = player;
}


bool players::getPlayerJump(int player)
{
    return(playerJump[player]);
}

void players::setPlayerJump(int player, bool jump)
{
    playerJump[player] = jump;
}

bool players::getPlayerJumped(int player)
{
    return(playerJumped[player]);
}
void players::setPlayerJumped(int player, bool jumped)
{
    playerJumped[player] = jumped;
}
int players::getPlayerJumpMaxHeight(int player)
{
    return(playerJumpMaxHeight[player]);
}
void players::setPlayerJumpMaxHeight(int player, int maxHeight)
{
    playerJumpMaxHeight[player] = maxHeight;
}
int players::getPlayerJumpMinHeight(int player)
{
    return(playerJumpMinHeight[player]);
}
void players::setPlayerJumpMinHeight(int player, int minHeight)
{
    playerJumpMinHeight[player] = minHeight;
}

vector<Ogre::SceneNode*> players::getNode()
{
    return(node);
}

void players::setNode(std::vector<Ogre::SceneNode*> Node)
{
    node = Node;
}

vector<Ogre::Entity*> players::getModel()
{
    return (model);
}
void players::setModel(std::vector<Ogre::Entity*> Model)
{
    model = Model;
}

/* int players::getPlayerTeam(int player)
{
	return(playerTeam[player]);
}
void players::setPlayerTeam(int player, int team)
{
	playerTeam[player] = team;
}
*/
bool players::getPlayerAI(int player)
{
    return(playerAI[player]);
}

void players::setPlayerAI(int player, bool AI)
{
    playerAI[player] = AI;
}

int players::getTotalPlayers(void)
{
    return(totalPlayers);
}

void players::setTotalPlayers(int players)
{
    totalPlayers = players;
}

// change positions of players nodes
bool players::changePositions()
{
	/*
    gameState *gameS = gameState::Instance();
//exit(0);
    std::vector <int> playerIDS = gameS->getPlayerID();      // copies playerID values to playerIDS
    std::vector <int>::iterator playersIT;   // iterator for player IDs

    std::vector<teamState> teamInstance = gameS->getTeamInstance();
    std::vector <playerState> pInstance = gameS->getPlayerInstance();
//	cout << "posChange[0] = " << posChange[0] << endl;
    for (int i = 0; i < 10; i++)
//    for (playersIT = playerIDS.begin();playersIT != playerIDS.end(); ++playersIT)
    {
//        cout << posChange[i] << endl;
//         node[i]->translate(posChange[i]);
//        pInstance[i].getNode()->translate(posChange[i]);
//        node[*playersIT]->translate(posChange[*playersIT]);
    }
    */
    return true;
}

int players::checkPlayerMoveStatus(int player, int positionXCoord, int positionYCoord)
{

    int playerXCoord = 0;// = playerGame[player].getPlayerXCoord();
    int playerYCoord = 0;// = playerGame[player].getPlayerYCoord();
//	int object1X = playerXCoords[player];
//	int object1Y = playerYCoords[player];
//	int object1H = playerSprites[player]->h;
//	int object1W = playerSprites[player]->w;

//	cout <<"player " << player << " animation mode " <<  playerAnimationMode[player] << endl;
	//exit(0);
//	if (playerAnimationMode[player] == 4
    if (playerXCoord == positionXCoord && playerYCoord == positionYCoord)
    {
//		cout << "player x coord = " << playerXCoords[player];
	//				exit(0);
//		pointGuardSet = true;
	//				cout << "DONE" << endl;
	//				exit(0);

//memcheck	cout << "player " << player << " set" << endl;
        return(1);
    }


/*	if (collisionCheck(object1X,object1Y,object1H,object1W,object2X,object2Y,object2H,object2W))
	{
		return(1);
	}
*/
    else
    {
        return(0);
    }
}

// moves a player into position according to set x and y coordinates
int players::movePlayerIntoPosition(int player, int positionXCoord, int positionYCoord)
{

//	int playerXCoord = playerGame[player].getPlayerXCoord();
//	int playerYCoord = playerGame[player].getPlayerYCoord();
// 	int animationMode = 0;
//
// 	// checks if point guard y coords are less than those of set position
// 	if (playerYCoord < positionYCoord)
// 	{
//
// 		// checks if point guard x coords are less than those of set position
// 		if (playerXCoord< positionXCoord)
// 		{
// 			// moves player down and right
// 			animationMode= 8;
// 		}
//
// 		// checks if point guard x coords are greater thann those of set position
// 		if (playerXCoord> positionXCoord)
// 		{
// 			// moves player down and left
// 			animationMode= 7;
// 		}
// 		else
// 		{
// 			// moves player down
// 			animationMode= 2;
// 		}
// 	}
//
// 	// checks if point guard y coords are greater than those of the set position
// 	if (playerYCoord> positionYCoord)
// 	{
//
// 		// checks if point guard x coords are greater than those of the set position
// 		if (playerXCoord> positionXCoord)
// 		{
// 			// moves player up and left
// 			animationMode = 5;
// 		}
//
// 		// checks if point guard x coords are less than those of set position
// 		if (playerXCoord< positionXCoord)
// 		{
// 			// moves player up and right
// 			animationMode= 6;
// 		}
//
// 		else
// 		{
// 			// moves player up
// 			animationMode= 1;
// 		}
// 	}
//
//
// 	// checks if point guard x coords are less than those of set position
// 	if (playerXCoord < positionXCoord)
// 	{
//
// 		// checks if point guard y coords are less than those of set position
// 		if (playerYCoord < positionYCoord)
// 		{
// 			//  moves player down and right
// 			animationMode= 8;
// 		}
//
// 		// checks if point guard y coords are greater thann those of set position
// 		if (playerYCoord> positionYCoord)
// 		{
// 			// moves player up and right
// 			animationMode= 6;
// 		}
// 		else
// 		{
// 			// moves player right
// 			animationMode= 4;
// 		}
// 	}
//
// 	// checks if point guard x coords are greater than those of the set position
// 	if (playerXCoord> positionXCoord)
// 	{
//
// 		// checks if point guard y coords are greater than those of the set position
// 		if (playerYCoord> positionYCoord)
// 		{
// 			// moves player up and left
// 			animationMode = 5;
// 		}
//
// 		// checks if point guard y coords are less than those of set position
// 		if (playerYCoord< positionYCoord)
// 		{
// 			// moves player down and left
// 			animationMode= 7;
// 		}
//
// 		else
// 		{
// 			// moves player left
// 			animationMode= 3;
// 		}
// 	}


//	return(animationMode);
    return(0);
}

