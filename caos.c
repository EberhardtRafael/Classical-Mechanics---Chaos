#include<stdio.h>
#include<stdlib.h>
#include<math.h>
#include "helper.h"

#define PI 3.14159265359
#define A 0.13
#define B 0.21
#define C 6.5
#define dT 0.01

// Function to compute next step of Rössler attractor
void rossler_step(double *x, double *y, double *z, int i) {
    x[i+1] = x[i] + dT * (-y[i] - z[i]);
    y[i+1] = y[i] + dT * (x[i] + A*y[i]);
    z[i+1] = z[i] + dT * (B + z[i]*(x[i] - C));
}

int main(){

    int numsteps = 100000;
    double x[numsteps], y[numsteps], z[numsteps];

    // Initial conditions
    x[0] = 0.0;
    y[0] = 0.0;
    z[0] = 0.0;

    char outputFile[] = "rossler.dat";
    char gnuplotFile[] = "plot_rossler.gp";
    char gnuplotOutput[] = "rossler.png";

    FILE *fp = fopen(outputFile, "w");
    if (!fp) { printf("Error opening file\n"); return 1; }

    for(int i = 0; i < numsteps-1; i++) {
        rossler_step(x, y, z, i);
    }

    for(int i = 0; i < numsteps - 1; i++) {
        fprintf(fp, "%f %f %f\n", x[i], y[i], z[i]);
    }
    fclose(fp);

    generate_gnuplot_script(outputFile, gnuplotOutput);

    printf("Data saved to rossler.dat and Gnuplot script %s generated.\n", gnuplotFile);
    printf("Run: gnuplot %s to create %s\n", gnuplotFile, gnuplotOutput);

    return 0;
}
