#include<stdio.h>
#include<string.h>
#include<math.h>
#include<stdlib.h>
#include<locale.h>

double FUN (double X,int op){
 double F;

 switch(op){
  case(1):
  F = pow(X,3) - (9*X) +3;
  break;
  case(2):
  F= pow(X,2) - 10;
  break;
  case(3):
  F= (2*pow(X,3)) - cos(X+1) - 3;
  break;
  case(4):
  F= (0.05*pow(X,3)) - (0.4*pow(X,2)) + (3*sin(X)*X);
  break;
  case(5):
  F= 2*(X*X*X) +3*(X*X) -(exp(X)) + 3;
  break;
  case(6):
  F= (4*X*X*X) + (6*X*X) - (26*X) -14;
  break;  }

return(F);}





main () {
int i,Imax,op1,op;
double a,b,e,Fa,Fb,x,Fx,D,E=100,aux;


printf("\nQual função deseja encontrar a raiz:\n");
printf("1) X = (9x-3)^1/3\n");
printf("2) X^2 - 10 = 0\n");
printf("3) 2X^3 - cos(X+1) – 3 = 0\n");
printf("4) 0.05X^3 – 0.4X^2 + 3*sen(X)*X = 0\n");
printf("5) 2X^3 + 3X^2 -e^x +3 = 0\n");
printf("6) 4X^3 + 6X^2 -26X -14 = 0\n");
scanf("%d",&op);
printf("Insira os limites : ");
scanf("%lf %lf",&a,&b);
printf("\nInsira limite de iterações : ");
scanf("%d",&Imax);
printf("\nInsira a tolerancia : ");
scanf("%lf",&e);

Fa=FUN(a,op);
Fb=FUN(b,op);
i=0;

if((abs(Fa))<(abs(Fb))){
      aux=a;
      a=b;
      b=aux;
      aux=Fa;
      Fa=Fb;
      Fb=aux;
}
x=b;
Fx=Fb;
printf("\n||i:%d ||a:%.4lf ||b:%.4lf ||x:%.4lf ||Fa:%.4lf ||Fb:%.4lf ||Fx:%.4lf ||Dx:------\n",i,a,b,x,Fa,Fb,Fx);




while((E>e)&&(i<=Imax)){
 i++;

 D = -((Fx/(Fb-Fa))*(b-a));
 x= x + D;
 Fx=FUN(x,op);




printf("||i:%d ||a:%.4lf ||b:%.4lf ||x:%.4lf ||Fa:%.4lf ||Fb:%.4lf ||Fx:%.4lf ||Dx:%.4lf\n",i,a,b,x,Fa,Fb,Fx,D);
if(D<0)
    E=D*-1;
else
    E=D;

 a=b;
 b=x;
 Fa=Fb;
 Fb=Fx;
}
}

