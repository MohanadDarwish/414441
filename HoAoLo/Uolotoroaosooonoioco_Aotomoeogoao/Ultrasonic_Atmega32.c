/*
 * Ultrasonic_Atmega32.c
 *
 * Created: Sunday-22-Jan 8:41:41 PM
 *  Author: mohanad1
 */ 
#include "Ultrasonic_Atmega32.h"

#define TRIGGER 0
#define CALCULATING_ECHO_PULSE_WIDTH 1

volatile INT8U OVF_count=0;
volatile INT8U Distance_In_CM = 2; //2cm initially ==> 150us
volatile INT8U timer0_ultasonic_mode = TRIGGER;

ISR(TIMER0_OVF_vect){
	OVF_count++;
	if(timer0_ultasonic_mode== TRIGGER)
	{
		CLEAR_BIT(ULTRASONIC_PORT,ULTRASONIC_TRIGGER_PIN);//clearing the trigger pin after 10 counts 245-->255 == 10us
		timer0_ultasonic_mode=CALCULATING_ECHO_PULSE_WIDTH;
		OVF_count=0;
	}
	else if (	(timer0_ultasonic_mode==CALCULATING_ECHO_PULSE_WIDTH) && (OVF_count==62)	)
	{	
		Distance_In_CM++;
		OVF_count=0;
	}
}//end of OVF_ISR

void ULTRASONIC_Init(){
	SET_BIT(ULTRASONIC_DIRECTION_REGISTER,ULTRASONIC_TRIGGER_PIN);//Trigger pin ==>output pin PA0
	CLEAR_BIT(ULTRASONIC_DIRECTION_REGISTER,ULTRASONIC_ECHO_PIN);//ECHO pin <==input pin PA3		
	return;
}

INT16U ULTRASONIC_Start_Trigger_and_Get_Distance(){
	INT16U Distance_Measured=0x0000;// no obstacle Distance_Measured = 0 //distance more than 500cm ==> no obstacle
	
	STRUCT_V_G_T0_config.clock_select=T0_CLK_8;
	STRUCT_V_G_T0_config.compare_output_mode=T0_OC0_DISCONNECTED;
	STRUCT_V_G_T0_config.interrupt_mode=T0_INTERRUPT_OVF;
	STRUCT_V_G_T0_config.mode_of_operation=T0_NORMAL_MODE;
	STRUCT_V_G_T0_config.pwm_mode=T0_NON_PWM_MODE;
	STRUCT_V_G_T0_config.U8_TIMER0_COUNTER_REGISTER_value=245;//from 245 to 255 10 counts 10*1us = 10us the trigger pulse
	
	TIMER0_Init(STRUCT_V_G_T0_config);
	
	SET_BIT(ULTRASONIC_PORT,ULTRASONIC_TRIGGER_PIN);// starting the trigger signal from count 245 to 255 and clearing the signal in the ISR_OVF()
	TIMER0_Start();
	while(! GET_BIT(ULTRASONIC_PIN,ULTRASONIC_ECHO_PIN)	);
	TIMER0_Stop();
	if(Distance_In_CM<500)//distance less than 500cm ==> there is an obstacle
	{
		Distance_Measured = Distance_In_CM;// no obstacle Distance_Measured = 0
	}
	return Distance_Measured;
}
