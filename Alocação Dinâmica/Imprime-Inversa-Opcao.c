#include <stdio.h>
#include <stdlib.h>

void aloca (float **p, int tam);			//ponteiro p/ ponteiro - recebe endereco do ponteiro
int recebe (float *p);
void imprimeInverso (float *p, int tam);

main( )
{
	float *ptr=NULL;
	int cont=0;
	char op;
	
	do
	{
	 	aloca(&ptr,cont+1);//chamada por referencia - endereco do ptr
	    recebe(ptr+cont);
        cont++;
	    printf("Deseja continuar? (S/N): ");
	    scanf(" %c",&op);
	    fflush(stdin);
	}while(toupper(op)=='S');
	
	imprimeInverso(ptr,cont);

	system("pause");
}//main

void aloca (float **p, int tam)
{
	///printf("\nANTES Funcao aloca - Endereco: %u", *p);
	if((*p = (float *) realloc(*p, tam * sizeof(float))) == NULL)
	{
	    printf("Erro na alocacao");
	    exit(1);
	}
	printf("\nFuncao aloca - Endereco: %u\n", *p);
}//aloca

int recebe (float *p)
{
	//printf("\nFuncao recebe - Digite os valores \n");

    printf("Endereco: %u - Valor = ",p);
    scanf("%f",p);
	
}//recebe

void imprimeInverso (float *p, int tam)
{
	int i;
	printf("\nFuncao imprime invertido - Mostra os valores \n");
	for(i=tam-1;i>=0;i--)
	   printf("Endereco: %u - Valor = %.2f\n",p+i,*(p+i));
}//imprime


