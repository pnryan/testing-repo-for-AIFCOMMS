/**************************************************************************/
/*!
        @file     BalloonAndPfoilState.hh
        @author1  Justin Albert (jalbert@uvic.ca)
        @author2  Patrick Ryan  (patrick.ryan5787@gmail.com)
        @author3  Aravind Shaj  (aravindshaj@gmail.com)
        @author4  Hannah Swan   (hannah.swan.3.14@gmail.com)
        @license  GPL

        This is the class containing the present state of the ALTAIR
        parafoil, balloon, rigging, and helium bleed valve.  
    
        An example usage:
            #include "ALTAIR_state.hh"
            #include "BalloonAndPfoilState.hh"

            bool isCutdown = altairState->getBalAndPfoil()->getIsCutdown();

        Justin Albert  jalbert@uvic.ca            first version 7 Jul. 2018

        @section  HISTORY

        v1.0  - First version
*/
/**************************************************************************/


#ifndef __BALLOONANDPFOILSTATE_HH__
#define __BALLOONANDPFOILSTATE_HH__#define BalloonInitVolume           8812.17   //initial volume of balloon in m^3#define BalloonInitPressure         101400.9  //initial pressure of balloon in m^3#define BalloonInitTemp             288.14    //initial temperature of balloon in K/********************************************************************note:	these values may be way off. I temporarily borrowed the values Aravind had used in a 	preliminary version of drag calc which was written in matlab. these will need to be 	made sure to be accurate before a final version		Also it may be best to make these easier to modify later. perhaps an initial state request	should be made to a user at run time as these values will not neccasarily remain constant	between launches.*********************************************************************/
//------------------------------------
// Collaborating Class Declarations --
//------------------------------------

//              ---------------------
//              -- Class Interface --
//              ---------------------
class   BalloonAndPfoilState {

    public:

        BalloonAndPfoilState();

        virtual ~BalloonAndPfoilState();						        virtual float                  getBalloonInitVolume  ()    {return BalloonInitVolume  ;}				        virtual float                  getBalloonInitPressure()    {return BalloonInitPressure;}								virtual float                  getBalloonInitTemp    ()    {return BalloonInitTemp    ;}				

        virtual bool                   getIsCutdown();

        virtual void                   setIsCutdown(    bool  isCutdown  );


    private:

        bool                           _isCutdown;

};



#endif // __BALLOONANDPFOILSTATE_HH__
