#include <stdio.h>
#include <stdlib.h>
#include "LinkedList.h"
#include "Employee.h"

/** \brief Parsea los datos los datos de los empleados desde el archivo data.csv (modo texto).
 *
 * \param path char*
 * \param pArrayListEmployee LinkedList*
 * \return int
 *
 */
int parser_EmployeeFromText(FILE *pFile, LinkedList *pArrayListEmployee)
{
	int retorno=ERROR;
	int r;
	Employee* empleado;
	char idStr[50], nombreStr[50], horasTrabajadasStr[50], sueldoStr[50];
	r = fscanf(pFile, "%[^,],%[^,],%[^,],%[^\n]\n", idStr, nombreStr,
					horasTrabajadasStr, sueldoStr);
	do
	{
		r = fscanf(pFile, "%[^,],%[^,],%[^,],%[^\n]\n", idStr, nombreStr,
				horasTrabajadasStr, sueldoStr);
		if (r == 4)
		{
			/*printf("Lei: %s %s %s %s\n", idStr, nombreStr, horasTrabajadasStr,
					sueldoStr);*/
			empleado = employee_newParametros(idStr, nombreStr,
					horasTrabajadasStr, sueldoStr);
			if (empleado != NULL)
			{
				if (!ll_add(pArrayListEmployee, empleado))
				{
					retorno = RETORNO_EXITOSO;
				}
			}
		}
		else
		{
			break;
		}
	} while (!feof(pFile));
	return retorno;
}

/** \brief Parsea los datos los datos de los empleados desde el archivo data.csv (modo binario).
 *
 * \param path char*
 * \param pArrayListEmployee LinkedList*
 * \return int
 *
 */
int parser_EmployeeFromBinary(FILE *pfile, LinkedList *pArrayListEmployee)
 {
	int retorno = ERROR;
	int cantidadDatos;
	Employee *auxEmpleado;
	do
	{
		auxEmpleado = employee_new();

		if (auxEmpleado != NULL)
		{
			cantidadDatos = fread(auxEmpleado, sizeof(Employee), 1, pfile);
		}

		if (cantidadDatos == 1) {
			if (!ll_add(pArrayListEmployee, auxEmpleado))
			{
				retorno = 0;
			}
		} else
		{
			employee_delete(auxEmpleado);
		}
	} while (!feof(pfile));

	return retorno;
}
