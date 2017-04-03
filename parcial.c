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
#define IncDec PIN_A5
#define sensor1 PIN_B0
#define sensor2 PIN_B1
#define sensor3 PIN_B2
#define sensor4 PIN_B3
#define enter PIN_E1
#define cambio PIN_E2

#define ON           1
#define OFF          0

#define  FAST_GLCD
/********************************************************/
/*--- Espacio para declaracion de variables globales  --*/
/********************************************************/
char  text_glcd[40];
char  last_key=0x00;
char  last_screen;
signed int dato=0,posy=55,aux,x,t,i, bandera=0, dato1=0, dato2=0;
unsigned int cont;
unsigned char valor2[7];
/********************************************************/
/********************************************************/
/*-------------- Espacio para funciones  ---------------*/
/********************************************************/

#include "GLCD_128x64_KS0108.c"
#include <graphics.c>
#include <math.h>
#include "lobo.h"

void tanque();
void contador();
void imagen();

/*-------------------- Actualiza pantalla con graficos -----------------------*/
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

glcd_update();                             // Actualiza pantalla

delay_ms(1000);                           
glcd_fillScreen(OFF); 
glcd_update(); 
 


 glcd_rect(5, 5, 40,  55, YES, ON);          // Ejemplo para dibujar rectangulo 
glcd_rect(45, 5, 80, 55, NO, ON);          // Ejemplo para dibujar rectangulo 
glcd_rect(85, 5, 125,  55, NO, ON);          // Ejemplo para dibujar rectangulo 


sprintf(text_glcd,"OPC 1");
glcd_text57(9, 8, text_glcd, 1, OFF);       // Imprime texto

sprintf(text_glcd,"OPC 2");
glcd_text57(49, 8, text_glcd, 1, ON);       // Imprime texto

sprintf(text_glcd,"OPC 3");
glcd_text57(89, 8, text_glcd, 1, ON);       // Imprime texto


glcd_update();

   for(;;){
	if(bandera==0){
		if(input(cambio)==0){
					dato=dato+1;
					glcd_fillScreen(OFF);
				while(input(cambio)==0){dato=dato;}
			}
			else{
				dato=dato;
			}
		
			if(dato>2){
				dato=0;
			}
			switch(dato){
			case 1:
				glcd_rect(5, 5, 40,  55, NO, ON);          // Ejemplo para dibujar rectangulo 
				glcd_rect(45, 5, 80, 55, YES, ON);          // Ejemplo para dibujar rectangulo 
				glcd_rect(85, 5, 125,  55, NO, ON);          // Ejemplo para dibujar rectangulo 
		
				
				sprintf(text_glcd,"OPC 1");
				glcd_text57(9, 8, text_glcd, 1, ON);       // Imprime texto
		
				sprintf(text_glcd,"OPC 2");
				glcd_text57(49, 8, text_glcd, 1, OFF);       // Imprime texto
				
				sprintf(text_glcd,"OPC 3");
				glcd_text57(89, 8, text_glcd, 1, ON);       // Imprime texto
				
	
				glcd_update();
				break;
					
			case 2:
				glcd_rect(5, 5, 40,  55, NO, ON);          // Ejemplo para dibujar rectangulo 
				glcd_rect(45, 5, 80, 55, NO, ON);          // Ejemplo para dibujar rectangulo 
				glcd_rect(85, 5, 125,  55, YES, ON);          // Ejemplo para dibujar rectangulo 
		
				
				sprintf(text_glcd,"OPC 1");
				glcd_text57(9, 8, text_glcd, 1, ON);       // Imprime texto
		
				sprintf(text_glcd,"OPC 2");
				glcd_text57(49, 8, text_glcd, 1, ON);       // Imprime texto
				
				sprintf(text_glcd,"OPC 3");
				glcd_text57(89, 8, text_glcd, 1, OFF);       // Imprime texto
				
	
				glcd_update();
				break;		
	
	
			default:
				glcd_rect(5, 5, 40,  55, YES, ON);          // Ejemplo para dibujar rectangulo 
				glcd_rect(45, 5, 80, 55, NO, ON);          // Ejemplo para dibujar rectangulo 
				glcd_rect(85, 5, 125,  55, NO, ON);          // Ejemplo para dibujar rectangulo 
		
				
				sprintf(text_glcd,"OPC 1");
				glcd_text57(9, 8, text_glcd, 1, OFF);       // Imprime texto
		
				sprintf(text_glcd,"OPC 2");
				glcd_text57(49, 8, text_glcd, 1, ON);       // Imprime texto
				
				sprintf(text_glcd,"OPC 3");
				glcd_text57(89, 8, text_glcd, 1, ON);       // Imprime texto
				
	
				glcd_update();
				break;
			}
			delay_ms(100);
			glcd_fillScreen(OFF);

			if(input(enter)==0){    //en la simulacion enter tiene que empezar en 1
				bandera=1;
				while(input(enter)==0){}    //hasta que no se suelte el enter no entra a la funcion
			}
	}
	else{
		switch(dato){
			case 1:
				glcd_fillScreen(OFF); 
				glcd_update(); 
				contador();
				break;
					
			case 2:
				glcd_fillScreen(OFF); 
				glcd_update();
				imagen();
				
				break;		

			default:
				glcd_fillScreen(OFF); 
				glcd_update(); 
				tanque();
				break;
			}
		if(input(enter)==0){    //en la simulacion enter tiene que empezar en 1
				bandera=0;
				while(input(enter)==0){}    //hasta que no se suelte el enter no entra a la funcion
		}
	}	
	

   }  
}

void tanque(){
	dato2=0;          // Retardo en milisegundos
 	if(input(sensor1)) dato2=dato2+1;
	if(input(sensor2)) dato2=dato2+2;
	if(input(sensor3)) dato2=dato2+4;
	if(input(sensor4)) dato2=dato2+8;
	
	switch (dato2){
		case 0: 
			dato2=0;
			glcd_line(40, 5, 40, 45, ON) ;
			glcd_line(80, 5, 80, 45, ON) ;  
			glcd_line(40, 45, 80, 45, ON) ; 
			sprintf(valor2, "%d", dato2);
			glcd_text57(50,50, valor2,2,ON);
			glcd_update();
			break;
		case 1: 
			dato2=25;
			glcd_line(40, 5, 40, 45, ON) ; 
			glcd_line(80, 5, 80, 45, ON) ;  
			glcd_line(40, 45, 80, 45, ON) ; 
			glcd_rect(40, 35 , 80,  45, YES, ON);
			sprintf(valor2, "%d", dato2);
			glcd_text57(50,50, valor2,2,ON);
			glcd_update();
			break;
		case 3: 
			dato2=50;
			glcd_line(40, 5, 40, 45, ON) ; 
			glcd_line(80, 5, 80, 45, ON) ;  
			glcd_line(40, 45, 80, 45, ON) ; 
			glcd_rect(40, 25 , 80,  45, YES, ON);
			sprintf(valor2, "%d", dato2);
			glcd_text57(50,50, valor2,2,ON);
			glcd_update();
			break;
		case 7: 
			dato2=75;
			glcd_line(40, 5, 40, 45, ON) ; 
			glcd_line(80, 5, 80, 45, ON) ;  
			glcd_line(40, 45, 80, 45, ON) ; 
			glcd_rect(40, 15 , 80,  45, YES, ON);
			sprintf(valor2, "%d", dato2);
			glcd_text57(50,50, valor2,2,ON);
			glcd_update();
			break;
		case 15: 
			dato2=100;
			glcd_line(40, 5, 40, 45, ON) ; 
			glcd_line(80, 5, 80, 45, ON) ;  
			glcd_line(40, 45, 80, 45, ON) ; 
			glcd_rect(40, 5 , 80,  45, YES, ON);
			sprintf(valor2, "%d", dato2);
			glcd_text57(50,50, valor2,2,ON);
			glcd_update();
			break;
		default:
			sprintf(text_glcd,"sensores fallan");
			glcd_text57(4, 4, text_glcd, 1, ON); 
			glcd_update();
			delay_ms(200);
			break;
	}
	delay_ms(200);
}

void contador(){
	dato1=0;          // Retardo en milisegundos
 	if(input(in0)) dato1=dato1+1;
	if(input(in1)) dato1=dato1+2;
	if(input(in2)) dato1=dato1+4;
	if(input(in3)) dato1=dato1+8;	
	sprintf(valor2, "%d", cont);
	glcd_text57(30,30, valor2,3,ON);
	glcd_update();
	if(input(IncDec)==0){
		cont=cont+dato1;
	}
	else{
		cont=cont-dato1;
	}
	delay_ms(500);
}

void imagen(){
	PrintLogo();                               // Imprime Logo en Pantalla
	glcd_update();                             // Actualiza pantalla
	delay_ms(500);                           	
}