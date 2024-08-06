#include<stdio.h>
#include<stdlib.h>

int leitura(float *p);
void imprime(float *p,int q);

int main()
{	
	float a[5];
	int qtde;

	printf("\nLeitura - Vetor:\n");
	qtde=leitura(a);	
	printf("\nImprime - Vetor:");
	imprime(a,qtde);
	
	system("PAUSE");
	return 0;	
}

int leitura(float *p)
{
	int cont=0;
	char resp;
	do
	{
		printf("vet[%i]= ",cont);
		scanf("%f",p);
		fflush(stdin);
		p++;
		cont++;
		printf("Deseja continuar (S/N)? : ");
        scanf(" %c",&resp);  
	}while(toupper(resp)=='S'&& cont<5);
	return cont;
}//leitura

void imprime(float *p,int q)
{
	int i;
	for(i=0;i<q;i++,p++)
		printf("\nvet[%i]= %f",i,*p);
	printf("\n\n\n");
	system("pause");
}//imprime



