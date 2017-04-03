//========================================================
// Nombre del Programa: trabajo 2
// Autor:guillermo acevedo y walter moreno
// Fecha:07/02/17
//========================================================

#include "EMm47J53_StackConfig.h"
/********************************************************/
/*------- Espacio para declaracion de constantes  ------*/
/********************************************************/

#define in0 PIN_B0
#define in1 PIN_B1

/********************************************************/
/*--- Espacio para declaracion de variables globales  --*/
/********************************************************/

unsigned char contador=0;
int vector[16]={6,71,6,70,7,47,35,43,121,70,8,127,65,12,3,127};
int x,y,temp;
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
set_tris_a(0b00000000);
set_tris_b(0b11111111);



   	for(;;){
	dato=0;          // Retardo en milisegundos
	 	if(input(in0)) dato=dato+1;
		if(input(in1)) dato=dato+2;


	switch(dato){
	case 0:
     for(x=0; x<10;x++){
     	output_d(vector[0]);
		output_a(0);
		delay_ms(50);  
		output_d(vector[1]);
		output_a(1);
		delay_ms(50);  
		output_d(vector[2]);
		output_a(2);
		delay_ms(50);  
		output_d(vector[3]);
		output_a(3);
		delay_ms(50);  
	}
	for(y=0; y<15;y++){
     	temp=vector[y];
		vector[y]=vector[y+1];
		vector[y+1]=temp;
	}
	break;
	
	case 1:
	for(x=0; x<5;x++){
     	output_d(vector[0]);
		output_a(0);
		delay_ms(50);  
		output_d(vector[1]);
		output_a(1);
		delay_ms(50);  
		output_d(vector[2]);
		output_a(2);
		delay_ms(50);  
		output_d(vector[3]);
		output_a(3);
		delay_ms(50);  
	}
	for(y=0; y<15;y++){
     	temp=vector[y];
		vector[y]=vector[y+1];
		vector[y+1]=temp;
	}
	break;
	
	case 2:
	for(x=0; x<2;x++){
     	output_d(vector[0]);
		output_a(0);
		delay_ms(50);  
		output_d(vector[1]);
		output_a(1);
		delay_ms(50);  
		output_d(vector[2]);
		output_a(2);
		delay_ms(50);  
		output_d(vector[3]);
		output_a(3);
		delay_ms(50);  
	}
	for(y=0; y<15;y++){
     	temp=vector[y];
		vector[y]=vector[y+1];
		vector[y+1]=temp;
	}
	break;

	case 3:
	for(x=0; x<10;x++){
     	output_d(vector[0]);
		output_a(0);
		delay_ms(50);  
		output_d(vector[1]);
		output_a(1);
		delay_ms(50);  
		output_d(vector[2]);
		output_a(2);
		delay_ms(50);  
		output_d(vector[3]);
		output_a(3);
		delay_ms(50);  
	}
	for(y=15; y>0;y--){
     	temp=vector[y];
		vector[y]=vector[y-1];
		vector[y-1]=temp;
	}
	break;
	default:
	for(x=0; x<10;x++){
     	output_d(vector[0]);
		output_a(0);
		delay_ms(50);  
		output_d(vector[1]);
		output_a(1);
		delay_ms(50);  
		output_d(vector[2]);
		output_a(2);
		delay_ms(50);  
		output_d(vector[3]);
		output_a(3);
		delay_ms(50);  
	}
	for(y=15; y>0;y--){
     	temp=vector[y];
		vector[y]=vector[y-1];
		vector[y-1]=temp;
	}
	break;
	}
   }  
}
