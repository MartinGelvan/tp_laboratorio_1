
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
                printf("Ingrese ambos valores para poder realizar los calculos");

            }
            else
            {
                if(numeroUno>=1 && numeroUno == (int) numeroUno)
                {
                   factorialA= FactorizarNumero(numeroUno);
                }
                if(numeroDos>=1 && numeroDos==(int) numeroDos)
                {
                   factorialB= FactorizarNumero(numeroDos);
                }

                suma= SumarNumeros(numeroUno,numeroDos);
                resta= RestarNumeros(numeroUno,numeroDos);
                multiplicar= MultiplicarNumeros(numeroUno,numeroDos);
                dividir= DividirNumeros(numeroUno,numeroDos);
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

                if(numeroDos==0)
                {
                    printf("\nError, no se puede dividir por 0.\n");
                }else
                {
                   printf("\nEl resultado de %.2f/%.2f es: %.2f",numeroUno, numeroDos, dividir);
                }

                if(numeroUno== (int) numeroUno && numeroUno>=0)
                {
                    printf("\nEl resultado del factorial A es:%d\n",factorialA);
                }else
                {
                    printf("\nError, no se puede hacer el factorial de A.\n");
                }

                if(numeroDos==(int)numeroDos && numeroDos>=0)
                {
                    printf("\nEl resultado del factorial B es:%d\n",factorialB);
                }else
                {
                    printf("\nError, no se puede hacer el factorial de B.\n");
                }


               // printf("\nEl factorial de %.2f es: %d y El factorial de %.2f es: %d", numeroUno, factorialA, numeroDos,factorialB);

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

