#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<math.h>


typedef struct{
double X,Y;
}Pares;


double Fun(double X,double Y, int op){
double F;
switch(op){
case(1):
    F= 2*X -2;
    break;
case(2):
F = X -2*Y +1;
    break;
case(3):
F= -Y + X +2;
break;
case(4):
F = cos(X);
break;
}

return(F);


}



main () {

double a,b,h;
int i , op=0,aux, m;
Pares P[99];
menu:
printf("Selecione a EDO que será resolvida :\n");
printf("1)- (dy/dx) = 2X -2\n");
printf("2)- (dy/dx) = X -2Y +1\n");
printf("3)- (dy/dx) = -Y + X +2\n");
printf("4)- (dy/dx) = cos(X)\n");
scanf("%d",&op);

if((op<=0)||(op>4)){
 printf("Opção Invalida !\n");
 system("cls");
 goto menu;   }

printf("Insira o m : ");
scanf("%d",&m);
printf("\nInsira os limites : ");
scanf("%lf %lf",&a,&b);
printf("Insira Y inicial : ");
scanf("%lf",&P[0].Y);

P[0].X=a;
h=(b-a)/m;


for(i=1;i<=m;i++){
 P[i].X = P[i-1].X + h;
 //printf("X = %.4lf \n",P[i].X);

 P[i].Y = P[i-1].Y + (h*Fun(P[i-1].X,P[i-1].Y,op));
 printf("Y = %.4lf \n",P[i].Y);
}


printf("Y(%.0lf) = %.4lf \n",b,P[m].Y);
}




