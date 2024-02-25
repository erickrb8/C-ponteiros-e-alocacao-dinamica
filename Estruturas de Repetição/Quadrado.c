#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <math.h>

int main()
{
char op='s';
float lado,p,a;
while(toupper(op)=='S')   //biblioteca ctype.h
  {
  	system("cls");     //limpeza da tela
	printf("\nDigite o lado do quadrado: ");
  	scanf("%f",&lado);
  	fflush(stdin);
  	a=pow(lado,2);       //biblioteca math.h
  	p=4*lado;
  	printf("\nArea: %.2f\n\nPerimetro: %.2f\n",a,p);
  	printf("\nDeseja continuar? [S]im ou [N]ao: ");
  	scanf("%c",&op);
  	fflush(stdin);
  }//while
system("pause");
return 0;
}//main
