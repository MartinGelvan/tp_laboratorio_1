/*
 * ArrayEmployes.h
 *
 *  Created on: 8 oct. 2021
 *      Author: PCNEW
 */

#ifndef ARRAYEMPLOYEES_H_
#define ARRAYEMPLOYEES_H_


typedef struct
{
    int id;
    char name[51];
    char lastName[51];
    float salary;
    int sector;
    int isEmpty;


}aEmployee;


/** \brief Show menu with main options
 *
 * \return void
 *
 */
void Menu();

/**
 * \brief add in a existing list of employees the values received as parameters in the first empty position
 *
 * \param listEmployees []
 * \param len int
 * \param id int
 * \param name[] char
 * \param lastName[] char
 * \param salary float
 * \param sector int
 * \return int Return (-1) if Error [Invalid length or NULL pointer or without free space] - (0) if Ok
 */
void addEmployee(aEmployee listEmployees[],int len,int id, char name[],char	lastName[],float salary,int sector);

/** \brief Only show one employee
 *
 * \param aEmployee (list Employees)
 * \return void
 *
 */
void PrintOneEmployee(aEmployee);
/** \brief Look for a free space
 *
 * \param aEmployee[] (list Employee)
 * \param int len
 * \return int
 *
 */
int SearchFree(aEmployee[],int);
/** \brief Remove a Employee by Id
 *
 * \param aEmployee[] (list Employee)
 * \param int len
 * \param int id
 * \return int Return (-1) if Error [Invalid length or NULL pointer or if can't
		find a employee] - (0) if Ok
 *
 */
int removeEmployee(aEmployee listEmployees[],int len, int id);
/** \brief
 *
 * \param aEmployee[]  (list Employee)
 * \param int len
 * \return void
 *
 */
void printEmployees(aEmployee[],int);
/** \brief Allows the user to modify the employee based on his id
 *
 * \param aEmployee[] (list Employee)
 * \param int len
 * \return void
 *
 */
void ModifyEmployee(aEmployee[],int);
/** \brief find an Employee by Id en returns the index position in array.
 *
 * \param aEmployee[] (list Employee)
 * \param int len
 * \param int id
 * \return int Return employee index position or (-1) if [Invalid length or NULL
			pointer received or employee not found]
 *
 */
int findEmployeeById(aEmployee[],int,int);
/** \brief Sort the elements in the array of employees and order
 *
 * \param aEmployee[] (list Employee)
 * \param int len
 * \param int order
 * \return int Return (-1) if Error [Invalid length or NULL pointer] - (0) if Ok
 *
 */
int sortEmployeeByName(aEmployee listEmployees[],int len, int order);
/** \brief Add up employee salaries
 *
 * \param aEmployee[] (list Employee)
 * \param int len
 * \return float
 *
 */
float SumSalaries(aEmployee[],int);
/** \brief average employee salaries
 *
 * \param aEmployee[] (list Employee)
 * \param int len
 * \return float
 *
 */
float AverageSalaries(aEmployee[],int);
/** \brief Amount employees loaded in the list
 *
 * \param aEmployee[] (list Employee)
 * \param int len
 * \return int
 *
 */
int AmountLoaded(aEmployee[],int);
/** \brief  Amount exceed average salary
 *
 * \param aEmployee[] (list Employee)
 * \param int len
 * \return int
 *
 */
int AmountExceedAverageSalary(aEmployee[],int);
/** \brief To indicate that all position in the array are empty,this function put the flag (isEmpty)
 * 		in TRUE in all position of the array
 *
 * \param aEmployee[] (list Employee)
 * \param int len
 * \return int
 *
 */
int initEmployee(aEmployee[],int);
/** \brief print the content of employees array
 *
 * \param aEmployee[] (list Employees)
 * \param int len
 * \return void
 *
 */
void OptionFour(aEmployee[],int);



#endif /* ARRAYEMPLOYEES_H_ */
