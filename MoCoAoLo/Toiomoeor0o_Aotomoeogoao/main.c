/*
 * Timer0_Atmega32.c
 *
 * Created: Wednesday-11-Jan 6:15:43 PM
 *  Author: mohanad1
 */ 
#include "Timer0.h"
#include "Timer0_Test_Cases.h"


int main(void){
SET_BIT(DDRF,3);//output
SET_BIT(PORTF,3)	;//set this pin PF3 to 1

Test_Case_One_Second();	//testing the one second blinking
//Test_Case_PWM();			//testing the PWM
	while (1)
	{
	}
	return 0;
}