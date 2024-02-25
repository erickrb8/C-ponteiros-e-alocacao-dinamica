#include <stdio.h>
#include <stdlib.h>

int main()
{
int A[100],B[100],C[100],i,qtde;
do
 {
 	printf("\nDigite a quantidade de elementos do vetor (max.100): ");
 	scanf("%i",&qtde);
 	fflush(stdin);
 }while(qtde<1 ||qtde>100);
//Receber qtde numeros e armazenar em um vetor
for(i=0;i<qtde;i++)
  {
    printf("Digite A[%i]= ",i);
    scanf("%i",&A[i]);
    fflush(stdin);
  }//for
printf("\n");
for(i=0;i<qtde;i++)
  {
    printf("Digite B[%i]= ",i);
    scanf("%i",&B[i]);
    fflush(stdin);
  }//for
printf("\nO vetor resultante C:\n");
for(i=0;i<qtde;i++)
  {
    C[i]=A[i]+B[i];
	printf("C[%i]= %i\n",i,C[i]);
  }//for
printf("\n");
system("pause");
return 0;
}//main

