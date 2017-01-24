/*
 * Servo_Motor_Atmega32.h
 *
 * Created: Tuesday-24-Jan 2:36:28 AM
 *  Author: mohanad1
 */ 


#ifndef SERVO_MOTOR_ATMEGA32_H_
#define SERVO_MOTOR_ATMEGA32_H_


#include "STD_Data_Types.h"
#include "STD_Macros.h"
#include "Timer0.h"

#define Servo_Motor_Output_Port		PORTB	//timer0 port
#define Servo_Motor_Direction_Port	DDRB	// should be always output and set in the timer0 driver
#define Servo_Motor_Pin				3	//PB3 --> oc0

void Servo_Motor_Init(void);
void Servo_Motor_Rotate_In_Degrees(INT8U);//e.g. Servo_Motor_Rotate_In_Degrees(num_of_degrees,direction);



#endif /* SERVO_MOTOR_ATMEGA32_H_ */