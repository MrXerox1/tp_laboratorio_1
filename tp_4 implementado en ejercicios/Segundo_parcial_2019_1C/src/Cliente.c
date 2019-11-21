/*
 * Cliente.c
 *
 *  Created on: 20 nov. 2019
 *      Author: sergio
 */
#include <stdio.h>
#include <stdlib.h>
#include <stdio_ext.h>
#include <string.h>
#include "Cliente.h"
#include "utn.h"
static int isValidId(char *id);

Cliente* cliente_new() {
	return malloc(sizeof(Cliente));
}

void cliente_delete(Cliente *this) {
	free(this);
}
Cliente* cliente_newParametros(char *idStr, char *cuitStr, char *cantidadStr,char *fechaStr, char *tipoFotoStr, char* precioStr) {
	Cliente *retorno = NULL;
	Cliente *this;
	this = cliente_new();

	if (this != NULL) {
		if (cliente_setId_venta(this,idStr) == 0 && cliente_setCuit_cliente(this,cuitStr) == 0 &&
				cliente_setCantidad(this, cantidadStr) == 0 &&
				cliente_setFecha(this, fechaStr) == 0 &&
				cliente_setTipo_foto(this,tipoFotoStr) == 0 &&
				cliente_setPrecio_unitario(this,precioStr) == 0)
		{
			retorno = this;
		} else {
			printf("borre %s\n", idStr);
			cliente_delete(this);
		}
	}

	return retorno;
}

int cliente_setId_venta(Cliente *this, char *id) {
	int retorno = ERROR;

	if (this != NULL && isValidId(id)) {
		this->id_venta = atoi(id);
		retorno = EXIT_SUCCESS;
	}

	return retorno;
}
int cliente_getId_venta(Cliente *this, int *id) {
	int retorno = ERROR;

	if (this != NULL && id != NULL) {
		*id = this->id_venta;

		retorno = RETORNO_EXITOSO;
	}
	return retorno;

}

static int isValidId(char *id) {
	int retorno = ERROR;

	if (id != NULL) {
		if (esSoloNumerosPositivos(id, "\nERROR_ID")) {
			retorno = EXIT_SUCCESS;
		}
	}

	return retorno;
}

int cliente_setTipo_foto(Cliente *this, char *foto) {
	int retorno = ERROR;

	if (this != NULL) {
		if (strlen(foto) > 0) {
			strncpy(this->tipo_foto, foto, sizeof(this->tipo_foto));
			retorno = 0;
		}
	}

	return retorno;
}
int cliente_getTipo_foto(Cliente *this, char *foto) {
	int retorno = ERROR;

	if (this != NULL && foto != NULL) {
		strncpy(foto, this->tipo_foto, sizeof(this->tipo_foto));

		retorno = 0;
	}
	return retorno;

	return retorno;
}

int cliente_setFecha(Cliente *this, char *fecha) {
	int retorno = ERROR;

	if (this != NULL) {
		if (strlen(fecha) > 0) {
			strncpy(this->fecha, fecha, sizeof(this->fecha));
			retorno = 0;
		}
	}

	return retorno;
}
int cliente_getFecha(Cliente *this, char *fecha) {
	int retorno = ERROR;

	if (this != NULL && fecha != NULL) {
		strncpy(fecha, this->fecha, sizeof(this->fecha));

		retorno = 0;
	}
	return retorno;
}

int cliente_setCuit_cliente(Cliente *this, char *cuit) {
	int retorno = ERROR;

		if (this != NULL) {
			if (strlen(cuit) > 0) {
				strncpy(this->cuit_cliente, cuit, sizeof(this->cuit_cliente));
				retorno = 0;
			}
		}

		return retorno;
}
int cliente_getCuit_cliente(Cliente *this, char *cuit) {
	int retorno = ERROR;

		if (this != NULL && cuit != NULL) {
			strncpy(cuit, this->cuit_cliente, sizeof(this->cuit_cliente));

			retorno = 0;
		}
		return retorno;
	}

int cliente_setCantidad(Cliente *this, char *cantidad) {
	int retorno = ERROR;

	if (this != NULL && cantidad != NULL) {
		*cantidad = this->cantidad;

		retorno = 0;
	}
	return retorno;
}
int cliente_getCantidad(Cliente *this, int *cantidad) {
	int retorno = ERROR;

	if (this != NULL && cantidad != NULL) {
		*cantidad = this->cantidad;

		retorno = 0;
	}
	return retorno;
}

int cliente_setPrecio_unitario(Cliente *this, char *precio) {

	int retorno = ERROR;

	if (this != NULL) {
		this->precio_unitario = atof(precio);
		retorno = EXIT_SUCCESS;
	}

	return retorno;
}
int cliente_getPrecio_unitario(Cliente *this, float *precio) {
	int retorno = ERROR;

		if (this != NULL && precio != NULL) {
			*precio = this->precio_unitario;

			retorno = 0;
		}
		return retorno;
}
