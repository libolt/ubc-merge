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

#ifndef _PLAYERS_H_
#define _PLAYERS_H_

#include <string>
#include <vector>

#ifdef __APPLE__
#include <Ogre/Ogre.h>
#include <Ogre/OgreVector3.h>
#else
#include "Ogre.h"
#include "OgreVector3.h"
#endif
//#include <OgreOde_Core.h>

#include "playerdata.h"

using namespace std;

class players
{
public:
//		players();
    ~players();

    static players *Instance();

    Ogre::AnimationState *mAnimationState[10];
    Ogre::AnimationState *mAnimationState2;
    // returns array of player
    std::vector<playerData> getPlayer();
    // adds to array of player;
    void addPlayer(playerData data);

    int getTotalPlayers(void);
    void setTotalPlayers(int players);


    // checks to see if player is in position
    int checkPlayerMoveStatus(int player, int positionXCoord, int positionYCoord);

    // moves player into position
    int movePlayerIntoPosition(int player, int positionXCoord, int positionYCoord);


    // gets and sets player under User control
    int getPlayerUnderControl(void);
    void setPlayerUnderControl(int player);

    int getPlayerControlBasketball(void);	// retrieves playerControlBasketball value
    void setPlayerControlBasketball(int player);		// sets playerControlBasketball value

    int getPlayerAnimationMode(int player);
    void setPlayerAnimationMode(int player, int animationMode);

    // gets and sets playerDirection
    std::vector<int> getPlayerDirection();
    void setPlayerDirection(std::vector<int> direction);

    // gets and sets oldPlayerDirection
    std::vector<int> getOldPlayerDirection();
    void setOldPlayerDirection(std::vector<int> direction);

    int getPlayerHasBasketball(void);
    void setPlayerHasBasketball(int player);

    bool getPlayerJump(int player);
    void setPlayerJump(int player, bool jump);

    bool getPlayerJumped(int player);
    void setPlayerJumped(int player, bool jumped);

    int getPlayerJumpMaxHeight(int player);
    void setPlayerJumpMaxHeight(int player, int maxHeight);

    int getPlayerJumpMinHeight(int player);
    void setPlayerJumpMinHeight(int player, int minHeight);



    bool changePositions();	// changes the positions of the player nodes

    int getPlayerTeam(int player);
    void setPlayerTeam(int player, int team);

    bool getPlayerAI(int player);
    void setPlayerAI(int player, bool AI);

    // gets and sets node
    std::vector<Ogre::SceneNode*> getNode();
    void setNode(std::vector<Ogre::SceneNode*> Node);

    std::vector<Ogre::Entity*> getModel();
    void setModel(std::vector<Ogre::Entity*> Model);

    // make private
/*    OgreOde::World *_world;
    Ogre::AxisAlignedBox aab;
    OgreOde::SimpleSpace *dollSpace;
    OgreOde::Body *dollFeetBody;
    OgreOde::SphereGeometry *feetGeom;
    OgreOde::TransformGeometry *feetTrans;
    OgreOde::Body *dollTorsoBody;
    OgreOde::TransformGeometry *torsoTrans;
    OgreOde::CapsuleGeometry *torsoGeom;
    OgreOde::HingeJoint *joint;
    OgreOde::Body *torso;
    OgreOde::Body *feet;
*/
protected:
    players();
    players(const players&);
    players& operator= (const players&);
    std::vector<int> playerDirection;
    std::vector<int> oldPlayerDirection;
    std::vector<bool> playerDirectionChanged;

private:
    static players *pInstance;

    int totalPlayers;
    std::vector<playerData> player;
//    std::vector<playerGameData> playerGame;

		// defines which player has the basketball
//		int playerHasBasketball;

		// define which team a player is a member of
//		int playerTeam[10];

    // defines if a player is controlled by the AI subsystem
    bool playerAI[10];

    // NOTE:  Make an array for multiple players
    int playerUnderControl;  // player that is controlled by the user

    int playerAnimationMode[10];  // determines which animation of player to draw

    int playerControlBasketball;  // stores which player if any controls the basketball

//		int playerDirection[10];	// determines which way player is facing
    // stores active player sprite

    // Key: 0 = still 1 = moving up (jumping) 2 = moving down 3 = moving left 4 = moving right

    bool playerJump[10];  // sets whether player is jumping in the air.
    bool playerJumped[10]; // sets whether a player has jumped in the air.
    int playerJumpMaxHeight[10]; // sets maximum jump height for players
    int playerJumpMinHeight[10]; //sets height of players landing;

    std::vector<Ogre::SceneNode*> node;
    std::vector<Ogre::Entity*> model;


};


#endif

