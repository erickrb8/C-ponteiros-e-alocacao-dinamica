#include <stdio.h>
#include <stdlib.h> //system("pause")
#include <locale.h>

int main()
{
	setlocale(LC_ALL, "portuguese");
	float valorMReal, valorTaxaDolar, valorDolar;
	system("color 1A");
	printf("\nQual o valor do produto? ");
	scanf("%f", &valorMReal);
	printf("\nQual o valor da taxa de convers�o do d�lar hoje? ");
	scanf("%f", &valorTaxaDolar);
	valorDolar = valorMReal / valorTaxaDolar;
	printf("\nMercadoria em reais  R$ %.2f e em d�lar US$ %.2f \n", valorMReal, valorDolar);
	
	system("pause");
	return 0;	
}
