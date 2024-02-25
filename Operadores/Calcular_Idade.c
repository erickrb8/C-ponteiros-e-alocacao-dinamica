/*
Programa que faz a operação do cálculo da Idade
Data 18/03/2021
*/

//Definição do cabeçalho com as bibliotecas
#include <stdio.h>    //standard input output
					  //funções padrões de entrada e saída
#include <locale.h> //tem as funções de configuração do país

int main()  //tipo de retorno da função main
{
	int ano_atual, ano_nasc, idade, diasvividos, horasvividas;
	
	setlocale(LC_ALL, "portuguese");
	
	printf("\n\nPrograma de Cálculo de Idade\n");   //  \n new line
	printf("--------------------------------");	
	printf("\nQual o ano de nascimento:       ");  //   \t  tab dar 6 espaços em branco
	scanf("%i", &ano_nasc);
		
	printf("\nQual o ano atual: \t");
	scanf("%i" , &ano_atual);
	idade =   ano_atual - ano_nasc;
	printf("%i é a sua idade e você nasceu em %i \n",  idade, ano_nasc);
	
	diasvividos = idade * 365;
	printf("\nVocê viveu %i anos \n", diasvividos);
	horasvividas = diasvividos * 24;
	printf("\nVocê viveu %i horas \n", horasvividas);
	return 0;  //o valor 0 para o SO significa Success
} //fim da função principal





