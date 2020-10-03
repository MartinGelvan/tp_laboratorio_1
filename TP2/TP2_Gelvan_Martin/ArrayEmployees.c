#include <stdio.h>
#include <stdlib.h>
#include<string.h>
#define TAM 1000
#include "ArrayEmployees.h"

void Menu()
{
    printf("\n1.ALTAS\n2.MODIFICAR\n3.BAJA\n4.INFORMAR\n5.SALIR\n");

}

void addEmployee(aEmployee listEmployees[],int len)
{
    aEmployee oneEmpleado;
    int i;

    i=SearchFree(listEmployees,len);


    if(i!=-1)
    {
        printf("\nINGRESE NOMBRE: ");
        fflush(stdin);
        scanf("%[^\n]", oneEmpleado.name);
        printf("\nINGRESE APELLIDO: ");
        fflush(stdin);
        scanf("%[^\n]", oneEmpleado.lastName);
        printf("\nINGRESE SALARIO: ");
        scanf("%f", &oneEmpleado.salary);

        while(oneEmpleado.salary<0)
        {
            printf("\nERROR,INGRESE UN SALARIO POSITIVO\n");
            printf("\nENTER SALARY: ");
            scanf("%f", &oneEmpleado.salary);
        }

        printf("\nINGRESE SECTOR: ");
        scanf("%d", &oneEmpleado.sector);

        while(oneEmpleado.sector<0)
        {
            printf("\nERROR,INGRESE UN SECTOR POSITIVO\n");
            printf("\nINGRESE SECTOR: ");
            scanf("%d", &oneEmpleado.sector);
        }


        listEmployees[i]=oneEmpleado;

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

void removeEmployee(aEmployee listEmployees[],int len)
{
    int position;
    int id;

    printEmployees(listEmployees,len);

    printf("\nINGRESE EL ID DEL EMPLEADO A ELIMINAR: ");
    scanf("%d",&id);

    position=findEmployeeById(listEmployees,len,id);

    if(position>=0)
    {
        listEmployees[position].isEmpty=1;
        printf("\nEMPLEADO ELIMINADO EXITOSAMENTE\n");

    }else
    {
        printf("\nNO SE ENCONTRO EL EMPLEADO A ELIMINAR\n");
    }

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

    printEmployees(listEmployees,len);

    printf("\nINGRESE EL ID DEL EMPLEADO A MODIFICAR: ");
    scanf("%d",&id);

    position=findEmployeeById(listEmployees,len,id);

        if(position>=0)
        {
            printf("\n¿QUE DESEA MODIFICAR?\n1.NOMBRE\n2.APELLIDO\n3.SALARIO\n4.SECTOR\n");
            printf("\nELIJA UNA OPCION: ");
            scanf("%d",&answer);

            switch(answer)
            {
            case 1:
                printf("INGRESE NUEVO NOMBRE:");
                fflush(stdin);
                scanf("%[^\n]", newName);
                printf("\n¿ESTAS SEGURO DE MODIFICAR EL NOMBRE?\n");
                printf("\nELIJA UNA OPCION (s / n): ");
                fflush(stdin);
                scanf("%c", &confirm);
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
                printf("INGRESE NUEVO APELLIDO:");
                fflush(stdin);
                scanf("%[^\n]", newLastName);
                printf("\n¿ESTAS SEGURO DE MODIFICAR EL APELLIDO?\n");
                printf("\nELIJA UNA OPCION (s / n): ");
                fflush(stdin);
                scanf("%c", &confirm);
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
                printf("INGRESE NUEVO SALARIO:");
                fflush(stdin);
                scanf("%f", &newSalary);
                printf("\n¿ESTAS SEGURO DE CAMBIAR EL SALARIO?\n");
                printf("\nELIJA UNA OPCION (s / n): ");
                fflush(stdin);
                scanf("%c", &confirm);
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
                printf("INGRESE NUEVO SECTOR:");
                    scanf("%d", &newSector);
                    printf("\n¿ESTAS SEGURO DE CAMBIAR EL SECTOR?\n");
                    printf("\nELIJA UNA OPCION (s / n): ");
                    fflush(stdin);
                    scanf("%c", &confirm);
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
            listEmployees[i].id=i+1;
            PrintOneEmployee(listEmployees[i]);
        }
    }


}



void OptionFour(aEmployee listEmployees[],int len)
{
    int i;
    float sum;
    float average;
    int CounterEmployeesHigherAverage;

    OrderEmployees(listEmployees,len);



    printf("\t__________________________________________________________________________________________\n");
    printf("\t|NOMBRE| \t|APELLIDO| \t|SALARIO| \t\t|SECTOR| \t\t|ID|\n");
    printf("\t------------------------------------------------------------------------------------------\n");


    for(i=0;i<len;i++)
    {


        if(listEmployees[i].isEmpty==0)
        {
            listEmployees[i].id=i+1;
            PrintOneEmployee(listEmployees[i]);
        }

    }

    sum=SumSalaries(listEmployees,len);
    average=AverageSalaries(listEmployees,len);
    CounterEmployeesHigherAverage=AmountExceedAverageSalary(listEmployees,len);



    printf("\nEL SALARIO TOTAL ES: %.2f\n", sum);
    printf("\nEL PROMEDIO DE LOS SALARIOS ES: %.2f\n", average);
    printf("\nNUMERO DE EMPLEADOS QUE SUPERAN EL SALARIO PROMEDIO: %d\n", CounterEmployeesHigherAverage);
    sortEmployeeByName(listEmployees,len);


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
void OrderEmployees(aEmployee listEmployees[],int len)
{
    int i;
    int j;
    aEmployee auxEmployee;

     for(i=0;i<len-1;i++)
    {
        for(j=i+1;j<len;j++)
        {
           if(strcmp(listEmployees[i].lastName,listEmployees[j].lastName)>0)
           {
               auxEmployee=listEmployees[i];
               listEmployees[i]=listEmployees[j];
               listEmployees[j]=auxEmployee;


           }else
           {
               if(strcmp(listEmployees[i].lastName,listEmployees[j].lastName)==0 && listEmployees[i].sector<listEmployees[j].sector)
               {
                   auxEmployee=listEmployees[i];
                   listEmployees[i]=listEmployees[j];
                   listEmployees[j]=auxEmployee;


               }


           }


        }



    }



}

void sortEmployeeByName(aEmployee listEmployees[],int len)
{
    int i;
    int opcion;

     printf("\n____________________________\n");
    printf("\nELIJA COMO QUIERE ORDENAR EL EMPLEADO\n");
    printf("\n---------------------------------\n");
    printf("\n\n1.ASCENDENTE A-->Z\n\n2.DESCENDENTE Z--->A\n");
    printf("\nELIJA UNA OPCION: ");
    scanf("%d",&opcion);

        printf("\t__________________________________________________________________________________________\n");
        printf("\t|NOMBRE| \t\t|APELLIDO| \t|SALARIO| \t\t|SECTOR| \t\t|ID|\n");
        printf("\t------------------------------------------------------------------------------------------\n");

    switch(opcion)
    {
        case 1:
                for(i=0;i<len;i++)
                {
                    if(listEmployees[i].isEmpty==0)
                    {
                        PrintOneEmployee(listEmployees[i]);
                    }

                }

        break;

        case 2:
                for(i=len-1;i>0;i--)
                {
                    if(listEmployees[i].isEmpty==0)
                    {
                        PrintOneEmployee(listEmployees[i]);
                    }

                }

        break;


    }



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
