#include <stdio.h>
#include <stdlib.h>
#include <stdio_ext.h>
#include <string.h>
#include "Employee.h"
#include "utn.h"
static int isValidIdString(char *id);
static int isValidNombre(char *nombre);
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
				employee_getSueldoString(this,sueldoStr) == EXIT_SUCCESS &&
				employee_setIdString(this,idStr) == EXIT_SUCCESS )
		{
				retorno = this;
		}
		else
		{
			employee_delete(this);
		}
	}

	return retorno;
}

int employee_getIdString(Employee *this,char *id)
{
	int retorno = ERROR;

	if(this != NULL && isValidIdString(id))
	{
		this->id=atoi(id);
		retorno = EXIT_SUCCESS;
	}

	return retorno;
}

int employee_setIdString(Employee *this,char *id)
{
	int retorno = ERROR;

	if(this != NULL && id != NULL)
	{
		sprintf(id,"%d",this->id);
		retorno = EXIT_SUCCESS;
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

	if(this != NULL && isValidNombre(nombre))
	{
		strcpy(this->nombre,nombre);
		retorno = EXIT_SUCCESS;
	}

	return retorno;
}

int employee_getNombre(Employee* this,char* nombre)
{
	int retorno = EXIT_ERROR;

	if(this != NULL && nombre != NULL)
	{
		strcpy(nombre,this->nombre);
		retorno = EXIT_SUCCESS;
	}

	return retorno;
}

static int isValidNombre(char *nombre)
{
	int retorno = EXIT_ERROR;

	if(nombre != NULL)
	{
		esNombreOApellido(nombre,"\nERROR_NOMBRE");
		retorno = EXIT_SUCCESS;
	}

	return retorno;
}

int employee_setHorasTrabajadasString(Employee* this,char *horasTrabajadas){
	int retorno = ERROR;

		if(this != NULL && horasTrabajadas != NULL)
		{
			sprintf(horasTrabajadas,"%d",this->horasTrabajadas);
			retorno = EXIT_SUCCESS;
		}

		return retorno;
}
int employee_getHorasTrabajadasString(Employee* this,char *horasTrabajadas){
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

int employee_setSueldoString(Employee* this,char* sueldo)
{
	int retorno = ERROR;

			if(this != NULL && sueldo != NULL)
			{
				sprintf(sueldo,"%d",this->sueldo);
				retorno = EXIT_SUCCESS;
			}

			return retorno;
}
int employee_getSueldoString(Employee* this,char* sueldo)
{
	int retorno = ERROR;

			if(this != NULL && isValidSueldoString(sueldo))
			{
				this->sueldo=atoi(sueldo);
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

void employee_delete(Employee *this){
	free(this);
}
