//========================================================
// Nombre del Programa: trabajo 2
// Autor:guillermo acevedo y walter moreno
// Fecha:07/02/17
//========================================================

#include "EMm47J53_StackConfig.h"
/********************************************************/
/*------- Espacio para declaracion de constantes  ------*/
/********************************************************/



/********************************************************/
/*--- Espacio para declaracion de variables globales  --*/
/********************************************************/

unsigned char contador=0;
int vector[20]={0,119,119,119,0,65,62,62,62,65,0,63,63,63,63,1, 118, 118, 118,1};
int x,y,temp;
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
set_tris_a(0b00000000);
set_tris_b(0b00000000);



   	for(;;){
	  for(x=0;x<4;x++){
		output_b(x);
     	output_d(vector[0+(x*5)]);
		output_a(0);
		delay_us(50);  
		output_d(vector[1+(x*5)]);
		output_a(1);
		delay_us(50);  
		output_d(vector[2+(x*5)]);
		output_a(2);
		delay_us(50);  
		output_d(vector[3+(x*5)]);
		output_a(3);
		delay_us(50);
		output_d(vector[4+(x*5)]);
		output_a(4);
		delay_us(50);   

		}
   }  
}
