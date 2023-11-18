/******************************************************************************
 * Project: Fan Controller System
 * File Name: main.c
 * Description: Application layer
 * Author: Nouran Ahmed
 *******************************************************************************/
#include "LIBRARY/atmega_32.h"
#include "HAL/LCD/lcd.h"
#include "HAL/ULTRASONIC/ultrasonic.h"

int main(void) {
	uint16 distance;
    SREG_REG.bits.I_BIT=1;
	LCD_init();
	Ultrasonic_init();
	LCD_displayString("Distance =    cm");

	while (1) {
		LCD_moveCursor(0, 11);
		distance = Ultrasonic_readDistance();
		if (distance >= 100) {
			LCD_integerToString(distance);
		} else {
			LCD_integerToString(distance);
			/* In case the digital value is two or one digits print space in the next digit place */
			LCD_displayCharacter(' ');
		}
	}
	return 0;
}

