#include <stdio.h>
#include <stdlib.h>

int main()
{
int matriz[10][10],linha,coluna,lin,col,soma[10],maior,pos;
do
 {
 	printf("\nLinhas: ");
 	scanf("%i",&linha);
 	fflush(stdin);
 }while(linha<1 || linha>10);
do
 {
 	printf("\nColunas: ");
 	scanf("%i",&coluna);
 	fflush(stdin);
 }while(coluna<1 || coluna>10);
//leitura da matriz
for(lin=0;lin<linha;lin++)
  for(col=0;col<coluna;col++)
    {
    	printf("\nmatriz[%i][%i]= ",lin,col);
    	scanf("%i",&matriz[lin][col]);
    	fflush(stdin);
    }//for
//soma das colunas
for(col=0;col<coluna;col++)
  {
  	soma[col]=0;    //limpando cada elemento do meu vetor
  	for(lin=0;lin<linha;lin++)
  	  soma[col]+=matriz[lin][col];
  }//for col
//mostra matriz
for(lin=0;lin<linha;lin++)
  {
    for(col=0;col<coluna;col++)
       	printf("%i\t",matriz[lin][col]);
    printf("\n");   	
  }//for
//verifica maior coluna
for(col=0;col<coluna;col++)
  {
  	if(col==0)
  	  {
  	  	maior=soma[0];    //1º elemento do vetor soma
  	  	pos=0;
  	  }//if
  	printf("\nColuna %i - Soma: %i\n",col,soma[col]);
  	if(maior<soma[col])
  	  {
  	  	maior=soma[col];
  	  	pos=col;
  	  }//if
  }//for
printf("\nMaior coluna %i - Soma: %i\n\n",pos,maior);
system("pause");
return 0;
}//main
