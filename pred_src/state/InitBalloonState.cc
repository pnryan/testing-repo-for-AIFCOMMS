/**************************************************************************/

/*!

        @file     InitBalloonState.cc

        @author1  Justin Albert (jalbert@uvic.ca)

        @author2  Patrick Ryan  (patrick.ryan5787@gmail.com)

        @author3  Aravind Shaj  (aravindshaj@gmail.com)

        @author4  Hannah Swan   (hannah.swan.3.14@gmail.com)

        @license  GPL



        This is the class containing the Initial Balloon state onboard ALTAIR for a given launch

    

        @section  HISTORY



        v1.0  - First version

*/

/**************************************************************************/



//-----------------------

// This Class's Header --

//-----------------------

#include "InitBalloonState.hh"



//-------------------------------

// Collaborating Class Headers --

//-------------------------------





//              ----------------------------------------

//              -- Public Function Member Definitions --

//              ----------------------------------------



//---------------

// Constructor --

//---------------

InitBalloonState::InitBalloonState()


 : _initVolume	(			8812.17 ),

   _initPressure(       	101400.9),

   _initTemp	( 			288.14	)

   
   {
	   
   }



//--------------

// Destructor --

//--------------

InitBalloonState::~InitBalloonState()

{

}



//-----------

// Methods --

//-----------

void

InitBalloonState::setInitVolume(            float initVolume             	)

{

  _initVolume             	= initVolume;

}



void

InitBalloonState::setInitPressure(        	float initPressure		      	)

{

  _initPressure		        = initPressure;

}



void

InitBalloonState::setInitTemp(  			float initTemp					)

{

  _initTemp = initTemp;

}








