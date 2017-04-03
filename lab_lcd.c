//========================================================
// Nombre del Programa: lab2
// Autor:guillermo acevedo y walter moreno
// Fecha:07/02/17
//========================================================

#include "EMm47J53_StackConfig.h"
#include <flex_lcd.c>
/********************************************************/
/*------- Espacio para declaracion de constantes  ------*/
/********************************************************/

#define in0 PIN_A0
#define in1 PIN_A1
#define in2 PIN_A2
#define in3 PIN_A3
#define emerg PIN_A5
#define sensor1 PIN_C0
#define sensor2 PIN_C1
#define sensor3 PIN_C2
#define sensor4 PIN_C6
#define bombaVac PIN_D0
#define bombaLlen PIN_D1

/********************************************************/
/*--- Espacio para declaracion de variables globales  --*/
/********************************************************/

unsigned char contador=0;
unsigned char contador1=0;
int dato,dato1, bandera, bandera1;

/********************************************************/
/********************************************************/
/*-------------- Espacio para funciones  ---------------*/
/********************************************************/

void valor_lcd(int cont);
void valor_lcd1(int cont1);

/******************************************************************************/
/******************************************************************************/
/*--------------------- Espacio de codigo principal --------------------------*/
/******************************************************************************/ 
#zero_ram
void main(){
mcu_init(); 

lcd_init();                               // Inicializa microcontrolador

set_tris_d(0b00000000);
set_tris_c(0b11111111);
set_tris_b(0b00000000);
set_tris_a(0b11111111);



delay_ms(100);
lcd_putc("guille acevedo\n");
lcd_putc("walter moreno");

delay_ms(200);
lcd_putc("\f");

	while(1){
		dato=0;          // Retardo en milisegundos
		bandera=0;
		bandera1=0;
	 	if(input(sensor1)) dato=dato+1;
		if(input(sensor2)) dato=dato+2;
		if(input(sensor3)) dato=dato+4;
		if(input(sensor4)) dato=dato+8;

	lcd_putc("\f");
	switch (dato){
		case 0: 
			dato=0;
			valor_lcd(dato);
			break;
		case 1: 
			dato=25;
			valor_lcd(dato);
			break;
		case 3: 
			dato=50;
			valor_lcd(dato);
			break;
		case 7: 
			dato=75;
			valor_lcd(dato);
			break;
		case 15: 
			dato=100;
			valor_lcd(dato);
			break;
		default:
			bandera1=1;
			lcd_putc("\f");
			lcd_putc("sensores fallan");
			delay_ms(200);
	}
	lcd_putc("\n");
		 if(bandera1==0){
			dato1=0;          // Retardo en milisegundos
			 	if(input(in0)) dato1=dato1+1;
				if(input(in1)) dato1=dato1+2;
				if(input(in2)) dato1=dato1+4;
				if(input(in3)) dato1=dato1+8;
		
		
			switch (dato1){
				case 0: 
					dato1=0;
					break;
				case 1: 
					dato1=25;
					break;
				case 3: 
					dato1=50;
					break;
				case 7: 
					dato1=75;
					break;
				case 15: 
					dato1=100;
					break;
				default:
					bandera=1;
					dato1=dato;
			}
			if(dato1>dato){
				output_high(bombaLlen);
				output_low(bombaVac);
				lcd_putc(" llen=1 vac=0 ");
				delay_ms(100);		
			}
			else if(dato1<dato){
				output_low(bombaLlen);
				output_high(bombaVac);
				lcd_putc(" llen=0  vac=1 ");
				delay_ms(100);			
			}
			else{
				output_low(bombaLlen);
				output_low(bombaVac);
				lcd_putc(" llen=0  vac=0 ");
				delay_ms(100);	
			}
			if(bandera==1){
				lcd_putc("\f");
				lcd_putc("mal ingreso dato");
				delay_ms(200);	
			}
		}
		if(input(emerg)){
			break;
		}	
	}
	lcd_putc("\f");
	lcd_putc("emergencia");
	delay_ms(200);
}

void valor_lcd(int cont){
	int centenas = cont/100;
	int decenas = (cont%100)/10;
    int unidades = (cont%10);
	lcd_putc("dato= ");
	lcd_putc(centenas+0x30);
	lcd_putc(decenas+0x30);
	lcd_putc(unidades+0x30);
	lcd_putc("%");
}

