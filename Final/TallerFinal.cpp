/*--------------------------------------------------------------------------------
            TALLER N7
   Autor: Cristian Rodriguez	1007794309
   Fecha: 3 de Febrero del 2019
--------------------------------------------------------------------------------*/
#include <conio.h>
#include <ctype.h>
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>
#include <windows.h>
#include <iostream>
#include <cstdlib>
#include "Librerias/LibRARA.h"
using namespace std;
using namespace FuncionesRaras;
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
#define ESPERAR(n) Sleep(n)
#define FAIL printf("\7")
#define SALTO printf("\n")
#define MENSAJE(s) printf("%s", s)
// Definidion de tipos
typedef enum { LeerDatos = 1, ImprimirDatos, Estadisticas, Salir } Opciones;
typedef enum { Seguir = 1, NoSeguir } SeguirLeyendo;
typedef enum { Letras, Alfanumerico } TDato;
typedef enum { Mayor_Menor = 1, Menor_Mayor } Tipo_orden;
typedef enum { NoDisponible, Enero, Febrero, Marzo, Abril, Mayo, Junio,
  Julio, Agosto, Septiembre, Octubre, Noviembre, Diciembre} Meses;
enum Resolu { Nd1, H, HD, FHD, UHD, Otrs, NResoluciones }; //Nd : NoDisponible
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
  Usi EstResoluciones[NResoluciones];
  Usi EstTiposPantalla[Ntpanta];
  Usi EstTDT[Ntdt];
  int NDato;}EstDatos;
struct Dispositivo {
  char Modelo[SHORT];
  char Marca[SHORT];
  Ui Tipos_Pantalla;
  Ui Resoluciones;
  Ui TDT;
  float Peso;
  float Grosor;
  int NRegistro;
  Fechas FechaLanzamiento;};
typedef struct Dispositivo Dispositive;
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
void LeerTexto(char *Lectura, TDato Tipo_Dato) {
  Ui Car, NCARLeidos = 0;
  while ((Car = toupper(getche())) != ENTER) {
    switch (Tipo_Dato) {
      case Letras: {
        if (Car == BORRAR) {
          Lectura[NCARLeidos--] = Car;
          printf(" ");
          CursorAtras();
          break;}
        if (isalpha(Car)) {
            Lectura[NCARLeidos++] = Car;
            break;}else {
                    FAIL;
                    Lectura[NCARLeidos--] = BORRAR;
                    CursorAtras();
                    printf(" ");CursorAtras();
                    break;}}
      case Alfanumerico: {
        if (Car == BORRAR) {
          Lectura[NCARLeidos--] = Car;
          printf(" ");
          CursorAtras();
          break;}
        if (isalnum(Car)) {
            Lectura[NCARLeidos++] = Car;
            break;} else {
                      FAIL;
                      Lectura[NCARLeidos--] = BORRAR;
                      CursorAtras();
                      printf(" ");CursorAtras();
                      break;}}
    }}
  if (Car == ENTER) {
    Lectura[NCARLeidos++] = FINCADENA;
    Lectura[NCARLeidos] = FINVECTOR;
  }
  //return NCARLeidos;
}
/*
   Nombre: LeerDatos
   Funcion: Permite leer los datos de n dispositivos, otorgandole al usuario la
   desicion de elegir cuando desea parar de ingresar dispositivos
 */
void Leer_Datos(EstDatos &Estadistica) {
  CLEAR;
  FILE *Televisores=NULL;
  if(!(Televisores=fopen("Archivos/Registro.bin","ab"))){
    MENSAJE("ERROR!");PAUSE;
    exit(1);
  }else{
    Dispositive NuevoT;
    SeguirLeyendo Leer = Seguir;
    while (Leer == Seguir) {
      CLEAR;
      Imprime_Titulos(LeerDatos);
      NuevoT.NRegistro = ++Estadistica.NDato;
      BARRITAS(76);
      printf("\tNumero de registro:\t\t \t\t %3d\n", NuevoT.NRegistro);
      BARRITAS(76);
      SALTO; SALTO;
      printf("\t\tModelo:\t");
      LeerTexto(NuevoT.Modelo, Alfanumerico);
      SALTO;
      printf("\n\t\tMarca:\t");
      LeerTexto(NuevoT.Marca, Letras);
      SALTO;
      printf("\n\t\tTipo de pantalla:\t\n");
      BARRITAS(76);
      for(int i=1; i<Ntpanta; i++){printf(" %d. %s \t", i, Tipo_Pantalla[i]);}
      SALTO;
      BARRITAS(76);
      printf("\n\t\tSeleccione el tipo de pantalla de su TV:\t");
      scanf("%u", &NuevoT.Tipos_Pantalla);
      while ((NuevoT.Tipos_Pantalla < 1) || (NuevoT.Tipos_Pantalla > (Ntpanta-1))) {
        printf("\n\tTipo de pantalla no valida.");
        printf("\n\t\tSeleccione el tipo de pantalla de su TV:\t");
        scanf("%u", &NuevoT.Tipos_Pantalla);}
      Estadistica.EstTiposPantalla[NuevoT.Tipos_Pantalla]++;
      printf("\n\t\tResolucion:\t\n");
      BARRITAS(76);
      for(int i=1; i<NResoluciones; i++){ printf(" %d. %s \t", i, Resolucion[i]);}
      SALTO;
      BARRITAS(76);
      printf("\n\t\tSeleccione la resolucion de su TV:\t");
      scanf("%u", &NuevoT.Resoluciones);
      while ((NuevoT.Resoluciones < 1) || (NuevoT.Resoluciones > (NResoluciones-1))) {
        printf("\n\tResolucion no valida.");
        printf("\n\t\tSeleccione la resolucion de su TV:\t");
        scanf("%u", &NuevoT.Resoluciones);}
      Estadistica.EstResoluciones[NuevoT.Resoluciones]++;
      printf("\n\t\tTelevision Digital Terrestre:\n");
      BARRITAS(76);
      for (int i = 1; i < Ntdt; i++) {printf("\t\t %d. %s \t\t", i, Tiene_Tdt[i]);}
      SALTO;
      BARRITAS(76);
      printf("\n\t\tSeleccione la opcion correcta para su TV:\t");
      scanf("%u", &NuevoT.TDT);
      while ((NuevoT.TDT < 1) || (NuevoT.TDT > (Ntdt-1))) {
        printf("\n\tOpcion no valida.");
        printf("\n\t\tSeleccione una opcion correcta para su TV:\t");
        scanf("%u", &NuevoT.TDT);}
      Estadistica.EstTDT[NuevoT.TDT]++;
      printf("\n\t\tPeso(g):\t");
      scanf("%f", &NuevoT.Peso);
      printf("\n\t\tGrosor(mm):\t");
      scanf("%f", &NuevoT.Grosor);
      printf("\n\t\tMes de lanzamiento:\t");
      scanf("%d", &NuevoT.FechaLanzamiento.MesLanzamiento);
      while ((NuevoT.FechaLanzamiento.MesLanzamiento > 12)){
        printf("\n\tMes Invalido.");
        printf("\n\t\tMes de lanzamiento:\t");
        scanf("%d", &NuevoT.FechaLanzamiento.MesLanzamiento);}
      printf("\n\t\tDia de lanzamiento:\t");
      scanf("%u", &NuevoT.FechaLanzamiento.DiaLanzamiento);
      printf("\n\t\tAnyo de lanzamiento:\t");
      scanf("%u", &NuevoT.FechaLanzamiento.ALanzamiento);
      while (NuevoT.FechaLanzamiento.ALanzamiento > ANYOSIG) {
        printf("\n\tERROR: Anyo invalido.");
        printf("\n\t\tAnyo de lanzamiento:\t");
        scanf("%u", &NuevoT.FechaLanzamiento.ALanzamiento);}

      fwrite(&NuevoT, sizeof(NuevoT), 1, Televisores);
      printf("\n\n\tDesea ingresar otro dispositivo?\n");
      printf("\t---------------------\n");
      printf("\t|  1. Si     2. No  |\n");
      printf("\t---------------------\n");
      scanf("%d", &Leer);
      while (Leer < 1 || Leer > 2) {
        printf("\n\tOpcion no valida.");
        printf("\n\t\tSeleccione una opcion valida:\t");
        scanf("%d", &Leer);}
    }
    fclose(Televisores);
  }
}
/*
   Nombre: Imprime_Datos
   Funcion: Imprime los datos de los dispositivos ingresados, con un lapso de 2
   seg cada uno.
 */

void Imprimir_Datos() {
  CLEAR;
  FILE *Televisores=NULL;
  if(!(Televisores=fopen("Archivos/Registro.bin","rb"))){
    MENSAJE("ERROR!");PAUSE;
    exit(1);}
  else{
    Dispositive Dato;
    Imprime_Titulos(ImprimirDatos);
    BARRITAS(76);SALTO;
    printf("  ESPECIFICACIONES DEL PRODUCTO\t\t \t\tDATOS\n\n");
    BARRITAS(76);SALTO;SALTO;
    while(fread(&Dato, sizeof(Dato), 1, Televisores)){
      BARRITAS(76);SALTO;
      printf("\tNumero de registro:\t\t \t%d\n", Dato.NRegistro);
      BARRITAS(76);SALTO;
      printf("\tModelo\t\t\t \t\t%s \n\n", Dato.Modelo);
      BARRITAS(76);SALTO;
      printf("\tMarca\t\t\t \t\t%s \n\n", Dato.Marca);
      BARRITAS(76);SALTO;
      printf("\tPantalla\t\t \t\t%s \n\n", Tipo_Pantalla[Dato.Tipos_Pantalla]);
      BARRITAS(76);SALTO;
      printf("\tResolucion\t\t \t\t%s \n\n", Resolucion[Dato.Resoluciones]);
      BARRITAS(76);SALTO;
      printf("\tTDT\t\t\t \t\t%s \n\n", Tiene_Tdt[Dato.TDT]);
      BARRITAS(76);SALTO;
      printf("\tPeso\t\t\t \t\t%1.2f \n\n", Dato.Peso);
      BARRITAS(76);SALTO;
      printf("\tGrosor\t\t\t \t\t%1.2f \n\n", Dato.Grosor);
      BARRITAS(76);SALTO;
      printf("\tFecha de lanzamiento\t \t\t%u de %s / %u  \n\n",
             Dato.FechaLanzamiento.DiaLanzamiento,
             Mes_es[Dato.FechaLanzamiento.MesLanzamiento],
             Dato.FechaLanzamiento.ALanzamiento);
      BARRITAS(76);SALTO;
      ESPERAR(500);}}
  PAUSE;
  return;}
/*
   Nombre: Imprimir_Estadisticas
   Funcion: Imprime las estadisticas de los dispositvos ingresados( los que
   tienen TDT, las resoluciones y los tipos de pantallla)
 */

void Imprimir_Estadisticas(EstDatos Estadistica) {
  CLEAR;
  Imprime_Titulos(Estadisticas);
  printf("\tEstadisticas TDT\n\n");
  for (int l = 1; l < Ntdt; l++) {
    printf("\t\t%s\t\t", Tiene_Tdt[l]);
    printf("%u\n\n", Estadistica.EstTDT[l]);}
  printf("\n\tEstadisticas tipos de pantalla\n\n");
  for (int p = 1; p < Ntpanta; p++) {
    printf("\t\t%s\t\t", Tipo_Pantalla[p]);
    printf("%u\n\n", Estadistica.EstTiposPantalla[p]);}
  printf("\n\tEstadisticas resoluciones\n\n");
  for (int u = 1; u < NResoluciones; u++) {
    printf("\t\t%s\t\t", Resolucion[u]);
    printf("%u\n\n", Estadistica.EstResoluciones[u]);}
  SALTO;SALTO;
  printf("\tSe ingresaron %2d dispositvos.\n\n", Estadistica.NDato);
  PAUSE;
}

main() {
  system("Title MENU");
  system("mode con: cols=76 lines=300");
  system("color F0");
  hide();
  EstDatos Estadistica;
  FILE *Televisores = NULL, *EstadisticasG = NULL;
  Opciones Opcion = ImprimirDatos;
  for (int q = 0; q < NResoluciones; q++) Estadistica.EstResoluciones[q] = 0;
  for (int q = 0; q < Ntpanta; q++) Estadistica.EstTiposPantalla[q] = 0;
  for (int q = 0; q < Ntdt; q++) Estadistica.EstTDT[q] = 0;
  Estadistica.NDato=0;
  if(!(Televisores=fopen("Archivos/Registro.bin", "ab"))){
    MENSAJE("ERROR REGISTRO/CREACION!");PAUSE;exit(1);}
  else fclose(Televisores);

  if(!(EstadisticasG=fopen("Archivos/NRegistro.bin", "ab"))){
    MENSAJE("ERROR NREGISTRO/CREACION!");PAUSE;exit(1);}
    else{fclose(EstadisticasG);EstadisticasG=NULL;
        if(!(EstadisticasG=fopen("Archivos/NRegistro.bin","rb"))){
          MENSAJE("ERROR ESTADISTICAS!");PAUSE;
          exit(1);}
        else{
          if(feof(EstadisticasG)) {fwrite(&Estadistica, sizeof(Estadistica), 1, EstadisticasG);}
          else {fread(&Estadistica, sizeof(Estadistica), 1, EstadisticasG);}
          fclose(EstadisticasG);}}
  while (Opcion != Salir) {
    CLEAR; system("Title MENU");
    switch (Menu()) {
      case LeerDatos: {
        system("Title INGRESO DE DATOS");
        Leer_Datos(Estadistica);
        break;}
      case ImprimirDatos: {
        system("Title SALIDA DATOS");
        if(Estadistica.NDato !=0){ Imprimir_Datos(); break;}
        else{printf("\n\t\tNo hay datos suficientes.\n\n");
        ESPERAR(1000);break;}}
      case Estadisticas: {
        system("Title ESTADISTICAS");
        if (Estadistica.NDato != 0) {
          Imprimir_Estadisticas(Estadistica);
          break;}
        else {
          printf("\n\t\tNo hay datos suficientes.\n\n");
          ESPERAR(1000);
          break;
        }}
      case Salir: {
        system("Title Finalizando");
        if(!(EstadisticasG=fopen("Archivos/NRegistro.bin","wb"))){
          MENSAJE("ERROR ESTADISTICAS!");PAUSE;
          exit(1);}
        else {fwrite(&Estadistica, sizeof(Estadistica), 1, EstadisticasG); fclose(EstadisticasG);}

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
