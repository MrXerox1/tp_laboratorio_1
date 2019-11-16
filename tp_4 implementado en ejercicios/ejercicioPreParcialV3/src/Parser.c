#include <stdio.h>
#include <stdlib.h>
#include "LinkedList.h"
#include "Empleado.h"

int parser_parseEmpleados(FILE* fileName, LinkedList* listaEmpleados)
{
	int retorno=ERROR;
	int r;
	Empleado* empleado;
	char idStr[50], nombreStr[50], horasTrabajadasStr[50];
	r = fscanf(fileName, "%[^,],%[^,],%[^\n]\n", idStr, nombreStr,
					horasTrabajadasStr);
	do
	{
		r = fscanf(fileName, "%[^,],%[^,],%[^\n]\n", idStr, nombreStr,
				horasTrabajadasStr);
		if (r == 3)
		{
			//printf("Lei: %s %s %s \n", idStr, nombreStr, horasTrabajadasStr);
			empleado = empleado_newParametros(idStr, nombreStr,
					horasTrabajadasStr);
			if (empleado != NULL)
			{
				if (!ll_add(listaEmpleados, empleado))
				{
					retorno = RETORNO_EXITOSO;
				}
			}
		}
		else
		{
			break;
		}
	} while (!feof(fileName));
	return retorno;
}

