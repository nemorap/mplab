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

#define fila1 		PIN_B0
#define fila2 		PIN_B1
#define fila3 		PIN_B2
#define fila4 		PIN_B3
#define columna1	PIN_B4
#define columna2	PIN_B5
#define columna3	PIN_B6

#define ON           1
#define OFF          0

#define  FAST_GLCD
/********************************************************/
/*--- Espacio para declaracion de variables globales  --*/
/********************************************************/
char  text_glcd[40];
char  last_key=0x00;
char  last_screen;
signed int vector[120];
signed int bandera=2, cont_tecla=0, tecla_valida=0, acceso_teclado=1, i=0, ingreso=0;
int dato=0;
char valor2[7];
/********************************************************/
/********************************************************/
/*-------------- Espacio para funciones  ---------------*/
/********************************************************/

#include "GLCD_128x64_KS0108.c"
#include <graphics.c>
#include <math.h>
#include "rias.h"

void teclado();
void antirebote();
/*-------------------- Actualiza pantalla con graficos -----------------------*/
void PrintLogo(void){
int16 h=0,i=0,j=0,k=0,l=0;
glcd_fillScreen(OFF);
   for(h=0;h<8;h++){
      for(i=0;i<64;i++)displayData.left[j++]=rias[l++]; 
      for(i=0;i<64;i++)displayData.right[k++]=rias[l++]; 
   }
}

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
set_tris_c(0b00000000);
set_tris_a(0b11111111);     
set_tris_b(0b11110000);                             // Inicializa microcontrolador
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
glcd_update();                             // Actualiza pantalla

delay_ms(300);                           
glcd_fillScreen(OFF); 
glcd_update();  

PrintLogo();                               // Imprime Logo en Pantalla
glcd_update();                             // Actualiza pantalla
delay_ms(400);                           
glcd_fillScreen(OFF); 
glcd_update(); 
 
   for(;;){
		i=0;
		while(i<128){
			teclado();
			if(ingreso==1){
				if(tecla_valida<10){
					sprintf(valor2, "%d", tecla_valida);
					glcd_text57(i,30, valor2,1,ON);
					glcd_update();
				}
				else if(tecla_valida==10){
						sprintf(text_glcd,"*");
						glcd_text57(i, 30, text_glcd,1, ON);  
						glcd_update();
					}
				else{
						sprintf(text_glcd,"#");
						glcd_text57(i, 30, text_glcd, 1, ON); 
						glcd_update(); 
					}
				i=i+7;

			}
			delay_ms(10);
		}
		
		glcd_fillScreen(OFF);

   }  
}

void teclado(){
		ingreso=0;
		if(acceso_teclado==1){
			output_high(fila1);
			output_low(fila2);
			output_low(fila3);
			output_low(fila4);
			if(input(columna1)){dato=1; acceso_teclado=0; bandera=0;}
			if(input(columna2)){dato=2; acceso_teclado=0; bandera=0;}
			if(input(columna3)){dato=3; acceso_teclado=0; bandera=0;}
		
		    output_high(fila2);
			output_low(fila1);
			output_low(fila3);
			output_low(fila4);
			if(input(columna1)){dato=4; acceso_teclado=0; bandera=0;}
			if(input(columna2)){dato=5; acceso_teclado=0; bandera=0;}
			if(input(columna3)){dato=6; acceso_teclado=0; bandera=0;}
		
			output_high(fila3);
			output_low(fila2);
			output_low(fila1);
			output_low(fila4);
			if(input(columna1)){dato=7; acceso_teclado=0; bandera=0;}
			if(input(columna2)){dato=8; acceso_teclado=0; bandera=0;}
			if(input(columna3)){dato=9; acceso_teclado=0; bandera=0;}
		
			output_high(fila4);
			output_low(fila2);
			output_low(fila3);
			output_low(fila1);
			if(input(columna1)){dato=10; acceso_teclado=0; bandera=0;}
			if(input(columna2)){dato=0; acceso_teclado=0; bandera=0;}
			if(input(columna3)){dato=11; acceso_teclado=0; bandera=0;}
		}
	if(bandera==0){
		cont_tecla=12;
		bandera=1;
	}
	else if(bandera==1){
		cont_tecla--;
		if(cont_tecla==0){
			acceso_teclado=1;
			tecla_valida=dato;
			ingreso=1;
			bandera=2;
		}
	}
}

