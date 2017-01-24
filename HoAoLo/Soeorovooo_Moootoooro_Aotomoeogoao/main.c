/*
 * main.c
 *
 * Created: Tuesday-24-Jan 2:36:45 AM
 *  Author: mohanad1
 */ 

#include "Servo_Motor_Atmega32.h"
#define F_CPU 8000000UL
#include <util//delay.h>

int main(void)
{	
	sei();
	Servo_Motor_Init();
		
	while(1)
	{
		
		Servo_Motor_Rotate_In_Degrees(90);
				
	}
}