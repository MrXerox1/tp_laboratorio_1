/*
 ============================================================================
 Name        : tp_laboratorio_1.c
 Author      : sergio tirante
 Version     :
 Copyright   : Your copyright notice
 Description : Hello World in C, Ansi-style
 ============================================================================
 */

#include <stdio.h>
#include <stdio_ext.h>
#include <stdlib.h>
#include "utn.h"

int main(void)
{
	int retorno = ERROR_UNO;
	int opciones;
	char confirmacion;
	float numeroX=0;
	float numeroY=0;
	if(mostrarMenu(numeroX,numeroY)==0)
	{
		do
		{
			printf("elija una opcion \n");
			scanf("%d",&opciones);
			switch(opciones)
			{
			case 1:
				printf("%d",opciones);
				break;
			case 2:
				printf("%d",opciones);
				break;
			case 3:

				break;
			case 4:
				printf("%d",opciones);
				break;
			case 5:
				printf("%d",opciones);
				break;
			default:
				printf("error ingreso incorrecto");
				break;
			}
			printf("\nContinuar (s/n)? \n");
						__fpurge(stdin);
						scanf("%c",&confirmacion);
			retorno=RETORNO_EXITOSO;
		}while(confirmacion != 'n');
		return retorno;
	}
}
