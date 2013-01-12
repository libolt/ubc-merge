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
    networking *network = networking::Instance();

    network->clientConnect();

// do something here
    int x = 1;
    do
    {

        /* Wait up to 1000 milliseconds for an event. */
        while (enet_host_service (network->getClient(), & network->getEvent(), 1000) > 0)
        {
            switch (network->getEvent().type)
            {
            case ENET_EVENT_TYPE_CONNECT:
                printf("A new client connected from %x:%u.\n",
                        network->getEvent().peer -> address.host,
                        network->getEvent().peer -> address.port);

                /* Store any relevant client information here. */
         //       event.peer->data = "Client information";
                break;

            case ENET_EVENT_TYPE_RECEIVE:
                printf ("A packet of length %u containing %s was received from %s on channel %u.\n",
                        network->getEvent().packet -> dataLength,
                        network->getEvent().packet -> data,
                        network->getEvent().peer -> data,
                        network->getEvent().channelID);

                /* Clean up the packet now that we're done using it. */
                enet_packet_destroy (network->getEvent().packet);

                break;

            case ENET_EVENT_TYPE_DISCONNECT:
                printf ("%s disconected.\n", network->getEvent().peer -> data);

                /* Reset the peer's client information. */

                network->getEvent().peer -> data = NULL;
            }
        }

        float *y = new float[1];
        y[0] = 20;
		packetType pType;
		packetData pData;
		movementDirection mDirection;
		pType = PLAYER;
		pData = MOVE;
		mDirection = RIGHT;
        int clientID = network->getClientID();
		string *data = new string;
		cout << "pType is " << pType << endl;
		data[0] = Ogre::StringConverter::toString(pType);
		cout << "pType = " << data[0] << endl;
		data[0] += Ogre::StringConverter::toString(pData);

		data[0] += Ogre::StringConverter::toString(mDirection);
//		data[0] = Ogre::StringConverter::toString("003\0");
        data[0] = "003";
        if (clientID == 0)
        {
            data[0] = "newIDdah";
        }
		const char *sendData = data[0].c_str();
		cout << "sendData = " << sendData << endl;
        /* Create a reliable packet of size 7 containing "packet\0" */
        ENetPacket * packet = enet_packet_create (sendData, sizeof(sendData) + 1, ENET_PACKET_FLAG_RELIABLE);

        /* Extend the packet so and append the string "foo", so it now */
        /* contains "packetfoo\0"                                      */
//        enet_packet_resize (packet, strlen ("packetfoo") + 1);
//        strcpy (&packet->data [strlen ("packet")], "foo");

        /* Send the packet to the peer over channel id 0. */
        /* One could also broadcast the packet by         */
        /* enet_host_broadcast (host, 0, packet);         */
        enet_peer_send (network->getPeer(), 0, packet);

    } while (x != 0);
    enet_host_destroy(network->getClient());


    return (0);
}
