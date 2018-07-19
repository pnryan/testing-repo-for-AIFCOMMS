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

//#include "../state/GondolaAndPropState.hh"

#include "../state/BalloonAndPfoilState.hh"




//              ----------------------------------------

//              -- Public Member Function Definitions --

//              ----------------------------------------



float DragCalcMethods::getBalloonDrag()

{
	
	float initState 		= altairState->getBalAndPfoil()->getBalloonInitTemp()*altairState->getBalAndPfoil()->getBalloonInitPressure()*
							altairState->getBalAndPfoil()->getBalloonInitVolume()		;
						
	float payloadVelocity	= altairState->getExtEnv()->getForwardVelocityRelToWind()	;
	
	float temp			 	= altairState->getExtEnv() -> getOutsideTemp() 				;
	
	float pressure 			= 2.488*(temp/216.6)-11.388									;
	
	float viscosity 		= (1.458e-6*sqrt(temp))/(1+110.4/temp)						;
		
	float density			= pressure/(0.2869*temp)									;
	
	float rho_nu 			= density/viscosity											;
	
	float balloonVolume 	= (temp/pressure)*initState  								;
	
	float balloonRadius  	= pow((0.75*balloonVolume/M_PI),(1/3))						;
	
	float crossSecArea   	= M_PI*balloonRadius*balloonRadius     						;
	
	float Re			 	= rho_nu*payloadVelocity*2*balloonRadius					;
	
	float dragCoef       	= 24/Re + 2.6*(Re/5)/(1+pow((Re/5),1.52)) + 0.411*pow(Re/2.63e5,-7.94)/(1+pow(Re/2.63e5,-8)) + 0.25*(Re/1e6)/(1+(Re/1e6));
									//This equation comes from curve fitting??? ask Aravind about this
	
	return dragCoef																		;			
	
}




