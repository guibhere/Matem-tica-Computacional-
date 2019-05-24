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
  break;
  case(7):
  F= (pow(X,5)) -(2*X) -1;
  break;
  case(8):
  F= sqrt(X) +(-5*exp(-X));
  break;  }


 return(F);
}

 double DFUN (double X,int op){
 double F;

 switch(op){
  case (1):
  F=3*(X*X) -9;
  break;
  case (2):
  F=2*X;
  break;
  case (3):
  F=6*(X*X) + sin(X+1);
  break;
  case (4):
  F=((0.15*X -0.8)*X) + (3*sin(X)) +(3*(X*(cos(X))));
  break;
  case(5):
  F= 6*X*(X+1) - exp(X);
  break;
  case(6):
  F=  2*((6*X*X) + (6*X) -13);
  break;}

 return(F);
 }

int FUNMENU(){
 int op;
printf("\nQual função deseja encontrar a raiz:\n");
printf("1) X = (9x-3)^1/3\n");
printf("2) X^2 - 10 = 0\n");
printf("3) 2X^3 - cos(X+1) – 3 = 0\n");
printf("4) 0.05X^3 – 0.4X^2 + 3*sen(X)*X = 0\n");
printf("5) 2X^3 + 3X^2 -e^x +3 = 0\n");
printf("6) 4X^3 + 6X^2 -26X -14 = 0\n");
printf("7) X^5 -2X -1 =0\n");
printf("8) sqrt(X) -5e^(-x) =0\n");
scanf("%d",&op);
return(op);}



void BIS(){
  int i,Imax,op1,op;
double a,b,e,E,Fa,Fb,x,Fx,D;

op=FUNMENU();
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

while((i<=Imax)){

  if(Fx<0)
  D=Fx*-1;
 else
  D=Fx;




 x=(a+b)/2;
 Fx=FUN(x,op);

 printf("\nI : %d\n",i);
 printf("|   a:%.4lf  |   b:%.4lf   |   x:%.4lf |\n",a,b,x);
 printf("|F(a):%.4lf  |F(b):%.4lf   |F(x):%.4lf |\n",Fa,Fb,Fx);
 printf("Erro :%.4lf\n",E);
 if((E<e)&&(D<e))
    break;


  E=E/2;



 if(Fa*Fx>0){
   a=x;
   Fa=Fx;}
 else{
    b=x;
    Fb=Fx;}

i++;

}
printf("\n X=%.4lf //F(%.4lf) = %.4lf\n",x,x,Fx);
system("pause");
system("cls");
MENU();
}

void RAPH(){
 int i,Imax,op;
double a,b,e,E,Fa,Fb,x,Fx,D,Dx;

op=FUNMENU();

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
system("pause");
system("cls");
MENU();
}

void SECA(){
int i,Imax,op1,op;
double a,b,e,Fa,Fb,x,Fx,D,E=100,aux;

op=FUNMENU();

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
system("pause");
system("cls");
MENU();
}

void MENU(){
int(op);

printf("Qual Metodo deseja utilizar ?\n");
printf("1)- MÉTODO da BISSEÇÂO\n");
printf("2)- MÉTODO de NEWTON-RAPHSON\n");
printf("3)- MÉTODO da SECANTE\n");
printf("4)- SAIR\n");
scanf("%d",&op);
system("cls");
switch(op){
case(1):
    printf("*****************  Método da BISSEÇÂO  **************************");
    BIS();
    break;
case(2):
    printf("*****************  Método de NEWTON RAPHSON  **************************");
    RAPH();
    break;
case(3):
    printf("*****************  Método da SECANTE  **************************");
    SECA();
    break;
case(4):
    break;
}}

main () {
setlocale(LC_ALL, "Portuguese");
 MENU();
}
