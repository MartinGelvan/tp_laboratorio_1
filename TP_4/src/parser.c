#include <stdio.h>
#include <stdlib.h>
#include "LinkedList.h"
#include "Employee.h"
#include "parser.h"
#include "Controller.h"
/** \brief Parsea los datos los datos de los empleados desde el archivo data.csv (modo texto).
 *
 * \param path char*
 * \param pArrayListEmployee LinkedList*
 * \return int
 *
 */
int parser_EmployeeFromText(FILE* pFile , LinkedList* pArrayListEmployee)
{
	char auxId[40];
	char auxNombre[40];
	char auxHoras[40];
	char auxSueldo[40];
	int exito=0;

	if(pFile!=NULL && pArrayListEmployee!=NULL)
	{
		fscanf(pFile,"%[^,],%[^,],%[^,],%[^\n]\n", auxId,auxNombre,auxHoras,auxSueldo);

		while(!feof(pFile))
		{
			Employee* pEmployee;
			fscanf(pFile,"%[^,],%[^,],%[^,],%[^\n]\n", auxId,auxNombre,auxHoras,auxSueldo);
			pEmployee= employee_newParametros(auxId, auxNombre, auxHoras, auxSueldo);
			ll_add(pArrayListEmployee, pEmployee);
			if(feof(pFile))
			{
				break;
			}

		}


		if(feof(pFile))
		{
			exito=1;
		}

	}

    return exito;
}

/** \brief Parsea los datos los datos de los empleados desde el archivo data.csv (modo binario).
 *
 * \param path char*
 * \param pArrayListEmployee LinkedList*
 * \return int
 *
 */
int parser_EmployeeFromBinary(FILE* pFile , LinkedList* pArrayListEmployee)
{
	//char auxId[40];
	//char auxNombre[40];
	//char auxHoras[40];
	//char auxSueldo[40];
	int exito=0;

	if(pFile!=NULL && pArrayListEmployee!=NULL)
	{
		//fscanf(pFile,"%[^,],%[^,],%[^,],%[^\n]\n", auxId,auxNombre,auxHoras,auxSueldo);

		while(!feof(pFile))
		{
			Employee* pEmployee= employee_new();
			fread(pEmployee,sizeof(Employee), 1,pFile);
			if(feof(pFile))
			{
				break;
			}
			ll_add(pArrayListEmployee, pEmployee);


		}

		exito=1;
	}
    return exito;
}
