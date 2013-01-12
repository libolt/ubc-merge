
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
    networking *network = networking::Instance();
    ENetPeer *peer;
    ENetEvent event;
    ENetPacket *packet;
	event = network->getEvent();

	network->serverSetup();

    int x = 0;
    do
    {
        /* Wait up to 1000 milliseconds for an event. */
        while (enet_host_service (network->getServer(), & event, 1000) > 0)
        {
			std::cout << "EVENT == " << event.type << std::endl;
            switch (event.type)
            {
            case ENET_EVENT_TYPE_CONNECT:

/*                cout << "A new client connected from %x:%u." <<
                        event.peer -> address.host <<
                        event.peer -> address.port << endl;
                cout << event.peer->address.host << endl;
*/
            	printf("A new client connected from %x:%u.",
            			event.peer -> address.host,
            			event.peer -> address.port);
            	/* Store any relevant client information here. */
//                event.peer->data = "Client information";
                break;

            case ENET_EVENT_TYPE_RECEIVE:
                printf ("A packet of length %u containing %s was received from %s on channel %u.\n",
                        event.packet -> dataLength,
                        event.packet -> data,
                        event.peer -> data,
                        event.channelID);

				cout << "event.packet->data = " << event.packet->data << endl;
				Ogre::String *info;
				info = new Ogre::String;
//				info[0] = Ogre::StringConverter::toString(event.packet->data);
//				info[0].assign(event.packet->data);
				char *data, *deta;

				data = new char[event.packet->dataLength + 1];
				cout << "size of data = " << sizeof(event.packet->data) << endl;
				cout << "size of data packet = " << event.packet->dataLength << endl;
//				sprintf_s(data, event.packet->dataLength + 1,"%s", event.packet->data);
				snprintf(data,event.packet->dataLength + 1, "%s", event.packet->data);
//				string data;
//				strcpy(event.packet->data,data.c_str());
				info[0] = data;
				string *receiveData;
				receiveData = new string;
				receiveData[0] = info[0];
				cout << "data = " << data << endl;
				cout << "receiveData = " << receiveData[0] << endl;
//				cout << "DAMN = " << Ogre::StringConverter::parseInt(damn[0]) << endl;
//				cout << "DAMN = " << Ogre::StringConverter::isNumber(damn[0]) << endl;
				packetType pType;
				packetData pData;
				movementDirection mDirection;
				//pType = Ogre::StringConverter::parseInt(damn[0]);
//				cout << "atoi = " <<  Ogre::StringConverter::parseInt(damn[0]) << endl;

				string *Type;
				Type = new string;
				string *Data;
				Data = new string;
				string *Direction;
				Direction = new string;
				Type[0] = receiveData[0][0];
				Data[0] = receiveData[0][1];
				Direction[0] = receiveData[0][2];
				cout << "Type[0] = " << Type[0] << endl;
				cout << "Data[0]" << Data[0] << endl;
				cout << "Direction[0]" << Direction[0] << endl;
				pType = static_cast<packetType>(Ogre::StringConverter::parseInt(Type[0]));
				pData = static_cast<packetData>(Ogre::StringConverter::parseInt(Data[0]));
				mDirection = static_cast<movementDirection>(Ogre::StringConverter::parseInt(Direction[0]));

				cout << "Packet Type = " << pType << endl;
				cout << "Packet Data = " << pData << endl;
				cout << "Movement Direction = " << mDirection << endl;

//	 			ePacket *pack = new ePacket;(
//				pack[0] = event.packet->data;
                /* Clean up the packet now that we're done using it. */
                cout << "Peer = " << event.peer->incomingPeerID << endl;
//                exit(0);

				enet_packet_destroy (event.packet);
                break;

            case ENET_EVENT_TYPE_DISCONNECT:
                printf ("%s disconected.\n", event.peer -> data);

                /* Reset the peer's client information. */
                event.peer -> data = NULL;
            }
            packet = enet_packet_create ("test",5, ENET_PACKET_FLAG_RELIABLE);
            cout << "Peer = " << network->getPeer() << endl;
//            enet_peer_send (network->getPeer(), 0, packet);
            peer = network->getPeer();
//            enet_peer_send(peer,0,packet);
//            exit(0);

        }

    } while (x != 5);


    enet_host_destroy(network->getServer());



  return EXIT_SUCCESS;
}
