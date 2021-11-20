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
    int banderaTexto=0;
    int banderaBinario=0;


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
                exito=controller_loadFromText("src\\data.csv",listaEmpleados);
                if(exito==1)
                {
                	printf("\nSe cargo en forma de texto con exito!\n\n");
                	banderaTexto=1;
                }else
                {
                	printf("\nNo se logro cargar en forma de texto\n");
                }


                system("pause");
                break;
            case 2:
            	exito=controller_loadFromBinary("src\\dataBinario.csv" , listaEmpleados);
            	if(exito==1)
				{
					printf("\nSe cargo en forma binaria con exito!\n\n");
					banderaBinario=1;
				}else
				{
					printf("\nNo se logro cargar en forma binaria\n");
				}
            	system("pause");
			break;

			case 3:
				if(banderaTexto==1 || banderaBinario==1)
				{
					exito=controller_addEmployee(listaEmpleados);
					if(exito==1)
					{
						printf("\nSe agrego un empleado con exito!\n\n");
					}else
					{
						printf("\nNo se logro agregar un empleado\n");
					}
				}else
				{
					printf("\nIngrese la opcion 1 primero o la 2\n");
				}
				system("pause");
			break;

			case 4:
				if(banderaTexto==1 || banderaBinario==1)
				{
					exito=controller_editEmployee(listaEmpleados);
					banderaBinario=1;


				}else
				{
					printf("\nIngrese la opcion 1 primero o la 2\n");
				}
				system("pause");
			break;

			case 5:
				if(banderaTexto==1 || banderaBinario==1)
				{
					controller_removeEmployee(listaEmpleados);

				}else
				{
					printf("\nIngrese la opcion 1 primero o la 2\n");
				}
				system("pause");
			break;

			case 6:
				if(banderaTexto==1 || banderaBinario==1)
				{
					exito=controller_ListEmployee(listaEmpleados);
					if(exito==1)
					{
						printf("\nSe mostro la lista con exito!\n\n");
						banderaBinario=1;
					}else
					{
						printf("\nNo se logro mostrar la lista\n");
					}
				}else
				{
					printf("\nIngrese la opcion 1 primero o la 2\n");
				}
				system("pause");
			break;

			case 7:
				if(banderaTexto==1 || banderaBinario==1)
				{
					exito=controller_sortEmployee(listaEmpleados);
					if(exito==1)
					{
						printf("\nSe ordeno con exito!\n\n");
						banderaBinario=1;
					}else
					{
						printf("\nNo se logro ordenar\n");
					}
				}else
				{
					printf("\nIngrese la opcion 1 primero o la 2\n");
				}
				system("pause");
			break;

			case 8:
				if(banderaTexto==1 || banderaBinario==1)
				{
					exito=controller_saveAsText("src\\data.csv" , listaEmpleados);
					if(exito==1)
					{
						printf("\nSe guardo en forma de texto con exito!\n\n");
					}else
					{
						printf("\nNo se logro guardar en forma de texto\n");
					}

				}else
				{
					printf("\nIngrese la opcion 1 primero o la 2\n");
				}

				system("pause");
			break;

			case 9:

				if(banderaTexto==1 || banderaBinario==1)
				{
					exito=controller_saveAsBinary("src\\dataBinario.csv" ,listaEmpleados );
					if(exito==1)
					{
						printf("\nSe guardo en forma binaria con exito!\n\n");
					}else
					{
						printf("\nNo se logro guardar en forma binaria\n");
					}

				}else
				{
					printf("\nIngrese la opcion 1 primero o la 2\n");
				}
				system("pause");
			break;

			case 10:
					printf("\nFinalizado\n");

			break;
        }
    }while(option != 10);
    return 0;
}

