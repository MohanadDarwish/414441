/*
 * One_Second.c
 *
 * Created: Saturday-14-Jan 10:40:49 AM
 *  Author: mohanad1
 */ 
#define ON	1
#define OFF 0
#define TEST_CASE_ONE_SEC_TOGGLE	ON

#if TEST_CASE_ONE_SEC_TOGGLE == ON

#include "Timer0_Test_Cases.h"
INT16U OVF_count=0;
INT16U COMP_count=0;
ISR(TIMER0_OVF_vect){
	if (OVF_count==30)
	{
		TCNT0=127;
		OVF_count++;
	}
	else if (OVF_count==31)
	{
		TOGGLE_BIT(PORTA,0);
		OVF_count++;
		OVF_count=0;
	}
	else
	{
		OVF_count++;
	}
}

ISR(TIMER0_COMP_vect){
	//SET_BIT(PORTB,7);// i changed that seven from 6 !
}
void Test_Case_One_Second(void){	
	SET_BIT(DDRA,0);//PA0---> output
		
	STRUCT_V_G_T0_config.pwm_mode=1;
	STRUCT_V_G_T0_config.mode_of_operation=0;
	STRUCT_V_G_T0_config.compare_output_mode=0;
	STRUCT_V_G_T0_config.clock_select=T0_CLK_1024;//8M/1024 MHZ
	STRUCT_V_G_T0_config.U8_TIMER0_COUNTER_REGISTER_value=100;
	STRUCT_V_G_T0_config.U8_TIMER0_COMPARE_OUTPUT_REGISTER_value=0;
	STRUCT_V_G_T0_config.interrupt_mode= T0_INTERRUPT_OVF;
	
	TIMER0_Init(STRUCT_V_G_T0_config);
	sei();//set global interrupt
	TIMER0_Start();
	while(1)
    {	
    }
	return;
}
#endif