#include <stdio.h>
#include <stdlib.h>

void aloca (float **p, int tam);			//ponteiro p/ ponteiro - recebe endereco do ponteiro
void recebe (float *p, int tam);
void imprime (float *p, int tam);
void altera (float *p, int tam);

main( )
{
	float *ptr=NULL;
	aloca(&ptr,10);				//chamada por refercncia - endereco do ptr
	recebe(ptr,10);
	imprime(ptr,10);
	altera(ptr,10);
	imprime(ptr,10);
	system("pause");
}//main

void aloca (float **p, int tam)
{
	if((*p = (float *) realloc(*p, tam * sizeof(float))) == NULL)
	{
	    printf("Erro na alocacao");
	    exit(1);
	}
	printf("\nFuncao aloca - Endereco: %u", *p);
}//aloca

void recebe (float *p, int tam)
{
	int i;
	
	printf("\nFuncao recebe - Digite os valores \n");
	for(i=0;i<tam;i++)
	{
	   printf("Endereco: %u - Valor = ",p+i);
	   scanf("%f",p+i);
	}
}//recebe

void imprime (float *p, int tam)
{
	int i;
	printf("\nFuncao imprime - Mostra os valores \n");
	for(i=0;i<tam;i++)
	   printf("Endereco: %u - Valor = %.2f\n",p+i,*(p+i));
}//imprime

void altera (float *p, int tam)
{
	int i;
	//printf("\nFuncao imprime - Mostra os valores \n");
	for(i=0;i<tam;i++)
	   *(p+i)+=30;
}//imprime
