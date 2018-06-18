// Have to change variable names and look after proper inheritance
// We need to inherit forward velocity,rate of revolution,diameter,density in SI Units
 
/* Herein get_CT, given that it is a very approximate analysis we are doing, I came up with a simple linear expression for C_t.
     From the plot it was evident that C_t tends to be more and more linear as we.... 
     move towards a smaller pitch/diameter ratio.
     Hence I just came up with a linear equation for the situation considering two power law equations for x and y intersects...
     That is I came up with two regression models for the intersections and just got the equation of the line connecting them  
     I thought this was better than interpolation for now. Please let me know if I should change this!
*/ 
// This is a function that calculates the Coefficient of Thrust
float get_CT(float &J)
{
    //float a = 0.0881; // Declare in global scope later
    // float C_t = (-a/0.7)*J + a;
    // return C_t;
    // OR
    //return ( (-a/0.7)*J + a );
    // OR
    
/*
    if (J>=0 && J<=0.7)
    return ( (-0.0881/0.7)*J + 0.0881 );
    else
    return 0;
*/
return 0.25*(1+copysign(1.0, J))*(1-copysign(1.0, (J-0.7))*( (-0.0881/0.7)*J + 0.0881 );
}
   
// This function would give the thrust due to one propeller in action 
float get_thrust(float h, float vel, float rpm , float Dia ,float rho /* take from get_density */ ) // Probably could be inherited from a struct. 
                                                                                                   // Change it later if so!
{

float J; // non_dimensionalised velocity
float Thrust_prop,C_t;
J = vel/(rpm*Dia);                                 //  here vel is forward velocity i.e relative axial velocity to undisturbed flow 
C_t = get_CT(J);
Thrust_prop = C_t*rho*pow(rpm,2)*pow(Dia,4);
return Thrust_prop;
}
