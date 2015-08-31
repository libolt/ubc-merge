/***************************************************************************
 *   Copyright (C) 1999 - 2015 by Mike McLean   *
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

#include "conversion.h"

//conversion* conversion::pInstance = 0;
boost::shared_ptr<conversion> conversion::pInstance;

//conversion* conversion::Instance()
boost::shared_ptr<conversion> conversion::Instance()
{
    if (pInstance == 0)  // is it the first call?
    {
//        pInstance = new conversion; // create sole instance
        boost::shared_ptr<conversion> tInstance(new conversion);
        pInstance = tInstance;
    }
    return pInstance; // returns the value of pInstance
}

// inputSystem constructor
conversion::conversion()
{
    
}

/*conversion::~conversion()
{
}*/

// conversion to std::string
std::string conversion::toString(char *data)  // converts char * data to string
{
    std::string strData;
    strData = boost::lexical_cast<std::string>(data);
    return (strData);
}
/*std::string conversion::toString(char **data)  // converts char ** data to string
{
    std::string strData;
    strData = boost::lexical_cast<std::string>(data);
    return (strData);
}*/
std::string conversion::toString(const char *data)  // converts const char * data to string
{
    std::string strData;
//    strData = boost::lexical_cast<std::string>(data);
    return (strData);
}
std::string conversion::toString(int data)  // converts int data to string
{
    std::string strData;
    strData = boost::lexical_cast<std::string>(data);
    return (strData);
}
std::string conversion::toString(enet_uint8 *data)  // converts enet_uint8 data to string
{
    std::string strData;
    strData = boost::lexical_cast<std::string>(data);
    return (strData);
}
std::string conversion::toString(long data)  // converts long data to string
{
    std::string strData;
    strData = boost::lexical_cast<std::string>(data);
    return (strData);
}
std::string conversion::toString(unsigned int data)  // converts unsigned int data to string
{
    std::string strData;
    strData = boost::lexical_cast<std::string>(data);
    return (strData);
}

std::string conversion::toString(unsigned long data)  // converts unsigned long data to string
{
    std::string strData;
    strData = boost::lexical_cast<std::string>(data);
    return (strData);
}
std::string conversion::toString(float data)  // converts float data to string
{
    std::string strData;
    strData = boost::lexical_cast<std::string>(data);
    return (strData);
}
std::string conversion::toString(double data)  // converts double data to string
{
    std::string strData;
    strData = boost::lexical_cast<std::string>(data);
    return (strData);
}
/*std::string conversion::toString(size_t data)  // converts size_t data to string
{
    std::string strData;
    strData = boost::lexical_cast<std::string>(data);
    return (strData);
}*/
std::string conversion::toString(Ogre::Vector3 data)  // converts Ogre::Vector3 data to string
{
    std::string strData;
    strData = "OgreVector3(" +boost::lexical_cast<std::string>(data.x) +"," +boost::lexical_cast<std::string>(data.y) +"," + boost::lexical_cast<std::string>(data.z) +")";
    return(strData);
}
std::string conversion::toString(Ogre::Vector3 data)  // converts Ogre::Vector3 data to string
{
    std::string strData;
    strData = "OgreVector3(" +boost::lexical_cast<std::string>(data.x) +"," +boost::lexical_cast<std::string>(data.y) +"," + boost::lexical_cast<std::string>(data.z) +")";
    return(strData);
}
std::string conversion::toString(void *data)  // converts void * data to string
{
    std::string strData;
    return(strData);
}
std::string conversion::toString(playerPositions data) // converts playerPositions data to string
{
    std::string strData;
    switch (data)
    {
        case NONE:
            strData = "NONE";
        break;
        case PG:
            strData = "PG";
        break;
        case SG:
            strData = "SG";
        break;
        case SF:
            strData = "SF";
        break;
        case PF:
            strData = "PF";
        break;
        case C:
            strData = "C";
        break;
        default:
            strData = "";
        break;
    }
    
    return(strData);
}
// convert to char
char conversion::toChar(std::string data)  // converts from std::string to char
{
    char charData;
    charData = boost::lexical_cast<char>(data);
    return (charData);
}
char conversion::toChar(char *data)  // converts from char * to char
{
    char charData;
    charData = boost::lexical_cast<char>(data);
    return (charData);
}
/*char conversion::toChar(char **data)  // converts from char ** to char
{
    char charData;
    charData = boost::lexical_cast<char>(data);
    return (charData);
}*/
/*char conversion::toChar(const char *data)  // converts from const char * to char
{
    char charData;
//    charData = boost::lexical_cast<char>(data);
    return (charData);
}*/
char conversion::toChar(int data)  // converts from int to char
{
    char charData;
    charData = boost::lexical_cast<char>(data);
    return (charData);
}
char conversion::toChar(long data)  // converts from long to char
{
    char charData;
    charData = boost::lexical_cast<char>(data);
    return (charData);
}
char conversion::toChar(unsigned int data)  // converts from unsigned int to char
{
    char charData;
    charData = boost::lexical_cast<char>(data);
    return (charData);
}
char conversion::toChar(unsigned long data)  // converts from unsigned long to char
{
    char charData;
    charData = boost::lexical_cast<char>(data);
    return (charData);
}
char conversion::toChar(enet_uint8 *data)  // converts from enet_uint8 * to char
{
    char charData;
    charData = boost::lexical_cast<char>(data);
    return (charData);
}
char conversion::toChar(float data)  // converts from float to char
{
    char charData;
    charData = boost::lexical_cast<char>(data);
    return (charData);
}
char conversion::toChar(double data)  // converts from double to char
{
    char charData;
    charData = boost::lexical_cast<char>(data);
    return (charData);
}
/*char conversion::toChar(size_t data)  // converts from size_t to char
{
    char charData;
    charData = boost::lexical_cast<char>(data);
    return (charData);
}*/
char conversion::toChar(void *data)  // converts from void * to char
{
    char charData;
    charData = boost::lexical_cast<char>(data);
    return (charData);
}

// convert to char *
/*char *conversion::toCharPtr(std::string data)  // converts from std::string to char *
{
    char *charPtrData;
    charPtrData = boost::lexical_cast<char *>(data);
    return (charPtrData);
}
char *conversion::toCharPtr(char data)  // converts from char to char *
{
    char *charPtrData;
    charPtrData = boost::lexical_cast<char *>(data);
    return (charPtrData);
}
char *conversion::toCharPtr(char **data)  // converts from char ** to char *
{
    char *charPtrData;
    charPtrData = boost::lexical_cast<char *>(data);
    return (charPtrData);
}
char *conversion::toCharPtr(const char *data)  // converts from const char * to char *
{
    char *charPtrData;
//    charPtrData = boost::lexical_cast<char *>(data);
    return (charPtrData);
}
char *conversion::toCharPtr(int data)  // converts from int to char *
{
    char *charPtrData;
    charPtrData = boost::lexical_cast<char *>(data);
    return (charPtrData);
}
char *conversion::toCharPtr(long data)  // converts from long to char *
{
    char *charPtrData;
    charPtrData = boost::lexical_cast<char *>(data);
    return (charPtrData);
}
char *conversion::toCharPtr(unsigned long data)  // converts from unsigned long to char *
{
    char *charPtrData;
    charPtrData = boost::lexical_cast<char *>(data);
    return (charPtrData);
}
char *conversion::toCharPtr(enet_uint8 *data)  // converts from enet_uint8 * to char *
{
    char *charPtrData;
    charPtrData = boost::lexical_cast<char *>(data);
    return (charPtrData);
}
char *conversion::toCharPtr(float data)  // converts from float to char *
{
    char *charPtrData;
    charPtrData = boost::lexical_cast<char *>(data);
    return (charPtrData);
}
char *conversion::toCharPtr(double data)  // converts from double to char *
{
    char *charPtrData;
    charPtrData = boost::lexical_cast<char *>(data);
    return (charPtrData);
}
char *conversion::toCharPtr(size_t data)  // converts from size_t to char *
{
    char *charPtrData;
    charPtrData = boost::lexical_cast<char *>(data);
    return (charPtrData);
}
char *conversion::toCharPtr(void *data)  // converts from void * to char *
{
    char *charPtrData;
    charPtrData = boost::lexical_cast<char *>(data);
    return (charPtrData);
}*/

// convert to char **
/*char **conversion::toCharPtrPtr(std::string data)  // converts from std::string to char **
{
    char **charPtrPtrData;
    charPtrPtrData = boost::lexical_cast<char **>(data);
    return (charPtrPtrData);
}
char **conversion::toCharPtrPtr(char data)  // converts from char to char **
{
    char **charPtrPtrData;
    charPtrPtrData = boost::lexical_cast<char **>(data);
    return (charPtrPtrData);
}
char **conversion::toCharPtrPtr(char *data)  // converts from char * to char **
{
    char **charPtrPtrData;
    charPtrPtrData = boost::lexical_cast<char **>(data);
    return (charPtrPtrData);
}
char **conversion::toCharPtrPtr(const char *data)  // converts from const char * to char **
{
    char **charPtrPtrData;
    charPtrPtrData = boost::lexical_cast<char **>(data);
    return (charPtrPtrData);
}
char **conversion::toCharPtrPtr(int data)  // converts from int to char **
{
    char **charPtrPtrData;
    charPtrPtrData = boost::lexical_cast<char **>(data);
    return (charPtrPtrData);
}
char **conversion::toCharPtrPtr(long data)  // converts from long to char **
{
    char **charPtrPtrData;
    charPtrPtrData = boost::lexical_cast<char **>(data);
    return (charPtrPtrData);
}
char **conversion::toCharPtrPtr(unsigned long data)  // converts from unsigned long to char **
{
    char **charPtrPtrData;
    charPtrPtrData = boost::lexical_cast<char **>(data);
    return (charPtrPtrData);
}
char **conversion::toCharPtrPtr(enet_uint8 *data)  // converts from enet_uint8 * to char **
{
    char **charPtrPtrData;
    charPtrPtrData = boost::lexical_cast<char **>(data);
    return (charPtrPtrData);
}
char **conversion::toCharPtrPtr(float data)  // converts from float to char **
{
    char **charPtrPtrData;
    charPtrPtrData = boost::lexical_cast<char **>(data);
    return (charPtrPtrData);
}
char **conversion::toCharPtrPtr(double data)  // converts from double to char **
{
    char **charPtrPtrData;
    charPtrPtrData = boost::lexical_cast<char **>(data);
    return (charPtrPtrData);
}
char **conversion::toCharPtrPtr(size_t data)  // converts from size_t to char **
{
    char **charPtrPtrData;
    charPtrPtrData = boost::lexical_cast<char **>(data);
    return (charPtrPtrData);
}
char **conversion::toCharPtrPtr(void *data)  // converts from void * to char **
{
    char **charPtrPtrData;
    charPtrPtrData = boost::lexical_cast<char **>(data);
    return (charPtrPtrData);
}
*/

// convert to const char *
/*const char *conversion::toConstCharPtr(std::string data)  // converts from std::string to const char *
{
    const char *constCharPtrData;
    constCharPtrData = boost::lexical_cast<const char *>(data);
    return (constCharPtrData);
}
const char *conversion::toConstCharPtr(char data)  // converts from char to const char *
{
    const char *constCharPtrData;
    constCharPtrData = boost::lexical_cast<const char *>(data);
    return (constCharPtrData);
}
const char *conversion::toConstCharPtr(char *data)  // converts from char * to const char *
{
    const char *constCharPtrData;
    constCharPtrData = boost::lexical_cast<const char *>(data);
    return (constCharPtrData);
}
const char *conversion::toConstCharPtr(char **data)  // converts from char ** to const char *
{
    const char *constCharPtrData;
    constCharPtrData = boost::lexical_cast<const char *>(data);
    return (constCharPtrData);
}
const char *conversion::toConstCharPtr(int data)  // converts from int to const char *
{
    const char *constCharPtrData;
    constCharPtrData = boost::lexical_cast<const char *>(data);
    return (constCharPtrData);
}
const char *conversion::toConstCharPtr(long data)  // converts from long to const char *
{
    const char *constCharPtrData;
    constCharPtrData = boost::lexical_cast<const char *>(data);
    return (constCharPtrData);
}
const char *conversion::toConstCharPtr(unsigned long data)  // converts from unsigned long to const char *
{
    const char *constCharPtrData;
    constCharPtrData = boost::lexical_cast<const char *>(data);
    return (constCharPtrData);
}
const char *conversion::toConstCharPtr(enet_uint8 *data)  // converts from enet_uint8 * to const char *
{
    const char *constCharPtrData;
    constCharPtrData = boost::lexical_cast<const char *>(data);
    return (constCharPtrData);
}
const char *conversion::toConstCharPtr(float data)  // converts from float to const char *
{
    const char *constCharPtrData;
    constCharPtrData = boost::lexical_cast<const char *>(data);
    return (constCharPtrData);
}
const char *conversion::toConstCharPtr(double data)  // converts from double to const char *
{
    const char *constCharPtrData;
    constCharPtrData = boost::lexical_cast<const char *>(data);
    return (constCharPtrData);
}
const char *conversion::toConstCharPtr(size_t data)  // converts from size_t to const char *
{
    const char *constCharPtrData;
    constCharPtrData = boost::lexical_cast<const char *>(data);
    return (constCharPtrData);
}
const char *conversion::toConstCharPtr(void *data)  // converts from void * to const char *
{
    const char *constCharPtrData;
    constCharPtrData = boost::lexical_cast<const char *>(data);
    return (constCharPtrData);
}*/

// convert to int
int conversion::toInt(std::string data)  // converts from std::string to int
{
    int intData;
    intData = boost::lexical_cast<int>(data);
    return (intData);
}
int conversion::toInt(char data)  // converts from char to int
{
    int intData;
    intData = boost::lexical_cast<int>(data);
    return (intData);
}
int conversion::toInt(char *data)  // converts from char * to int
{
    int intData;
    intData = boost::lexical_cast<int>(data);
    return (intData);
}
/*int conversion::toInt(char **data)  // converts from char ** to int
{
    int intData;
    intData = boost::lexical_cast<int>(data);
    return (intData);
}*/
/*int conversion::toInt(const char *data)  // converts from const char * to int
{
    int intData;
//    intData = boost::lexical_cast<int>(data);
    return (intData);
}*/
int conversion::toInt(long data)  // converts from long to int
{
    int intData;
    intData = boost::lexical_cast<int>(data);
    return (intData);
}
int conversion::toInt(unsigned int data)  // converts from unsigned int to int
{
    int intData;
    intData = boost::lexical_cast<int>(data);
    return (intData);
}
int conversion::toInt(unsigned long data)  // converts from unsigned long to int
{
    int intData;
    intData = boost::lexical_cast<int>(data);
    return (intData);
}
int conversion::toInt(enet_uint8 *data)  // converts from enet_uint8 * to int
{
    int intData;
    intData = boost::lexical_cast<int>(data);
    return (intData);
}
int conversion::toInt(float data)  // converts from float to int
{
    int intData;
    intData = boost::lexical_cast<int>(data);
    return (intData);
}
int conversion::toInt(double data)  // converts from double to int
{
    int intData;
    intData = boost::lexical_cast<int>(data);
    return (intData);
}
/*int conversion::toInt(size_t data)  // converts from size_t to int
{
    int intData;
    intData = boost::lexical_cast<int>(data);
    return (intData);
}*/
int conversion::toInt(void *data)  // converts from void * to int
{
    int intData;
    intData = boost::lexical_cast<int>(data);
    return (intData);
}

// convert to long
long toLong(std::string data)  // converts from std::string to long
{
    long longData;
    longData = boost::lexical_cast<long>(data);
    return (longData);
}
long toLong(char data)  // converts from char to long
{
    long longData;
    longData = boost::lexical_cast<long>(data);
    return (longData);
}
long toLong(char *data)  // converts from char * to long
{
    long longData;
    longData = boost::lexical_cast<long>(data);
    return (longData);
}
/*long toLong(char **data)  // converts from char ** to long
{
    long longData;
    longData = boost::lexical_cast<long>(data);
    return (longData);
}*/
/*long toLong(const char *data)  // converts from const char * to long
{
    long longData;
//    longData = boost::lexical_cast<long>(data);
    return (longData);
}*/
long toLong(int data)  // converts from int to long
{
    long longData;
    longData = boost::lexical_cast<long>(data);
    return (longData);
}
long toLong(unsigned int data)  // converts from unsigned int to long
{
    long longData;
    longData = boost::lexical_cast<long>(data);
    return (longData);
}
long toLong(unsigned long data)  // converts from unsigned long to long
{
    long longData;
    longData = boost::lexical_cast<long>(data);
    return (longData);
}
long toLong(enet_uint8 *data)  // converts from enet_uint8 * to long
{
    long longData;
    longData = boost::lexical_cast<long>(data);
    return (longData);
}
long toLong(float data)  // converts from float to long
{
    long longData;
    longData = boost::lexical_cast<long>(data);
    return (longData);
}
long toLong(double data)  // converts from double to long
{
    long longData;
    longData = boost::lexical_cast<long>(data);
    return (longData);
}
/*long toLong(size_t data)  // converts from size_t to long
{
    long longData;
    longData = boost::lexical_cast<long>(data);
    return (longData);
}*/
long toLong(void *data)  // converts from void * to long
{
    long longData;
    longData = boost::lexical_cast<long>(data);
    return (longData);
}

// convert to unsigned int
unsigned int toUnsignedInt(std::string data)  // converts from std::string to unsigned int
{
    unsigned int unsignedIntData;
    unsignedIntData = boost::lexical_cast<unsigned int>(data);
    return (unsignedIntData);
}
unsigned int toUnsignedInt(char data)  // converts from char to unsigned int
{
    unsigned int unsignedIntData;
    unsignedIntData = boost::lexical_cast<unsigned long>(data);
    return (unsignedIntData);
}
unsigned long toUnsignedInt(char *data)  // converts from char * to unsigned int
{
    unsigned int unsignedIntData;
    unsignedIntData = boost::lexical_cast<unsigned long>(data);
    return (unsignedIntData);
}
/*unsigned int toUnsignedInt(char **data)  // converts from char ** to unsigned int
{
    unsigned int unsignedIntData;
    unsignedIntData = boost::lexical_cast<unsigned long>(data);
    return (unsignedIntData);
}*/
/*unsigned int toUnsignedInt(const char *data)  // converts from const char * to unsigned int
{
    unsigned int unsignedIntData;
//    unsignedIntData = boost::lexical_cast<unsigned long>(data);
    return (unsignedIntData);
}*/
unsigned int toUnsignedInt(long data)  // converts from long to unsigned int
{
    unsigned int unsignedIntData;
    unsignedIntData = boost::lexical_cast<unsigned long>(data);
    return (unsignedIntData);
}
unsigned int toUnsignedInt(int data)  // converts from int to unsigned int
{
    unsigned int unsignedIntData;
    unsignedIntData = boost::lexical_cast<unsigned long>(data);
    return (unsignedIntData);
}
unsigned int toUnsignedInt(unsigned int data)  // converts from unsigned int to unsigned int
{
    unsigned int unsignedIntData;
    unsignedIntData = boost::lexical_cast<unsigned long>(data);
    return (unsignedIntData);
}

unsigned int toUnsignedInt(enet_uint8 *data)  // converts from enet_uint8 * to unsigned int
{
    unsigned int unsignedIntData;
    unsignedIntData = boost::lexical_cast<unsigned long>(data);
    return (unsignedIntData);
}
unsigned int toUnsignedInt(float data)  // converts from float to unsigned int
{
    unsigned int unsignedIntData;
    unsignedIntData = boost::lexical_cast<unsigned long>(data);
    return (unsignedIntData);
}
unsigned int toUnsignedInt(double data)  // converts from double to unsigned int
{
    unsigned int unsignedIntData;
    unsignedIntData = boost::lexical_cast<unsigned long>(data);
    return (unsignedIntData);
}
/*unsigned int toUnsignedInt(size_t data)  // converts from size_t to unsigned int
{
    unsigned int unsignedIntData;
    unsignedIntData = boost::lexical_cast<unsigned long>(data);
    return (unsignedIntData);
}*/
unsigned int toUnsignedInt(void *data)  // converts from void * to unsigned int
{
    unsigned int unsignedIntData;
    unsignedIntData = boost::lexical_cast<unsigned long>(data);
    return (unsignedIntData);
}

// convert to unsigned long
unsigned long toUnsignedLong(std::string data)  // converts from std::string to unsigned long
{
    unsigned long unsignedLongData;
    unsignedLongData = boost::lexical_cast<unsigned long>(data);
    return (unsignedLongData);
}
unsigned long toUnsignedLong(char data)  // converts from char to unsigned long
{
    unsigned long unsignedLongData;
    unsignedLongData = boost::lexical_cast<unsigned long>(data);
    return (unsignedLongData);
}
unsigned long toUnsignedLong(char *data)  // converts from char * to unsigned long
{
    unsigned long unsignedLongData;
    unsignedLongData = boost::lexical_cast<unsigned long>(data);
    return (unsignedLongData);
}
/*unsigned long toUnsignedLong(char **data)  // converts from char ** to unsigned long
{
    unsigned long unsignedLongData;
    unsignedLongData = boost::lexical_cast<unsigned long>(data);
    return (unsignedLongData);
}*/
/*unsigned long toUnsignedLong(const char *data)  // converts from const char * to unsigned long
{
    unsigned long unsignedLongData;
//    unsignedLongData = boost::lexical_cast<unsigned long>(data);
    return (unsignedLongData);
}*/
unsigned long toUnsignedLong(long data)  // converts from long to unsigned long
{
    unsigned long unsignedLongData;
    unsignedLongData = boost::lexical_cast<unsigned long>(data);
    return (unsignedLongData);
}
unsigned long toUnsignedLong(int data)  // converts from int to unsigned long
{
    unsigned long unsignedLongData;
    unsignedLongData = boost::lexical_cast<unsigned long>(data);
    return (unsignedLongData);
}
unsigned long toUnsignedLong(unsigned int data)  // converts from unsigned int to unsigned long
{
    unsigned long unsignedLongData;
    unsignedLongData = boost::lexical_cast<unsigned long>(data);
    return (unsignedLongData);
}

unsigned long toUnsignedLong(enet_uint8 *data)  // converts from enet_uint8 * to unsigned long
{
    unsigned long unsignedLongData;
    unsignedLongData = boost::lexical_cast<unsigned long>(data);
    return (unsignedLongData);
}
unsigned long toUnsignedLong(float data)  // converts from float to unsigned long
{
    unsigned long unsignedLongData;
    unsignedLongData = boost::lexical_cast<unsigned long>(data);
    return (unsignedLongData);
}
unsigned long toUnsignedLong(double data)  // converts from double to unsigned long
{
    unsigned long unsignedLongData;
    unsignedLongData = boost::lexical_cast<unsigned long>(data);
    return (unsignedLongData);
}
/*unsigned long toUnsignedLong(size_t data)  // converts from size_t to unsigned long
{
    unsigned long unsignedLongData;
    unsignedLongData = boost::lexical_cast<unsigned long>(data);
    return (unsignedLongData);
}*/
unsigned long toUnsignedLong(void *data)  // converts from void * to unsigned long
{
    unsigned long unsignedLongData;
    unsignedLongData = boost::lexical_cast<unsigned long>(data);
    return (unsignedLongData);
}

// convert to float
float conversion::toFloat(std::string data)  // converts from std::string to float
{
    float floatData;
    floatData = boost::lexical_cast<float>(data);
    return (floatData);
}
float conversion::toFloat(char data)  // converts from char to float
{
    float floatData;
    floatData = boost::lexical_cast<float>(data);
    return (floatData);
}
float conversion::toFloat(char *data)  // converts from char * to float
{
    float floatData;
    floatData = boost::lexical_cast<float>(data);
    return (floatData);
}
/*float conversion::toFloat(char **data)  // converts from char ** to float
{
    float floatData;
    floatData = boost::lexical_cast<float>(data);
    return (floatData);
}*/
/*float conversion::toFloat(const char *data)  // converts from const char * to float
{
    float floatData;
//    floatData = boost::lexical_cast<float>(data);
    return (floatData);
}*/
float conversion::toFloat(int data)  // converts from int to float
{
    float floatData;
    floatData = boost::lexical_cast<float>(data);
    return (floatData);
}
float conversion::toFloat(long data)  // converts from long to float
{
    float floatData;
    floatData = boost::lexical_cast<float>(data);
    return (floatData);
}
float conversion::toFloat(unsigned int data)  // converts from unsigned int to float
{
    float floatData;
    floatData = boost::lexical_cast<float>(data);
    return (floatData);
}
float conversion::toFloat(unsigned long data)  // converts from unsigned long to float
{
    float floatData;
    floatData = boost::lexical_cast<float>(data);
    return (floatData);
}
float conversion::toFloat(enet_uint8 *data)  // converts from enet_uint8 * to float
{
    float floatData;
    floatData = boost::lexical_cast<float>(data);
    return (floatData);
}
float conversion::toFloat(double data)  // converts from double to float
{
    float floatData;
    floatData = boost::lexical_cast<float>(data);
    return (floatData);
}
/*float conversion::toFloat(size_t data)  // converts from size_t to float
{
    float floatData;
    floatData = boost::lexical_cast<float>(data);
    return (floatData);
}*/
float conversion::toFloat(void *data)  // converts from void * to float
{
    float floatData;
    floatData = boost::lexical_cast<float>(data);
    return (floatData);
}

// convert to double
double conversion::toDouble(std::string data)  // converts from std::string to double
{
    double doubleData;
    doubleData = boost::lexical_cast<double>(data);
    return (doubleData);
}
double conversion::toDouble(char data)  // converts from char to double
{
    double doubleData;
    doubleData = boost::lexical_cast<double>(data);
    return (doubleData);
}
double conversion::toDouble(char *data)  // converts from char * to double
{
    double doubleData;
    doubleData = boost::lexical_cast<double>(data);
    return (doubleData);
}
/*double conversion::toDouble(char **data)  // converts from char ** to double
{
    double doubleData;
    doubleData = boost::lexical_cast<double>(data);
    return (doubleData);
}*/
/*double conversion::toDouble(const char *data)  // converts from const char * to double
{
    double doubleData;
//    doubleData = boost::lexical_cast<double>(data);
    return (doubleData);
}*/
double conversion::toDouble(int data)  // converts from int to double
{
    double doubleData;
    doubleData = boost::lexical_cast<double>(data);
    return (doubleData);
}
double conversion::toDouble(long data)  // converts from long to double
{
    double doubleData;
    doubleData = boost::lexical_cast<double>(data);
    return (doubleData);
}
double conversion::toDouble(unsigned int data)  // converts from unsigned int to double
{
    double doubleData;
    doubleData = boost::lexical_cast<double>(data);
    return (doubleData);
}
double conversion::toDouble(unsigned long data)  // converts from unsigned long to double
{
    double doubleData;
    doubleData = boost::lexical_cast<double>(data);
    return (doubleData);
}
double conversion::toDouble(enet_uint8 *data)  // converts from enet_uint8 * to double
{
    double doubleData;
    doubleData = boost::lexical_cast<double>(data);
    return (doubleData);
}
double conversion::toDouble(float data)  // converts from float to double
{
    double doubleData;
    doubleData = boost::lexical_cast<double>(data);
    return (doubleData);
}
/*double conversion::toDouble(size_t data)  // converts from size_t to double
{
    double doubleData;
    doubleData = boost::lexical_cast<double>(data);
    return (doubleData);
}*/
double conversion::toDouble(void *data)  // converts from void * to double
{
    double doubleData;
    doubleData = boost::lexical_cast<double>(data);
    return (doubleData);
}

// convert to enet_uint8 *
/*enet_uint8 * conversion::toEnet_uint8Ptr(std::string data)  // converts from std::string to enet_uint8 *
{
    enet_uint8 *enet_uint8PtrData;
    enet_uint8PtrData = boost::lexical_cast<uint8_t *>(data);
    return (enet_uint8PtrData);
}
enet_uint8 * conversion::toEnet_uint8Ptr(char data)  // converts from char to enet_uint8 *
{
    enet_uint8 *enet_uint8PtrData;
    enet_uint8PtrData = boost::lexical_cast<uint8_t *>(data);
    return (enet_uint8PtrData);
}
enet_uint8 * conversion::toEnet_uint8Ptr(char *data)  // converts from char * to enet_uint8 *
{
    enet_uint8 *enet_uint8PtrData;
    enet_uint8PtrData = boost::lexical_cast<uint8_t *>(data);
    return (enet_uint8PtrData);
}
enet_uint8 * conversion::toEnet_uint8Ptr(char **data)  // converts from char ** to enet_uint8 *
{
    enet_uint8 *enet_uint8PtrData;
    enet_uint8PtrData = boost::lexical_cast<uint8_t *>(data);
    return (enet_uint8PtrData);
}
enet_uint8 * conversion::toEnet_uint8Ptr(const char *data)  // converts from const char * to enet_uint8 *
{
    enet_uint8 *enet_uint8PtrData;
//    enet_uint8PtrData = boost::lexical_cast<uint8_t *>(data);
    return (enet_uint8PtrData);
}
enet_uint8 * conversion::toEnet_uint8Ptr(int data)  // converts from int to enet_uint8 *
{
    enet_uint8 *enet_uint8PtrData;
    enet_uint8PtrData = boost::lexical_cast<uint8_t *>(data);
    return (enet_uint8PtrData);
}
enet_uint8 * conversion::toEnet_uint8Ptr(long data)  // converts from long to enet_uint8 *
{
    enet_uint8 *enet_uint8PtrData;
    enet_uint8PtrData = boost::lexical_cast<uint8_t *>(data);
    return (enet_uint8PtrData);
}
enet_uint8 * conversion::toEnet_uint8Ptr(unsigned long data)  // converts from unsigned long to enet_uint8 *
{
    enet_uint8 *enet_uint8PtrData;
    enet_uint8PtrData = boost::lexical_cast<uint8_t *>(data);
    return (enet_uint8PtrData);
}
enet_uint8 * conversion::toEnet_uint8Ptr(double data)  // converts from double to enet_uint8 *
{
    enet_uint8 *enet_uint8PtrData;
    enet_uint8PtrData = boost::lexical_cast<uint8_t *>(data);
    return (enet_uint8PtrData);
}
enet_uint8 * conversion::toEnet_uint8Ptr(float data)  // converts from float to enet_uint8 *
{
    enet_uint8 *enet_uint8PtrData;
    enet_uint8PtrData = boost::lexical_cast<uint8_t *>(data);
    return (enet_uint8PtrData);
}
enet_uint8 * conversion::toEnet_uint8Ptr(size_t data)  // converts from size_t to enet_uint8 *
{
    enet_uint8 *enet_uint8PtrData;
    enet_uint8PtrData = boost::lexical_cast<uint8_t *>(data);
    return (enet_uint8PtrData);
}
enet_uint8 * conversion::toEnet_uint8Ptr(void *data)  // converts from void * to enet_uint8 *
{
    enet_uint8 *enet_uint8PtrData;
    enet_uint8PtrData = boost::lexical_cast<uint8_t *>(data);
    return (enet_uint8PtrData);
}*/

// convert to size_t

/*size_t conversion::toSize_t(std::string data)  // converts from std::string to size_t
{
    size_t size_tData;
    size_tData = boost::lexical_cast<size_t>(data);
    return (size_tData);
}
size_t conversion::toSize_t(char data)  // converts from char to size_t
{
    size_t size_tData;
    size_tData = boost::lexical_cast<size_t>(data);
    return (size_tData);
}
size_t conversion::toSize_t(char *data)  // converts from char * to size_t
{
    size_t size_tData;
    size_tData = boost::lexical_cast<size_t>(data);
    return (size_tData);
}
size_t conversion::toSize_t(char **data)  // converts from char ** to size_t
{
    size_t size_tData;
    size_tData = boost::lexical_cast<size_t>(data);
    return (size_tData);
}
size_t conversion::toSize_t(const char *data)  // converts from const char * to size_t
{
    size_t size_tData;
//    size_tData = boost::lexical_cast<size_t>(data);
    return (size_tData);
}
size_t conversion::toSize_t(int data)  // converts from int to size_t
{
    size_t size_tData;
    size_tData = boost::lexical_cast<size_t>(data);
    return (size_tData);
}
size_t conversion::toSize_t(long data)  // converts from long to size_t
{
    size_t size_tData;
    size_tData = boost::lexical_cast<size_t>(data);
    return (size_tData);
}
size_t conversion::toSize_t(unsigned long data)  // converts from unsigned long to size_t
{
    size_t size_tData;
    size_tData = boost::lexical_cast<size_t>(data);
    return (size_tData);
}
size_t conversion::toSize_t(enet_uint8 *data)  // converts from enet_uint8 * to size_t
{
    size_t size_tData;
    size_tData = boost::lexical_cast<size_t>(data);
    return (size_tData);
}
size_t conversion::toSize_t(float data)  // converts from float to size_t
{
    size_t size_tData;
    size_tData = boost::lexical_cast<size_t>(data);
    return (size_tData);
}
size_t conversion::toSize_t(double data)  // converts from double to size_t
{
    size_t size_tData;
    size_tData = boost::lexical_cast<size_t>(data);
    return (size_tData);
}
size_t conversion::toSize_t(void *data)  // converts from void * to size_t
{
    size_t size_tData;
    size_tData = boost::lexical_cast<size_t>(data);
    return (size_tData);
}
*/

// convert to void *
/*void * conversion::voidPtr(std::string data)  // converts from std::string to void *
{
    void *voidPtrData;
    voidPtrData = boost::lexical_cast<void *>(data);
    return (voidPtrData);
}
void * conversion::voidPtr(char data)  // converts from char to void *
{
    void *voidPtrData;
    voidPtrData = boost::lexical_cast<void *>(data);
    return (voidPtrData);
}
void * conversion::voidPtr(char *data)  // converts from char * to void *
{
    void *voidPtrData;
    voidPtrData = boost::lexical_cast<void *>(data);
    return (voidPtrData);
}
void * conversion::voidPtr(char **data)  // converts from char ** to void *
{
    void *voidPtrData;
    voidPtrData = boost::lexical_cast<void *>(data);
    return (voidPtrData);
}
void * conversion::voidPtr(const char *data)  // converts from const char * to void *
{
    void *voidPtrData;
//    voidPtrData = boost::lexical_cast<void *>(data);
    return (voidPtrData);
}
void * conversion::voidPtr(int data)  // converts from int to void *
{
    void *voidPtrData;
    voidPtrData = boost::lexical_cast<void *>(data);
    return (voidPtrData);
}
void * conversion::voidPtr(long data)  // converts from long to void *
{
    void *voidPtrData;
    voidPtrData = boost::lexical_cast<void *>(data);
    return (voidPtrData);
}
void * conversion::voidPtr(unsigned long data)  // converts from unsigned long to void *
{
    void *voidPtrData;
    voidPtrData = boost::lexical_cast<void *>(data);
    return (voidPtrData);
}
void * conversion::voidPtr(enet_uint8 *data)  // converts from enet_uint8 * to void *
{
    void *voidPtrData;
    voidPtrData = boost::lexical_cast<void *>(data);
    return (voidPtrData);
}
void * conversion::voidPtr(float data)  // converts from float to void *
{
    void *voidPtrData;
    voidPtrData = boost::lexical_cast<void *>(data);
    return (voidPtrData);
}
void * conversion::voidPtr(double data)  // converts from double to void *
{
    void *voidPtrData;
    voidPtrData = boost::lexical_cast<void *>(data);
    return (voidPtrData);
}
void * conversion::voidPtr(size_t data)  // converts from void * to void *
{
    void *voidPtrData;
    voidPtrData = boost::lexical_cast<void *>(data);
    return (voidPtrData);
}*/

OpenSteer::Vec3 conversion::toOpenSteerVec3(Ogre::Vector3 vect)  // converts from Ogre::Vector3 to OpenSteer::Vec3
{

    OpenSteer::Vec3 vec3;

    vec3.x = vect[0];
    vec3.y = vect[1];
    vec3.z = vect[2];

    return (vec3);
}
Ogre::Vector3 conversion::toOgreVector3(OpenSteer::Vec3 vect) // converts from OpenSteer::Vec3 to Ogre::Vector3
{
    Ogre::Vector3 vector3;
    vector3[0] = vect.x;
    vector3[1] = vect.y;
    vector3[2] = vect.z;

    return (vector3);
}
/*
template <typename T>
std::string conversion::toString(const T& input)  // converts data to string);
{
    std::string data;
    data = boost::lexical_cast<std::string>(input);
    return(data);
}
*/

/*
template<typename T> inline std::string conversion::toString(const T& x)
{
  std::ostringstream out;
  out << x;
  return out.str();
}
template<> inline std::string conversion::toString<bool>(const bool& x)
{
  std::ostringstream out;
  out << std::boolalpha << x;
  return out.str();
}
template<> inline std::string conversion::toString<double>(const double& x)
{
  const int sigdigits = std::numeric_limits<double>::digits10;
  // or perhaps std::numeric_limits<double>::max_digits10 if that is available on your compiler
  std::ostringstream out;
  out << std::setprecision(sigdigits) << x;
  return out.str();
}
template<> inline std::string conversion::toString<float>(const float& x)
{
  const int sigdigits = std::numeric_limits<float>::digits10;
  // or perhaps std::numeric_limits<float>::max_digits10 if that is available on your compiler
  std::ostringstream out;
  out << std::setprecision(sigdigits) << x;
  return out.str();
}
template<> inline std::string conversion::toString<long double>(const long double& x)
{
  const int sigdigits = std::numeric_limits<long double>::digits10;
  // or perhaps std::numeric_limits<long_double>::max_digits10 if that is available on your compiler
  std::ostringstream out;
  out << std::setprecision(sigdigits) << x;
  return out.str();
}
*/
