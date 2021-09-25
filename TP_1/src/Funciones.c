/*
 * Funciones.c
 *
 *  Created on: 5 sep. 2021
 *      Author: PCNEW
 */


#include <stdio.h>
#include <stdlib.h>

/**
 * @fn    float sumarNumeros(float, float)
 * @brief Se realiza la operacion sumar entre dos numeros ingresados por el usuario
 *
 * @param float Indicamos la variable flotante del primer numero numeroUno
 * @param float Indicamos la variable flotante del segundo numero numeroDos
 * @return float Nos devuelve el resultado de la suma como un numero flotante
 */
float sumarNumeros(float numeroUno,float numeroDos) {

	float suma;


	suma= numeroUno + numeroDos;



	return suma;

}


/**
 * @fn float multiplicarNumeros(float, float)
 * @brief Se realiza la operacion multiplicacion entre dos numeros ingresados por el usuario
 *
 * @param float Indicamos la variable flotante del primer numero numeroUno
 * @param float Indicamos la variable flotante del segundo numero numeroDos
 * @return float Nos devuelve el resultado de la multiplicacion como un numero flotante
 */
float multiplicarNumeros(float numeroUno,float numeroDos) {

	float multiplicar;



	multiplicar= numeroUno * numeroDos;

	return multiplicar;

}



/**
 * @fn float restarNumeros(float, float)
 * @brief Se realiza la operacion resta entre dos numeros ingresados por el usuario
 *
 * @param float Indicamos la variable flotante del primer numero numeroUno
 * @param float Indicamos la variable flotante del segundo numero numeroDos
 * @return float Nos devuelve el resultado de la resta como un numero flotante
 */
float restarNumeros(float numeroUno,float numeroDos)
{
    float resta;

    resta= numeroUno - numeroDos;

    return resta;

}



/**
 * @fn float dividirNumeros(float, float)
 * @brief Se realiza la operacion division entre dos numeros ingresados por el usuario
 *
 * @param float Indicamos la variable flotante del primer numero numeroUno
 * @param float Indicamos la variable flotante del segundo numero numeroDos
 * @return float Nos devuelve el resultado de la division como un numero flotante
 */
float dividirNumeros(float numeroUno,float numeroDos)
{
    float dividir;

    dividir= numeroUno / numeroDos;

    return dividir;
}


/**
 * @fn long int factorizarNumero(int)
 * @brief Se realiza la operacion factorial entre dos numeros ingresados por el usuario
 *
 * @param int Indicamos la variable entera del numero numeroFactorial
 * @return long int Nos devuelve el resultado de la factorizacion como numero entero largo
 */
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
