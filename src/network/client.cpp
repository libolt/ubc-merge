//
// C++ Implementation: client
//
// Description:
//
//
// Author:  <>, (C) 2007
//
// Copyright: See COPYING file that comes with this distribution
//
//
#include "tinyxml.h"
#include "network.h"

using namespace std;

int main(int argc, char *argv[])
{
    networkEngine *network = networkEngine::Instance();
    network->networkClient();	// loads network client code

    return (0);
}
