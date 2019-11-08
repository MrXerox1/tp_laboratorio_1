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
		switch (option) {
		case 1:
			controller_loadFromText("data.csv", listaEmpleados);
			break;
		case 2:
			controller_saveAsBinary("data.bin", listaEmpleados);
			break;
		case 3:
			   controller_addEmployee(listaEmpleados);
			break;
		case 4:
			controller_editEmployee(listaEmpleados);
			break;
		case 5:
			controller_removeEmployee(listaEmpleados);
			break;
		case 6:
			controller_ListEmployee(listaEmpleados);
			break;
		case 7:
			controller_sortEmployee(listaEmpleados);
			break;
		case 8:
			controller_saveAsText("data_Escribir.csv",listaEmpleados);
			break;
		case 9:
			break;
		case 10:
			break;
		default:
			break;
		}
	} while (option != 10);
	return 0;

	printf("%d %d %d",course,lets,find);
	return 0;
}


