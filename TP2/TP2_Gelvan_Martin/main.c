#include <stdio.h>
#include <stdlib.h>
#include<string.h>
#define TAM 1000
#include "ArrayEmployees.h"

int main()
{
    int option;
    aEmployee listEmployees[TAM];
    int i;
    int AlreadyEnterEmployee=0;


    i=initEmployee(listEmployees,TAM);


    do
    {

        printf("\n1.HIGH\n2.MODIFICATE\n3.LOW\n4.PRINT\n5.EXIT\n");
        printf("\nCHOOSE AN OPTION: ");
        scanf("%d", &option);

        while(option!=1 && option!=2 && option!=3 && option!=4 && option!=5)
        {
            printf("\nERROR,THES OPTION DOES NOT EXIST\n");
            printf("RE-ENTER THE OPTION: ");
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
                        printf("\nSUCCESSFUL UPLOAD!\n");
                    }else
                    {
                        printf("\nTHERE IS NO MORE SPACE!!\n");
                    }
                break;
            case 2:

                if(AlreadyEnterEmployee==0)
                {
                    printf("\nFIRST ENTER AN EMPLOYEE\n");
                }else
                {
                    ModifyEmployee(listEmployees,TAM);
                }

                break;
            case 3:

                 if(AlreadyEnterEmployee==0)
                {
                    printf("\nFIRST ENTER AN EMPLOYEE\n");
                }else
                {
                  removeEmployee(listEmployees,TAM);
                }

                break;
            case 4:

                if(AlreadyEnterEmployee==0)
                {
                    printf("\nFIRST ENTER AN EMPLOYEE\n");
                }else
                {
                  printEmployees(listEmployees,TAM);
                }

                break;
            case 5:
                printf("FINISHED");
                break;


        }


    }while(option!=5);

    return 0;
}


