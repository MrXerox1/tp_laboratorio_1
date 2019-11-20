/*
 * Controller.c
 *
 *  Created on: 20 nov. 2019
 *      Author: sergio
 */
#include <stdio.h>
#include <stdlib.h>
#include "Cliente.h"

int controller_cargarPorTexto(char* path , LinkedList* pArrayListEmployee)
{
	FILE* pfile;
	pfile=fopen(path,"r");
	if(pfile==NULL)
	{
		printf("el archivo no existe");
		exit(ERROR);
	}
	else
	{
		parser_parseEmpleados(pfile,pArrayListEmployee);
	}
	fclose(pfile);
    return RETORNO_EXITOSO;
}
/** \brief Guarda los datos de los empleados en el archivo data.csv (modo texto).
 *
 * \param path char*
 * \param pArrayListEmployee LinkedList*
 * \return int
 *
 */
int controller_generarArchivoInformes(char* path , LinkedList* pArrayListEmployee)
{
	int i;
	int id_venta;
	char cuit_cliente;
	char fecha[50];
	char tipo_foto[50];
	int cantidad;
	int precio_unitario;
	Empleado *auxEmpleado;
	int size = ll_len(pArrayListEmployee);
	FILE* pfile;
		pfile=fopen(path,"w");
		if(pfile==NULL)
		{
			printf("el archivo no existe");
			exit(ERROR);
		}
		else
		{
		fprintf(pfile, "id\tnombre\thoras trabajadas\tsueldo\n");
		for (i = 0; i < size; i++)
		{
			auxEmpleado = ll_get(pArrayListEmployee, i);
			empleado_getId(auxEmpleado, &id);
			empleado_getNombre(auxEmpleado, nombre);
			empleado_getHorasTrabajadas(auxEmpleado, &horasTrabajadas);
			empleado_getSueldo(auxEmpleado,&sueldo);
			fprintf(pfile, "%d,%s,%d,%d\n", id,nombre, horasTrabajadas,sueldo);
		}
		return RETORNO_EXITOSO;
		}
		fclose(pfile);

}
