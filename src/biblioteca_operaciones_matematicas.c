/*
 ============================================================================
 * biblioteca_operaciones_matematicas.c
  Author      : sergio tirante
 Version     :
 Copyright   : Your copyright notice
 Description : Hello World in C, Ansi-style
 ============================================================================
 */
#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include "utn.h"
//muestra el menu en consola
float mostrarMenu(float numeroX, float numeroY){
	printf("\n1. Ingresar 1er operando (A=%f)\n",numeroX);
	printf("2. Ingresar 2do operando (B=%f)\n",numeroY);
	printf("3. Calcular todas las operaciones\n");
	printf("a) Calcular la suma (A+B)\n");
	printf("b) Calcular la resta (A-B)\n");
	printf("c) Calcular la division (A/B)\n");
	printf("d) Calcular la multiplicacion (A*B)\n");
	printf("e) Calcular el factorial (A!)\n");
	printf("4. Informar resultados\n");
	printf("5. Salir\n");
return 0;
}
// pide un numero float
float getInt(float *resultado,float maximo,float minimo,float reintentos,char* mensaje, char* mensajeError)
{
	float numero;
	float retorno= ERROR_UNO;
	do
	{
		printf("%s",mensaje);
		if(scanf("%f",&numero)==1 && numero >= minimo && numero <= maximo)
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
//muestra los resultados en consola
float mostrarResultados(float numeroY,float resultadoSuma,
		float resultadoResta, float resultadoDivision, float resultadoProducto,
		int resultadoFactorialX, int resultadoFactorialY)
{
	int retorno = ERROR_UNO;

	printf("a) “El resultado de A+B es: %f”\n",resultadoSuma);
	printf("b) “El resultado de A-B es: %f”\n",resultadoResta);
	if(numeroY !=0){
	printf("c) “El resultado de A/B es: %f”\n",resultadoDivision);
	}else{
		printf("c) “No es posible dividir por cero”\n");
	}
	printf("d) “El resultado de A*B es: %f”\n",resultadoProducto);
	printf("e) “El factorial de A es: %d y El factorial de B es: %d”\n",resultadoFactorialX,resultadoFactorialY);

	return retorno;
}
//suma de numeros A y B
float getSuma(float numeX,float numeY, float *resultSuma)
{
    *resultSuma=numeX+numeY;
    return RETORNO_EXITOSO;
}
//resta de numeros A y B
float getResta(float numeroX,float numeroY, float *resultadoResta)
{
    *resultadoResta=numeroX-numeroY;
    return RETORNO_EXITOSO;
}
//multiplicacion de numeros A y B
float getProducto(float numeroX,float numeroY, float *resultadoProducto)
{
	*resultadoProducto=numeroX*numeroY;
	return RETORNO_EXITOSO;
}
//division de numeros A y B
float getDivision(float numeroX,float numeroY, float *resultadoDivision)
{
	float retorno=ERROR_UNO;
	if(numeroY != 0.0)
	{
		*resultadoDivision=numeroX/numeroY;
		retorno = RETORNO_EXITOSO;
	}
	return retorno;
}
//conseguir factorial para numero A o B
float getFactorial(float Numero, int *Presultado)
{
	int acumulador=1;
	int numero= Numero;
	int  factor;
	float retorno=ERROR_UNO;
	if (numero < 0)
	{
	        printf("Error, no se puede hacer factorial de negativos.");
	} else
		{
	        for(factor=1;factor<=numero; ++factor)
	        {
	        	acumulador *= factor;
	        }
	        *Presultado=acumulador;
	        retorno = RETORNO_EXITOSO;
	    }
	return retorno;
}
//calcula todas las operaciones con los mismos valores y tira un valor de error especifico si no se logra alguna
float CalcularOperaciones(float numeroX, float numeroY, float *resultadoSuma, float*resultadoResta, float*resultadoDivision,
		float *resultadoProducto,int *resultadoFactorialX, int *resultadoFactorialY)
{
	float resultSuma;
	float resultResta;
	float resultDivision;
	float resultProducto;
	int resultFactorialX;
	int resultFactorialY;
	float retorno=ERROR_UNO;

	if(getSuma(numeroX,numeroY,&resultSuma)==0)
	{
		*resultadoSuma=resultSuma;
		retorno=RETORNO_EXITOSO;
	}else{
		retorno=ERROR_SUMA;
	}
	if(getResta(numeroX,numeroY,&resultResta)==0)
	{
		*resultadoResta=resultResta;
		retorno=RETORNO_EXITOSO;
	}
	else{
		retorno=ERROR_RESTA;
	}
	if(getDivision(numeroX,numeroY,&resultDivision)==0)
	{
		*resultadoDivision=resultDivision;
		retorno=RETORNO_EXITOSO;
	}else{
		retorno=ERROR_DIVISION;
	}
	if(getProducto(numeroX,numeroY,&resultProducto)==0)
	{
		*resultadoProducto=resultProducto;
		retorno=RETORNO_EXITOSO;
	}else{
		retorno=ERROR_PRODUCTO;

	}
	if(getFactorial(numeroX,&resultFactorialX)==0)
	{
		*resultadoFactorialX=resultFactorialX;
		retorno=RETORNO_EXITOSO;
	}else{
		retorno=ERROR_FACTORIAL_X;

	}
	if(	getFactorial(numeroY,&resultFactorialY)==0)
	{
		*resultadoFactorialY=resultFactorialY;
		retorno=RETORNO_EXITOSO;
	}else{
		retorno=ERROR_FACTORIAL_Y;
	}
	return retorno;
}
