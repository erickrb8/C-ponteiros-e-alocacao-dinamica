#include <stdio.h>
#include <stdlib.h>
#include <locale.h>
int main()
{
setlocale(LC_ALL,"portuguese");
float tempf, tempc;
int x;

for (x = 1; x<=5; x++)
{
		printf("\nDigite uma temperatura em Fahrenheit\n");
		scanf("%f", &tempf);
		
		tempc = (tempf-32)/1.8;
		printf("\nA temperatura em �C �: %.3f \n",tempc);
		
		if(tempc < 15)
			printf("\nEst� frio\n");
		else if (tempc>=15 && tempc<=30)
			printf("\nEst� normal\n");
		else 
			printf("\nEst� quente\n");
}
printf("\nFim do programa");	
system("pause");
return 0;
}

