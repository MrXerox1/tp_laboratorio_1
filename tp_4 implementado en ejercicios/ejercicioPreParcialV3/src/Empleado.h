#ifndef EMPLEADO_H_INCLUDED
#define EMPLEADO_H_INCLUDED
#define RETORNO_EXITOSO 0
#define ERROR -1
struct S_Empleado
{
  int id;
  char nombre[128];
  int horasTrabajadas;
  int sueldo;
};
typedef struct S_Empleado Empleado;

Empleado* empleado_new();
void empleado_delete(Empleado *this);
Empleado* empleado_newParametros(char* idStr,char* nombreStr,char* horasTrabajadasStr);

int empleado_setId(Empleado* this,char *id);
int empleado_getId(Empleado* this,int *id);


int empleado_setNombre(Empleado* this,char* nombre);
int empleado_getNombre(Empleado* this,char* nombre);

int empleado_setHorasTrabajadas(Empleado* this,char* horasTrabajadas);
int empleado_getHorasTrabajadas(Empleado* this,int* horasTrabajadas);

int empleado_getSueldo(Empleado* this,int* sueldo);
int empleado_setSueldo(Empleado* this,int* sueldo);

int em_calcularSueldo(void* this);

#endif // EMPLEADO_H_INCLUDED
