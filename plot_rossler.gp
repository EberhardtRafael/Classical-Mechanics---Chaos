set terminal pngcairo size 800,600 enhanced
set output 'rossler.png'
set grid

set xlabel 'X'
set ylabel 'Y'
set zlabel 'Z'
set view 50, 300
set ticslevel 0
splot 'rosslerA.dat' using 1:2:3 with lines lc rgb 'red' title 'Trajectory A: x0 = 0.00, y0 = 0.00, z0 = 0.00','rosslerB.dat' using 1:2:3 with lines lc rgb 'blue' title 'Trajectory B: x0 = 0.01, y0 = 0.00, z0 = 0.00','rosslerC.dat' using 1:2:3 with lines lc rgb 'green' title 'Trajectory C: x0 = 0.10, y0 = 0.01, z0 = 0.01'
