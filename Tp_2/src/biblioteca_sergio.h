/*
 * biblioteca_sergio.h
 *
 *  Created on: 4 sep. 2019
 *      Author: alumno
 */

#ifndef BIBLIOTECA_SERGIO_H_
#define BIBLIOTECA_SERGIO_H_

#define RETORNO_EXITOSO 0
#define ERROR_UNO -1
int getInt(int *resultado,int maximo,int minimo,int reintentos,char* mensaje, char* mensajeError);
int initArrayInt(int *pArray , int limite, int valor);
int getArrayInt(int *pArray, int limite, int maximo, int minimo, int reintentos, char *mensaje, char *mensajeError);
int printArrayInt(int *pArray , int limite);
int getMaximoMinimo(int *pArray , int limite, int *pMax, int *pMin);
int getPromedio(int *pArray , int limite, int *promedio);
int ordenarArrays(int *pArray,int limite);
#endif /* BIBLIOTECA_SERGIO_H_ */
