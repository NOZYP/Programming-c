/*
--------------------------------------------------------------------------------
			TALLER N3
Autores: Cristian Rodriguez	1007794309
		 Johan Taborda 		1225092815
Fecha: 16 de Septiembre del 2018
--------------------------------------------------------------------------------
*/
#include<string.h>
#include<stdlib.h>
#include<stdio.h>
#include<ctype.h>
#include<windows.h>
using namespace std;
//Definidion de tipos
typedef enum {LeerDatos=1, OrdenarDatos, ImprimirDatos, Estadisticas, Salir} Opciones;
typedef enum {NoHay, Hay} ValidarDatos;
typedef enum {NoEstanOrdenados, EstanOrdenados} ValidarOrden;
typedef enum {Seguir=1, NoSeguir} SeguirLeyendo;
typedef unsigned short int Usi;
//Definicion de constantes
const char *NDispositivo[]={"Primer","Segundo","Tercer","Cuarto","Quinto","Sexto","septimo","octavo","Noveno","Decimo",
						"Undecimo","Duodecimo","Decimo tercero","Decimo cuarto","Decimo quinto","Decimo sexto","Decimo octavo","Decimo noveno","Vigesimo",
						"Vigesimo primero","Vigesimo segundo","Vigesimo tercero","Vigesimo cuarto","Vigesimo quinto","Vigesimo sexto","Vigesimo septimo","Vigesimo octavo","Vigesimo noveno","Trigesimo"};
const char *Mes_es[]={"NoDisponible", "Enero", "Febrero", "Mayo", "Marzo", "Abril", "Mayo", "Junio", "Julio", "Agosto", "Septiembre", "Octubre",
						"Noviembre", "Diciembre"};
const char *Tipo_Pantalla[]={"NoDisponible", "Plasma", "LCD", "LED", "OLED", "Otros"};
const char *Resolucion[]={"NoDisponible", "480pp", "720pp", "1080pp", "UHD", "4K", "Otros"};
const char *Tiene_Tdt[]={"NoDisponible", "Si", "No"};
//Definicion de macros
#define CLEAR system("cls")
#define LONG 50
#define SHORT 10
#define LIMPIAR fflush(stdin);
#define PAUSE system("pause")
#define LIMITEDATOS 30
#define ESPERAR(n) Sleep(n);

Opciones Menu();
void Leer_Datos(char Marca[LIMITEDATOS][LONG], char Color[LIMITEDATOS][SHORT],
char Modelo[LIMITEDATOS][SHORT], char Grosor[LIMITEDATOS][SHORT], char Mes[LIMITEDATOS][SHORT],
Usi Orden[LIMITEDATOS], Usi AuxOrden, Usi EstResoluciones[7],
Usi EstTiposPantalla[6], Usi EstTDT[3], Usi MesLanzamiento[LIMITEDATOS], Usi ALanzamiento[LIMITEDATOS],
Usi Resoluciones[LIMITEDATOS], Usi DiaLanzamiento[LIMITEDATOS], Usi TDT[LIMITEDATOS],
Usi Tipos_Pantalla[LIMITEDATOS], Usi NDato, SeguirLeyendo Leer, float Peso[LIMITEDATOS]);

main()
{
	char Marca[LIMITEDATOS][LONG], Color[LIMITEDATOS][SHORT];
	char Modelo[LIMITEDATOS][SHORT], Grosor[LIMITEDATOS][SHORT], Mes[LIMITEDATOS][SHORT];
	Usi Orden[LIMITEDATOS], AuxOrden=0;
	Usi EstResoluciones[]={0, 0, 0, 0, 0, 0, 0};
	Usi EstTiposPantalla[]={0, 0, 0, 0, 0, 0};
	Usi EstTDT[]={0, 0, 0};
	Usi MesLanzamiento[LIMITEDATOS], ALanzamiento[LIMITEDATOS], Resoluciones[LIMITEDATOS];
	Usi DiaLanzamiento[LIMITEDATOS], TDT[LIMITEDATOS], Tipos_Pantalla[LIMITEDATOS];
	Usi NDato=0, IDato=0;
	SeguirLeyendo Leer=Seguir;
	ValidarDatos HayDatos=NoHay;
	ValidarOrden Ordenados=NoEstanOrdenados;
	system("mode con: cols=76 lines=300");
	Opciones Opcion=ImprimirDatos;
	float Peso[LIMITEDATOS];
	for(int w=0; w<LIMITEDATOS; w++){
		Orden[w]=w;
	}
	while (Opcion!=Salir){
		CLEAR;
		switch(Menu())
			{
				case LeerDatos:{
					Leer=Seguir;
					HayDatos=Hay;
					Ordenados=NoEstanOrdenados;
					Leer_Datos(Marca, Color, Modelo, Grosor, Mes, Orden, AuxOrden, EstResoluciones, EstTiposPantalla, EstTDT, MesLanzamiento, ALanzamiento, Resoluciones, DiaLanzamiento, TDT, Tipos_Pantalla, NDato, Leer, Peso);
					break;
				}
				case OrdenarDatos:{
					if((HayDatos==Hay)&&(NDato>1)){
					Ordenados=EstanOrdenados;
					printf("\n\t\tOrdenando Datos"); ESPERAR(1000);
					printf(".");	ESPERAR(2000);
					printf(".");	ESPERAR(3000);
					printf(".\n");
					for(int i=0; i<=(NDato-2); i++){
						for(int j=1; j<=(NDato-1); j++){
							for(int k=0; k<SHORT; k++){
								if(toupper(Modelo[i][k])<toupper(Modelo[j][k]))
								{
									AuxOrden=Orden[i];
									Orden[i]=Orden[j];
									Orden[j]=AuxOrden;
									k=SHORT;
								}
							}
						}
					}
					break;
					}
					else{
						printf("\n\t\tNo hay datos para ordenar.\n");
						PAUSE;
						break;
					}
				}
				case ImprimirDatos:{
					if(HayDatos==Hay){
						if((Ordenados==EstanOrdenados)||(NDato==1)){
							CLEAR;
							printf("\n----------------------------------------------------------------------------\n");
							printf("\n\t\t     Imprimiendo datos.\n\n");
							printf("----------------------------------------------------------------------------");
							for(IDato=0; IDato<NDato; IDato++)
								{
									printf("\n\n\n\t\t\t   %s Dispositivo\n", NDispositivo[IDato]);
									printf("----------------------------------------------------------------------------\n");
									printf("  ESPECIFICACIONES DEL PRODUCTO\t|\t\t   DATOS\n\n");
									printf("--------------------------------+-------------------------------------------\n");
									printf("\tModelo\t\t\t|\t\t%s \n\n", Modelo[Orden[IDato]]);
									printf("--------------------------------+-------------------------------------------\n");
									printf("\tMarca\t\t\t|\t\t%s \n\n", Marca[Orden[IDato]]);
									printf("--------------------------------+-------------------------------------------\n");
									printf("\tPantalla\t\t|\t\t%s \n\n", Tipo_Pantalla[Tipos_Pantalla[Orden[IDato]]]);
									printf("--------------------------------+-------------------------------------------\n");
									printf("\tResolucion\t\t|\t\t%s \n\n", Resolucion[Resoluciones[Orden[IDato]]]);
									printf("--------------------------------+-------------------------------------------\n");
									printf("\tTDT\t\t\t|\t\t%s \n\n", Tiene_Tdt[TDT[Orden[IDato]]]);
									printf("--------------------------------+-------------------------------------------\n");
									printf("\tPeso\t\t\t|\t\t%1.2f \n\n", Peso[Orden[IDato]]);
									printf("--------------------------------+-------------------------------------------\n");
									printf("\tGrosor\t\t\t|\t\t%s \n\n", Grosor[Orden[IDato]]);
									printf("--------------------------------+-------------------------------------------\n");
									printf("\tColor\t\t\t|\t\t%s \n\n", Color[Orden[IDato]]);
									printf("--------------------------------+-------------------------------------------\n");
									printf("\tFecha de lanzamiento\t|\t\t%u de %s / %u  \n\n", DiaLanzamiento[Orden[IDato]],  Mes_es[MesLanzamiento[Orden[IDato]]], ALanzamiento[Orden[IDato]]);
									printf("----------------------------------------------------------------------------\n\n\n");
									ESPERAR(2000);
								}
								PAUSE;
								break;
						}
						else{
							printf("\n\t\tLos datos aun no han sido ordenados.\n\n");
							PAUSE;
							break;
						}
				}
				else{
					printf("\n\t\tNo hay datos para imprimir.\n\n");
					PAUSE;
					break;
				}
			}
					case Estadisticas:{
						CLEAR;
						printf("\n----------------------------------------------------------------------------\n");
						printf("\t\t\t\tEstadisticas\n");
						printf("\n----------------------------------------------------------------------------\n\n");
						printf("\tEstadisticas TDT\n\n");
						for(int l=1; l<=2; l++){
							printf("\t\t%s\t\t", Tiene_Tdt[l]);
							printf("%u\n\n", EstTDT[l]);
						}
						printf("\n\tEstadisticas tipos de pantalla\n\n");
						for(int p=1; p<=5; p++){
							printf("\t\t%s\t\t", Tipo_Pantalla[p]);
							printf("%u\n\n", EstTiposPantalla[p]);
						}
						printf("\n\tEstadisticas resoluciones\n\n");
						for(int u=1; u<=6; u++){
							printf("\t\t%s\t\t", Resolucion[u]);
							printf("%u\n\n", EstResoluciones[u]);
						}
						PAUSE;
						break;
					}
					case Salir:{
						printf("\n\t\tSaliendo...\n");
						ESPERAR(2000);
						printf("\t\tGracias.\n");
						return 0;
					}
					default: printf("\n\t\tOpcion incorrecta.\n");
					PAUSE;
				}
	}
}
Opciones Menu(){
	Opciones Opcion;
	CLEAR;
	printf("\t\t       +-----------------------+\n");
	printf("\t\t       |          MENU         |\n");
	printf("\t\t       +-----------------------+\n");
	printf("\t\t       |    1. Leer Datos      |\n");
	printf("\t\t       +-----------------------+\n");
	printf("\t\t       |    2. Ordenar Datos   |\n");
	printf("\t\t       +-----------------------+\n");
	printf("\t\t       |    3. Imprimir Datos  |\n");
	printf("\t\t       +-----------------------+\n");
	printf("\t\t       |    4. Estadisticas    |\n");
	printf("\t\t       +-----------------------+\n");
	printf("\t\t       |    5. Salir           |\n");
	printf("\t\t       +-----------------------+\n");
	printf("\t\t  Que deseas hacer?\t\t  ");
	scanf("%d", &Opcion);
	return Opcion;
}

void Leer_Datos(char Marca[LIMITEDATOS][LONG], char Color[LIMITEDATOS][SHORT],
char Modelo[LIMITEDATOS][SHORT], char Grosor[LIMITEDATOS][SHORT], char Mes[LIMITEDATOS][SHORT],
Usi Orden[LIMITEDATOS], Usi AuxOrden, Usi EstResoluciones[7],
Usi EstTiposPantalla[6], Usi EstTDT[3], Usi MesLanzamiento[LIMITEDATOS], Usi ALanzamiento[LIMITEDATOS],
Usi Resoluciones[LIMITEDATOS], Usi DiaLanzamiento[LIMITEDATOS], Usi TDT[LIMITEDATOS],
Usi Tipos_Pantalla[LIMITEDATOS], Usi NDato, SeguirLeyendo Leer, float Peso[LIMITEDATOS]){
	CLEAR;
	if(NDato==LIMITEDATOS){
		printf("\n\t\tHaz alcanzado el limite de dispositivos...\n\n");
		PAUSE;
		return;
	}
		while(NDato<LIMITEDATOS){
			printf("\n----------------------------------------------------------------------------\n");
			printf("\t\t     Ingrese los datos solicitados.\n\n");
			printf("----------------------------------------------------------------------------\n\n");
			if(NDato!=0){
				printf("\n\n\tDesea ingresar otro dispositivo?\n");
				printf("\t---------------------\n");
				printf("\t|  1. Si  |  2. No  |\n");
				printf("\t---------------------\n");
				scanf("%d", &Leer);
			}
			if(Leer==Seguir){
				printf("\n\n\t %s Dispositivo:\n\n", NDispositivo[NDato]);
				printf("\t\tModelo:\t");
				scanf("%s", &Modelo[NDato]); LIMPIAR;
				printf("\n\t\tMarca:\t");
				scanf("%s", &Marca[NDato]); LIMPIAR;
				printf("\n\t\tTipo de pantalla:\t\n");
				printf("\t-----------------------------------------------------------\n");
				printf("\t| 1. Plasma |  2. LCD  |  3. LED  |  4. OLED  |  5. Otros |\n");
				printf("\t-----------------------------------------------------------\n");
				printf("\n\t\tSeleccione el tipo de pantalla de su TV:\t");
				scanf("%u", &Tipos_Pantalla[NDato]); LIMPIAR;
				while((Tipos_Pantalla[NDato]<1)||(Tipos_Pantalla[NDato]>5)){
					printf("\n\tTipo de pantalla no valida.");
					printf("\n\t\tSeleccione el tipo de pantalla de su TV:\t");
					scanf("%u", &Tipos_Pantalla[NDato]); LIMPIAR;
				}
				EstTiposPantalla[Tipos_Pantalla[NDato]]++;
				printf("\n\t\tResolucion:\t\n");
				printf("----------------------------------------------------------------------------\n");
				printf("| 1. 480pp |  2. 720pp  |  3. 1080pp  |  4. Ultra HD  |  5. 4K |  6. Otros |\n");
				printf("----------------------------------------------------------------------------\n");
				printf("\n\t\tSeleccione la resolucion de su TV:\t");
				scanf("%u", &Resoluciones[NDato]); LIMPIAR;
				while((Resoluciones[NDato]<1)||(Resoluciones[NDato]>6)){
					printf("\n\tResolucion no valida.");
					printf("\n\t\tSeleccione la resolucion de su TV:\t");
					scanf("%u", &Resoluciones[NDato]); LIMPIAR;
				}
				EstResoluciones[Resoluciones[NDato]]++;
				printf("\n\t\tTelevision Digital Terrestre:\n");
				printf("\t---------------------\n");
				printf("\t|  1. Si  |  2. No  |\n");
				printf("\t---------------------\n");
				printf("\n\t\tSeleccione la opcion correcta para su TV:\t");
				scanf("%u", &TDT[NDato]);
				while((TDT[NDato]<1)||(TDT[NDato]>2)){
					printf("\n\tOpcion no valida.");
					printf("\n\t\tSeleccione una opcion correcta para su TV:\t");
					scanf("%u", &TDT[NDato]); LIMPIAR;
				}
				EstTDT[TDT[NDato]]++;
				printf("\n\t\tPeso(g):\t");
				scanf("%f", &Peso[NDato]);
				printf("\n\t\tGrosor(mm):\t");
				scanf("%s", &Grosor[NDato]); LIMPIAR;
				printf("\n\t\tColor:\t");
				scanf("%s", &Color[NDato]); LIMPIAR;
				printf("\n\t\tDia de lanzamiento:\t");
				scanf("%u", &DiaLanzamiento[NDato]); LIMPIAR;
				printf("\n\t\tMes de lanzamiento:\t");
				scanf("%u", &MesLanzamiento[NDato]); LIMPIAR;
				while((MesLanzamiento[NDato]<1)||(MesLanzamiento[NDato]>12)){
					printf("\n\tMes Invalido.");
					printf("\n\t\tMes de lanzamiento:\t");
					scanf("%u", &MesLanzamiento[NDato]); LIMPIAR;
				}
				printf("\n\t\tAnyo de lanzamiento:\t");
				scanf("%u", &ALanzamiento[NDato]); LIMPIAR;
				while((ALanzamiento[NDato]<2010)||(ALanzamiento[NDato]>2018)){
					printf("\n\tERROR: En el anyo ingresado, aun no se comercializaban los TV.");
					printf("\n\t\tAnyo de lanzamiento:\t");
					scanf("%u", &ALanzamiento[NDato]); LIMPIAR;
				}
				NDato++;
				CLEAR;
			}
			else{
				return;
			}
	}
	return;
}
