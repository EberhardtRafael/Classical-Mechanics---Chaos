set terminal pngcairo size 800,600 enhanced
set output 'rossler.png'
set grid

set xlabel 'X'
set ylabel 'Y'
set zlabel 'Z'
set view 50, 300
set ticslevel 0
splot 'rossler.dat' using 1:2:3 with lines lw 2 lc rgb 'blue';
