#include <stdio.h> 
#include <stdlib.h> 
#include <locale.h>

int main()
{
  setlocale(LC_ALL, "portuguese");
  int numA, Pac;
  char codigo;
  int ocGripe=0, ocVirose=0, ocCabeca=0, ocNaoDiag=0; 
  //ocGripe=ocVirose=ocCabeca=ocNaoDiag=0; 
  
  printf("\nQuantos atendimentos ser�o realizados?");
  scanf("%i", &numA); //4
  for (Pac=1; Pac <= numA; ++Pac )
  {
  	system("cls");
  	printf("\nNovo atendimento \n");
  	printf("\n\nC�digo: ");
  	codigo= getche(); //o c�digo tem que ser de 0 a 9
  	switch(codigo)
  	{
  		case '4': printf("\nGripe");
  				  printf("\nVitamina C");
  				  printf("\nOcorr�ncia: Gripe %i", ++ocGripe);
 
  		break;
  		case '1': case '2': 
  				  printf("\nVirose");
  				  printf("\nDescanso");
  				  ocVirose++;
  				  printf("\nOcorr�ncia: Virose %i", ocVirose);
  		break;
  		case '3' : case '5':
		  		  printf("\nDor de cabe�a");
  				  printf("\nRem�diosss");
  				  ++ocCabeca;
  		break;
  		case '6':
  				  printf("\nN�o definido");
  				  printf("\nExames");
  				  ++ocNaoDiag;
  		break;
  		default:
  				printf("\nC�digo inv�lido");
  				--Pac;
  		break;  			
  	} 
     printf("\n\n");
     system("pause");  	
  } //acabou o atendimento
  printf("\nRelat�rio di�rio\n");
  printf("====================");
  printf("\nOcorr�ncia: Gripe %i Cefaleia %i Virose %i N�o Diagnosticado %i ", ocGripe, ocCabeca,ocVirose,ocNaoDiag  );
  
 
  printf("\n\n");
  system("pause");  	
  return 0;	 
}
