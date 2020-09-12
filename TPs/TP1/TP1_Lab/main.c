
#include <stdlib.h>
#include "funciones.h"


int main()
{
    float numeroUno;
    float numeroDos;
    float suma;
    float resta;
    float multiplicar;
    float dividir;
    int factorialA;
    int factorialB;
    int opcion;
    char terminado;
    int banderaNumeroUno;
    int banderaNumeroDos;
    int banderaCalculosRealizados;

    banderaCalculosRealizados=0;

    banderaNumeroUno=0;

    banderaNumeroDos=0;


    terminado=0;





    while(terminado==0)
    {
        if(banderaNumeroUno==0)
        {
            printf("\n|1.Ingresar 1er operando A=X|\n");

        }
        else
        {
            printf("\n|1.Ingresar 1er operando A=%.2f\n", numeroUno);
        }

        if(banderaNumeroDos==0)
        {
            printf("\n|2.Ingresar 2do operando B=Y|\n");

        }
        else
        {
            printf("\n|2.Ingresar 2do operando B=%.2f|\n",numeroDos);
        }


        printf("\n|3.Calcular todas las operaciones|\n");
        printf("\n|4.Informar resultados|\n");
        printf("\n|5.Salir|\n");
        printf("\nElija la opcion: ");
        scanf("%d", &opcion);




        while(opcion!=1 && opcion!=2 && opcion!=3 && opcion!=4 && opcion!=5)
        {
            printf("Error, esa opcion no se encuentra disponible, reingrese la opcion que desee.\n");
            printf("\n|1.Ingresar primer numero|\n|2.Ingresar segundo numero|\n|3.Calcular|\n|4.Mostrar operacion|\n|5.Salir|\n");
            printf("Elija la opcion: ");
            scanf("%d", &opcion);

        }



        switch(opcion)
        {

        case 1:
            printf("Ingrese el primer numero: ");
            scanf("%f", &numeroUno);
            banderaNumeroUno=1;

            break;

        case 2:
            printf("Ingrese el segundo numero: ");
            scanf("%f", &numeroDos);
            banderaNumeroDos=1;


            break;

        case 3:

            if(banderaNumeroUno==0 && banderaNumeroDos==0)
            {
                printf("\nIngrese ambos valores para poder realizar los calculos\n");

            }
            else
            {


                suma= SumarNumeros(numeroUno,numeroDos);
                resta= RestarNumeros(numeroUno,numeroDos);
                multiplicar= MultiplicarNumeros(numeroUno,numeroDos);
                if(numeroDos!=0)
                {
                    dividir= DividirNumeros(numeroUno,numeroDos);
                }

                 if(numeroUno>=0)
                {
                    factorialA= FactorizarNumero(numeroUno);
                }

                if(numeroDos>=0)
                {
                    factorialB= FactorizarNumero(numeroDos);
                }

                printf("\nSe realizaron los calculos con exito, vaya a la opcion 4 para mostrar resultados\n");
                banderaCalculosRealizados=1;


            }


            break;

        case 4:

            if(banderaCalculosRealizados==0)
            {
                printf("\nPor favor ejecute primero la opcion 3\n");

            }
            else
            {

                printf("\nEl resultado de %.2f+%.2f es: %.2f\n",numeroUno, numeroDos, suma);
                printf("\nEl resultado de %.2f-%.2f es: %.2f\n",numeroUno, numeroDos, resta);
                printf("\nEl resultado de %.2f*%.2f es: %.2f\n",numeroUno, numeroDos, multiplicar);
                if(numeroDos!=0)
                {
                    printf("\nEl resultado de %.2f/%.2f es: %.2f\n",numeroUno, numeroDos, dividir);
                }
                else
                {
                    printf("\nError, no se puede dividir por 0.\n");

                }

                if(numeroUno>=0)
                {
                    printf("\nEl factorial de %.2f es: %d", numeroUno, factorialA);

                }else
                {
                    printf("\nError, no se puede realizar el factorial de un numero negativo.\n");

                }

                if(numeroDos>=0)
                {
                    printf("\nEl factorial de %.2f es: %d\n", numeroDos,factorialB);

                }else
                {
                    printf("\nError, no se puede realizar el factorial de un numero negativo.\n");

                }


                banderaCalculosRealizados=0;

            }


            break;

        case 5:
            printf("\nGracias por usar nuestra calculadora\n");
            terminado=1;
            break;

        }
    }



    return 0;

}
