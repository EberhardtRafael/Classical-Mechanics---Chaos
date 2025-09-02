#ifndef HELPER_H
#define HELPER_H

void generate_gnuplot_script(const char *datafile, const char *output_gif);
void generate_gnuplot_gif_script(const char *datafile, const char *output_gif, int numframes, int total_points);

#endif