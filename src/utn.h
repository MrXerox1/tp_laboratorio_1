/*
 * utn.h
 *
 *  Created on: 5 sep. 2019
 *      Author: sergio
 */

#ifndef UTN_H_
#define UTN_H_

#define ERROR_UNO -1.0
#define ERROR_SUMA -2.0
#define ERROR_RESTA -3.0
#define ERROR_DIVISION -4.0
#define ERROR_PRODUCTO -5.0
#define ERROR_FACTORIAL_X -6.0
#define ERROR_FACTORIAL_Y -7.0
#define RETORNO_EXITOSO 0.0
float mostrarMenu(float numeroX, float numeroY);
float getSuma(float numeX,float numeY, float *resultSuma);
float getResta(float numeroX,float numeroY, float *resultadoResta);
float getProducto(float numeroX,float numeroY, float *resultadoProducto);
float getDivision(float numeroX,float numeroY, float *resultadoDivision);
float getFactorial(float pNumero, int *Presultado);
float mostrarResultados(float numeroY,float resultadoSuma,
		float resultadoResta, float resultadoDivision, float resultadoProducto,
		int resultadoFactorialX, int resultadoFactorialY);
float getInt(float *resultado,float maximo,float minimo,float reintentos,char* mensaje, char* mensajeError);
float CalcularOperaciones(float numeroX, float numeroY, float *resultadoSuma, float*resultadoResta, float*resultadoDivision,
		float *resultadoProducto,int *resultadoFactorialX, int *resultadoFactorialY);


#endif /* UTN_H_ */
