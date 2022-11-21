#include "stm32f3xx.h"			// Platform specific header (HW definition)
#include "lab3.h"						// Lab specific defines/declaration

#include <stdint.h>					// Standard Integer - data type definitions


void exercise_2_1(void){

	uint32_t count = 0;								// Simple counter variable
	
	RCC->AHBENR |= (1U<<17);					// Enable clock access to GPIOA
	
	GPIOA->MODER |=  (1U<<10);				// Configure the GPIOA as output
	GPIOA->MODER &= ~(1U<<11); 				// Configure the GPIOA as output
	
	GPIOA->MODER |=  (1U<<12);				// Configure the GPIOA as output
	GPIOA->MODER &= ~(1U<<13); 				// Configure the GPIOA as output
	
	GPIOA->ODR ^= (1U<<5);						// Toggle Output state of PA5
	
	RCC->AHBENR |= (1U<<19);					// Enable clock access to GPIOC
	
	GPIOC->MODER &= ~(1U<<26);				// Configure the GPIOA as input
	GPIOC->MODER &= ~(1U<<27); 				// Configure the GPIOA as input
	
	GPIOC->PUPDR |= (1U<<26);
	GPIOC->PUPDR &= ~(1U<<27);
	
	
	while(1) {
		GPIOA->ODR ^= (1U<<5);				// Toggle Output state of PA5
		GPIOA->ODR ^= (1U<<6);			  // Toggle Output state of PA6
		
		if(GPIOC->ODR &= GPIO_ODR_13){
			GPIOA->ODR &= ~(1U<<5);				// Toggle Output state of PA5
			
		}else{
		
		}	
			
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
