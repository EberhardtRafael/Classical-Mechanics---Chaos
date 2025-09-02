#include <stdio.h>
#include "helper.h"

// Function to generate Gnuplot script
void generate_gnuplot_gif_script(const char *datafile, const char *output_gif, int numframes, int total_points) {
    FILE *gp = fopen("plot_rossler.gp", "w");
    if (!gp) {
        printf("Error creating Gnuplot script\n");
        return;
    }

    fprintf(gp,
        "set terminal gif animate delay 5 optimize size 800,600\n"
        "set output '%s'\n"
        "set view 60, 30\n"
        "set ticslevel 0\n"
        "set grid\n\n"
        "do for [i=1:%d] {\n"
        "   last = int(i * %d / %d);\n"
        "   if (last < 1){\n"
        "     last = 1;\n"
        "   }\n"
        "   splot '%s' using 1:2:3 every ::0::last with lines lw 2 lc rgb 'blue';\n"
        "}\n",
        output_gif, numframes, total_points, numframes, datafile
    );

    fclose(gp);
}

Vec3 get_initial_conditions(const char *datafile) {
    Vec3 v = {0,0,0};
    FILE *fp = fopen(datafile, "r");
    if (!fp) return v;

    char line[128];
    if (fgets(line, sizeof(line), fp)) {
        sscanf(line, "%lf %lf %lf", &v.x, &v.y, &v.z);
    }

    fclose(fp);
    return v;
}

void generate_gnuplot_script(const char *datafileA, const char *datafileB, const char *datafileC, const char *output) {
    FILE *gp = fopen("plot_rossler.gp", "w");
    if (!gp) {
        printf("Error creating Gnuplot script\n");
        return;
    }

    Vec3 icA = get_initial_conditions(datafileA);
    Vec3 icB = get_initial_conditions(datafileB);
    Vec3 icC = get_initial_conditions(datafileC);

    fprintf(gp,
        "set terminal pngcairo size 800,600 enhanced\n"
        "set output '%s'\n"
        "set grid\n\n"
        "set xlabel 'X'\n"
        "set ylabel 'Y'\n"
        "set zlabel 'Z'\n"
        "set view 50, 300\n"
        "set ticslevel 0\n"
        "splot '%s' using 1:2:3 with lines lc rgb 'red' title 'Trajectory A: x0 = %.2f, y0 = %.2f, z0 = %.2f',"
        "'%s' using 1:2:3 with lines lc rgb 'blue' title 'Trajectory B: x0 = %.2f, y0 = %.2f, z0 = %.2f',"
        "'%s' using 1:2:3 with lines lc rgb 'green' title 'Trajectory C: x0 = %.2f, y0 = %.2f, z0 = %.2f'\n",
        output, datafileA, icA.x, icA.y, icA.z, datafileB, icB.x, icB.y, icB.z, datafileC, icC.x, icC.y, icC.z
    );

    fclose(gp);
}
