//========================================================
// Nombre del Programa: lab2
// Autor:guillermo acevedo y walter moreno
// Fecha:07/02/17
//========================================================

#include "EMm47J53_StackConfig.h"
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
int vector[17]={64,121,36,48,25,18,2,120,0,16,8,3,70,33,6,14,119};
int x,y,temp;
int dato,dato1,dato2,resul;
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
set_tris_b(0b11111111);



   	for(;;){
	dato=0;          // Retardo en milisegundos
	dato1=0;  
	dato2=0;    
	 	if(input(in0)){ 
			dato=dato+1;
			dato1=dato1+1;
		}
		if(input(in1)){
			 dato=dato+2;
			dato1=dato1+2;
		}
		if(input(in2)){
			 dato=dato+4;
			dato2=dato2+1;
		}
		if(input(in3)){
			 dato=dato+8;
			dato2=dato2+2;
		}

		resul=dato1*dato2;
		
     	output_d(vector[0]);
		output_a(0);
		delay_ms(50);  
		output_d(vector[resul]);
		output_a(1);
		delay_ms(50);  
		output_d(vector[16]);
		output_a(2);
		delay_ms(50);  
		output_d(vector[dato]);
		output_a(3);
		delay_ms(50);  

	
   }  
}
