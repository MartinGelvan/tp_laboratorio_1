/*
 ============================================================================
 Name        : TP_1.c
 Author      : Martin Gelvan
 Version     :
 Copyright   : Your copyright notice
 Description : Hello World in C, Ansi-style
 ============================================================================
 */

#include <stdio.h>
#include <stdlib.h>
#include "Menu.h"

int main(void) {
	setbuf(stdout,NULL);

	int opcion=0;

	do{



		menu(opcion);


	}while(opcion==4);

	return EXIT_SUCCESS;
}
