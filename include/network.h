/***************************************************************************
 *   Copyright (C) 2014 by Mike McLean   *
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

#include "enums.h"

using namespace std;

enum packetType { PLAYER, BALL, COURT };
enum packetData { MOVE, SHOOT, PASS };
//enum movementDirection { FORWARD, BACKWARD, LEFT, RIGHT };

class networkEngine
{
    public:

//    networkEngine();
    ~networkEngine();

    int getTeamNumber();  // returns the value of teamNumber
    void setTeamNumber(int set);  // sets the value of teamNumber
    
    bool getIsClient();	// returns the value of the isClient variable
    void setIsClient(bool client);	// sets the value of the isClient variable

    bool getIsServer();	// returns the value of the isServer variable
    void setIsServer(bool server);	// sets the value of the isServer variable

    bool getClientEstablishedConnection();					// returns clientEstablishedConnection variable
    void setClientEstablishedConnection(bool connection);	// sets clientEstablishedConnection variable

    bool getServerReceivedConnection();						// returns serverReceivedConnection variable
    void setServerReceivedConnection(bool connection);		// sets serverReceivedConnection variable

    bool getPacketReceived();								// returns packetReceived variable
    void setPacketReceived(bool received);					// sets packetReceived variable

    int getClientID();	// returns the value of clientID variable;
    void setClientID(int ID);  // sets the value of clientID variable;

    Ogre::String getIPAddress();	// returns the value of the ipAddress string
    void setIPAddress(Ogre::String IP);	// sets the value of the ipAddress string

    Ogre::String getReceivedData();	// returns receivedData variable
    void setReceivedData(Ogre::String data);

    ENetAddress getListenAddress();	// returns listenAddress variable
    void setListenAddress(ENetAddress address);	// sets listenAddress variable

    ENetAddress getServerAddress();	// returns serverAddress variable
    void setServerAddress(ENetAddress address);	// sets serverAddress variable

    ENetHost *getClient();	//	returns client variable
    void setClient(ENetHost *Client);	// sets client variable

    ENetEvent getEvent();	// returns event variable
    void setEvent(ENetEvent Event);	// sets event variable

    ENetPeer *getPeer();	// returns peer variable
    void setPeer(ENetPeer *Peer);	// sets peer variable

    ENetHost *getServer();	// returns server variable
    void setServer(ENetHost *Server);	// sets server variable

    int initialize();	// initialize networkEngine code
    void clientConnect();	// setup client connection.
    void networkClient();	// Client code

    void serverSetup();	// setup server.
    void networkServer();	// Server code

    void processLocalInput();  // processes local input for sending to remote system
    void processRemoteInput(); // processes input received from a remote system
    
    void sendPacket(Ogre::String packetData);	// sends a packet to the peer

    static networkEngine *Instance();

    protected:
    networkEngine();
    networkEngine(const networkEngine&);
    networkEngine& operator= (const networkEngine&);

    private:

    int counter;
    static networkEngine *pInstance;

    int clientID;	// defines the client ID number used to identify which client is communicating with the server
    std::string ipAddress; // stores IP Address used for either server or client code
    std::string receivedData; // stores received packet data
    bool packetReceived;	// if set then a packet was received from remote connection

    // ENET related code
    ENetAddress listenAddress;
    ENetAddress serverAddress;
    ENetHost *client;
    ENetEvent event;
    ENetPeer *peer;
    ENetHost *server;
    ENetPacket *packet;

    netGameTypes netGameType;   // stores what type of network game this instance is
    int teamNumber; // stores which team the network player is on
    // FiXME! deprecated in favor of netGameTypes
    bool isClient;	// stores whether or not this instance is the client
    bool isServer; // stores whethr or not this instance is the server

    bool serverSetupComplete;	// stores whether or not the server is setup and running
    bool clientEstablishedConnection;	// stores whether or not a connection from client to server was successful
    bool serverReceivedConnection;		// stores whether or not server received a client connection.
};


#endif
