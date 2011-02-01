//
// C++ Interface: menus
//
// Description:
//
//
// Author: Mike McLean <libolt@libolt.net>, (C) 2006
//
// Copyright: See COPYING file that comes with this distribution
//
//

#ifndef _MENUS_H_
#define _MENUS_H_
/*
class menus
{
public:


	// initializes menus
	int menuInit(void);

	// drawss the menu at a given location
	int drawMenu(SDL_Surface *screen, SDL_Rect *coords);


	int mainMenu(void);
	int mainMenuInput(void);

	int startGameMenu(void);
	int startGameMenuInput(void);

	int optionsMenu(void);
	int optionsMenuInput(void);

	int selectPlayersMenu(void);
	int selectPlayersMenuInput(void);

	int selectTeamsMenu(void);
	int selectTeamsMenuInput(void);

	int setGameRulesMenu(void);
	int setGameRulesMenuInput(void);

	int setGameOptionsMenu(void);
	int setGameOptionsMenuInput(void);

	// sets the parameters then runs the game loop
	int startGame(void);

	SDL_Surface *getMenuScreen(void);
	void setMenuScreen(SDL_Surface *screen);

	SDL_Surface *getTeam1Logos(void);
	void setTeam1Logos(SDL_Surface *logos);

	SDL_Surface *getTeam2Logos(void);
	void setTeam2Logos(SDL_Surface *logos);

	static menus *Instance();
protected:
	menus();
	menus(const menus&);
	menus& operator= (const menus&);
private:
	static menus *pInstance;


	SDL_Surface *menuScreen;

	int numberHumanPlayers;	// stores the number of players controlled by human input
	int teamsSelected[2];	// array to store which teams are selected to play
	int selectedTeamNumber;	// stores the number of the selected team
	int humanPlayersTeam[4];	// sets which team a human controlled player is on
	int selectedPlayer;	// stores the selected player
	int playerStatus[4];

	// boolean values that determine whether a menu has been loaded into a memory buffer
	bool mainMenuLoaded;
	bool startGameMenuLoaded;
	bool optionsMenuLoaded;
	bool selectPlayersMenuLoaded;
	bool selectTeamsMenuLoaded;
	bool selectGameOptionsMenuLoaded;
	bool setGameRulesMenuLoaded;
	bool setGameOptionsMenuLoaded;


	bool team1LogoCoordsSet;
	bool team2LogoCoordsSet;
	bool teamLogoInitDraw;

	// menu surfaces
	SDL_Surface *selectTeamsMenuSurface;
	SDL_Surface *mainMenuSurface;
	SDL_Surface *startGameMenuSurface;
	SDL_Surface *optionsMenuSurface;
	SDL_Surface *selectPlayersMenuSurface;
	SDL_Surface *setGameRulesMenuSurface;
	SDL_Surface *setGameOptionsMenuSurface;

	// player button surfaces
	SDL_Surface *player1Surface;
	SDL_Surface *player2Surface;
	SDL_Surface *player3Surface;
	SDL_Surface *player4Surface;

	// team logo surfaces
	SDL_Surface *team1Logos;
	SDL_Surface *team2Logos;

	// coordinates for surfaces
	SDL_Rect selectTeamsMenuCoords, team1LogoCoords, team2LogoCoords, playerSelectCoords[4];


//	vector<string> datapaths;

	// array of paths to search for data files


};
*/
#endif

