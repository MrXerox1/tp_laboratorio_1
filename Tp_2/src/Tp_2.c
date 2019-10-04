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

int main()
{
	int opcion;
	int contadorIdEmpleado = 0;
	int retorno=ERROR;

	datosPersonales arrayEmpleado[QTY_TIPO];
	empleado_Inicializar(arrayEmpleado, QTY_TIPO);

	do {
		mostrarMenu();
		printf("ingrese una opcion ");
		fflush(stdin);
		scanf("%d",&opcion);

		switch (opcion) {
		case 1: //Alta
			empleadoAlta(arrayEmpleado, QTY_TIPO, &contadorIdEmpleado);
			break;

		case 2:
			modificarPorId(arrayEmpleado,QTY_TIPO);
			break;

		case 3:
			bajaEmpleado(arrayEmpleado, contadorIdEmpleado);

			break;

		case 4:
			//no se el por que a veces aparecen warnigs aca pero desaparecen al copilar de nuevo.
			mostrarOrdenado(arrayEmpleado,QTY_TIPO);
			mostrarSalarioPromedio(arrayEmpleado,QTY_TIPO);
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
