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
 *   GNU General Public License for more details.                          *
 *                                                                         *
 *   You should have received a copy of the GNU General Public License     *
 *   along with this program; if not, write to the                         *
 *   Free Software Foundation, Inc.,                                       *
 *   59 Temple Place - Suite 330, Boston, MA  02111-1307, USA.             *
 ***************************************************************************/

#include "threads.h"
#include "gameengine.h" 

threads* threads::pInstance = 0;
threads* threads::Instance()
{
    if (pInstance == 0)  // is it the first call?
    {
        pInstance = new threads; // create sole instance
    }
    return pInstance; // address of sole instance
}


boost::mutex threads::Writer::_writerMutex;
//-------------------------------------------------------------------------------------
threads::threads()
{
    value = 0;
    count = 0;
    globalVariable = 0;
    globalVariableProtector = new boost::mutex;
}
 
void threads::workerFunc()
{
    boost::posix_time::seconds workTime(3);

    logMsg("Worker: running");

    // Pretend to do something useful...
    boost::this_thread::sleep(workTime);

    logMsg("Worker: finished");
//	exit(0);
}

void threads::workerFunc2()
{
    boost::posix_time::seconds workTime(3);

    logMsg("Worker2: running");

    // Pretend to do something useful...
    boost::this_thread::sleep(workTime);

    logMsg("Worker2: finished");
//	exit(0);
}

void threads::inputWorkerFunc()  // handles input processing
{
    gameEngine *gameE = gameEngine::Instance();
    
    logMsg("inputWorker!");
    gameE->processInput();
}

void threads::producer()
{
    while (true)
    {
        {
            // value and counter must both be updated atomically
            // using a mutex lock
            lockType lock(mutex);
            value = std::rand();
            ++count;

            // Notify the consumer that a new value is ready.
            condvar.notify_one();
        }

        // Simulate exaggerated 2ms delay
        boost::this_thread::sleep(boost::posix_time::milliseconds(200));
    }
}

void threads::consumer()
{
    // Local copies of 'count' and 'value' variables. We want to do the
    // work using local copies so that they don't get clobbered by
    // the producer when it updates.
    int currentCount = 0;
    double currentValue = 0;

    while (true)
    {
        {
            // Acquire the mutex before accessing 'count' and 'value' variables.
            lockType lock(mutex); // mutex is locked while in this scope
            while (count == currentCount)
            {
                // Wait for producer to signal that there is a new value.
                // While we are waiting, Boost releases the mutex so that
                // other threads may acquire it.
                condvar.wait(lock);
            }

            // `lock` is automatically re-acquired when we come out of
            // condvar.wait(lock). So it's safe to access the 'value'
            // variable at this point.
            currentValue = value; // Grab a copy of the latest value
                                  // while we hold the lock.
        }

        // Now that we are out of the mutex lock scope, we work with our
        // local copy of `value`. The producer can keep on clobbering the
        // 'value' variable all it wants, but it won't affect us here
        // because we are now using `currentValue`.
        std::cout << "value = " << currentValue << "\n";

        // Simulate exaggerated 5ms delay
        boost::this_thread::sleep(boost::posix_time::milliseconds(500));
    }
}
