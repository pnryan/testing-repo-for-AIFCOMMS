#ifndef THRUST_FORMULA_INCLUDE
#define THRUST_FORMULA_INCLUDE

float get_rpm(float &rpm , float &h);


float get_thrust(float h, float vel, float rpm , float Dia ,float pitch ,float rho /* take from get_density */ );


#endif


