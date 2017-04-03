#include "EMm47J53_StackConfig.h"
//========================================================
// Nombre del Programa: Manejo del LCD GRAFICO 128x64
// Autor: Claudia Leonor Rueda Guzmán
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

void drawFrame(x,y,w,h) 
{ 
    int i=0; 
    glcd_rect(x, y, w, h, NO, ON);              // Outline the frame 

	sprintf(text_glcd,"Voltaje");
    glcd_text57(58, 57, text_glcd, 1, ON);       // Display "Volts" 

    for (i=5;i<=w;i+=10)                        // Draw some fancy markers :) 
    {                                           // horizontal 
        glcd_line(i,h,i,h+5,ON);                // every 10 pixel 
    } 
    for(i=y; i<=h;i+=10)                        // vertical 
    { 
        glcd_line(1,i,5,i,ON); 
    } 
} 

/******************************************************************************/
/******************************************************************************/
/*--------------------- Espacio de codigo principal --------------------------*/
/******************************************************************************/ 
#zero_ram
void main(){
char i;
mcu_init();                                // Inicializa microcontrolador
SETUP_ADC(ADC_OFF);                        // ADC deshabilitado
SETUP_ADC_PORTS(NO_ANALOGS);               // Todos los puertos como dgitales
glcd_init(ON);                             // Inicializa pantalla GLCD
glcd_fillScreen(OFF);                      // Pantalla GLCD fondo Blanco

sprintf(text_glcd,"PROGRAMA DE PRUEBA");
glcd_text57(4, 4, text_glcd, 1, ON);       // Imprime texto
glcd_line(0, 15, 127, 15, ON) ;            // Ejemplo para dibujar linea
glcd_update();                             // Actualiza pantalla
delay_ms(500);                           


glcd_circle(10,40, 8, YES, ON); //Dibujamos el cuerpo con un cÌrculo lleno//                      
glcd_circle(35,40, 8, NO, ON); //Dibujamos el cuerpo con un cÌrculo vacio// 
glcd_rect(60, 45, 75, 30, YES, ON);          // Ejemplo para dibujar rectangulo 
glcd_rect(80, 45, 95, 30,NO , ON);          // Ejemplo para dibujar rectangulo 

glcd_update(); 
delay_ms(500);
glcd_fillScreen(OFF);
glcd_update();

glcd_bar(5, 5, 70, 50, 2, ON); 
glcd_bar(9, 5, 79, 50, 1, ON);
glcd_bar(14, 5, 84, 50, 3, ON); 
glcd_update();

delay_ms(500);
glcd_fillScreen(OFF);
glcd_update();

glcd_rect(5, 5, 115,  25, YES, ON);          // Ejemplo para dibujar rectangulo 
glcd_rect(5, 35, 115, 55, NO, ON);          // Ejemplo para dibujar rectangulo 

sprintf(text_glcd,"MENU ACTIVADO");
glcd_text57(9, 8, text_glcd, 1, OFF);       // Imprime texto

sprintf(text_glcd,"MENU DESACTIVADO");
glcd_text57(9, 38, text_glcd, 1, ON);       // Imprime texto

glcd_update();
delay_ms(500);

glcd_fillScreen(OFF);
glcd_update();

glcd_rect(5, 5, 115,  25, NO, ON);          // Ejemplo para dibujar rectangulo 
glcd_rect(5, 35, 115, 55, YES, ON);          // Ejemplo para dibujar rectangulo 

sprintf(text_glcd,"MENU DESACTIVADO");
glcd_text57(9, 8, text_glcd, 1, ON);       // Imprime texto

sprintf(text_glcd,"MENU ACTIVADO");
glcd_text57(9, 38, text_glcd, 1, OFF);       // Imprime texto
glcd_update();
delay_ms(500);
glcd_fillScreen(OFF);
glcd_update();

glcd_rect(5, 5, 115,  25, YES, ON);          // Ejemplo para dibujar rectangulo 
glcd_rect(5, 35, 115, 55, NO, ON);          // Ejemplo para dibujar rectangulo 

sprintf(text_glcd,"MENU ACTIVADO");
glcd_text57(9, 8, text_glcd, 1, OFF);       // Imprime texto

sprintf(text_glcd,"MENU DESACTIVADO");
glcd_text57(9, 38, text_glcd, 1, ON);       // Imprime texto

glcd_update();
delay_ms(500);


glcd_fillScreen(OFF);
drawFrame(5,0,125,51);  
glcd_update();

 for(;;)
 {	
for (i=0;i<100;i++){
glcd_pixel(i,i+10,on);
glcd_update();
delay_ms(150);
}
glcd_fillScreen(OFF);
drawFrame(5,0,125,51); 
glcd_update();
   }  
}
