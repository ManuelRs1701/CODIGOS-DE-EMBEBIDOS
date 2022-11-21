#include "stm32f3xx_hal.h"
#include "lab3.h"					// Lab specific defines/declarations
#include "stm32f3xx_hal_gpio.h"
#include <stdint.h>				// Standard Integer - data type definitions


void exercise_3(void) {

	uint32_t count = 0;			// Simple counter variable

	setup_rcc();						// Helper function to setup the RCC
	setup_gpio();						// Helper function to setup the GPIOs
	
	HAL_GPIO_WritePin(GPIOA, GPIO_PIN_5, GPIO_PIN_SET);

	while(1) {
		// ------------------------------------------------------------------------------- //
		// 															Placeholder 1			 																 //
		// ------------------------------------------------------------------------------- //
		HAL_GPIO_TogglePin(GPIOA, GPIO_PIN_5);
		HAL_GPIO_TogglePin(GPIOA, GPIO_PIN_6);
		
		if(HAL_GPIO_ReadPin(GPIOC, GPIO_PIN_13) == 0){
			HAL_GPIO_WritePin(GPIOA, GPIO_PIN_6, GPIO_PIN_RESET);			// apaga el led del PA6
			HAL_GPIO_WritePin(GPIOA, GPIO_PIN_7, GPIO_PIN_SET);				// enciende el led del PA7
		}else{
			HAL_GPIO_WritePin(GPIOA, GPIO_PIN_7, GPIO_PIN_RESET);	    // apaga el led del PA7	
		}
		
		if(HAL_GPIO_ReadPin(GPIOC, GPIO_PIN_12) == 0){  
			HAL_GPIO_WritePin(GPIOA, GPIO_PIN_6, GPIO_PIN_RESET);			// apaga el led del PA6
			HAL_GPIO_WritePin(GPIOA, GPIO_PIN_8, GPIO_PIN_SET);			  // enciende el led del PA8
		}else{
			HAL_GPIO_WritePin(GPIOA, GPIO_PIN_8, GPIO_PIN_RESET);     // apaga el led del PA8

		}

		for(count = 0; count < g_waitcycles; count++) {
			// ------------------------------------------------------------------------------- //
			// 															Placeholder 2			 																 //
			// ------------------------------------------------------------------------------- //
			__NOP(); // Tells the compiler do not delete this empty loop
		}
	}
}

/* 
*	@brief Embedded Systems (ES) Lab 3
* Helper Functions
* Exercise 3
*/
void setup_rcc(void) {
	__HAL_RCC_GPIOA_CLK_ENABLE(); 					//Configura el acceso del clock al GPIOA
	__HAL_RCC_GPIOC_CLK_ENABLE(); 					//Configura el acceso del clock al GPIOC
}

void setup_gpio(void){
	//SETUP LEDS
	GPIO_InitTypeDef leds = {0}; 
	
  leds.Pin = GPIO_PIN_5 | GPIO_PIN_6 | GPIO_PIN_7 | GPIO_PIN_8; 							// Inicializa todos los leds				
	leds.Mode = GPIO_MODE_OUTPUT_PP; 																						// Output Push Pull Mode
	leds.Pull = GPIO_NOPULL; 																										// No Pull-up or Pull-down activation
	leds.Speed = GPIO_SPEED_FREQ_LOW;
	HAL_GPIO_Init(GPIOA, &leds);
	
	//SETUP BUTTONS
	GPIO_InitTypeDef buttons = {0}; 
	
  buttons.Pin = GPIO_PIN_13 | GPIO_PIN_12; 								// Inicializa los botones PC13 Y PC12
	buttons.Mode = GPIO_MODE_INPUT; 												// configura como entrada
	buttons.Pull = GPIO_PULLUP; 														// configura como pull up

	HAL_GPIO_Init(GPIOC, &buttons);
}

