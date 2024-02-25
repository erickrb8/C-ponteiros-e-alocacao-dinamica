#include <stdio.h>
#include <stdlib.h>
#include <string.h>  //funçao strlen()

int main()
{
char frase[80],str[80];
int pos[80],tamf,tams,i,cont,j,qtde=0,z,x=0;

printf("\nDigite uma frase: ");
gets(frase);
fflush(stdin);
tamf=strlen(frase);
printf("\nDigite o string a ser buscado: ");
gets(str);
fflush(stdin);
tams=strlen(str);
for(i=0;i<tamf;i++)
  {
  	cont=0;
  	for(j=0;j<tams;j++)
  	  {
  	  	if(frase[i+j]==str[j])
  	  	  {
  	  	  	cont++;
  	  	  	if(cont==tams)
  	  	  	  {
  	  	  	  	qtde++;
  	  	  	  	for(z=0;z<tams;z++,x++)   //guardar as posições
  	  	  	  	  pos[x]=i+1+z;
  	  	  	  }//if cont
  	  	  }//if frase
  	  	else
  	  	  j=tams;
  	  }//for j
  }//for i
if(qtde==0)
  printf("\nNao ha ocorrencia do string %s na frase\n\n",str);
else
  {
  	printf("\nO string %s ocorreu %i vezes nas posicoes:\n",str,qtde);
  	for(i=0;i<qtde*tams;i++)
  	  printf("%i\t",pos[i]);
  }//else
system("pause");
return 0;
}//main
