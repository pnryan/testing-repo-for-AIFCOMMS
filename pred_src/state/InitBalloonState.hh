/**************************************************************************/

/*!

        @file     DefaultBalloonAndPfoilState.hh

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





#ifndef __INIT_BALLOON_STATE_HH__

#define __INIT_BALLOON_STATE_HH__



//              ---------------------

//              -- Class Interface --

//              ---------------------

class   InitBalloonState {

    public:
		
        InitBalloonState();
		

        virtual ~InitBalloonState();
		
		
		
        virtual float                  getInitVolume  ()    {return _initVolume  ;}
		
		

        virtual float                  getInitPressure()    {return _initPressure;}
		
		
		
		virtual float                  getInitTemp    ()    {return _initTemp    ;}
		
		
		
		
		
		
		
		virtual void                   	setInitVolume( 		float  initVolume    	);
		
		
		
		virtual void 					setInitPressure(	float  initPressure		);
		
		
		
		virtual void					setInitTemp(		float  initTemp			);



	private:
		
		float _initVolume;
		
		float _initPressure;
		
		float _initTemp;
	
};

#endif // __INIT_BALLOON_STATE_HH__
