#include "stm32f3xx.h"			// Platform specific header (HW definition)
#include "lab3.h"						// Lab specific defines/declaration

#include <stdint.h>					// Standard Integer - data type definitions

//--------------defs-----------------------------------------------------------------
#define RCC_BASE_ 					(0x40021000UL)										// Base address for the RCC 
#define GPIOA_BASE_					(0x48000000UL)										// Base address for the GPIOA

#define AHBEN_REG_OFFSET		(0x14UL)													// Offset address to get the RCCAHB REG
#define MODE_REG_OFFSET			(0x00UL)													// Offset address to get the MODER
#define OD_REG_OFFSET				(0x14UL)													// Offset address to get the ODR

#define RCC_AHBEN_REG 			(*(volatile uint32_t *)(RCC_BASE_ + AHBEN_REG_OFFSET))
#define GPIOA_MODE_REG 			(*(volatile uint32_t *)(GPIOA_BASE_ + MODE_REG_OFFSET))
#define GPIOA_OD_REG				(*(volatile uint32_t *)(GPIOA_BASE_ + OD_REG_OFFSET))
//--------------defs-----------------------------------------------------------------


void exercise_1_1(void){

	uint32_t count = 0;								// Simple counter variable
	
	RCC_AHBEN_REG |= (1U<<17);				// Enable clock access to GPIOA
	
	GPIOA_MODE_REG |=  (1U<<10);			// Configure the GPIOA as output
	GPIOA_MODE_REG &= ~(1U<<11); 			// Configure the GPIOA as output
	
	while(1) {
		GPIOA_OD_REG ^= (1U<<5);				// Toggle Output state of PA5
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
