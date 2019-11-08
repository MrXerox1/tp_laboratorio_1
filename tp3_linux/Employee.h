#ifndef employee_H_INCLUDED
#define employee_H_INCLUDED
#define RETORNO_EXITOSO 0
#define ERROR -1
#include "Controller.h"
#include "LinkedList.h"
typedef struct
{
    int id;
    char nombre[128];
    int horasTrabajadas;
    int sueldo;
}Employee;

Employee* employee_new();
Employee* employee_newParametros(char* idStr,char* nombreStr,char* horasTrabajadasStr, char *sueldoStr);
void employee_delete();

int employee_setIdString(Employee* this,char *id);
int employee_getIdString(Employee* this,int *id);


int employee_setNombre(Employee* this,char* nombre);
int employee_getNombre(Employee* this,char* nombre);

int employee_setHorasTrabajadasString(Employee* this,char* horasTrabajadas);
int employee_getHorasTrabajadasString(Employee* this,int* horasTrabajadas);


int employee_setSueldoString(Employee* this,char* sueldo);
int employee_getSueldoString(Employee* this,int* sueldo);
int empleadoBuscarID(LinkedList *pArrayListEmployee, int size, int valorBuscado,int *posicion);
int employee_sort(void* Employee1, void* Employee2);
int employee_buscarIdMax(LinkedList *pArrayListEmployee);


#endif // employee_H_INCLUDED
