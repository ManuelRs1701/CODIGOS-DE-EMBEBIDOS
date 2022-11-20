#include "lab4.h"								// Lab specific defines/declaration


/* Global variables */
volatile uint32_t count = 0;		// Variable to count interrupts produced by S1


void exercise_1(void) {
	
	//// Placeholder 1 /////////////////////////////////////////////////////////
  /* Configuring (LED2 green) and (LED2 blue) as output */
  ////////////////////////////////////////////////////////////////////////////
	RCC->AHBENR |= (1U<<17);					// Enable clock access to GPIOA
	
	GPIOA->MODER |=  (1U<<10);				// Configura el PA5 como salida
	GPIOA->MODER &= ~(1U<<11); 				
	
	GPIOA->MODER |=  (1U<<12);				// Configura el PA6 como salida
	GPIOA->MODER &= ~(1U<<13); 				

	//// Placeholder 2 /////////////////////////////////////////////////////////
  /* Configuring (USER BUTTON S1) as an input */
  ////////////////////////////////////////////////////////////////////////////
	RCC->AHBENR |= (1U<<19);
	
	GPIOC->MODER &= ~(1U<<27);				//Configura el PC13 como entrada
	GPIOC->MODER &= ~(1U<<26); 				
	
	GPIOC->MODER &= ~(1U<<25);				//Configura el PC12 como entrada
	GPIOC->MODER &= ~(1U<<24); 				
	
	GPIOC->ODR |= GPIO_PULLUP;				// es pull up 
	
	//// Placeholder 3 /////////////////////////////////////////////////////////
  /* Configure interrupts for buttons S1 and S2 */
  ////////////////////////////////////////////////////////////////////////////
	__disable_irq();								//deshabilita las interrupciones globalmente
	
	RCC->APB2ENR |= (1U<<0);				//habilita SYSCFG 
	
	SYSCFG->EXTICR[3] |= (1U<<5);		//habilita el EXTI13 para PC13
	EXTI->IMR |= (1U<<13);					//habilita el IMR para el EXTI13
	EXTI->RTSR |= (1U<<13);					//habilita el RTSR para el EXTI13 (genera interrupcion al soltar el boton)
	
	
	
	NVIC_EnableIRQ(EXTI15_10_IRQn);
	__enable_irq();
	//// Placeholder 4 /////////////////////////////////////////////////////////
  /* Enable interrupts for both GPIO */
  /* Enable interrupts on Ports 		 */
  /* Enable interrupts globally 		 */
  ////////////////////////////////////////////////////////////////////////////
	
	//// Placeholder 5 /////////////////////////////////////////////////////////
  /* Initially turn the LED2 green ON and the LED2 blue OFF */
	////////////////////////////////////////////////////////////////////////////
	
	//ENCIENDE EL LED Y APAGA EL OTRO
	GPIOA->ODR |= (1U<<5); 						//este enciende 
	GPIOA->ODR &= ~(1U<<6);						//este apaga
	GPIOA->ODR ^= (1U<<5); 						//este enciende 
	
	/* Code that is executed when processor is not busy with handling an interrupt */
	while(1) {
		// Sleep while waiting for an interrupt
		__WFI();
		// Do something after wake up				// Toggle Output state of PA5
		GPIOA->ODR ^= (1U<<5);				// Toggle Output state of PA6
	}
}


/*
**  EXT Interrupt 
*/ 
//void EXTI15_10_IRQHandler(void) {
	// From which line the interrupt was rised 
	// Toggle the LED blue
	// Increment the variable count 
	//count++;
	// Clear the interrupt flags
	//EXTI->PR |= (1U<<13);
//}
