#include <stdlib.h>
#include <stdio.h>
#include <locale.h>

int main()
{
	setlocale(LC_ALL, "portuguese");
	int vetor[5], i;
	//i   0   1   2  3  4
	 //   7   2   4  1  9
	 //n  7   4   4  1  8 ---acertos 3
	srand(time(NULL));
	
	for (i= 0; i< 5; ++i  )
	{
	   vetor[i] = 1 +(rand() %10);
	}
    
    system("color B2");
    printf("\nJogo da Memória\n Tente adivinhar \n");
    for (i=0; i<5; i++ ) //++i 0 1 2 3 4 (<5)
    {
    	printf("\t%i ", vetor[i]);
    	_sleep(100);  
	}
	_sleep(1000);
	system("cls");
	printf("\nQuais foram os números: ");
	int acertos=0;
	int num;
	for (i=0; i<=4; i+=1 )
	{
		scanf("%i", &num);
		if (num ==  vetor[i]   )	
		{  ++acertos; }
	}
    printf("\nTotal de acertos %i ", acertos);
    //printf("%i  %i  %i  %i  %i" , vetor[0], vetor[1], vetor[2],...)
    
    
    /*	
	vetor[0] = 1 +(rand() %10);  //1 a 10
    vetor[1] = 1 + (rand() %10);	
	vetor[2] = 1 + (rand() %10);	
	vetor[3] = 1 + (rand() %10);	
	vetor[4] = 1 + (rand() %10);	
	*/
	getch();
	return 0;
}
