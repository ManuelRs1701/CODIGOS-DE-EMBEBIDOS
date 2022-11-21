#include "stm32f3xx.h"			// Platform specific header (HW definition)
#include "lab3.h"						// Lab specific defines/declaration

#include <stdint.h>					// Standard Integer - data type definitions


void exercise_1_2(void){

	uint32_t count = 0;								// Simple counter variable
	
	RCC->AHBENR |= (1U<<17);					// Enable clock access to GPIOA
	
	GPIOA->MODER |=  (1U<<10);			// Configure the GPIOA as output
	GPIOA->MODER &= ~(1U<<11); 			// Configure the GPIOA as output

	
	while(1) {
		GPIOA->ODR ^= (1U<<5);				// Toggle Output state of PA5
		
		// ------------------------------------------------------------------------------- //
		// 															Placeholder 1			 																 //
		// ------------------------------------------------------------------------------- //

		for(count = 0; count < g_waitcycles; count++) {	// Busy Loop Delay
			// ------------------------------------------------------------------------------- //
			// 															Placeholder 2			 																 //
			// ------------------------------------------------------------------------------- //
			__NOP();	// Tells the compiler do not delete this empty loop
		}
	}
}
