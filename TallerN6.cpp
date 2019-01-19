/*
--------------------------------------------------------------------------------
			TALLER N6
Autor: Cristian Rodriguez	1007794309
Fecha: 14 de Octubre del 2018
--------------------------------------------------------------------------------
*/
#include<string.h>
#include<stdlib.h>
#include<stdio.h>
#include<conio.h>
#include<ctype.h>
#include<windows.h>
using namespace std;
//Definicion de macros
#define CLEAR system("cls")
#define LONG 50
#define SHORT 10
#define ENTER 13
#define BORRAR 8
#define SPACE 32
#define FINCADENA '\n'
#define FINVECTOR '\0'
#define PAUSE system("pause")
#define ESPERAR(n) Sleep(n);
#define FAIL printf("\7");
#define SALTO printf("\n")
//Definidion de tipos
typedef enum {LeerDatos=1, OrdenarDatos, ImprimirDatos, Estadisticas, Salir} Opciones;
typedef enum {NoHay, Hay} ValidarDatos;
typedef enum {Seguir=1, NoSeguir} SeguirLeyendo;
typedef enum {Numeros, Letras, Alfanumerico} TDato;
typedef unsigned short int Usi;
typedef unsigned int Ui;
//Estructuras
typedef struct {
        Usi DiaLanzamiento;
        int MesLanzamiento;
        Ui ALanzamiento;
      } Fechas;
typedef struct {
        char Modelo[SHORT];
        char Marca[LONG];
        Usi Tipos_Pantalla;
        Usi Resoluciones;
        Usi TDT;
        float Peso;
        char Grosor[SHORT];
        char Color[SHORT];
        Fechas FechaLanzamiento;
      } Dispositivo;
//Definicion de constantes
const char *NDispositivo[]={"Primer","Segundo","Tercer","Cuarto","Quinto","Sexto","septimo","octavo","Noveno","Decimo",
      						"Undecimo","Duodecimo","Decimo tercero","Decimo cuarto","Decimo quinto","Decimo sexto","Decimo octavo","Decimo noveno","Vigesimo",
      						"Vigesimo primero","Vigesimo segundo","Vigesimo tercero","Vigesimo cuarto","Vigesimo quinto","Vigesimo sexto","Vigesimo septimo","Vigesimo octavo","Vigesimo noveno","Trigesimo"};
const char *Mes_es[]={"NoDisponible", "Enero", "Febrero", "Marzo", "Abril", "Mayo", "Junio", "Julio", "Agosto", "Septiembre", "Octubre",
      						"Noviembre", "Diciembre"};
const char *Tipo_Pantalla[]={"NoDisponible", "Plasma", "LCD", "LED", "OLED", "Otros"};
const char *Resolucion[]={"NoDisponible", "480pp", "720pp", "1080pp", "UHD", "4K", "Otros"};
const char *Tiene_Tdt[]={"NoDisponible", "Si", "No"};

//Funciones
/*
Nombre: B
Funcion: Imprime tantos guiones se necesiten para organizar la informacion guardada, a la hora de imprimirla.
*/
void BARRITAS(int q)
{
  for(int t=1; t<=q; t++){
      printf("-");}
      printf("\n");
}
/*
Nombre: Imprime_Titulos
Funcion: Imprime el titulo respectivo al proceso realizado
*/
void Imprime_Titulos(Opciones Opcion){
	switch (Opcion){
		case LeerDatos:{
			CLEAR; SALTO;
			BARRITAS(76);
			printf("\t\t     Ingrese los datos solicitados.\n\n");
			BARRITAS(76); SALTO;
			return;
		}
		case ImprimirDatos:{
			CLEAR; SALTO;
			BARRITAS(76);
			printf("\n\t\t     Imprimiendo datos.\n\n");
			BARRITAS(76); SALTO;
			return;
		}
		case Estadisticas:{
			CLEAR; SALTO;
			BARRITAS(76);
			printf("\t\t\t\tEstadisticas\n");
			BARRITAS(76); SALTO;
			return;
		}
	}
}
/*
Nombre: Menu
Funcion: Imprime el menu de opciones en pantalla y permite elegir lo que se desea ejecutar
*/
Opciones Menu(){
	Opciones Opcion;
	CLEAR; SALTO;
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
/*
Nombre: LeerTexto
Funcion: Permite leer cadenas caracter por caracter, permitiendo corregir y validar los carateres ingresados
*/
void LeerTexto(char Lectura[], TDato Tipo_Dato){
	Ui Car, NCARLeidos=0;
	while((Car=toupper(getche()))!=ENTER){
		switch(Tipo_Dato){
			case Numeros:{
				if(isdigit(Car)){
					if(Car==BORRAR){
							Lectura[NCARLeidos--]=toupper(Car);}
					else{Lectura[NCARLeidos++]=toupper(Car);}}
				else{FAIL
              break;}
      }
			case Letras:{
				if(isalpha(Car)||(Car==BORRAR)){
					if(Car==BORRAR){
							Lectura[NCARLeidos--]=toupper(Car);
              break;}
					else {Lectura[NCARLeidos++]=toupper(Car); break;}}
				else {FAIL
              break;}
			}
			case Alfanumerico:{
        if(isalnum(Car)){
  				if(Car==BORRAR){
  					Lectura[NCARLeidos--]=toupper(Car); break;}
  				else {Lectura[NCARLeidos++]=toupper(Car); break;}}
        else {FAIL
              break;}
			}
		}
	}
	if(Car==ENTER){
		Lectura[NCARLeidos++]=FINCADENA;
		Lectura[NCARLeidos]=FINVECTOR;
	printf("\n");}
}
/*
Nombre: LeerDatos
Funcion: Permite leer los datos de n dispositivos, otorgandole al usuario la desicion de elegir cuando desea parar de ingresar dispositivos
*/
Usi Leer_Datos(Dispositivo *Televisores, Usi EstResoluciones[], Usi EstTiposPantalla[], Usi EstTDT[], Usi NDato, Opciones Opcion, Usi *Orden){
	CLEAR;
  SeguirLeyendo Leer=Seguir;
  Usi N=0;
		while(N<NDato){
      Imprime_Titulos(Opcion=LeerDatos);
			if(N!=0){
				printf("\n\n\tDesea ingresar otro dispositivo?\n");
				printf("\t---------------------\n");
				printf("\t|  1. Si  |  2. No  |\n");
				printf("\t---------------------\n");
				scanf("%d", &Leer);
			}
			if(Leer==Seguir){
        if(N==NDato){
          printf("\n\n\tLimite de datos alcanzado.\n");
          PAUSE;
          return N;}
				Imprime_Titulos(Opcion=LeerDatos);
				printf("\n\n\t %s Dispositivo:\n\n", NDispositivo[N]);
				printf("\t\tModelo:\t");
				LeerTexto(Televisores[N].Modelo, Alfanumerico);
				printf("\n\t\tMarca:\t");
				LeerTexto(Televisores[N].Marca, Letras);
				printf("\n\t\tTipo de pantalla:\t\n");
				printf("\t-----------------------------------------------------------\n");
				printf("\t| 1. Plasma |  2. LCD  |  3. LED  |  4. OLED  |  5. Otros |\n");
				printf("\t-----------------------------------------------------------\n");
				printf("\n\t\tSeleccione el tipo de pantalla de su TV:\t");
				scanf("%u", &Televisores[N].Tipos_Pantalla);
				while((Televisores[N].Tipos_Pantalla<1)||(Televisores[N].Tipos_Pantalla>5)){
					printf("\n\tTipo de pantalla no valida.");
					printf("\n\t\tSeleccione el tipo de pantalla de su TV:\t");
					scanf("%u", &Televisores[N].Tipos_Pantalla);
				}
				EstTiposPantalla[Televisores[N].Tipos_Pantalla]++;
				printf("\n\t\tResolucion:\t\n");
				printf("----------------------------------------------------------------------------\n");
				printf("| 1. 480pp |  2. 720pp  |  3. 1080pp  |  4. Ultra HD  |  5. 4K |  6. Otros |\n");
				printf("----------------------------------------------------------------------------\n");
				printf("\n\t\tSeleccione la resolucion de su TV:\t");
				scanf("%u", &Televisores[N].Resoluciones);
				while((Televisores[N].Resoluciones<1)||(Televisores[N].Resoluciones>6)){
					printf("\n\tResolucion no valida.");
					printf("\n\t\tSeleccione la resolucion de su TV:\t");
					scanf("%u", &Televisores[N].Resoluciones);
				}
				EstResoluciones[Televisores[N].Resoluciones]++;
				printf("\n\t\tTelevision Digital Terrestre:\n");
				printf("\t---------------------\n");
				printf("\t|  1. Si  |  2. No  |\n");
				printf("\t---------------------\n");
				printf("\n\t\tSeleccione la opcion correcta para su TV:\t");
				scanf("%u", &Televisores[N].TDT);
				while((Televisores[N].TDT<1)||(Televisores[N].TDT>2)){
					printf("\n\tOpcion no valida.");
					printf("\n\t\tSeleccione una opcion correcta para su TV:\t");
					scanf("%u", &Televisores[N].TDT);
				}
				EstTDT[Televisores[N].TDT]++;
				printf("\n\t\tPeso(g):\t");
				scanf("%f", &Televisores[N].Peso);
				printf("\n\t\tGrosor(mm):\t");
				LeerTexto(Televisores[N].Grosor, Numeros);
				printf("\n\t\tColor:\t");
				LeerTexto(Televisores[N].Color, Letras);
				printf("\n\t\tMes de lanzamiento:\t");
				scanf("%d", &Televisores[N].FechaLanzamiento.MesLanzamiento);
				while((Televisores[N].FechaLanzamiento.MesLanzamiento<1)||(Televisores[N].FechaLanzamiento.MesLanzamiento>12)){
					printf("\n\tMes Invalido.");
					printf("\n\t\tMes de lanzamiento:\t");
					scanf("%d", &Televisores[N].FechaLanzamiento.MesLanzamiento);
				}
				printf("\n\t\tDia de lanzamiento:\t");
				scanf("%u", &Televisores[N].FechaLanzamiento.DiaLanzamiento);
				printf("\n\t\tAnyo de lanzamiento:\t");
				scanf("%u", &Televisores[N].FechaLanzamiento.ALanzamiento);
				while((Televisores[N].FechaLanzamiento.ALanzamiento<2008)||(Televisores[N].FechaLanzamiento.ALanzamiento>2018)){
					printf("\n\tERROR: En el anyo ingresado, aun no se comercializaban los TV.");
					printf("\n\t\tAnyo de lanzamiento:\t");
					scanf("%u", &Televisores[N].FechaLanzamiento.ALanzamiento);
				}
				N++;
				CLEAR;
			}
			else{return N;}
	}
  if(N==NDato){
    printf("\n\n\tLectura finalizada.\n");
    PAUSE;
    return N;}
}
/*
Nombre: Ordenar_Datos
Funcion: Ordena en orden alfabetico los dispositivos ingresados con respecto a su modelo
*/
void Ordenar_Datos(Usi AuxOrden, Usi *Orden, Dispositivo *Televisores, Usi NDato){
	printf("\n\t\tOrdenando Datos");
	ESPERAR(1000); printf(".");	ESPERAR(1500); printf(".");	ESPERAR(2000); printf("."); SALTO;
	for(int i=0; i<(NDato-1); i++)
		for(int j=i+1; j<(NDato); j++)
				if(strcmp(strupr(Televisores[i].Modelo), strupr(Televisores[j].Modelo))){
					AuxOrden=Orden[i];
					Orden[i]=Orden[j];
					Orden[j]=AuxOrden;
				}
}
/*
Nombre: Imprime_Datos
Funcion: Imprime los datos de los dispositivos ingresados, con un lapso de 2 seg cada uno.
*/
void Imprimir_Datos(Dispositivo *Televisores, Usi *Orden, Usi NDato, Opciones Opcion){
  CLEAR;
	Imprime_Titulos(Opcion=ImprimirDatos);
	for(Usi IDato=0; IDato<NDato; IDato++){
			printf("\n\n\n\t\t\t   %s Dispositivo\n", NDispositivo[IDato]);
			BARRITAS(76);
			printf("  ESPECIFICACIONES DEL PRODUCTO\t|\t\t   DATOS\n\n");
			BARRITAS(76);
			printf("\tModelo\t\t\t|\t\t%s \n\n", Televisores[Orden[IDato]].Modelo);
			BARRITAS(76);
			printf("\tMarca\t\t\t|\t\t%s \n\n", Televisores[Orden[IDato]].Marca);
			BARRITAS(76);
			printf("\tPantalla\t\t|\t\t%s \n\n", Tipo_Pantalla[Televisores[Orden[IDato]].Tipos_Pantalla]);
		  BARRITAS(76);
			printf("\tResolucion\t\t|\t\t%s \n\n", Resolucion[Televisores[Orden[IDato]].Resoluciones]);
			BARRITAS(76);
			printf("\tTDT\t\t\t|\t\t%s \n\n", Tiene_Tdt[Televisores[Orden[IDato]].TDT]);
			BARRITAS(76);
			printf("\tPeso\t\t\t|\t\t%1.2f \n\n", Televisores[Orden[IDato]].Peso);
			BARRITAS(76);
			printf("\tGrosor\t\t\t|\t\t%s \n\n", Televisores[Orden[IDato]].Grosor);
			BARRITAS(76);
			printf("\tColor\t\t\t|\t\t%s \n\n", Televisores[Orden[IDato]].Color);
			BARRITAS(76);
			printf("\tFecha de lanzamiento\t|\t\t%u de %s / %u  \n\n", Televisores[Orden[IDato]].FechaLanzamiento.DiaLanzamiento,
                                                                 Mes_es[Televisores[Orden[IDato]].FechaLanzamiento.MesLanzamiento],
                                                                 Televisores[Orden[IDato]].FechaLanzamiento.ALanzamiento);
			BARRITAS(76);
			ESPERAR(1000);}
	return;
}
/*
Nombre: Imprimir_Estadisticas
Funcion: Imprime las estadisticas de los dispositvos ingresados( los que tienen TDT, las resoluciones y los tipos de pantallla)
*/
void Imprimir_Estadisticas(Usi EstTDT[3], Usi EstTiposPantalla[6], Usi EstResoluciones[7], Opciones Opcion){
	Imprime_Titulos(Opcion=Estadisticas);
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
}
main(){
	system("mode con: cols=76 lines=300");
  system ("color 0B");
	Dispositivo *Televisores;
	Usi *Orden;
  Usi AuxOrden=0;
	Usi EstResoluciones[7];
		for(int q=0; q<=7; q++){
                EstResoluciones[q]=0;}
	Usi EstTiposPantalla[6];
		for(int q=0; q<=6; q++){
                EstTiposPantalla[q]=0;}
	Usi EstTDT[3];
	    for(int q=0; q<=3; q++){
                EstTDT[q]=0;}
	Usi NDato=0;
	SeguirLeyendo Leer=Seguir;
	ValidarDatos HayDatos=NoHay;
	Opciones Opcion=ImprimirDatos;

	while (Opcion!=Salir){
		CLEAR;
		switch(Menu()){
				case LeerDatos:{
          if(NDato){
            printf("\n\t\tYa hay datos guardados.\n");
            break;
            }
          else {
            printf("\n\t\tCuantos televisores desea ingresar?\t\t");
            scanf("%u", &NDato);
            Televisores=(Dispositivo *)malloc(sizeof(Dispositivo)*NDato);
            Orden=(Usi *)malloc(sizeof(Usi)*NDato);
            for(int r=0; r<NDato; r++){
                        Orden[r]=r;}
            HayDatos=Hay;
            NDato=Leer_Datos(Televisores, EstResoluciones, EstTiposPantalla, EstTDT, NDato, Opcion, Orden);
            break;
          }
				}
				case OrdenarDatos:{
					if((HayDatos==Hay)&&(NDato>1)){
					Ordenar_Datos(AuxOrden, Orden, Televisores, NDato);
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
							Imprimir_Datos(Televisores, Orden, NDato, Opcion);
              PAUSE;
							break;
            }
				else{
					printf("\n\t\tNo hay datos para imprimir.\n\n");
					PAUSE;
					break;
				}
			}
					case Estadisticas:{
            if(HayDatos==Hay){
              CLEAR;
						  Imprimir_Estadisticas(EstTDT, EstTiposPantalla, EstResoluciones, Opcion);
              PAUSE;
  						break;
            }
            else{
              printf("\n\t\tNo hay datos para imprimir.\n\n");
              PAUSE;
              break;
            }
					}
					case Salir:{
						printf("\n\t\tSaliendo...\n");
						ESPERAR(2000);
						printf("\t\tGracias.\n");
            free(Televisores);
            free(Orden);
						return 0;
					}
					default: printf("\n\t\tOpcion incorrecta.\n");
					PAUSE;
				}
	}
}
