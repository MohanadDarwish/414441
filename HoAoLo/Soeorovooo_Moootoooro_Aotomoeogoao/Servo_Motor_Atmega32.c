/*
 * Servo_Motor_Atmega32.c
 *
 * Created: Tuesday-24-Jan 2:34:54 AM
 *  Author: mohanad1
 */ 

#include "Servo_Motor_Atmega32.h"

ISR(TIMER0_OVF_vect){

	TIMER0_Stop();
	TIMER0_Set_TIMER0_COUNTER_REGISTER_Val(6);
}

void Servo_Motor_Init(void)
{	
	SET_BIT(Servo_Motor_Direction_Port,Servo_Motor_Pin);
	STRUCT_V_G_T0_config.clock_select=T0_CLK_64;// 1 tick = 8us Tovf=2048 us
	STRUCT_V_G_T0_config.compare_output_mode=T0_CLEAR_OC0; //on compare clear the signal to low (non-inverting  ```|__
	STRUCT_V_G_T0_config.interrupt_mode=T0_INTERRUPT_OVF;
	STRUCT_V_G_T0_config.mode_of_operation=T0_FAST_PWM_MODE;
	STRUCT_V_G_T0_config.pwm_mode=T0_PWM_MODE;
	STRUCT_V_G_T0_config.U8_TIMER0_COUNTER_REGISTER_value=6;// count 6 ==> 48us(as if it is 0us because counter starts from 6) ,count 55=(55-6)*8 us =392 us ==> 0 degree
	STRUCT_V_G_T0_config.U8_TIMER0_COMPARE_OUTPUT_REGISTER_value=55;// by default OCR is on 0 degree ON from count 6 to count 55(392 us)
	
	TIMER0_Init(STRUCT_V_G_T0_config);
	
	return;
}
	
		/*****************************************************************************************************/
		/******************** PWM ON PERIOD MIN 1000us(1ms) AND MAXIMUM 2000us(2MS) **************************/
		/*****************************************************************************************************/

void Servo_Motor_Rotate_In_Degrees(INT8U Num_of_Degrees)	//e.g. Servo_Motor_Rotate_In_Degrees(num_of_degrees,direction);
{	
	if(Num_of_Degrees<=0)//55-6=49				49*8 us = 392 us for 0 degrees
	{
		TIMER0_Set_TIMER0_COMPARE_OUTPUT_REGISTER_Val(55);
	}
	else if(Num_of_Degrees==15)//137-6=131     131*8 us = 1048 us for 14.5 degrees
	{
		TIMER0_Set_TIMER0_COMPARE_OUTPUT_REGISTER_Val(137);
	}
	else if(Num_of_Degrees==30)//148-6=142     142*8 us = 1136 us for 30.8 degrees
	{
		TIMER0_Set_TIMER0_COMPARE_OUTPUT_REGISTER_Val(148);
	}
	else if(Num_of_Degrees==45)//158-6=152     152*8 us = 1216 us for 44.9 degrees
	{
		TIMER0_Set_TIMER0_COMPARE_OUTPUT_REGISTER_Val(158);
	}
	else if(Num_of_Degrees==60)//168-6=162     162*8 us = 1296 us for 60 degrees
	{
		TIMER0_Set_TIMER0_COMPARE_OUTPUT_REGISTER_Val(168);
	}
	else if(Num_of_Degrees==75)//178-6=172     172*8 us = 1376 us for 74.2 degrees
	{
		TIMER0_Set_TIMER0_COMPARE_OUTPUT_REGISTER_Val(178);
	}	
	else if(Num_of_Degrees==90)//189-6=183     183*8 us = 1464 us for 89.9 degrees
	{	
		TIMER0_Set_TIMER0_COMPARE_OUTPUT_REGISTER_Val(189);
	}
	else if(Num_of_Degrees==105)//199-6=193     193*8 us = 1544 us for 104 degrees
	{	
		TIMER0_Set_TIMER0_COMPARE_OUTPUT_REGISTER_Val(199);
	}
	else if(Num_of_Degrees==120)//209-6=203     203*8 us = 1624 us for 119 degrees
	{
		TIMER0_Set_TIMER0_COMPARE_OUTPUT_REGISTER_Val(209);
	}
	else if(Num_of_Degrees==135)//220-6=214     214*8 us = 1712 us for 135 degrees
	{
		TIMER0_Set_TIMER0_COMPARE_OUTPUT_REGISTER_Val(220);
	}
	else if(Num_of_Degrees==150)//231-6=225		225*8 us = 1800 us for 149 degrees
	{	
		TIMER0_Set_TIMER0_COMPARE_OUTPUT_REGISTER_Val(231);
	}
	else if(Num_of_Degrees==165)//241-6=235		235*8 us = 1880 us for 164 degrees
	{	
		TIMER0_Set_TIMER0_COMPARE_OUTPUT_REGISTER_Val(241);
	}
	else if(Num_of_Degrees>=180)//254-6=248     248*8 us = 1984 us for 180 degrees
	{
		TIMER0_Set_TIMER0_COMPARE_OUTPUT_REGISTER_Val(254);
	}
	else
	{
		TIMER0_Set_TIMER0_COMPARE_OUTPUT_REGISTER_Val( (Num_of_Degrees*123/178) + 127);// other degrees from 1 to 179 degrees  this equation will be evaluated and has error of +5%
	}
	TIMER0_Start();

	return;	
}
