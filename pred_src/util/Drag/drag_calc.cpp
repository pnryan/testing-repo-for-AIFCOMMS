//This file is meant to calculate the drag experienced by ALTRAIR 
//given the density of surrounding air, the current velocity, a drag coefficient, and 
//the balloon radius


// for now the drag coefficient will likely have to be a constant estimated value until
//experiments can be done in a wind tunnel or otherwise to determine a better value for
//both the balloon and the payload. 


#define pi 3.14159265359

//Cd for a balloon will for the time being be approximated as 0.47, this ultimately should be 
//determined experimentally and modified accordingly however for the time being this should serve
//as an appropriate approximation. 

float sphere_drag(float &Cd, float &rho, float &V, float &R){
	
	//define reference area for drag calculation on a sphere. This is just the cross sectional area
	A = pi*R*R;
	
	drag = Cd*.5*rho*V*V*A;
	return drag;
}


//Cd for the rectangular prism will for the time being be approximated as 1.28 which is the 
//Cd for a flat plate according to https://www.grc.nasa.gov/www/k-12/airplane/shaped.html
float rectangular_prism_drag(float &Cd, float &rho, float &V, float &L, float &W, float &H){
	
	// define reference drag area for calculation on a rectangular prism
	A = W*H;
	
	drag = Cd*.5*rho*V*V*A;
	return drag;
}