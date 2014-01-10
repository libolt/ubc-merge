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

#include "enet/enet.h"
#include <iostream>
#include <stdio.h>
#include <stdlib.h>

#include "OgreString.h"
#include "OgreStringConverter.h"
#include "Ogre.h"

using namespace std;

enum packetType { PLAYER, BALL, COURT };
enum packetData { MOVE, SHOOT, PASS };
//enum movementDirection { FORWARD, BACKWARD, LEFT, RIGHT };

class networkEngine
{
    public:

//    networkEngine();
    virtual ~networkEngine();
    virtual int initialize();	// initialize networkEngine code
    virtual void clientConnect();	// setup client connection.
    virtual void networkClient();	// Client code

    virtual void serverSetup();	// setup server.
    virtual void networkServer();	// Server code

    virtual bool getClientEstablishedConnection();					// returns clientEstablishedConnection variable
    virtual void setClientEstablishedConnection(bool connection);	// sets clientEstablishedConnection variable

    virtual bool getServerReceivedConnection();						// returns serverReceivedConnection variable
    virtual void setServerReceivedConnection(bool connection);		// sets serverReceivedConnection variable

    virtual bool getPacketReceived();								// returns packetReceived variable
    virtual void setPacketReceived(bool received);					// sets packetReceived variable

    virtual void sendPacket(Ogre::String packetData);	// sends a packet to the peer

    virtual int getClientID();	// returns the value of clientID variable;
    virtual void setClientID(int ID);  // sets the value of clientID variable;

    virtual Ogre::String getIPAddress();	// returns the value of the ipAddress string
    virtual void setIPAddress(Ogre::String IP);	// sets the value of the ipAddress string

    virtual Ogre::String getReceivedData();	// returns receivedData variable
    virtual void setReceivedData(Ogre::String data);

    virtual ENetAddress getListenAddress();	// returns listenAddress variable
    virtual void setListenAddress(ENetAddress address);	// sets listenAddress variable

    virtual ENetAddress getServerAddress();	// returns serverAddress variable
    virtual void setServerAddress(ENetAddress address);	// sets serverAddress variable

    virtual ENetHost *getClient();	//	returns client variable
    virtual void setClient(ENetHost *Client);	// sets client variable

    virtual ENetEvent getEvent();	// returns event variable
    virtual void setEvent(ENetEvent Event);	// sets event variable

    virtual ENetPeer *getPeer();	// returns peer variable
    virtual void setPeer(ENetPeer *Peer);	// sets peer variable

    virtual ENetHost *getServer();	// returns server variable
    virtual void setServer(ENetHost *Server);	// sets server variable

    static networkEngine *Instance();

    protected:
    networkEngine();
    networkEngine(const networkEngine&);
    networkEngine& operator= (const networkEngine&);

    private:

    int counter;
    static networkEngine *pInstance;

    int clientID;	// defines the client ID number used to identify which client is communicating with the server
    Ogre::String ipAddress; // stores IP Address used for either server or client code
    Ogre::String receivedData; // stores received packet data
    bool packetReceived;	// if set then a packet was received from remote connection

    // ENET related code
    ENetAddress listenAddress;
    ENetAddress serverAddress;
    ENetHost *client;
    ENetEvent event;
    ENetPeer *peer;
    ENetHost *server;
    ENetPacket *packet;

    bool serverSetupComplete;
    bool clientEstablishedConnection;	// stores whether or not a connection from client to server was successful
    bool serverReceivedConnection;		// stores whether or not server received a client connection.
};


#endif
