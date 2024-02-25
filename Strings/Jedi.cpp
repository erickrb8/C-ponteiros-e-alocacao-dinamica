#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <ctype.h>

int main()
{
char nome[80],mae[20],cidade[20],njedi[6],sjedi[6],cjedi[8];
int i,j,z,tam;  
printf("Nome completo: ");
gets(nome);
fflush(stdin);
printf("\nNome da mae: ");
gets(mae);
fflush(stdin);
printf("\nCidade onde nasceu: ");
gets(cidade);
fflush(stdin);
//nome Jedi
tam=strlen(nome);
for(i=0;i<3;i++)
 njedi[i]=nome[i];
for(z=tam;z>=0;z--)
 if(nome[z]==' ')
  {
  for(j=0;j<2;j++,i++)
    njedi[i]=tolower(nome[z+1+j]);
  z=-10;
  }
njedi[i]='\0';
//sobrenome Jedi   
for(i=0;i<2;i++)
  sjedi[i]=mae[i];
for(j=0;j<3;j++,i++)
  sjedi[i]=tolower(cidade[j]);
sjedi[i]='\0';
//nome composto
tam=strlen(sjedi);
for(i=0;i<3;i++)
  cjedi[i]=njedi[i];
cjedi[i]='-';
i++;
for(j=tam-3;j<tam;j++,i++)
  if(j==tam-3)
    cjedi[i]=toupper(sjedi[j]);
  else
    cjedi[i]=sjedi[j];
cjedi[i]='\0';
printf("\nNome jedi: %s ", njedi);
printf("\nSobrenome jedi: %s", sjedi);
printf("\nNome composto: %s\n\n", cjedi);
system("pause");
return 0;
}//main
