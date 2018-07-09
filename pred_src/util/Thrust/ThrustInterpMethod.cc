#include <math.h>
#include <stdio.h>
#include <stdlib.h>

#include "thrustInterpMethod.hh"


float get_J(float RPM, float f_vel, float diameter)
{	
	float ang_freq = RPM * M_PI / 30;					//turn RPM into radians/s
	float J = f_vel / (ang_freq*diameter);				//get dimensionless velocity

	return J;
}



float get_CT(float J,)
{
	float linear_CT_interp = 0.0881;								//linear interpolation for approximation of C_t

	if (J >= 0 && J <= 0.7)											//sanity check
	{
		float C_t = -(linear_CT_interp / 0.7)*J + linear_CT_interp;	//linear interpolation using above
		return C_t;
	}

	return 0;
}




float interp_thrust(float rho, float RPM, float f_vel, float diameter) // inherited from struct in run_model.c- may need bug fixes when ALTAIR_state is complete
{
	float Thrust_prop, C_t;
	float J = get_J(RPM, f_vel, diameter);
	float C_t = get_CT(J);
	
	float curr_RPM = *curr_state->RPM;								//get values from ALTAIR_state
	float curr_diameter = *curr_diameter->diameter;

	Thrust_prop = C_t * rho*pow(curr_RPM, 2)*pow(curr_diameter, 4);	//calculation of thrust per model
	return Thrust_prop;
}
