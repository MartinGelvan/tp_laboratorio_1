/*
 * pedirNumeros.h
 *
 *  Created on: 3 sep. 2021
 *      Author: PCNEW
 */

#ifndef PEDIRNUMEROS_H_
#define PEDIRNUMEROS_H_
#include <stdio.h>
#include <stdlib.h>


/**
 * @fn float pedirNumeroEntero(char*, char*, int, int)
 * @brief Se pide un numero flotante con el mensaje de ingresarlo, el error y el rango de que numero a que numero se puede ingresar
 *
 * @param char Indicamos la variable de tipo char del mensaje de ingresar numero
 * @param char Indicamos la variable de tipo char del mensaje de error
 * @param int Indicamos la variable de tipo int del rango minimo del numero a pedir
 * @param int Indicamos la variable de tipo int del rango maximo del numero a pedir
 * @return int Nos devuelve el numero flotante que ingresamos
 */
float pedirNumeroEntero(char* , char* , int , int );


#endif /* PEDIRNUMEROS_H_ */
