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
    int exito;


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
                exito=controller_loadFromText("data.csv",listaEmpleados);
                if(exito==1)
                {
                	printf("\nSe cargo en forma de texto con exito!\n");
                }else
                {
                	printf("\nNo se logro cargar en forma de texto\n");
                }


                system("pause");
                break;
            case 2:
            	exito=controller_loadFromBinary("data.csv" , listaEmpleados);
            	if(exito==1)
				{
					printf("\nSe cargo en forma binaria con exito!\n");
				}else
				{
					printf("\nNo se logro cargar en forma binaria\n");
				}
			break;

			case 3:
				controller_addEmployee(listaEmpleados);
			break;

			case 4:
				controller_editEmployee(listaEmpleados);
			break;

			case 5:
				controller_removeEmployee(listaEmpleados);
			break;

			case 6:
				controller_ListEmployee(listaEmpleados);
			break;

			case 7:
				controller_sortEmployee(listaEmpleados);
			break;

			case 8:
				exito=controller_saveAsText("data.csv" , listaEmpleados);
				if(exito==1)
				{
					printf("\nSe guardo en forma de texto con exito!\n");
				}else
				{
					printf("\nNo se logro guardar en forma de texto\n");
				}

			break;

			case 9:
				exito=controller_saveAsBinary("data.csv" ,listaEmpleados );
				if(exito==1)
				{
					printf("\nSe guardo en forma binaria con exito!\n");
				}else
				{
					printf("\nNo se logro guardar en forma binaria\n");
				}
			break;

			case 10:
					printf("\nFinalizado\n");
			break;
        }
    }while(option != 10);
    return 0;
}

