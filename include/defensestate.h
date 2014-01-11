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

#ifndef _DEFENSESTATE_H_
#define _DEFENSESTATE_H_

class defenseState
{
public:

	defenseState();	// constructor

	virtual bool getExecute();	// retrieves the value of execute variable
	virtual void setExecute(bool ex);	// sets the value of the execute variable

	virtual void setupState();		// sets up initial state of the object

	virtual void updateState();	// updates the state of the object

private:

	bool execute;	// If set then execute the defense logic

};

#endif
