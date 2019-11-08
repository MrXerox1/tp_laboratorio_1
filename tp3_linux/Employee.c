#include <stdio.h>
#include <stdlib.h>
#include <stdio_ext.h>
#include <string.h>
#include "Employee.h"
#include "utn.h"
static int isValidIdString(char *id);
static int isValidhorasTrabaString(char *horasTrabajadas);
static int isValidSueldoString(char *sueldo);

Employee* employee_new()
{
	return malloc(sizeof(Employee));
}

Employee* employee_newParametros(char* idStr,char* nombreStr,char* horasTrabajadasStr, char *sueldoStr)
{
	Employee *retorno = NULL;
	Employee *this;
	this = employee_new();

	if(this != NULL)
	{
		if(		employee_setNombre(this,nombreStr) == EXIT_SUCCESS &&
				employee_setHorasTrabajadasString(this,horasTrabajadasStr) == EXIT_SUCCESS &&
				employee_setSueldoString(this,sueldoStr) == EXIT_SUCCESS &&
				employee_setIdString(this,idStr) == EXIT_SUCCESS )
		{
				retorno = this;
		}
		else
		{
			printf("borre %s\n",idStr);
			employee_delete(this);
		}
	}

	return retorno;
}

int employee_setIdString(Employee *this,char *id)
{
	int retorno = ERROR;

	if(this != NULL && isValidIdString(id))
	{
		this->id=atoi(id);
		retorno = EXIT_SUCCESS;
	}

	return retorno;
}

int employee_getIdString(Employee *this,int *id)
{
	int retorno = ERROR;

		if (this != NULL && id != NULL)
		{
			*id = this->sueldo;

			retorno = RETORNO_EXITOSO;
		}
	return retorno;
}

static int isValidIdString(char *id)
{
	int retorno = ERROR;

	if(id != NULL)
	{
		if(esSoloNumerosPositivos(id,"\nERROR_ID"))
		{
			retorno = EXIT_SUCCESS;
		}
	}

	return retorno;
}

int employee_setNombre(Employee* this,char* nombre)
{
	int retorno = EXIT_ERROR;

	if(this != NULL)
	{
		if(strlen(nombre) > 0)
        {
            strncpy(this->nombre,nombre, sizeof(this->nombre));
            retorno = 0;
        }
	}

	return retorno;
}

int employee_getNombre(Employee* this,char* nombre)
{
	int retorno = EXIT_ERROR;

	 if(this != NULL && nombre != NULL)
	    {
	        strncpy(nombre,this->nombre,128);

	        retorno = 0;
	    }
	    return retorno;

	return retorno;
}

int employee_getHorasTrabajadasString(Employee* this,int *horasTrabajadas){
	int retorno = ERROR;

	    if(this != NULL && horasTrabajadas != NULL)
	    {
	        *horasTrabajadas = this->horasTrabajadas;

	        retorno = 0;
	    }
		return retorno;
}
int employee_setHorasTrabajadasString(Employee* this,char *horasTrabajadas){
	int retorno = ERROR;

		if(this != NULL && isValidhorasTrabaString(horasTrabajadas))
		{
			this->horasTrabajadas=atoi(horasTrabajadas);
			retorno = EXIT_SUCCESS;
		}

		return retorno;
}

static int isValidhorasTrabaString(char *horasTrabajadas)
{
	int retorno = ERROR;

	if(horasTrabajadas != NULL)
	{
		if(esSoloNumerosPositivos(horasTrabajadas,"\nERROR_HORA_TRABAJO"))
		{
			retorno = EXIT_SUCCESS;
		}
	}

	return retorno;
}

int employee_getSueldoString(Employee* this,int* sueldo)
{
	int retorno = ERROR;

	if(this != NULL && sueldo != NULL)
	    {
	        *sueldo = this->sueldo;

	        retorno = 0;
	    }
			return retorno;
}
int employee_setSueldoString(Employee* this,char* sueldo)
{
	int retorno = ERROR;
	if (this != NULL && sueldo != NULL && isValidSueldoString(sueldo)) {

		this->sueldo = atoi(sueldo);
		retorno = EXIT_SUCCESS;
	}
	return retorno;
}

static int isValidSueldoString(char *sueldo)
{
	int retorno = ERROR;

	if(sueldo != NULL)
	{
		if(esSoloNumerosPositivos(sueldo,"\nERROR_SUELDO"))
		{
			retorno = EXIT_SUCCESS;
		}
	}

	return retorno;
}

int employee_buscarIdMax(LinkedList *pArrayListEmployee)
{
	int flag = 0;
	int maxId;
	int i;
	Employee *auxEmpleado;
	int size = ll_len(pArrayListEmployee);
	for (i = 1; i < size; i++)
	{
		auxEmpleado = ll_get(pArrayListEmployee, i);
		if (auxEmpleado->id > maxId || flag == 0)
		{
			flag = 1;
			maxId = auxEmpleado->id;
		}
	}

	return maxId;
}



int employee_sort(void* Employee1, void* Employee2)
{
	Employee* empleado1 = (Employee*) Employee1;
	Employee* empleado2 = (Employee*) Employee2;
	if(empleado1->sueldo>empleado2->sueldo)
	{
		return 1;
	}
	else if(empleado1->sueldo<empleado2->sueldo)
	{
		return -1;
	}
	else
	{
		return 0;
	}

}
int empleadoBuscarID(LinkedList *pArrayListEmployee, int size, int valorBuscado,
		int *posicion)
{
	__fpurge(stdin);
	Employee *empleado;
	int retorno = ERROR;
	int i;
	if (pArrayListEmployee != NULL && size > 0)
	{
		for (i = 0; i < size; i++)
		{
			empleado = ll_get(pArrayListEmployee, i);
			if (empleado->id == valorBuscado)
			{
				retorno = RETORNO_EXITOSO;
				*posicion = i;
				break;
			}
		}
	}
	return retorno;
}

void employee_delete(Employee *this){
	free(this);
}
