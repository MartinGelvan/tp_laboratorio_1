#include <stdio.h>
#include <stdlib.h>
#include "LinkedList.h"
#include "Employee.h"
#include "Inputs.h"
#include "parser.h"
#include "Controller.h"


/** \brief Carga los datos de los empleados desde el archivo data.csv (modo texto).
 *
 * \param path char*
 * \param pArrayListEmployee LinkedList*
 * \return int
 *
 */
int controller_loadFromText(char* path , LinkedList* pArrayListEmployee)
{
	FILE* pFile;

	if(path!=NULL && pArrayListEmployee!=NULL)
	{
		pFile=fopen(path,"r");

		if(pFile!=NULL)
		{
			parser_EmployeeFromText(pFile ,pArrayListEmployee);
			fclose(pFile);
		}
	}
    return 1;
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
	FILE* pFile;

	if(path!=NULL && pArrayListEmployee!=NULL)
	{
		pFile=fopen(path,"rb");

		if(pFile!=NULL)
		{
			parser_EmployeeFromBinary(pFile ,pArrayListEmployee);
			fclose(pFile);
		}
	}
    return 1;
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
	Employee* pEmployee=employee_new();
	char auxId[40];
	char auxNombre[40];
	char auxHoras[40];
	char auxSueldo[40];

	if(pArrayListEmployee!=NULL)
	{

		pedirCadena(auxNombre,"Ingrese su nombre (40 caracteres maximo): ", "Error, reingrese su nombre (40 caracteres maximo)", 40);
		pedirCadena(auxHoras,"Ingrese las horas (1h minimo 40hs maximo):", "Error, reingrese su nombre (40 caracteres maximo)", 2);
		pedirCadena(auxSueldo,"Ingrese el sueldo ($1000 minimo , $40000 maximo):", "Error, reingrese su sueldo ($1000 minimo , $40000 maximo):", 5);
		pEmployee=employee_newParametros(auxId, auxNombre, auxHoras, auxSueldo);
		ll_add(pArrayListEmployee, pEmployee);

	}

    return 1;
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
	int auxId;
	int index;
	LinkedList* auxEmployee;
	if(pArrayListEmployee!=NULL)
	{
		controller_ListEmployee(pArrayListEmployee);

		pedirEntero(&auxId, "Ingrese el ID del empleado a eliminar(1-2000): ", "Error,reingrese el ID del empleado a eliminar(1-2000): ", 1, 2000);

		index=controller_searchIdEmployee(pArrayListEmployee, auxId);

		auxEmployee=ll_get(pArrayListEmployee, index);

		if(pedirConfirmacion("\nIngrese 's' para confirmar el alta de la estadia: ")==0)
			{
				ll_remove(auxEmployee, index);
			}
	}
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
	int i;
	int tam;
	int auxId;
	int auxHoras;
	int auxSueldo;
	char auxNombre[20];
	Employee* auxEmployee;

	printf("%-10s %-5s %-10s %-10s","ID","NOMBRE","HORAS","SUELDO");

	if(pArrayListEmployee!=NULL)
	{
		tam=ll_len(pArrayListEmployee);

		for(i=0;i<tam;i++)
		{
			auxEmployee=ll_get(pArrayListEmployee, i);
			employee_getId(auxEmployee, &auxId);
			employee_getNombre(auxEmployee, auxNombre);
			employee_getHorasTrabajadas(auxEmployee, &auxHoras);
			employee_getSueldo(auxEmployee, &auxSueldo);
			printf("%10d %5s %10d %10d",auxId,auxNombre,auxHoras,auxSueldo);
		}
	}

    return 1;
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
	FILE* pFile;
	int tam;
	int i;
	Employee* employee;
	int auxId;
	char auxNombre[21];
	int auxHoras;
	int auxSueldo;

	if(path!=NULL && pArrayListEmployee!=NULL)
	{

		pFile=fopen(path,"w");

		if(pFile!=NULL)
		{
			tam= ll_len(pArrayListEmployee);
			fprintf(pFile,"Id,Nombre,Horas trabajadas,Sueldo\n");

			for(i=0;i<tam;i++)
			{
				employee=ll_get(pArrayListEmployee, i);
				employee_getId(employee,&auxId);
				employee_getNombre(employee,auxNombre);
				employee_getHorasTrabajadas(employee,&auxHoras);
				employee_getSueldo(employee,&auxSueldo);
				fprintf(pFile,"%d,%s,%d,%d\n", auxId,auxNombre, auxHoras,auxSueldo);
			}
			fclose(pFile);
		}

	}
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
	FILE* pFile;
	Employee* employee;
	int tam;
	int i;

	if(path!=NULL && pArrayListEmployee!=NULL)
	{
		pFile=fopen(path, "wb");

		if(pFile!=NULL)
		{
			tam=ll_len(pArrayListEmployee);

			for(i=0;i<tam;i++)
			{
				employee=ll_get(pArrayListEmployee, i);
				fwrite(employee,sizeof(Employee),1,pFile);
			}

			fclose(pFile);
		}
	}
    return 1;
}

int controller_searchIdEmployee(LinkedList* this, int auxId)
{
	int tam;
	int i;
	Employee* auxEmployee;
	int idEmployee;
	int index=-1;

	if(this!=NULL)
	{
		tam=ll_len(this);

		for(i=0;i<tam;i++)
		{
			auxEmployee=(Employee*)ll_get(this,i);
			idEmployee=auxEmployee->id;
			employee_getId(auxEmployee, &idEmployee);

			if(auxId==idEmployee)
			{
				index=i;
				break;
			}
		}
	}

	return index;
}
