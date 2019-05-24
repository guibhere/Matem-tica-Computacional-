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

double a,b,h,K1,K2,K3,K4;
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
printf("\n");
for(i=1;i<=m;i++){
    P[i].X= P[i-1].X + h;
    K1= h*Fun(P[i-1].X,P[i-1].Y,op);
    K2= h*Fun((P[i-1].X+(h/2)),(P[i-1].Y + (K1/2)),op);
    K3= h*Fun((P[i-1].X+(h/2)),(P[i-1].Y + (K2/2)),op);
    K4= h*Fun((P[i-1].X+h),(P[i-1].Y + K3),op);
    P[i].Y = P[i-1].Y + (K1/6) + (K2/3) + (K3/3) + (K4/6);
    printf("K1= %.4lf \nK2= %.4lf \nK3= %.4lf\nK4= %.4lf\nY = %.4lf \n",K1,K2,K3,K4,P[i].Y);
    printf("\n");
}

printf("Y(%.0lf) = %.4lf \n",b,P[m].Y);
}


