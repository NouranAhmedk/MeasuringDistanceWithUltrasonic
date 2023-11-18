 /******************************************************************************
 * Module: ULTRASONIC
 * File Name: ultrasonic.c
 * Description: Source file for the Ultrasonic driver
 * Author: Nouran Ahmed
 *******************************************************************************/

#ifndef HAL_ULTRASONIC_ULTRASONIC_H_
#define HAL_ULTRASONIC_ULTRASONIC_H_

#include "../../LIBRARY/std_types.h"

/*******************************************************************************
 *                                Definitions                                  *
 *******************************************************************************/
#define ULTRASONIC_TRIGGER_PORT_ID  PORTB_ID
#define ULTRASONIC_ECHO_PORT_ID     PORTD_ID
#define ULTRASONIC_TRIGGER_PIN_ID   PIN5_ID
#define ULTRASONIC_ECHO_PIN_ID      PIN6_ID

/*******************************************************************************
 *                            Functions Prototypes                             *
 *******************************************************************************/


/*initialization Function of the Ultrasonic driver*/
void Ultrasonic_init(void);
/*Trigger pulse to the ultrasonic.*/
void Ultrasonic_Trigger(void);
/*Implement distance measurements and return the distance*/
uint16 Ultrasonic_readDistance(void);
/*Call Back function*/
void Ultrasonic_edgeProcessing(void);

#endif /* HAL_ULTRASONIC_ULTRASONIC_H_ */
