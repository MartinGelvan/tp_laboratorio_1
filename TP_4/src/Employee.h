#ifndef employee_H_INCLUDED
#define employee_H_INCLUDED
#include "LinkedList.h"

typedef struct
{
    int id;
    char nombre[128];
    int horasTrabajadas;
    int sueldo;
}Employee;

Employee* employee_new();
Employee* employee_newParametros(char* idStr,char* nombreStr,char* horasTrabajadasStr,char* sueldoStr);
void employee_delete(Employee* this);


int employee_setId(Employee* this,int id);
int employee_getId(Employee* this,int* id);

int employee_setNombre(Employee* this,char* nombre);
int employee_getNombre(Employee* this,char* nombre);

int employee_setHorasTrabajadas(Employee* this,int horasTrabajadas);
int employee_getHorasTrabajadas(Employee* this,int* horasTrabajadas);

int employee_setSueldo(Employee* this,int sueldo);
int employee_getSueldo(Employee* this,int* sueldo);


int employee_CompareById(void* employeeOne, void* employeeTwo);
int employee_CompareByName(void* employeeOne, void* employeeTwo);
int employee_CompareBySueldo(void* employeeOne, void* employeeTwo);
int employee_CompareByHorasTrabajadas(void* employeeOne, void* employeeTwo);

int employee_searchIdEmployee(LinkedList* this, int auxId);
int employee_ultimoId(LinkedList* this);
#endif // employee_H_INCLUDED
