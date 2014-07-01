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

#ifndef _OFFENSE_H_
#define _OFFENSE_H_

#include "enums.h"

class offenses
{
public:

    offenses();
    virtual ~offenses();

protected:

    virtual int execute(void);   // executes selected offense

    virtual int pgExecute(void);

    virtual int sgExecute(void);

    virtual int sfExecute(void);

    virtual int pfExecute(void);

    virtual int cExecute(void);

    virtual int checkPlayerPosition(void);

    virtual float *getPlayerStartPos(void); // retrieves playerStartPos value
    virtual void setPlayerStartPos(float *startPos);    // sets playerStartPos value

    virtual bool getPlayerStartPosSet(void);    // retrieves playerStartPosSet value
    virtual void setPlayerStartPosSet(bool set);    // sets playerStartPosSet value

    virtual bool getPgStartPosSet(void);    // retrieves pgStartPosSet value
    virtual void setPgStartPosSet(bool set);    // sets pgStartPosSet value

    virtual bool getSgStartPosSet(void);    // retrieves sgStartPosSet value
    virtual void setSgStartPosSet(bool set);    // sets sgStartPosSet value

    virtual bool getSfStartPosSet(void);    // retrieves sfStartPosSet value
    virtual void setSfStartPosSet(bool set);    // sets sfStartPosSet value

    virtual bool getPfStartPosSet(void);    // retrieves pfStartPosSet value
    virtual void setPfStartPosSet(bool set);    // sets pfStartPosSet value

    virtual bool getCStartPosSet(void);    // retrieves cStartPosSet value
    virtual void setCStartPosSet(bool set);    // sets cStartPosSet value

    virtual offenseTypes getOffenseType(void);	// returns offenseType variable
    virtual void setOffenseType(offenseTypes type);	// sets offenseType variable;
private:

    float *playerStartPos;    // stores start Positions for player

    bool playerStartPosSet; // value for whether or not players are at their starting positions
    bool pgStartPosSet;     // value for whether a Point Guard's start position is set.
    bool sgStartPosSet;     // value for whether a Shooting Guard's start position is set
    bool sfStartPosSet;     // value for whether a Small Forward's start position is set
    bool pfStartPosSet;     // value for whether a Power Forward's start position is set
    bool cStartPosSet;      // value for whether a Center's start position is set

    offenseTypes offenseType;	// Stores which offense is being run

};

class boxOffense : public offenses
{
public:

    boxOffense();
    virtual ~boxOffense();

    courtSide_t getCourtSide(void);
    void setCourtSide(courtSide_t side);

protected:

    virtual int executeOffense(void);
    virtual int setPositions(void);
    virtual int pgExecuteOffense(void);
    virtual int sgExecuteOffense(void);
    virtual int sfExecuteOffense(void);
    virtual int pfExecuteOffense(void);
    virtual int cExecuteOffense(void);

private:

    courtSide_t courtSide;// stores which side of the court offense is run on

};
/*
class offenses
{

public:

	// tracks game time
	int time;

	Uint32 shotStartTime;
	Uint32 shotEndTime;

	int pointGuardStartXCoord;
	int pointGuardStartYCoord;

	int shootingGuardStartXCoord;
	int shootingGuardStartYCoord;

	int smallForwardStartXCoord;
	int smallForwardStartYCoord;

	int powerForwardStartXCoord;
	int powerForwardStartYCoord;

	int centerStartXCoord;
	int centerStartYCoord;

	int timeBasketballShot;

	int timeBasketballInMotion;

	bool pointGuardSet;
	bool shootingGuardSet;
	bool smallForwardSet;
	bool powerForwardSet;
	bool centerSet;

	bool boxOffensePositionsSet;




	// sets up the offense
	bool setupOffense(void);

	// sets up box offense
	bool boxOffenseSetup(void);

	// sets positions for box offense

	bool boxOffenseSetPositions(void);

	// executes box offense
	bool boxOffenseExecute(void);


	// sets up motion offense
	bool setupMotionOffense(void);

	int calculateShot(int player);

	int checkShot(void);

	int beginShot(int player);
	int updateShot(void);
	int endShot(void);

	int getPlayerGuard(int player);
	void setPlayerGuard(int player, int playerGuarding);

	bool getPlayerSetPick(int player);
	void setPlayerSetPick(int player, bool setPick);

	int getPlayerToPickFor(int player);
	void setPlayerToPickFor(int picker, int pickFor);

	int getDefenderToPick(int picker);
	void setDefenderToPick(int picker,int defender);


	bool getPickSet(int player);
	void setPickSet(int player, bool pickSetValue);

	// gets and sets high point of shot
	int getShotHighPoint(void);
	void setShotHighPoint(int highPoint);

	// gets and sets low point of shot
	int getShotLowPoint(void);
	void setShotLowPoint(int lowPoint);

	// gets and sets shot's max arc X coord
	int getMaxArcXCoord(void);
	void setMaxArcXCoord(int XCoord);

	// gets and sets shot's max arc Y coord
	int getMaxArcYCoord(void);
	void setMaxArcYCoord(int YCoord);

	// gets and sets maxArcReached
	bool getMaxArcReached(void);
	void setMaxArcReached(bool reached);

	// gets and sets maxArcXReached
	bool getMaxArcXReached(void);
	void setMaxArcXReached(bool reached);

	// gets and sets maxArcYReached
	bool getMaxArcYReached(void);
	void setMaxArcYReached(bool reached);

	int getEndArcXCoord(void);
	void setEndArcXCoord(int XCoord);

	int getEndArcYCoord(void);
	void setEndArcYCoord(int YCoord);

	bool getEndArcReached(void);
	void setEndArcReached(bool reached);

	bool getEndArcXReached(void);
	void setEndArcXReached(bool reached);

	bool getEndArcYReached(void);
	void setEndArcYReached(bool reached);

	// gets and sets shotCalculcated
	bool getShotCalculated(void);
	void setShotCalculated(bool calculated);

	bool getShotTaken(void);
	void setShotTaken(bool taken);

	double getInitialShotXCoord(void);
	void setInitialShotXCoord(double XCoord);

	double getInitialShotYCoord(void);
	void setInitialShotYCoord(double XCoord);

	bool getOffenseSet(void);
	void setOffenseSet(bool set);

	bool getBox(void);
	void setBox(bool set);

	bool getBoxSet(void);
	void setBoxSet(bool set);

	bool getMotion(void);
	void setMotion(bool set);

	bool getMotionSet(void);
	void setMotionSet(bool set);

	static offenses *Instance();
protected:
	offenses();
	offenses(const offenses&);
	offenses& operator= (const offenses&);
private:
	static offenses *pInstance;


	// flag determining if offense is setup
	bool offenseSet;

	// flags for running box offense
	bool box;
	bool boxSet;

	// flags for running motion offense
	bool motion;
	bool motionSet;


	// defines which opponent the player is guarding if on defense
	int playerGuard[10];

	// flag that when set true invokes the player to set a pick
	bool playerSetPick[10];

	// if playerSetPick is true then this variable sets which player's man is to be picked
	int playerToPickFor[10];

	// defender to pick

	int defenderToPick[10];

	// determines whether or not pick was set
	bool pickSet[10];

	// shot related variables

	double initialShotXCoord;
	double initialShotYCoord;
	int maxArcXCoord;		// sets the X coord of basketball's max arc when shot

	int maxArcYCoord;		// sets the Y coord of the basketball's max arc when shot

	int endArcXCoord;		// sets the X coord of the end of the baskeball's arc when shot

	int endArcYCoord;		// sets the Y coord of the end of the basketball's arc when shot

	bool maxArcReached;	// sets flag of whether max arc of ball is reached during shot

	bool maxArcXReached;	// flag that is set when the max arc X of a shot is reached.

	bool maxArcYReached;	// flag that is set when the max arc Y of a shot is reached.

	bool shotCalculated;

	bool shotTaken;

	bool endArcReached;
	bool endArcXReached;

	bool endArcYReached;

};
*/
#endif


