#include<stdio.h>
#include<math.h>
#include<string.h>
#include<stdlib.h>
#include<locale.h>
#include "mpi.h"
#define TRUE 0
#define FALSE 1

typedef struct{
    double x,y;
}Pontos;

int main (int argc, char *argv[]) {

  setlocale(LC_ALL, "Portuguese");
  int i,j,n,p,my_rank;
  double Po,Li[99],X;
  Pontos P[99];

    MPI_Status status;
    MPI_Init(&argc,&argv);
    MPI_Comm_rank(MPI_COMM_WORLD,&my_rank);
    MPI_Comm_size(MPI_COMM_WORLD,&p);

  printf("Insira a quantidade de pontos : ");
  scanf("%d",&n);
  printf("\n");

  printf("X para a interpolação : ");
  scanf("%lf",&X);
  printf("\n");

 if(my_rank==0){
  for(i=0;i<n;i++){
   printf("Insira P[%d] : (X ; Y) \n",i+1);
   scanf("%lf %lf",&P[i].x,&P[i].y);
   printf("P[%d]: (%.4lf;%.4lf)\n",i+1,P[i].x,P[i].y);
  }}

      MPI_Bcast(P,n,MPI_INT,0,MPI_COMM_WORLD);




  i=0;
  j=0;
  Po=0;

  while(i<n){


   Li[i]=1;
   for(j=0;j<n;j++){

     if(i!=j)
     Li[i]= Li[i] * (X-P[j].x)/(P[i].x - P[j].x);

   }
  // printf("%.4lf \n",Li[i]*P[i].y);
   Po = Po + (Li[i]*P[i].y);
   i++;
  }
  printf("P[%.4lf] = %.4lf\n",X,Po);
}











