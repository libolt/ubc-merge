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

 #include "logging.h"
 
 #include "Ogre.h"
 #include "renderengine.h"
 
logging* logging::pInstance = 0;

logging* logging::Instance()
{
    if (pInstance == 0)  // is it the first call?
    {
        pInstance = new logging; // create sole instance
    }
    return pInstance; // address of sole instance
}
 
logging::logging()
{
	 
}
 
logging::~logging()
{
	 
}
 
void logging::logMessage(std::string msg)
{
	renderEngine *renderE = renderEngine::Instance();
	 
	if (renderE->getMRoot()->isInitialised())
    {
		Ogre::LogManager::getSingletonPtr()->logMessage(msg);
	}
	else
	{
        #ifdef __ANDROID__
	        __android_log_print(ANDROID_LOG_DEBUG, "com.libolt.ubc", msg.c_str());
        #endif
	}
}
 
