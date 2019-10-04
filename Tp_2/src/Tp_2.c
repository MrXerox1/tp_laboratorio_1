/*
 ============================================================================
 Name        : Tp_2.c
 Author      : Sergio Tirante
 Version     :
 Copyright   : Your copyright notice
 Description : Hello World in C, Ansi-style
 ============================================================================
 */
#include <stdio.h>
#include <stdlib.h>
#include "libreria_empleado.h"
#include "biblioteca_sergio.h"
#define REINTENTOS 2
#define MENSAJE "\ningrese una opcion  "
#define MENSAJE_ERROR "\n[error]opcion ingresada no es valida\n"
int main()
{
	int opcion;
	int contadorIdEmpleado = 0;
	int retorno=ERROR;

	datosPersonales arrayEmpleado[QTY_TIPO];
	empleado_Inicializar(arrayEmpleado, QTY_TIPO);

	do
	{
		mostrarMenu();
		fflush(stdin);
		getInt(&opcion, 5, 1, REINTENTOS, MENSAJE, MENSAJE_ERROR);
		switch (opcion)
		{
		case 1: //Alta
			empleadoAlta(arrayEmpleado, QTY_TIPO, &contadorIdEmpleado);
			break;

		case 2:
			if(ConfirmarDatoCargado(arrayEmpleado,QTY_TIPO)==RETORNO_EXITOSO)
			{
			modificarPorId(arrayEmpleado,QTY_TIPO);
			}else
			{
				printf("---------------------\t[error] primero ingrese un empleado\t-----------------");
			}

			break;

		case 3:
			if(ConfirmarDatoCargado(arrayEmpleado,QTY_TIPO)==RETORNO_EXITOSO)
			{
				bajaEmpleado(arrayEmpleado, contadorIdEmpleado);
			}else
			{
				printf("---------------------\t[error] primero ingrese un empleado\t-----------------");
			}

			break;

		case 4:

			if (ConfirmarDatoCargado(arrayEmpleado, QTY_TIPO) == RETORNO_EXITOSO)
			{
				mostrarOrdenado(arrayEmpleado, QTY_TIPO);
				mostrarSalarioPromedio(arrayEmpleado, QTY_TIPO);
			} else
			{
				printf(
						"---------------------\t[error] primero ingrese un empleado\t-----------------");
			}


			break;
		case 5:
			printf("a elegido salir del programa");
			break;
		default:
			printf("\nOpcion no valida");
		}
	} while (opcion != 5);
	return retorno;
}
