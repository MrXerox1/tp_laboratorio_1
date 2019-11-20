/*
 * Cliente.h
 *
 *  Created on: 20 nov. 2019
 *      Author: sergio
 */

#ifndef CLIENTE_H_
#define CLIENTE_H_
struct
{
	int id_venta;
	char cuit_cliente;
	char fecha[50];
	char tipo_foto[50];
	int cantidad;
	int precio_unitario;

}typedef Cliente;

Cliente* cliente_new();

void cliente_delete(Cliente *this);

Cliente* cliente_newParametros(char* idStr,char* nombreStr,char* horasTrabajadasStr);

int cliente_setId_venta(Cliente* this,char *id);
int cliente_getId_venta(Cliente* this,int *id);


int cliente_setTipo_foto(Cliente* this,char* nombre);
int cliente_getTipo_foto(Cliente* this,char* nombre);

int cliente_setFecha(Cliente* this,char* nombre);
int cliente_getFecha(Cliente* this,char* nombre);

int cliente_setCuit_cliente(Cliente* this,char* nombre);
int cliente_getCuit_cliente(Cliente* this,char* nombre);

int cliente_setCantidad(Cliente* this,char* horasTrabajadas);
int cliente_getCantidad(Cliente* this,int* horasTrabajadas);

int cliente_getPrecio_unitario(Cliente* this,int* sueldo);
int cliente_setPrecio_unitario(Cliente* this,int* sueldo);

int em_calcularSueldo(void* this);

#endif /* CLIENTE_H_ */
