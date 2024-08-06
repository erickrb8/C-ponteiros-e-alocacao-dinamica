#include<stdio.h>
#include<stdlib.h>

void leitura(float *p,int q);
void imprime(float *p,int q);

int main()
{	
	float a[5];
	int qtde;

	do{
		printf("\nQtde de elementos - max 5: ");
		scanf("%i",&qtde);
	}while(qtde<1 || qtde>5);
	
	printf("\nLeitura - Vetor:\n");
	leitura(a,qtde);	
	printf("\nImprime - Vetor:");
	imprime(a,qtde);
	
	system("PAUSE");
	return 0;	
}

void leitura(float *p,int q)
{
	int i;
	for(i=0;i<q;i++,p++)
	{
		printf("vet[%i]= ",i);
		scanf("%f",p);
		fflush(stdin);
	}//for
}//leitura

void imprime(float *p,int q)
{
	int i;
	for(i=0;i<q;i++,p++)
		printf("\nvet[%i]= %f",i,*p);
	printf("\n\n\n");
	system("pause");
}//imprime



