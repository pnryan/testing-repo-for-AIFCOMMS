/**************************************************************************/

/*!

    @file     DragCalcMethods.hh

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



#ifndef __DRAG_CALC_METHODS_HH__

#define __DRAG_CALC_METHODS_HH__



//              ---------------------

//              -- Class Interface --

//              ---------------------

class DragCalcMethods {



    public:



	static float getBalloonDrag();		// get the present drag due to the balloon
	
	
	
	static float getPayloadDrag();		// currently only returns a dummy values for drag on the payload of ALTAIR


    private:



        DragCalcMethods() {} 			// constructor should never be used

	

};



#endif // __THRUST_CALC_METHODS_HH__

