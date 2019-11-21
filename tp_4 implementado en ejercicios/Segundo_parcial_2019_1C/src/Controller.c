/*
 * Controller.c
 *
 *  Created on: 20 nov. 2019
 *      Author: sergio
 */
#include <stdio.h>
#include <stdlib.h>
#include "Cliente.h"
#include "Parser.h"
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
		parser_Clientes(pfile,pArrayListEmployee);
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

	int CantFotosTotales;
	int CantMayor150;
	int CantMayor300;
	int CantDePolaroReveladas;
	FILE *pfile;
	pfile = fopen(path, "w");
	if (pfile == NULL)
	{
		printf("el archivo no existe");
		exit(ERROR);
	} else
	{
		CantFotosTotales=ll_count(pArrayListEmployee,cliente_Contar_CantFotosTotal);
		printf(" fotos 1 %d\n",CantFotosTotales);
		CantMayor150=ll_count(pArrayListEmployee,cliente_Contar_Cantmayor150);
		printf(" fotos 2 %d\n",CantMayor150);
		CantMayor300=ll_count(pArrayListEmployee,cliente_Contar_CantMayor300);
		printf(" fotos 3 %d\n",CantMayor300);
		CantDePolaroReveladas=ll_count(pArrayListEmployee,cliente_Contar_CantPolaroidReveladas);
		printf(" fotos 4 %d\n",CantDePolaroReveladas);
		fprintf(pfile,
			"********************\n"
			"Informe de ventas\n"
			"********************\n"
			"- Cantidad de fotos reveladas totales: %d\n"
			"- Cantidad de ventas por un monto mayor a $150: %d\n"
			"- Cantidad de ventas por un monto mayor a $300: %d\n"
			"- Cantidad de fotos polaroids reveladas: %d\n"
			"********************\n",
			CantFotosTotales, CantMayor150, CantMayor300,
			CantDePolaroReveladas);
	}
	fclose(pfile);
	return RETORNO_EXITOSO;

}
