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
/** \brief add in a existing list of employees the values received as parameters in the first empty position
 *
 * \param aEmployee[] (list Employee)
 * \param int len
 * \return void
 *
 */

void addEmployee(aEmployee[],int);
/** \brief Order employees
 *
 * \param aEmployee[] (list Employees)
 * \param int len
 * \return void
 *
 */
void OrderEmployees(aEmployee[],int);
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
 * \return void
 *
 */
void removeEmployee(aEmployee[],int);
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
 * \return int
 *
 */
int findEmployeeById(aEmployee[],int,int);
/** \brief Sort the elements in the array of employees
 *
 * \param aEmployee[] (list Employee)
 * \param int len
 * \return void
 *
 */
void sortEmployeeByName(aEmployee[],int);
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
/** \brief
 *
 * \param aEmployee[] (list Employee)
 * \param int len
 * \return int
 *
 */
int AmountLoaded(aEmployee[],int);
/** \brief
 *
 * \param aEmployee[] (list Employee)
 * \param int len
 * \return int
 *
 */
int AmountExceedAverageSalary(aEmployee[],int);
/** \brief To indicate that all position in the array are empty
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
