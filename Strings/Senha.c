#include <stdio.h>
#include <stdlib.h>

int main()
{
char senha1[7],senha2[7];
int i,cont=0,cont1=0;  //cont=contador geral  cont1=contador dos 3 primeiros
printf("\nDigite a senha: ");
gets(senha1);
fflush(stdin);
printf("\nConfirme a senha: ");
gets(senha2);
fflush(stdin);
for(i=0;i<6;i++)
  if(senha1[i]==senha2[i])
    {
      cont++;  //são iguais
      if(i<3)
        cont1++;
    }//if
if(cont==6)  //todos os caracteres iguais
  printf("\nSenha valida!\n\n");
else if(cont1==3)   //3 primeiros são iguais
  printf("\nApenas os 3 primeiros caracteres corretos\n");
else
  printf("\nSenha invalida!\n\n");
system("pause");
return 0;
}//main
