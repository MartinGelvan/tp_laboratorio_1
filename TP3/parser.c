#include <stdio.h>
#include <stdlib.h>
#include "LinkedList.h"
#include "Employee.h"
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
    Employee* oneEmployee;
    char auxId[10];
    char auxNombre[128];
    char auxHorasTrabajadas[10];
    char auxSueldo[10];
    int leidos;
    int entro=0;

    if(pFile!=NULL && pArrayListEmployee!=NULL)
    {
        fscanf(pFile,"%[^,],%[^,],%[^,],%[^\n]\n",auxId,auxNombre,auxHorasTrabajadas,auxSueldo);
        while(!feof(pFile))
        {
            leidos=fscanf(pFile,"%[^,],%[^,],%[^,],%[^\n]\n",auxId,auxNombre,auxHorasTrabajadas,auxSueldo);
            if(leidos==4)
            {
                //printf("%2s %10s %4s %4s\n",auxId,auxNombre,auxHorasTrabajadas,auxSueldo);
                oneEmployee=employee_newParametros(auxId,auxNombre,auxHorasTrabajadas,auxSueldo);
                ll_add(pArrayListEmployee, oneEmployee);
                //entro=1;
            }
            if(feof(pFile))
            {
                break;
            }

            //oneEmployee=employee_new();
        }

        fclose(pFile);
        controller_ListEmployee(pArrayListEmployee);
        entro=1;
    }

    return entro;
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
    Employee* oneEmployee;
    int bandera;
    int entro=0;


    if(pFile!=NULL && pArrayListEmployee!=NULL)
    {

        while(!feof(pFile))
        {
            oneEmployee=employee_new();
            bandera=fread(oneEmployee,sizeof(Employee),1,pFile);
            if(bandera==1)
            {
                ll_add(pArrayListEmployee,oneEmployee);
            }

        }
        entro=1;
        fclose(pFile);
    }

    return entro;
}
