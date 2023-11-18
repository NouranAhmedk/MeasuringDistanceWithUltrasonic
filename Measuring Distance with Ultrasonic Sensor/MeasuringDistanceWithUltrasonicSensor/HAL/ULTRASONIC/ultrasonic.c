 /******************************************************************************
 * Module: ULTRASONIC
 * File Name: Ultrasonic.c
 * Description: Source file for the ULTRASONIC driver
 * Author: Nouran Ahmed
 *******************************************************************************/

#include <util/delay.h>
#include"ultrasonic.h"
#include"../../MCAL/ICU/icu.h"
#include "../../MCAL/GPIO/gpio.h"

/*Global Variables*/
static volatile uint8 g_edgeCount = 0;
static uint16 timerValue;
static uint16 distance = 0;

void Ultrasonic_init(void){
	/* Create configuration structure for ICU driver */
	ICU_ConfigType ICU_Configurations = {F_CPU_8,RAISING};
	ICU_init(&ICU_Configurations);

	 /*Setup the ICU call back function*/
	ICU_setCallBack(Ultrasonic_edgeProcessing);

	/*Setup the direction for the trigger pin as output pin through the GPIO driver*/
	GPIO_setupPinDirection(ULTRASONIC_TRIGGER_PORT_ID,ULTRASONIC_TRIGGER_PIN_ID,PIN_OUTPUT); /* according to requirement set it as PIN_OUTPUT */

	/*Make sure the pin value is Zero*/
	GPIO_writePin(ULTRASONIC_TRIGGER_PORT_ID,ULTRASONIC_TRIGGER_PIN_ID, LOGIC_LOW);
}


void Ultrasonic_Trigger(void){

	/*Send trigger plus*/
	GPIO_writePin(ULTRASONIC_TRIGGER_PORT_ID,ULTRASONIC_TRIGGER_PIN_ID,LOGIC_HIGH);

	/*Transmit trigger pulse of at least 10 us*/
	_delay_us(10);

	/*trigger the plus*/
	GPIO_writePin(ULTRASONIC_TRIGGER_PORT_ID,ULTRASONIC_TRIGGER_PIN_ID,LOGIC_LOW);
}



uint16 Ultrasonic_readDistance(void){

	/*Send the trigger pulse by using Ultrasonic_Trigger function*/
      Ultrasonic_Trigger();

    /*Start the measurements by the ICU from this moment*/
	  while(g_edgeCount != 2);
	  g_edgeCount = 0;


  	/*   Distance = Speed x Time
	 *   Sound velocity = 340.00 m/s = 34000 cm/s
     *   The distance of Object (in cm) = 340000 ∗ Time
     *   Now, here we have selected an internal 8MHz oscillator frequency for ATmega16, with
	 *   Prescaler F_CPU/8 for timer frequency. Then time to execute 1 instruction is 1 us.
	 *   So, the timer gets incremented after 1 us time elapse.
	 *   = 17000 x (TIMER value) x 1 x 10^-6 cm
	 *   = 0.017 x (TIMER value) cm
	 *   = (TIMER value) / 58.8 cm
     */

      distance = 1 + (timerValue / 58);  /* Get approximate value because of the decimal*/
      return distance;
}


/*Call Back function*/
void Ultrasonic_edgeProcessing(void){

	/*increment the edges on every callback*/
	g_edgeCount++;
	if(g_edgeCount == 1)
	{
		/*
		 * Clear the timer counter register to start measurements from the
		 * first detected rising edge
		 */
		ICU_clearTimerValue();
		/* Detect falling edge */
		ICU_setEdgeDetectionType(FALLING);
	}
	else if(g_edgeCount == 2)
	{
		/* Store the High time value */
		timerValue = ICU_getInputCaptureValue();
		/* Detect rising edge */
		ICU_setEdgeDetectionType(RAISING);
		/* Clear the timer counter register to start measurements again */
		ICU_clearTimerValue();

	}

}

