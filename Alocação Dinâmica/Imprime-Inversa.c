#include <stdio.h>
#include <stdlib.h>

void aloca (float **p, int tam);			//ponteiro p/ ponteiro - recebe endereco do ponteiro
void recebe (float *p, int tam);
void imprimeInverso (float *p, int tam);

main( )
{
	float *ptr=NULL;
	int qtd;
	printf("Digite a quantidade de valores: ");
	scanf("%i",&qtd);
	aloca(&ptr,qtd);				//chamada por refercncia - endereco do ptr
	recebe(ptr,qtd);
	imprimeInverso(ptr,qtd);

	system("pause");
}//main

void aloca (float **p, int tam)
{
	if((*p = (float *) realloc(*p, tam * sizeof(float))) == NULL)
	{
	    printf("Erro na alocacacao");
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

void imprimeInverso (float *p, int tam)
{
	int i;
	printf("\nFuncao imprime - Mostra os valores \n");
	for(i=tam-1;i>=0;i--)
	   printf("Endereco: %u - Valor = %.2f\n",p+i,*(p+i));
}//imprime


