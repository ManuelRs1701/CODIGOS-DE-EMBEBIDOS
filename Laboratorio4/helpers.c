#include "lab4.h"						// Lab specific defines/declaration


void setup_leds(void) {
	// Clock enable
	__HAL_RCC_GPIOA_CLK_ENABLE(); 					//Configura el acceso del clock al GPIOA
	
	// Configure the GPIO as output
	GPIO_InitTypeDef leds = {0};
  leds.Pin = GPIO_PIN_5 | GPIO_PIN_6; 							// Inicializa todos los leds				
	leds.Mode = GPIO_MODE_OUTPUT_PP; 									// Output Push Pull Mode
	leds.Pull = GPIO_NOPULL; 													// No Pull-up or Pull-down activation
	leds.Speed = GPIO_SPEED_FREQ_LOW;
	HAL_GPIO_Init(GPIOA, &leds);
	

	
	//// Placeholder  //////////////////////////////////////////////////////////
  /* Initially turn LEDs off */
  ////////////////////////////////////////////////////////////////////////////
	HAL_GPIO_WritePin(GPIOA, GPIO_PIN_5, GPIO_PIN_RESET);
	HAL_GPIO_WritePin(GPIOA, GPIO_PIN_6, GPIO_PIN_RESET);
}


void setup_buttons(void) {
	// Clock enable
	__HAL_RCC_GPIOC_CLK_ENABLE(); 					//Configura el acceso del clock al GPIOA
	
	// Configure the GPIO as input
	GPIO_InitTypeDef buttons = {0}; 
	
  buttons.Pin = GPIO_PIN_13 | GPIO_PIN_12; 								// Inicializa los botones
	buttons.Mode = GPIO_MODE_IT_FALLING; 										// Output Push Pull Mode
	buttons.Pull = GPIO_PULLUP; 														// No Pull-up or Pull-down activation

	HAL_GPIO_Init(GPIOC, &buttons);
	
	//// Placeholder 3 /////////////////////////////////////////////////////////
  /* Configure interrupts for buttons S1 and S2 */
  ////////////////////////////////////////////////////////////////////////////
	HAL_NVIC_SetPriority(EXTI15_10_IRQn, 0, 0);
	HAL_NVIC_EnableIRQ(EXTI15_10_IRQn);
	

	
	
	//// Placeholder 4 /////////////////////////////////////////////////////////
  /* Enable interrupts for both GPIO */
  /* Enable interrupts on Ports 		 */
  /* Enable interrupts globally 		 */
  ////////////////////////////////////////////////////////////////////////////

}

	
