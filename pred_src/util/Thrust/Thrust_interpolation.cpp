// Have to change variable names and look after proper inheritance
// We need to inherit forward velocity,rate of revolution,diameter,density in SI Units

#include <math.h>
#include <stdio.h>
#include <stdlib.h>
#include <assert.h>

#include "altitude.h"
#include "rum_model.h"

//Computes value for J=v/nd 'dimensionless velocity'
//Figured it was better than computing it in both functions
float get_J(ALTAIR_state* curr_state)
{
	float curr_RPM = *curr_state->RPM;								//access states from ALTAIR_state
	float curr_f_vel = *curr_state->f_vel;
	float curr_diameter = *curr_state->diameter;
	
	float ang_freq = curr_RPM * M_PI / 30;							//turn RPM into radians/s
	float J = curr_f_vel / (ang_freq*curr_diameter);				//get dimensionless velocity

	return J;
}

/* Herein get_CT, given that it is a very approximate analysis we are doing, I came up with a simple linear expression for C_t.
From the plot it was evident that C_t tends to be more and more linear as we....
move towards a smaller pitch/diameter ratio.
Hence I just came up with a linear equation for the situation considering two power law equations for x and y intersects...
That is I came up with two regression models for the intersections and just got the equation of the line connecting them
I thought this was better than interpolation for now. Please let me know if I should change this!
*/
// This is a function that calculates the Coefficient of Thrust
float get_CT(ALTAIR_state* curr_state)
{
	float J = get_J(curr_state);
	float linear_CT_interp = 0.0881;								//linear interpolation for approximation of C_t

	if (J >= 0 && J <= 0.7)											//sanity check
	{
		float C_t = -(linear_CT_interp / 0.7)*J + linear_CT_interp;	//linear interpolation using above
		return C_t;
	}

	return 0;

}

// This function would give the thrust due to one propeller in action 
float get_thrust(ALTAIR_state* curr_state, float rho /* take from get_density */) // inherited from struct in run_model.c- may need bug fixes when ALTAIR_state is complete
{
	float Thrust_prop, C_t;
	float J = get_J(curr_state);
	float C_t = get_CT(J);
	
	float curr_RPM = *curr_state->RPM;								//get values from ALTAIR_state
	float curr_diameter = *curr_diameter->diameter;

	Thrust_prop = C_t * rho*pow(curr_RPM, 2)*pow(curr_diameter, 4);	//calculation of thrust per model
	return Thrust_prop;
}