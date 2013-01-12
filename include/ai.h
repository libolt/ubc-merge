/***************************************************************************
 *   Copyright (C) 2003 by Mike McLean                                     *
 *   libolt@libolt.net                                                     *
 *                                                                         *
 *   This program is free software; you can redistribute it and/or modify  *
 *   it under the terms of the GNU General Public License as published by  *
 *   the Free Software Foundation; either version 2 of the License, or     *
 *   (at your option) any later version.                                   *
 ***************************************************************************/

 #ifndef _AI_H_
 #define _AI_H_

class aiPlayers 
{
public:

    // gets and sets the aiXCoords	
    int getAiXCoord(int player);
    void setAiXCoord(int player, int XCoord);
    
    // gets and sets the aiYCoords	
    int getAiYCoord(int player);
    void setAiYCoord(int player, int YCoord);
    
    // gets and sets aiHasBasketball
    bool getAiHasBasketball(void);
    void setAiHasBasketball(bool has);
    
    // gets and sets playerAIControlled
    bool getPlayerAIControlled(int player);
    void setPlayerAIControlled(int player, bool controlled);
    
    // gets and sets playerUnderAIControl;
    int getPlayerUnderAIControl(void);
    void setPlayerUnderAIControl(int player);
    
    // gets and sets aiOFfenseSet
    bool getAiOffenseSet(void);
    void setAiOffenseSet(bool set);
    
    // gets and sets aiOffenseSelection
    int getAiOffenseSelection(void);
    void setAiOffenseSelection(int selection);
    
    // AI function prototypes
    
    // initial setup of AI players
    int aiSetup(void);
    
    // ai jump ball routines
    int aiJumpBall(void);
    
    // sets up ai offense
    int aiOffenseSetup(void);
    
    // executes ai offense
    int aiOffenseExecute(void);
    
    // gets teamAIControlled
    int getTeamAIControlled(void);
    void setTeamAIControlled(int team);
    
    static aiPlayers *Instance();
protected:
    aiPlayers();
    aiPlayers(const aiPlayers&);
    aiPlayers& operator= (const aiPlayers&);
private:
    static aiPlayers *pInstance;
    
    int aiXCoords[10];
    int aiYCoords[10];
    
    bool aiHasBasketball;
    
    // stores whether or not a player is under the AI's control
    bool playerAIControlled[10];
    
    // stores which ai player is currently
    int playerUnderAIControl;
    
    // sets whether or not the ai offense is setup
    
    bool aiOffenseSet;
    
    // selection of which offense ai is to run
    int aiOffenseSelection;
    
    int teamAIControlled; // defines which team is controlled by AI, valid values are 0= none 1= 
};

 #endif

