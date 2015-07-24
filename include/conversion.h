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

#include <iostream>
#include <sstream>
#include <iomanip>k
#include <string>
#include <limits>

#include <boost/lexical_cast.hpp>

#include "Ogre.h"
#include "OgreVector3.h"

#include "enet.h"

//template<class T, class TL>
class conversion  // class for conversion between data types
{
    public:
        static conversion *Instance();

        std::string toString(char *data);  // converts char * data to string
        std::string toString(char **data);  // converts char ** data to string
        std::string toString(const char *data);  // converts const char * data to string
        std::string toString(int data);  // converts int data to string
        std::string toString(enet_uint8 *data);  // converts const enet_uint8 * data to string
        std::string toString(long data);  // converts long data to string
        std::string toString(unsigned long data);  // converts unsigned long data to string
        std::string toString(float data);  // converts float data to string
        std::string toString(double data);  // converts double data to string
        std::string toString(size_t data);  // converts size_t data to string
        std::string toString(void *data);  // converts void * data to string
        std::string toString(Ogre::Vector3 data);  // converts Ogre::Vector3 data to string

//        template <typename T>

/*        std::string toString(const T& input);  // converts data to string);
        template<typename T> inline std::string conversion::toString(const T& x);
        template<> inline std::string conversion::toString<bool>(const bool& x);
        template<> inline std::string conversion::toString<double>(const double& x);
        template<> inline std::string conversion::toString<float>(const float& x);
        template<> inline std::string conversion::toString<long double>(const long double& x);


TL string toString<bool>(const bool& x, TL)
{
  std::ostringstream out;
  out << std::boolalpha << x;
  return out.str();
}
template<> inline std::string toString<double>(const double& x)
{
  const int sigdigits = std::numeric_limits<double>::digits10;
  // or perhaps std::numeric_limits<double>::max_digits10 if that is available on your compiler
  std::ostringstream out;
  out << std::setprecision(sigdigits) << x;
  return out.str();
}
template<> inline std::string toString<float>(const float& x)
{
  const int sigdigits = std::numeric_limits<float>::digits10;
  // or perhaps std::numeric_limits<float>::max_digits10 if that is available on your compiler
  std::ostringstream out;
  out << std::setprecision(sigdigits) << x;
  return out.str();
}
template<> inline std::string toString<long double>(const long double& x)
{
  const int sigdigits = std::numeric_limits<long double>::digits10;
  // or perhaps std::numeric_limits<long_double>::max_digits10 if that is available on your compiler
  std::ostringstream out;
  out << std::setprecision(sigdigits) << x;
  return out.str();
}
*/

    protected:
    conversion();
    conversion(const conversion&);
    conversion& operator= (const conversion&);

    ~conversion();

    private:
    
    static conversion *pInstance;

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
