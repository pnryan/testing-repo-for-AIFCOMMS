// Have to change variable names and look after proper inheritance
// We need to inherit forward velocity,rate of revolution,diameter,density in SI Units
 
// rho is assumed to be value after density correction
   
// This function would give the thrust due to one propeller in action 

#define pi 3.14159265359

float get_rpm(float &rpm , float &h)
{
    // Here also I thought we could fit a curve instead of interpolation
    // A cubic was fit to get the curve of rpm_factor and altitude from matlab after digitizing the plot
    // k_factor = a + b*x + c*x^2 + d*x^3
    // a = 1.395    b= 0.3246   c= 0.05041  d= 0.006461
    // k_factor = 1.395 + 0.3246*h + 0.05041*pow(h,2) + 0.006461*pow(h,3);
    // rpm_eff = rpm/k_factor
    return rpm/(1.395 + 0.3246*h + 0.05041*pow(h,2) + 0.006461*pow(h,3));

}


float get_thrust(float h, float vel, float rpm , float Dia ,float pitch ,float rho /* take from get_density */ ) // Probably could be inherited from a struct. 
                                                                                                                 // Change it later if so!
{

float Thrust_prop,a;
rpm_eff = get_rpm(rpm,h);       // efeective rpm
a = (rpm_eff*0.0254*pitch/60); // Comes below in the equation of thrust
Thrust_prop = rho*(pi/(0.0254*Dia))*(pow(a,2) - pow(a,1)*vel)*pow(Dia/(3.29546*pitch),1.5);
return Thrust_prop;
}