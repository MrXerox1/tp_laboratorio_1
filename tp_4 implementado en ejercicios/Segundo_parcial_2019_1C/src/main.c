/*
 ============================================================================
 Name        : Modelo_segundo_Parcial.c
 Author      : sergio tirante
 Version     :
 Copyright   : Your copyright notice
 Description : C, Ansi-style
 ============================================================================
 */

#include <stdio.h>
#include <stdlib.h>
#include "Cliente.h"
#include "LinkedList.h"
#include "Controller.h"


int main()
{
    // Definir lista de empleados
    LinkedList* ListaCliente;

    // Crear lista empledos
    ListaCliente = ll_newLinkedList();

    // Leer empleados de archivo data.csv
    if(controller_cargarPorTexto("data.csv", ListaCliente)==0)
    {
        // Calcular fotos totales
        printf("Calculando Fotos totales\n");


        Cliente *cliente;
        int size = ll_len(ListaCliente);
        int i;

	    if(ListaCliente != NULL && size > 0)
	    {

	        for (i=0;i<size;i++)
	        {
	        	cliente = ll_get(ListaCliente, i);

	            if(cliente != NULL)
	            {
	                printf ("%d %s %s %d %f %s\n", cliente->id_venta, cliente->fecha, cliente->tipo_foto, cliente->cantidad,cliente-> precio_unitario,cliente->cuit_cliente);
	            }
	        }
	    }


        // Generar archivo de salida
        if(controller_generarArchivoInformes("informes.csv",ListaCliente)==0)
        {
            printf("Archivo generado correctamente\n");
        }
        else
            printf("Error generando archivo\n");
    }
    else
        printf("Error leyendo empleados\n");

    return 0;
}
