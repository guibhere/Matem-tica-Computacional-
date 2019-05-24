#include<stdio.h>
#include<stdlib.h>
#include<math.h>
#include<locale.h>


double trapezio(int n , double a , double b , double h , int op){
    int i,j,k=0,c;
    double F,x,I=0;
 for(x=a ; x<=b; x = x+h){

 switch(op){
     case (1):
          F= (pow(x,3)) * log(x);
          break;
     case (2):
         F= log( pow(x,3) + sqrt(exp(x) + 1) );
         break;
     case (3):
         F=4*(1/(1+ (x*x)));
         break;
     case(4):
        F= exp(x);
        break;
 }

    c=2;
  if((k==0)||(k==n))
     c=1;

  I= I + ((h/2)*(F*c));
  k++;
 }
 return(I);
}

double simpson(int n , double a , double b , double h , int op){
    int i,j,k=0,c;
    double F,x,I=0;

    for(x=a ; x<=b; x = x+h){

switch(op){
     case (1):
          F= (pow(x,3)) * log(x);
          break;
     case (2):
         F= log( pow(x,3) + sqrt(exp(x) + 1) );
         break;
     case (3):
         F=4*(1/(1+ (x*x)));
         break;
     case(4):
        F= exp(x);
        break;
 }

   if((k==0)||(k==n))
    c=1;
   else{
    if(k%2==0)
    c=2;
    else
    c=4;}
    I= I + ((h/3)*(F*c));
    k++;
    }
    return(I);
}

double simpson2(int n , double a , double b , double h ,int op ){
    int i,j,k=0,c;
    double F,x,I=0;

    for(x=a ; x<=b; x = x+h){
switch(op){
     case (1):
          F= (pow(x,3)) * log(x);
          break;
     case (2):
         F= log( pow(x,3) + sqrt(exp(x) + 1) );
         break;
     case (3):
         F=4*(1/(1+ (x*x)));
         break;
     case(4):
        F= exp(x);
        break;
 }
   if((k==0)||(k==n))
    c=1;
   else{
    if(k%3==0)
    c=2;
    else
    c=3;}

    I= I + (((3*h)/8)*(F*c));
    k++;
    }
    return(I);
}


main () {

 int i,n,op;
 double a,b,I1,I2,I3,h;
 setlocale(LC_ALL, "Portuguese");
 Option:
 printf("Qual função será integrada ? \n");
 printf(" 1)- F(x)= x^3 * ln(x)\n");
 printf(" 2)- F(x)= ln(x^3 + sqrt(e^x +1))\n");
 printf(" 3)- F(x)= 4*(1/1+x^2) \n");
 printf(" 4)- F(x)= e^x \n");

 scanf("%d",&op);
 if((op<=0)||(op>4)){
   system("cls");
  printf("Opção Invalida!\n");
 goto Option;}






 printf("Insira os limites de integração : ");
 scanf("%lf %lf",&a,&b);
 printf("Insira N : ");
 scanf("%d",&n);
 h = (b-a)/(n);

 I1=trapezio(n,a,b,h,op);
 printf("\nIntegral via metodo dos Trapezios  I1 = %.4lf\n",I1);


 if(n%2==0){
  I2=simpson(n,a,b,h,op);
  printf("Integral via metodo de Simpson(1/3) I2 = %.4lf\n",I2);}
  else
  printf("Não é possivel a integração via Simpson(1/3)\n");

 if(n%3==0){
  I3=simpson2(n,a,b,h,op);
  printf("Integral via metodo de Simpson(3/8) I3 = %.4lf\n",I3);}
  else
  printf("Não é possivel a integração via Simpson(3/8)\n");

}

