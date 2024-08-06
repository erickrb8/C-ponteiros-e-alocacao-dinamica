#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

typedef 	struct	livro {
	int		reg;			// registro do livro - gerado automaticamente
	char	titulo[20];		// titulo do livro
	char	status;			// [L]ivre / [E]mprestado 
}livro;

typedef	struct	aluno {
	char	RA[7];			// RA do aluno
	char	nome[80];		// nome do aluno
	int		numreg;			// numero do registro do livro
	int		dias;			// tempo de permanencia - em dias
}aluno;

void aloca_livro(livro **pl,int tam);
void aloca_aluno(aluno **pa,int tam);
int	 verifica_livro();
int	 verifica_aluno();
void cadastra_livro(livro *pl);
void grava_livro(livro *pl);
void grava_aluno(aluno *pa);
int	 busca_livro(livro *pl,char *aux);
void atualiza_livro(livro *pl,int pos);	
void emprestimo(aluno *pa,livro *pl);
int  procura_RA(aluno *pa,char *aux);
void devolucao(aluno *pa,livro *pl);
void devolve_livro(livro *pl,int aux_reg);
void mostra_livro(livro *pl);
void mostra_aluno(aluno *pa);
void maiuscula(char *aux);

main()
{
livro *liv=NULL;
aluno *alu=NULL;
int op;
aloca_livro(&liv,1);
aloca_aluno(&alu,1);
do{
	system("cls");
	printf("\n[1]Cadastro Livro\n[2]Emprestimo\n[3]Devolucao\n[4]Mostra Livro\n[5]Mostra Aluno\n[6]Fim\nOpcao: ");
	scanf("%i",&op);
	fflush(stdin);
	switch(op)
	   {
	   	case 1: cadastra_livro(liv);
	   			break;
	   	case 2: emprestimo(alu,liv);
	   			break;
	   	case 3: devolucao(alu,liv);
	   			break;
	   	case 4: mostra_livro(liv);
	   			break;
	   	case 5: mostra_aluno(alu);
	   			break;
	   }//switch
  }while(op!=6);
}//main

void aloca_livro(livro **pl,int tam)
{
if((*pl=(livro*)realloc(*pl,tam*sizeof(livro)))==NULL)
  exit(1);
}//aloca_livro

void aloca_aluno(aluno **pa,int tam)
{
if((*pa=(aluno*)realloc(*pa,tam*sizeof(aluno)))==NULL)
  exit(1);
}//aloca_aluno

int	 verifica_livro()
{
FILE *fptr=NULL;
int qtde;
if((fptr=fopen("livros.bin","rb"))==NULL)
  return 0;
else
  {
  	fseek(fptr,0,2);   //posiciona fseek no final do arquivo
  	qtde=ftell(fptr)/sizeof(livro);
  	fclose(fptr);
  	return qtde;
  }//else	
}//verifica_livro

int	 verifica_aluno()
{
FILE *fptr=NULL;
int qtde;
if((fptr=fopen("alunos.bin","rb"))==NULL)
  return 0;
else
  {
  	fseek(fptr,0,2);   //posiciona fseek no final do arquivo
  	qtde=ftell(fptr)/sizeof(aluno);
  	fclose(fptr);
  	return qtde;
  }//else	
}//verifica_aluno

void cadastra_livro(livro *pl)
{
int qtde;
qtde=verifica_livro();
pl->reg=qtde+1;
printf("\nRegistro: %i\n",pl->reg);
printf("\nLivro a ser cadastrado: ");
gets(pl->titulo);
fflush(stdin);
strupr(pl->titulo);
pl->status='L';
grava_livro(pl);
}//cadastra_livro

void grava_livro(livro *pl)
{
FILE *fptr=NULL;
if((fptr=fopen("livros.bin","ab"))==NULL)
  printf("\nErro no arquivo\n\n\n");
else
  fwrite(pl,sizeof(livro),1,fptr);
fclose(fptr);
}//grava_livro

void grava_aluno(aluno *pa)
{
FILE *fptr=NULL;
if((fptr=fopen("alunos.bin","ab"))==NULL)
  printf("\nErro no arquivo\n\n\n");
else
  fwrite(pa,sizeof(aluno),1,fptr);
fclose(fptr);
}//grava_aluno

int	 busca_livro(livro *pl,char *aux)
{
FILE *fptr=NULL;
int i,qtde,achou=-1;

qtde=verifica_livro();
if((fptr=fopen("livros.bin","rb"))==NULL)
  printf("\nErro no arquivo\n\n");
else
  {
  	for(i=0;i<qtde;i++)
  	  {
  	  	fseek(fptr,i*sizeof(livro),0);
  	  	fread(pl,sizeof(livro),1,fptr);
  	  	if((strcmp(pl->titulo,aux)==0) && pl->status=='L')
  	  	  {
  	  	  	achou=i;
  	  		i=qtde;
		  }//if
		}//for
	fclose(fptr);    //dentro do else por conta do rb	
   }//else
return achou;
}//busca_livro

void atualiza_livro(livro *pl,int pos)
{
FILE *fptr=NULL;

if((fptr=fopen("livros.bin","rb+"))==NULL)
  printf("\nErro no arquivo\n\n");
else
  {
  	fseek(fptr,pos*sizeof(livro),0);
  	fwrite(pl,sizeof(livro),1,fptr);
  }//else
fclose(fptr);    //fora do else por conta do rb+
}//atualiza_livro

void emprestimo(aluno *pa,livro *pl)
{
char aux_liv[20];
int ind;
mostra_livro(pl);
system("cls");
printf("\nTitulo do livro: ");
gets(aux_liv);
fflush(stdin);
maiuscula(aux_liv);
ind=busca_livro(pl,aux_liv);		//busca a posicao do equipo disponivel
if(ind==-1)
  printf("\nNao ha livro disponivel com esse titulo\n\n");
else
  {
  	pa->numreg=pl->reg;
  	printf("\nRA: ");
  	gets(pa->RA);
  	fflush(stdin);
  	printf("\nNome: ");
  	gets(pa->nome);
  	fflush(stdin);
  	maiuscula(pa->nome);
  	printf("\nQuantos dias: ");
  	scanf("%i",&pa->dias);
  	fflush(stdin);
  	grava_aluno(pa);
  	pl->status='E';
  	atualiza_livro(pl,ind);
  }//else
system("pause");
}//emprestimo

int procura_RA(aluno *pa,char *aux)
{
FILE *fptr=NULL;
int i,qtde,achou=-1;

qtde=verifica_aluno();
if((fptr=fopen("alunos.bin","rb"))==NULL)
  printf("\nErro ao abrir o arquivo\n");
else
  {
  	for(i=0;i<qtde;i++)
  	  {
  	    fseek(fptr,i*sizeof(aluno),0);
  	    fread(pa,sizeof(aluno),1,fptr);
  	    if(strcmp(pa->RA,aux)==0)
  	      {
  	      	achou=i;
  	      	i=qtde;		//forca a saida do for
  	      }//if
      }//for
    fclose(fptr);		//dentro do else por conta do rb
  }//else
return achou;
}//procura_RA

void devolucao(aluno *pa,livro *pl)
{
char aux[7];
int achou;
printf("\nRA do aluno: ");
gets(aux);
fflush(stdin);
achou=procura_RA(pa,aux);
if(achou==-1)
  printf("\nAluno nao encontrado\n\n");
else
  {
  	printf("\nNome: %s",pa->nome);
	printf("\nRegistro do livro: %i",pa->numreg);		//mostra registro do livro
	devolve_livro(pl,pa->numreg);						// troca status para Livre
	printf("\nTitulo do livro: %s",pl->titulo);			//mostra titulo
	printf("\nDias: %i",pa->dias);
	printf("\nValor a pagar: %i\n\n\n",pa->dias*5);	    // calcula o valor a pagar
  }//else
system("pause");	
}//devolucao

void devolve_livro(livro *pl,int aux_reg) 
{
FILE *fptr=NULL;
int i,qtde;

qtde=verifica_livro();
if((fptr=fopen("livros.bin","rb+"))==NULL) 
    printf("\nErro ao abrir o arquivo\n");
else
  {
  	for(i=0;i<qtde;i++)
  	  {
  	  	fseek(fptr,i*sizeof(livro),0);
    	fread(pl,sizeof(livro),1,fptr);
  	    if(pl->reg == aux_reg)
  	      {
  	      	pl->status='L';				    	// troca o status do livro para Livre
      		fseek(fptr,i*sizeof(livro),0);
    		fwrite(pl,sizeof(livro),1,fptr);
    		i=qtde;			//forca a saida do for
  	      }//if
      }//for
  }//else
  fclose(fptr);			//fora do else por conta do rb+
}//acha_livro

void mostra_livro(livro *pl)
{
FILE *fptr=NULL;
int i,qtde;

qtde=verifica_livro();
if((fptr=fopen("livros.bin","rb"))==NULL)
  printf("\nErro  no arquivo\n\n");
else
  {
  	for(i=0;i<qtde;i++)
  	  {
  	  	fseek(fptr,i*sizeof(livro),0);
  	  	fread(pl,sizeof(livro),1,fptr);
  	  	printf("\nRegistro: %i\nLivro: %s\nStatus: %c\n\n",pl->reg,pl->titulo,pl->status);
	  }//for
	fclose(fptr);   //dentro do else por conta do rb
  }//else
system("pause");
}//mostra_livro

void mostra_aluno(aluno *pa)
{
FILE *fptr=NULL;
int i,qtde;

qtde=verifica_aluno();
if((fptr=fopen("alunos.bin","rb"))==NULL)
  printf("\nErro  no arquivo\n\n");
else
  {
  	for(i=0;i<qtde;i++)
  	  {
  	  	fseek(fptr,i*sizeof(aluno),0);
  	  	fread(pa,sizeof(aluno),1,fptr);
  	  	printf("\nRA: %s\nNome: %s\nRegistro do Livro: %i\nDias: %i\n\n",pa->RA,pa->nome,pa->numreg,pa->dias);
	  }//for
	fclose(fptr);   //dentro do else por conta do rb
  }//else
system("pause");
}//mostra_aluno

void maiuscula(char *aux)
{
int i,tam;
tam=strlen(aux);
for(i=0;i<tam;i++)
  if(*(aux+i)>='a'&&*(aux+i)<='z')
    *(aux+i)-=32;
}//maiuscula
