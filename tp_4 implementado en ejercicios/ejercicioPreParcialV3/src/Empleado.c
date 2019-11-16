#include <stdio.h>
#include <stdlib.h>
#include <stdio_ext.h>
#include <string.h>
#include "Empleado.h"
#include "utn.h"
static int isValidId(char *id);

Empleado* empleado_new()
{
	return malloc(sizeof(Empleado));
}
void empleado_delete(Empleado *this){
	free(this);
}
Empleado* empleado_newParametros(char* idStr,char* nombreStr,char* horasTrabajadasStr)
{
	Empleado *retorno = NULL;
	Empleado *this;
	this = empleado_new();

	if(this != NULL)
	{
		if(		empleado_setNombre(this,nombreStr) == EXIT_SUCCESS &&
				empleado_setHorasTrabajadas(this,horasTrabajadasStr) == EXIT_SUCCESS &&
				empleado_setId(this,idStr) == EXIT_SUCCESS )
		{
				retorno = this;
		}
		else
		{
			printf("borre %s\n",idStr);
			empleado_delete(this);
		}
	}

	return retorno;
}
int empleado_setId(Empleado *this,char *id)
{
	int retorno = ERROR;

	if(this != NULL && isValidId(id))
	{
		this->id=atoi(id);
		retorno = EXIT_SUCCESS;
	}

	return retorno;
}

int empleado_getId(Empleado *this,int *id)
{
	int retorno = ERROR;

		if (this != NULL && id != NULL)
		{
			*id = this->id;

			retorno = RETORNO_EXITOSO;
		}
	return retorno;
}

static int isValidId(char *id)
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

int empleado_setNombre(Empleado* this,char* nombre)
{
	int retorno = ERROR;

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

int empleado_getNombre(Empleado* this,char* nombre)
{
	int retorno = ERROR;

	 if(this != NULL && nombre != NULL)
	    {
	        strncpy(nombre,this->nombre,128);

	        retorno = 0;
	    }
	    return retorno;

	return retorno;
}

int empleado_getHorasTrabajadas(Empleado* this,int *horasTrabajadas){
	int retorno = ERROR;

	    if(this != NULL && horasTrabajadas != NULL)
	    {
	        *horasTrabajadas = this->horasTrabajadas;

	        retorno = 0;
	    }
		return retorno;
}
int empleado_setHorasTrabajadas(Empleado* this,char *horasTrabajadas){
	int retorno = ERROR;

		if(this != NULL)
		{
			this->horasTrabajadas=atoi(horasTrabajadas);
			retorno = EXIT_SUCCESS;
		}

		return retorno;
}

int empleado_getSueldo(Empleado* this,int* sueldo)
{
	int retorno = ERROR;

	if(this != NULL && sueldo != NULL)
	    {
	        *sueldo = this->sueldo;

	        retorno = 0;
	    }
			return retorno;
}
int empleado_setSueldo(Empleado* this,int* sueldo)
{
	int retorno = ERROR;
	if (this != NULL && sueldo != NULL) {

		this->sueldo = *sueldo;
		retorno = EXIT_SUCCESS;
	}
	return retorno;
}

/*Luego, debera calcular el campo "sueldo" de cada uno de los empleados leidos, segun la horas que trabajaron, con el
    siguiente criterio:
    Los valores de horas varian entre 80 y 240.
    - Las primeras 120 horas la hora vale $180
    - De 120 a 160 horas, la hora vale $240
    - De 160 a 240 horas, la hora vale $350

    Para hacer este calculo, se debera desarrollar la funcion "map" en al biblioteca LinkedList, La cual recibe la lista y una funcion.
    La funcion map ejecutara la funcion recibida como parametro por cada item de la lista, y le pasaran en cada llamada, uno de los items.
    De esta manera la funcion pasada como parametro podra realizar un calculo con el item recibido, en este caso, calcular el sueldo.
 * */
int em_calcularSueldo(void* this)
 {
	int retorno= ERROR;
	int horasTrabajadas;
	int sueldo;
	int auxhorasTrabajadas;
	// recibo elemento empleado como void.
	empleado_getHorasTrabajadas(this, &horasTrabajadas);
	if (horasTrabajadas <= 120)
	{
		sueldo = horasTrabajadas * 180;
		empleado_setSueldo(this, &sueldo);
		retorno = 0;
	}
	else if (horasTrabajadas <= 160)
	{
		auxhorasTrabajadas= 120 * 180;
		 horasTrabajadas = horasTrabajadas - 120;
		 sueldo = auxhorasTrabajadas + horasTrabajadas * 240;
		empleado_setSueldo(this, &sueldo);
		retorno = 0;
	}
	else if (horasTrabajadas <= 240)
	{
		auxhorasTrabajadas= 120 * 180 + 40 * 240;
		horasTrabajadas = horasTrabajadas - 160;
		sueldo = auxhorasTrabajadas + horasTrabajadas * 350;
		empleado_setSueldo(this, &sueldo);
		retorno = 0;
	}

	// hacer calculo de sueldo y escribirlo en campo sueldo del empleado
	return retorno;
}
