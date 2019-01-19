/*
--------------------------------------------------------------------------------
			TALLER N1
Autores: Cristian Rodriguez	1007794309
		 Johan Taborda 		1225092815
Fecha: 9 de Septiembre del 2018
--------------------------------------------------------------------------------
*/
#include<string.h>
#include<stdlib.h>
#include<stdio.h>


using namespace std;
//Definidion de tipos
enum Opciones{LeerDatos=1, OrdenarDatos, ImprimirDatos, Salir};
enum ValidarDatos {NoHay, Hay};
typedef enum {Seguir=1, NoSeguir} SeguirLeyendo;
typedef unsigned short int Usi;

//Definicion de constantes
const char *NDispositivo[]={
						"Primer","Segundo","Tercer","Cuarto","Quinto","Sexto","septimo","octavo","Noveno","Decimo",
						"Undecimo","Duodecimo","Decimo tercero","Decimo cuarto","Decimo quinto","Decimo sexto","Decimo octavo","Decimo noveno","Vigesimo",
						"Vigesimo primero","Vigesimo segundo","Vigesimo tercero","Vigesimo cuarto","Vigesimo quinto","Vigesimo sexto","Vigesimo septimo","Vigesimo octavo","Vigesimo noveno","Trigesimo"};

//Definicion de macros
#define CLEAR system("cls")
#define PAUSE system("pause")
#define LONG 50
#define SHORT 10
#define LIMPIAR fflush(stdin);
#define LIMITEDATOS 30

int main()
{
	char Marca[LIMITEDATOS][LONG], Color[LIMITEDATOS][SHORT], Modelo[LIMITEDATOS][SHORT], Resolucion[LIMITEDATOS][SHORT], Grosor[LIMITEDATOS][SHORT], Mes[LIMITEDATOS][SHORT];
	Usi MesLanzamiento, ALanzamiento[LIMITEDATOS];
	Usi DiaLanzamiento[LIMITEDATOS];
	Usi NDato=0;
	Usi IDato=0;
	SeguirLeyendo Leer=Seguir;
	ValidarDatos HayDatos=NoHay;
	system("mode con: cols=76 lines=300");
	Opciones Opcion=ImprimirDatos;
	float Peso[LIMITEDATOS];

	while (Opcion!= Salir)
	{
		CLEAR;
		printf("\n\t\t\t   +-------------------+\n");
		printf("\t\t\t   |        MENU       |\n");
		printf("\t\t\t   +-------------------+\n");
		printf("\t\t\t   | 1. Leer Datos     |\n");
		printf("\t\t\t   +-------------------+\n");
		printf("\t\t\t   | 2. Ordenar Datos  |\n");
		printf("\t\t\t   +-------------------+\n");
		printf("\t\t\t   | 3. Imprimir Datos |\n");
		printf("\t\t\t   +-------------------+\n");
		printf("\t\t\t   | 4. Salir          |\n");
		printf("\t\t\t   +-------------------+\n\n\n");
		printf("\t\t Que deseas hacer?\t\t");
		scanf("%d", &Opcion);
	CLEAR;
		switch(Opcion)
			{
				case LeerDatos:{
					Leer=Seguir;
					if(NDato==LIMITEDATOS)
					{
						printf("Haz alcanzado el limite de dispositivos...");
						PAUSE;
						break;
					}
					else{
						printf("\n----------------------------------------------------------------------------\n");
						printf("\t\t     Ingrese los datos solicitados.\n\n");
						printf("----------------------------------------------------------------------------\n\n");

						while(NDato<LIMITEDATOS)
							{
								if(Leer==Seguir)
								{
								HayDatos=Hay;
								printf("\n\n\t %s Dispositivo:\n\n", NDispositivo[NDato]);
								printf("\t\t\tModelo:\t");
								scanf("%s", &Modelo[NDato]); LIMPIAR;
								printf("\n\t\t\tMarca:\t");
								scanf("%s", &Marca[NDato]); LIMPIAR;
								printf("\n\t\t\tResolucion:\t");
								scanf("%s", &Resolucion[NDato]); LIMPIAR;
								printf("\n\t\t\tPeso(g):\t");
								scanf("%f", &Peso[NDato]);
								printf("\n\t\t\tGrosor(mm):\t");
								scanf("%s", &Grosor[NDato]); LIMPIAR;
								printf("\n\t\t\tColor:\t");
								scanf("%s", &Color[NDato]); LIMPIAR;
								printf("\n\t\t\tDia de lanzamiento:\t");
								scanf("%u4", &DiaLanzamiento[NDato]);
								printf("\n\t\t\tMes de lanzamiento:\t");
								scanf("%u", &MesLanzamiento);

								while (MesLanzamiento!=0)
									{
										switch(MesLanzamiento)
											{
												case 1: {
													strcpy(Mes[NDato],"Enero");
													MesLanzamiento=0;
													break;
												}
												case 2: {
													strcpy(Mes[NDato],"Febrero");
													MesLanzamiento=0;
													break;
												}
												case 3: {
													strcpy(Mes[NDato],"Marzo");
													MesLanzamiento=0;
													break;
												}
												case 4: {
													strcpy(Mes[NDato],"Abril");
													MesLanzamiento=0;
													break;
												}
												case 5: {
													strcpy(Mes[NDato],"Mayo");
													MesLanzamiento=0;
													break;
												}
												case 6: {
													strcpy(Mes[NDato],"Junio");
													MesLanzamiento=0;
													break;
												}
												case 7: {
													strcpy(Mes[NDato],"Julio");
													MesLanzamiento=0;
													break;
												}
												case 8: {
													strcpy(Mes[NDato],"Agosto");
													MesLanzamiento=0;
													break;
												}
												case 9: {
													strcpy(Mes[NDato],"Septiembre");
													MesLanzamiento=0;
													break;
												}
												case 10: {
													strcpy(Mes[NDato],"Octubre");
													MesLanzamiento=0;
													break;
												}
												case 11: {
													strcpy(Mes[NDato],"Noviembre");
													MesLanzamiento=0;
													break;
												}
												case 12: {
													strcpy(Mes[NDato],"Diciembre");
													MesLanzamiento=0;
													break;
												}
												default: {
													printf("Mes no existente.");
													printf("\n\t\t\tMes de lanzamiento:\t");
													scanf("%u", &MesLanzamiento); LIMPIAR;
												}
											}
									}
								printf("\n\t\t\tAnyo de lanzamiento:\t");
								scanf("%u", &ALanzamiento[NDato]);
								printf("\n\n\tDesea ingresar otro dispositivo?\n");
								printf("\t---------------------\n");
								printf("\t|  1. Si  |  2. No  |\n");
								printf("\t---------------------\n");
								scanf("%d", &Leer);
								NDato++;
								}
								else{
									PAUSE;
									break;
								}
							}
						}
				}
				case OrdenarDatos:{
					CLEAR;

					break;
					}
				case ImprimirDatos:{
					if(HayDatos==Hay)
					{
						CLEAR;
						printf("\n----------------------------------------------------------------------------\n");
						printf("\n\t\t     Imprimiendo datos.\n\n");
						printf("----------------------------------------------------------------------------");

						for(int IDato=0; IDato<NDato; IDato++)
							{
								printf("\n\n\n\t\t\t   %s Dispositivo\n", NDispositivo[IDato]);
								printf("----------------------------------------------------------------------------\n");
								printf("  ESPECIFICACIONES DEL PRODUCTO\t|\t\t   DATOS\n\n");
								printf("--------------------------------+-------------------------------------------\n");
								printf("\tModelo\t\t\t|\t\t%s \n\n", Modelo[IDato]);
								printf("--------------------------------+-------------------------------------------\n");
								printf("\tMarca\t\t\t|\t\t%s \n\n", Marca[IDato]);
								printf("--------------------------------+-------------------------------------------\n");
								printf("\tResolucion\t\t|\t\t%s \n\n", Resolucion[IDato]);
								printf("--------------------------------+-------------------------------------------\n");
								printf("\tPeso\t\t\t|\t\t%1.2f \n\n", Peso[IDato]);
								printf("--------------------------------+-------------------------------------------\n");
								printf("\tGrosor\t\t\t|\t\t%s \n\n", Grosor[IDato]);
								printf("--------------------------------+-------------------------------------------\n");
								printf("\tColor\t\t\t|\t\t%s \n\n", Color[IDato]);
								printf("--------------------------------+-------------------------------------------\n");
								printf("\tFecha de lanzamiento\t|\t\t%u de %s / %u  \n\n", DiaLanzamiento[IDato], Mes[IDato], ALanzamiento[IDato]);
								printf("----------------------------------------------------------------------------\n\n\n");
							}
						PAUSE;
						break;
					}
					else{
						printf("\nNo hay datos para imprimir.\n");
						PAUSE;
						break;
					}
				}
					case Salir:{
						printf("Saliendo...\n");
						printf("Gracias.");
						return 0;
					}

					default: printf("Opcion incorrecta.\n");
					PAUSE;
				}
	}
}
