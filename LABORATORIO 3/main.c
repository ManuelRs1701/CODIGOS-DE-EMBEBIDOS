#include <stdint.h>								// Standard Integer Library - Datatype definition

#include "lab3.h"									// Lab Header File for lab specific defines/declaration


// Global variables definition for the number of cycles of the busy loop
uint32_t g_waitcycles = WAIT_CYCLES * WAIT_INIT_MULTI; 

// Global variables for the Exercise 2.2
uint32_t exercise_2_counter = 0;


/*
*	@Brief Embedded Systems (ES) Lab 3
* 
* The goal of this lab is that the students get to know the platform
* STM32F3xx. This lab splits into following parts:
* Exercise 1.1: Flashing an existing application
* Exercise 1.2: Modifying an existing application
* Exercise 1.3: Adding a blinking LED RGB
* Exercise 2.1: Adding a input GPIO
* Exercise 2.2: GPIO Input Polling
* Exercise 2.3: Debugging
* Exercise 3:   Using Library functions instead of Bare Metal Programming
*/

int main(void) {
	
	//exercise_1_1();
	//exercise_1_2();
  //exercise_1_3();
	//exercise_2_1();
  //exercise_2_2();	
	//exercise_2_3();	
	exercise_3();
}
