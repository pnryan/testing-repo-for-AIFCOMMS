/**************************************************************************/
/*!
        @file     ExternalEnvironState.cc
        @author1  Justin Albert (jalbert@uvic.ca)
        @author2  Patrick Ryan  (patrick.ryan5787@gmail.com)
        @author3  Aravind Shaj  (aravindshaj@gmail.com)
        @author4  Hannah Swan   (hannah.swan.3.14@gmail.com)
        @license  GPL

        This is the class containing the present state of all of ALTAIR's
        relevant external environmental conditions.
    
        Justin Albert  jalbert@uvic.ca            first version 7 Jul. 2018

        @section  HISTORY

        v1.0  - First version
*/
/**************************************************************************/

//-----------------------
// This Class's Header --
//-----------------------
#include "ExternalEnvironState.hh"

//-------------------------------
// Collaborating Class Headers --
//-------------------------------


//              ----------------------------------------
//              -- Public Function Member Definitions --
//              ----------------------------------------

//---------------
// Constructor --
//---------------
ExternalEnvironState::ExternalEnvironState()
 : _outsideTemp(              0. ),
   _outsideAirDensity (       1. ),
   _forwardVelocityRelToWind( 0. )
{
}

//--------------
// Destructor --
//--------------
ExternalEnvironState::~ExternalEnvironState()
{
}

//-----------
// Methods --
//-----------
float
ExternalEnvironState::getOutsideTemp()
{
  return _outsideTemp;
}

float
ExternalEnvironState::getOutsideAirDensity()
{
  return _outsideAirDensity;
}

float
ExternalEnvironState::getForwardVelocityRelToWind()
{
  return _forwardVelocityRelToWind;
}



void
ExternalEnvironState::setOutsideTemp(               float outsideTemp              )
{
  _outsideTemp              = outsideTemp;
}

void
ExternalEnvironState::setOutsideAirDensity(         float outsideAirDensity        )
{
  _outsideAirDensity        = outsideAirDensity;
}

void
ExternalEnvironState::setForwardVelocityRelToWind(  float forwardVelocityRelToWind )
{
  _forwardVelocityRelToWind = forwardVelocityRelToWind;
}


