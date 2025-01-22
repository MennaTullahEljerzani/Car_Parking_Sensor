/*
 ============================================================================
 Name        : led.c
 Author      : Menna Tullah Medhat
 Description : The LED driver will control the red, green, and blue LEDs based
               on the light intensity. The required functions include
               initialization, turning LEDs on, and turning LEDs off.
 Date        : 10/6/2024
 ============================================================================
 */
#include "gpio.h"
#include "led.h"


/*Initializes all Leds (red, green, blue) pins direction.
  Turn off all the Leds*/
void LEDS_init(void){
	GPIO_setupPinDirection(LEDPORT_ID, LEDPIN1_ID, PIN_OUTPUT);
	GPIO_setupPinDirection(LEDPORT_ID, LEDPIN2_ID, PIN_OUTPUT);
	GPIO_setupPinDirection(LEDPORT_ID, LEDPIN3_ID, PIN_OUTPUT);

#if (LOGIC==POSITIVE_LOGIC)
	GPIO_writePin(LEDPORT_ID , LEDPIN1_ID, LOGIC_LOW);
	GPIO_writePin(LEDPORT_ID , LEDPIN2_ID, LOGIC_LOW);
	GPIO_writePin(LEDPORT_ID , LEDPIN3_ID, LOGIC_LOW);
 #else
	GPIO_writePin(LEDPORT_ID , LEDPIN1_ID, LOGIC_HIGH);
	GPIO_writePin(LEDPORT_ID , LEDPIN2_ID, LOGIC_HIGH);
	GPIO_writePin(LEDPORT_ID , LEDPIN3_ID, LOGIC_HIGH);
 #endif
}

/*Turns on the specified LED.*/
void LED_on(LED_ID id){
#if (LOGIC==POSITIVE_LOGIC)
	GPIO_writePin(LEDPORT_ID , id, LOGIC_HIGH);
 #else
	GPIO_writePin(LEDPORT_ID , id, LOGIC_LOW);
 #endif
}


/*Turns off the specified LED*/
void LED_off(LED_ID id){
#if (LOGIC==POSITIVE_LOGIC)
	GPIO_writePin(LEDPORT_ID , id, LOGIC_LOW);
 #else
	GPIO_writePin(LEDPORT_ID , id, LOGIC_HIGH);
 #endif
}

