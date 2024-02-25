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
  
  printf("\nQuantos atendimentos serão realizados?");
  scanf("%i", &numA); //4
  for (Pac=1; Pac <= numA; ++Pac )
  {
  	system("cls");
  	printf("\nNovo atendimento \n");
  	printf("\n\nCódigo: ");
  	codigo= getche(); //o código tem que ser de 0 a 9
  	switch(codigo)
  	{
  		case '4': printf("\nGripe");
  				  printf("\nVitamina C");
  				  printf("\nOcorrência: Gripe %i", ++ocGripe);
 
  		break;
  		case '1': case '2': 
  				  printf("\nVirose");
  				  printf("\nDescanso");
  				  ocVirose++;
  				  printf("\nOcorrência: Virose %i", ocVirose);
  		break;
  		case '3' : case '5':
		  		  printf("\nDor de cabeça");
  				  printf("\nRemédiosss");
  				  ++ocCabeca;
  		break;
  		case '6':
  				  printf("\nNão definido");
  				  printf("\nExames");
  				  ++ocNaoDiag;
  		break;
  		default:
  				printf("\nCódigo inválido");
  				--Pac;
  		break;  			
  	} 
     printf("\n\n");
     system("pause");  	
  } //acabou o atendimento
  printf("\nRelatório diário\n");
  printf("====================");
  printf("\nOcorrência: Gripe %i Cefaleia %i Virose %i Não Diagnosticado %i ", ocGripe, ocCabeca,ocVirose,ocNaoDiag  );
  
 
  printf("\n\n");
  system("pause");  	
  return 0;	 
}
