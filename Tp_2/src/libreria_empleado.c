/*
 * libreria_empleado.c
 *
 *  Created on: 30 sep. 2019
 *      Author: sergio
 */

#include <stdio.h>
#include <stdlib.h>
#include <stdio_ext.h>
#include <string.h>
#include "biblioteca_sergio.h"
#include "libreria_empleado.h"
#define MENSAJE "ingrese id "
#define MENSAJE_ERROR "error ese id no es valido "
#define MINIMO 0
#define REINTENTOS 2

int mostrarMenu() {
	int retorno = ERROR;
	printf("\n1. alta del empleado\n");
	printf("2. MODIFICAR DATOS DEL empleado\n");
	printf("3. BAJA DEL empleado\n");
	printf("4. INFORMAR:\n1. Listado de los empleados ordenados alfabéticamente por Apellido y Sector.\n2. Total y promedio de los salarios, y cuántos empleados superan el salario promedio. ");
	printf("5. SALIR\n");
	return retorno;
}

int empleado_Inicializar(datosPersonales empleado[], int size) {
	int retorno = -1;
	if (empleado != NULL && size > 0) {
		for (; size > 0; size--) {
			empleado[size - 1].isEmpty = VACIO;
		}
		retorno = 0;
	}
	return retorno;
}

int ingresoEmpleado(datosPersonales *empleado) {
	int retorno = ERROR;

	datosPersonales aux;
	__fpurge(stdin);
	printf("Ingrese el Nombre \n");
	__fpurge(stdin);
	fgets(aux.nombre, sizeof(aux.nombre), stdin);
	__fpurge(stdin);

	printf("\nIngrese el apellido \n");
	fgets(aux.apellido, sizeof(aux.apellido), stdin);
	__fpurge(stdin);

	printf("\nIngrese sector \n");
	scanf("%d", &aux.sector);
	__fpurge(stdin);

	printf("\nIngrese numero de salario \n");
	__fpurge(stdin);
	scanf("%f", &aux.salario);

	*empleado = aux;

	retorno = RETORNO_EXITOSO;

	return retorno;
}

int empleadoAlta(datosPersonales *empleado, int size, int *contadorID) {
	int retorno = ERROR;
	int posicion;
	if (empleado != NULL && size > 0 && contadorID != NULL) {
		if (empleadoBuscarEmpty(empleado, size, &posicion) == ERROR) {
			printf("\nNo hay lugares vacios");
		} else {
			(*contadorID)++;
			ingresoEmpleado(&empleado[posicion]);
			empleado[posicion].idempleado = *contadorID;
			empleado[posicion].isEmpty = LLENO;
			printf("\nDatos Personales");
			printf("\n%s", empleado[posicion].nombre);
			printf("\n%s", empleado[posicion].apellido);
			printf("\n%d", empleado[posicion].sector);
			printf("\n%f", empleado[posicion].salario);
			printf("\n%d", empleado[posicion].idempleado);
			retorno = RETORNO_EXITOSO;
		}
	}
	return retorno;
}

int empleadoBuscarEmpty(datosPersonales empleado[], int size, int *posicion) {
	int retorno = ERROR;
	int i;
	if (empleado != NULL && size >= 0 && posicion != NULL) {
		for (i = 0; i < size; i++) {
			if (empleado[i].isEmpty == VACIO) {
				retorno = RETORNO_EXITOSO;
				*posicion = i;
				break;
			}
		}
	}
	return retorno;
}

int empleadoBuscarID(datosPersonales empleado[], int size, int valorBuscado,
		int *posicion) {
	int retorno = ERROR;
	int i;
	if (empleado != NULL && size >= 0) {
		for (i = 0; i < size; i++) {
			if (empleado[i].isEmpty == VACIO)
				continue;
			else if (empleado[i].idempleado == valorBuscado) {
				retorno = 0;
				*posicion = i;
				break;
			}
		}
	}
	return retorno;
}

int modificarPorId(datosPersonales empleado[], int contadorId) {
	int retorno = ERROR;
	int id;
	char salir = 'n';
	int indice;
	int opcion;
	__fpurge(stdin);
	if (getInt(&id, contadorId, MINIMO, REINTENTOS, MENSAJE, MENSAJE_ERROR)
			== 0) {
		if (empleadoBuscarID(empleado, contadorId, id, &indice) == 0) {

			do {
				printf("\nElegir opcion a modificar");
				printf("\n1)Nombre %s", empleado[indice].nombre);
				printf("\n2)Apellido %s", empleado[indice].apellido);
				printf("\n3)sector %d", empleado[indice].sector);
				printf("\n4)salario %f", empleado[indice].salario);
				printf("\n5)SALIR\n");
				__fpurge(stdin);
				scanf("%d", &opcion);
				__fpurge(stdin);
				switch (opcion) {
				case 1:
					__fpurge(stdin);
					printf("Ingrese el Nombre \n");
					__fpurge(stdin);
					fgets(empleado[indice].nombre,
							sizeof(empleado[indice].nombre),
							stdin);
					break;
				case 2:
					printf("\nIngrese el apellido \n");
					fgets(empleado[indice].apellido,
							sizeof(empleado[indice].apellido),
							stdin);

					break;
				case 3:
					__fpurge(stdin);

					printf("\nIngrese sector \n");
					scanf("%d", &empleado[indice].sector);
					break;

				case 4:
					printf("\nIngrese numero de salario \n");
					__fpurge(stdin);
					scanf("%f", &empleado[indice].salario);
					break;

				case 5:
					printf("esta seguro de que quiere salir? s/n");
					scanf("%s", &salir);
					break;
				default:
					printf("\nOpcion no valida");
				}
			} while (salir != 'n');
		} else {
			printf("error al modificar");
		}
	}

	return retorno;
}

int listarEmpleados(datosPersonales empleado[], int size) {
	int retorno = ERROR;
	int i;
	if (empleado != NULL && size >= 0) {
		for (i = 0; i < size; i++) {
			if (empleado[i].isEmpty == VACIO)
				continue;
			else
				printf("\n nombre:%s\n apellido:%s\n salario:%f\n sector:%d\nidempleado:%d\nisEmpty:%d\n", empleado[i].nombre,
						empleado[i].apellido, empleado[i].salario, empleado[i].sector,
						empleado[i].idempleado, empleado[i].isEmpty);
		}
		retorno = RETORNO_EXITOSO;
	}
	return retorno;
}

int bajaEmpleado(datosPersonales empleado[], int contadorId) {
	int retorno = ERROR;
	int id;
	int indice;
	__fpurge(stdin);
	if (getInt(&id, contadorId, MINIMO, REINTENTOS, MENSAJE,
	MENSAJE_ERROR) == RETORNO_EXITOSO) {
		if (empleadoBuscarID(empleado, contadorId, id,
				&indice)==RETORNO_EXITOSO) {
			if (empleado[indice].isEmpty == LLENO) {
				empleado[indice].isEmpty = VACIO;
				printf("el espacio de %d esta ahora vacio \n", id);
			} else {
				printf("[error] este id ya esta vacio");
			}
		}
	}
	return retorno;
}
void mostrarOrdenado(datosPersonales lista[],int size)
{
    int i,j;
    datosPersonales aux= {};
    for(i=0; i<size-1; i++)
    {
        for(j=i+1; j<size; j++)
        {//no se el por que a veces aparecen warnigs aca pero desaparecen al copilar de nuevo.
            if(strcmp(lista[i].apellido,lista[j].apellido)>0)
            {
                aux=lista[i];
                lista[i]=lista[j];
                lista[j]=aux;
            }
        }
    }
    for(i=0; i<size; i++)
    {
        if(lista[i].isEmpty==LLENO)
        {//no se el por que a veces aparecen warnigs aca pero desaparecen al copilar de nuevo.
            printf("\n APELLIDO: %s \t NOMBRE: %s \t salario: %f \t sector: %d",lista[i].apellido,lista[i].nombre,lista[i].salario,lista[i].sector);
        }
    }
    printf("\n");
}

int mostrarSalarioPromedio(datosPersonales lista[],int size)
{
	int retorno=ERROR;
    int i;
    int contadorActivos=0;
    datosPersonales acum;
    acum.salario = 0;
    	for(i=0; i<=size; i++)
    	{
    		if(lista[i].isEmpty==LLENO)
    		{
    		contadorActivos++;
    		acum.salario=lista[i].salario + acum.salario;
    		}
    	}
    	acum.salario=acum.salario/contadorActivos;
    	  printf("\n promedios de salario: %f",acum.salario);
    	  retorno=RETORNO_EXITOSO;
    return retorno;
}

