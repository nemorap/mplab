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

#define ventilador    PIN_A3

#define ON           1
#define OFF          0

#define  FAST_GLCD
/********************************************************/
/*--- Espacio para declaracion de variables globales  --*/
/********************************************************/
char  text_glcd[40];
char  last_key=0x00;
char  last_screen;
float calculo, temp, prom;
unsigned char sensor1, sensor2, sensor3;
signed int vector[120];
signed int dato,posy=55,aux,x,t,i;
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
set_tris_a(0b00000111);  
                              // Inicializa microcontrolador
SETUP_ADC_PORTS(sAN0 | sAN1 | sAN2);                        // ADC deshabilitado
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

for (i=0; i<120;i++){
	vector[i]=55;
}

while(TRUE)
{	
	glcd_fillScreen(OFF);
	glcd_update();
	set_adc_channel(0);
	delay_us(100);
	sensor1=read_adc();
	set_adc_channel(1);
	delay_us(100);
	sensor2=read_adc();
	set_adc_channel(2);
	delay_us(100);
	sensor3=read_adc();
	prom=(sensor1+sensor2+sensor3)/3;
	calculo=prom*0.0124;
	temp=calculo/0.010;
	sprintf(valor2, "%f", temp);
	glcd_text57(30,0, valor2,1,ON);
	glcd_update();
 	glcd_line(7, 55, 127, 55, ON) ;  
	glcd_line(7, 0, 7, 55, ON) ;
	sprintf(text_glcd,"t");
	glcd_text57(120, 57, text_glcd, 1, ON);       // Imprime texto
	sprintf(text_glcd,"T");
	glcd_text57(0, 0, text_glcd, 1, ON);       // Imprime texto
	vector[119]=50-(prom/2);
	posy=vector[119];	
	for (t=0; t<119;t++){
		vector[t]=vector[t+1];
		glcd_pixel(t+8,vector[t],ON);
	}
	glcd_pixel(127,vector[119],ON);
	glcd_update();
	
    if(temp>=35){
      output_high(ventilador);
	}
	else{
		output_low(ventilador);
	}
	delay_ms(100);
	glcd_fillScreen(OFF); 
	glcd_update();
}
}
