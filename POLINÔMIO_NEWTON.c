#include<stdio.h>
#include<string.h>
#include<math.h>
#include<stdlib.h>
#include<locale.h>
#define TRUE 0
#define FALSE 1

typedef struct{
double x,y;
}Pontos;


main () {
setlocale(LC_ALL, "Portuguese");
int i,j,k,n;
double D[99],X,Po;
Pontos P[99];


printf("Numero de Pontos para a Interpolação : ");
scanf("%d",&n);
printf("\n");

for(i=0;i<n;i++){
  printf("Insira P[%d] : ",i+1);
  scanf("%lf %lf",&P[i].x,&P[i].y);
  printf("\n P[%d] : (%.2lf ; %.2lf )\n",i+1,P[i].x,P[i].y);
  D[i]=P[i].y;
}

printf("Insira o X a ser interpolado : ");
scanf("%lf",&X);


for(i=0;i<n-1;i++){

        for(j=n-1;j>i;j--){
         D[j]=(D[j]-D[j-1])/(P[j].x - P[j-(i+1)].x);

        printf("D[%d] = %.4lf \n",j+1,D[j]);
        }}

 Po=D[n-1];

 for(i=n-2;i>=0;i--){


   Po= Po*(X-P[i].x) +D[i];
 }

 printf("P(%.2lf) = %.4lf\n",X,Po);

}





























