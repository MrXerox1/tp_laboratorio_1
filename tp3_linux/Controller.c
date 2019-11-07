#include <stdio.h>
#include <stdlib.h>
#include <stdio_ext.h>
#include "LinkedList.h"
#include "Employee.h"
#include "parser.h"
#include "utn.h"
#define	MINIMO 1
#define	MENSAJE "ingrese la id del empleado a modificar\n"
#define	MENSAJE_ERROR "la id del empleado a modificar es incorrecta\n"
#define REINTENTOS 2
/** \brief Carga los datos de los empleados desde el archivo data.csv (modo texto).
 *
 * \param path char*
 * \param pArrayListEmployee LinkedList*
 * \return int
 *
 */
int controller_loadFromText(char* path , LinkedList* pArrayListEmployee)
{
	FILE* pfile;
	pfile=fopen(path,"r");
	if(pfile==NULL)
	{
		printf("el archivo no existe");
		exit(ERROR);
	}
	else
	{
		parser_EmployeeFromText(pfile,pArrayListEmployee);
	}
	fclose(pfile);
    return RETORNO_EXITOSO;
}

/** \brief Carga los datos de los empleados desde el archivo data.csv (modo binario).
 *
 * \param path char*
 * \param pArrayListEmployee LinkedList*
 * \return int
 *
 */
int controller_loadFromBinary(char* path , LinkedList* pArrayListEmployee)
{
	FILE *pfile;
	pfile = fopen(path, "rb");
	if (pfile == NULL)
	{
		printf("el archivo no existe");
		exit(ERROR);
	} else
	{
		parser_EmployeeFromBinary(pfile, pArrayListEmployee);
	}
	fclose(pfile);
	return RETORNO_EXITOSO;
}

/** \brief Alta de empleados
 *
 * \param path char*
 * \param pArrayListEmployee LinkedList*
 * \return int
 *
 */
int controller_addEmployee(LinkedList* pArrayListEmployee)
{
	int retorno = ERROR;
	int size = ll_len(pArrayListEmployee);
	Employee *this;
	Employee *auxThis;
	auxThis = ll_get(pArrayListEmployee, size-1);
	this = employee_new();
	if (this != NULL)
	{

		this->id=auxThis->id+1;
		printf("Ingrese el Nombre \n");
		__fpurge(stdin);
		fgets(this->nombre, sizeof(this->nombre), stdin);
		printf("\nIngrese cantidad de horas trabajdas\n");
		__fpurge(stdin);
		scanf("%d", &this->horasTrabajadas);
		printf("\nIngrese el sueldo \n");
		__fpurge(stdin);
		scanf("%d", &this->sueldo);
		if (this != NULL)
		{
            printf ("%d %s %d %d\n", this->id,this->nombre,this->horasTrabajadas,this->sueldo);
			if (!ll_add(pArrayListEmployee, this)) {
				retorno = 0;
			}
		}
	}

	return retorno;
}

/** \brief Modificar datos de empleado
 *
 * \param path char*
 * \param pArrayListEmployee LinkedList*
 * \return int
 *
 */
int controller_editEmployee(LinkedList *pArrayListEmployee)
 {
	int retorno = ERROR;
	int id;
	char salir = 'n';
	int opcion;
	int size = ll_len(pArrayListEmployee);
	int posicion;
	Employee *empleado;

	__fpurge(stdin);
	if (getInt(&id, MENSAJE, MENSAJE_ERROR, MINIMO, size, REINTENTOS) == 0)
	{
		if (empleadoBuscarID(pArrayListEmployee, size, id,
				&posicion)==RETORNO_EXITOSO) {
			empleado = ll_get(pArrayListEmployee, posicion);
			do {
				printf("\nElegir opcion a modificar");
				printf("\n1)Nombre %s", empleado->nombre);
				printf("\n2)Horas Trabajadas %d", empleado->horasTrabajadas);
				printf("\n3)sueldo %d", empleado->sueldo);
				printf("\n4)SALIR\n");
				__fpurge(stdin);
				scanf("%d", &opcion);
				__fpurge(stdin);
				switch (opcion) {
				case 1:
					__fpurge(stdin);
					printf("Ingrese el Nombre \n");
					__fpurge(stdin);
					fgets(empleado->nombre, sizeof(empleado->nombre),
					stdin);
					break;
				case 2:
					printf("\nIngrese el horasTrabajadas \n");
					scanf("%d", &empleado->horasTrabajadas);

					break;
				case 3:
					printf("\nIngrese numero de sueldo \n");
					__fpurge(stdin);
					scanf("%d", &empleado->sueldo);
					break;

				case 4:
					printf("esta seguro de que quiere salir? s/n");
					scanf("%s", &salir);
					break;
				default:
					printf("\nOpcion no valida");
				}
			} while (salir == 'n');
			retorno = RETORNO_EXITOSO;
		}

	}
	return retorno;
}

/** \brief Baja de empleado
 *
 * \param path char*
 * \param pArrayListEmployee LinkedList*
 * \return int
 *
 */
int controller_removeEmployee(LinkedList* pArrayListEmployee)
{
	int retorno = ERROR;
	int posicion;
	int id;
	int size = ll_len(pArrayListEmployee);

	__fpurge(stdin);
	if (getInt(&id, MENSAJE, MENSAJE_ERROR, MINIMO, size, REINTENTOS) == 0) {
		if (empleadoBuscarID(pArrayListEmployee, size, id,
				&posicion)==RETORNO_EXITOSO) {
			ll_remove(pArrayListEmployee,posicion);
			printf("el empleado con la id: %d  fue borrado",id);
			retorno=RETORNO_EXITOSO;
		}
	}
	return retorno;
}

/** \brief Listar empleados
 *
 * \param path char*
 * \param pArrayListEmployee LinkedList*
 * \return int
 *
 */
int controller_ListEmployee(LinkedList* pArrayListEmployee)
{
	  int retorno = ERROR;
	    Employee* empleado;
	    int size=ll_len(pArrayListEmployee);
	    int i;

	    if(pArrayListEmployee != NULL && size > 0)
	    {
	        printf("\nID: \t Nombre: \t Horas Trabajadas: \t Sueldo: \n");

	        for (i=0;i<size;i++)
	        {
	            empleado = ll_get(pArrayListEmployee, i);

	            if(empleado != NULL)
	            {
	                printf ("%d %s %d %d\n", empleado->id,empleado->nombre,empleado->horasTrabajadas,empleado->sueldo);
	            }
	        }

	        retorno = RETORNO_EXITOSO;
	    }

	    return retorno;
}

/** \brief Ordenar empleados
 *
 * \param path char*
 * \param pArrayListEmployee LinkedList*
 * \return int
 *
 */
int controller_sortEmployee(LinkedList* pArrayListEmployee)
{
    return 1;
}

/** \brief Guarda los datos de los empleados en el archivo data.csv (modo texto).
 *
 * \param path char*
 * \param pArrayListEmployee LinkedList*
 * \return int
 *
 */
int controller_saveAsText(char* path , LinkedList* pArrayListEmployee)
{
    return 1;
}

/** \brief Guarda los datos de los empleados en el archivo data.csv (modo binario).
 *
 * \param path char*
 * \param pArrayListEmployee LinkedList*
 * \return int
 *
 */
int controller_saveAsBinary(char* path , LinkedList* pArrayListEmployee)
{
    return 1;
}


