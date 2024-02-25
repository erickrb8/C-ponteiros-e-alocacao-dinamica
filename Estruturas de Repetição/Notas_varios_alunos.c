#include <stdio.h>
#include <stdlib.h>

int main()
{
char op;
float n1,n2;
do
 {
  printf("\nCalcula a media de notas dos alunos\n\n");
  system("cls");   //limpa a tela
  do
   {
    printf("\nDigite a nota1 (0~10): ");
    scanf("%f",&n1);
    fflush(stdin);
    if(n1<0 || n1>10)
     printf("\nValor invalido\n\n");
   }while(n1<0 || n1>10);
  do
   {
    printf("\nDigite a nota2 (0~10): ");
    scanf("%f",&n2);
    fflush(stdin);
    if(n2<0 || n2>10)
     printf("\nValor invalido\n\n");
   }while(n2<0 || n2>10); 
  printf("\nMedia=%.2f\n\n",(n1+n2)/2); 
  printf("\nDeseja continuar? <S> ou <N>: ");
  scanf("%c",&op);
  fflush(stdin);
  }while(op=='s'||op=='S');        //(op!='n' && op!='N');
system("pause");
return 0;
}//main
