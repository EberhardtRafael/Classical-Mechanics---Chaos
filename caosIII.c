#include<stdio.h>
#include<stdlib.h>
#include<math.h>

#define PI 3.14159265359
#define A 0.2
#define B 0.2
//#define C 5.7


#define dT 0.0001 //Originalmente, era 0.0001 para que hpuvesse maior precisão. A animação fica muito lenta, no entanto.

void getAttractor(void){

float discriminante;
float c = 0;
float attractorp[3];
float attractorm[3];
    
    printf("set title \"Rossler\"\n");
    printf("set xlabel \" c \"\n");
    printf("set ylabel \" y \"\n");
    printf("set xrange[-0.01: 1.01]\n");
    printf("set yrange[-0.01: -0.21]\n");
    printf("plot \"-\" u 1:3 w l, \"-\" u 1:3 w l\n");
    
    //printf("splot \"-\" u 1:2:3\n");
    for(int i = 0; i < 100; i++){

        discriminante = sqrt(c*c - 4*A*B);

        attractorp[0] = (c + discriminante)/2.;
        attractorp[1] = (-c - discriminante)/2*A;
        attractorp[2] = (c + discriminante)/2*A;
	//printf("splot \"-\" u 1:2:3\n");
        printf("%f %f %f %f \n", c, attractorp[0], attractorp[1], attractorp[2]);
        //printf("e\n");
        //printf("pause 0.1\n");
        c += 0.01;
        }
        printf("e\n");
        
        c = 0;
    for(int i = 0; i < 100; i++){   
    
        discriminante = sqrt(c*c - 4*A*B); 
        
        attractorp[0] = (c + discriminante)/2.;
        attractorp[1] = (-c + discriminante)/2*A;
        attractorp[2] = (c + discriminante)/2*A;

        printf("%f %f %f %f \n", c, attractorm[0], attractorm[1], attractorm[2]);
        c += 0.01;
        }
        printf("e\n");
       printf("pause -1\n");
       //printf("set term png\n");
       //printf("set output \"rossattractory.png\"\n");
       //printf("replot\n"); 
}

int main(){


float x, y, z;
float C;

float t_ini = 0;
float t_fin = 32*PI;
float t;
int numsteps = (int)((t_fin-t_ini)/dT);
//int numsteps = 1000;

C = 5.7;


x = -1;
y = 0;
z = 0;
t = 0;


//getAttractor();



    printf("set title \"Rossler\"\n");
    printf("set xlabel \" x \" \n");
    printf("set ylabel \" y \" \n");
    printf("set ylabel \" y \" \n");
    printf("set xrange [-10:12] \n");
    printf("set yrange [-11:12] \n");
    printf("set zrange [0:22] \n");
    printf("set lmargin 0 \n");
    printf("set rmargin 0 \n");
    printf("set tmargin 0 \n");
    printf("set bmargin 0 \n");    
    printf("splot \'-\' u 1:2:3 w l title \"Rossler system's orbits\"\n");
    
   
    for(int i = 0; i < numsteps; i++){
    
        printf("%lf %lf %lf\n", x, y, z);
    
        x+= dT*(-y - z);
        y+= dT*(x + A*y);
        z+= dT*(B + z*(x - C));   
        t += dT;
        //C += 0.2;
  
    } 	

printf("e\n");

printf("set term png\n");
printf("set output \"ross_orbit.png\"\n");
printf("replot\n");
	
//printf("pause -1\n");	



  
 
return 0;
}
