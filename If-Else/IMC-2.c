#include<stdio.h>
#include<stdlib.h>
#include<math.h>

int main()
{ 
float peso,altura,imc;
printf("\nCalculo do IMC\n");
printf("Digite o seu peso: ");
scanf("%f",&peso);
printf("Digite a sua altura: ");
scanf("%f",&altura);

//verificação do IMC = kg/m2 
//pow(x,y): eleva x à potência y

imc = peso/(pow(altura,2));
if(imc<18.5)
  printf("\nVc esta Abaixo do peso\n");
else if (imc<25)
       printf("\nVc esta Saudavel\n");
     else if(imc<30)
            printf("\nVc esta com Sobrepeso\n");
          else if(imc<35)
          	     printf("\nVc esta com Obesidade Grau 1\n");
          	   else if(imc<40)
          	  	      printf("\nVc esta com Obesidade Grau 2 - severa\n");
          	        else
          	          printf("\nVc esta com Obesidade Grau 3 - morbida\n");
system("pause");
return 0;
}//main

