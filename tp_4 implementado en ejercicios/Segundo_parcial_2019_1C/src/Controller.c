/*
 * Controller.c
 *
 *  Created on: 20 nov. 2019
 *      Author: sergio
 */
#include <stdio.h>
#include <stdlib.h>
#include "Cliente.h"

#include "LinkedList.h"

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
		parser_parseClientes(pfile,pArrayListEmployee);
	}
	fclose(pfile);
    return RETORNO_EXITOSO;
}
/** \brief Guarda los datos de los clientes en el archivo data.csv (modo texto).
 *
 * \param path char*
 * \param pArrayListEmployee LinkedList*
 * \return int
 *
 */
int controller_generarArchivoInformes(char* path , LinkedList* pArrayListEmployee)
{
	int i;
	int CantFotosTotales;
	int CantMayor150;
	- CantMayor300;
	- CantdeReveladas;
	Cliente *auxCliente;
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
			auxCliente = ll_get(pArrayListEmployee, i);
			fprintf(pfile, "%d,\n",);
		}
		return RETORNO_EXITOSO;
		}
		fclose(pfile);

}
