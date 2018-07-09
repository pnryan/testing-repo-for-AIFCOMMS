#include <math.h>
#include <stdio.h>
#include <stdlib.h>

#include "thrustCalcMethod.hh"
#include "thrustInterpMethod.hh"
#include "thrustMomTransMethod.hh"

//default constructor for thrust object if no values given
	thrust :: thrust(){
		alt = 0;
		density = 0;
		interp_thrust = 0;
		mom_trans_thrust = 0;
	}
	
	//full constructor for thrust object when parameters are given upon initialization
	thrust :: thrust(ALTAIR_state* state, float altitude, float rho){
		curr_state = state;
		alt = altitude;
		density = rho;
	}
	
	//A call to this method will have the values of interp_thrust and mom_trans_thrust calculated and
	//set for a given thrust object.
	void thrust :: set_thrust_values(){
		interp_thrust = interp_thrust(density, curr_state -> RPM, curr_state -> f_vel, curr_state -> diameter);
		mom_trans_thrust = mom_trans_thrust(alt, curr_state -> RPM ,density,curr_state -> pitch, curr_state -> diameter, curr_state -> f_vel);
	}
}