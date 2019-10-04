/*
 * funciones.c
 *
 *  Created on: 4 sep. 2019
 *      Author: alumno
 */
#include <stdio.h>
#include <stdio_ext.h>
#include <stdlib.h>
#include "biblioteca_sergio.h"
#define INDICE 0
int getInt(int *resultado,int maximo,int minimo,int reintentos,char* mensaje, char* mensajeError)
{
	int numero;
	int retorno= ERROR_UNO;
	do
	{
		printf("%s",mensaje);
		if(scanf("%d",&numero)==1 && numero >= minimo && numero <= maximo)
		{
			*resultado = numero;
			retorno = RETORNO_EXITOSO;
			break;
		}
		printf("%s",mensajeError);
		reintentos--;
	}while(reintentos >= 0);
	return retorno;
}

int initArrayInt(int *pArray , int limite, int valor)

{
	int retorno = -1;
	int i;
	if(pArray != NULL && limite > 0)
	{
		for(i=0;i<limite;i++)
		{
			pArray[i]=valor;
		}
		retorno = 0;
	}
	return retorno;
}

int getArrayInt(int *pArray, int limite, int maximo, int minimo, int reintentos, char *mensaje, char *mensajeError)
{
	int numero;
	char respuesta;
	int retorno= ERROR_UNO;
	int i = 0;
	if(pArray != NULL && limite > 0)
	{
		do
		{
			if(getInt(&numero,maximo,minimo,reintentos,mensaje,mensajeError)==0)
			{
				pArray[i] = numero;
					i++;
			}
			if(i == limite)
			{
				break;
			}
			printf("quiere seguir ingresando? (s/n)");
			__fpurge(stdin);
			scanf("%c",&respuesta);
		}while(respuesta != 'n');
	}
	return retorno;
}

int printArrayInt(int *pArray , int limite)
{
	int retorno = ERROR_UNO;
	int i;
	if(pArray != NULL && limite > 0)
	{
		for(i=INDICE;i<limite;i++)
		{
			printf("\n\t%d",pArray[i]);
		}
		retorno = RETORNO_EXITOSO;
	}
	return retorno;
}

int getMaximoMinimo(int *pArray , int limite, int *pMax, int *pMin)
{
	int numMax;
	int numMin;
	int i;
	int retorno = ERROR_UNO;
	if(pArray != NULL && limite > 0)
		{
			numMax=pArray[0];
			numMin=pArray[0];
		}
	for(i = 1;i < limite;i++)
		{
			if(pArray[i] > numMax)
			{
				numMax = pArray[i];
			}
			if(pArray[i] < numMin)
			{
				numMin=pArray[i];
			}
		}
	*pMax=numMax;
	*pMin=numMin;
	retorno = RETORNO_EXITOSO;
	return retorno;
}

int getPromedio(int *pArray , int limite, int *promedio)
{

	int retorno = ERROR_UNO;
	int i;
	int acumulador = 0;

	if(pArray != NULL && limite > 0)
		{
		for(i = 0;i < limite;i++)
			{
				acumulador= acumulador+pArray[i];
			}
		*promedio = acumulador/limite;
		retorno = RETORNO_EXITOSO;
		}

	return retorno;
}
int ordenarArrays(int *pArray,int limite)
{
	int flagDesordenado=ERROR_UNO;
	int i;
	int aux;
	int retorno = ERROR_UNO;
	while(flagDesordenado==ERROR_UNO)
	{
		flagDesordenado=RETORNO_EXITOSO;
		for(i=0;i<(limite-1);i++)
		{
			if(pArray[i] > pArray[i+1])
			{
				aux=pArray[i];
				pArray[i]=pArray[i+1];
				pArray[i+1]=aux;
				flagDesordenado=ERROR_UNO;
			}
		}
		retorno=RETORNO_EXITOSO;
	}
	return retorno;
}
