


#include <stdlib.h>
#include "Employee.h"
#include <string.h>

int employee_CompareByName(void* e1, void* e2)
{
    Employee* empleado1;
    Employee* empleado2;
    char auxNombre1[20];
    char auxNombre2[20];



    empleado1=(Employee*)e1;
    empleado2=(Employee*)e2;

    employee_getNombre(empleado1,auxNombre1);
    employee_getNombre(empleado2,auxNombre2);

    return strcmp(auxNombre1,auxNombre2);
}


int employee_CompareById(void* e1, void* e2)
{
    int compare=0;
    Employee* empleado1;
    Employee* empleado2;
    int auxId1;
    int auxId2;

    empleado1=(Employee*)e1;
    empleado2=(Employee*)e2;

    employee_getId(empleado1,&auxId1);
    employee_getId(empleado2,&auxId2);

    if(auxId1>auxId2)
    {
        compare=1;

    }else
    {
        if(auxId1<auxId2)
        {
            compare=-1;
        }
    }

    return compare;
}


int employee_CompareBySalary(void* e1, void* e2)
{
    int compare=0;
    Employee* empleado1;
    Employee* empleado2;
    int auxSueldo1;
    int auxSueldo2;

    empleado1=(Employee*)e1;
    empleado2=(Employee*)e2;

    employee_getSueldo(empleado1,&auxSueldo1);
    employee_getSueldo(empleado2,&auxSueldo2);


    if(auxSueldo1>auxSueldo2)
    {
        compare=1;

    }else
    {
        if(auxSueldo1<auxSueldo2)
        {
            compare=-1;
        }
    }

    return compare;
}

int employee_CompareByHorasTrabajadas(void* e1, void* e2)
{
    int compare=0;
    Employee* empleado1;
    Employee* empleado2;
    int auxHoras1;
    int auxHoras2;

    empleado1=(Employee*)e1;
    empleado2=(Employee*)e2;

    employee_getHorasTrabajadas(empleado1,&auxHoras1);
    employee_getHorasTrabajadas(empleado2,&auxHoras2);


    if(auxHoras1>auxHoras2)
    {
        compare=1;

    }else
    {
        if(auxHoras1<auxHoras2)
        {
            compare=-1;
        }
    }

    return compare;
}


Employee* employee_new()
{
    Employee* pListEmployees;;

    pListEmployees= (Employee*) malloc(sizeof(Employee));

    return pListEmployees;

}

Employee* employee_newParametros(char* idStr,char* nombreStr,char* horasTrabajadasStr,char* sueldoStr)
{
    Employee* pEmployee;

    pEmployee=employee_new();

    if(pEmployee!=NULL)
    {
        employee_setNombre(pEmployee,nombreStr);
        employee_setSueldo(pEmployee,atoi(sueldoStr));
        employee_setHorasTrabajadas(pEmployee,atoi(horasTrabajadasStr));
        employee_setId(pEmployee,atoi(idStr));
    }

    return pEmployee;

}

int employee_setId(Employee* this,int id)
{
    int setteo=0;
    if(this!=NULL && id>0)
    {
        this->id=id;
        setteo=1;
    }

    return setteo;
}
int employee_getId(Employee* this,int* id)
{
    int getteo=0;

    if(this!=NULL && id!=NULL)
    {
        *id=this->id;
        getteo=1;
    }

    return getteo;
}

int employee_setNombre(Employee* this,char* nombre)
{
   int setteo=0;

    if(this!=NULL)
    {
        strcpy(this->nombre,nombre);
        setteo=1;
    }

    return setteo;
}


int employee_getNombre(Employee* this,char* nombre)
{
    int getteo=0;

    if(this!=NULL && nombre!=NULL)
    {
        strcpy(nombre,this->nombre);
        getteo=1;
    }

    return getteo;
}

int employee_setHorasTrabajadas(Employee* this,int horasTrabajadas)
{
    int setteo=0;
    if(this!=NULL && horasTrabajadas>0)
    {
        this->horasTrabajadas=horasTrabajadas;
        setteo=1;
    }

    return setteo;
}


int employee_getHorasTrabajadas(Employee* this,int* horasTrabajadas)
{
     int getteo=0;

    if(this!=NULL && horasTrabajadas!=NULL)
    {
        *horasTrabajadas=this->horasTrabajadas;
        getteo=1;
    }

    return getteo;
}

int employee_setSueldo(Employee* this,int sueldo)
{
    int setteo=0;
    if(this!=NULL && sueldo>0)
    {
        this->sueldo=sueldo;
        setteo=1;
    }

    return setteo;
}


int employee_getSueldo(Employee* this,int* sueldo)
{
     int getteo=0;

    if(this!=NULL && sueldo!=NULL)
    {
        *sueldo=this->sueldo;
        getteo=1;
    }

    return getteo;
}

int employee_searchIdEmployee(LinkedList* pArrayListEmployee, int auxId)
{
    int len;
    int i;
    Employee* auxEmpleado;
    int idEmpleado;
    int index=-1;

    len=ll_len(pArrayListEmployee);


    for(i=0;i<len;i++)
    {
        auxEmpleado=(Employee*)ll_get(pArrayListEmployee, i);
        idEmpleado=auxEmpleado->id;
        employee_getId(auxEmpleado,&idEmpleado);

       if(auxId==idEmpleado)
       {
            index=i;
            break;

       }
    }

    return index;
}
