/*
 * Ultrasonic_Atmega32.h
 *
 * Created: Sunday-22-Jan 8:42:24 PM
 *  Author: mohanad1
 */ 


#ifndef ULTRASONIC_ATMEGA32_H_
#define ULTRASONIC_ATMEGA32_H_

#include "Timer0.h"

#define ULTRASONIC_DIRECTION_REGISTER		DDRA
#define ULTRASONIC_PORT						PORTA
#define ULTRASONIC_PIN						PINA

#define ULTRASONIC_TRIGGER_PIN				0
#define ULTRASONIC_ECHO_PIN					3

void ULTRASONIC_Init(void);// initiate the 2 pins(TRIG,ECHO) used to interface the miro-controller with the ultrasonic sensor... e.g. ULTRASONIC_Init();
INT16U ULTRASONIC_Start_Trigger_and_Get_Distance(void);//start the trigger signal 10us high pulse then calculate the distance and returns it in INT16U	Distance_Measured... e.g. Distance = ULTRASONIC_Start_Trigger_and_Get_Distance();

#endif /* ULTRASONIC_ATMEGA32_H_ */
