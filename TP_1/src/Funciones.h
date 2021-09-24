/*
 * Funciones.h
 *
 *  Created on: 5 sep. 2021
 *      Author: PCNEW
 */

#ifndef FUNCIONES_H_
#define FUNCIONES_H_
#include <stdio.h>
#include <stdlib.h>


#endif /* FUNCIONES_H_ */

/**
 * @fn    float sumarNumeros(float, float)
 * @brief Se realiza la operacion sumar entre dos numeros ingresados por el usuario
 *
 * @param float Indicamos la variable flotante del primer numero numeroUno
 * @param float Indicamos la variable flotante del segundo numero numeroDos
 * @return float Nos devuelve el resultado de la suma como un numero flotante
 */
float sumarNumeros(float numeroUno,float numeroDos);

/**
 * @fn float multiplicarNumeros(float, float)
 * @brief Se realiza la operacion multiplicacion entre dos numeros ingresados por el usuario
 *
 * @param float Indicamos la variable flotante del primer numero numeroUno
 * @param float Indicamos la variable flotante del segundo numero numeroDos
 * @return float Nos devuelve el resultado de la multiplicacion como un numero flotante
 */
float multiplicarNumeros(float numeroUno,float numeroDos);

/**
 * @fn float restarNumeros(float, float)
 * @brief Se realiza la operacion resta entre dos numeros ingresados por el usuario
 *
 * @param float Indicamos la variable flotante del primer numero numeroUno
 * @param float Indicamos la variable flotante del segundo numero numeroDos
 * @return float Nos devuelve el resultado de la resta como un numero flotante
 */
float restarNumeros(float numeroUno,float numeroDos);

/**
 * @fn float dividirNumeros(float, float)
 * @brief Se realiza la operacion division entre dos numeros ingresados por el usuario
 *
 * @param float Indicamos la variable flotante del primer numero numeroUno
 * @param float Indicamos la variable flotante del segundo numero numeroDos
 * @return float Nos devuelve el resultado de la division como un numero flotante
 */
float dividirNumeros(float numeroUno,float numeroDos);

/**
 * @fn long int factorizarNumero(int)
 * @brief Se realiza la operacion factorial entre dos numeros ingresados por el usuario
 *
 * @param int Indicamos la variable entera del numero numeroFactorial
 * @return long int Nos devuelve el resultado de la factorizacion como numero entero largo
 */
long int factorizarNumero(int numeroFactorial);
