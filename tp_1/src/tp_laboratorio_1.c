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
#define NUM_SIN_CARGA 0.0
#define MAX_NUMERO 200
#define MIN_NUMERO -200
#define REINT_NUMERO 2
#define MENSAJE "ingrese un numero: \n"
#define MENSAJE_ERROR "Error intente de nuevo\n"

int main(void)
{
	int retorno = ERROR_UNO;
	int opciones;
	char confirmacion;
	float numeroX=NUM_SIN_CARGA;
	float numeroY=NUM_SIN_CARGA;
	float resultadoSuma=NUM_SIN_CARGA;
	float resultadoResta=NUM_SIN_CARGA;
	float resultadoDivision=NUM_SIN_CARGA;
	float resultadoProducto=NUM_SIN_CARGA;
	int resultadoFactorialX=NUM_SIN_CARGA;
	int resultadoFactorialY=NUM_SIN_CARGA;
	do
	{
		//muestra el menu
		if(mostrarMenu(numeroX,numeroY)==RETORNO_EXITOSO)
			{
			//se da a elegir opcion del menu
			printf("elija una opcion \n");
			scanf("%d",&opciones);
			switch(opciones)
			{
			case 1:
				//ingresa numero A
				if(getInt(&numeroX,MAX_NUMERO,MIN_NUMERO,REINT_NUMERO,MENSAJE,MENSAJE_ERROR)==RETORNO_EXITOSO)
				{
					retorno=RETORNO_EXITOSO;
				}
				break;
			case 2:
				//ingresa numero B
				if(getInt(&numeroY,MAX_NUMERO,MIN_NUMERO,REINT_NUMERO,MENSAJE,MENSAJE_ERROR)==RETORNO_EXITOSO)
				{
					retorno=RETORNO_EXITOSO;
				}
				break;
			case 3:
				//lama a la funcion que calcula las operaciones
				if(CalcularOperaciones(numeroX,numeroY,&resultadoSuma,&resultadoResta,&resultadoDivision,
						&resultadoProducto,&resultadoFactorialX,&resultadoFactorialY)==RETORNO_EXITOSO)
				{
					retorno=RETORNO_EXITOSO;
				}
				break;
			case 4:
				//llama a la funcion mostrarResultados
				if(mostrarResultados(numeroY,resultadoSuma,resultadoResta,
					resultadoDivision,resultadoProducto,resultadoFactorialX,
					resultadoFactorialY)==RETORNO_EXITOSO)
				{
					retorno=RETORNO_EXITOSO;
				}
				break;
			case 5:
				//mensaje de confirmacion de salida
				printf("\nEsta seguro que quiere salir? (s/n) \n");
				__fpurge(stdin);
				scanf("%c",&confirmacion);
				break;
			default:
				//default para cualquier cosa igresada que no este contemplada
				printf("error ingreso incorrecto");
				break;
			}
			__fpurge(stdin);
			retorno=RETORNO_EXITOSO;
		}
	}while(confirmacion != 's');
	return retorno;
}
