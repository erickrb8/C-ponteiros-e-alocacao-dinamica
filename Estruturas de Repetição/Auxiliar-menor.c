#include <stdio.h>
#include <stdlib.h>

int main()
{
int i;
float num,menor;  //menor - variável auxiliar
for(i=0;i<5;i++)
  {
  	printf("\nDigite o %i numero: ",i+1);
  	scanf("%f",&num);
  	fflush(stdin);
  	if(i==0 || num<menor)      //i=0 - 1ªvez do loop
  	  menor=num;
  }//for
printf("\nMenor valor digitado = %.2f\n\n",menor);
system("pause");
return 0;
}//main
