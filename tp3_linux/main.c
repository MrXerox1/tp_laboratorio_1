#include <stdio.h>
#include <stdlib.h>
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
		fflush(stdin);
		scanf("%d", &option);
		switch (option) {
		case 1:
			controller_loadFromText("data.csv", listaEmpleados);
			break;
		case 2:
			break;
		case 3:
			break;
		case 4:
			break;
		case 5:
			break;
		case 6:
			break;
		case 7:
			break;
		case 8:
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


