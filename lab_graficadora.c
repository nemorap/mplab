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

#define in0 PIN_A0
#define in1 PIN_A1
#define in2 PIN_A2
#define in3 PIN_A3
#define pulsador PIN_A5

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
signed int dato=0,bandera=0;
/********************************************************/
/********************************************************/
/*-------------- Espacio para funciones  ---------------*/
/********************************************************/

#include "GLCD_128x64_KS0108.c"
#include <graphics.c>
#include <math.h>
#include "rias.h"

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
set_tris_a(0b11111111);                                // Inicializa microcontrolador
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

delay_ms(3000);                           
glcd_fillScreen(OFF); 
glcd_update();  

PrintLogo();                               // Imprime Logo en Pantalla
glcd_update();                             // Actualiza pantalla
delay_ms(4000);                           
glcd_fillScreen(OFF); 
glcd_update(); 
for (i=0; i<120;i++){
	vector[i]=55;
}
 
   for(;;){
		bandera=0;
		
		if(input(pulsador)==0){
				dato=dato+1;
			while(input(pulsador)==0){dato=dato;}
		}
		else{
			dato=dato;
		}
	
		if(dato>3){
			dato=0;
		}
		switch(dato){
		case 1:
			glcd_rect(5, 5, 55,  25, NO, ON);          // Ejemplo para dibujar rectangulo 
			glcd_rect(5, 35, 55, 55, YES, ON);          // Ejemplo para dibujar rectangulo 
			glcd_rect(65, 5, 115,  25, NO, ON);          // Ejemplo para dibujar rectangulo 
			glcd_rect(65, 35, 115, 55, NO, ON);          // Ejemplo para dibujar rectangulo 
			
			sprintf(text_glcd,"OPC 1");
			glcd_text57(9, 8, text_glcd, 1, ON);       // Imprime texto
	
			sprintf(text_glcd,"OPC 2");
			glcd_text57(9, 38, text_glcd, 1, OFF);       // Imprime texto
			
			sprintf(text_glcd,"OPC 3");
			glcd_text57(69, 8, text_glcd, 1, ON);       // Imprime texto
			
			sprintf(text_glcd,"OPC 4");
			glcd_text57(69, 38, text_glcd, 1, ON);       // Imprime texto
			glcd_update();
			break;
				
		case 2:
			glcd_rect(5, 5, 55,  25, NO, ON);          // Ejemplo para dibujar rectangulo 
			glcd_rect(5, 35, 55, 55, NO, ON);          // Ejemplo para dibujar rectangulo 
			glcd_rect(65, 5, 115,  25, YES, ON);          // Ejemplo para dibujar rectangulo 
			glcd_rect(65, 35, 115, 55, NO, ON);          // Ejemplo para dibujar rectangulo 
			
			sprintf(text_glcd,"OPC 1");
			glcd_text57(9, 8, text_glcd, 1, ON);       // Imprime texto
	
			sprintf(text_glcd,"OPC 2");
			glcd_text57(9, 38, text_glcd, 1, ON);       // Imprime texto
			
			sprintf(text_glcd,"OPC 3");
			glcd_text57(69, 8, text_glcd, 1, OFF);       // Imprime texto
			
			sprintf(text_glcd,"OPC 4");
			glcd_text57(69, 38, text_glcd, 1, ON);       // Imprime texto
			glcd_update();
			break;			

		case 3:
			glcd_rect(5, 5, 55,  25, NO, ON);          // Ejemplo para dibujar rectangulo 
			glcd_rect(5, 35, 55, 55, NO, ON);          // Ejemplo para dibujar rectangulo 
			glcd_rect(65, 5, 115,  25, NO, ON);          // Ejemplo para dibujar rectangulo 
			glcd_rect(65, 35, 115, 55, YES, ON);          // Ejemplo para dibujar rectangulo 
			
			sprintf(text_glcd,"OPC 1");
			glcd_text57(9, 8, text_glcd, 1, ON);       // Imprime texto
	
			sprintf(text_glcd,"OPC 2");
			glcd_text57(9, 38, text_glcd, 1, ON);       // Imprime texto
			
			sprintf(text_glcd,"OPC 3");
			glcd_text57(69, 8, text_glcd, 1, ON);       // Imprime texto
			
			sprintf(text_glcd,"OPC 4");
			glcd_text57(69, 38, text_glcd, 1, OFF);       // Imprime texto
			glcd_update();
			break;

		default:
			glcd_rect(5, 5, 55,  25, YES, ON);          // Ejemplo para dibujar rectangulo 
			glcd_rect(5, 35, 55, 55, NO, ON);          // Ejemplo para dibujar rectangulo 
			glcd_rect(65, 5, 115,  25, NO, ON);          // Ejemplo para dibujar rectangulo 
			glcd_rect(65, 35, 115, 55, NO, ON);          // Ejemplo para dibujar rectangulo 
			
			sprintf(text_glcd,"OPC 1");
			glcd_text57(9, 8, text_glcd, 1, OFF);       // Imprime texto
	
			sprintf(text_glcd,"OPC 2");
			glcd_text57(9, 38, text_glcd, 1, ON);       // Imprime texto
			
			sprintf(text_glcd,"OPC 3");
			glcd_text57(69, 8, text_glcd, 1, ON);       // Imprime texto
			
			sprintf(text_glcd,"OPC 4");
			glcd_text57(69, 38, text_glcd, 1, ON);       // Imprime texto
			glcd_update();
			break;
		}
		delay_ms(100);
		glcd_fillScreen(OFF);

   }  
}
