/*
 * libreria_empleado.h
 *
 *  Created on: 30 sep. 2019
 *      Author: sergio
 */

#ifndef LIBRERIA_EMPLEADO_H_
#define LIBRERIA_EMPLEADO_H_
//cantida de arrays
#define QTY_TIPO 1000
//retornos
#define RETORNO_EXITOSO 0
#define ERROR -1
//isEmpty
#define VACIO 0
#define LLENO 1

typedef struct {
	int idempleado;
	char nombre[30];
	char apellido[30];
	int sector;
	float salario;
	int isEmpty;
} datosPersonales;
int empleadoBuscarID(datosPersonales array[], int size, int valorBuscado, int* posicion);
int empleado_Inicializar(datosPersonales empleado[], int size);
int empleadoBuscarEmpty(datosPersonales empleado[], int size, int *posicion);
int empleadoAlta(datosPersonales empleado[], int size, int *contadorID);
int ingresoEmpleado(datosPersonales empleado[]);
int mostrarMenu();
int listarEmpleados(datosPersonales empleado[], int size);
int empleadoBuscarID(datosPersonales empleado[], int size, int valorBuscado, int* posicion);
int modificarPorId(datosPersonales empleado[],int contadorId);
int bajaEmpleado(datosPersonales empleado[], int contadorId);
void mostrarOrdenado(datosPersonales lista[],int size);
int mostrarSalarioPromedio(datosPersonales lista[],int size);
int ConfirmarDatoCargado(datosPersonales empleado[], int size);





#endif /* LIBRERIA_EMPLEADO_H_ */
