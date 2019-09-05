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
#include "utn.h"

float mostrarMenu(float numeroX, float numeroY){
printf("1. Ingresar 1er operando (A=x)\n");
printf("2. Ingresar 2do operando (B=y)\n");
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
float calcularTodo(float *numeroX,float *numeroY)
{
	int retorno = ERROR_UNO;

	printf("a) “El resultado de A+B es: %f”",resultadoSuma);
	printf("b) “El resultado de A-B es: %f”",resultadoResta);
	if(numeroY !=0){
	printf("c) “El resultado de A/B es: %f”",resultadoDivision);
	}else{
		printf("“No es posible dividir por cero”");
	}
	printf("d) “El resultado de A*B es: %f”",resultadoMultiplicacion);
	printf("e) “El factorial de A es: r1 y El factorial de B es: %d”",resultadoFactorial);

	return retorno;
}
float getSum(float*numeroX,float*numeroY)
{
    float resultado;
    resultado=(*numeroX)+(*numeroY);
    printf("\nEl resultado de %.2f+%.2f es: %.2f\n",*numeroX,*numeroY,resultado);
    return 0;
}
