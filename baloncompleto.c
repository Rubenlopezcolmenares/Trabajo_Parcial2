/*----------------------------------------------------------------*/
/* Autor: Equipo #5                                               */
/*				Raquel Francisco Bernal                                 */
/*				Beatriz Garcia Rios                                     */
/*				Ruben Lopez Colmenares                                  */
/*				Eliezer Fidel Palomec Arias                             */
/*				Nancy Miren Ramos Santos											      	  */
/* E-mail:raquel-bernal@hotmail.com                               */
/*				beatrizgarciarios1808@gmail.com                         */
/*				rubencolmenares1999@gmail.com                           */
/*				palomec_94@hotmail.com                                  */
/*				minkykpoper@gmail.com                                   */
/* Fecha creacion:                                                */
/* Fecha actualizacion:                                           */
/* Descripcion: Este programa esta elaborado en el lenguaje de    */
/*              programacion C, para fines academicos. En el cual */
/*              se incluyen:                                      */
/*                              - los tipos de de datos basico:   */
/*                                (int, char, float, void).       */
/*                              - arreglos                        */
/*                              - estructuras                     */
/*                              - constantes                      */
/*                              - enumeraciones                   */
/*                              - menu de opciones                */
/*              Tambien se incluyen funciones de la biblioteca    */
/*              string.h:                                         */
/*                        - strcpy()                              */
/*                        - strtok()                              */
/*                                                                */
/*              Asi mismo, se utiliza la funcion system(),        */
/*              propiamente de la biblioteca stdlib.h             */
/*----------------------------------------------------------------*/



#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>



/* El codigo de colores fue tomado de la siguiente pagina:  */
/* www.forosdelweb.com/f96/printf-otros-colores-836106      */

#define _RESET        "\x1b[0m"     /* Resetear el color.   */
#define _ARESET       "\E[m"        /* Resetear todo.       */

#define _TNEGRO       "\x1b[30m"    /* Define el color del texto en negro.              */
#define _TROJO        "\x1b[31m"    /* Define el color del texto en rojo.               */
#define _TVERDE       "\x1b[32m"    /* Define el color del texto en verde.              */
#define _TAMARILLO    "\x1b[33m"    /* Define el color del texto en amarillo.           */
#define _TAZUL        "\x1b[34m"    /* Define el color del texto en azul.               */
#define _TMORADO      "\x1b[35m"    /* Define el color del texto en morado.             */
#define _TCYAN        "\x1b[36m"    /* Define el color del texto en cyan.               */
#define _TBLANCO      "\x1b[37m"    /* Define el color del texto en blanco.             */

#define _FNEGRO       "\x1b[40m"    /* Define el color del fondo del texto en negro.    */
#define _FROJO        "\x1b[41m"    /* Define el color del fondo del texto en rojo.     */
#define _FVERDE       "\x1b[42m"    /* Define el color del fondo del texto en verde.    */
#define _FAMARILLO    "\x1b[43m"    /* Define el color del fondo del texto en amarillo. */
#define _FAZUL        "\x1b[44m"    /* Define el color del fondo del texto en azul.     */
#define _FMORADO      "\x1b[45m"    /* Define el color del fondo del texto en morado.   */
#define _FCYAN        "\x1b[46m"    /* Define el color del fondo del texto en cyan.     */
#define _FBLANCO      "\x1b[47m"    /* Define el color del fondo del texto en blanco.   */

#define _NEGRITA      "\E[1m"       /* Negrita.        */
#define _NNEGRITA     "\E[22m"      /* No negrita.     */
#define _CURSIVA      "\E[3m"       /* Ccursiva.       */
#define _NCURSIVA     "\E[23m"      /* No cursiva.     */
#define _SUBRAYADO    "\E[4m"       /* Subrayado.      */
#define _NSUBRAYADO   "\E[24m"      /* No subrayado.   */
#define _PARPADEANTE  "\E[5m"       /* Parpadeante.    */
#define _NPARPADEANTE "\E[25m"      /* No parpadeante. */



#define TAM_NOM     50        /* Definicion del tamanio del arreglo unidimensional */
#define TAM_MATERIAL     12        /* Tamaño del material del Balon */
#define TAM_BALON 10        /* Tamaño del Balon */


#define TAM_MARCA 10        /* Tamanio de la marca del Balones */
#define TOTAL_BALON 10        /* Tamaño total de Balones    */




/* Declaracion de enumeraciones para el control de menu de opciones:                             */
/* LISTAR                  = 1                                                                   */
/* INSERTAR                = 2                                                                   */
/* ACTUALIZAR              = 3                                                                   */
/* ORDENAR_ASCENDENTE      = 4                                                                   */
/*ORDENAR_DESCENDENTE      = 5                                                                   */
/* ELIMINAR                = 6                                                                   */
/* BUSCAR                  = 7                                                                   */
/* AYUDA                   = 8                                                                   */
/* QUIENES SOMOS           = 9                                                                   */
/* SALIR                   = 10                                                                  */
enum OPCIONES_MENU{INSERTAR = 1,
	                 LISTAR,
	                 ACTUALIZAR,
	                 ORDENAR_ASCENDENTE,
									 ORDENAR_DESCENDENTE,
	                 ELIMINAR,
	                 BUSCAR,
	                 AYUDA,
	                 QUIENES_SOMOS,
									 INTEGRANTES,
                   SALIR};



/* Declaracion de enumeracion para el manejo de los casos: */
/* Buscar por:     Material o por Tamaño,                 */
/* Actualizar por: Material o por Tamaño,                 */
/* Eliminar por:   Materila o por Tamaño                  */
enum OPCIONES_BUSCAR_ACTUALIZAR_ELIMINAR{_xMaterial=1,
                                         _xMarca};



/* Se define una estructura para modelar los datos de un Balon. */
/* Los miembros de la estructura son:                             */
/*                                    - Material                    */
/*                                    - Tamaño           */
/*                                    - Marca                    */
/*                                    - Peso                  */
/*                                    - Color                  */

typedef struct
{
	char Material[TAM_MATERIAL];
	int Tamanio;
	char Marca[TAM_MARCA];
	float Peso;
	char Color[20];

}Balon;



int main(void)
{
  Balon balon[TOTAL_BALON];      /* Declaracion de una variable de arreglo de estructura balon[]       */
	int numBalon = 0;               /* Controla el numero de balones que desea el usuario.                 */
	int opcion;                       /* Controla las opciones del menu.                                     */
	char c;                           /* Lee un caracter y valida el salto de linea para salir de la opcion. */



	int arrayTemp[TOTAL_BALON];      /* Almacena los indices de los registros almacenados en la estructura */
	char materialBuscar[50];             /*Almacena el material a buscar dentro de la estructura                */
	char marcaBuscar[12];          /*Almacena la marca a buscar dentro de la estructura             */



	int opcionBuscar = 0;



	do{
		system("clear");  /* Limpia toda la pantalla.           */
		puts("");         /* Haciendo salto de lina con puts(). */



		printf(_FVERDE _TCYAN  _NEGRITA _SUBRAYADO "\nS I S T E M A     D E    C O N T R O L    D E    B A L O N E S" _ARESET);



		printf(_TMORADO _NEGRITA "\nM E N U    P R I N C I P A L\n");

		printf(_TAMARILLO _NEGRITA "\n\t1. Insertar");
		printf(_TAMARILLO _NEGRITA "\n\t2. Listar");
		printf(_TAMARILLO _NEGRITA "\n\t3. Actualizar");
		printf(_TAMARILLO _NEGRITA "\n\t4. Ordenar Ascendente");
		printf(_TAMARILLO _NEGRITA "\n\t5. Ordenar Descendente");
    printf(_TAMARILLO _NEGRITA "\n\t6. Eliminar");
		printf(_TAMARILLO _NEGRITA "\n\t7. Buscar");
		printf(_TAMARILLO _NEGRITA "\n\t8. Ayuda");
		printf(_TAMARILLO _NEGRITA "\n\t9. Quienes Somos");
		printf(_TAMARILLO _NEGRITA "\n\t10. Integrantes");
		printf(_TAMARILLO _NEGRITA "\n\t11. Salir");



		printf(_TCYAN _NEGRITA "\n\nSeleccione una opcion: ");
		scanf("%d", &opcion);



		switch(opcion)
		{


			case LISTAR:
							printf(_TCYAN _NEGRITA "\n\n2. L I S T A     D E    B A L O N E S \n\n");


							/* Ciclo for: permite imprimir los datos de los ingresados por el usuario */
							printf(_TROJO     _NEGRITA);
							printf("%-12s|%-10s|%-10s|\tPESO\t|\tCOLOR\t|", "MATERIAL", "TAMANIO", "MARCA");
							printf("\n---------------------------------------------------------------------------\n");
							for(int i = 0; i < numBalon; i++)
							{
								printf(_TBLANCO _NEGRITA);
								printf("%-12s|%-10d|%-10s|\t%.2f\t|\t%s\t", balon[i].Material,
																															balon[i].Tamanio,
																			 												balon[i].Marca,
																															balon[i].Peso,
																															balon[i].Color);

								printf("\n");
							}



							while(getchar() != '\n');     /* Limpiar el buffer en caso de tener almacenado el salto de linea */
							printf(_TAMARILLO _NEGRITA "\n\n\nPresiones Enter para salir: ");

							while((c=getchar()) != '\n')  /* Solicita un enter al usuario para reiniciar el menu principal */
							{}
							break;
			case INSERTAR:
											printf(_TCYAN     _NEGRITA "\n\n1. A L T A     D E     B A L O N E S");
											printf(_TAMARILLO _NEGRITA "\n\nIntroduce el numero de balones: " _TVERDE);
											scanf("%d",&numBalon);

											printf("\n\n" _ARESET);

											/* Ciclo for: permite solocitar los datos de los ingresados por el usuario */
											for(int i = 0; i < numBalon; i++)
											{
											  while(getchar() != '\n'); /* Limpiar el buffer en caso de tener almacenado el salto de linea */



												printf(_TBLANCO _NEGRITA "Introduce el nombre del Material: "              _NNEGRITA _TVERDE);
												fgets(balon[i].Material, TAM_MATERIAL, stdin);                                    /* Solicita el nombre del material al usuario          */
												strcpy(balon[i].Material, strtok(balon[i].Material, "\n"));								    /* Elimina el salto de linea '\n' que genera fgets() */



												printf(_TBLANCO _NEGRITA "Introduce el Tamaño del Balon: "           _NNEGRITA _TVERDE);
												scanf("%d",&balon[i].Tamanio);                                 /* Solicita el tamaño del balon al usuario        */

												while(getchar() != '\n'); /* Limpiar el buffer en caso de tener almacenado el salto de linea */

												printf(_TBLANCO _NEGRITA "Introduce la marca del Balon: " _NNEGRITA _TVERDE);
												fgets(balon[i].Marca, TAM_MARCA, stdin);                         /* Solicita la marca del balon al usuario        */
												strcpy(balon[i].Marca, strtok(balon[i].Marca, "\n")); /*Elimina el salto de linea '\n' que genera fgets    */



												printf(_TBLANCO _NEGRITA "Introduce el peso del Balon: "                _NNEGRITA _TVERDE);
												scanf("%f", &balon[i].Peso);

												printf(_TBLANCO _NEGRITA "Introduce el color del Balon: "                _NNEGRITA _TVERDE);
												scanf("%s", balon[i].Color);

											  while(getchar() != '\n'); /* Limpiar el buffer en caso de tener almacenado el salto de linea */




												printf("\n\n");
											}



											while(getchar() != '\n'); /* Limpiar el buffer en caso de tener almacenado el salto de linea */
										  printf(_TAMARILLO _NEGRITA "Presiones Enter para salir: ");



											while((c=getchar()) != '\n')  /* Solicita un enter al usuario para reiniciar el menu principal */
											{}
											break;

						case ORDENAR_ASCENDENTE:
															while(getchar() != '\n');     /* Limpiar el buffer en caso de tener almacenado el salto de linea */
															printf(_TAMARILLO _NEGRITA "\n\n4. O R D E N A R   A S C E D E N T E\n\n");


															for(int i = 0; i < numBalon; i++)
																arrayTemp[i] = i;


															for(int i = 0; i < numBalon; i++)
																for(int j = i + 1; j < numBalon; j++)
																	if(strcmp(balon[arrayTemp[i]].Material, balon[arrayTemp [j]].Material) > 0)
																	{
																		int aux = arrayTemp[i];
																		arrayTemp[i] = arrayTemp[j];
																		arrayTemp[j] = aux;
																	}



																	/* Ciclo for: permite imprimir los datos de los ingresados por el usuario */
																	printf(_TROJO     _NEGRITA);
																	printf("%-12s|%-10s|%-10s|\tPESO\t|\tCOLOR\t|", "MATERIAL", "TAMANIO", "MARCA");
																	printf("\n-------------------------------------------------------------------------\n");
																	for(int i = 0; i < numBalon; i++)
																	{
																		printf(_TBLANCO _NEGRITA);
																		printf("%-12s|%-10d|%-10s|\t%.2f\t|\t%s\t", balon[arrayTemp[i]].Material,
																																										balon[arrayTemp[i]].Tamanio,
																																										balon[arrayTemp[i]].Marca,
																																										balon[arrayTemp[i]].Peso,
																																										balon[arrayTemp[i]].Color);

																		printf("\n");
																	}

															/* printf(_TROJO     _NEGRITA "\n\nEn construccion ...!");*/
															printf(_TAMARILLO _NEGRITA "\n\nPresione Enter para regresar al menu principal: ");
															while((c=getchar()) != '\n')  /* Solicita un enter al usuario para reiniciar el menu principal */
															{}
															break;

									case ORDENAR_DESCENDENTE:
																			while(getchar() != '\n');     /* Limpiar el buffer en caso de tener almacenado el salto de linea */
																			printf(_TAMARILLO _NEGRITA "\n\n5. O R D E N A R    D E S C E D E N T E\n\n");


																			for(int i = 0; i < numBalon; i++)
																				arrayTemp[i] = i;


																			for(int i = 0; i < numBalon; i++)
																				for(int j = i + 1; j < numBalon; j++)
																					if(strcmp(balon[arrayTemp[i]].Material, balon[arrayTemp[j]].Material) < 0)
																					{
																						int aux = arrayTemp[i];
																						arrayTemp[i] = arrayTemp[j];
																						arrayTemp[j] = aux;
																					}

																					/* Ciclo for: permite imprimir los datos de los ingresados por el usuario */
																					printf(_TROJO     _NEGRITA);
																					printf("%-12s|%-10s|%-10s|\tPESO\t|\tCOLOR\t|", "MATERIAL", "TAMANIO", "MARCA");
																					printf("\n------------------------------------------------------------------------\n");
																					for(int i = 0; i < numBalon; i++)
																					{
																						printf(_TBLANCO _NEGRITA);
																						printf("%-12s|%-10d|%-10s|\t%.2f\t|\t%s\t", balon[arrayTemp[i]].Material,
																																																			 balon[arrayTemp[i]].Tamanio,
																																																			 balon[arrayTemp[i]].Marca,
																																																			 balon[arrayTemp[i]].Peso,
																																																			 balon[arrayTemp[i]].Color);

																						printf("\n");
																					}



																			/* printf(_TROJO     _NEGRITA "\n\nEn construccion ...!");*/
																			printf(_TAMARILLO _NEGRITA "\n\nPresione Enter para regresar al menu principal: ");
																			while((c=getchar()) != '\n')  /* Solicita un enter al usuario para reiniciar el menu principal */
																			{}
																			break;

								case BUSCAR:
																							while(getchar() != '\n');     /* Limpiar el buffer en caso de tener almacenado el salto de linea */
																							printf(_TAMARILLO _NEGRITA "\n\n7. B U S C A R\n\n");
																							printf(_TCYAN     _NEGRITA "Buscar Balon por:\n\n");
																							printf(_TBLANCO   _NEGRITA "\t1. Material\n");
																							printf(_TBLANCO   _NEGRITA "\t2. Marca \n\n");



																							printf(_TCYAN     _NEGRITA "Introduce una opcion: ");
																							scanf("%d", &opcionBuscar);



																							switch(opcionBuscar)
																							{
																								case _xMaterial:
																															while(getchar() != '\n');     /* Limpiar el buffer en caso de tener almacenado el salto de linea */



																															printf(_TCYAN _NEGRITA "\n\nIngrese el material del Balon: ");
																															fgets(materialBuscar, TAM_NOM, stdin);
																															strcpy(materialBuscar, strtok(materialBuscar, "\n"));



																															for(int i = 0; i < numBalon; i++)
																																if(strcmp(materialBuscar, balon[i].Material) == 0)
																																{
																																	printf(_TROJO     _NEGRITA);
																																	printf("%-12s|%-10s|%-10s|\tPESO\t|\tCOLOR\t|", "MATERIAL", "TAMANIO", "MARCA");
																																	printf("\n---------------------------------------------------------------------------\n");
																																	printf(_TBLANCO _NEGRITA);
																																	printf("%-12s|%-10d|%-10s|\t%.2f\t|\t%s\t", balon[i].Material,
																																																									balon[i].Tamanio,
																																																									balon[i].Marca,
																																																									balon[i].Peso,
																																																									balon[i].Color);
																																}

																																break;

																									case _xMarca:
																																	while(getchar() != '\n');     /* Limpiar el buffer en caso de tener almacenado el salto de linea */



																																	printf(_TCYAN _NEGRITA "\n\nIntroduce la marca: ");
																																	fgets(marcaBuscar, TAM_NOM, stdin);
																																	strcpy(marcaBuscar, strtok(marcaBuscar, "\n"));




																																	for(int i = 0; i < numBalon; i++)
																																		if(strcmp(marcaBuscar, balon[i].Marca) == 0)
																																			{
																																				printf(_TROJO     _NEGRITA);
																																				printf("%-12s|%-10s|%-10s|\tPESO\t|\tCOLOR\t|", "MATERIAL", "TAMANIO", "MARCA");
																																				printf("\n---------------------------------------------------------------------------\n");
																																				printf(_TBLANCO _NEGRITA);
																																				printf("%-12s|%-10d|%-10s|\t%.2f\t|\t%s\t", balon[i].Material,
																																																												balon[i].Tamanio,
																																																												balon[i].Marca,
																																																												balon[i].Peso,
																																																												balon[i].Color);
																																			}

																																break;
																							}

																							printf(_TAMARILLO _NEGRITA "\n\nPresione Enter para regresar al menu principal: ");
																							while((c=getchar()) != '\n')  /* Solicita un enter al usuario para reiniciar el menu principal */
																							{}
																							break;

							case ACTUALIZAR:
																											while(getchar() != '\n');     /* Limpiar el buffer en caso de tener almacenado el salto de linea */
																											printf(_TAMARILLO _NEGRITA "\n\n3. A C T U A L I Z A R\n\n");



																											printf(_TCYAN     _NEGRITA "Buscar el Balon a actualizar por:\n\n");
																											printf(_TBLANCO   _NEGRITA "\t1. Material\n");
																											printf(_TBLANCO   _NEGRITA "\t2. Marca \n\n");



																											printf(_TCYAN     _NEGRITA "Introduce una opcion: ");
																											scanf("%d", &opcionBuscar);

																											switch(opcionBuscar)
																											{
																													case _xMaterial:
																																		while(getchar() != '\n');     /* Limpiar el buffer en caso de tener almacenado el salto de linea */




																																		printf(_TCYAN _NEGRITA "\n\nIntroduceel Material del Balon: ");
																																		fgets(materialBuscar, TAM_NOM, stdin);
																																		strcpy(materialBuscar, strtok(materialBuscar, "\n"));


																																		for(int i = 0; i < numBalon; i++)
																																		{
																																		if(strcmp(materialBuscar, balon[i].Material) == 0)
																																		{
																																		printf(_TROJO     _NEGRITA);
																																	  printf("%-12s|%-10s|%-10s|\tPESO\t|\tCOLOR\t|", "MATERIAL", "TAMANIO", "MARCA");
																																		printf("\n---------------------------------------------------------------------------\n");
																																		printf(_TBLANCO _NEGRITA);
																																		printf("%-12s|%-10d|%-10s|\t%.2f\t|\t%s\t", balon[i].Material,
																																																							 balon[i].Tamanio,
																																																							 balon[i].Marca,
																																																						 	 balon[i].Peso,
																																																							 balon[i].Color);

																																				printf("\n\n");


																																				printf(_TBLANCO _NEGRITA "Introduce el nombre del Material: "              _NNEGRITA _TVERDE);
																																				fgets(balon[i].Material, TAM_MATERIAL, stdin);                                    /* Solicita el nombre del material al usuario          */
																																				strcpy(balon[i].Material, strtok(balon[i].Material, "\n"));								    /* Elimina el salto de linea '\n' que genera fgets() */



																																				printf(_TBLANCO _NEGRITA "Introduce el Tamaño del Balon: "           _NNEGRITA _TVERDE);
																																				scanf("%d",&balon[i].Tamanio);                                 /* Solicita el tamaño del balon al usuario        */

																																				while(getchar() != '\n'); /* Limpiar el buffer en caso de tener almacenado el salto de linea */

																																				printf(_TBLANCO _NEGRITA "Introduce la marca del Balon: " _NNEGRITA _TVERDE);
																																				fgets(balon[i].Marca, TAM_MARCA, stdin);                         /* Solicita la marca del balon al usuario        */
																																				strcpy(balon[i].Marca, strtok(balon[i].Marca, "\n")); /*Elimina el salto de linea '\n' que genera fgets    */



																																				printf(_TBLANCO _NEGRITA "Introduce el peso del Balon: "                _NNEGRITA _TVERDE);
																																				scanf("%f", &balon[i].Peso);

																																				printf(_TBLANCO _NEGRITA "Introduce el color del Balon: "                _NNEGRITA _TVERDE);
																																				scanf("%s", balon[i].Color);
																																				printf("\n\n");

																																				printf(_TROJO     _NEGRITA);
																																				printf("%-12s|%-10s|%-10s|\tPESO\t|\tCOLOR\t|", "MATERIAL", "TAMANIO", "MARCA");
																																				printf("\n---------------------------------------------------------------------------\n");
																																				printf(_TBLANCO _NEGRITA);
																																				printf("%-12s|%-10d|%-10s|\t%.2f\t|\t%s\t", balon[i].Material,
																																																									 balon[i].Tamanio,
																																																									 balon[i].Marca,
																																																									 balon[i].Peso,
																																																									 balon[i].Color);



																																				break;
																																			}
																																		}


																																		break;

																													case _xMarca:
																																		while(getchar() != '\n');     /* Limpiar el buffer en caso de tener almacenado el salto de linea */



																																		printf(_TCYAN _NEGRITA "\n\nIntroduce la Marca del Balon: ");
																																		fgets(marcaBuscar, 50, stdin);
																																		strcpy(marcaBuscar, strtok(marcaBuscar, "\n"));



																																		for(int i = 0; i < numBalon; i++)
																																		{
																																			if(strcmp(marcaBuscar, balon[i].Marca) == 0)
																																			{
																																				printf(_TROJO     _NEGRITA);
																																				printf("%-12s|%-10s|%-10s|\tPESO\t|\tCOLOR\t|", "MATERIAL", "TAMANIO", "MARCA");
																																				printf("\n---------------------------------------------------------------------------\n");
																																				printf(_TBLANCO _NEGRITA);
																																				printf("%-12s|%-10d|%-10s|\t%.2f\t|\t%s\t", balon[i].Material,
																																																									 balon[i].Tamanio,
																																																									 balon[i].Marca,
																																																									 balon[i].Peso,
																																																									 balon[i].Color);

																																						printf("\n\n");


																																						printf(_TBLANCO _NEGRITA "Introduce el nombre del Material: "              _NNEGRITA _TVERDE);
																																						fgets(balon[i].Material, TAM_MATERIAL, stdin);                                    /* Solicita el nombre del material al usuario          */
																																						strcpy(balon[i].Material, strtok(balon[i].Material, "\n"));								    /* Elimina el salto de linea '\n' que genera fgets() */



																																						printf(_TBLANCO _NEGRITA "Introduce el Tamaño del Balon: "           _NNEGRITA _TVERDE);
																																						scanf("%d",&balon[i].Tamanio);                                 /* Solicita el tamaño del balon al usuario        */

																																						while(getchar() != '\n'); /* Limpiar el buffer en caso de tener almacenado el salto de linea */

																																						printf(_TBLANCO _NEGRITA "Introduce la marca del Balon: " _NNEGRITA _TVERDE);
																																						fgets(balon[i].Marca, TAM_MARCA, stdin);                         /* Solicita la marca del balon al usuario        */
																																						strcpy(balon[i].Marca, strtok(balon[i].Marca, "\n")); /*Elimina el salto de linea '\n' que genera fgets    */



																																						printf(_TBLANCO _NEGRITA "Introduce el peso del Balon: "                _NNEGRITA _TVERDE);
																																						scanf("%f", &balon[i].Peso);

																																						printf(_TBLANCO _NEGRITA "Introduce el color del Balon: "                _NNEGRITA _TVERDE);
																																						scanf("%s", balon[i].Color);
																																						printf("\n\n");

																																						printf(_TROJO     _NEGRITA);
																																						printf("%-12s|%-10s|%-10s|\tPESO\t|\tCOLOR\t|", "MATERIAL", "TAMANIO", "MARCA");
																																						printf("\n---------------------------------------------------------------------------\n");
																																						printf(_TBLANCO _NEGRITA);
																																						printf("%-12s|%-10d|%-10s|\t%.2f\t|\t%s\t", balon[i].Material,
																																																											 balon[i].Tamanio,
																																																											 balon[i].Marca,
																																																											 balon[i].Peso,
																																																											 balon[i].Color);
																																				break;
																																			}
																																		}
																																		break;
																											}
																											while(getchar() != '\n');     /* Limpiar el buffer en caso de tener almacenado el salto de linea */

																											printf(_TAMARILLO _NEGRITA "\n\nPresione Enter para regresar al menu principal: ");
																											while((c=getchar()) != '\n')  /* Solicita un enter al usuario para reiniciar el menu principal */
																											{}
																											break;

						case ELIMINAR:
																																															while(getchar() != '\n');     /* Limpiar el buffer en caso de tener almacenado el salto de linea */
																																															printf(_TAMARILLO _NEGRITA "\n\n6. E L I M I N A R\n\n");



																																															printf(_TCYAN     _NEGRITA "Buscar el Balon a actualizar por:\n\n");
																																															printf(_TBLANCO   _NEGRITA "\t1. Material\n");
																																															printf(_TBLANCO   _NEGRITA "\t2. Marca \n\n");



																																															printf(_TCYAN     _NEGRITA "Introduce una opcion: ");
																																															scanf("%d", &opcionBuscar);

																																															switch(opcionBuscar)
																																															{
																																																	case _xMaterial:
																																																						while(getchar() != '\n');     /* Limpiar el buffer en caso de tener almacenado el salto de linea */




																																																						printf(_TCYAN _NEGRITA "\n\nIntroduceel Material del Balon: ");
																																																						fgets(materialBuscar, TAM_NOM, stdin);
																																																						strcpy(materialBuscar, strtok(materialBuscar, "\n"));


																																																						for(int i = 0; i < numBalon; i++)
																																																						{
																																																						if(strcmp(materialBuscar, balon[i].Material) == 0)
																																																						{
																																																						printf(_TROJO     _NEGRITA);
																																																						printf("%-12s|%-10s|%-10s|\tPESO\t|\tCOLOR\t|", "MATERIAL", "TAMANIO", "MARCA");
																																																						printf("\n---------------------------------------------------------------------------\n");
																																																						printf(_TBLANCO _NEGRITA);
																																																						printf("%-12s|%-10d|%-10s|\t%.2f\t|\t%s\t", balon[i].Material,
																																																																											 balon[i].Tamanio,
																																																																											 balon[i].Marca,
																																																																											 balon[i].Peso,
																																																																											 balon[i].Color);

																																																				    printf("\n\n");

																																																						printf(_TBLANCO _NEGRITA "\n\nPresione una (s) si esta seguro de eliminar el registo:  "                _NNEGRITA _TVERDE);



																																																						char opcionEliminar;
																																																						while((opcionEliminar = getchar()) == 's')
																																																						{
																																																								for(int j = i; j < numBalon-1; j++)
																																																								{
																																																									strcpy(balon[j].Material,          balon[j+1].Material);
																																																									balon[j].Tamanio    =   balon[j+1].Tamanio;
																																																									strcpy(balon[j].Marca, balon[j+1].Marca);
																																																									balon[j].Peso    = balon[j+1].Peso;
																																																									strcpy(balon[j].Color,    balon[j+1].Color);


																																																								}

																																																								printf("\n\nEl registro se ha eliminado exitosamente.\n\n");

																																																						}

																																																						strcmp(balon[numBalon-1].Material,          "");
																																																						balon[numBalon-1].Tamanio =-1;
																																																						strcmp(balon[numBalon-1].Marca, "");
																																																						balon[numBalon-1].Peso     = -1;
																																																						strcmp(balon[numBalon-1].Color,   "");



																																																						numBalon--;



																																																						printf("\n\n");

																																																						for(int i = 0; i < numBalon; i++)
																																																						{
																																																							if(strcmp(materialBuscar, balon[i].Material) == 0)
																																																							{
																																																								printf(_TROJO     _NEGRITA);
																																																								printf("%-12s|%-10s|%-10s|\tPESO\t|\tCOLOR\t|", "MATERIAL", "TAMANIO", "MARCA");
																																																								printf("\n---------------------------------------------------------------------------\n");
																																																								printf(_TBLANCO _NEGRITA);
																																																								printf("%-12s|%-10d|%-10s|\t%.2f\t|\t%s\t", balon[i].Material,
																																																																													 balon[i].Tamanio,
																																																																													 balon[i].Marca,
																																																																													 balon[i].Peso,
																																																																													 balon[i].Color);
																																																								 }
			 																																																				}


			 																																																			break;

			 																																																	  	}
			 																																																	 }


			 																																																	break;

																																												  case _xMarca:
																																																									while(getchar() != '\n');     /* Limpiar el buffer en caso de tener almacenado el salto de linea */




																																																									printf(_TCYAN _NEGRITA "\n\nIntroduce la Marca del Balon: ");
																																																									fgets(marcaBuscar, TAM_NOM, stdin);
																																																									strcpy(marcaBuscar, strtok(marcaBuscar, "\n"));


																																																									for(int i = 0; i < numBalon; i++)
																																																									{
																																																									if(strcmp(marcaBuscar, balon[i].Marca) == 0)
																																																									{
																																																									printf(_TROJO     _NEGRITA);
																																																									printf("%-12s|%-10s|%-10s|\tPESO\t|\tCOLOR\t|", "MATERIAL", "TAMANIO", "MARCA");
																																																									printf("\n---------------------------------------------------------------------------\n");
																																																									printf(_TBLANCO _NEGRITA);
																																																									printf("%-12s|%-10d|%-10s|\t%.2f\t|\t%s\t", balon[i].Material,
																																																																														 balon[i].Tamanio,
																																																																														 balon[i].Marca,
																																																																														 balon[i].Peso,
																																																																														 balon[i].Color);

																																																									printf("\n\n");

																																																									printf(_TBLANCO _NEGRITA "\n\nPresione una (s) si esta seguro de eliminar el registo:  "                _NNEGRITA _TVERDE);



																																																									char opcionEliminar;
																																																									while((opcionEliminar = getchar()) == 's')
																																																									{
																																																											for(int j = i; j < numBalon-1; j++)
																																																											{
																																																												strcpy(balon[j].Material,          balon[j+1].Material);
																																																												balon[j].Tamanio    =   balon[j+1].Tamanio;
																																																												strcpy(balon[j].Marca, balon[j+1].Marca);
																																																												balon[j].Peso    = balon[j+1].Peso;
																																																												strcpy(balon[j].Color,    balon[j+1].Color);






																																																											}

																																																											printf("\n\nSe ha eliminado :...\n\n");

																																																									}

																																																									strcmp(balon[numBalon-1].Material,          "");
																																																									balon[numBalon-1].Tamanio =-1;
																																																									strcmp(balon[numBalon-1].Marca, "");
																																																									balon[numBalon-1].Peso     = -1;
																																																									strcmp(balon[numBalon-1].Color,   "");




																																																									numBalon--;



																																																									printf("\n\n");

																																																									for(int i = 0; i < numBalon; i++)
																																																									{
																																																										if(strcmp(marcaBuscar, balon[i].Marca) == 0)
																																																										{
																																																											printf(_TROJO     _NEGRITA);
																																																											printf("%-12s|%-10s|%-10s|\tPESO\t|\tCOLOR\t|", "MATERIAL", "TAMANIO", "MARCA");
																																																											printf("\n---------------------------------------------------------------------------\n");
																																																											printf(_TBLANCO _NEGRITA);
																																																											printf("%-12s|%-10d|%-10s|\t%.2f\t|\t%s\t", balon[i].Material,
																																																																																 balon[i].Tamanio,
																																																																																 balon[i].Marca,
																																																																																 balon[i].Peso,
																																																																																 balon[i].Color);
																																																											 }
																																																										}


																																																									break;

																																																									}
																																																							 }
																																																						 }
			 																																																			printf(_TAMARILLO _NEGRITA "\n\nPresione Enter para regresar al menu principal: ");
			 																																																			while((c=getchar()) != '\n')  /* Solicita un enter al usuario para reiniciar el menu principal */
			 																																																			{}
			 																																																			break;



          case AYUDA:
					printf(_TAMARILLO _NEGRITA"\n\n 8. A Y U D A\n\n");

 				 									puts(_TBLANCO _NEGRITA"En la opcion 1. Insertar, usted puede ingresar los datos de los balones que usted desea registrar.");
 													puts(_TBLANCO _NEGRITA"En la opcion 2. Listar, enlista los datos que usted ingresó en la opcion 1.");
 													puts(_TBLANCO _NEGRITA"En la opciion 3. Actualizar, usted puede corregir los datos ingresados para actualizarlos en caso de un error o algun cambio.");
 													puts(_TBLANCO _NEGRITA"En la opcion 4. Ordenar Ascendente, usted puede ordenar sus datos ingresados de A-Z y en la opcion 5. Ordenar Descendente puede hacer lo contrario, ordenar de Z-A. ");
 													puts(_TBLANCO _NEGRITA"En la opcion 6. Eliminar, usted puede quitar datos de la lista que ya no utilice.");
													puts(_TBLANCO _NEGRITA"En la opcion 7. Buscar, usted puede encontrar facilmente algun dato que desee.");
													puts(_TBLANCO _NEGRITA"En la opcion 9. Quienes Somos, recibira informacion sobre esta estructura");
													puts(_TBLANCO _NEGRITA"En la opcion 10. Integrantes, recibira la informacion acerca de las personas que realizaron este programa. ");
													puts(_TBLANCO _NEGRITA"En la opcion 11. Salir, usted puede salir del programa.");

													printf(_TCYAN _NEGRITA"\nPresione enter para regresara al menu principal\n");

 													while(getchar() != '\n');     /* Limpiar el buffer en caso de tener almacenado el salto de linea */

 													while ((c=getchar()) != '\n'){}
 													break;



         case QUIENES_SOMOS:

				 printf(_TAMARILLO _NEGRITA "\n\n9. Q U I E N E S   S O M O S\n\n");

				 									puts(_TCYAN _NEGRITA"Nosotros somos alumnos de la Licenciatura en informatica de la Universidad de la Sierra Sur");
													puts(_TCYAN _NEGRITA"Nuestro objetivo es realizar una estructura en lenguaje c para hacer un inventario de datos sobre balones");
													puts(_TCYAN _NEGRITA"que nos puede ser de ayuda para personas que se dediquen a la venta de estos, ya que puede llevar un buen conteo");
													puts(_TCYAN _NEGRITA"del registro de compras y ventas");

													printf(_TBLANCO _NEGRITA"\n\nPresione enter para regresara al menu principal\n");

													while(getchar() != '\n');     /* Limpiar el buffer en caso de tener almacenado el salto de linea */

													while ((c=getchar()) != '\n'){}
													break;

					case INTEGRANTES:

													printf(_TCYAN _NEGRITA "\n\n10. I N T E G R A N T E S\n\n");

													puts(_TBLANCO _NEGRITA "1.- Raquel Francisco Bernal     ");
													puts(_TBLANCO _NEGRITA "2.- Beatriz Garcia Rios         ");
													puts(_TBLANCO _NEGRITA "3.- Ruben Lopez Colmenares      ");
													puts(_TBLANCO _NEGRITA "4.- Eliezer Fidel Palomec Arias ");
													puts(_TBLANCO _NEGRITA "5.- Nancy Miren Ramos Santos    ");

													printf(_TAMARILLO _NEGRITA"\n\nPresione enter para regresara al menu principal\n");

													while(getchar() != '\n');     /* Limpiar el buffer en caso de tener almacenado el salto de linea */

													while ((c=getchar()) != '\n'){}
													break;


					case SALIR:
															system("clear");              /* Antes de terminar la ejecucion del programa, limpia la pantalla */
															exit(0);                      /* Termina la ejecucion del programa                               */
										}
									}while(opcion != SALIR);

									return 0;
								}
