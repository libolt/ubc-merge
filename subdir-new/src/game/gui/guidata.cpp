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

#include "network.h"

#include "gui.h"
#include "conversion.h"
#include "courtdata.h"
#include "gameengine.h"
#include "gamestate.h"
#include "load.h"
#include "logging.h"
#include "renderengine.h"
#include "teamdata.h"

#ifdef __ANDROID__
#include "android-config.h"
#else
#include "config.h"
#endif

bool GUISystem::addCourtSelectionMenuData() // adds data to Player Start Selection Menu widgets
{
    //gameState *gameS = gameState::Instance();
    boost::shared_ptr<gameState> gameS = gameState::Instance();
    
    std::vector<courtData> courtDataInstance;
    std::vector<std::string> courtName;
    if (!gameS->getCourtDataLoaded())
    {
        if (gameS->createCourtDataInstances())
        {
            gameS->setCourtDataLoaded(true);
        }
        else
        {
        }
    }
    courtDataInstance = gameS->getCourtDataInstance();
    
    for (size_t x=0;x<courtDataInstance.size();++x)
    {
        courtName.push_back(courtDataInstance[x].getName());
    }
    
    logMsg("courtName = " +courtName[0]);
    size_t i = 0;
    while (i<courtName.size())
    {
        courtSelectBox->addItem(courtName[i]);
        ++i;
    }
    
    return (true);
}

void GUISystem::addPlayerStartSelectionMenuData() // adds data to Player Start Selection Menu widgets
{
    //conversion *convert = conversion::Instance();
    boost::shared_ptr<conversion> convert = conversion::Instance();
    //gameState *gameS = gameState::Instance();
    boost::shared_ptr<gameState> gameS = gameState::Instance();
    
    boost::shared_ptr<loader> load = loader::Instance();

    std::vector<playerData> playerDataInstance; // = gameS->getPlayerDataInstance();
    playerDataInstance = load->loadPlayers();
    gameS->setPlayerDataInstances(playerDataInstance);

    std::vector<size_t> overAllRatings;
    std::vector<std::string> pNames;
    std::vector<std::string> pPositions;
    std::vector<size_t> pIDs;
    std::vector< std::vector<size_t> > overallRatings;
    std::vector<size_t> overall;

    size_t overallRatingsSize = 0;
    size_t flag = 1;
    size_t temp = 0;
    size_t tempID = 0;
    string tempName;
    string tempPosition;

    playerNames.push_back(pNames);
    playerNames.push_back(pNames);

    playerPositions.push_back(pPositions);
    playerPositions.push_back(pPositions);

    playerIDs.push_back(pIDs);
    playerIDs.push_back(pIDs);

    overallRatings.push_back(overall);
    overallRatings.push_back(overall);

    for (size_t i = 0;i < playerDataInstance.size(); ++i)
    {
        logMsg("pDTeam = " +convert->toString(playerDataInstance[i].getTeamID()));
        logMsg("teamID == " +convert->toString(gameS->getTeamID()[1]));
        if (playerDataInstance[i].getTeamID() == gameS->getTeamID()[0])
        {
            size_t overallRating = playerDataInstance[i].getOverallRating();
            std::string playerOverallRating = convert->toString(overallRating);
            std::string playerName = playerDataInstance[i].getFirstName() +" " +playerDataInstance[i].getLastName() +" " +convert->toString(playerDataInstance[i].getPrimaryPosition()); // +"            "; // +playerOverallRating;
            std::string playerPosition = convert->toString(playerDataInstance[i].getPrimaryPosition());
            size_t playerID = playerDataInstance[i].getID();

            playerNames[0].push_back(playerName);
            playerPositions[0].push_back(playerPosition);
            playerIDs[0].push_back(playerID);
            overallRatings[0].push_back(overallRating);
        }

        if (playerDataInstance[i].getTeamID() == gameS->getTeamID()[1])
        {
            size_t overallRating = playerDataInstance[i].getOverallRating();
            std::string playerOverallRating = convert->toString(overallRating);
            std::string playerName = playerDataInstance[i].getFirstName() +" " +playerDataInstance[i].getLastName( ) +" " +convert->toString(playerDataInstance[i].getPrimaryPosition()); // +"            "; // +playerOverallRating;
            bool playerNameLengthReached = false;
            std::string playerPosition = convert->toString(playerDataInstance[i].getPrimaryPosition());
            size_t playerID = playerDataInstance[i].getID();

            playerNames[1].push_back(playerName);
            playerPositions[1].push_back(playerPosition);
            playerIDs[1].push_back(playerID);
            overallRatings[1].push_back(overallRating);
        }
    }



    overallRatingsSize = overallRatings[0].size();
    flag = 1;
    temp = 0;
    tempID = 0;
    tempName.clear();
    tempPosition.clear();
    logMsg("overallRating before = " +convert->toString(overallRatings[0][0]));
    for (size_t l=0; l<overallRatingsSize && flag; ++l)
    {
        flag = 0;
        for (size_t j=0; j < (overallRatingsSize -1); ++j)
        {
            if (overallRatings[0][j+1] > overallRatings[0][j])      // ascending order simply changes to <
            {
                temp = overallRatings[0][j];             // swap elements
                tempName = playerNames[0][j];
                tempPosition = playerPositions[0][j];
                tempID = playerIDs[0][j];

                overallRatings[0][j] = overallRatings[0][j+1];
                playerNames[0][j] = playerNames[0][j+1];
                playerPositions[0][j] = playerPositions[0][j+1];
                playerIDs[0][j] = playerIDs[0][j+1];

                overallRatings[0][j+1] = temp;
                playerNames[0][j+1] = tempName;
                playerPositions[0][j+1] = tempPosition;
                playerIDs[0][j+1] = tempID;

                flag = 1;               // indicates that a swap occurred.
            }
        }

    }

    logMsg("overallRating after = " +convert->toString(overallRatings[0][0]));

    overallRatingsSize = overallRatings[1].size();
    flag = 1;
    temp = 0;
    tempID = 0;
    tempName.clear();
    tempPosition.clear();
    logMsg("overallRating before = " +convert->toString(overallRatings[1][0]));
    for (size_t l=0; l<overallRatingsSize && flag; ++l)
    {
        flag = 0;
        for (size_t j=0; j < (overallRatingsSize -1); ++j)
        {
            if (overallRatings[1][j+1] > overallRatings[1][j])      // ascending order simply changes to <
            {
                temp = overallRatings[1][j];             // swap elements
                tempName = playerNames[1][j];
                tempPosition = playerPositions[1][j];
                tempID = playerIDs[1][j];

                overallRatings[1][j] = overallRatings[1][j+1];
                playerNames[1][j] = playerNames[1][j+1];
                playerPositions[1][j] = playerPositions[1][j+1];
                playerIDs[1][j] = playerIDs[1][j+1];

                overallRatings[1][j+1] = temp;
                playerNames[1][j+1] = tempName;
                playerPositions[1][j+1] = tempPosition;
                playerIDs[1][j+1] = tempID;

                flag = 1;               // indicates that a swap occurred.
            }
        }

    }
    logMsg("overallRating after = " +convert->toString(overallRatings[1][0]));

    std::vector<size_t> starters; // used for initial creatio  of teamStarterID vector
//    starters.push_back(1);
    for (size_t i=0;i<5;++i)
    {
        team0IDs.push_back(starters);
        team1IDs.push_back(starters);
    }

    size_t startID = 0;
/*    for (size_t i=0;i<5;++i)
    {

        teamStarterID[0].push_back(startID);
//        exit(0);
        teamStarterID[1].push_back(startID);
//        exit(0);
    }
*/
    for (size_t i = 0;i < playerNames[0].size(); ++i)
    {
       bool playerNameLengthReached = false;
        while (!playerNameLengthReached)
        {
            if (playerNames[0][i].length() >= 18)
            {
                playerNameLengthReached = true;
            }
            else
            {
                playerNames[0][i] += " ";
            }
        }
        playerNames[0][i] += " " +convert->toString(overallRatings[0][i]);
        logMsg("playerNames[0][i] == " +playerNames[0][i]);

        std::string PName;
        if (playerPositions[0][i] == "PG")
        {
            team0PGSelectBox->addItem(playerNames[0][i]);
            team0IDs[0].push_back(playerIDs[0][i]);
//            exit(0);
        }
        else if (playerPositions[0][i] == "SG")
        {
            team0SGSelectBox->addItem(playerNames[0][i]);
            team0IDs[1].push_back(playerIDs[0][i]);
       }
        else if (playerPositions[0][i] == "SF")
        {
            team0SFSelectBox->addItem(playerNames[0][i]);
            team0IDs[2].push_back(playerIDs[0][i]);
        }
        else if (playerPositions[0][i] == "PF")
        {
            team0PFSelectBox->addItem(playerNames[0][i]);
            team0IDs[3].push_back(playerIDs[0][i]);
       }
        else if (playerPositions[0][i] == "C")
        {
            team0CSelectBox->addItem(playerNames[0][i]);
            team0IDs[4].push_back(playerIDs[0][i]);
       }
        else
        {

        }
    }

    for (size_t i=0;i<playerIDs[0].size();++i)
    {
        logMsg("PlayerIDs == " +convert->toString(playerIDs[0][i]));
    }

//    exit(0);

    logMsg("PG == " +team0PGSelectBox->getItemNameAt(0));
    logMsg("PG ID == " +convert->toString(team0IDs[0][0]));
//    exit(0);
    logMsg("SG == " +team0SGSelectBox->getItemNameAt(0));
    logMsg("SG ID == " +convert->toString(team0IDs[1][0]));
    logMsg("SF == " +team0SFSelectBox->getItemNameAt(0));
    logMsg("SF ID == " +convert->toString(team0IDs[2][0]));
    logMsg("PF == " +team0PFSelectBox->getItemNameAt(0));
    logMsg("PF ID == " +convert->toString(team0IDs[3][0]));
    logMsg("C == " +team0CSelectBox->getItemNameAt(0));
    logMsg("C ID == " +convert->toString(team0IDs[4][0]));
//    exit(0);

    for (size_t i = 0;i < playerNames[1].size(); ++i)
    {
       bool playerNameLengthReached = false;
        while (!playerNameLengthReached)
        {
            if (playerNames[1][i].length() >= 18)
            {
                playerNameLengthReached = true;
            }
            else
            {
                playerNames[1][i] += " ";
            }
        }
        playerNames[1][i] += " " +convert->toString(overallRatings[1][i]);
        logMsg("playerNames[1][i] == " +playerNames[1][i]);

        std::string PName;

        if (playerPositions[1][i] == "PG")
        {
            team1PGSelectBox->addItem(playerNames[1][i]);
            team1IDs[0].push_back(playerIDs[1][i]);
            logMsg("Adding PG1");
        }
        else if (playerPositions[1][i] == "SG")
        {
            team1SGSelectBox->addItem(playerNames[1][i]);
            team1IDs[1].push_back(playerIDs[1][i]);
            logMsg("Adding SG1");
        }
        else if (playerPositions[1][i] == "SF")
        {
            team1SFSelectBox->addItem(playerNames[1][i]);
            team1IDs[2].push_back(playerIDs[1][i]);
            logMsg("Adding SF1");
        }
        else if (playerPositions[1][i] == "PF")
        {
            team1PFSelectBox->addItem(playerNames[1][i]);
            team1IDs[3].push_back(playerIDs[1][i]);
            logMsg("Adding PF1");
        }
        else if (playerPositions[1][i] == "C")
        {
            team1CSelectBox->addItem(playerNames[1][i]);
            team1IDs[4].push_back(playerIDs[1][i]);
            logMsg("Adding C1");
        }
        else
        {

        }

    }

    logMsg("PG1 == " +team1PGSelectBox->getItemNameAt(0));
    logMsg("PG1 ID == " +convert->toString(team1IDs[0][0]));

    logMsg("SG1 == " +team1SGSelectBox->getItemNameAt(0));
    logMsg("SG1 ID == " +convert->toString(team1IDs[1][0]));

    logMsg("SF1 == " +team1SFSelectBox->getItemNameAt(0));
    logMsg("SF1 ID == " +convert->toString(team1IDs[2][0]));

    logMsg("PF1 == " +team1PFSelectBox->getItemNameAt(0));
    logMsg("PF1 ID == " +convert->toString(team1IDs[3][0]));

    logMsg("C1 == " +team1CSelectBox->getItemNameAt(0));
    logMsg("C1 ID == " +convert->toString(team1IDs[4][0]));

//    exit(0);

    
}

