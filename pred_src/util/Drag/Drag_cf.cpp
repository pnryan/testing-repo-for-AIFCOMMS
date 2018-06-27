// Source -> http://pages.mtu.edu/~fmorriso/DataCorrelationForSphereDrag2016.pdf
<<<<<<< HEAD

#include "Sphere_drag.h" 
// The purpose of this function is to give the value of Cd corresponding to a particular height and Reynold's number
#define pi 3.14159265359


float get_drag_cf(float h, float vel, float D) // D is the diameter of the balloon
{
    //float h = 5000, vel = 21.50, D =6.8;
    //Diameter I'm gonna use PV = nRT and gas as H2 and initial volume as 164.6362(not 8812.17) m^3
    //P = rho*(R/M_air)*T and P*V = m*(R/M_H2)*T  and assuming P & T equilibrium
    //always we get V2 = (T2/P2)(P1*V1/T1)
    //P1 = 1.014009e5 Pa     T1 = 288.14K      V1 = 8812.17 m^3
    // Wetted area in drag eq = pi*r*r.........D = 0.5*rho*v*v*S*Cd

    //Re = rho_nui.*vel*D;
    // We could ideally combine the get_density and get_drag functions as both of them are really similar and this is unwanted repetition
    float t=0.f, T=0.f, nui=0.f, p=0.f, rho_nui=0.f, V=0.f, r=0.f, S=0.f, Re=0.f, c=0.f;
    c = 101.4009*164.6362/288.14; // c = (P1*V1/T1)  We could probably define this inside the main ALTAIR struct

        if (h>25000)
        {
           t = -131.21 + 0.00299*h;
           T = 273.1 + t;
           nui = (1.458e-6*sqrt(T))/(1+110.4/T);
           p = 2.488*(T/216.6)-11.388;
           rho_nui = (p/(0.2869*T))/nui;    // Density/viscosity    
           V = (T/p)*c;
           r = pow((0.75*V/pi),(1/3));
           S = pi*r*r;
           Re= rho_nui*vel*2*r;
        }
        else if (h<=25000 && h>11000)
        {
           t = -56.46;
           T = 273.1 + t;
           nui = (1.458e-6*sqrt(T))/(1+110.4/T);
           p =22.65*exp(1.73 - 0.000157*h);
           rho_nui = (p/(0.2869*T))/nui;
           V = (T/p)*c;
           r = pow((0.75*V/pi),(1/3));
           S = pi*r*r;
           Re = rho_nui*vel*2*r;
        }
        else
        {
           t = 15.04 - 0.00649*h;
           T = 273.1 + t;
           nui = (1.458e-6*sqrt(T))/(1+110.4/T);
           p = 101.29*pow(T/288.08,5.256);
           rho_nui = (p/(0.2869*T))/nui;
           V = (T/p)*c;
           r = pow((0.75*V/pi),(1/3));
           S = pi*r*r;
           Re = rho_nui*vel*2*r;
        }


    double Cd_sphere = 24/Re + 2.6*(Re/5)/(1+pow((Re/5),1.52)) + 0.411*pow(Re/2.63e5,-7.94)/(1+pow(Re/2.63e5,-8)) + 0.25*(Re/1e6)/(1+(Re/1e6));
    // From curve fitting
    double Cd_rec = 2.05;
    // Could not get a good value.
        
    //cout<<"Cd = "<<Cd; 
    //Return 1;

    return (Cd_sphere+Cd_rec);
}
