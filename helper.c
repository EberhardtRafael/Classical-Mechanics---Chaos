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

void generate_gnuplot_script(const char *datafile, const char *output_gif) {
    FILE *gp = fopen("plot_rossler.gp", "w");
    if (!gp) {
        printf("Error creating Gnuplot script\n");
        return;
    }

    fprintf(gp,
        "set terminal pngcairo size 800,600 enhanced\n"
        "set output '%s'\n"
        "set grid\n\n"
        "set xlabel 'X'\n"
        "set ylabel 'Y'\n"
        "set zlabel 'Z'\n"
        "set view 50, 300\n"
        "set ticslevel 0\n"
        "splot '%s' using 1:2:3 with lines lw 2 lc rgb 'blue';\n",
        output_gif, datafile
    );

    fclose(gp);
}
