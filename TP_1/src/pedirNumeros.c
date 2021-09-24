/*
 * pedirNumeros.c
 *
 *  Created on: 3 sep. 2021
 *      Author: PCNEW
 */

#include <stdio.h>
#include <stdlib.h>
#include "pedirNumeros.h"


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

