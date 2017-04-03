//========================================================
// Nombre del Programa:
// Autor:
// Fecha:
//========================================================

#include "EMm47J53_StackConfig.h"
/********************************************************/
/*------- Espacio para declaracion de constantes  ------*/
/********************************************************/

/********************************************************/
/*--- Espacio para declaracion de variables globales  --*/
/********************************************************/

unsigned char contador=0;
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



   for(;;){ 
     contador++;              // Incrementa variable contador
     output_d(contador);      // Saca por leds lo que contiene variable contador
     delay_ms(50);            // Retardo en milisegundos
   }  
}