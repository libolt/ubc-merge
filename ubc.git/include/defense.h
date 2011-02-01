//
// C++ Interface: defense
//
// Description: 
//
//
// Author: Mike McLean <libolt@libolt.net>, (C) 2006
//
// Copyright: See COPYING file that comes with this distribution
//
//

#ifndef _DEFENSE_H_
#define _DEFENSE_H_

class defenses
{
public:
	
    int getTeamOnDefense(void);
    void setTeamOnDefense(int team);
    
    bool getManToMan(void);
    void setManToMan(bool man);
    
    bool getZone(void);
    void setZone(bool zone);
    
    bool getDefenseSet(void);
    void setDefenseSet(bool set);
    
    
    bool getManToManSet(void);
    void setManToManSet(bool set);
    
    bool getZoneSet(void);
    void setZoneSet(bool set);
    
    // sets up defense
    bool setupDefense(void);
    bool setupManToManDefense(void);
    bool setupZoneDefense(void);
    
    // executes defense
    int executeDefense(void);
    int executeManToManDefense(void);
    int executeZoneDefense(void);
    
    
    static defenses *Instance();
protected:
    defenses();
    defenses(const defenses&);
    defenses& operator= (const defenses&);
private:
    static defenses *pInstance;
    
    
    int teamOnDefense;
    
    bool manToMan;
    bool zone;
    
    bool defenseSet;
    bool manToManSet;
    bool zoneSet;
    
    // holds approx X Y coordinates a defender should be at
    int defenderXCoord[5];
    int defenderYCoord[5];
};

#endif

