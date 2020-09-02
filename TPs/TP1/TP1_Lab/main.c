#include <stdio.h>
#include <stdlib.h>


int SumarNumeros(int,int);
int RestarNumeros(int,int);
int MultiplicarNumeros(int,int);
float DividirNumeros(float,int);
int FactorizarNumero(int);

int main()
{
    int numeroUno;
    int numeroDos;
    int suma;
    int resta;
    int multiplicar;
    float dividir;
    char cuentaRealizar;
    int factorial;
    int opcion;
    char terminado;

    terminado=0;





    while(terminado==0)
    {
        printf("\n1.Mostrar opciones de calculos\n2.Salir\n");
        printf("Elija la opcion: ");
        scanf("%d", &opcion);




        switch(opcion)
        {

            case 1:

                printf("Ingrese la cuenta que quiere realizar:\n");
                printf("\ns(sumar)\nr(restar)\nm(multiplicar)\nd(dividir)\nf(factorizar)\n");
                printf("\nElija una opcion: ");
                fflush(stdin);
                scanf("%c", &cuentaRealizar);
                while(cuentaRealizar!='s' & cuentaRealizar!='r' & cuentaRealizar!='m' & cuentaRealizar!='d' & cuentaRealizar!='f')
                {
                    printf("Error, reingrese la cuenta que quiere realizar (s,r,m,d,f): ");
                    fflush(stdin);
                    scanf("%c", &cuentaRealizar);
                }

                printf("Ingrese el primer numero: ");
                scanf("%d", &numeroUno);

                printf("Ingrese el segundo numero: ");
                scanf("%d", &numeroDos);




                if(cuentaRealizar=='f')
                {
                    factorial= FactorizarNumero(numeroUno);
                    printf("El factorial de %d es %d\n , y el de %d es %d", numeroUno, factorial);
                }


                if(cuentaRealizar=='s')
                {
                    suma= SumarNumeros(numeroUno,numeroDos);
                    printf("La suma de los numeros es de: %d\n", suma);
                }

                if(cuentaRealizar=='r')
                {
                    resta= RestarNumeros(numeroUno,numeroDos);
                    printf("La resta de los numeros es de: %d\n", resta);
                }

                if(cuentaRealizar=='m')
                {
                    multiplicar= MultiplicarNumeros(numeroUno,numeroDos);
                    printf("La multiplicacion de los numeros es de: %d\n", multiplicar);
                }

                if(cuentaRealizar=='d')
                {
                    if(numeroDos==0)
                    {
                        printf("Error,No es posible dividir por 0, vuelva a ingresar un numero");
                        scanf("%.2f",dividir);


                    }else
                    {
                        dividir= DividirNumeros(numeroUno,numeroDos);
                        printf("La division de los numeros es de: %.2f\n", dividir);
                    }

                }
            break;

            case 2:
                    printf("Gracias por usar nuestra calculadora");
                    terminado=1;
            break;



        }
    }









    return 0;
}

int SumarNumeros(int primerNumeroSuma,int segundoNumeroSuma)
{
    int suma;

    suma= primerNumeroSuma + segundoNumeroSuma;

    return suma;

}

int RestarNumeros(int primerNumeroResta,int segundoNumeroResta)
{
    int resta;

    resta= primerNumeroResta - segundoNumeroResta;

    return resta;

}

int MultiplicarNumeros(int primerNumeroMultiplicar,int segundoNumeroMultiplicar)
{
    int multiplicar;

    multiplicar= primerNumeroMultiplicar * segundoNumeroMultiplicar;

    return multiplicar;

}

float DividirNumeros(float primerNumeroDividir,int segundoNumeroDividir)
{
    float dividir;

    dividir= primerNumeroDividir / segundoNumeroDividir;

    return dividir;
}

int FactorizarNumero(int numeroFactorial)
{
    int factorial;

    if(numeroFactorial==0)
    {
        return 1;
    }else
    {
       factorial=numeroFactorial*FactorizarNumero(numeroFactorial-1);
    }


    return factorial;

}


/*
#include <stdio.h>
#include <stdlib.h>

int SumarNumeros(int,int);
int RestarNumeros(int,int);
int MultiplicarNumeros(int,int);
float DividirNumeros(float,int);

int main()
{
    int numeroUno;
    int numeroDos;
    int suma;
    int resta;
    int multiplicar;
    float dividir;


    printf("Ingrese el primer numero: ");
    scanf("%d", &numeroUno);

    printf("Ingrese el segundo numero: ");
    scanf("%d", &numeroDos);

    suma= SumarNumeros(numeroUno,numeroDos);
    printf("La suma de los numeros es de: %d\n", suma);

    resta= RestarNumeros(numeroUno,numeroDos);
    printf("La resta de los numeros es de: %d\n", resta);

    multiplicar= MultiplicarNumeros(numeroUno,numeroDos);
    printf("La multiplicacion de los numeros es de: %d\n", multiplicar);

    dividir= DividirNumeros(numeroUno,numeroDos);
    printf("La division de los numeros es de: %.2f\n", dividir);


    return 0;
}

int SumarNumeros(int primerNumeroSuma,int segundoNumeroSuma)
{
    int suma;

    suma= primerNumeroSuma + segundoNumeroSuma;

    return suma;

}

int RestarNumeros(int primerNumeroResta,int segundoNumeroResta)
{
    int resta;

    resta= primerNumeroResta - segundoNumeroResta;

    return resta;

}

int MultiplicarNumeros(int primerNumeroMultiplicar,int segundoNumeroMultiplicar)
{
    int multiplicar;

    multiplicar= primerNumeroMultiplicar * segundoNumeroMultiplicar;

    return multiplicar;

}

float DividirNumeros(float primerNumeroDividir,int segundoNumeroDividir)
{
    float dividir;

    dividir= primerNumeroDividir / segundoNumeroDividir;

    return dividir;
}

*/
