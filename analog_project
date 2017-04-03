#include "EMm47J53_StackConfig.h"
//========================================================
// Nombre del Programa: Manejo del LCD GRAFICO 128x64
// Autor: Claudia Leonor Rueda Guzmán
// UNIVERSIDAD PONTIFICIA BOLIVARIANA
//========================================================


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
float calculo, temp;
unsigned char dato;
/********************************************************/
/********************************************************/
/*-------------- Espacio para funciones  ---------------*/
/********************************************************/

#include "GLCD_128x64_KS0108.c"
#include <graphics.c>
#include <math.h>
#include "lobo.h"


void PrintLogo(void){
int16 h=0,i=0,j=0,k=0,l=0;
glcd_fillScreen(OFF);
   for(h=0;h<8;h++){
      for(i=0;i<64;i++)displayData.left[j++]=lobo[l++]; 
      for(i=0;i<64;i++)displayData.right[k++]=lobo[l++]; 
   }
}

/******************************************************************************/
/******************************************************************************/
/*--------------------- Espacio de codigo principal --------------------------*/
/******************************************************************************/ 
#zero_ram
void main(){
float valor;
char valor2[7]; //Con esta variable visualizar un dato en pantalla//
mcu_init();  
set_tris_e(0b00000000);
set_tris_d(0b00000000);
set_tris_c(0b00000000);
set_tris_a(0b11111111);  
                              // Inicializa microcontrolador
SETUP_ADC_PORTS(sAN1);                        // ADC deshabilitado
SETUP_ADC(ADC_CLOCK_INTERNAL);               // Todos los puertos como dgitales

glcd_init(ON);                             // Inicializa pantalla GLCD
glcd_fillScreen(OFF);                      // Pantalla GLCD fondo Blanco

sprintf(text_glcd,"Guillermo acevedo");
glcd_text57(4, 4, text_glcd, 1, ON);       // Imprime texto
glcd_line(0, 15, 127, 15, ON) ;            // Ejemplo para dibujar linea
sprintf(text_glcd,"Walter Moreno");
glcd_text57(4, 17, text_glcd, 1, ON);       // Imprime texto
glcd_line(0, 28, 127, 28, ON) ;  
sprintf(text_glcd,"ola k asen");
glcd_text57(4, 30, text_glcd, 1, ON);  
glcd_line(0, 41, 127, 41, ON) ; 
sprintf(text_glcd,"Winter is coming");
glcd_text57(4, 42, text_glcd, 1, ON);  
glcd_line(0, 53, 127, 53, ON) ; 
glcd_update();                             // Actualiza pantalla

delay_ms(300);                           
glcd_fillScreen(OFF); 
glcd_update();  

PrintLogo();                               // Imprime Logo en Pantalla
glcd_update();                             // Actualiza pantalla
delay_ms(400);                           
glcd_fillScreen(OFF); 



while(TRUE)
{	
	glcd_fillScreen(OFF); 
	set_adc_channel(1);
	delay_us(100);
	dato=read_adc();
	sprintf(valor2, "%u", dato);
	glcd_text57(30,30, valor2,1,ON);
	glcd_update();
	calculo=dato*0.0124;
	sprintf(valor2, "%f", calculo);
	glcd_text57(30,50, valor2,1,ON);
	glcd_update();
	temp=calculo/0.010;
	sprintf(valor2, "%f", temp);
	glcd_text57(30,10, valor2,1,ON);
	glcd_update();
  	delay_ms(200);
}
}
