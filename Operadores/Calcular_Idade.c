/*
Programa que faz a opera��o do c�lculo da Idade
Data 18/03/2021
*/

//Defini��o do cabe�alho com as bibliotecas
#include <stdio.h>    //standard input output
					  //fun��es padr�es de entrada e sa�da
#include <locale.h> //tem as fun��es de configura��o do pa�s

int main()  //tipo de retorno da fun��o main
{
	int ano_atual, ano_nasc, idade, diasvividos, horasvividas;
	
	setlocale(LC_ALL, "portuguese");
	
	printf("\n\nPrograma de C�lculo de Idade\n");   //  \n new line
	printf("--------------------------------");	
	printf("\nQual o ano de nascimento:       ");  //   \t  tab dar 6 espa�os em branco
	scanf("%i", &ano_nasc);
		
	printf("\nQual o ano atual: \t");
	scanf("%i" , &ano_atual);
	idade =   ano_atual - ano_nasc;
	printf("%i � a sua idade e voc� nasceu em %i \n",  idade, ano_nasc);
	
	diasvividos = idade * 365;
	printf("\nVoc� viveu %i anos \n", diasvividos);
	horasvividas = diasvividos * 24;
	printf("\nVoc� viveu %i horas \n", horasvividas);
	return 0;  //o valor 0 para o SO significa Success
} //fim da fun��o principal





