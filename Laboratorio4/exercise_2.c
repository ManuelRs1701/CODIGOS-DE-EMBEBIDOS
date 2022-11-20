
#include "lab4.h"								// Lab specific defines/declaration

/* Global variables */
volatile bool button1_flag;			// Flag to indicate that button S1 has been pressed
volatile bool button2_flag;			// Flag to indicate that button S2 has been pressed
volatile uint32_t count1 = 0;		// Variable to count interrupts produced by S1
volatile uint32_t count2 = 0;		// Variable to count interrupts produced by S2


void exercise_2(void) {

	
	//// Placeholder 1 /////////////////////////////////////////////////////////
  /* Configuring (LED2 green) and (LED2 blue) as output */
  ////////////////////////////////////////////////////////////////////////////
	setup_leds();

  //// Placeholder 2 /////////////////////////////////////////////////////////
  /* Configuring (USER BUTTON S1) and (Button S2) as an input */
  ////////////////////////////////////////////////////////////////////////////
	setup_buttons();
	

  /* Code that is executed when processor is not busy with handling an interrupt */
	while(1) {
		// Sleep while waiting for an interrupt
		__WFI();
		// after interrupt ocurred
		if (button1_flag) {
			/* Increase counter for button S1  */
			count1 += 1;
			button1_flag = false;
		}
		if (button2_flag) {
			/* Increase counter for button S2 */
			
			count2 += 1;
			button2_flag = false;
		}
	}
}


/*
** EXT Interrupt Service Routine
*/ 
void EXTI15_10_IRQHandler(void) {
	//// Pseudocode 1  ///////////////////////////////////////////////
  if ((EXTI->PR & (1U<<13)) != 0) {
  //  toggleGreenLED();
	HAL_GPIO_WritePin(GPIOA, GPIO_PIN_5, GPIO_PIN_SET);
  //  setFlagForButton1();
  //  clearInterruptFlag();
	button1_flag = true;
  }
  else if ((EXTI->PR & (1U<<12)) != 0) {
   //   toggleBlueLED();
	HAL_GPIO_WritePin(GPIOA, GPIO_PIN_6, GPIO_PIN_SET);
   //   setFlagForButton2();
   //   clearInterruptFlag();
	button2_flag = false;
  }
  ////////////////////////////////////////////////////////////////////////////
}
	

