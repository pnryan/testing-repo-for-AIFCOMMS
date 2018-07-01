// Have to change variable names and look after proper inheritance
// We need to inherit forward velocity,rate of revolution,diameter,density in SI Units
 
// rho is assumed to be value after density correction
   
// This function would give the thrust due to one propeller in action 
#include <iostream>
#include "Thrust_formula.h"
#define pi 3.14159265359


#include <math.h>
#include <stdio.h>
#include <stdlib.h>
#include <assert.h>


#include "../../altitude.h"
#include "../../run_model.h"  

float get_rpm(float &rpm , float &alt)
{
    // Here also I thought we could fit a curve instead of interpolation
    // A cubic was fit to get the curve of rpm_factor and altitude from matlab after digitizing the plot
    // k_factor = a + b*x + c*x^2 + d*x^3
    // a = 1.395    b= 0.3246   c= 0.05041  d= 0.006461
    // k_factor = 1.395 + 0.3246*h + 0.05041*pow(h,2) + 0.006461*pow(h,3);
    // rpm_eff = rpm/k_factor
    return rpm/(1.395 + 0.3246*alt + 0.05041*pow(alt,2) + 0.006461*pow(alt,3));

}

float get_thrust(float alt, ALTAIR_state* curr_state ,float rho /* take from get_density */ )
{
	float Thrust_prop,a;
	float curr_RPM = curr_state->RPM;
	float pitch = curr_state->pitch;
	float diameter = curr_state->diameter;
	float curr_f_vel = curr_state->f_vel;

	float rpm_eff = get_rpm(curr_RPM, alt);       // effective rpm
	a = (rpm_eff*0.0254*pitch/60); // Comes below in the equation of thrust
	Thrust_prop = 1.225*rho*(M_PI/(0.0254*diameter))*(pow(a,2) - a*curr_f_vel)*pow(diameter/(3.29546*pitch),1.5);
	return Thrust_prop;
}