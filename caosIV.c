#include<stdio.h>
#include<stdlib.h>
#include<math.h>

#define PI 3.14159265359
#define A 0.2
#define B 0.2
//#define C 5.7


#define dT 0.0001 //Originalmente, era 0.0001 para que hpuvesse maior precisão. A animação fica muito lenta, no entanto.

 



/*
attractorp[0] = (c - discriminante)/2;
attractorp[1] = -(c - discriminante)/2*A;
attractorp[1] = (c - discriminante)/2*A;
printf("%f %f %f",attractorm[0], attractorm[1], attractorm[2]);
*/
}

int main(){


float x, y, z;
float C;

float t_ini = 0;
float t_fin = 32*PI;
float t;
int numsteps = (int)((t_fin-t_ini)/dT);
//int numsteps = 1000;


C = 0;
z = 0;

        
        printf("set title \"Rossler\"\n");
        printf("set xlabel \" t \" \n");
        printf("set ylabel \" z(t) \" \n");
        
       
       printf("plot \'-\' u 1:2 w l title \"z(t); a = b = 0.2, c = 5.7; z(0) = 0\", \'-\' u 1:2 w l title \"z(t); a = b = 0.2, c = 5.7; z(0) = 1\", \'-\' u 1:2 w l title \"z(t); a = b = 0.2, c = 5.7; z(0) = 2\"\n");
         
for(int j = 0; j < 3; j++){

y = 0;
x = -1;
t = 0;
    
    
    
    for(int i = 0; i < numsteps; i++){
    
    //printf("splot \'-\' u 1:2:3 w p \n");     
    //printf("%lf %lf %lf\n", x, y, z);
    //printf("e\n");
    //printf("pause 0.1");   
    
        printf("%f %lf\n", t,  x);
    
        x+= dT*(-y - z);
        y+= dT*(x + A*y);
        z+= dT*(B + z*(x - C));   
        t += dT;
  
    } 
        	
    

z += 1;
printf("e\n");

}	

/*
printf("set term png\n");
printf("set output \"rossz0II.png\"\n");
printf("replot\n");
*/
printf("pause -1");

return 0;
}
