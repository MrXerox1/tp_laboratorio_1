#ifndef contoller_H_INCLUDED
#define controller_H_INCLUDED
#include "LinkedList.h"

int controller_cargarPorTexto(char* path , LinkedList* pArrayListEmployee);
int controller_generarArchivoSueldos(char* path , LinkedList* pArrayListEmployee);

#endif // controller_H_INCLUDED
