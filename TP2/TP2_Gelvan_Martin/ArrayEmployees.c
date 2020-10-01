#include <stdio.h>
#include <stdlib.h>
#include<string.h>
#define TAM 1000
#include "ArrayEmployees.h"


void addEmployee(aEmployee listEmployees[],int len)
{
    aEmployee oneEmpleado;
    int i;

    i=SearchFree(listEmployees,len);


    if(i!=-1)
    {
        printf("\nENTER NAME: ");
        fflush(stdin);
        scanf("%[^\n]", oneEmpleado.name);
        printf("\nENTER LAST NAME: ");
        fflush(stdin);
        scanf("%[^\n]", oneEmpleado.lastName);
        printf("\nENTER SALARY: ");
        scanf("%f", &oneEmpleado.salary);

        while(oneEmpleado.salary<0)
        {
            printf("\nERROR, ENTER A POSITIVE SALARY\n");
            printf("\nENTER SALARY: ");
            scanf("%f", &oneEmpleado.salary);
        }

        printf("\nENTER SECTOR: ");
        scanf("%d", &oneEmpleado.sector);

        while(oneEmpleado.sector<0)
        {
            printf("\nERROR, ENTER A POSITIVE SECTOR\n");
            printf("\nENTER SECTOR: ");
            scanf("%d", &oneEmpleado.sector);
        }


        listEmployees[i]=oneEmpleado;

        listEmployees[i].isEmpty=0;

    }else
    {
        printf("No hay espacio!!!");
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

    printf("\nENTER THE ID OF THE EMPLOYEE TO REMOVE: ");
    scanf("%d",&id);

    position=findEmployeeById(listEmployees,len,id);

    if(position>=0)
    {
        listEmployees[position].isEmpty=1;
        printf("\nEMPLOYEE REMOVED SUCCESSFULLY\n");

    }else
    {
        printf("\nNOT FOUND THE EMPLOYEE TO DELETE\n");
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

    printf("\nENTER THE ID OF THE EMPLOYEE TO MODIFY: ");
    scanf("%d",&id);

    position=findEmployeeById(listEmployees,len,id);

        if(position>=0)
        {
            printf("\n¿WHAT WOULD YOU LIKE TO MODIFY?\n1.NAME\n2.LAST NAME\n3.SALARY\n4.SECTOR\n");
            printf("\nCHOOSE AN OPTION: ");
            scanf("%d",&answer);

            switch(answer)
            {
            case 1:
                printf("ENTER NEW NAME:");
                fflush(stdin);
                scanf("%[^\n]", newName);
                printf("\n¿YOU ARE SURE TO CHANGE THE NAME?\n");
                printf("\nCHOOSE AN OPTION (y / n): ");
                fflush(stdin);
                scanf("%c", &confirm);
                if(confirm=='y')
                {
                    strcpy(listEmployees[position].name,newName);
                    printf("\nMODIFIED EMPLOYEE\n");

                }
                else
                {
                    printf("\nCANCELED MODIFICATION\n");
                }
                break;

            case 2:
                printf("ENTER NEW LAST NAME:");
                fflush(stdin);
                scanf("%[^\n]", newLastName);
                printf("\n¿YOU ARE SURE TO CHANGE THE LAST NAME?\n");
                printf("\nCHOOSE AN OPTION (y / n): ");
                fflush(stdin);
                scanf("%c", &confirm);
                if(confirm=='y')
                {
                    strcpy(listEmployees[position].lastName,newLastName);
                    printf("\nMODIFIED EMPLOYEE\n");

                }
                else
                {
                    printf("\nCANCELED MODIFICATION\n");
                }
                break;

            case 3:
                printf("ENTER NEW SALARY:");
                fflush(stdin);
                scanf("%f", &newSalary);
                printf("\n¿YOU ARE SURE TO CHANGE THE SALARY?\n");
                printf("\nCHOOSE AN OPTION (y / n): ");
                fflush(stdin);
                scanf("%c", &confirm);
                if(confirm=='y')
                {
                    listEmployees[position].salary=newSalary;
                    printf("\nMODIFIED EMPLOYEE\n");

                }
                else
                {
                    printf("\nCANCELED MODIFICATION\n");
                }
                break;

            case 4:
                printf("ENTER NEW SECTOR:");
                    scanf("%d", &newSector);
                    printf("\n¿YOU ARE SURE TO CHANGE THE SECTOR?\n");
                    printf("\nCHOOSE AN OPTION (y / n): ");
                    fflush(stdin);
                    scanf("%c", &confirm);
                    if(confirm=='y')
                    {
                        listEmployees[position].sector=newSector;
                        printf("\nMODIFIED EMPLOYEE\n");

                    }else
                    {
                        printf("\nCANCELED MODIFICATION\n");
                    }
            break;
        }



        }



}


void printEmployees(aEmployee listEmployees[],int len)
{
    int i;
    float sum;
    float average;
    int CounterEmployeesHigherAverage;


    sortEmployeeByName(listEmployees,len);

    printf("\t__________________________________________________________________________________________\n");
    printf("\t|Name| \t\t|Last Name| \t|Salary| \t\t|Sector| \t\t|ID|\n");
    printf("\t------------------------------------------------------------------------------------------\n");
    for(i=0;i<len;i++)
    {


        if(listEmployees[i].isEmpty==0)
        {
            listEmployees[i].id=i+1;
            printf("\n\t-----------------------------------------------------------------------------------------\n");
            printf("\n%14s | %13s | %14.2f | %18d | %20d|\n", listEmployees[i].name, listEmployees[i].lastName,listEmployees[i].salary, listEmployees[i].sector, listEmployees[i].id);
            printf("\n\t-----------------------------------------------------------------------------------------\n");
        }

    }

    sum=SumSalaries(listEmployees,len);
    average=AverageSalaries(listEmployees,len);
    CounterEmployeesHigherAverage=AmountExceedAverageSalary(listEmployees,len);



    printf("\nTHE TOTAL SALARY IS: %.2f\n", sum);
    printf("\nTHE AVERAGE SALARY IS: %.2f\n", average);
    printf("\nTHE NUMBER OF EMPLOYEES WHO HAVE SALARIES EXCEED THE AVERAGE IS: %d\n", CounterEmployeesHigherAverage);


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

void sortEmployeeByName(aEmployee listEmployees[],int len)
{
    int i;
    int j;
    aEmployee auxEmployee;

    for(i=0;i<len-1;i++)
    {
        for(j=i+1;j<len;j++)
        {
           if(strcmp(listEmployees[i].lastName,listEmployees[j].lastName)<0 && listEmployees[i].sector<listEmployees[j].sector)
           {
               auxEmployee=listEmployees[i];
               listEmployees[i]=listEmployees[j];
               listEmployees[j]=auxEmployee;


           }


        }



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
