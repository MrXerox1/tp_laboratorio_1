/*
 * Controller.h
 *
 *  Created on: 20 nov. 2019
 *      Author: sergio
 */

#ifndef CONTROLLER_H_
#define CONTROLLER_H_
#include "LinkedList.h"

int controller_cargarPorTexto(char* path , LinkedList* pArrayListEmployee);
int controller_generarArchivoInformes(char* path , LinkedList* pArrayListEmployee);



#endif /* CONTROLLER_H_ */
