/*
 * Funciones.c
 *
 *  Created on: 5 sep. 2021
 *      Author: PCNEW
 */


#include <stdio.h>
#include <stdlib.h>


float sumarNumeros(float numeroUno,float numeroDos) {

	float suma;


	suma= numeroUno + numeroDos;



	return suma;

}



float multiplicarNumeros(float numeroUno,float numeroDos) {

	float multiplicar;



	multiplicar= numeroUno * numeroDos;

	return multiplicar;

}




float restarNumeros(float numeroUno,float numeroDos)
{
    float resta;

    resta= numeroUno - numeroDos;

    return resta;

}




float dividirNumeros(float numeroUno,float numeroDos)
{
    float dividir;

    dividir= numeroUno / numeroDos;

    return dividir;
}



long int factorizarNumero(int numeroFactorial)
{
    int factorial;

    if(numeroFactorial==0)
    {
        return 1;
    }else
    {
       factorial=numeroFactorial*factorizarNumero(numeroFactorial-1);
    }


    return factorial;

}
