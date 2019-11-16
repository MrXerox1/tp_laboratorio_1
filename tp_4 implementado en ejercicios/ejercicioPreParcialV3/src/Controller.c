#include <stdio.h>
#include <stdlib.h>
#include <stdio_ext.h>
#include "LinkedList.h"
#include "Empleado.h"
#include "Parser.h"
#include "utn.h"
/** \brief Carga los datos de los empleados desde el archivo data.csv (modo texto).
 *
 * \param path char*
 * \param pArrayListEmployee LinkedList*
 * \return int
 *
 */
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
int controller_generarArchivoSueldos(char* path , LinkedList* pArrayListEmployee)
{
	int i;
	int id;
	int horasTrabajadas;
	int sueldo;
	char nombre[128];
	Empleado* auxEmpleado;
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


