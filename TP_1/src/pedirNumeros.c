/*
 * pedirNumeros.c
 *
 *  Created on: 3 sep. 2021
 *      Author: PCNEW
 */

#include <stdio.h>
#include <stdlib.h>
#include "pedirNumeros.h"


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
float pedirNumeroEntero(char* mensaje, char* mensajeError, int minimo, int maximo)
{
	float numeroIngresado;

	printf("%s", mensaje);
	fflush(stdin);
	scanf("%f", &numeroIngresado);

	while(numeroIngresado < minimo || numeroIngresado > maximo)
	{
		printf("%s", mensajeError);
		fflush(stdin);
		scanf("%f", &numeroIngresado);
	}

	return numeroIngresado;
}

