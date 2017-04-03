#include "EMm47J53_StackConfig.h"
/********************************************************/
/*------- Espacio para declaracion de constantes  ------*/
/********************************************************/

#define GLCD_DI      PIN_E1   // Data or Instruction input (RS)
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
unsigned int32 dato=0, vuelta=0, vuelta_segundo=0, dato1=0, vueltas=0;
float dato2=0;
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
set_tris_a(0b11111111);  
set_tris_b(0b11111111);                              // Inicializa microcontrolador
SETUP_ADC(ADC_OFF);                        // ADC deshabilitado
SETUP_ADC_PORTS(NO_ANALOGS);               // Todos los puertos como dgitales
glcd_init(ON);                             // Inicializa pantalla GLCD
glcd_fillScreen(OFF);                      // Pantalla GLCD fondo Blanco
sprintf(text_glcd,"Guillermo acevedo");
glcd_text57(4, 4, text_glcd, 1, ON);       // Imprime texto
glcd_line(0, 15, 127, 15, ON) ;            // Ejemplo para dibujar linea
sprintf(text_glcd,"Walter Moreno");
glcd_text57(4, 17, text_glcd, 1, ON);       // Imprime texto
glcd_line(0, 28, 127, 28, ON) ;  
glcd_update();  
SETUP_TIMER_1(T1_EXTERNAL | T1_DIV_BY_1 );
SET_TIMER1(0);
SETUP_TIMER_2(T2_DIV_BY_4,0x32,1);
SET_TIMER2(0);
enable_interrupts(INT_TIMER2);
enable_interrupts(GLOBAL);

   for(;;){
		delay_ms(100);
		glcd_fillScreen(OFF); 
		dato=GET_TIMER1();
		sprintf(text_glcd,"vueltas:");
		glcd_text57(0, 10, text_glcd, 1, ON); 
		sprintf(valor2, "%lu", vueltas);
		glcd_text57(50,10, valor2,1,ON);
		glcd_update();
		sprintf(text_glcd,"vueltas por minuto:");
		glcd_text57(0, 30, text_glcd, 1, ON); 
		sprintf(valor2, "%f", dato2);
		glcd_text57(50,40, valor2,1,ON);
		glcd_update();
   }  
}

#INT_TIMER2
interr_TIMER2(){
	dato=GET_TIMER1();
	if(dato>=72){
		vuelta++;
		vueltas++;
		SET_TIMER1(0);
		dato=GET_TIMER1();
	}
	dato1=dato1+1;
	if(dato1>=40000){
		vuelta_segundo=vuelta;
		dato2=(((dato*100)/72)/100)+vuelta_segundo;
		dato2=dato2*60;
		vuelta=0;	
		dato1=0;	
	}
	SET_TIMER2(0);
}
