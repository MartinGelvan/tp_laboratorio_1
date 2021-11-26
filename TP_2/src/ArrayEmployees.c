/*
 * ArrayEmployees.c
 *
 *  Created on: 8 oct. 2021
 *      Author: PCNEW
 */


#include <stdio.h>
#include <stdlib.h>
#include<string.h>
#define TAM 1000
#include "ArrayEmployees.h"
#include "Inputs.h"
#include "ValidacionesPersonalizado.h"

void Menu()
{
    printf("\n1.ALTAS\n2.MODIFICAR\n3.BAJA\n4.INFORMAR\n5.SALIR\n");

}

void addEmployee(aEmployee listEmployees[],int len,int id, char name[],char	lastName[],float salary,int sector)
{

    int i;

    i=SearchFree(listEmployees,len);


    if(i!=-1)
    {
    	pedirCadena(name, "INGRESE NOMBRE: ","ERROR, REINGRESE NOMBRE (MAX 21 CARACTERES Y EN LETRAS): ", 21);
    	validacion_Minuscula(name);
    	pedirCadena(lastName, "INGRESE APELLIDO: ","ERROR, REINGRESE APELLIDO (MAX 21 CARACTERES Y EN LETRAS): ", 21);
    	validacion_Minuscula(lastName);
    	pedirFlotante(&salary,"INGRESE SALARIO: ","ERROR, REINGRESE SALARIO (10000-170000): ",10000, 170000);
    	pedirEntero(&sector, "INGRESE SECTOR: ","ERROR, REINGRESE SECTOR (1-1000): ",1, 1000);

    	listEmployees[i].id=id;
        strcpy(listEmployees[i].name,name);
        strcpy(listEmployees[i].lastName,lastName);
        listEmployees[i].salary=salary;
        listEmployees[i].sector=sector;

        listEmployees[i].isEmpty=0;

    }else
    {
        printf("NO HAY ESPACIO!!!");
    }


}

int SearchFree(aEmployee listEmployees[],int len)
{
    int i;
    int index;

    index=-1;

    for(i=0;i<len;i++)
    {
        if(listEmployees[i].isEmpty==1)
        {
            index=i;
            break;

        }


    }

    return index;


}

int removeEmployee(aEmployee listEmployees[],int len, int id)
{
	int retorno=-1;
    int position;


    position=findEmployeeById(listEmployees,len,id);

    if(position>=0)
    {
        listEmployees[position].isEmpty=1;
        PrintOneEmployee(listEmployees[position]);
        printf("\nEMPLEADO ELIMINADO EXITOSAMENTE\n");
        retorno=1;

    }else
    {
        printf("\nNO SE ENCONTRO EL EMPLEADO A ELIMINAR\n");
    }

    return retorno;
}

void ModifyEmployee(aEmployee listEmployees[],int len)
{
    int id;
    int answer;
    char newName[51];
    int newSector;
    float newSalary;
    char newLastName[51];
    char confirm;
    int position;
    aEmployee idEmployee;


    printEmployees(listEmployees,len);

    pedirEntero(&idEmployee.id, "INGRESE ID: ","ERROR, REINGRESE ID (0-1000): ",0, 1000);
    id=idEmployee.id;

    position=findEmployeeById(listEmployees,len,id);

        if(position>=0)
        {
        	pedirEntero(&answer,"\n¿QUE DESEA MODIFICAR?\n1.NOMBRE\n2.APELLIDO\n3.SALARIO\n4.SECTOR\n\nELIJA UNA OPCION(1-4):",
        				"ERROR, ¿QUE DESEA MODIFICAR?\n1.NOMBRE\n2.APELLIDO\n3.SALARIO\n4.SECTOR\n\nELIJA UNA OPCION(1-4):",1, 4);


            switch(answer)
            {
            case 1:

            	pedirCadena(newName, "INGRESE NUEVO NOMBRE: ","ERROR, REINGRESE NOMBRE (MAX 21 CARACTERES): ", 21);
            	validacion_Minuscula(newName);
            	pedirCadena(&confirm, "\n¿ESTAS SEGURO DE MODIFICAR EL NOMBRE?:\n","ERROR, REINGRESE LA OPCION (s / n): ", 1);


                if(confirm=='s')
                {
                    strcpy(listEmployees[position].name,newName);
                    printf("\nEMPLEADO MODIFICADO\n");

                }
                else
                {
                    printf("\nMODIFICACION CANCELADA\n");
                }
                break;

            case 2:
            	pedirCadena(newLastName, "INGRESE NUEVO APELLIDO: ","ERROR, REINGRESE APELLIDO (MAX 21 CARACTERES): ", 21);
            	validacion_Minuscula(newLastName);
            	pedirCadena(&confirm, "\n¿ESTAS SEGURO DE MODIFICAR EL APELLIDO?:\n","ERROR, REINGRESE LA OPCION (s / n): ", 1);


                if(confirm=='s')
                {
                    strcpy(listEmployees[position].lastName,newLastName);
                    printf("\nEMPLEADO MODIFICADO\n");

                }
                else
                {
                    printf("\nMODIFICACION CANCELADA\n");
                }
                break;

            case 3:
            	pedirFlotante(&newSalary, "INGRESE NEVO SALARIO: ","ERROR, REINGRESE SALARIO (10000-170000): ",100000, 170000);
            	pedirCadena(&confirm, "\n¿ESTAS SEGURO DE MODIFICAR EL SALARIO?:\n","ERROR, REINGRESE LA OPCION (s / n): ", 1);

                if(confirm=='s')
                {
                    listEmployees[position].salary=newSalary;
                    printf("\nEMPLEADO MODIFICADO\n");

                }
                else
                {
                    printf("\nMODIFICACION CANCELADA\n");
                }
                break;

            case 4:
            	pedirEntero(&newSector, "INGRESE NEVO SECTOR: ","ERROR, REINGRESE SECTOR (1-1000): ",1, 1000);
            	pedirCadena(&confirm, "\n¿ESTAS SEGURO DE MODIFICAR EL SECTOR?:\n","ERROR, REINGRESE LA OPCION (s / n): ", 1);

				if(confirm=='s')
				{
					listEmployees[position].sector=newSector;
					printf("\nEMPLEADO MODIFICADO\n");

				}else
				{
					printf("\nMODIFICACION CANCELADA\n");
				}
            break;
        }



        }



}

void PrintOneEmployee(aEmployee listEmployees)
{

    printf("\n\t-----------------------------------------------------------------------------------------\n");
    printf("\n%14s | %13s | %14.2f | %18d | %20d|\n", listEmployees.name, listEmployees.lastName,listEmployees.salary, listEmployees.sector, listEmployees.id);
    printf("\n\t-----------------------------------------------------------------------------------------\n");

}

void printEmployees(aEmployee listEmployees[],int len)
{
    int i;


    printf("\t__________________________________________________________________________________________\n");
    printf("\t|NOMBRE| \t|APELLIDO| \t|SALARIO| \t\t|SECTOR| \t\t|ID|\n");
    printf("\t------------------------------------------------------------------------------------------\n");


    for(i=0;i<len;i++)
    {
        if(listEmployees[i].isEmpty==0)
        {
           // listEmployees[i].id=i+1;
            PrintOneEmployee(listEmployees[i]);
        }
    }


}



void OptionFour(aEmployee listEmployees[],int len)
{

    float sum;
    float average;
    int CounterEmployeesHigherAverage;





    sum=SumSalaries(listEmployees,len);
    average=AverageSalaries(listEmployees,len);
    CounterEmployeesHigherAverage=AmountExceedAverageSalary(listEmployees,len);



    printf("\nEL SALARIO TOTAL ES: %.2f\n", sum);
    printf("\nEL PROMEDIO DE LOS SALARIOS ES: %.2f\n", average);
    printf("\nNUMERO DE EMPLEADOS QUE SUPERAN EL SALARIO PROMEDIO: %d\n", CounterEmployeesHigherAverage);



}

int findEmployeeById(aEmployee listEmployees[],int len, int id)
{
    int i;
    aEmployee oneEmployee;
    int found;

    found=-1;

    for(i=0;i<len;i++)
    {
        oneEmployee=listEmployees[i];

        if(oneEmployee.id==id && oneEmployee.isEmpty==0)
        {
            found=i;
            break;

        }

    }

    return found;


}

int sortEmployeeByName(aEmployee listEmployees[],int len, int order)
{
	int retorno=-1;
    int i;
    int bandera;
    aEmployee auxEmployee;


    switch(order)
    {
        case 1:
        	do
			{

				bandera = 0;

				for(i = 0; i < len - 1; i++)
				{
					if(strcmp(listEmployees[i].lastName, listEmployees[i+1].lastName) >0)
					{
						auxEmployee = listEmployees[i];
						listEmployees[i] = listEmployees[i+1];
						listEmployees[i+1] = auxEmployee;
						bandera = 1;
						retorno = 0;
					}else
					{
						if(strcmp(listEmployees[i].lastName, listEmployees[i+1].lastName) ==0 && listEmployees[i].sector > listEmployees[i+1].sector)
						{
							auxEmployee = listEmployees[i];
							listEmployees[i] = listEmployees[i+1];
							listEmployees[i+1] = auxEmployee;
							bandera = 1;
							retorno = 0;
						}
					}
				}
			}while(bandera);

        break;

        case 2:
        	do
			{
				bandera = 0;

				for(i = 0; i < len - 1 ; i++)
				{
					if(strcmp(listEmployees[i].lastName, listEmployees[i+1].lastName) <0)
					{
						auxEmployee = listEmployees[i];
						listEmployees[i] = listEmployees[i+1];
						listEmployees[i+1] = auxEmployee;
						bandera = 1;
						retorno = 0;
					}else
					{
						if(strcmp(listEmployees[i].lastName, listEmployees[i+1].lastName) ==0 && listEmployees[i].sector < listEmployees[i+1].sector)
						{
							auxEmployee = listEmployees[i];
							listEmployees[i] = listEmployees[i+1];
							listEmployees[i+1] = auxEmployee;
							bandera = 1;
							retorno = 0;
						}
					}
				}
			}while(bandera);

        break;


    }

    return retorno;

}

float SumSalaries(aEmployee listEmployees[],int len)
{
    int i;
    float salariesAccumulator;

    salariesAccumulator=0;

    for(i=0;i<len;i++)
    {
        if(listEmployees[i].isEmpty==0)
        {
            salariesAccumulator=salariesAccumulator+listEmployees[i].salary;
        }


    }

    return salariesAccumulator;

}

float AverageSalaries(aEmployee listEmployees[],int len)
{
    int i;
    float AverageSalaries;

    AverageSalaries=0;

    for(i=0;i<len;i++)
    {
        if(listEmployees[i].isEmpty==0)
        {
          AverageSalaries=SumSalaries(listEmployees,len)/AmountLoaded(listEmployees,len);
        }

    }


    return AverageSalaries;

}

int AmountLoaded(aEmployee listEmployees[],int len)
{
    int i;
    int chargedCounter;

    chargedCounter=0;

    for(i=0;i<len;i++)
    {
        if(listEmployees[i].isEmpty==0)
        {
          chargedCounter++;
        }

    }

    return chargedCounter;

}

int AmountExceedAverageSalary(aEmployee listEmployees[],int len)
{
    int i;
    float average;
    int counterEmployeesHigherAverage;

    counterEmployeesHigherAverage=0;

    average =AverageSalaries(listEmployees,len);
    for(i=0;i<len;i++)
    {
        if(listEmployees[i].isEmpty==0 && listEmployees[i].salary>average)
        {
            counterEmployeesHigherAverage++;
        }

    }

    return counterEmployeesHigherAverage;

}

int initEmployee(aEmployee listEmployees[],int len)
{
    int i;

    for(i=0;i<len;i++)
    {
        listEmployees[i].isEmpty=1;
    }

    return 0;

}


