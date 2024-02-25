#include <stdio.h>
#include <stdlib.h>

int main()
{
int num1,num2;
num1=num2=0;
printf("\nDigite dois numeros: ");
scanf("%i %i",&num1,&num2);
if((num1%num2) == 0)
  printf("\nSao multiplos\n");
else
  printf("\nNao sao multiplos\n");
system("pause");
return 0;
}//main
