//#include "EMm47J53_StackConfig.h"
//#include <18F47J53.h>

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

#define senal PIN_B1
#define mecanico PIN_B2


#define ON           1
#define OFF          0

#define  FAST_GLCD
/********************************************************/
/*--- Espacio para declaracion de variables globales  --*/
/********************************************************/
char  text_glcd[40];
char  last_key=0x00;
char  last_screen;
unsigned int dato=0, refresh=0;
unsigned int cajas=0;
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
//#zero_ram
void main(){
char i;
//mcu_init();

set_tris_e(0b00000000);
set_tris_d(0b00000000);
set_tris_c(0b00000001);
set_tris_a(0b11111111);   
set_tris_b(0b11111101);                            // Inicializa microcontrolador
SETUP_ADC(ADC_OFF);                        // ADC deshabilitado
SETUP_ADC_PORTS(NO_ANALOGS);               // Todos los puertos como dgitales
glcd_init(ON);                             // Inicializa pantalla GLCD
glcd_fillScreen(OFF);                      // Pantalla GLCD fondo Blanco
SETUP_TIMER_1(T1_EXTERNAL | T1_DIV_BY_1 | T1_GATE );
SET_TIMER1(0);
enable_interrupts(INT_EXT_H2L);
enable_interrupts(GLOBAL);




   for(;;){
		delay_ms(1);
		dato=GET_TIMER1();
		if(dato==16){
			output_high(mecanico);
			delay_ms(10);
			output_low(mecanico);
		}
		if(refresh==50){		
		glcd_fillScreen(OFF); 
		sprintf(text_glcd,"botellas = ");
		glcd_text57(0, 30, text_glcd, 1, ON);   
		sprintf(valor2, "%u", dato);
		glcd_text57(65,30, valor2,1,ON);
		glcd_update();
		sprintf(text_glcd,"cajas = ");
		glcd_text57(0, 0, text_glcd, 1, ON);   
		sprintf(valor2, "%u", cajas);
		glcd_text57(50,0, valor2,1,ON);
		glcd_update();
		refresh=0;
		}
		refresh++;
   }  
}

#INT_EXT

interr_EXTERNA(){
		SET_TIMER1(0);
		output_high(senal);
		delay_ms(10);
		output_low(senal);
		cajas++;	
}

