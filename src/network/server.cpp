
#ifdef HAVE_CONFIG_H
#include <config.h>
#endif

#if _MSC_VER
#define snprintf _snprintf
#endif

#include <cstdio>
#include "network.h"

using namespace std;

int main(int argc, char *argv[])
{
    networkEngine *network = networkEngine::Instance();
//    ENetPeer *peer;
//    ENetEvent event;
//    ENetPacket *packet;
//	event = network->getEvent();

	network->networkServer();	// loads server code




  return EXIT_SUCCESS;
}
