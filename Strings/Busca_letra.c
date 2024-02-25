#include <stdio.h>
#include <stdlib.h>
#include <string.h>  //funçao strlen()
#include <ctype.h>   //função toupper()

int main()
{
char frase[80],letra;
int i,tam,cont=0;   //contar qtde de letras iguais a procurada
printf("\nDigite uma frase: ");
gets(frase);
fflush(stdin);
tam=strlen(frase);
printf("\nDigite uma letra: ");
scanf("%c",&letra);
fflush(stdin);
for(i=0;i<tam;i++)
  if(toupper(frase[i])==toupper(letra))
    cont++;     //igual - achou a letra
printf("\nA letra %c ocorre %i vez(es) na frase\n\n",letra,cont);
system("pause");
return 0;
}//main
