/*
 ============================================================================
 Name        : TP_2.c
 Author      : 
 Version     :
 Copyright   : Your copyright notice
 Description : Hello World in C, Ansi-style
 ============================================================================
 */

#include <stdio.h>
#include <stdlib.h>
#include<string.h>
#define TAM 1000
#include "ArrayEmployees.h"
#include "ValidacionesPersonalizado.h"
#include "Inputs.h"

int main(void) {
	setbuf(stdout,NULL);

	int option;

	aEmployee listEmployees[TAM];
	aEmployee employeeAux;
	int i;
	int AlreadyEnterEmployee=0;
	int iD=0;
	int order;
	int iDParaEliminar;


	i=initEmployee(listEmployees,TAM);


	do
	{

		Menu();

		pedirEntero(&option," \nELIJA UNA OPCION(1-5): ", "\nERROR ESA OPCION NO EXISTE,ELIJA UNA OPCION(1-5):", 1, 5);



		switch(option)
		{

			case 1:
			AlreadyEnterEmployee=0;
			addEmployee(listEmployees,TAM,iD,employeeAux.name ,employeeAux.lastName,employeeAux.salary,employeeAux.sector);
			AlreadyEnterEmployee=1;

			if(i!=-1)
			{
				iD++;
				printf("\nCARGA EXITOSA!\n");

			}else
			{
				printf("\nNO HAY MAS ESPACIO!!\n");
			}
			system("pause");
			break;
			case 2:

			if(AlreadyEnterEmployee==0)
			{
				printf("\nPRIMERO INGRESE EMPLEADO\n");
			}else
			{
				ModifyEmployee(listEmployees,TAM);
			}
			system("pause");
			break;
			case 3:

			if(AlreadyEnterEmployee==0)
			{
				printf("\nPRIMERO INGRESE EMPLEADO\n");
			}else
			{
				printEmployees(listEmployees, TAM);
				pedirEntero(&iDParaEliminar, "INGRESE EL ID PARA ELIMINAR ", "ERROR, ESE ID NO EXISTE,INGRESE EL ID PARA ELIMINAR ", 0, iD);
				removeEmployee(listEmployees,TAM, iDParaEliminar);
			}
			system("pause");
			break;
			case 4:
			if(AlreadyEnterEmployee==0)
			{
				printf("\nPRIMERO INGRESE EMPLEADO\n");
			}else
			{
				pedirEntero(&option, "Que desea mostrar? \n\n"
						"1. Listado de los empleados ordenados alfabéticamente por Apellido y Sector\n\n"
						"2. Total y promedio de los salarios, y cuántos empleados superan el salario promedio\n\nElija opcion: ", "Error,Que desea mostrar? \n\n"
						"1. Listado de los empleados ordenados alfabéticamente por Apellido y Sector\n\n"
						"2. Total y promedio de los salarios, y cuántos empleados superan el salario promedio\n\nElija opcion:  ", 1, 2);

				switch(option)
				{
				case 1:
						printf("\n____________________________\n");
					    printf("\nELIJA COMO QUIERE ORDENAR EL EMPLEADO\n");
					    printf("\n---------------------------------\n");
					    printf("\n\n1.ASCENDENTE A-->Z\n\n2.DESCENDENTE Z--->A\n");
					    printf("\nELIJA UNA OPCION: ");
					    scanf("%d",&order);
					sortEmployeeByName(listEmployees,TAM, order);
					printEmployees(listEmployees, TAM);
					break;
				case 2:
						OptionFour(listEmployees,TAM);
					break;

				}

			}

			system("pause");
			break;
			case 5:
			printf("FINALIZADO\n");
			system("pause");
			break;


		}


	}while(option!=5);



	return EXIT_SUCCESS;
}
