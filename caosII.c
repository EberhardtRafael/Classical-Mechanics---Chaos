#include<stdio.h>
#include<stdlib.h>
#include<math.h>

#define PI 3.14159265359
#define A 0.1
#define B 0.1
//#define C 5.7


#define dT 0.001 //Originalmente, era 0.0001 para que hpuvesse maior precisão. A animação fica muito lenta, no entanto.


int main(){


float x, y, z;
float C;

float t_ini = 0;
float t_fin = 32*PI;
float t;
//int numsteps = (int)((t_fin-t_ini)/dT);
int numsteps = 100000;
//float chave = -1.;

C = 1;

//Comandos do Gnuplot:
	//printf("set pm3d\n");
	//printf("set ticslevel 0.0\n");
	//printf("set xrange[0:10]\n");
	//printf("set yrange[-1:1]\n");
	//printf("set zrange[-10:10]\n");
	//printf("set dgrid3d 100,100\n");
	//printf("set hidden3d\n");		
        //printf("plot \'-\' u 1:2\n");
        printf("set title \"Rossler\"\n");
        printf("set xlabel \" t \" \n");
        printf("set ylabel \" z(t) \" \n");
        
        
        //printf("splot \'-\' u 1:2:3 w l title \"5.4\", \'-\' u 1:2:3 w l title \"5.5\", \'-\' u 1:2:3 w l title \"5.6\", \'-\' u 1:2:3 w l title \"5.7\", \'-\' u 1:2:3 w l title \"5.8\", \'-\' u 1:2:3 w l title \"5.9\" \n");
        printf("plot \'-\' u 1:2 ls 1, \'-\' u 1:2 ls 1, \'-\' u 1:2 ls 1,\'-\' u 1:2 ls 1,\'-\' u 1:2 ls 1, \'-\' u 1:2 ls 1, \'-\' u 1:2 ls 1, \'-\' u 1:2 ls 1, \'-\' u 1:2 ls 1, \'-\' u 1:2 ls 1\n");
         
for(int j = 0; j < 10; j++){
x = -1;
y = 0;
z = 0;
t = 0;    
    
    for(int i = 0; i < numsteps; i++){
    
    //printf("splot \'-\' u 1:2:3 w p \n");     
    //printf("%lf %lf %lf\n", x, y, z);
    //printf("e\n");
    //printf("pause 0.1");   
    
        printf("%f %lf\n", C,  z);
    
        x+= dT*(-y - z);
        y+= dT*(x + A*y);
        z+= dT*(B + z*(x - C));   
        t += dT;
  
    } 
C += 0.1;
printf("e\n");

}	

printf("plot \'-\' u 1:2 ls 1, \'-\' u 1:2 ls 1, \'-\' u 1:2 ls 1,\'-\' u 1:2 ls 1,\'-\' u 1:2 ls 1, \'-\' u 1:2 ls 1, \'-\' u 1:2 ls 1, \'-\' u 1:2 ls 1, \'-\' u 1:2 ls 1, \'-\' u 1:2 ls 1\n");
         
for(int j = 0; j < 10; j++){
x = -1;
y = 0;
z = 0;
t = 0;    
    
    for(int i = 0; i < numsteps; i++){
    
    //printf("splot \'-\' u 1:2:3 w p \n");     
    //printf("%lf %lf %lf\n", x, y, z);
    //printf("e\n");
    //printf("pause 0.1");   
    
        printf("%f %lf\n", C,  z);
    
        x+= dT*(-y - z);
        y+= dT*(x + A*y);
        z+= dT*(B + z*(x - C));   
        t += dT;
  
    } 
C += 0.1;
printf("e\n");

}	

printf("plot \'-\' u 1:2 ls 1, \'-\' u 1:2 ls 1, \'-\' u 1:2 ls 1,\'-\' u 1:2 ls 1,\'-\' u 1:2 ls 1, \'-\' u 1:2 ls 1, \'-\' u 1:2 ls 1, \'-\' u 1:2 ls 1, \'-\' u 1:2 ls 1, \'-\' u 1:2 ls 1\n");
         
for(int j = 0; j < 10; j++){
x = -1;
y = 0;
z = 0;
t = 0;    
    
    for(int i = 0; i < numsteps; i++){
    
    //printf("splot \'-\' u 1:2:3 w p \n");     
    //printf("%lf %lf %lf\n", x, y, z);
    //printf("e\n");
    //printf("pause 0.1");   
    
        printf("%f %lf\n", C,  z);
    
        x+= dT*(-y - z);
        y+= dT*(x + A*y);
        z+= dT*(B + z*(x - C));   
        t += dT;
  
    } 
C += 0.1;
printf("e\n");

}	


/*
C = 14;

x = -1;
y = 0;
z = 0;
t = 0;
    
    
   
    for(int i = 0; i < numsteps; i++){
    
      
        printf("%f %lf\n", t,  y);
    
        x+= dT*(-y - z);
        y+= dT*(x + A*y);
        z+= dT*(B + z*(x - C));   
        t += dT;
  
    } 	
    
printf("e\n");	


C = 0;

x = -1;
y = 0;
z = 0;
t = 0;
    
    
    
    for(int i = 0; i < numsteps; i++){
    
      
        printf("%f %lf\n", t,  y);
    
        x+= dT*(-y - z);
        y+= dT*(x + A*y);
        z+= dT*(B + z*(x - C));   
        t += dT;
  
    } 	
    
printf("e\n");	

*/
/*
printf("set term png\n");
printf("set output \"rosszII.png\"\n");
printf("replot\n");
*/
printf("pause -1");

return 0;
}
