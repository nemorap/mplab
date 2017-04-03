//========================================================
// Nombre del Programa:
// Autor:
// Fecha:
//========================================================

#include "EMm47J53_StackConfig.h"
/********************************************************/
/*------- Espacio para declaracion de constantes  ------*/
/********************************************************/
#define in0 PIN_A0
#define in1 PIN_A1
#define in2 PIN_A2
#define in3 PIN_A3

/********************************************************/
/*--- Espacio para declaracion de variables globales  --*/
/********************************************************/

unsigned char contador=0;
int dato;
/********************************************************/
/********************************************************/
/*-------------- Espacio para funciones  ---------------*/
/********************************************************/



/******************************************************************************/
/******************************************************************************/
/*--------------------- Espacio de codigo principal --------------------------*/
/******************************************************************************/ 
#zero_ram
void main(){
mcu_init();                                // Inicializa microcontrolador

set_tris_d(0b00000000);
set_tris_c(0b00000000);
set_tris_a(0b11111111);


   	for(;;){ 
     	dato=0;          // Retardo en milisegundos
	 	if(input(in0)) dato=dato+1;
		if(input(in1)) dato=dato+2;
		if(input(in2)) dato=dato+4;
		if(input(in3)) dato=dato+8;

		output_d(dato);
   }  
}