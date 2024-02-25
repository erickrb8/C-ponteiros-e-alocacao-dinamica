/*Faça um programa de controle de temperatura de um tanque/equipamento. 
De acordo com a entrada da temperatura (que pode ser por meio por um dispositivo 
ou pelo usuário) estabilize em 50 graus. 
A estabilização deve ocorrer por um aquecimento ou resfriamento. */

#include <stdlib.h>
#include <locale.h>
int main()
{
setlocale(LC_ALL,"portuguese");
int temp, cont;
printf("\nQual a temperatura? ");
scanf("%i", &temp); //20 --- tem que chegar a 50

//resfriamento
for (cont = temp; cont > 50 ; cont -= 1) //--cont
{
	printf("\n Resfriando %i ",cont);
	_sleep(500); // 1000 milesimos de segundos - 1 segundo
}
//aquecimento
for (cont=temp; cont < 50 ; ++cont)
{
	printf("\n Aquecendo %i ",cont);
	_sleep(500); 
}

//printf("\n estabilizada em  %i ",cont);

printf("\nFim do programa");	
system("pause");
return 0;
}

