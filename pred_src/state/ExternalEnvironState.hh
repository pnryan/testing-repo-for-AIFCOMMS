/**************************************************************************/
/*!
        @file     ExternalEnvironState.hh
        @author1  Justin Albert (jalbert@uvic.ca)
        @author2  Patrick Ryan  (patrick.ryan5787@gmail.com)
        @author3  Aravind Shaj  (aravindshaj@gmail.com)
        @author4  Hannah Swan   (hannah.swan.3.14@gmail.com)
        @license  GPL

        This is the class containing the present state of all of ALTAIR's 
        relevant external environmental conditions.  
    
        An example usage:
            #include "ALTAIR_state.hh"
            #include "ExternalEnvironState.hh"

            float outsideTemp = altairState->getExtEnv()->getOutsideTemp();

        Justin Albert  jalbert@uvic.ca            first version 7 Jul. 2018

        @section  HISTORY

        v1.0  - First version
*/
/**************************************************************************/


#ifndef __EXTERNALENVIRONSTATE_HH__
#define __EXTERNALENVIRONSTATE_HH__

//------------------------------------
// Collaborating Class Declarations --
//------------------------------------

//              ---------------------
//              -- Class Interface --
//              ---------------------
class   ExternalEnvironState {

    public:

        ExternalEnvironState();

        virtual ~ExternalEnvironState();

        virtual float                  getOutsideTemp();
        virtual float                  getOutsideAirDensity();
        virtual float                  getForwardVelocityRelToWind();				virtual float                  getAltitude();

        virtual void                   setOutsideTemp(              float  outsideTemp               );
        virtual void                   setOutsideAirDensity(        float  outsideAirDensity         );
        virtual void                   setForwardVelocityRelToWind( float  forwardVelocityRelToWind  );				virtual void                   setAltitude(                 float  Altitude                  );


    private:

        float                          _outsideTemp;
        float                          _outsideAirDensity;
        float                          _forwardVelocityRelToWind;				float						   _altitude;

};



#endif // __EXTERNALENVIRONSTATE_HH__
