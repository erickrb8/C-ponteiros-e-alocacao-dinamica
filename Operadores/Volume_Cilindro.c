#include <stdio.h>
#include <stdlib.h> //system("pause")
#include <locale.h>
#include <math.h>  //função pow(base, expoente) -- potência
#define PI 3.14159
int main()
{
	//const float PI= 3.14159;
	setlocale(LC_ALL, "portuguese");
    float altura, raio, volume;
    printf("Qual a altura do cilindro em questão? ");
    scanf("%f", &altura);
    printf("\nQual o raio do cilindro em questão? ");
    scanf("%f", &raio);
    volume = altura * pow(raio, 2) * PI;
    printf("\nVolume = %.2f ", volume);
    
	system("pause");
	return 0;	
}
