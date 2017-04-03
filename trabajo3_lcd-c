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

#define in0 PIN_B0
#define in1 PIN_B1
#define in2 PIN_B2
#define in3 PIN_B3

/********************************************************/
/*--- Espacio para declaracion de variables globales  --*/
/********************************************************/

unsigned char contador=0;
int dato;

/********************************************************/
/********************************************************/
/*-------------- Espacio para funciones  ---------------*/
/********************************************************/

void valor_lcd(int cont);

/******************************************************************************/
/******************************************************************************/
/*--------------------- Espacio de codigo principal --------------------------*/
/******************************************************************************/ 
#zero_ram
void main(){
mcu_init(); 

lcd_init();                               // Inicializa microcontrolador

set_tris_d(0b00000000);
set_tris_e(0b00000000);
set_tris_b(0b00000000);


dato=1;
delay_ms(100);
lcd_putc("* hola WalGui *\n");
lcd_putc(" arquitectura ");

delay_ms(500);
lcd_putc("\f");
lcd_putc("ejemplo del LCD");
lcd_gotoxy(5,2);
lcd_putc("2x16");
delay_ms(500);
lcd_putc("\f");



	while(1){
		valor_lcd(contador);
		contador++;
		delay_ms(200);
		lcd_putc("\f");
	}
}

void valor_lcd(int cont){
	int centenas = cont/100;
	int decenas = (cont%100)/10;
    int unidades = (cont%10);
	lcd_gotoxy(5,1);
	lcd_putc("contador");
	lcd_gotoxy(7,2); 
	lcd_putc(centenas+0x30);
	lcd_putc(decenas+0x30);
	lcd_putc(unidades+0x30);
	
}