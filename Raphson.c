#include<stdio.h>
#include<string.h>
#include<math.h>
#include<stdlib.h>


double FUN (double X,int op){
 double F;
 //F= (X*X) +X -6;
 F=(X*X*X) -9*X +3;
 return(F);
}



 double DFUN (double X,int op){
 double F;
 //F = 2*X +1;
 F=3*(X*X) -9;
 return(F);
 }


main () {
int i,Imax,op;
double a,b,e,E,Fa,Fb,x,Fx,D,Dx;

printf("Insira X(0): ");
scanf("%lf",&x);
printf("\nInsira limite de iterações : ");
scanf("%d",&Imax);
printf("\nInsira a tolerancia : ");
scanf("%lf",&e);


Fx=FUN(x,op);
Dx=DFUN(x,op);
D=Fx/Dx;

if(D<0)
    E=D*-1;
else
    E=D;

printf(" F(X)= %.4lf // D(X)= %.4lf // E= %.4lf \n",Fx,Dx,E);

i=0;

while((E>e)&&(i<=Imax)){

         if(D<0)
    E=D*-1;
else
    E=D;

        i++;
    x = x - D;
    printf("X(%d) = %.4lf\n",i,x);
    Fx=FUN(x,op);
    Dx=DFUN(x,op);
    D=Fx/Dx;


    printf(" F(X)= %.4lf // D(X)= %.4lf // E= %.4lf \n",Fx,Dx,E);
}
}



