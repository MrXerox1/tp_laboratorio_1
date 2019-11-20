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
int main()
{
    // Definir lista de empleados
    LinkedList* listaEmpleados;

    // Crear lista empledos
    //...
    listaEmpleados = ll_newLinkedList();
    // Leer empleados de archivo data.csv
    if(controller_cargarPorTexto("data.csv", listaEmpleados)==0)
    {
        // Calcular sueldos
        printf("Calculando sueldos de empleados\n");
        ll_map(listaEmpleados,em_calcularSueldo);

        // Generar archivo de salida
        if(controller_generarArchivoSueldos("informes.csv",listaEmpleados)==0)
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
