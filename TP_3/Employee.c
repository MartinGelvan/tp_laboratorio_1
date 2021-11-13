#include <stdlib.h>
#include "Employee.h"
#include "ValidacionesPersonalizado.h"
#include <string.h>

/**
 * @fn Employee employee_new*()
 * @brief Crea espacio libre en memoria dinamica
 *
 * @return retorna el espacio creado dinamicamente
 */
Employee* employee_new()
{
	Employee* pListEmployees;

	pListEmployees= (Employee*) malloc(sizeof(Employee));

	return pListEmployees;

}

/**
 * @fn Employee employee_newParametros*(char*, char*, char*, char*)
 * @brief Me guardo con los setters los datos del empleado utilizando auxiliares
 *
 * @param idStr
 * @param nombreStr
 * @param horasTrabajadasStr
 * @param sueldoStr
 * @return Me retorna un empleado
 */
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

/**
 * @fn int employee_setId(Employee*, int)
 * @brief Seteo el ID
 *
 * @param this recibe algo de tipo empleado
 * @param id recibe un id
 * @return Me retorna 1 si lo pudo settear
 */
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

/**
 * @fn int employee_getId(Employee*, int*)
 * @brief Obtengo un ID
 *
 * @param this Recibe algo del tipo empleado
 * @param id recibe un id
 * @return Me retorna 1 si lo pudo obtener
 */
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

/**
 * @fn int employee_setNombre(Employee*, char*)
 * @brief Seteo el nombre
 *
 * @param this Recibe algo de tipo empleado
 * @param nombre Recibe un nombre
 * @return Me retorna 1 si lo pudo settear
 */
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

/**
 * @fn int employee_getNombre(Employee*, char*)
 * @brief Obtengo el nombre
 *
 * @param this Recibe algo del tipo empleado
 * @param nombre Recibe un nombre
 * @return Me retorna 1 si lo pudo obtener
 */
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

/**
 * @fn int employee_setHorasTrabajadas(Employee*, int)
 * @brief Seteo las Horas Trabajadas
 *
 * @param this Recibe algo de tipo empleado
 * @param horasTrabajadas Recibe las horas trabajadas
 * @return Me retorna 1 si lo pudo settear
 */
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

/**
 * @fn int employee_getHorasTrabajadas(Employee*, int*)
 * @brief Obtengo las Horas Trabajadas
 *
 * @param this this Recibe algo de tipo empleado
 * @param horasTrabajadas Recibe las horas trabajadas
 * @return Me retorna 1 si lo pudo obtener
 */
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

/**
 * @fn int employee_setSueldo(Employee*, int)
 * @brief  Seteo el sueldo
 *
 * @param this this Recibe algo de tipo empleado
 * @param sueldo Recibe un sueldo
 * @return Me retorna 1 si lo pudo settear
 */
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

/**
 * @fn int employee_getSueldo(Employee*, int*)
 * @brief Obtengo un sueldo
 *
 * @param this this Recibe algo de tipo empleado
 * @param sueldo Recibe un sueldo
 * @return Me retorna 1 si lo pudo obtener
 */
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

/**
 * @fn void employee_delete(Employee*)
 * @brief Me realiza el free
 *
 * @param this Recibe algo del tipo empleado
 */
void employee_delete(Employee* this)
{
	if(this!=NULL)
	{
		free(this);
		this=NULL;
	}
}

/**
 * @fn int employee_CompareById(void*, void*)
 * @brief  Compara los id de los empleados para despues ordenarlos de forma ascendente o descendente
 *
 * @param employeeOne Recibe un empleado
 * @param employeeTwo Recibe otro empleado
 * @return Me retorna 1 si el Id del empleado 1 es mayor que el empleado 2, me retorna -1 si el Id del empleado 1 es menor que el empleado 2
 */
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

/**
 * @fn int employee_CompareByName(void*, void*)
 * @brief Compara los nombres de los empleados y luego los ordena tanto de forma A a la Z o de la Z a la A
 *
 * @param employeeOne Recibe un empleado
 * @param employeeTwo Recibe otro empleado
 * @return Me retorna la comparacion de los nombres
 */
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

/**
 * @fn int employee_CompareBySueldo(void*, void*)
 * @brief Compara los sueldos de los empleados y luego los forma de madera ascendente o descendente
 *
 * @param employeeOne Recibe un empleado
 * @param employeeTwo Recibe otro empleado
 * @return Retorna 1 si el suelado del empleado 1 es mayor al del empleado 2, y retorna -1 si el sueldo del empleado 1 es menor al sueldo del empleado 2
 */
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

/**
 * @fn int employee_CompareByHorasTrabajadas(void*, void*)
 * @brief Compara las Horas Trabajadas de los empleados y luego los forma de madera ascendente o descendente
 *
 * @param employeeOne Recibe un empleado
 * @param employeeTwo Recibe otro empleado
 * @return Retorna 1 si las Horas Trabajadas del empleado 1 es mayor al del empleado 2, y retorna -1 si Las Horas Trabajadas del empleado 1 es menor a las Horas Trabajadas del empleado 2
 */
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

/**
 * @fn int employee_searchIdEmployee(LinkedList*, int)
 * @brief Busco por Id el indice de un empleado en especifico
 *
 * @param this Recibe algo del tipo empleado
 * @param auxId Recibe un Id
 * @return Me retorna el indice del empleado buscado
 */
int employee_searchIdEmployee(LinkedList* this, int auxId)
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


