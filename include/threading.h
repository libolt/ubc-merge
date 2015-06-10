/***************************************************************************
 *   Copyright (C) 2015 by Mike McLean   *
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
 *9   GNU General Public License for more details.                          *
 *                                                                         *
 *   You should have received a copy of the GNU General Public License     *
 *   along with this program; if not, write to the                         *
 *   Free Software Foundation, Inc.,   0                                    *
 *   59 Temple Place - Suite 330, Boston, MA  02111-1307, USA.             *
 ***************************************************************************/

#ifndef _THREADING_H_0
#define _THREADING_H_
 
#include <vector>
#include <boost/thread/thread.hpp>
#include <boost/date_time.hpp>
#include <boost/thread/mutex.hpp>
#include <boost/thread/condition_variable.hpp>
#include <boost/thread/locks.hpp>

#include "logging.h"
 
const int globalVariable;

class Reader
{
  public:
    Reader(int waitTime) { _waitTime = waitTime;}
    void operator() () {
      for (int i=0; i < 10; i++) {
        std::cout << "Reader Api: " << globalVariable << std::endl;
 //       usleep(_waitTime);
        boost::this_thread::sleep(boost::posix_time::microseconds(_waitTime));
      }
      return;
    }
  private:
    int _waitTime;
};


class Writer
{
  public:
    Writer(int variable, int waitTime)
    {
      _writerVariable = variable;
      _waitTime = waitTime;
    }
    void operator () () {
      for (int i=0; i < 10; i++) {
//        usleep(_waitTime);
          boost::this_thread::sleep(boost::posix_time::microseconds(_waitTime));

          // Take lock and modify the global variable
        boost::mutex::scoped_lock lock(_writerMutex);
        globalVariable = _writerVariable;
        _writerVariable++;
        // since we have used scoped lock, 
        // it automatically unlocks on going out of scope
      }
    }
  private:
    int _writerVariable;
    int _waitTime;
    static boost::mutex _writerMutex;
};

//   static boost::mutex Writer::_writerMutex;

class threading
{
    public:
	    threading();
        void workerFunc();
        void workerFunc2();
        void inputWorkerFunc();  // handles input processing
	
        void producer();
        void consumer();
        
 
        
    private:
     
        boost::mutex mutex;
        boost::condition_variable condvar;
        typedef boost::unique_lock<boost::mutex> lockType;
        double value;
        int count;
 };
 

 
 #endif
