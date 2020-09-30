#include "funciones.h"



float SumarNumeros(float primerNumeroSuma,float segundoNumeroSuma)
{
    float suma;

    suma= primerNumeroSuma + segundoNumeroSuma;

    return suma;

}

float RestarNumeros(float primerNumeroResta,float segundoNumeroResta)
{
    float resta;

    resta= primerNumeroResta - segundoNumeroResta;

    return resta;

}

float MultiplicarNumeros(float primerNumeroMultiplicar,float segundoNumeroMultiplicar)
{
    float multiplicar;

    multiplicar= primerNumeroMultiplicar * segundoNumeroMultiplicar;

    return multiplicar;

}

float DividirNumeros(float primerNumeroDividir,float segundoNumeroDividir)
{
    float dividir;

    dividir= primerNumeroDividir / segundoNumeroDividir;

    return dividir;
}

long int FactorizarNumero(int numeroFactorial)
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

