#include <stdio.h>
#include <stdlib.h>

typedef struct dados{
int    reg;
char   produto[20];
int    qtde;
float  preco;
}dados;

void aloca(dados **p,int tam);
int	 verifica();
void cadastro(dados *p,int nreg);
void grava(dados *p);
void mostra(dados *p);

main()
{
dados *pd=NULL;
int qreg;
char op;
aloca(&pd,1);
do{
	qreg=verifica();   //qtde de elementos dentro do arquivo
	cadastro(pd,qreg+1);
	grava(pd);
	printf("\nDeseja continuar <S/N>: ");
	scanf("%c",&op);
	fflush(stdin);
  }while(op!='n'&&op!='N');
mostra(pd);
}//main

void aloca(dados **p,int tam)
{
if((*p=(dados*)realloc(*p,tam*sizeof(dados)))==NULL)
  exit(1);
}//aloca

int	 verifica()
{
FILE *fptr=NULL;
int qtde=0;
if((fptr=fopen("estoque.bin","rb"))==NULL)	
  return qtde;
else
  {
  	fseek(fptr,0,2);   //posiciona o fptr no final 
  	qtde=ftell(fptr)/sizeof(dados);
  	fclose(fptr);
  	return qtde;
  }//else
}//verifica

void cadastro(dados *p,int nreg)
{
p->reg=nreg;
printf("\nRegistro: %i",p->reg);
printf("\nProduto: ");
gets(p->produto);
fflush(stdin);
printf("\nQtde em estoque: ");
scanf("%i",&p->qtde);
fflush(stdin);
printf("\nPreco: ");
scanf("%f",&p->preco);
fflush(stdin);
}//cadastro

void grava(dados *p)
{
FILE *fptr=NULL;
if((fptr=fopen("estoque.bin","ab"))==NULL)
  printf("\nErro - impossivel gravar os dados\n\n");
else
  {
  	fwrite(p,sizeof(dados),1,fptr);
  	printf("\nRegistro gravado com sucesso\n\n");
  }//else
fclose(fptr);
system("pause");
}//grava

void mostra(dados *p)
{
FILE *fptr=NULL;
int i,qtde;
qtde=verifica();	
if((fptr=fopen("estoque.bin","rb"))==NULL)
  printf("\nErro - impossivel ler os registros\n\n");
else
  {
  	for(i=0;i<qtde;i++)
  	  {
  	  	fseek(fptr,i*sizeof(dados),0);
  	  	fread(p,sizeof(dados),1,fptr);
  	  	printf("\nRegistro: %i\nProduto: %s\nQtde: %i\nPreco: %.2f\n",p->reg,p->produto,p->qtde,p->preco);
  	  }//for
  	fclose(fptr);  
  }//else
system("pause");
}//mostra
