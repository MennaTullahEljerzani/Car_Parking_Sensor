/*
 ============================================================================
 Name        : ultrasonic.h
 Author      : Menna Tullah Medhat
 Description : Car Parking Sensor Using ATmega32, Ultrasonic Sensor,
               LCD Display, LEDs, and Buzzer. The aim of this project is to
               design a simple car parking sensor system
 Date        : 13/6/2024
 ============================================================================
 */

#include <avr/io.h>
#include "buzzer.h"
#include "led.h"
#include "lcd.h"
#include <util/delay.h>
#include "std_types.h"
#include "ultrasonic.h"

int main(void)
{
	/*Distance <= 5 cm: All LEDs are flashing (Red, Green, Blue), Buzzer
	sounds, LCD shows "Stop."
	6 cm <= Distance <= 10 cm: All LEDs ON (Red, Green, Blue), No
	buzzer.
	11 cm <= Distance <= 15 cm: Red and Green LEDs ON, Blue LED OFF.
	16 cm <= Distance <= 20 cm: Only Red LED ON, others OFF.
	Distance > 20 cm: All LEDs OFF, Buzzer OFF	*/
	uint16 distance_measured=0;
	LCD_init();/*initiate the lcd*/
	Buzzer_init();/*initiate the buzzer*/
	LEDS_init();/*initiate the LEDs*/
	Ultrasonic_init();/*initiate the ultrasonic sensor*/

	LCD_clearScreen();

	for(;;)
	{
		distance_measured = Ultrasonic_readDistance() + 1; /* Read the distance */
		LCD_displayString("Distance= ");

		/* Display the distance and control the LEDs and buzzer based on distance */
		LCD_moveCursor(0, 10); /* Move cursor to the distance position */
		LCD_intgerToString(distance_measured);

		if (distance_measured < 10)
		{
			LCD_moveCursor(0, 11);
			LCD_displayString("  ");
		}
		else
		{
			LCD_displayCharacter(' ');
		}

		LCD_displayString(" cm");

		if (distance_measured > 20)
		{
			Buzzer_off();
			LED_off(LEDPIN1_ID);
			LED_off(LEDPIN2_ID);
			LED_off(LEDPIN3_ID);
		}
		else if (distance_measured <= 20 && distance_measured >= 16)
		{
			Buzzer_off();
			LED_on(LEDPIN1_ID);
			LED_off(LEDPIN2_ID);
			LED_off(LEDPIN3_ID);
		}
		else if (distance_measured <= 15 && distance_measured >= 11)
		{
			Buzzer_off();
			LED_on(LEDPIN1_ID);
			LED_on(LEDPIN2_ID);
			LED_off(LEDPIN3_ID);
		}
		else if (distance_measured <= 10 && distance_measured >= 6)
		{
			Buzzer_off();
			LED_on(LEDPIN1_ID);
			LED_on(LEDPIN2_ID);
			LED_on(LEDPIN3_ID);
			LCD_displayStringRowColumn(1,0,"                ");
		}
		else if (distance_measured <= 5) /* Corrected logic: distance <= 5 cm */
				{
			//LCD_clearScreen(); /* Clear the LCD screen */
			LCD_moveCursor(1, 6); /* Move to the second line */
			LCD_displayString("Stop       "); /* Display "Stop" on the first line */
			Buzzer_on();
			LED_on(LEDPIN1_ID);
			LED_on(LEDPIN2_ID);
			LED_on(LEDPIN3_ID);
			_delay_ms(100);
			Buzzer_off();
			LED_off(LEDPIN1_ID);
			LED_off(LEDPIN2_ID);
			LED_off(LEDPIN3_ID);
				}
		else
		{
			LCD_intgerToString(distance_measured); /* Display the distance */
			LCD_displayString(" cm");
		}
	}
}
