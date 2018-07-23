/**************************************************************************/

/*!

    @file     DragCalcMethods.cc

    @author1  Justin Albert (jalbert@uvic.ca)

    @author2  Patrick Ryan  (patrick.ryan5787@gmail.com)

    @author3  Aravind Shaj  (aravindshaj@gmail.com)

    @author4  Hannah Swan   (hannah.swan.3.14@gmail.com)

    @license  GPL



    This is the class containing drag calculation methods to determine the

    magnitude (in Newtons) of the drag force acting on the ALTAIR

    payload at a current instant, in terms of variables such as: 1) ALTAIRS
	
	current elevationASL, 2) Initial Balloon state, pressure, volume, and temp



    @section  HISTORY



    v1.0  - First version

*/

/**************************************************************************/





#include <math.h>

#include <stdio.h>

#include <stdlib.h>



//-----------------------

// This Class's Header --

//-----------------------

#include "DragCalcMethods.hh"



//-------------------------------

// Collaborating Class Headers --

//-------------------------------

#include "../state/ALTAIR_state.hh"

#include "../state/ExternalEnvironState.hh"

#include "../state/InitBalloonState.hh"





#define eulersNum  2.71828


//              ----------------------------------------

//              -- Public Member Function Definitions --

//              ----------------------------------------

// gets the drag in Newtons affecting the balloon at a given altitude calculated based on the current size of the balloon,

// the balloons current size is determined using the ideal gas law PV=nRT


float DragCalcMethods::getBalloonDrag()

{
	
	InitBalloonState* initBal 		= altairState->getInitBal()													;
	
	float initState 				= initBal->getInitTemp()*initBal->getInitPressure()*initBal->getInitVolume();
							
	ExternalEnvironState* ExtEnv 	= altairState-> getExtEnv()													;
	
	float payloadVelocity			= ExtEnv-> getForwardVelocityRelToWind()									;
	
	float temp			 			= ExtEnv-> getOutsideTemp() 												;
	
	float density					= ExtEnv-> getOutsideAirDensity()											;
	
	float elevationASL				= ExtEnv-> getElevationASL()												;
	
	
	
	
	
	
	float pressure 					= 0																			;
	
	if (elevationASL > 25000) 
	{
		pressure 					= 2.488*pow((temp/216.6),-11.388)											;
	}
	else if (11000 < elevationASL && elevationASL < 25000)
	{
		pressure					= 22.65*pow(eulersNum,1.73-(0.000157*elevationASL))							;
	}
	else
	{
		pressure					= 101.29*pow(temp/288.8,5.256)												;
	}
		//this equation comes from the following source:https://www.grc.nasa.gov/www/k-12/airplane/atmosmet.html
		
		
		
		
	
	
	float viscosity 				= (1.458e-6*sqrt(temp))/(1+110.4/temp)										;

	float rho_nu 					= density/viscosity															;
	
	float balloonVolume 			= (temp/pressure)*initState  												;
	
	float balloonRadius  			= pow((0.75*balloonVolume/M_PI),(1/3))										;
	
	float crossSecArea   			= M_PI*balloonRadius*balloonRadius     										;
	
	float Re			 			= rho_nu*payloadVelocity*2*balloonRadius									;
	
	float dragCoef       			= 24/Re + 2.6*(Re/5)/(1+pow((Re/5),1.52)) + 0.411*pow(Re/2.63e5,-7.94)/(1+pow(Re/2.63e5,-8)) + 0.25*(Re/1e6)/(1+(Re/1e6));
							//This equation comes from curve fitting and is sourced from: http://pages.mtu.edu/~fmorriso/DataCorrelationForSphereDrag2016.pdf

	float drag 						= dragCoef*crossSecArea*density*payloadVelocity*payloadVelocity/2			;
	
	return drag																									;	
	
}




// Returns drag in Newtons affecting the ALTAIR payload. 

// note that this function is essentially returning dummy values at this point as we have been unable to find

// an effective model for determining the Drag Coefficient on a cuboid. This will need to be completely 

// overhauled when we find a method of achieving this. 

float DragCalcMethods::getPayloadDrag()

{
	
	float payloadVelocity	= altairState->getExtEnv()->getForwardVelocityRelToWind()			;
	
	float density			= altairState->getExtEnv()->getOutsideAirDensity()					;
	
	float crossSecArea		= .2 																;
	
	float dragCoef 			= 2.05																;
	
	float drag				= dragCoef*crossSecArea*density*payloadVelocity*payloadVelocity/2	;

	return drag																					;

}


