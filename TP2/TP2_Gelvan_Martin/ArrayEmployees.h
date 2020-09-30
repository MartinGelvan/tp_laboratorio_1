
typedef struct
{
    int id;
    char name[51];
    char lastName[51];
    float salary;
    int sector;
    int isEmpty;


}aEmployee;

/** \brief add in a existing list of employees the values received as parameters in the first empty position
 *
 * \param aEmployee[] (list Employee)
 * \param int len
 * \return void
 *
 */
void addEmployee(aEmployee[],int);
/** \brief
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
/** \brief print the content of employees array
 *
 * \param aEmployee[]  (list Employee)
 * \param int len
 * \return void
 *
 */
void printEmployees(aEmployee[],int);
/** \brief
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
/** \brief
 *
 * \param aEmployee[] (list Employee)
 * \param int len
 * \return float
 *
 */
float SumSalaries(aEmployee[],int);
/** \brief
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

