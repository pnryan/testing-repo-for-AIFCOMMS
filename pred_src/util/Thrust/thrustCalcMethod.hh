#ifndef __THRUST_CALC_METHOD_H__
#define __THRUST_CALC_METHOD_H__

typedef struct ALTAIR_state ALTAIR_state;	//the ALTAIR_state struct will likely evolve in time as we 
											//determine what state variables are most important and should
											//likely become a class with constructor etc before too long.
struct ALTAIR_state
{
	float RPM;
	float f_vel;		//f_vel here refers to foreward velocity of the payload
	float orientation[2];   // a normalized vector <u,v> corresponding to the orientation of ALTAIR's payload
	float diameter;
	float pitch;
	float mass;
};


class thrust{
	public:
	
	ALTAIR_state* curr_state;
	float alt;
	float density;
	float interp_thrust;
	float mom_trans_thrust;
	
	//default constructor
	thrust();
	
	//current state constructor.
	thrust(ALTAIR_state* state, float altitude, float rho);
	
	void set_thrust_values();
}

#endif // __THRUST_CALC_METHOD_H__