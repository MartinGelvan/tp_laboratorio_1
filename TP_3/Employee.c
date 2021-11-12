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

int employee_CompareById(void* employeeOne, void* employeeTwo)
{
	int comparacion=0;
	Employee* empleadoUno;
	Employee* empleadoDos;
	int auxIdUno;
	int auxIdDos;

	if(employeeOne!=NULL && employeeTwo!=NULL)
	{
		empleadoUno=(Employee*)employeeOne;
		empleadoDos=(Employee*)employeeTwo;

		employee_getId(empleadoUno, &auxIdUno);
		employee_getId(empleadoDos, &auxIdDos);

		if(auxIdUno>auxIdDos)
		{
			comparacion=1;

		}else
		{
			if(auxIdUno<auxIdDos)
			{
				comparacion=-1;
			}
		}

		empleadoUno=NULL;
		empleadoDos=NULL;
	}

	return comparacion;
}

int employee_CompareByName(void* employeeOne, void* employeeTwo)
{
	int retorno=-1;
	Employee* empleadoUno;
	Employee* empleadoDos;
	char auxNombreUno[128];
	char auxNombreDos[128];

	if(employeeOne!=NULL && employeeTwo!=NULL)
	{
		empleadoUno=(Employee*)employeeOne;
		empleadoDos=(Employee*)employeeTwo;

		employee_getNombre(empleadoUno, auxNombreUno);
		employee_getNombre(empleadoDos, auxNombreDos);

		retorno=strcmp(auxNombreUno,auxNombreDos);

		empleadoUno=NULL;
		empleadoDos=NULL;

	}

	return retorno;
}

int employee_CompareBySueldo(void* employeeOne, void* employeeTwo)
{
	int comparacion=0;
	Employee* empleadoUno;
	Employee* empleadoDos;
	int auxSueldoUno;
	int auxSueldoDos;

	if(employeeOne!=NULL && employeeTwo!=NULL)
	{
		empleadoUno=(Employee*)employeeOne;
		empleadoDos=(Employee*)employeeTwo;

		employee_getSueldo(empleadoUno, &auxSueldoUno);
		employee_getSueldo(empleadoDos, &auxSueldoDos);

		if(auxSueldoUno>auxSueldoDos)
		{
			comparacion=1;

		}else
		{
			if(auxSueldoUno<auxSueldoDos)
			{
				comparacion=-1;
			}
		}

		empleadoUno=NULL;
		empleadoDos=NULL;
	}

	return comparacion;
}

int employee_CompareByHorasTrabajadas(void* employeeOne, void* employeeTwo)
{
	int comparacion=0;
	Employee* empleadoUno;
	Employee* empleadoDos;
	int auxHorasUno;
	int auxHorasDos;

	if(employeeOne!=NULL && employeeTwo!=NULL)
	{
		empleadoUno=(Employee*)employeeOne;
		empleadoDos=(Employee*)employeeTwo;

		employee_getHorasTrabajadas(empleadoUno, &auxHorasUno);
		employee_getHorasTrabajadas(empleadoDos, &auxHorasDos);

		if(auxHorasUno>auxHorasDos)
		{
			comparacion=1;

		}else
		{
			if(auxHorasUno<auxHorasDos)
			{
				comparacion=-1;
			}
		}

		empleadoUno=NULL;
		empleadoDos=NULL;
	}

	return comparacion;
}

