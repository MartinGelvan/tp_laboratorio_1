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

int main(void) {
	setbuf(stdout,NULL);

	int option;

	aEmployee listEmployees[TAM];
	int i;
	int AlreadyEnterEmployee=0;


	i=initEmployee(listEmployees,TAM);


	do
	{

		Menu();
		printf("\nELIJA UNA OPCION: ");
		scanf("%d", &option);

		while(option!=1 && option!=2 && option!=3 && option!=4 && option!=5)
		{
			printf("\nERROR ESA OPCION NO EXISTE\n");
			printf("REINGRESE LA OPCION: ");
			scanf("%d", &option);
		}

		switch(option)
		{

			case 1:
			AlreadyEnterEmployee=0;
			addEmployee(listEmployees,TAM);
			AlreadyEnterEmployee=1;

			if(i!=-1)
			{
				printf("\nCARGA EXITOSA!\n");

			}else
			{
				printf("\nNO HAY MAS ESPACIO!!\n");
			}
			break;
			case 2:

			if(AlreadyEnterEmployee==0)
			{
				printf("\nPRIMERO INGRESE EMPLEADO\n");
			}else
			{
				ModifyEmployee(listEmployees,TAM);
			}

			break;
			case 3:

			if(AlreadyEnterEmployee==0)
			{
				printf("\nPRIMERO INGRESE EMPLEADO\n");
			}else
			{
			  removeEmployee(listEmployees,TAM);
			}

			break;
			case 4:
			if(AlreadyEnterEmployee==0)
			{
				printf("\nPRIMERO INGRESE EMPLEADO\n");
			}else
			{
			  OptionFour(listEmployees,TAM);
			}

			break;
			case 5:
			printf("FINALIZADO");
			break;


		}


	}while(option!=5);



	return EXIT_SUCCESS;
}
