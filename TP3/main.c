
#include "LinkedList.h"
#include "Controller.h"
#include "Employee.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

/****************************************************
    Menu:
     1. Cargar los datos de los empleados desde el archivo data.csv (modo texto).x
     2. Cargar los datos de los empleados desde el archivo data.dat (modo binario).
     3. Alta de empleado x
     4. Modificar datos de empleado x
     5. Baja de empleado x
     6. Listar empleados x
     7. Ordenar empleados
     8. Guardar los datos de los empleados en el archivo data.csv (modo texto).
     9. Guardar los datos de los empleados en el archivo data.csv (modo binario).
    10. Salir
*****************************************************/


int main()
{
    LinkedList* miLista;
    int opcion;
    int siguienteId=1;

    miLista = ll_newLinkedList();//constructor

    do
    {
        printf("1. Cargar los datos de los empleados desde el archivo data.csv (modo texto)\n");
        printf("2. Cargar los datos de los empleados desde el archivo data.csv (modo binario)\n");
        printf("3. Alta de empleado\n");
        printf("4. Modificar datos de empleado\n");
        printf("5. Baja de empleado\n");
        printf("6. Listar empleados\n");
        printf("7. Ordenar empleados\n");
        printf("8. Guardar los datos de los empleados en el archivo data.csv (modo texto)\n");
        printf("9. Guardar los datos de los empleados en el archivo data.csv (modo binario)\n");
        printf("10. Salir\n");
        printf("\nElija una opcion:");

        scanf("%d",&opcion);

        switch(opcion)
        {
            case 1:
                    controller_loadFromText("data.csv" , miLista);
            break;

            case 2:
                    controller_loadFromBinary("data.dat" , miLista);
            break;

            case 3:
                    controller_addEmployee(miLista,siguienteId);
            break;

            case 4:
                    controller_editEmployee(miLista);
            break;

            case 5:
                    controller_removeEmployee(miLista);
            break;

            case 6:
                    controller_ListEmployee(miLista);
            break;

            case 7:
                    controller_sortEmployee( miLista);
            break;

            case 8:

            break;

            case 9:

            break;

            case 10:

            break;

        }


    }while(opcion!=10);

    return 0;
}
