#ifndef HELPER_H
#define HELPER_H

// Array of size 3
typedef struct {
    double x;
    double y;
    double z;
} Vec3;

Vec3 get_initial_conditions(const char *datafile);
void generate_gnuplot_script(const char *datafileA, const char *datafileB, const char *datafileC, const char *output_gif);
void generate_gnuplot_gif_script(const char *datafile, const char *output_gif, int numframes, int total_points);

#endif