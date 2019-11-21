/*
 * Cliente.h
 *
 *  Created on: 20 nov. 2019
 *      Author: sergio
 */

#ifndef CLIENTE_H_
#define CLIENTE_H_
#define ERROR -1
#define RETORNO_EXITOSO 0

struct
{
	int id_venta;
	char cuit_cliente[50];
	char fecha[50];
	char tipo_foto[50];
	int cantidad;
	float precio_unitario;

}typedef Cliente;

Cliente* cliente_new();

void cliente_delete(Cliente *this);

Cliente* cliente_newParametros(char *idStr, char *cuitStr, char *cantidadStr,char *fecha, char *tipoFoto, char* precio);

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

int cliente_setPrecio_unitario(Cliente* this,char* sueldo);
int cliente_getPrecio_unitario(Cliente* this,float* sueldo);


#endif /* CLIENTE_H_ */
