//========================================================
// Nombre del Programa: lab2
// Autor:guillermo acevedo, walter moreno, juan pablo marin
// Fecha:28/03/17
//========================================================

//#include "EMm47J53_StackConfig.h"
/********************************************************/
/*------- Espacio para declaracion de constantes  ------*/
/********************************************************/
#include <18F47J53.h>
#device ADC=8
#FUSES NOWDT         //WDT disabled (enabled by SWDTEN bit)                 
#FUSES PLL3          //Divide by 3 (12 MHz oscillator input)         
#FUSES NOPLLEN       //PLL Disabled
#FUSES NOSTVREN      //stack overflow/underflow reset enabled             
#FUSES NOXINST       //Extended instruction set disabled         
#FUSES NOCPUDIV      //No CPU system clock divide     
#FUSES NOPROTECT     //Program memory is not code-protected       
#FUSES HSPLL         //HS oscillator, PLL enabled, HSPLL used by USB       
#FUSES SOSC_HIGH     //High Power T1OSC/SOSC circuit selected
#FUSES CLOCKOUT      //CLKO output enabled on the RA6 pin
#FUSES NOFCMEN       //Fail-Safe Clock Monitor disabled
#FUSES NOIESO        //Two-Speed Start-up disabled
#FUSES WDT32768      //Watchdog Postscaler 1:32768
#FUSES DSWDTOSC_INT  //DSWDT uses INTOSC/INTRC as clock
#FUSES RTCOSC_INT    //RTCC uses INTRC as clock
#FUSES NODSBOR       //Zero-Power BOR disabled in Deep Sleep
#FUSES NODSWDT       //Deep Sleep Watchdog Timer Disabled
#FUSES DSWDT8192     //Deep Sleep Watchdog Postscaler: 1:8,192 (8.5 seconds)
#FUSES NOIOL1WAY     //IOLOCK bit can be set and cleared
#FUSES ADC12         //ADC 10 or 12 Bit Select:12 - Bit ADC Enabed
#FUSES MSSPMSK7      //MSSP 7 Bit address masking
#FUSES NOWPFP        //Write Protect Program Flash Page 0
#FUSES NOWPCFG       //Write/Erase last page protect Disabled
#FUSES WPDIS         //WPFP[5:0], WPEND, and WPCFG bits ignored
#FUSES WPEND         //Start protection at page 0
#FUSES LS48MHZ       //Low Speed USB mode with 48 MHz System clock at 48 MHz USB CLKEN divide-by is set to 8
#use delay(clock=48000000)

#pin_select U2TX=PIN_D2 //Selecciona hardware UART2
#pin_select U2RX=PIN_D3 //Selecciona hardware UART2

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
unsigned int vector[120];
unsigned int bandera=2, cont_tecla=0, tecla_valida=0, acceso_teclado=1, i=0, ingreso=0,dato2=0, tecla_anterior=0;
unsigned int32 dato1=0; 
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
//#zero_ram
void main(){
char i;
//mcu_init();

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
 
SETUP_TIMER_2(T2_DIV_BY_4,0xf3,1);
SET_TIMER2(0);
enable_interrupts(INT_TIMER2);
enable_interrupts(GLOBAL);

   for(;;){

	
		dato1=dato1+dato2;
		sprintf(text_glcd,"contador=");
		glcd_text57(4, 17, text_glcd, 1, ON);       // Imprime texto
		glcd_update();
		sprintf(valor2, "%lu", dato1);
		glcd_text57(60,17, valor2,1,ON);
		glcd_update(); 
		delay_ms(100);

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
		cont_tecla=20000;
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
	if(ingreso==1){
		if(tecla_anterior==1){
			dato2=tecla_valida;
			tecla_anterior=0;
		}
		if(tecla_valida==11){
			tecla_anterior=1;
		}
	}
}

#INT_TIMER2
interr_TIMER2(){
	teclado();
	
	SET_TIMER2(0);
}
