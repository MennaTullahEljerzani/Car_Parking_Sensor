/*
 ============================================================================
 Name        : led.h
 Author      : Menna Tullah Medhat
 Description : The LED driver will control the red, green, and blue LEDs based
               on the light intensity. The required functions include
               initialization, turning LEDs on, and turning LEDs off.
 Date        : 10/6/2024
 ============================================================================
 */

#include "gpio.h"
#include "std_types.h"

#define LEDPORT_ID   PORTC_ID
#define LOGIC        POSITIVE_LOGIC
#define NEGATIVE_LOGIC  0
#define POSITIVE_LOGIC  1


typedef enum
{
	LEDPIN1_ID = 0,	LEDPIN2_ID = 1, LEDPIN3_ID = 2,
}LED_ID;

#ifndef LED_H_
#define LED_H_

/*Initializes all Leds (red, green, blue) pins direction.
  Turn off all the Leds*/
void LEDS_init(void);

/*Turns on the specified LED.*/
void LED_on(LED_ID id);

/*Turns off the specified LED*/
void LED_off(LED_ID id);

#endif /* LED_H_ */
