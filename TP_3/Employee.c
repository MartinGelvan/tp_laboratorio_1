#include <stdlib.h>
#include "Employee.h"
#include "ValidacionesPersonalizado.h"
#include <string.h>

Employee* employee_new()
{
	Employee* pListEmployees;

	pListEmployees= (Employee*) malloc(sizeof(Employee));

	return pListEmployees;

}

Employee* employee_newParametros(char* idStr,char* nombreStr,char* horasTrabajadasStr,char* sueldoStr)
{
	Employee* pEmployee;

	int IdTransformado;
	int HorasTransformado;
	int sueldoTransformado;
	pEmployee=employee_new();

	if(pEmployee!=NULL && idStr!=NULL && nombreStr!=NULL && horasTrabajadasStr!=NULL && sueldoStr!=NULL)
	{

		validacion_Numero(idStr);
		IdTransformado=atoi(idStr);
		employee_setId(pEmployee, IdTransformado);
		validacion_Cadena(nombreStr);
		employee_setNombre(pEmployee, nombreStr);
		validacion_Numero(horasTrabajadasStr);
		HorasTransformado=atoi(horasTrabajadasStr);
		employee_setHorasTrabajadas(pEmployee, HorasTransformado);
		validacion_Numero(sueldoStr);
		sueldoTransformado=atoi(sueldoStr);
		employee_setSueldo(pEmployee, sueldoTransformado);

	}

	return pEmployee;
}

int employee_setId(Employee* this,int id)
{
	int retorno=0;

	if(this!=NULL)
	{
		this->id=id;
		retorno=1;
	}

	return retorno;
}

int employee_getId(Employee* this,int* id)
{
	int retorno=0;

	if(this!=NULL && id!=NULL)
	{
		*id=this->id;
		retorno=1;
	}

	return retorno;
}

int employee_setNombre(Employee* this,char* nombre)
{
	int retorno=0;

	if(this!=NULL && nombre!=NULL)
	{
		strcpy(this->nombre,nombre);
		retorno=1;
	}

	return retorno;
}

int employee_getNombre(Employee* this,char* nombre)
{
	int retorno=0;

	if(this!=NULL && nombre!=NULL)
	{
		strcpy(nombre,this->nombre);
		retorno=1;
	}

	return retorno;
}

int employee_setHorasTrabajadas(Employee* this,int horasTrabajadas)
{
	int retorno=0;

	if(this!=NULL)
	{
		this->horasTrabajadas=horasTrabajadas;
		retorno=1;
	}

	return retorno;
}

int employee_getHorasTrabajadas(Employee* this,int* horasTrabajadas)
{
	int retorno=0;

	if(this!=NULL && horasTrabajadas!=NULL)
	{
		*horasTrabajadas=this->horasTrabajadas;
		retorno=1;
	}

	return retorno;
}

int employee_setSueldo(Employee* this,int sueldo)
{
	int retorno=0;

	if(this!=NULL)
	{
		this->sueldo=sueldo;
		retorno=1;
	}

	return retorno;
}

int employee_getSueldo(Employee* this,int* sueldo)
{
	int retorno=0;

	if(this!=NULL && sueldo!=NULL)
	{
		*sueldo=this->sueldo;
		retorno=1;
	}

	return retorno;
}

void employee_delete(Employee* this)
{
	if(this!=NULL)
	{
		free(this);
		this=NULL;
	}
}

