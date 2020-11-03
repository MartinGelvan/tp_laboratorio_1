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

/** \brief Compara los nombres de los empleados para luego ordenarlos de la A a la Z o de la Z a la A
 *
 * \param e1 void* Recibe un empleado
 * \param e2 void* Recibe otro empleado
 * \return int Me retorna la comparacion
 *
 */
int employee_CompareByName(void* e1, void* e2);
/** \brief Compara los Id de los empleados para luego ordenarlos de forma ascendente o descendente
 *
 * \param e1 void* Recibe un empleado
 * \param e2 void* Recibe otro empleado
 * \return int Me retorna 1 si e1 es mayor a e2, me retorna -1 si e1 es menor que e2 y me retorna 0 si son iguales
 *
 */
int employee_CompareById(void* e1, void* e2);
/** \brief Compara los sueldos de los empleados para luego ordenarlos de forma ascendente o descendente
 *
 * \param e1 void* Recibe un empleado
 * \param e2 void* Recibe otro empleado
 * \return int Me retorna 1 si e1 es mayor a e2, me retorna -1 si e1 es menor que e2 y me retorna 0 si son iguales
 *
 */
int employee_CompareBySalary(void* e1, void* e2);
/** \brief Compara las horas de trabajo de los empleados para luego ordenarlos de forma ascendente o descendente
 *
 * \param e1 void* Recibe un empleado
 * \param e2 void* Recibe otro empleado
 * \return int Me retorna 1 si e1 es mayor a e2, me retorna -1 si e1 es menor que e2 y me retorna 0 si son iguales
 *
 */
int employee_CompareByHorasTrabajadas(void* e1, void* e2);
/** \brief Crea espacio en memoria dinamica
 *
 * \return Employee*
 *
 */
Employee* employee_new();
/** \brief Guardo con los setters los datos del empleado utilizando auxiliares
 *
 * \param idStr char*
 * \param nombreStr char*
 * \param horasTrabajadasStr char*
 * \param sueldoStr char*
 * \return Employee* Me retorna un empleado
 *
 */
Employee* employee_newParametros(char* idStr,char* nombreStr,char* horasTrabajadasStr,char* sueldoStr);
void employee_delete();

/** \brief Seteo el id
 *
 * \param this Employee* Recibe un empleado
 * \param id int Recibe un id
 * \return int Me retorna 1 si lo pudo setear
 *
 */
int employee_setId(Employee* this,int id);
/** \brief Obtengo el id
 *
 * \param this Employee* Recibe un empleado
 * \param id int* Recibe un id
 * \return int Me retorna 1 si lo pudo obtener
 *
 */
int employee_getId(Employee* this,int* id);

/** \brief Seteo el Nombre
 *
 * \param this Employee* Recibe un empleado
 * \param nombre char* Recibe un Nombre
 * \return int Me retorna 1 si lo pudo setear
 *
 */
int employee_setNombre(Employee* this,char* nombre);
/** \brief Obtengo el Nombre
 *
 * \param this Employee* Recibe un empleado
 * \param nombre char* Recibe un Nombre
 * \return int Me retorna 1 si lo pudo obtener
 *
 */
int employee_getNombre(Employee* this,char* nombre);

/** \brief Seteo las horas trabajadas
 *
 * \param this Employee* Recibe un empleado
 * \param horasTrabajadas int Recibe las horas trabajadas
 * \return int Me retorna 1 si lo pudo setear
 *
 */
int employee_setHorasTrabajadas(Employee* this,int horasTrabajadas);
/** \brief Obtengo las horas trabajadas
 *
 * \param this Employee* Recibe un empleado
 * \param horasTrabajadas int* Recibe las horas trabajadas
 * \return int Me retorna 1 si lo pudo obtener
 *
 */
int employee_getHorasTrabajadas(Employee* this,int* horasTrabajadas);

/** \brief Seteo el sueldo
 *
 * \param this Employee* Recibe un empleado
 * \param sueldo int Recibe un sueldo
 * \return int Me retorna 1 si lo pudo setear
 *
 */
int employee_setSueldo(Employee* this,int sueldo);
/** \brief Obtengo el sueldo
 *
 * \param this Employee* Recibe un empleado
 * \param sueldo int* Recibe un sueldo
 * \return int Me retorna 1 si lo pudo obtener
 *
 */
int employee_getSueldo(Employee* this,int* sueldo);

/** \brief Obtengo la posicion de un empleado
 *
 * \param pArrayListEmployee LinkedList*
 * \param auxId int
 * \return int Me retorna la posicion
 *
 */
int employee_searchIdEmployee(LinkedList* pArrayListEmployee, int auxId);


#endif // employee_H_INCLUDED
