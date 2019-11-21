/*
 * Parser.c
 *
 *  Created on: 20 nov. 2019
 *      Author: sergio
 */
#include <stdio.h>
#include <stdlib.h>
#include "Cliente.h"
#include "Parser.h"
#include "LinkedList.h"
int parser_Clientes(FILE* fileName, LinkedList* listaClientes)
{
	int retorno=ERROR;
	int r;
	Cliente* cliente;
	char id_venta[50], cuit_cliente[50], fecha[50], tipo_foto[50], cantidad[50], precio_unitario[50];
	r = fscanf(fileName, "%[^,],%[^,],%[^,],%[^,],%[^,],%[^\n]\n",id_venta,  fecha, tipo_foto, cantidad, precio_unitario, cuit_cliente);
	do
	{
		r = fscanf(fileName, "%[^,],%[^,],%[^,],%[^,],%[^,],%[^\n]\n",id_venta,  fecha, tipo_foto, cantidad, precio_unitario, cuit_cliente );
		if (r == 6)
		{
			//printf("Lei: %s %s %s  %s  %s %s\n", id_venta,  fecha, tipo_foto, cantidad, precio_unitario, cuit_cliente);
			cliente = cliente_newParametros(id_venta,  fecha, tipo_foto, cantidad, precio_unitario, cuit_cliente);
			if (cliente != NULL)
			{
				if (!ll_add(listaClientes, cliente))
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
