/**************************************************************************/
/*!
        @file     GondolaAndPropState.hh
        @author1  Justin Albert (jalbert@uvic.ca)
        @author2  Patrick Ryan  (patrick.ryan5787@gmail.com)
        @author3  Aravind Shaj  (aravindshaj@gmail.com)
        @author4  Hannah Swan   (hannah.swan.3.14@gmail.com)
        @license  GPL

        This is the class containing the present state of the ALTAIR 
        gondola (and of all internals, except for all state variables 
        related to the light source payload) and of the ALTAIR propulsion 
        system.  
    
        An example usage:
            #include "ALTAIR_state.hh"
            #include "GondolaAndPropState.hh"

            float rpmOfMotor4 = altairState->getGondAndProp()->getRPMMotor4();

        Justin Albert  jalbert@uvic.ca            first version 7 Jul. 2018

        @section  HISTORY

        v1.0  - First version
*/
/**************************************************************************/


#ifndef __GONDOLAANDPROPSTATE_HH__
#define __GONDOLAANDPROPSTATE_HH__

#define ALTAIRPropellerDiameter  0.3556             // 14" = 35.56 cm = 0.3556 m

//------------------------------------
// Collaborating Class Declarations --
//------------------------------------

//              ---------------------
//              -- Class Interface --
//              ---------------------
class   GondolaAndPropState {

    public:

        GondolaAndPropState();

        virtual ~GondolaAndPropState();

        virtual float                  getPropellerDiameter() { return ALTAIRPropellerDiameter; }

        virtual int                    getRPMMotor(     int  motorNum                     );    // motorNum goes from 1 to 4 (not 0 to 3)
        virtual int                    getRPMMotor1();
        virtual int                    getRPMMotor2();
        virtual int                    getRPMMotor3();
        virtual int                    getRPMMotor4();

        virtual void                   setRPMMotor(     int  motorNum   ,  int  rpmMotor  );    // motorNum goes from 1 to 4 (not 0 to 3)
        virtual void                   setRPMMotor1(    int  rpmMotor1                    );
        virtual void                   setRPMMotor2(    int  rpmMotor2                    );
        virtual void                   setRPMMotor3(    int  rpmMotor3                    );
        virtual void                   setRPMMotor4(    int  rpmMotor4                    );


    private:

        int                            _rpmMotor[4];

};



#endif // __GONDOLAANDPROPSTATE_HH__
