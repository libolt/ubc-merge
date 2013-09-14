//
// C++ Implementation: network
//
// Description:
//
//
// Author: Mike McLean <libolt@libolt.net>, (C) 2007
//
// Copyright: See COPYING file that comes with this distribution
//
//

#include "network.h"
#include "gameengine.h"

networkEngine::networkEngine()
{
    initialize();
    counter = 0;
    clientID = 0;
    clientEstablishedConnection = false;
    serverReceivedConnection = false;
    serverSetupComplete = false;
}

networkEngine::~networkEngine()
{
    enet_host_destroy(server);	// cleans up server
    enet_host_destroy(client);	// cleans up client

}

networkEngine* networkEngine::pInstance = 0;
networkEngine* networkEngine::Instance()
{
    if (pInstance == 0)  // is it the first call?
    {
        pInstance = new networkEngine; // create sole instance
    }
    return pInstance; // address of sole instance
}


int networkEngine::initialize()
{
    if (enet_initialize () != 0)
    {
        fprintf (stderr, "An error occurred while initializing ENet.\n");
        return EXIT_FAILURE;
    }
    atexit (enet_deinitialize);

}

void networkEngine::clientConnect()
{
    gameEngine *gameE = gameEngine::Instance();

    if (!clientEstablishedConnection)
    {

		client = enet_host_create (NULL /* create a client host */,
					4 /* only allow 1 outgoing connection */,
			2 /* allow up to 2 channels to be used, 0 and 1*/,
					0 /* 56K modem with 56 Kbps downstream bandwidth */,
					0 /* 56K modem with 14 Kbps upstream bandwidth */);

		if (client == NULL)
		{
			fprintf (stderr,
					 "An error occurred while trying to create an ENet client host.\n");
			exit (EXIT_FAILURE);
		}

// Old Pre-GUI ipAddress input code
//    string ipAddress;
//    cout << "IP Address: " << endl;
//    cin >> ipAddress;

		/* Connect to some.server.net:1234. */
		enet_address_set_host (& serverAddress, ipAddress.c_str());
		serverAddress.port = 1234;

		/* Initiate the connection, allocating the two channels 0 and 1. */
		peer = enet_host_connect (client, & serverAddress, 2, 0);

		if (peer == NULL)
		{
		   fprintf (stderr,
					"No available peers for initiating an ENet connection.\n");
		   exit (EXIT_FAILURE);
		}

		/* Wait up to 5 seconds for the connection attempt to succeed. */
		if (enet_host_service (client, & event, 5000) > 0 &&
			event.type == ENET_EVENT_TYPE_CONNECT)
		{
			cout << "Connection to " << ipAddress << ":1234 succeeded." << endl;
			clientEstablishedConnection = true; // Tells other code that this instance is a network client
		}
		else
		{
			/* Either the 5 seconds are up or a disconnect event was */
			/* received. Reset the peer in the event the 5 seconds   */
			/* had run out without any significant event.            */
			enet_peer_reset (peer);

			cout << "Connection to " << ipAddress << ":1234 failed." << endl;
		}
		gameE->setClientRunning(true);
		clientEstablishedConnection = true;
    }
}

void networkEngine::networkClient()
{
//    ENetPeer *peer;
    ENetPacket *packet2;
//    clientConnect();

// do something here
    int x = 1;
//    do
//   {

        // Wait up to 1000 milliseconds for an event.
//        ENetHost *client = network->getClient();
//	ENetEvent event; // = network->getEvent();
//	event = network->getEvent();

    // processes client event ever 0 seconds.
	while (enet_host_service (client, &event, 0) > 0)
	{
	}
		//while (enet_host_service (network->getClient(), & network->getEvent(), 1000) > 0)
//    {
      /*      switch (network->getEvent().type)
            {
            case ENET_EVENT_TYPE_CONNECT:
                printf("A new client connected from %x:%u.\n",
                        network->getEvent().peer -> address.host,
                        network->getEvent().peer -> address.port);

                // Store any relevant client information here.
         //       event.peer->data = "Client information";
                exit(0);
                break;

            case ENET_EVENT_TYPE_RECEIVE:
                printf ("A packet of length %u containing %s was received from %s on channel %u.\n",
                        network->getEvent().packet -> dataLength,
                        network->getEvent().packet -> data,
                        network->getEvent().peer -> data,
                        network->getEvent().channelID);

                // Clean up the packet now that we're done using it.
                enet_packet_destroy (network->getEvent().packet);
                exit(0);
                break;

            case ENET_EVENT_TYPE_DISCONNECT:
                printf ("%s disconected.\n", network->getEvent().peer -> data);

                // Reset the peer's client information.

                network->getEvent().peer -> data = NULL;
            }*/
 //       }
/*
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
//		const char *sendData = data[0].c_str();
        char *sendData;
        sendData = new char[50];
        sendData = "flapjackstackwacktack";
        cout << "sendData = " << sendData << endl;
        cout << "size of sendData = " << strlen(sendData) << endl;
*/
		Ogre::String dataTest = "data data";
        // Create a reliable packet of size 7 containing "packet\0"
 //       packet = enet_packet_create (sendData,strlen(sendData) + 1, ENET_PACKET_FLAG_RELIABLE);
        packet = enet_packet_create(dataTest.c_str(),strlen(dataTest.c_str())+1,ENET_PACKET_FLAG_RELIABLE);
        packet2 = enet_packet_create("test2",6,ENET_PACKET_FLAG_RELIABLE);
        // Extend the packet so and append the string "foo", so it now
        // contains "packetfoo\0"
//        enet_packet_resize (packet, strlen ("packetfoo") + 1);
//        strcpy (&packet->data [strlen ("packet")], "foo");

        /* Send the packet to the peer over channel id 0. */
        /* One could also broadcast the packet by         */
        /* enet_host_broadcast (host, 0, packet);         */
//        peer = network->getPeer();
        std::cout << "Sending packets to server." << std::endl;
        enet_peer_send (peer, 0, packet);
        enet_peer_send (peer, 0, packet2);
//	}
//    } while (x != 0);
//    enet_host_destroy(client);

}

void networkEngine::serverSetup()
{
    gameEngine *gameE = gameEngine::Instance();

/* Bind the server to the default localhost.     */
/* A specific host address can be specified by   */
/* enet_address_set_host (& address, "x.x.x.x"); */

// Old Pre-GUI ip address input code
//    string ipAddress;
//    cout << "IP Address to bind to:" << endl;
//    cin >> ipAddress;

	listenAddress.host = enet_address_set_host (& listenAddress, ipAddress.c_str());
	/* Bind the server to port 1234. */
	listenAddress.port = 1234;

	server = enet_host_create (& listenAddress /* the address to bind the server host to */,
								 32      /* allow up to 32 clients and/or outgoing connections */,
				 2	/* allows up to 2 channels, 0, 1*/,
								  0      /* assume any amount of incoming bandwidth */,
								  0      /* assume any amount of outgoing bandwidth */);
	if (server == NULL)
	{
		cerr << "An error occurred while trying to create an ENet server host." << endl;
		exit (EXIT_FAILURE);
	}

	gameE->setServerRunning(true);
}

void networkEngine::networkServer()
{
//	serverSetup();
    gameEngine *gameE = gameEngine::Instance();

    int x = 0;
//    do
//    {
        /* Wait up to 1000 milliseconds for an event. */
        while (enet_host_service (server, & event, 1) > 0)
        {
//        	exit(0);
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
//            	exit(0);
            	serverReceivedConnection = true;	// Tells code that a client has connected
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
                cout << "info = " << info[0] << endl;

                // test code to enable player movement based on network data
				if (info[0] == "up")
				{
					gameE->setMovePlayer(true);
				}
                enet_packet_destroy (event.packet);
                break;

            case ENET_EVENT_TYPE_DISCONNECT:
                printf ("%s disconected.\n", event.peer -> data);

                /* Reset the peer's client information. */
                event.peer -> data = NULL;
            }
            packet = enet_packet_create ("test",5, ENET_PACKET_FLAG_RELIABLE);
            cout << "Peer = " << peer << endl;
//            enet_peer_send (network->getPeer(), 0, packet);
//            peer = network->getPeer();
//            enet_peer_send(peer,0,packet);
//            exit(0);

        }

//    } while (x != 5);


//    enet_host_destroy(server);

}

void networkEngine::sendPacket(Ogre::String packetData)
{
	while (enet_host_service (client, &event, 0) > 0)
	{
	}
    packet = enet_packet_create(packetData.c_str(),strlen(packetData.c_str())+1,ENET_PACKET_FLAG_RELIABLE);
    enet_peer_send (peer, 0, packet);

}

bool networkEngine::getClientEstablishedConnection()
{
	return (clientEstablishedConnection);
}

void networkEngine::setClientEstablishedConnection(bool connection)
{
	clientEstablishedConnection = connection;
}

bool networkEngine::getServerReceivedConnection()
{
	return (serverReceivedConnection);
}

void networkEngine::setServerReceivedConnection(bool connection)
{
	serverReceivedConnection = connection;
}
int networkEngine::getClientID()
{
	return (clientID);
}

void networkEngine::setClientID(int ID)
{
	clientID = ID;
}

Ogre::String networkEngine::getIPAddress()	// returns ipAddress string
{
	return(ipAddress);
}

void networkEngine::setIPAddress(Ogre::String IP)	// sets ipAddress string
{
	ipAddress = IP;
}

ENetAddress networkEngine::getListenAddress()
{
    return (listenAddress);
}
void networkEngine::setListenAddress(ENetAddress address)
{
    listenAddress = address;
}

ENetAddress networkEngine::getServerAddress()
{
    return (serverAddress);
}

void networkEngine::setServerAddress(ENetAddress address)
{
    serverAddress = address;
}

ENetHost *networkEngine::getClient()
{
    return (client);
}
void networkEngine::setClient(ENetHost *Client)
{
    client = Client;
}

ENetEvent networkEngine::getEvent()
{
    return (event);
}
void networkEngine::setEvent(ENetEvent Event)
{
    event = Event;
}

ENetPeer *networkEngine::getPeer()
{
    return (peer);
}
void networkEngine::setPeer(ENetPeer *Peer)
{
    peer = Peer;
}

ENetHost *networkEngine::getServer()
{
    return (server);
}
void networkEngine::setServer(ENetHost *Server)
{
    server = Server;
}


struct ePacket
{
	int ID;
	string data;
};
