#include "EMm47J53_StackConfig.h"
//========================================================
// Nombre del Programa: Manejo del LCD GRAFICO 128x64
// Autor: Claudia Leonor Rueda Guzm·n
// UNIVERSIDAD PONTIFICIA BOLIVARIANA
//========================================================


/********************************************************/
/*------- Espacio para declaracion de constantes  ------*/
/********************************************************/

#define GLCD_DI      PIN_C0   // Data or Instruction input (RS)
#define GLCD_RW      PIN_C1   // Read/Write
#define GLCD_E       PIN_C2   // Enable
#define GLCD_DB0     PIN_D0   // Data0
#define GLCD_DB1     PIN_D1   // Data1
#define GLCD_DB2     PIN_D2   // Data2
#define GLCD_DB3     PIN_D3   // Data3
#define GLCD_DB4     PIN_D4   // Data4
#define GLCD_DB5     PIN_D5   // Data5
#define GLCD_DB6     PIN_D6   // Data6
#define GLCD_DB7     PIN_D7   // Data7
#define GLCD_CS2     PIN_E0   // Chip Selection 1
#define GLCD_CS1     PIN_C7   // Chip Selection 2
#define GLCD_RST     PIN_C6   // Reset

#define ON           1
#define OFF          0

#define  FAST_GLCD
/********************************************************/
/*--- Espacio para declaracion de variables globales  --*/
/********************************************************/
char  text_glcd[40];
char  last_key=0x00;
char  last_screen;
/********************************************************/
/********************************************************/
/*-------------- Espacio para funciones  ---------------*/
/********************************************************/

#include "GLCD_128x64_KS0108.c"
#include <graphics.c>
#include <math.h>

/******************************************************************************/
/******************************************************************************/
/*--------------------- Espacio de codigo principal --------------------------*/
/******************************************************************************/ 
#zero_ram
void main(){
char i,dato;
float valor;
char valor2[7]; //Con esta variable visualizar un dato en pantalla//
mcu_init();                                // Inicializa microcontrolador
SETUP_ADC(ADC_OFF);                        // ADC deshabilitado
SETUP_ADC_PORTS(NO_ANALOGS);               // Todos los puertos como dgitales
glcd_init(ON);                             // Inicializa pantalla GLCD
glcd_fillScreen(OFF);                      // Pantalla GLCD fondo Blanco

dato=1;
valor=245.35; //constante
sprintf(valor2, "%3.2f", valor); //Mediante la funci€n sprintf, convertimos//
                                    //la variable float "valor" en la variable//
                                    //char "valor2" (para poder displayarla); //
                                    //los t»rminos "%3.2f" nos permiten ver   //
                                    //un n?mero de 3 unidades y 2 decimales   //

while(TRUE)
{	

  glcd_circle(40,40, 12, YES, ON); //Dibujamos el cuerpo con un cÃrculo lleno//                             
   glcd_circle(44,33, 1, YES, OFF);//Dibujamos el ojo con un cÃrculo vacÃo//
   delay_ms(250); 

//---------------PACKMAN CON LA BOCA ABIERTA-----------------//  


   glcd_line(40,40, 53,35, OFF);//En toda esta secuencia, dibujamos la boca//
   glcd_line(40,40, 53,36, OFF);//del comecocos abierta mediante lÃneas    //
   glcd_line(40,40, 53,37, OFF);
   glcd_line(40,40, 53,38, OFF);
   glcd_line(40,40, 53,39, OFF);
   glcd_line(40,40, 53,40, OFF);
   glcd_line(40,40, 53,41, OFF);
   glcd_line(40,40, 53,42, OFF);
   glcd_line(40,40, 53,43, OFF);
   glcd_line(40,40, 53,44, OFF);
   glcd_line(40,40, 53,45, OFF);
   glcd_line(40,40, 53,46, OFF);
   glcd_line(40,40, 53,47, OFF);
	glcd_update();
   delay_ms(250);


   glcd_text57(70,40, valor2,1,ON);  //En toda esta parte, Mostramos la     //
   glcd_update();
   delay_ms(250);                    //variable char "valor2" y le damos      //

   glcd_text57(70,40, valor2,1,OFF); //movimiento, borrando a su vez el rastro//
   glcd_text57(65,40, valor2,1,ON);  //que va dejando                         //
   glcd_update();
   delay_ms(250);

   glcd_text57(65,40, valor2,1,OFF);
   glcd_text57(60,40, valor2,1,ON);
   glcd_update();
   delay_ms(250);
   glcd_text57(60,40, valor2,1,OFF);
   glcd_text57(55,40, valor2,1,ON);
   glcd_update();
   delay_ms(250);
   glcd_text57(55,40, valor2,1,OFF);
   glcd_text57(50,40, valor2,1,ON);
   glcd_update();
   delay_ms(250);
   glcd_text57(50,40, valor2,1,OFF);
   glcd_text57(45,40, valor2,1,ON);
   glcd_update();
   delay_ms(250);
   glcd_text57(45,40, valor2,1,OFF);
   glcd_update();


}
}
