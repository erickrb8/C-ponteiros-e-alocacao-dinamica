#include <stdlib.h>
#include <stdio.h>
#include <locale.h>

int main()
{   
    setlocale(LC_ALL, "portuguese");
	                   // l  c
	unsigned char matriz[10][10];      // 'a'=?  'b'=?   '1'=?    1 ao 255
	int l, c;
	
	for (l = 0; l<=9; l++  )
	{
		//estou na linha
		for (c=0; c<10; c++ )//percorro as colunas
		{
			matriz[l][c]= 1; 	
			printf("  %c", matriz[l][c]);	
		}	
		printf("\n"); //acabaram as colunas daquela linha
	}
	
	int pl, pc, pal, pac;
	pl= rand()%10; //0 a 9 --pensando no índice
	pc= rand()%10;

	matriz[pl][pc]= 2; 
	
	printf("\nQuais coordenadas você acha que está Wolly?");
	scanf("%i %i", &pal, &pac);
		
	if (pl == pal && pc== pac)
	{
		printf("\nAcertou");
		for (l = 0; l<=9; l++  )	{
		//estou na linha
		for (c=0; c<10; c++ ){//percorro as colunas
			printf("  %c", matriz[l][c]);	
		}	
		printf("\n"); //acabaram as colunas daquela linha
	}		
	}
	else
		printf("\nErrou\n");		
	
	
	
	
	
	
	getch();
	return 0;
}

