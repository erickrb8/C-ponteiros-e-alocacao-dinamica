#include <stdio.h>
#include <stdlib.h>

int main()
{
int num;
printf("\nDigite um numero positivo: ");
scanf("%i",&num);
if(num>0)    //se é positivo
  {
  	if(num%2==0)
  	  printf("\nO numero %i \x82 par\n",num);
  	else
  	  printf("\nO numero %i \x82 impar\n",num);
  }//if
else
  printf("\nO numero %i nao \x82 positivo\n",num);
system("pause");
return 0;
}//main
