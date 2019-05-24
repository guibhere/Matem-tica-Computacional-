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
    int i,j,k,aux=0,N,cont=0;
    double B0,B1,x0,x1,y0,y1,d[10],D,xmin,xmax,ymin,ymax,incx,incy;
    Pontos P[10];
    Equation Eq[9999];
    i=0;
    printf("\nAtenção! : utilizar ','(vírgula) ao invés de '.'(ponto) para inserir números quebrados , \ndevido a utilização de biblioteca portuguesa.\n\n");
    printf("Observação: A execução é um pouco demorada devio a precisão  \n");
    printf("Numero de Pontos :");
    scanf("%d",&N);
    printf("\n");
    for(i=0;i<N;i++){

      printf("Insira P[%d] (X;Y) \n",i+1);
      scanf("%lf %lf",&P[i].X,&P[i].Y);
      printf("P[%d] : (%.2lf ; %.2lf) \n",i+1,P[i].X,P[i].Y);}


    for(i=0;i<N;i++){

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
      incx= (xmax - xmin)/xmax;
      incy= (ymax - ymin)/ymax;
      //inc=0.5;
      printf("X(%.2lf ...... %.2lf) ",xmin,xmax);
      printf("Y(%.2lf ...... %.2lf) ",ymin,ymax);
      printf("Incremento : X(%.4lf) || Y(%.4lf) \n",incx,incy);
      system("pause");


   aux=0;



   for(x0=xmin;x0<xmax;x0=x0+incx){
    for(y0=ymin;y0<ymax;y0=y0+incy){
     for(x1=xmin;x1<xmax;x1=x1+incx){
      for(y1=ymin;y1<ymax;y1=y1+incy){

    if(x0==x1)
        x1=x1+incx;
    printf("\nPonto 1 : (%.2lf;%.2lf) // Ponto 2 : (%.2lf;%.2lf)\n",x0,y0,x1,y1);

    if(aux>=9999){
      Quick(Eq,0,aux-1);
       printf("Função com menor erro : Y = %.2lf + %.2lf*X \n",Eq[0].B0,Eq[0].B1);
       printf("D(%.2lf;%.2lf) = %.4lf \n",Eq[0].B0,Eq[0].B1,Eq[0].D);
       aux=1;
       //system("pause");
       }



    Eq[aux].B0 = y0 + ((y1-y0)/(x1-x0))*(- x0);
    Eq[aux].B1 = ((y1-y0)/(x1-x0));

    printf("Y = %.2lf + %.2lf*X \n",Eq[aux].B0,Eq[aux].B1);

    D=0;

    for(k=0;k<N;k++){
     d[k]= (Eq[aux].B0 + Eq[aux].B1*P[k].X ) - P[k].Y;
     D = D + (d[k]*d[k]);
    }

    Eq[aux].D = D;
    printf("D(%.2lf;%.2lf) = %.4lf \n",Eq[aux].B0,Eq[aux].B1,Eq[aux].D);





aux++;
cont++;



   }}}}
   printf("\n %d ITERAÇÔES\n",cont);
   Quick(Eq,0,aux-1);



   printf("Função com menor erro : Y = %.2lf + %.2lf*X \n",Eq[0].B0,Eq[0].B1);
   printf("D(%.2lf;%.2lf) = %.4lf \n",Eq[0].B1,Eq[0].B0,Eq[0].D);



}







