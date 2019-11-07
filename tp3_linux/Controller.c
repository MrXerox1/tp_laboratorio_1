#include <stdio.h>
#include <stdlib.h>
#include <stdio_ext.h>
#include "LinkedList.h"
#include "Employee.h"
#include "parser.h"

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
	int idMaximo;
	int size = ll_len(pArrayListEmployee);
	Employee *this;
	this = employee_new();
	if (this != NULL)
	{
		if(controller_IdMaxima(&idMaximo,this,size)!=ERROR){
			this->id=idMaximo;
		}
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
int controller_editEmployee(LinkedList* pArrayListEmployee)
{
    return 1;
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
    return 1;
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


