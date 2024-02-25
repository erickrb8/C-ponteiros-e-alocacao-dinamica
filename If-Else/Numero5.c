#include<stdio.h>
#include<stdlib.h>


int main()
{
int x;
printf("Digite um numero:");	  
scanf("%i",&x);
if (x<1 || x>5)
   printf("O valor digitado \x82 %i\n",x);
system("pause");
return 0;
}//main

