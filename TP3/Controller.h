/** \brief Carga los datos del archivo csv
 *
 * \param path char* Le paso la direccion del archivo o el nombre del archivo
 * \param pArrayListEmployee LinkedList*
 * \return int Me retorna 0 o 1 si pudo o no cargar
 *
 */
int controller_loadFromText(char* path , LinkedList* pArrayListEmployee);
/** \brief Carga los datos del archivo dat
 *
 * \param path char* Le paso la direccion del archivo o el nombre del archivo
 * \param pArrayListEmployee LinkedList*
 * \return int Me retorna 0 o 1 si pudo o no cargar
 *
 */
int controller_loadFromBinary(char* path , LinkedList* pArrayListEmployee);
/** \brief Agrega un empleado nuevo a la lista de empleados
 *
 * \param pArrayListEmployee LinkedList*
 * \return int Me retorna 0 o 1 si pudo o no agregarlo
 *
 */
int controller_addEmployee(LinkedList* pArrayListEmployee);
/** \brief Permite a partir del Id modificar un empleado
 *
 * \param pArrayListEmployee LinkedList*
 * \return int Me retorna si pudo modificar o no
 *
 */
int controller_editEmployee(LinkedList* pArrayListEmployee);
/** \brief Permite a partir del Id dar de baja a un empleado
 *
 * \param pArrayListEmployee LinkedList*
 * \return int Me retorna si pudo eliminar o no
 *
 */
int controller_removeEmployee(LinkedList* pArrayListEmployee);
/** \brief Muestro lista de empleados
 *
 * \param pArrayListEmployee LinkedList*
 * \return int Me retorna 0 o 1 si pudo o no mostrarlos
 *
 */
int controller_ListEmployee(LinkedList* pArrayListEmployee);
/** \brief Me permite ordenar segun el usueario decida la lista de empleados
 *
 * \param pArrayListEmployee LinkedList*
 * \return int Me retorna 1 si lo pudo ordenar
 *
 */
int controller_sortEmployee(LinkedList* pArrayListEmployee);
/** \brief Me permite guardar las modificaciones que haga en la lista al archivo csv
 *
 * \param path char* Le paso la direccion del archivo o el nombre del archivo
 * \param pArrayListEmployee LinkedList*
 * \return int Me retorna si pudo o no guardar
 *
 */
int controller_saveAsText(char* path , LinkedList* pArrayListEmployee);
/** \brief Me permite guardar las modificaciones que haga en la lista al archivo dat
 *
 * \param path char* Le paso la direccion del archivo o el nombre del archivo
 * \param pArrayListEmployee LinkedList*
 * \return int Me retorna si pudo o no guardar
 *
 */
int controller_saveAsBinary(char* path , LinkedList* pArrayListEmployee);





