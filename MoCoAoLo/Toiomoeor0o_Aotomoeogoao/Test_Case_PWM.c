/*
 * PWM.c
 *
 * Created: Saturday-14-Jan 10:56:29 AM
 *  Author: mohanad1
 */ 
#define ON	1
#define OFF 0
#define TEST_CASE_PWM_SERVO	OFF

#if TEST_CASE_PWM_SERVO == ON	

#include "Timer0_Test_Cases.h"
INT16U OVF_count=0;
INT16U COMP_count=0;

ISR(TIMER0_OVF_vect){
		TCNT0=STRUCT_V_G_T0_config.TCNT0_value;	
}

ISR(TIMER0_COMP_vect){
		//CLEAR_BIT(PORTB,6);
}

void Test_Case_PWM(void){					/**************************el ON period feha error 0.07  ON=0.47 ms not 0.4 ms !**********************************/
	DDRB=0xff;//port b output
	DDRA=0xff;//port a output
	CLEAR_BIT(DDRB,2);//PB2 is input
	SET_BIT(PORTB,2);//set pull up resistor on PB2
		
	STRUCT_V_G_T0_config.pwm_mode=T0_PWM_MODE;
	STRUCT_V_G_T0_config.mode_of_operation=T0_FAST_PWM_MODE;
	STRUCT_V_G_T0_config.compare_output_mode=T0_CLEAR_OC0;
	STRUCT_V_G_T0_config.clock_select=T0_CLK_1024;//8M/1024 MHZ
	STRUCT_V_G_T0_config.OCR0_value=102;
	STRUCT_V_G_T0_config.TCNT0_value=99;
	
	TIMER0_Init(STRUCT_V_G_T0_config);
	sei();//set global interrupt
	TIMER0_Start();
	while(1)
    {	
    }
	return;
}
#endif