#include <math.h>
#include <stdio.h>
#include <stdlib.h>

#include "thrustMomTransMethod.hh"

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


float mom_trans_thrust(float alt, float RPM ,float rho,float pitch, float diameter, float f_vel)
{
	float Thrust_prop,a;

	float rpm_eff = get_rpm(RPM, alt);       // effective rpm
	a = (rpm_eff*0.0254*pitch/60); // Comes below in the equation of thrust
	Thrust_prop = 1.225*rho*(M_PI/(0.0254*diameter))*(pow(a,2) - a*f_vel)*pow(diameter/(3.29546*pitch),1.5);
	return Thrust_prop;
}