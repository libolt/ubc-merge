//
// C++ Interface: courts
//
// Description:
//
//
// Author: Mike McLean <libolt@libolt.net>, (C) 2006
//
// Copyright: See COPYING file that comes with this distribution
//
//

#ifndef _COURTS_H_
#define _COURTS_H_

#include <string>

class courtData
{
public:

    courtData();    // constructor
    virtual ~courtData();   // destructor

    // gets and sets modelName
    std::string getModelName();
    virtual void setModelName(std::string name);

protected:
private:

    std::string modelName;   // stores the file name of the court 3D model
};

#endif

