#include <stdio.h>
#include <stdlib.h>
#include "LinkedList.h"
#include "Employee.h"
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
    int exito=0;


    pFile=(FILE*)malloc(sizeof(FILE));

    if(path!=NULL && pArrayListEmployee!=NULL)
    {
        pFile= fopen(path,"r");

        if(pFile!=NULL)
        {
            exito=parser_EmployeeFromText(pFile , pArrayListEmployee);

            fclose(pFile);

        }


    }else
    {
        printf("No se encontro el archivo\n");
    }

    return exito;
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

    int exito=0;

    pFile=(FILE*)malloc(sizeof(FILE));


    if(path!=NULL && pArrayListEmployee!=NULL)
    {
        pFile= fopen("data.dat","rb");

        if(pFile!=NULL)
        {
            exito=parser_EmployeeFromBinary(pFile , pArrayListEmployee);

        }else
        {
            printf("Archivo Inexistene, se creara un archivo\n");
            pFile=fopen(path,"wb");
            fwrite(pArrayListEmployee, sizeof(LinkedList),1000,pFile);
        }


    }

    return exito;
}

/** \brief Alta de empleados
 *
 * \param path char*
 * \param pArrayListEmployee LinkedList*
 * \return int
 *
 */
int controller_addEmployee(LinkedList* pArrayListEmployee, int siguiente)
{
    int auxId;
    char auxNombre[128];
    int auxHorasTrabajadas;
    int auxSueldo;
    int exito=0;

    Employee* unEmpleado;

    if(pArrayListEmployee!=NULL)
    {
        unEmpleado=employee_new();
        if(unEmpleado!=NULL)
        {
            auxId=IdAutomatico(siguiente,1000);
            printf("Ingrese su nombre: ");
            fflush(stdin);
            scanf("%[^\n]",auxNombre);

            printf("Ingrese sus horas realizadas: ");
            scanf("%d",&auxHorasTrabajadas);

            printf("Ingrese su sueldo: ");
            scanf("%d",&auxSueldo);

            if(employee_setId(unEmpleado,auxId)==1 && employee_setNombre(unEmpleado,auxNombre)==1 && employee_setHorasTrabajadas(unEmpleado,auxHorasTrabajadas)==1 && employee_setSueldo(unEmpleado,auxSueldo)==1)
            {
                ll_add(pArrayListEmployee,unEmpleado);

            }
        }
        exito=1;
    }


    return exito;
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
    int auxId;
    int index;
    Employee* unEmpleado;
    int opcion;
    char auxNombre[20];
    int auxHorasTrabajo;
    int auxSueldo;


    if(pArrayListEmployee!=NULL)
    {
        controller_ListEmployee(pArrayListEmployee);

        printf("\nIngrese el ID del Empleado a modificar: ");
        scanf("%d",&auxId);

      index= employee_searchIdEmployee(pArrayListEmployee,auxId);

      if(index!=-1)
      {
        unEmpleado=(Employee*)ll_get(pArrayListEmployee,index);
        printf("Que desea modificar?\n");
        printf("1.Nombre\n2.Horas trabajadas\n3.Sueldo\n");
        printf("\nElija una opcion: ");
        scanf("%d",&opcion);

        switch(opcion)
        {
            case 1:
                    printf("Ingrese su nuevo nombre: ");
                    fflush(stdin);
                    scanf("%[^\n]", auxNombre);

                    employee_setNombre(unEmpleado,auxNombre);

            break;

            case 2:
                    printf("Ingrese sus nuevas horas de trabajo: ");
                    scanf("%d", &auxHorasTrabajo);
                    employee_setHorasTrabajadas(unEmpleado,auxHorasTrabajo);

            break;

            case 3:
                    printf("Ingrese su nuevo sueldo: ");
                    scanf("%d", &auxSueldo);
                    employee_setSueldo(unEmpleado,auxSueldo);

            break;

        }



      }


    }


    return index;
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
    Employee* auxEmpleado;



    if(pArrayListEmployee!=NULL)
    {
        controller_ListEmployee(pArrayListEmployee);

        printf("\nIngrese el ID del Empleado a eliminar: ");
        scanf("%d",&auxId);

        //ll_remove(pArrayListEmployee,auxId-1);

        auxEmpleado=ll_pop(pArrayListEmployee,auxId-1);

        printf("Empleado eliminado correctamente\n");
        printf("%5d %10s %6d %6d\n",auxEmpleado->id,auxEmpleado->nombre,auxEmpleado->horasTrabajadas,auxEmpleado->sueldo);


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
    int exito=0;
    int len;
    Employee* unEmpleado;



    if(pArrayListEmployee!=NULL)
    {
        len=ll_len(pArrayListEmployee);

        for(i=0;i<len;i++)
        {
            unEmpleado=(Employee*)ll_get(pArrayListEmployee, i);
            printf("%d %s %d %d\n", unEmpleado->id, unEmpleado->nombre, unEmpleado->horasTrabajadas, unEmpleado->sueldo);
        }

        exito=1;

    }



    return exito;
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
    Employee* unEmpleado;
    int len;
    int opcion;

    if(pArrayListEmployee!=NULL)
    {
        len=ll_len(pArrayListEmployee);

         printf("\nComo le gustaria ordenar?\n");
        printf("\n1.Por Id ascendente\n2.Por Id descendente\n3.Por Nombre A->Z\n4.Por Nombre Z->A\n");
        printf("\nElija una opcion: ");
        scanf("%d",&opcion);

        switch(opcion)
        {
            case 1:
                    ll_sort(pArrayListEmployee,employee_CompareById,1);
                    controller_ListEmployee(pArrayListEmployee);
            break;

            case 2:
                    ll_sort(pArrayListEmployee,employee_CompareById,0);
                    controller_ListEmployee(pArrayListEmployee);
            break;

            case 3:
                    ll_sort(pArrayListEmployee,employee_CompareByName,1);
                    controller_ListEmployee(pArrayListEmployee);
            break;

            case 4:
                    ll_sort(pArrayListEmployee,employee_CompareByName,0);
                    controller_ListEmployee(pArrayListEmployee);
            break;
        }
/*
        ll_sort(pArrayListEmployee,employee_CompareById,0);

        controller_ListEmployee(pArrayListEmployee);
*/
    }

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
    Employee* Empleado;
    int len;
    int exito=0;
    int i;

    if(path!=NULL && pArrayListEmployee!=NULL)
    {
        pFile=fopen(path,"w");

        if(pFile!=NULL)
        {
            len=ll_len(pArrayListEmployee);

            for(i=0;i<len;i++)
            {
                fprintf("%d %s %d %d\n",Empleado->id,Empleado->nombre,Empleado->horasTrabajadas,Empleado->sueldo);
            }

        }

        exito=1;
    }


    return exito;
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
    Employee* Empleado;
    int len;
    int exito=0;
    int i;

    if(path!=NULL && pArrayListEmployee!=NULL)
    {
        pFile=fopen(path,"wb");

        if(pFile!=NULL)
        {
            len=ll_len(pArrayListEmployee);

            for(i=0;i<len;i++)
            {
                fwrite(Empleado,sizeof(Employee),len,pFile);
            }

            fclose(pFile);
        }

        exito=1;
    }

    return exito;
}

int IdAutomatico(int siguiente, int id)
{
    return id+siguiente;
}
