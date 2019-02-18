/*--------------------------------------------------------------------------------
            TALLER N7
   Autor: Cristian Rodriguez	1007794309
   Fecha: 3 de Febrero del 2019
--------------------------------------------------------------------------------*/
#include <conio.h>
#include <ctype.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <windows.h>
#include <iostream>
#include <cstdlib>
using namespace std;
// Definicion de macros
#define CLEAR system("cls")
#define ANYOSIG 2020
#define LONG 50
#define SHORT 10
#define ENTER 13
#define BORRAR 8
#define SPACE 32
#define FINCADENA '\n'
#define FINVECTOR '\0'
#define PAUSE system("pause")
#define ESPERAR(n) Sleep(n);
#define FAIL printf("\7")
#define SALTO printf("\n")
// Definidion de tipos
typedef enum { LeerDatos = 1, ImprimirDatos, Estadisticas, Salir } Opciones;
typedef enum { Seguir = 1, NoSeguir } SeguirLeyendo;
typedef enum { Letras, Alfanumerico } TDato;
typedef enum { Mayor_Menor = 1, Menor_Mayor } Tipo_orden;
typedef enum { NoDisponible, Enero, Febrero, Marzo, Abril, Mayo, Junio,
  Julio, Agosto, Septiembre, Octubre, Noviembre, Diciembre} Meses;
enum Resolu { Nd1, H, HD, FHD, UHD, Otrs, NResoluciones }; //Nd == NoDisponible
enum Tdt { Nd2, Si, No, Ntdt };
enum Panta { Nd3, Plasma, LCD, LED, OLED, Otros, Ntpanta };
typedef unsigned short int Usi;
typedef unsigned int Ui;
// Estructuras
typedef struct {
  Ui ALanzamiento;
  Ui DiaLanzamiento;
  Meses MesLanzamiento;} Fechas;
typedef struct{
  Usi *EstResoluciones = NULL;
  Usi *EstTiposPantalla = NULL;
  Usi *EstTDT = NULL;} EstDatos;
struct Dispositivo {
  char *Modelo=NULL;
  char *Marca=NULL;
  Ui Tipos_Pantalla;
  Ui Resoluciones;
  Ui TDT;
  float Peso;
  float Grosor;
  int NRegistro;
  Fechas FechaLanzamiento;
  Dispositivo *Sgte = NULL;};
typedef struct {
  Dispositivo *Televisores=NULL;
  int NDato;
}SAVE_SHIT;
// Definicion de constantes
const char *Mes_es[] = {"NoDisponible", "Enero",      "Febrero", "Marzo",
                        "Abril",        "Mayo",       "Junio",   "Julio",
                        "Agosto",       "Septiembre", "Octubre", "Noviembre",
                        "Diciembre"};
const char *Tipo_Pantalla[] = {"NoDisponible", "Plasma", "LCD",
                               "LED",          "OLED", "Otros"};
const char *Resolucion[] = {"NoDisponible", "480pp", "720pp",
                            "1080pp",       "UHD",   "Otros"};
const char *Tiene_Tdt[] = {"NoDisponible", "Si", "No"};

// Funciones

/*void gotoxy(int x,int y){
     HANDLE hcon;
     hcon = GetStdHandle(STD_OUTPUT_HANDLE);
     COORD dwPos;
     dwPos.X = x;
     dwPos.Y= y;
     SetConsoleCursorPosition(hcon,dwPos);}*/

/*Nombre: hide
Funcion: Pone invisible el cursor*/
void hide() {
  HANDLE consoleHandle = GetStdHandle(STD_OUTPUT_HANDLE);
  CONSOLE_CURSOR_INFO info;
  info.dwSize = 1;
  info.bVisible = FALSE;
  SetConsoleCursorInfo(consoleHandle, &info);
}
/*Nombre: Barritas
   Funcion: Imprime tantos guiones se necesiten para organizar la informacion
   guardada, a la hora de imprimirla.*/
void BARRITAS(int q) {
  for (int t = 1; t <= q; t++) {
    printf("-");
  }
  printf("\n");
}
/*Nombre: Imprime_Titulos
   Funcion: Imprime el titulo respectivo al proceso realizado*/
void Imprime_Titulos(Opciones Opcion) {
  switch (Opcion) {
  case LeerDatos: {
    SALTO;
    BARRITAS(76);
    SALTO;
    printf("\t\t     Ingrese los datos solicitados.\n\n");
    BARRITAS(76);
    SALTO;
    break;
  }
  case ImprimirDatos: {
    SALTO;
    BARRITAS(76);SALTO;
    printf("\n\t\t     Imprimiendo datos.\n\n");
    BARRITAS(76);
    SALTO;
    break;
  }
  case Estadisticas: {
    SALTO;
    BARRITAS(76);SALTO;
    printf("\t\t\t\tEstadisticas\n");
    BARRITAS(76);
    SALTO;
    break;
  }
  case Salir:
    break;
  }
}
/* Nombre: Menu
   Funcion: Imprime el menu de opciones en pantalla y permite elegir lo que se
   desea ejecutar
 */
Opciones Menu() {
  CLEAR;
  SALTO;
  Opciones Opcion;
  printf("\t\t       +-----------------------+\n");
  printf("\t\t       |          MENU         |\n");
  printf("\t\t       +-----------------------+\n");
  printf("\t\t       |    1. Leer Datos      |\n");
  printf("\t\t       +-----------------------+\n");
  printf("\t\t       |    2. Imprimir Datos  |\n");
  printf("\t\t       +-----------------------+\n");
  printf("\t\t       |    3. Estadisticas    |\n");
  printf("\t\t       +-----------------------+\n");
  printf("\t\t       |    4. Salir           |\n");
  printf("\t\t       +-----------------------+\n");
  printf("\t\t  Que deseas hacer?\t\t  ");
  scanf("%d", &Opcion);
  if (Opcion < 1 || Opcion > 5) {
    printf("\n\tOpcion no valida.");
    printf("\n\t\tSeleccione una opcion valida:\t");
    scanf("%d", &Opcion);
  }
  return Opcion;
}
/*
   Nombre: LeerTexto
   Funcion: Permite leer cadenas caracter por caracter, permitiendo corregir y
   validar los carateres ingresados
 */
int LeerTexto(char *Lectura, TDato Tipo_Dato) {
  Ui Car, NCARLeidos = 0;
  while ((Car = toupper(getche())) != ENTER) {
    switch (Tipo_Dato) {
      case Letras: {
        if (Car == BORRAR) {
          Lectura[NCARLeidos--] = Car;
          break;}
        if (isalpha(Car)) {
            Lectura[NCARLeidos++] = Car;
            break;}else {
                    FAIL;
                    break;}}
      case Alfanumerico: {
        if (Car == BORRAR) {
          Lectura[NCARLeidos--] = Car;
          break;}
        if (isalnum(Car)) {
            Lectura[NCARLeidos++] = Car;
            break;} else {
                      FAIL;
                      break;}}
    }}
  if (Car == ENTER) {
    Lectura[NCARLeidos++] = FINCADENA;
    Lectura[NCARLeidos] = FINVECTOR;
  }
  return NCARLeidos;
}
/*
   Nombre: DestruirNodos
   Funcion: Permite liberar los espacios de memoria usados por nodos temporales
 */
void DestruirNodos(Dispositivo *ViejoE) { free(ViejoE); }
/*
   Nombre: LeerDatos
   Funcion: Permite leer los datos de n dispositivos, otorgandole al usuario la
   desicion de elegir cuando desea parar de ingresar dispositivos
 */
SAVE_SHIT Leer_Datos(SAVE_SHIT Shit, EstDatos Estadisticas) {
  CLEAR;
  Dispositivo *Puntero=NULL;
  char Linea[100];
  SeguirLeyendo Leer = Seguir;
  Usi N = 0;
  while (Leer == Seguir) {
    CLEAR;
    Imprime_Titulos(LeerDatos);
    if (N != 0) {
      printf("\n\n\tDesea ingresar otro dispositivo?\n");
      printf("\t---------------------\n");
      printf("\t|  1. Si     2. No  |\n");
      printf("\t---------------------\n");
      scanf("%d", &Leer);
      while (Leer < 1 || Leer > 2) {
        printf("\n\tOpcion no valida.");
        printf("\n\t\tSeleccione una opcion valida:\t");
        scanf("%d", &Leer);}
      CLEAR;}
    if (Leer == NoSeguir) { return Shit;}
    else { CLEAR; Imprime_Titulos(LeerDatos); }
    Dispositivo *NuevoE = (Dispositivo *)malloc(sizeof(Dispositivo));
    Shit.NDato++; N++;
    NuevoE->NRegistro = Shit.NDato;
    BARRITAS(76);
    printf("\tNumero de registro:\t\t \t\t %3d\n", NuevoE->NRegistro);
    BARRITAS(76);
    SALTO; SALTO;
    printf("\t\tModelo:\t");
    strcpy((NuevoE->Modelo = (char *) malloc(LeerTexto(Linea, Alfanumerico) * sizeof(char))), Linea);
    SALTO;
    printf("\n\t\tMarca:\t");
    strcpy((NuevoE->Marca =  (char *) malloc(LeerTexto(Linea, Letras) * sizeof(char))), Linea);
    SALTO;
    printf("\n\t\tTipo de pantalla:\t\n");
    BARRITAS(76);
    for(int i=1; i<Ntpanta; i++){printf(" %d. %s \t", i, Tipo_Pantalla[i]);}
    SALTO;
    BARRITAS(76);
    printf("\n\t\tSeleccione el tipo de pantalla de su TV:\t");
    scanf("%u", &NuevoE->Tipos_Pantalla);
    while ((NuevoE->Tipos_Pantalla < 1) || (NuevoE->Tipos_Pantalla > (Ntpanta-1))) {
      printf("\n\tTipo de pantalla no valida.");
      printf("\n\t\tSeleccione el tipo de pantalla de su TV:\t");
      scanf("%u", &NuevoE->Tipos_Pantalla);}
    Estadisticas.EstTiposPantalla[NuevoE->Tipos_Pantalla]++;
    printf("\n\t\tResolucion:\t\n");
    BARRITAS(76);
    for(int i=1; i<NResoluciones; i++){ printf(" %d. %s \t", i, Resolucion[i]);}
    SALTO;
    BARRITAS(76);
    printf("\n\t\tSeleccione la resolucion de su TV:\t");
    scanf("%u", &NuevoE->Resoluciones);
    while ((NuevoE->Resoluciones < 1) || (NuevoE->Resoluciones > (NResoluciones-1))) {
      printf("\n\tResolucion no valida.");
      printf("\n\t\tSeleccione la resolucion de su TV:\t");
      scanf("%u", &NuevoE->Resoluciones);}
    Estadisticas.EstResoluciones[NuevoE->Resoluciones]++;
    printf("\n\t\tTelevision Digital Terrestre:\n");
    BARRITAS(76);
    for (int i = 1; i < Ntdt; i++) {printf("\t\t %d. %s \t\t", i, Tiene_Tdt[i]);}
    SALTO;
    BARRITAS(76);
    printf("\n\t\tSeleccione la opcion correcta para su TV:\t");
    scanf("%u", &NuevoE->TDT);
    while ((NuevoE->TDT < 1) || (NuevoE->TDT > (Ntdt-1))) {
      printf("\n\tOpcion no valida.");
      printf("\n\t\tSeleccione una opcion correcta para su TV:\t");
      scanf("%u", &NuevoE->TDT);}
    Estadisticas.EstTDT[NuevoE->TDT]++;
    printf("\n\t\tPeso(g):\t");
    scanf("%f", &NuevoE->Peso);
    printf("\n\t\tGrosor(mm):\t");
    scanf("%f", &NuevoE->Grosor);
    printf("\n\t\tMes de lanzamiento:\t");
    scanf("%d", &NuevoE->FechaLanzamiento.MesLanzamiento);
    while ((NuevoE->FechaLanzamiento.MesLanzamiento < 1) ||
           (NuevoE->FechaLanzamiento.MesLanzamiento > 12)){
      printf("\n\tMes Invalido.");
      printf("\n\t\tMes de lanzamiento:\t");
      scanf("%d", &NuevoE->FechaLanzamiento.MesLanzamiento);}
    printf("\n\t\tDia de lanzamiento:\t");
    scanf("%u", &NuevoE->FechaLanzamiento.DiaLanzamiento);
    printf("\n\t\tAnyo de lanzamiento:\t");
    scanf("%u", &NuevoE->FechaLanzamiento.ALanzamiento);
    while (NuevoE->FechaLanzamiento.ALanzamiento > ANYOSIG) {
      printf("\n\tERROR: Anyo invalido.");
      printf("\n\t\tAnyo de lanzamiento:\t");
      scanf("%u", &NuevoE->FechaLanzamiento.ALanzamiento);}
    NuevoE->Sgte = NULL;
    if (Shit.Televisores == NULL) {Shit.Televisores = NuevoE;}
    else {
      Puntero = Shit.Televisores;
      while(Puntero->Sgte!=NULL) {Puntero = Puntero->Sgte;}
      Puntero->Sgte=NuevoE;
      }
    CLEAR;}
  return Shit;
}
/*
   Nombre: Imprime_Datos
   Funcion: Imprime los datos de los dispositivos ingresados, con un lapso de 2
   seg cada uno.
 */
void Imprimir_Datos(Dispositivo *Televisores) {
  CLEAR;
  Dispositivo *Puntero_2 = Televisores;
  Imprime_Titulos(ImprimirDatos);
  BARRITAS(76);SALTO;
  printf("  ESPECIFICACIONES DEL PRODUCTO\t\t \t\tDATOS\n\n");
  BARRITAS(76);SALTO;SALTO;
  do{
    BARRITAS(76);SALTO;
    printf("\tNumero de registro:\t\t \t%d\n", Puntero_2->NRegistro);
    BARRITAS(76);SALTO;
    printf("\tModelo\t\t\t \t\t%s \n\n", Puntero_2->Modelo);
    BARRITAS(76);SALTO;
    printf("\tMarca\t\t\t \t\t%s \n\n", Puntero_2->Marca);
    BARRITAS(76);SALTO;
    printf("\tPantalla\t\t \t\t%s \n\n", Tipo_Pantalla[Puntero_2->Tipos_Pantalla]);
    BARRITAS(76);SALTO;
    printf("\tResolucion\t\t \t\t%s \n\n", Resolucion[Puntero_2->Resoluciones]);
    BARRITAS(76);SALTO;
    printf("\tTDT\t\t\t \t\t%s \n\n", Tiene_Tdt[Puntero_2->TDT]);
    BARRITAS(76);SALTO;
    printf("\tPeso\t\t\t \t\t%1.2f \n\n", Puntero_2->Peso);
    BARRITAS(76);SALTO;
    printf("\tGrosor\t\t\t \t\t%1.2f \n\n", Puntero_2->Grosor);
    BARRITAS(76);SALTO;
    printf("\tFecha de lanzamiento\t \t\t%u de %s / %u  \n\n",
           Puntero_2->FechaLanzamiento.DiaLanzamiento,
           Mes_es[Puntero_2->FechaLanzamiento.MesLanzamiento],
           Puntero_2->FechaLanzamiento.ALanzamiento);
    BARRITAS(76);SALTO;
    ESPERAR(500);
    if(Puntero_2->Sgte==NULL){printf("Demonios, Gump\n");}
    Puntero_2 = Puntero_2->Sgte;} while(Puntero_2);
  DestruirNodos(Puntero_2);
  PAUSE;
  return;
}
/*
   Nombre: Imprimir_Estadisticas
   Funcion: Imprime las estadisticas de los dispositvos ingresados( los que
   tienen TDT, las resoluciones y los tipos de pantallla)
 */
void Imprimir_Estadisticas(EstDatos Estadistica, Usi NDato) {
  CLEAR;
  Imprime_Titulos(Estadisticas);
  printf("\tEstadisticas TDT\n\n");
  for (int l = 1; l < Ntdt; l++) {
    printf("\t\t%s\t\t", Tiene_Tdt[l]);
    printf("%u\n\n", Estadistica.EstTDT[l]);
  }
  printf("\n\tEstadisticas tipos de pantalla\n\n");
  for (int p = 1; p < Ntpanta; p++) {
    printf("\t\t%s\t\t", Tipo_Pantalla[p]);
    printf("%u\n\n", Estadistica.EstTiposPantalla[p]);
  }
  printf("\n\tEstadisticas resoluciones\n\n");
  for (int u = 1; u < NResoluciones; u++) {
    printf("\t\t%s\t\t", Resolucion[u]);
    printf("%u\n\n", Estadistica.EstResoluciones[u]);
  }
  SALTO;SALTO;
  printf("\tSe ingresaron %2d dispositvos.\n\n", NDato);
  PAUSE;
}

main() {
  system("Title MENU");
  system("mode con: cols=76 lines=300");
  system("color F0");
  hide();
  SAVE_SHIT Shit;
  EstDatos Estadistica;
  Shit.NDato=0;

  Estadistica.EstResoluciones = (Usi *) malloc((NResoluciones-1) * sizeof(Usi));
  for (int q = 0; q < NResoluciones; q++) Estadistica.EstResoluciones[q] = 0;

  Estadistica.EstTiposPantalla = (Usi *)malloc((Ntpanta-1) * sizeof(Usi));
  for (int q = 0; q < Ntpanta; q++) Estadistica.EstTiposPantalla[q] = 0;

  Estadistica.EstTDT = (Usi *)malloc((Ntdt-1) * sizeof(Usi));
  for (int q = 0; q < Ntdt; q++) Estadistica.EstTDT[q] = 0;

  Opciones Opcion = ImprimirDatos;
  while (Opcion != Salir) {
    CLEAR; system("Title MENU");
    switch (Menu()) {
    case LeerDatos: {
      system("Title INGRESO DE DATOS");
      Shit = Leer_Datos(Shit, Estadistica);
      break;
    }
    case ImprimirDatos: {
      system("Title IMPRESION");
      if (Shit.Televisores != NULL) {
        Imprimir_Datos(Shit.Televisores);
        break;
      } else {
        printf("\n\t\tNo hay datos suficientes.\n\n");
        ESPERAR(1000);
        break;
      }
    }
    case Estadisticas: {
      system("Title ESTADISTICAS");
      if (Shit.Televisores != NULL) {
        Imprimir_Estadisticas(Estadistica, Shit.NDato);
        break;
      } else {
        printf("\n\t\tNo hay datos suficientes.\n\n");
        ESPERAR(1000);
        break;
      }
    }
    case Salir: {
      system("Title PUTO EL QUE LO LEA");
      DestruirNodos(Shit.Televisores);
      printf("\n\t\tSaliendo...\n");
      ESPERAR(1500);
      printf("\t\tGracias.\n");
      return 0;
    }
    default:
      printf("\n\t\tOpcion incorrecta.\n");
      ESPERAR(1000);
    }
  }
}
