#include "teamstate.h"

teamState::teamState()
{
    assists = 0;
    blocks = 0;
    fouls = 0;
    rebounds = 0;
    steals = 0;
    technicals = 0;
    timeouts = 0;
}

teamState::~teamState()
{
}

int teamState::getAssists(void)   // retrieves assists
{
    return (assists);
}
void teamState::setAssists(int assist)    // sets assists
{
    assists = assist;
}

int teamState::getBlocks(void)    // retrieves blocks
{
    return (blocks);
}
void teamState::setBlocks(int block)   // sets blocks
{
    blocks = block;
}

int teamState::getFouls(void) // retrieves fouls
{
    return (fouls);
}
void teamState::setFouls(int foul)    // sets fouls
{
    fouls = foul;
}

int teamState::getRebounds(void)  // retrieves rebounds
{
    return (rebounds);
}
void teamState::setRebounds(int rebound)  // sets rebounds
{
    rebounds = rebound;
}

int teamState::getOffensiveRebounds(void) // retrieves offensiveRebounds
{
    return (offensiveRebounds);
}
void teamState::setOffensiveRebounds(int rebounds)    // sets offensiveRebounds
{
    offensiveRebounds = rebounds;
}
int teamState::getDefensiveRebounds(void) // retrieves defensiveRebounds
{
    return (defensiveRebounds);
}
void teamState::setDefensiveRebounds(int rebounds)    // sets defensiveRebounds
{
    defensiveRebounds = rebounds;
}

int teamState::getSteals(void)    // retrieves steals
{
    return (steals);
}
void teamState::setSteals(int steal)    // sets steals
{
    steals = steal;
}

int teamState::getTechnicals(void)    // retrieves technicals
{
    return (technicals);
}
void teamState::setTechnicals(int technical)  // sets technicals
{
    technicals = technical;
}

int teamState::getTimeouts(void)  // retrieves timeouts
{
    return (timeouts);
}
void teamState::setTimeouts(int timeout)  // sets timeouts
{
    timeouts = timeout;
}

int teamState::getFieldGoalsAttempted(void)   // retrieves fieldGoalsAttempted
{
    return (fieldGoalsAttempted);
}
void teamState::setFieldGoalsAttempted(int fieldGoals)    // sets fieldGoalsAttempted
{
    fieldGoalsAttempted = fieldGoals;
}

int teamState::getFieldGoalsMade(void)   // retrieves fieldGoalsMade
{
    return (fieldGoalsMade);
}
void teamState::setFieldGoalsMade(int fieldGoals)    // sets fieldGoalsMade
{
    fieldGoalsMade = fieldGoals;
}

int teamState::getThreePointersAttempted(void)   // retrieves threePointersAttempted
{
    return (threePointersAttempted);
}
void teamState::setThreePointersAttempted(int threePointers)  // sets threePointersAttempted
{
    threePointersAttempted = threePointers;
}

int teamState::getThreePointersMade(void)   // retrieves threePointersMade
{
    return (threePointersMade);
}
void teamState::setThreePointersMade(int threePointers)  // sets threePointersMade
{
    threePointersMade = threePointers;
}

int teamState::getFreeThrowsAttempted(void)   // retrieves freeThrowsAttempted
{
    return (freeThrowsAttempted);
}
void teamState::setFreeThrowsAttempted(int freeThrows)    // sets freeThrowsAttempted
{
    freeThrowsAttempted = freeThrows;
}

int teamState::getFreeThrowsMade(void)   // retrieves freeThrowsMade
{
    return (freeThrowsMade);
}
void teamState::setFreeThrowsMade(int freeThrows)    // sets freeThrowsMade
{
    freeThrowsMade = freeThrows;
}

vector<int> teamState::getPlayerID()  // retrieves playerID
{
    return (playerID);
}
void teamState::setPlayerID(std::vector<int> ID)   // sets playerID
{
    playerID = ID;
}
vector<int> teamState::getStarterID() // retrieves starterID
{
    return (starterID);
}
void teamState::setStarterID(std::vector<int> ID)  // sets starterID
{
    starterID = ID;
}
