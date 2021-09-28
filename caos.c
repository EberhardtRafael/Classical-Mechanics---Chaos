#include<stdio.h>
#include<stdlib.h>
#include<matdT.h>

#define PI 3.14159265359
#define A 0.13
#define B 0.21
#define C 6.5
#define dT 0.0001

double rossx(double *x, double *y, double *z, int nsteps){
    
    if(nsteps) x[nsteps+1] = x[nsteps] + dT*(-y - z);
    else 
    y[nsteps+1] = y[nsteps] + dT*(x + A*y);
    z[nsteps+1] = z[nsteps] + dT*(B + z*(x - C)); 
    //t += dT;
    
    return x;
}


int main(){

int numsteps = 50;
double x[numsteps, y[numsteps], z[numsteps];
float a, b, c;

float t_ini = 0;
float t_fin = 32*PI;
float t = t_ini;

//int numsteps = (int)((t_fin-t_ini)/dT);


x = 0;
y = 0;
z = 0;


for(int i = 0; i < numsteps; i++){

    printf("%f \t %lf\n",t, y);
    
   	
}


return 0;
}
