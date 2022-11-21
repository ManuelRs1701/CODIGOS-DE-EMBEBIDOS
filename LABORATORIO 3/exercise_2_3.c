#include "stm32f3xx.h"			// Platform specific header (HW definition)
#include "lab3.h"						// Lab specific defines/declaration

#include <stdint.h>					// Standard Integer - data type definitions


void exercise_2_3(void){

	uint32_t count = 0;								// Simple counter variable
	
	//Configuracion de los leds
	RCC->AHBENR |= (1U<<17);					// Enable clock access to GPIOA
	
	GPIOA->MODER |=  (1U<<10);				// Configura el PA5 como salida
	GPIOA->MODER &= ~(1U<<11); 				
	
	GPIOA->MODER |=  (1U<<12);				// Configura el PA6 como salida
	GPIOA->MODER &= ~(1U<<13); 				
	
	GPIOA->MODER |=  (1U<<14);				// Configura el PA7 como salida
	GPIOA->MODER &= ~(1U<<15);
	
	GPIOA->MODER |=  (1U<<16);				// Configura el PA8 como salida
	GPIOA->MODER &= ~(1U<<17);
	
	GPIOA->ODR ^= (1U<<5);						// Toggle Output state of PA5
	
	//Configuracion de los botones
	RCC->AHBENR |= (1U<<19);					// Enable clock access to GPIOC
	
	GPIOC->MODER &= ~(1U<<26);				// Configura PC13 como entrada
	GPIOC->MODER &= ~(1U<<27); 				
	
	GPIOC->MODER &= ~(1U<<25);				// Configura PC12 como entrada
	GPIOC->MODER &= ~(1U<<24); 	
	

	GPIOC->ODR |= GPIO_PULLUP;
	
				
		
		// ------------------------------------------------------------------------------- //
		// 															Placeholder 1			 																 //
		// ------------------------------------------------------------------------------- //

		for(count = 0; count < g_waitcycles; count++) {	// Busy Loop Delay
			
			//configuracion de intercalado de los leds
	while(1) {
		GPIOA->ODR ^= (1U<<5);							// Toggle Output state of PA5
		GPIOA->ODR ^= (1U<<6);							// Toggle Output state of PA6
		
		if((GPIOC->IDR & (1U << 13)) != 0){
			GPIOA->ODR &= ~(1U<<6);						// Toggle Output state of PA6 y PA7
			GPIOA->ODR |= (1U<<7);
		}else{
			GPIOA->ODR &= ~(1U<<7);     			// Apaga el led en PA7
		}
		
		if((GPIOC->IDR & (1U<<14)) != 0){  	
			GPIOA->ODR &= ~(1U<<6);						// Toggle Output state of PA6 y PA8
			GPIOA->ODR |= (1U<<8);     				
		}else{
			GPIOA->ODR &= ~(1U<<8);     			// Apaga el led en PA8

		}
			// ------------------------------------------------------------------------------- //
			// 															Placeholder 2			 																 //
			// ------------------------------------------------------------------------------- //
			__NOP();	// Tells the compiler do not delete this empty loop
		}
	}
}
