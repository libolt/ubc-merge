/***************************************************************************
 *   Copyright (C) 1999 - 2015 by Mike McLean   *
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

#include "conversion.h"
#include "gamestate.h"
#include "comparison.h"
#include "logging.h"
#include "physicsengine.h"
#include "jumpballs.h"

jumpBalls::jumpBalls()
{
    ballTipped = false;
    ballTippedToTeam = NOTEAM;
    ballTippedToPlayerID = -1;
    ballTippedToPosition = NONE;
    ballTipForceApplied = false;
    setupComplete = false;
    executeJumpBall = false;
    
}

jumpBallLocations_t jumpBalls::getJumpBallLocation()  // retrieves teh value of jumpBallLocation
{
    return (jumpBallLocation);
}
void jumpBalls::setJumpBallLocation(jumpBallLocations_t set)  // sets the value of jumpBallLocation
{
    jumpBallLocation = set;
}

std::vector<playerPositions> jumpBalls::getJumpBallPlayer()  // retrieves the value of jumpBallPlayer
{
    return (jumpBallPlayer);
}
void jumpBalls::setJumpBallPlayer(std::vector<playerPositions> set)  // sets the value of jumpBallPlayer
{
    jumpBallPlayer = set;
}

bool jumpBalls::getBallTipped()	 // retrieves the value of ballTipped
{
    return (ballTipped);
}
void jumpBalls::setBallTipped(bool tipped)  // sets the value of ballTipped
{
    ballTipped = tipped;
}

teamTypes jumpBalls::getBallTippedToTeam()  // retrieves the value of ballTippedToTeam
{
    return (ballTippedToTeam);
}
void jumpBalls::setBallTippedToTeam(teamTypes set)  // sets the value of ballTippedToTeam
{
    ballTippedToTeam = set;
}
int jumpBalls::getBallTippedToPlayerID()  // retrieves the value of ballTippedToPlayerID
{
    return (ballTippedToPlayerID);
}
void jumpBalls::setBallTippedToPlayerID(int player)	 // sets the value of ballTippedToPlayerID
{
    ballTippedToPlayerID = player;
}

playerPositions jumpBalls::getBallTippedToPosition()  // retrieves the value of ballTippedToPosition
{
    return (ballTippedToPosition);
}
void jumpBalls::setBallTippedToPosition(playerPositions set)  // sets the value of ballTippedToPosition
{
    ballTippedToPosition = set;
}

bool jumpBalls::getBallTipForceApplied()  // retrieves the value of ballTipForceApplied
{
    return (ballTipForceApplied);
}
void jumpBalls::setBallTipForceApplied(bool tip)  // sets the value of ballTipForceApplied
{
    ballTipForceApplied = tip;
}

bool jumpBalls::getSetupComplete()  // retrieves the value of setup
{
    return (setupComplete);
}
void jumpBalls::setSetupComplete(bool set)  // sets the value of setup
{
    setupComplete = set;
}

bool jumpBalls::getExecuteJumpBall()  // retrieves the value of executeJumpBall
{
    return (executeJumpBall);
}
void jumpBalls::setExecuteJumpBall(bool set)  // sets the value of executeJumpBall
{
    executeJumpBall = set;
}

btVector3 jumpBalls::getBBallVelocity()  // retrieves the value of bballVelocity
{
    return (bballVelocity);
}
void jumpBalls::setBBallVelocity(const btVector3 &set)  // sets the value of bballVelocity
{
    bballVelocity = set;
}

bool jumpBalls::updateState()  // updates state of the jumpBalls instance
{

    if (!jumpBallComplete)
    {
        if (!ballTipped)
        {
            ballTipped = jumpBallExecute();  // executes jump ball until ball is tipped
        }
        else
        {
            jumpBallComplete = tipToPlayer();
        }

    }

    else
    {
        return (true);
    }
    return (false);  // returns false until jump ball has completed
}

bool jumpBalls::jumpBallExecute() // initiates jump ball from jump ball circle
{

    boost::shared_ptr<conversion> convert = conversion::Instance();
    boost::shared_ptr<gameState> gameS = gameState::Instance();
    boost::shared_ptr<physicsEngine> physEngine = physicsEngine::Instance();

    std::vector<basketballs> basketballInstance = gameS->getBasketballInstance();
    int activeBBallInstance = gameS->getActiveBBallInstance();

    std::vector<teamState> teamInstance = gameS->getTeamInstance();
    std::vector< std::vector<playerState> > activePlayerInstance;


    //teamTypes currentTeam = jumpBall.getBallTippedToTeam();

    //std::vector<playerPositions> jumpBallPlayer = jumpBall.getJumpBallPlayer();

    std::vector<size_t> jumpPlayerInstance;  // stores playerID of players jumping for the ball

    if (gameS->getTeamWithBall() == NOTEAM && gameS->getTeamInstancesCreated())
    {
        size_t x = 0;
        while (x < teamInstance.size())
        {
            //activePlayerInstance.clear();
            activePlayerInstance.push_back(teamInstance[x].getActivePlayerInstance());
            size_t i = 0;

            while (i < activePlayerInstance[x].size()) // loops until the activePlayerInstance is found that is currently playing center
            {
                logMsg("jump i == " +convert->toString(i));
                if (activePlayerInstance[x][i].getActivePosition() == C)
                {

                    logMsg("jumpPlayerInstance = " +convert->toString(i));
                   // logMsg("PlayerName = " +activePlayerInstance[x][i].getPlayerName());
                    logMsg("ModelLoaded = " +convert->toString(activePlayerInstance[x][i].getModelLoaded()));
    //                    exit(0);
                    //jumpPlayerID.push_back(activePlayerInstance[i].getPlayerID());
                    jumpPlayerInstance.push_back(i);
                }
                i++;
                //teamTypes teamType = teamInstance[x].getTeamType();
                //size_t player = 4;
                //bool collCheck = collisionCheck(basketballInstance[activeBBallInstance].getPhysBody(), activePlayerInstance[centerID].getPhysBody());
                //logMsg("Team " +convert->toString(teamType) +" player " +convert->toString(player) +" collCheck == " +convert->toString(collCheck));
            }
            ++x;
        }
        logMsg("jumpPlayerID.size() = " +convert->toString(jumpPlayerInstance.size()));
        teamTypes teamType = teamInstance[0].getTeamType();
        bool collCheck = physEngine->collisionCheck(basketballInstance[activeBBallInstance].getPhysBody(), activePlayerInstance[0][jumpPlayerInstance[0]].getPhysBody());
        if (collCheck)
        {
            logMsg("team 0 center collided with ball");
            return (true);
        }
        logMsg("Team " +convert->toString(teamType) +" playerInstance " +convert->toString(jumpPlayerInstance[0]) +" collCheck == " +convert->toString(collCheck));
        teamType = teamInstance[1].getTeamType();
        collCheck = physEngine->collisionCheck(basketballInstance[activeBBallInstance].getPhysBody(), activePlayerInstance[1][jumpPlayerInstance[1]].getPhysBody());
        if (collCheck)
        {
            logMsg("team 1 center collided with ball");
            return (true);
        }
        logMsg("Team " +convert->toString(teamType) +" playerInstance " +convert->toString(jumpPlayerInstance[1]) +" collCheck == " +convert->toString(collCheck));

    //        exit(0);
    }
    return (false);  // executeJumpBall has not completed
}

bool jumpBalls::tipToPlayer()  // tips the basketball to the appropriate player
{
    boost::shared_ptr<gameState> gameS = gameState::Instance();
    boost::shared_ptr<conversion> convert = conversion::Instance();

    std::vector<basketballs> basketballInstance = gameS->getBasketballInstance();
    jumpBalls jumpBall = gameS->getJumpBall();
    teamTypes ballTippedToTeam = jumpBall.getBallTippedToTeam();
    quarters quarter = gameS->getQuarter();
    int activeBBallInstance = gameS->getActiveBBallInstance();

    if (quarter == NOQUARTER)
    {
        exit(0);
    }
/*    else if (quarter == FIRST)
    {
        exit(0);
    }
*/
    if (ballTipped)
    {
        switch (quarter)
        {
            case FIRST:
            case SECOND:
                logMsg("jump First/Second quarter");
                logMsg("ballTippedToTeam == " +convert->toString(ballTippedToTeam));
                exit(0);
                switch (ballTippedToTeam)
                {
                    case HOMETEAM:
                        bballVelocity.setX(20);
                        bballVelocity.setY(-1);
                        bballVelocity.setZ(0);
                        logMsg("jump HOMETEAM bballVelocity == " +convert->toString(bballVelocity));
                        return (true);

                    break;
                    case AWAYTEAM:
                        bballVelocity.setX(-20);
                        bballVelocity.setY(-1);
                        bballVelocity.setZ(0);
                        logMsg("jump AWAYTEAM bballVelocity == " +convert->toString(bballVelocity));
                        return (true);
                    break;
                    default:
                    break;
                }
            break;
            case THIRD:
            case FOURTH:
                logMsg("jump Third/Fourth quarter");
                switch (ballTippedToTeam)
                {
                    case HOMETEAM:
                        bballVelocity.setX(-20);
                        bballVelocity.setY(-1);
                        bballVelocity.setZ(0);
                        return (true);
                    break;
                    case AWAYTEAM:
                        bballVelocity.setX(20);
                        bballVelocity.setY(-1);
                        bballVelocity.setZ(0);
                        return (true);
                    break;
                    default:
                    break;
                }
            break;
            default:
            break;
        }
    }
    logMsg("jump bballVelocity == " +convert->toString(bballVelocity));
    return (false);  // tipToPlayer has not completed
}
