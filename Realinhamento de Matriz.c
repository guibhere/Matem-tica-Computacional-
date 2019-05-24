#include<stdio.h>
#include<math.h>
#include<string.h>
#include<stdlib.h>
#include<locale.h>
#define TRUE 0
#define FALSE 1


typedef struct{
  double Maior,l[3];
  double constante;
  int posL, posC ;
}Linhas;

void Quick(Linhas vet[ ], int esq, int dir){
int i=esq, j=dir;
Linhas x,y;
x = vet[(esq+dir)/2];
do{
while ((vet[i].posC < x.posC) && (i < dir))
i++;
while ((x.posC< vet[j].posC) && (j > esq))
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
int Mit=7,it=0,i,j;
double M[3][3],Emin=0.05,E=100,S[3][3],C[3],X0[3],X1[3],Sum,N1,N2,aux1,aux2,V,v,cont=0,R=TRUE;
Linhas L[3];

printf("Insira os coeficientes do sistema linear\n");
for(i=0;i<=2;i++){
 for(j=0;j<=2;j++){
    scanf("%lf",&S[i][j]);
    printf("%.0lfX%d ",S[i][j],j+1);

    }
    scanf("%lf",&C[i]);
    printf(" = %.0lf\n",C[i]);
    }

 ver:
 for(i=0;i<=2;i++){
    v=0;
 for(j=0;j<=2;j++){
  if(i==j)
    V=S[i][j];
   else
    v=v+S[i][j];
 }
 if(V>=v)
   R=TRUE;
 else{
    if(cont>0){
         printf("Sistema não convergente\n");
         goto END;}
    else {
         cont++;
         R=FALSE;
         break;
 }}}




 if(R==FALSE){
   for(i=0;i<=2;i++){
        L[i].Maior=0;
    for(j=0;j<=2;j++){
         L[i].l[j]=S[i][j];
        if(S[i][j]>L[i].Maior){
         L[i].Maior=S[i][j];
         L[i].posC=j;
         L[i].constante=C[i];}}}

    Quick(L,0,2);


    for(i=0;i<=2;i++){
    for(j=0;j<=2;j++){
      S[i][j]=L[i].l[j];
      C[i]=L[i].constante;
      printf("%.0lf ",S[i][j]);
    }printf("=%.0lf \n",C[i]);
    }
    system("pause");
    goto ver;
    }

   printf("Insira X[0] \n");
for(i=0;i<=2;i++){
  scanf("%lf",&X0[i]);
}


printf("Insira margem de erro minino : ");
scanf("%lf",&Emin);
printf("\nInsira maxima quantidade de iterações : ");
scanf("%d",&Mit);





for(i=0;i<=2;i++){
 for(j=0;j<=2;j++){
    if(i==j)
    M[i][j]=0;
    else
    M[i][j]=-(S[i][j])/(S[i][i]);
    printf("%.2lf ",M[i][j]);
}
 C[i]= (C[i])/(S[i][i]);
 printf(" %.2lf",C[i]);
 printf("\n");}



while((E>Emin)&&(it<=Mit)){
printf("K= %d \n\n",it);
for(i=0;i<=2;i++){
    Sum=0;
 for(j=0;j<=2;j++){
   if(i==j)
   Sum=Sum;
   else
   Sum=Sum + M[i][j]*X0[j];
   }
   X1[i]=Sum + C[i];
   printf("X%d[k+1]=%.4lf \n",i+1,X1[i]);
}
  N1=0;
  N2=0;

  for(i=0;i<=2;i++){
     aux1=(X1[i]-X0[i]);
     if(aux1<0)
        aux1=aux1*-1;
    if(aux1>N1)
    N1=aux1;

    aux2=(X1[i]);
    if(aux2<0)
        aux2=aux2*-1;
    if(aux2>N2)
    N2=aux2;

    X0[i]=X1[i];
    }

  E=N1/N2;
  printf("Erro = %.4lf%%\n",E);
  it++;
}

END:
    printf("FIM");
    }

















