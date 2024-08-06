#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct cliente{
       char nome[30];
       int conta;
       float saldo;
}cliente;

void aloca(cliente **aux,int tam);
void cadastro(cliente *aux);
int busca(cliente *aux,int total);
void mostra(cliente *aux);
void movimenta(cliente *aux,int op);

main()
{
	cliente *c=NULL;
	int op,cont=0,achou;
	do
	{
	   system("cls");
	   printf("\n[1]Cadastro\n[2]Deposito\n[3]Retirada\n[4]Fim\nOpcao: ");
	   scanf("%i",&op);
	   fflush(stdin);
	   switch(op)
	   {
	     case 1: aloca(&c,cont+1);
	             cadastro(c+cont);
	             mostra(c+cont);
	             cont++;
	             break;
	     case 2:
	     case 3: achou=busca(c,cont);
	             if(achou==-1)
	             {
	             	printf("\nConta Inexistente\n\n\n");
	               	system("pause");
	             }
	             else 
				 {
				    movimenta((c+achou),op);
	        	 }
	             break;
	    }//switch               
	}while(op!=4);
}//main     
          
void aloca(cliente **aux, int tam)
{
	if((*aux=(cliente*)realloc(*aux,tam*sizeof(cliente)))==NULL)
	  exit(1);
}//aloca

void cadastro(cliente *aux)
{
	static int cconta=1000;
	
	printf("\nNome: ");
	gets(aux->nome);
	fflush(stdin);
	aux->conta=cconta++;
	aux->saldo=0;
}//cadastro

int busca(cliente *aux,int total)
{
	int aux_conta,i;
	printf("\nConta Corrente: ");
	scanf("%i",&aux_conta);
	fflush(stdin);
	for(i=0;i<total;i++)
	{
	    if((aux+i)->conta==aux_conta)
	    {
		    return i;
		}
	}
	return -1;
}//busca

void mostra(cliente *aux)
{
	printf("\nNome: %s",aux->nome);
	printf("\nConta: %i",aux->conta);
	printf("\nSaldo: %.2f\n\n\n",aux->saldo);
	system("pause");
}//mostra

void movimenta(cliente *aux,int op)
{
	float quantia;
	
	mostra(aux);
	printf("\nQuantia a ser depositada/retirada: ");
	scanf("%f",&quantia);
	fflush(stdin);
	if(op==2)  //deposito
	{
		printf("\nSaldo atual: %.2f\n\n\n",aux->saldo+=quantia);
	}
	else
	{
	  	if(aux->saldo>=quantia)
	  	{
		    printf("\nSaldo atual: %.2f\n\n\n",aux->saldo-=quantia);
	  	}
	  	else
	  	{
		    printf("\nSaldo Insuficiente\n\n\n");
	  	}
	}
	system("pause");
}//movimenta

