#include "EMm47J53_StackConfig.h"

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
unsigned int dato=0, segundos=0, minutos=0;
unsigned int16 dato1=0;
unsigned int cont;
unsigned char valor2[7];
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
char i;
mcu_init();

set_tris_e(0b00000000);
set_tris_d(0b00000000);
set_tris_c(0b00000001);
set_tris_a(0b11111111);                                // Inicializa microcontrolador
SETUP_ADC(ADC_OFF);                        // ADC deshabilitado
SETUP_ADC_PORTS(NO_ANALOGS);               // Todos los puertos como dgitales
glcd_init(ON);                             // Inicializa pantalla GLCD
glcd_fillScreen(OFF);                      // Pantalla GLCD fondo Blanco
SETUP_TIMER_2(T2_DIV_BY_4,0x32,1);
SET_TIMER2(0);
enable_interrupts(INT_TIMER2);
enable_interrupts(GLOBAL);


   for(;;){
		delay_ms(100);	
		glcd_fillScreen(OFF); 
		sprintf(valor2, "%d", segundos);
		glcd_text57(30,30, valor2,2,ON);
		glcd_update();
		sprintf(valor2, "%d", minutos);
		glcd_text57(0,30, valor2,2,ON);
		glcd_update();
		sprintf(valor2, "%lu", dato1);
		glcd_text57(0,0, valor2,2,ON);
		glcd_update();
   }  
}

#INT_TIMER2
interr_TIMER2(){
	dato1=dato1+1;
	if(dato1>=60000){
		segundos=segundos+1;
		dato1=0;		
	}
	if(segundos==60){
		segundos=0;
		minutos=minutos+1;
	}
	SET_TIMER2(0);
}