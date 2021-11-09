#include <stdio.h>
#include <stdlib.h>
#include "LinkedList.h"
#include "Controller.h"
#include "Employee.h"
#include "Inputs.h"

/****************************************************
    Menu:
     1. Cargar los datos de los empleados desde el archivo data.csv (modo texto).
     2. Cargar los datos de los empleados desde el archivo data.csv (modo binario).
     3. Alta de empleado
     4. Modificar datos de empleado
     5. Baja de empleado
     6. Listar empleados
     7. Ordenar empleados
     8. Guardar los datos de los empleados en el archivo data.csv (modo texto).
     9. Guardar los datos de los empleados en el archivo data.csv (modo binario).
    10. Salir
*****************************************************/



int main()
{
	setbuf(stdout,NULL);
    int option = 10;


    LinkedList* listaEmpleados = ll_newLinkedList();
    do{
    	pedirEntero(&option, "1.Cargar los datos de los empleados desde el archivo data.csv (modo texto)\n"
    			 "2. Cargar los datos de los empleados desde el archivo data.csv (modo binario)\n"
    			"3. Alta de empleado\n"
    		     "4. Modificar datos de empleado\n"
    		     "5. Baja de empleado\n"
    		     "6. Listar empleados\n"
    		     "7. Ordenar empleados\n"
    		     "8. Guardar los datos de los empleados en el archivo data.csv (modo texto)\n"
    		     "9. Guardar los datos de los empleados en el archivo data.csv (modo binario)\n"
    		    "10. Salir\n"
    		    "Elija la opcion: ", "Error, esa opcion no existe, reingrese la opcion.\n"
    		    "1. Cargar los datos de los empleados desde el archivo data.csv (modo texto)\n"
				 "2. Cargar los datos de los empleados desde el archivo data.csv (modo binario)\n"
				 "3. Alta de empleado\n"
				 "4. Modificar datos de empleado\n"
				 "5. Baja de empleado\n"
				 "6. Listar empleados\n"
				 "7. Ordenar empleados\n"
				 "8. Guardar los datos de los empleados en el archivo data.csv (modo texto)\n"
				" 9. Guardar los datos de los empleados en el archivo data.csv (modo binario)\n"
				"10. Salir\n"
				"Elija la opcion: ", 1, 10);

        switch(option)
        {
            case 1:
                controller_loadFromText("data.csv",listaEmpleados);
                system("pause");
                break;
            case 2:
            	controller_loadFromBinary("data.csv" , listaEmpleados);
			break;

			case 3:
				controller_addEmployee(listaEmpleados);
			break;

			case 4:
				//controller_editEmployee(LinkedList* pArrayListEmployee);
			break;

			case 5:
				controller_removeEmployee(listaEmpleados);
			break;

			case 6:
				controller_ListEmployee(listaEmpleados);
			break;

			case 7:
				//controller_sortEmployee(LinkedList* pArrayListEmployee);
			break;

			case 8:
				controller_saveAsText("data.csv" , listaEmpleados);
			break;

			case 9:
				controller_saveAsBinary("data.csv" ,listaEmpleados );
			break;

			case 10:
					printf("\nFinalizado\n");
			break;
        }
    }while(option != 10);
    return 0;
}

