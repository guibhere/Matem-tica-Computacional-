#include<stdio.h>
#include<string.h>
#include<math.h>
#include<stdlib.h>


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
  break;}


 return(F);
}



main () {
int i,Imax,op1,op;
double a,b,e,E,Fa,Fb,x,Fx;


printf("Qual Metodo deseja utilizar ? ");
printf("1)- BISSEÇÂO\n");
printf("2)- RAPHSON\n");
printf("3)- .....\n");
scanf("%d",&op1);




printf("\nQual função deseja encontrar a raiz:\n");
printf("1) X = (9x-3)^1/3\n");
printf("2) X^2 - 10 = 0\n");
printf("3) 2X^3 - cos(X+1) – 3 = 0\n");
printf("4) 0.05X^3 – 0.4X^2 + 3*sen(X)*X = 0\n");
scanf("%d",&op);

printf("Insira os limites : ");
scanf("%lf %lf",&a,&b);
printf("\nInsira limite de iterações : ");
scanf("%d",&Imax);
printf("\nInsira a tolerancia : ");
scanf("%lf",&e);

Fa=FUN(a,op);
Fb=FUN(b,op);
E=(b-a)/2;
i=0;

while((E>e)&&(i<=Imax)){


 x=(a+b)/2;
 Fx=FUN(x,op);

 printf("\nI : %d\n",i);
 printf("|   a:%.4lf  |   b:%.4lf   |   x:%.4lf |\n",a,b,x);
 printf("|F(a):%.4lf  |F(b):%.4lf   |F(x):%.4lf |\n",Fa,Fb,Fx);
 printf("Erro :%.4lf\n",E);
 if(Fa*Fx>0){
   a=x;
   Fa=Fx;}
 else{
    b=x;
    Fb=Fx;}

    E=E/2;
    i++;
}
printf("\n X=%.4lf //F(%.4lf) = %.4lf\n",x,x,Fx);
}



