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

conversion* conversion::pInstance = 0;

conversion* conversion::Instance()
{
    if (pInstance == 0)  // is it the first call?
    {
        pInstance = new conversion; // create sole instance
    }
    return pInstance; // address of sole instance
}

// inputSystem constructor
conversion::conversion()
{
    
}

conversion::~conversion()
{
}

std::string conversion::toString(char *data)  // converts char * data to string
{
    std::string strData;
    strData = boost::lexical_cast<std::string>(data);
    return (strData);
}
std::string conversion::toString(int data)  // converts int data to string
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
