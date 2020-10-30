


#include <stdlib.h>
#include "Employee.h"
#include <string.h>

int employee_CompareByName(Employee* e1, Employee* e2)
{
    return strcmp(e1->nombre,e2->nombre);
}


int employee_CompareById(Employee* e1, Employee* e2)
{
    int compare=0;

    if(e1->id>e2->id)
    {
        compare=1;

    }else
    {
        if(e1->id<e2->id)
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
        strcpy(*nombre,this->nombre);
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
