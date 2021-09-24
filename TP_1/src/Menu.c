/*
 ============================================================================
 Name        : EjercicioMenu.c
 Author      : 
 Version     :
 Copyright   : Your copyright notice
 Description : Hello World in C, Ansi-style
 ============================================================================
 */

#include <stdio.h>
#include <stdlib.h>
void limpiarConsola(void);
void mostrarSeparador(void);
#include "pedirNumeros.h"
#include "Funciones.h"

void menu(int opcion) {

	setbuf(stdout,NULL);

	float numeroUno;
	float numeroDos;
	float suma;
	float resta;
	float multiplicacion;
	float dividir;
	float factorialA;
	float factorialB;
	int banderaNumeroUno=0;
	int banderaNumeroDos=0;
	int banderaCalculosRealizados=0;


	printf("Bienvenido!!!\n\n");




	do{

		if(banderaNumeroUno==0)
		{
			printf("1.Ingresar 1er operando A=X\n");

		}
		else
		{
			printf("1.Ingresar 1er operando A=%.2f\n", numeroUno);
		}

		if(banderaNumeroDos==0)
		{
			printf("2.Ingresar 2do operando B=Y\n");

		}
		else
		{
			printf("\n|2.Ingresar 2do operando B=%.2f\n",numeroDos);
		}


		opcion=pedirNumeroEntero("3.Calcular\n4.Informar\n5.Salir\nElija una opcion:","Error,reingrese la opcion: ",1,5);
		fflush(stdin);
		mostrarSeparador();


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
			 if((banderaNumeroUno==0 && banderaNumeroDos==0) || (banderaNumeroUno==0 && banderaNumeroDos==1) || (banderaNumeroUno==1 && banderaNumeroDos==0))
			 {
				printf("\nIngrese ambos valores para poder realizar los calculos\n");

			 }
			 else
			 {


				suma= sumarNumeros(numeroUno,numeroDos);

				resta= restarNumeros(numeroUno,numeroDos);

				multiplicacion= multiplicarNumeros(numeroUno,numeroDos);

				if(numeroDos!=0)
				{
					dividir= dividirNumeros(numeroUno,numeroDos);
				}

				 if(numeroUno>=0 && numeroUno==(int)numeroUno)
				{
					factorialA= factorizarNumero(numeroUno);
				}

				if(numeroDos>=0 && numeroDos==(int)numeroDos)
				{
					factorialB= factorizarNumero(numeroDos);
				}

				printf("\nSe realizaron los calculos con exito, vaya a la opcion 4 para mostrar resultados\n");
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
				mostrarSeparador();
				printf("\nEl resultado de %.2f-%.2f es: %.2f\n",numeroUno, numeroDos, resta);
				mostrarSeparador();
				printf("\nEl resultado de %.2f*%.2f es: %.2f\n",numeroUno, numeroDos, multiplicacion);
				mostrarSeparador();
				if(numeroDos!=0)
				{
					printf("\nEl resultado de %.2f/%.2f es: %.2f\n",numeroUno, numeroDos, dividir);
				}
				else
				{
					printf("\nError, no se puede dividir por 0.\n");

				}
				mostrarSeparador();
				if(numeroUno>=0 && numeroUno==(int)numeroUno)
				{
					printf("\nEl factorial de %.2f es: %.2f", numeroUno, factorialA);

				}else
				{
					printf("\nError, no se puede realizar el factorial de un numero negativo y de un numero decimal.\n");

				}
				if(numeroDos>=0 && numeroDos==(int)numeroDos)
				{
					printf("\nEl factorial de %.2f es: %.2f\n", numeroDos,factorialB);

				}else
				{
					printf("\nError, no se puede realizar el factorial de un numero negativo y de un decimal.\n");

				}

				mostrarSeparador();
				system("pause");
				banderaCalculosRealizados=0;

			}

			break;
		case 5:
			printf("Eligio salir\n");
			break;
		default:
			printf("Eligio cualquier cosa\n");
			break;



		}

		if(opcion!=5)
		{
			system("pause");
			limpiarConsola();

		}


	}while(opcion!=5);

}

void limpiarConsola(void)
{
	printf("\n\n\n\n");
}

void mostrarSeparador(void)
{
	printf("---------------------------------------------\n");

}

