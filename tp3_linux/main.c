#include <stdio.h>
#include <stdlib.h>
#include <stdio_ext.h>
#include "LinkedList.h"
#include "Controller.h"
#include "Employee.h"

/****************************************************
    Menu:
     1. Cargar los datos de los empleados desde el archivo data.csv (modo texto).
     2. Cargar los datos de los empleados desde el archivo data.csv (modo binario).
     3. Alta de empleado
     4. Modificar datos de empleado
     5. Baja de empleado
     6. Listar empleados
     7. Ordenar empleados
     8. Guardar los datos de los empleados en el archivo data.csv (modo texto).
     9. Guardar los datos de los empleados en el archivo data.csv (modo binario).
    10. Salir
*****************************************************/



int f1(int *a, int b,int (*foo)(int,int)) {
	*a = *a * 2;
	*a = foo(*a,b);
	return (*a);
}

int f2(int a, int b) {
	 a = b*b;
	 return a;
}


enum colors {lets,find,course};

int main()
{
	int flag=0;
	int option;
	LinkedList *listaEmpleados = ll_newLinkedList();

	do {
		printf("\nSeleccione una opcion del menu: \n");
		printf("1)Cargar los datos de los empleados desde el archivo (texto)\n");
		printf("2)Cargar los datos de los empleados desde el archivo (binario)\n");
		printf("3)Alta de empleado\n");
		printf("4)Modificacion de empleado\n");
		printf("5)Baja de empleado\n");
		printf("6)Listar empleados\n");
		printf("7)Ordenar empleados\n");
		printf("8)Guardar los datos de los empleados en el archivo (texto)\n");
		printf("9)Guardar los datos de los empleados en el archivo (binario)\n");
		printf("10)Salir\n");
		__fpurge(stdin);
		scanf("%d", &option);

		switch (option)
		{
		case 1:
			if (flag == 0)
			{
				controller_loadFromText("data.csv", listaEmpleados);
				flag = 1;
			}
			else
			{
							printf("no puede cargar ambas maneras a la vez\n");
			}
			break;
		case 2:
			if (flag == 0)
			{
				controller_loadFromBinary("data.bin", listaEmpleados);
				flag = 1;
			}
			else {
				printf("no puede cargar ambas maneras a la vez\n");
			}
			break;
		case 3:
			if (flag == 1)
			{
				controller_addEmployee(listaEmpleados);
			}
			else
			{
				printf("debe cargar de forma texto o binario antes de usar otra opcion\n");
			}
			break;
		case 4:
			if (flag == 1)
			{
				controller_editEmployee(listaEmpleados);
			}
			else
			{
				printf("debe cargar de forma texto o binario antes de usar otra opcion\n");
			}
			break;
		case 5:
			if (flag == 1)
			{
				controller_removeEmployee(listaEmpleados);
			}
			else
			{
				printf("debe cargar de forma texto o binario antes de usar otra opcion\n");
			}
			break;
		case 6:
			if (flag == 1)
			{
				controller_ListEmployee(listaEmpleados);
			}
			else
			{
				printf("debe cargar de forma texto o binario antes de usar otra opcion\n");
			}
			break;
		case 7:
			if (flag == 1)
			{
				controller_sortEmployee(listaEmpleados);
			}
			else
			{
				printf("debe cargar de forma texto o binario antes de usar otra opcion\n");
			}
			break;
		case 8:
			if (flag == 1) {
				controller_saveAsText("data_Escribir.csv", listaEmpleados);
			} else {
				printf("debe cargar de forma texto o binario antes de usar otra opcion\n");
			}
			break;
		case 9:
			if (flag == 1) {
				controller_saveAsBinary("data.bin", listaEmpleados);
			} else {
				printf("debe cargar de forma texto o binario antes de usar otra opcion\n");
			}
			break;
		case 10:
			break;
		default:
			break;
		}
	} while (option != 10);
	return 0;

	printf("%d %d %d", course, lets, find);
	return 0;
}


