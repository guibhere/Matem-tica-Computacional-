#include<stdio.h>
#include<math.h>
#include<string.h>
#include<stdlib.h>
#include<locale.h>
#define TRUE 0
#define FALSE 1

typedef struct{
   double X,Y;
}Pontos;

typedef struct{
    double B0,B1,D;
}Equation;


void Quick(Equation vet[ ], int esq, int dir){
int i=esq, j=dir;
Equation x,y;
x = vet[(esq+dir)/2];
do{
while ((vet[i].D < x.D) && (i < dir))
i++;
while ((x.D< vet[j].D) && (j > esq))
j--;
if ( i <= j ){
y = vet[i]; vet[i] = vet[j]; vet[j] = y;
i++; j--;
}
} while ( i <=j );
if ( esq < j )
Quick(vet, esq, j);
if ( i < dir )
Quick(vet, i, dir);}




main () {
    setlocale(LC_ALL, "Portuguese");
    int i,j,aux=0,cont=0;
    double B0,B1,x0,y0,x1,y1,d[99],D,xmin,xmax,ymin,ymax,inc,incx,incy;
    Pontos P[10];
    Equation Eq[9999];
    i=0;
    for(i=0;i<10;i++){

      printf("Insira P[%d] (X;Y) \n",i+1);
      scanf("%lf %lf",&P[i].X,&P[i].Y);
      printf("P[%d] : (%.2lf ; %.2lf) \n",i+1,P[i].X,P[i].Y);}


    for(i=0;i<10;i++){

             if(i==0){

      xmin = P[i].X;
      xmax = P[i].X;
      ymin = P[i].Y;
      ymax = P[i].Y;
      }

    else{
      if(xmin>P[i].X){
        xmin=P[i].X;}
          if(xmax<P[i].X){
            xmax=P[i].X;}
      if(ymin>P[i].Y){
        ymin=P[i].Y;}
          if(ymax<P[i].Y){
            ymax=P[i].Y;}

      }}

      printf("X(%.2lf ...... %.2lf) ",xmin,xmax);
      printf("Y(%.2lf ...... %.2lf) ",ymin,ymax);

      inc = (xmax - xmin)/(ymax - ymin);
      if((inc>0)&&(inc<1))
          inc = 0,1/inc;
      else if((inc>=1)&&(inc<10))
          inc = 1/inc;
      else if(inc>=100)
          inc = 10/inc;

      printf(" inc = %.4lf \n",inc);
      system("pause");
      inc=0.1;
      incx=(xmax - xmin);
      incy=(ymax - ymin);
    aux=0;
   cont=0;
   x0=xmin;
   y0=ymin;
   x1=xmin;
   y1=ymin;


   while((x0<=xmax)&&(y0<=ymax)){
      while((x1<=xmax)&&(y1<=ymax)){

   if((x0==x1)&&(y0==y1)){
      x1=x1+ incx;
      y1=y1+ sqrt(inc) ;}

    printf("\n Interação (%d)\n",cont +1);
    printf("Ponto 1: (%.2lf;%.2lf) // Pont0 2: (%.2lf;%.2lf) \n",x0,y0,x1,y1);

    Eq[cont].B0 = y0 + ((y1-y0)/(x1-x0))*(- x0);
    Eq[cont].B1 = ((y1-y0)/(x1-x0));
    printf("Y = %.2lf + %.2lf*X \n",Eq[cont].B0,Eq[cont].B1);

    D=0;
    for(i=0;i<10;i++){
     d[i]= (Eq[cont].B0 + Eq[cont].B1*P[i].X ) - P[i].Y;
     D = D + (d[i]*d[i]);
    }
    Eq[cont].D = D;
    printf("D(%.3lf;%.3lf) = %.4lf \n",Eq[cont].B0,Eq[cont].B1,Eq[cont].D);








    aux++;
    cont++;
     x1 = x1 +  pow( aux/100 , sqrt(incx) );
     y1 = y1 +  pow( aux/100 , sqrt(incy) );
   }
    x0= x0 +  incx;
    y0= y0 +  incy;
    x1=xmin;
    y1=ymin;
   }



   printf("\nContador : %d \n",cont);
   system("pause");
   Quick(Eq,0,cont-1);



   printf("Função com menor erro : Y = %.2lf + %.2lf*X \n",Eq[0].B0,Eq[0].B1);
   printf("D(%.2lf;%.2lf) = %.4lf \n",Eq[0].B0,Eq[0].B1,Eq[0].D);



}







