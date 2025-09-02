#include<stdio.h>
#include<stdlib.h>
#include<math.h>
#include "helper.h"

#define PI 3.14159265359
#define A 0.13
#define B 0.21
#define C 6.5
#define dT 0.01

// Computes next step of Rössler attractor
void rossler_step(double *x, double *y, double *z, int i) {
    x[i+1] = x[i] + dT * (-y[i] - z[i]);
    y[i+1] = y[i] + dT * (x[i] + A*y[i]);
    z[i+1] = z[i] + dT * (B + z[i]*(x[i] - C));
}

void run_trajectory(double x0, double y0, double z0, int numsteps, const char* filename) {
    double x[numsteps], y[numsteps], z[numsteps];

    x[0] = x0;
    y[0] = y0;
    z[0] = z0;

    // Integrates the whole trajectory
    for(int i = 0; i < numsteps-1; i++) {
        rossler_step(x, y, z, i);
    }

    FILE *fp = fopen(filename, "w");
    if (!fp) { 
        printf("Error opening file %s\n", filename); 
        return; 
    }

    for(int i = 0; i < numsteps; i++) {
        fprintf(fp, "%f %f %f\n", x[i], y[i], z[i]);
    }

    fclose(fp);
}

int main(){

    int numsteps = 10000;
    double x[numsteps], y[numsteps], z[numsteps];

    run_trajectory(0.0, 0.0, 0.0, numsteps, "rosslerA.dat");    // Trajectory A
    run_trajectory(0.01, 0.0, 0.0, numsteps, "rosslerB.dat"); // Trajectory B with tiny initial condition difference
    run_trajectory(0.1, 0.01, 0.01, numsteps, "rosslerC.dat"); // Trajectory C with a little more spressive initial condition difference

    generate_gnuplot_script("rosslerA.dat", "rosslerB.dat", "rosslerC.dat", "rossler.png");

    printf("Data saved and Gnuplot script generated.\n");

    return 0;
}
