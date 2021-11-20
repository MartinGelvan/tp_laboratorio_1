#include <stdio.h>
#include <stdlib.h>
#include "LinkedList.h"
#include "Employee.h"
#include "Inputs.h"
#include "parser.h"
#include "Controller.h"


/** \brief Carga los datos de los empleados desde el archivo data.csv (modo texto).
 *
 * \param path char*
 * \param pArrayListEmployee LinkedList*
 * \return int
 *
 */
int controller_loadFromText(char* path , LinkedList* pArrayListEmployee)
{
	FILE* pFile;
	int exito=0;

	if(path!=NULL && pArrayListEmployee!=NULL)
	{
		pFile=fopen(path,"r");

		if(pFile!=NULL)
		{
			parser_EmployeeFromText(pFile ,pArrayListEmployee);;
			exito=1;
		}
		fclose(pFile);
	}

	return exito;
    //return 1;
}

/** \brief Carga los datos de los empleados desde el archivo data.csv (modo binario).
 *
 * \param path char*
 * \param pArrayListEmployee LinkedList*
 * \return int
 *
 */
int controller_loadFromBinary(char* path , LinkedList* pArrayListEmployee)
{
	FILE* pFile;
	int exito=0;

	if(path!=NULL && pArrayListEmployee!=NULL)
	{
		pFile=fopen(path,"rb");

		if(pFile!=NULL)
		{
			parser_EmployeeFromBinary(pFile ,pArrayListEmployee);
			exito=1;
		}
		fclose(pFile);
	}

	return exito;
   // return 1;
}

/** \brief Alta de empleados
 *
 * \param path char*
 * \param pArrayListEmployee LinkedList*
 * \return int
 *
 */
int controller_addEmployee(LinkedList* pArrayListEmployee)
{
	Employee* pEmployee=employee_new();
	int id;
	//char auxId[40];
	char auxNombre[40];
	int auxHoras;
	int auxSueldo;
	//char auxHoras[40];
	//char auxSueldo[40];
	int exito=0;

	if(pArrayListEmployee!=NULL)
	{

		id=(employee_ultimoId(pArrayListEmployee)+1);
		pedirCadena(auxNombre,"Ingrese su nombre (40 caracteres maximo): ", "Error, reingrese su nombre (40 caracteres maximo)", 40);
		pedirEntero(&auxHoras,"Ingrese las horas (1h minimo 40hs maximo):", "Error, reingrese las horas (40 caracteres maximo)",1,40);
		pedirEntero(&auxSueldo,"Ingrese el sueldo ($1000 minimo , $40000 maximo):", "Error, reingrese su sueldo ($1000 minimo , $40000 maximo):", 1000,40000);
		//pedirCadena(auxHoras,"Ingrese las horas (1h minimo 40hs maximo):", "Error, reingrese su nombre (40 caracteres maximo)", 40);
		//pedirCadena(auxSueldo,"Ingrese el sueldo ($1000 minimo , $40000 maximo):", "Error, reingrese su sueldo ($1000 minimo , $40000 maximo):", 40000);
		//pEmployee=employee_newParametros(auxId, auxNombre, auxHoras, auxSueldo);
		employee_setId(pEmployee, id);
		employee_setNombre(pEmployee, auxNombre);
		employee_setHorasTrabajadas(pEmployee, auxHoras);
		employee_setSueldo(pEmployee, auxSueldo);
		ll_add(pArrayListEmployee, pEmployee);
		exito=1;

	}

    return exito;
}

/** \brief Modificar datos de empleado
 *
 * \param path char*
 * \param pArrayListEmployee LinkedList*
 * \return int
 *
 */
int controller_editEmployee(LinkedList* pArrayListEmployee)
{
	int opcion;
	int index;
	int auxId;
	char auxNombre[40];
	int auxHoras;
	int auxSueldo;
	Employee* auxEmployee;
	int exito=0;

	if(pArrayListEmployee!=NULL)
	{
		controller_ListEmployee(pArrayListEmployee);

		pedirEntero(&auxId, "Ingrese el ID del empleado a Modificar(1-2000): ", "Error,reingrese el ID del empleado a modificar(1-2000): ", 1, 2000);

		index=employee_searchIdEmployee(pArrayListEmployee, auxId);

		auxEmployee=ll_get(pArrayListEmployee, index);

		printf("%-10d %-10s %-5d %-5d", auxEmployee->id,auxEmployee->nombre,auxEmployee->horasTrabajadas,auxEmployee->sueldo);

		do{
			pedirEntero(&opcion, "\n¿Que desea modificar?\n"
					"1.Nombre\n"
					"2.Horas trabajadas\n"
					"3.Sueldo\n"
					"4.Atras\n"
					"Elija la opcion: ",
					"Error, reingrese la opcion\n\n"
					"1.Nombre\n"
					"2.Horas trabajadas\n"
					"3.Sueldo\n"
					"4.Atras\n"
					"Elija la opcion: ", 1, 4);

			switch(opcion)
			{
				case 1:
						pedirCadena(auxNombre, "Ingrese el nuevo nombre(maximo 40 caracteres):","Error,reingrese el nuevo nombre(maximo 40 caracteres):" , 40);

						printf("%s--->%s",auxEmployee->nombre,auxNombre);
						if(pedirConfirmacion("\nIngrese 's' para confirmar la modificacion del empleado: ")==0)
						{
							employee_setNombre(auxEmployee,auxNombre );
							printf("\nSe modifico con exito!\n");
						}else
						{
							printf("\nSe cancelo la modificacion\n");
						}

				break;

				case 2:
					pedirEntero(&auxHoras, "Ingrese la nueva cantidad de horas(1-40):","Error,reingrese la nueva cantidad de horas(1-40):" ,1, 40);

					printf("%d--->%d",auxEmployee->horasTrabajadas,auxHoras);
					if(pedirConfirmacion("\nIngrese 's' para confirmar la modificacion del empleado: ")==0)
					{
						employee_setHorasTrabajadas(auxEmployee,auxHoras );
						printf("\nSe modifico con exito!\n");
					}else
					{
						printf("\nSe cancelo la modificacion\n");
					}
				break;

				case 3:
					pedirEntero(&auxSueldo,"Ingrese el nuevo sueldo ($1000 minimo , $40000 maximo):", "Error, reingrese su nuevo sueldo ($1000 minimo , $40000 maximo):", 1000,40000);

					printf("%d--->%d",auxEmployee->sueldo,auxSueldo);
					if(pedirConfirmacion("\nIngrese 's' para confirmar la modificacion del empleado: ")==0)
					{
						employee_setSueldo(auxEmployee,auxSueldo );
						printf("\nSe modifico con exito!\n");
					}else
					{
						printf("\nSe cancelo la modificacion\n");
					}
				break;

				case 4:
				break;
			}


		}while(opcion==4);

		exito=1;
	}
    return exito;
}

/** \brief Baja de empleado
 *
 * \param path char*
 * \param pArrayListEmployee LinkedList*
 * \return int
 *
 */
int controller_removeEmployee(LinkedList* pArrayListEmployee)
{
	int auxId;
	int index;
	int exito=0;

	Employee* auxEmployee;
	if(pArrayListEmployee!=NULL)
	{
		controller_ListEmployee(pArrayListEmployee);

		pedirEntero(&auxId, "Ingrese el ID del empleado a eliminar(1-2000): ", "Error,reingrese el ID del empleado a eliminar(1-2000): ", 1, 2000);

		index=employee_searchIdEmployee(pArrayListEmployee, auxId);

		auxEmployee=ll_get(pArrayListEmployee, index);

		printf("%-10d %-10s %-5d %-5d", auxEmployee->id,auxEmployee->nombre,auxEmployee->horasTrabajadas,auxEmployee->sueldo);


		if(pedirConfirmacion("\nIngrese 's' para confirmar el borrado del empleado: ")==0)
			{
				ll_remove(pArrayListEmployee, index);
				printf("\nSe elimino con exito!\n\n");
			}else
			{
				printf("\nSe cancelo la eliminacion!\n\n");
			}

		exito=1;
	}
    return exito;
}

/** \brief Listar empleados
 *
 * \param path char*
 * \param pArrayListEmployee LinkedList*
 * \return int
 *
 */
int controller_ListEmployee(LinkedList* pArrayListEmployee)
{
	int i;
	int tam;
	int auxId;
	int auxHoras;
	int auxSueldo;
	char auxNombre[20];
	Employee* auxEmployee;
	int exito=0;

	printf("%-10s %-10s %-10s %-10s\n","ID","NOMBRE","HORAS","SUELDO");

	if(pArrayListEmployee!=NULL)
	{
		tam=ll_len(pArrayListEmployee);

		for(i=0;i<tam;i++)
		{
			auxEmployee=(Employee*)ll_get(pArrayListEmployee, i);
			employee_getId(auxEmployee, &auxId);
			employee_getNombre(auxEmployee, auxNombre);
			employee_getHorasTrabajadas(auxEmployee, &auxHoras);
			employee_getSueldo(auxEmployee, &auxSueldo);
			printf("%-10d %-10s %-10d %-10d\n",auxId,auxNombre,auxHoras,auxSueldo);
			//printf("%-10d %-5s %-10d %-10d\n",auxEmployee->id,auxEmployee->nombre,auxEmployee->horasTrabajadas,auxEmployee->sueldo);

		}

		exito=1;
	}

    return exito;
}

/** \brief Ordenar empleados
 *
 * \param path char*
 * \param pArrayListEmployee LinkedList*
 * \return int
 *
 */
int controller_sortEmployee(LinkedList* pArrayListEmployee)
{
	int opcion;
	int exito=0;

	if(pArrayListEmployee!=NULL)
	{
		pedirEntero(&opcion, "¿Como le gustaria ordenar?\n"
				"1.Por ID ascendente\n"
				"2.Por ID descendente\n"
				"3.Por Nombre A->Z\n"
				"4.Por Nombre Z->A\n"
				"5.Por Sueldo ascendente\n"
				"6.Por Sueldo descendente\n"
				"7.Por Horas Trabajadas ascendente\n"
				"8.Por Horas Trabajadas descendente\n\n"
				"Elija una opcion: ",
				"Error, reingrese la opcion\n"
				"1.Por ID ascendente\n"
				"2.Por ID descendente\n"
				"3.Por Nombre A->Z\n"
				"4.Por Nombre Z->A\n"
				"5.Por Sueldo ascendente\n"
				"6.Por Sueldo descendente\n"
				"7.Por Horas Trabajadas ascendente\n"
				"8.Por Horas Trabajadas descendente\n\n"
				"Elija una opcion: ", 1, 8);

		switch(opcion)
		{
			case 1:
				ll_sort(pArrayListEmployee, employee_CompareById, 1);
				controller_ListEmployee(pArrayListEmployee);
			break;
			case 2:
				ll_sort(pArrayListEmployee, employee_CompareById, 0);
				controller_ListEmployee(pArrayListEmployee);
			break;
			case 3:
				ll_sort(pArrayListEmployee, employee_CompareByName, 1);
				controller_ListEmployee(pArrayListEmployee);
			break;
			case 4:
				ll_sort(pArrayListEmployee, employee_CompareByName, 0);
				controller_ListEmployee(pArrayListEmployee);
			break;
			case 5:
				ll_sort(pArrayListEmployee, employee_CompareBySueldo, 1);
				controller_ListEmployee(pArrayListEmployee);
			break;
			case 6:
				ll_sort(pArrayListEmployee, employee_CompareBySueldo, 0);
				controller_ListEmployee(pArrayListEmployee);
			break;
			case 7:
				ll_sort(pArrayListEmployee, employee_CompareByHorasTrabajadas, 1);
				controller_ListEmployee(pArrayListEmployee);
			break;
			case 8:
				ll_sort(pArrayListEmployee, employee_CompareByHorasTrabajadas, 0);
				controller_ListEmployee(pArrayListEmployee);
			break;
		}

		exito=1;
	}
    return exito;
}

/** \brief Guarda los datos de los empleados en el archivo data.csv (modo texto).
 *
 * \param path char*
 * \param pArrayListEmployee LinkedList*
 * \return int
 *
 */
int controller_saveAsText(char* path , LinkedList* pArrayListEmployee)
{
	FILE* pFile;
	int tam;
	int i;
	Employee* employee;
	int auxId;
	char auxNombre[21];
	int auxHoras;
	int auxSueldo;
	int exito=0;

	if(path!=NULL && pArrayListEmployee!=NULL)
	{

		pFile=fopen(path,"w");

		if(pFile!=NULL)
		{
			tam= ll_len(pArrayListEmployee);
			fprintf(pFile,"Id,Nombre,Horas trabajadas,Sueldo\n");

			for(i=0;i<tam;i++)
			{
				employee=ll_get(pArrayListEmployee, i);
				employee_getId(employee,&auxId);
				employee_getNombre(employee,auxNombre);
				employee_getHorasTrabajadas(employee,&auxHoras);
				employee_getSueldo(employee,&auxSueldo);
				fprintf(pFile,"%d,%s,%d,%d\n", auxId,auxNombre, auxHoras,auxSueldo);
			}
			fclose(pFile);
			exito=1;
		}

	}
	return exito;
    //return 1;
}

/** \brief Guarda los datos de los empleados en el archivo data.csv (modo binario).
 *
 * \param path char*
 * \param pArrayListEmployee LinkedList*
 * \return int
 *
 */
int controller_saveAsBinary(char* path , LinkedList* pArrayListEmployee)
{
	FILE* pFile;
	Employee* employee;
	int tam;
	int i;
	int exito=0;

	if(path!=NULL && pArrayListEmployee!=NULL)
	{
		pFile=fopen(path, "wb");

		if(pFile!=NULL)
		{
			tam=ll_len(pArrayListEmployee);

			for(i=0;i<tam;i++)
			{
				employee=(Employee*)ll_get(pArrayListEmployee, i);
				fwrite(employee,sizeof(Employee),1,pFile);
			}

			fclose(pFile);
			exito=1;
		}
	}

	return exito;
	//return 1;
}

