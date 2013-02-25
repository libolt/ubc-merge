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

#ifndef _NETWORK_H_
#define _NETWORK_H_

#include <iostream>
#include <stdio.h>
#include <stdlib.h>
#include "enet/enet.h"
#include "OgreString.h"
#include "OgreStringConverter.h"
#include "Ogre.h"

using namespace std;

enum packetType { PLAYER, BALL, COURT };
enum packetData { MOVE, SHOOT, PASS };
enum movementDirection { FORWARD, BACKWARD, LEFT, RIGHT };

class networking
{
    public:

//    networking();
    virtual ~networking();
    virtual int initialize();
    virtual void clientConnect();
    virtual void serverSetup();


    virtual int getClientID();	// returns the value of clientID variable;
    virtual void setClientID(int ID);  // sets the value of clientID variable;

    virtual ENetAddress getListenAddress();
    virtual void setListenAddress(ENetAddress address);

    virtual ENetAddress getServerAddress();
    virtual void setServerAddress(ENetAddress address);

    virtual ENetHost *getClient();
    virtual void setClient(ENetHost *Client);

    virtual ENetEvent getEvent();
    virtual void setEvent(ENetEvent Event);

    virtual ENetPeer *getPeer();
    virtual void setPeer(ENetPeer *Peer);

    virtual ENetHost *getServer();
    virtual void setServer(ENetHost *Server);

    static networking *Instance();

    protected:
    networking();
    networking(const networking&);
    networking& operator= (const networking&);
    private:
    static networking *pInstance;

    int clientID;	// defines the client ID number used to identify which client is communicating with the server

    // ENET related code
    ENetAddress listenAddress;
    ENetAddress serverAddress;
    ENetHost *client;
    ENetEvent event;
    ENetPeer *peer;
    ENetHost *server;

};

networking::networking()
{
    initialize();
    clientID = 0;
}

networking::~networking()
{
}

networking* networking::pInstance = 0;
networking* networking::Instance()
{
    if (pInstance == 0)  // is it the first call?
    {
        pInstance = new networking; // create sole instance
    }
    return pInstance; // address of sole instance
}


int networking::initialize()
{
    if (enet_initialize () != 0)
    {
        fprintf (stderr, "An error occurred while initializing ENet.\n");
        return EXIT_FAILURE;
    }
    atexit (enet_deinitialize);

}

void networking::clientConnect()
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

    string ipAddress;
    cout << "IP Address: " << endl;
    cin >> ipAddress;
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
    }
    else
    {
        /* Either the 5 seconds are up or a disconnect event was */
        /* received. Reset the peer in the event the 5 seconds   */
        /* had run out without any significant event.            */
        enet_peer_reset (peer);

        cout << "Connection to " << ipAddress << ":1234 failed." << endl;
    }

}

void networking::serverSetup()
{
    /* Bind the server to the default localhost.     */
    /* A specific host address can be specified by   */
    /* enet_address_set_host (& address, "x.x.x.x"); */

    string ipAddress;
    cout << "IP Address to bind to:" << endl;
    cin >> ipAddress;
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
}

int networking::getClientID()
{
	return (clientID);
}

void networking::setClientID(int ID)
{
	clientID = ID;
}

ENetAddress networking::getListenAddress()
{
    return (listenAddress);
}
void networking::setListenAddress(ENetAddress address)
{
    listenAddress = address;
}

ENetAddress networking::getServerAddress()
{
    return (serverAddress);
}

void networking::setServerAddress(ENetAddress address)
{
    serverAddress = address;
}

ENetHost *networking::getClient()
{
    return (client);
}
void networking::setClient(ENetHost *Client)
{
    client = Client;
}

ENetEvent networking::getEvent()
{
    return (event);
}
void networking::setEvent(ENetEvent Event)
{
    event = Event;
}

ENetPeer *networking::getPeer()
{
    return (peer);
}
void networking::setPeer(ENetPeer *Peer)
{
    peer = Peer;
}

ENetHost *networking::getServer()
{
    return (server);
}
void networking::setServer(ENetHost *Server)
{
    server = Server;
}


struct ePacket
{
	int ID;
	string data;
};

#endif
