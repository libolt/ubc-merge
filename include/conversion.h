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
 
#ifndef _CONVERSION_H_
#define _CONVERSION_H_

#include "network.h"

#include <iostream>
#include <sstream>
#include <iomanip>
#include <string>
#include <limits>

#include <boost/lexical_cast.hpp>
#include <boost/shared_ptr.hpp>

#include "Ogre.h"
#include "OgreVector3.h"

#include "steering.h"

//template<class T, class TL>
class conversion  // class for conversion between data types
{
    public:
//        static conversion *Instance();
        static boost::shared_ptr<conversion> Instance();

        // convert to string
        std::string toString(char *data);  // converts char * data to string
//        std::string toString(char **data);  // converts char ** data to string
        std::string toString(const char *data);  // converts const char * data to string
        std::string toString(int data);  // converts int data to string
        std::string toString(long data);  // converts long data to string
        std::string toString(unsigned int data); // converts unsigned int data to string
        std::string toString(unsigned long data);  // converts unsigned long data to string
        std::string toString(enet_uint8 *data);  // converts const enet_uint8 * data to string
        std::string toString(float data);  // converts float data to string
        std::string toString(double data);  // converts double data to string
        std::string toString(void *data);  // converts void * data to string
        std::string toString(Ogre::Vector3 data);  // converts Ogre::Vector3 data to string

        // convert to char
        char toChar(std::string data);  // converts from std::string to char
        char toChar(char *data);  // converts from char * to char
//        char toChar(char **data);  // converts from char ** to char
        //char toChar(const char *data);  // converts from const char * to char
        char toChar(int data);  // converts from int to char
        char toChar(long data);  // converts from long to char
        char toChar(unsigned int data);  // converts from unsigned int to char
        char toChar(unsigned long data);  // converts from unsigned long to char
        char toChar(enet_uint8 *data);  // converts from enet_uint8 * to char
        char toChar(float data);  // converts from float to char
        char toChar(double data);  // converts from double to char
        char toChar(void *data);  // converts from void * to char
        
        // convert to char *
/*        char *toCharPtr(std::string data);  // converts from std::string to char *
        char *toCharPtr(char data);  // converts from char to char *
//        char *toCharPtr(char **data);  // converts from char ** to char *
        char *toCharPtr(const char *data);  // converts from const char * to char *        
        char *toCharPtr(int data);  // converts from int to char *
        char *toCharPtr(long data);  // converts from long to char *
        char *toCharPtr(unsigned long data);  // converts from unsigned long to char *
        char *toCharPtr(enet_uint8 *data);  // converts from enet_uint8 * to char *
        char *toCharPtr(float data);  // converts from float to char *
        char *toCharPtr(double data);  // converts from double to char *
        char *toCharPtr(size_t data);  // converts from size_t to char *
        char *toCharPtr(void *data);  // converts from void * to char *
*/
        // convert to char **
/*        char **toCharPtrPtr(std::string data);  // converts from std::string to char **
        char **toCharPtrPtr(char data);  // converts from char to char **
        char **toCharPtrPtr(char *data);  // converts from char * to char **
        char **toCharPtrPtr(const char *data);  // converts from const char * to char **        
        char **toCharPtrPtr(int data);  // converts from int to char **
        char **toCharPtrPtr(long data);  // converts from long to char **
        char **toCharPtrPtr(unsigned long data);  // converts from unsigned long to char **
        char **toCharPtrPtr(enet_uint8 *data);  // converts from enet_uint8 * to char **
        char **toCharPtrPtr(float data);  // converts from float to char **
        char **toCharPtrPtr(double data);  // converts from double to char **
        char **toCharPtrPtr(size_t data);  // converts from size_t to char **
        char **toCharPtrPtr(void *data);  // converts from void * to char **
*/
        // convert to const char *
/*        const char *toConstCharPtr(std::string data);  // converts from std::string to const char *
        const char *toConstCharPtr(char data);  // converts from char to const char *
        const char *toConstCharPtr(char *data);  // converts from char * to const char *
//        const char *toConstCharPtr(char **data);  // converts from char ** to const char *
        const char *toConstCharPtr(int data);  // converts from int to const char *
        const char *toConstCharPtr(long data);  // converts from long to const char *
        const char *toConstCharPtr(unsigned long data);  // converts from unsigned long to const char *
        const char *toConstCharPtr(enet_uint8 *data);  // converts from enet_uint8 * to const char *
        const char *toConstCharPtr(float data);  // converts from float to const char *
        const char *toConstCharPtr(double data);  // converts from double to const char *
        const char *toConstCharPtr(size_t data);  // converts from size_t to const char *
        const char *toConstCharPtr(void *data);  // converts from void * to const char *
*/

        // convert to int
        int toInt(std::string data);  // converts from std::string to int
        int toInt(char data);  // converts from char to int
        int toInt(char *data);  // converts from char * to int
//        int toInt(char **data);  // converts from char ** to int
        //int toInt(const char *data);  // converts from const char * to int
        int toInt(long data);  // converts from long to int
        int toInt(unsigned int data);  // converts from unsigned int to int
        int toInt(unsigned long data);  // converts from unsigned long to int
        int toInt(enet_uint8 *data);  // converts from enet_uint8 * to int
        int toInt(float data);  // converts from float to int
        int toInt(double data);  // converts from double to int
        //int toInt(size_t data);  // converts from size_t to int
        int toInt(void *data);  // converts from void * to int
        
        // convert to long
        long toLong(std::string data);  // converts from std::string to long
        long toLong(char data);  // converts from char to long
        long toLong(char *data);  // converts from char * to long
//        long toLong(char **data);  // converts from char ** to long
        //long toLong(const char *data);  // converts from const char * to long
        long toLong(int data);  // converts from int to long
        long toLong(unsigned int data);  // converts from unsigned int to long
        long toLong(unsigned long data);  // converts from unsigned long to long
        long toLong(enet_uint8 *data);  // converts from enet_uint8 * to long
        long toLong(float data);  // converts from float to long
        long toLong(double data);  // converts from double to long
        //long toLong(size_t data);  // converts from size_t to long
        long toLong(void *data);  // converts from void * to long

        // converts to unsigned int
        unsigned int toUnsignedInt(std::string data);  // converts from std::string to unsigned int
        unsigned int toUnsignedInt(char data);  // converts from char to unsigned int
        unsigned int toUnsignedInt(char *data);  // converts from char * to unsigned int
//        unsigned int toUnsignedInt(char **data);  // converts from char ** to unsigned int
        unsigned int toUnsignedInt(const char *data);  // converts from const char * to unsigned int
        unsigned int toUnsignedInt(long data);  // converts from long to unsigned int
        unsigned int toUnsignedInt(int data);  // converts from int to unsigned int
        unsigned int toUnsignedInt(unsigned long data);  // converts from unsigned long to unsigned int
        unsigned int toUnsignedInt(enet_uint8 *data);  // converts from enet_uint8 * to unsigned int
        unsigned int toUnsignedInt(float data);  // converts from float to unsigned int
        unsigned int toUnsignedInt(double data);  // converts from double to unsigned int
        //unsigned int toUnsignedInt(size_t data);  // converts from size_t to unsigned int
        unsigned int toUnsignedInt(void *data);  // converts from void * to unsigned int

        // converts to unsigned long
        unsigned long toUnsignedLong(std::string data);  // converts from std::string to unsigned long
        unsigned long toUnsignedLong(char data);  // converts from char to unsigned long
        unsigned long toUnsignedLong(char *data);  // converts from char * to unsigned long
//        unsigned long toUnsignedLong(char **data);  // converts from char ** to unsigned long
        unsigned long toUnsignedLong(const char *data);  // converts from const char * to unsigned long
        unsigned long toUnsignedLong(long data);  // converts from long to unsigned long
        unsigned long toUnsignedLong(int data);  // converts from int to unsigned long
        unsigned long toUnsignedLong(unsigned int data);  // converts from unsigned int to unsigned long
        unsigned long toUnsignedLong(enet_uint8 *data);  // converts from enet_uint8 * to unsigned long
        unsigned long toUnsignedLong(float data);  // converts from float to unsigned long
        unsigned long toUnsignedLong(double data);  // converts from double to unsigned long
        //unsigned long toUnsignedLong(size_t data);  // converts from size_t to unsigned long
        unsigned long toUnsignedLong(void *data);  // converts from void * to unsigned long

        // convert to float
        float toFloat(std::string data);  // converts from std::string to float
        float toFloat(char data);  // converts from char to float
        float toFloat(char *data);  // converts from char * to float
//        float toFloat(char **data);  // converts from char ** to float
        //float toFloat(const char *data);  // converts from const char * to float
        float toFloat(int data);  // converts from int to float
        float toFloat(long data);  // converts from long to float
        float toFloat(unsigned int data);  // converts from unsigned int to float
        float toFloat(unsigned long data);  // converts from unsigned long to float
        float toFloat(enet_uint8 *data);  // converts from enet_uint8 * to float
        float toFloat(double data);  // converts from double to float
        //float toFloat(size_t data);  // converts from size_t to float
        float toFloat(void *data);  // converts from void * to float
        
        // convert to double
        double toDouble(std::string data);  // converts from std::string to double
        double toDouble(char data);  // converts from char to double
        double toDouble(char *data);  // converts from char * to double
//        double toDouble(char **data);  // converts from char ** to double
        //double toDouble(const char *data);  // converts from const char * to double
        double toDouble(int data);  // converts from int to double
        double toDouble(long data);  // converts from long to double
        double toDouble(unsigned int data);  // converts from unsigned int to double
        double toDouble(unsigned long data);  // converts from unsigned long to double
        double toDouble(enet_uint8 *data);  // converts from enet_uint8 * to double
        double toDouble(float data);  // converts from float to double
        //double toDouble(size_t data);  // converts from size_t to double
        double toDouble(void *data);  // converts from void * to double
        
        // convert to enet_uint8 *
/*        enet_uint8 * toEnet_uint8Ptr(std::string data);  // converts from std::string to enet_uint8 *
        enet_uint8 * toEnet_uint8Ptr(char data);  // converts from char to enet_uint8 *
        enet_uint8 * toEnet_uint8Ptr(char *data);  // converts from char * to enet_uint8 *
//        enet_uint8 * toEnet_uint8Ptr(char **data);  // converts from char ** to enet_uint8 *
        enet_uint8 * toEnet_uint8Ptr(const char *data);  // converts from const char * to enet_uint8 *
        enet_uint8 * toEnet_uint8Ptr(int data);  // converts from int to enet_uint8 *
        enet_uint8 * toEnet_uint8Ptr(long data);  // converts from long to enet_uint8 *
        enet_uint8 * toEnet_uint8Ptr(unsigned long data);  // converts from unsigned long to enet_uint8 *
        enet_uint8 * toEnet_uint8Ptr(double data);  // converts from double to enet_uint8 *
        enet_uint8 * toEnet_uint8Ptr(float data);  // converts from float to enet_uint8 *
        enet_uint8 * toEnet_uint8Ptr(size_t data);  // converts from size_t to enet_uint8 *
        enet_uint8 * toEnet_uint8Ptr(void *data);  // converts from void * to enet_uint8 *
*/
        // convert to size_t
/*        size_t toSize_t(std::string data);  // converts from std::string to size_t
        size_t toSize_t(char data);  // converts from char to size_t
        size_t toSize_t(char *data);  // converts from char * to size_t
//        size_t toSize_t(char **data);  // converts from char ** to size_t
        //size_t toSize_t(const char *data);  // converts from const char * to size_t
        size_t toSize_t(int data);  // converts from int to size_t
        size_t toSize_t(long data);  // converts from long to size_t
        size_t toSize_t(unsigned long data);  // converts from unsigned long to size_t
        size_t toSize_t(enet_uint8 *data);  // converts from enet_uint8 * to size_t
        size_t toSize_t(float data);  // converts from float to size_t
        size_t toSize_t(double data);  // converts from double to size_t
        size_t toSize_t(void *data);  // converts from void * to size_t
*/

        // convert to void *
/*        void * voidPtr(std::string data);  // converts from std::string to void *
        void * voidPtr(char data);  // converts from char to void *
        void * voidPtr(char *data);  // converts from char * to void *
//        void * voidPtr(char **data);  // converts from char ** to void *
        void * voidPtr(const char *data);  // converts from const char * to void *
        void * voidPtr(int data);  // converts from int to void *
        void * voidPtr(long data);  // converts from long to void *
        void * voidPtr(unsigned long data);  // converts from unsigned long to void *
        void * voidPtr(enet_uint8 *data);  // converts from enet_uint8 * to void *
        void * voidPtr(float data);  // converts from float to void *
        void * voidPtr(double data);  // converts from double to void *
        void * voidPtr(size_t data);  // converts from void * to void *
*/
//        template <typename T>



        OpenSteer::Vec3 toOpenSteerVec3(Ogre::Vector3 vect);  // converts from Ogre::Vector3 to OpenSteer::Vec3
        Ogre::Vector3 toOgreVector3(OpenSteer::Vec3 vect); // converts from OpenSteer::Vec3 to Ogre::Vector3
    protected:
    conversion();
    conversion(const conversion&);
    conversion& operator= (const conversion&);

//    ~conversion();

    private:
    
//    static conversion *pInstance;
    static boost::shared_ptr<conversion> pInstance;
/*    
    T toString(const T& x, TL y)
{
  std::ostringstream out;
  out << x;
  return out.str();
}
*/
};

#endif
