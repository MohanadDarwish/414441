/*
 * Timer0.h
 *
 * Created: Wednesday-11-Jan 6:17:26 PM
 *  Author: mohanad1
 */ 


#ifndef TIMER0_H_
#define TIMER0_H_

#include<avr/interrupt.h>
#define F_CPU 8000000UL
#include <util/delay.h>
#include <avr/io.h>

#include "STD_Data_Types.h"
#include "STD_Macros.h"

#define  ATMEGA  32

enum timer0_mode_of_operation{
	T0_NORMAL_MODE,//0
	T0_PHASE_CORRECT_PWM_MODE,//1
	T0_CLEAR_TIMER_ON_COMPARE_MATCH_MODE,//2
	T0_FAST_PWM_MODE//3
	};
	
enum timer0_PWM_mode{
	T0_NON_PWM_MODE,//0
	T0_PWM_MODE//1
	};
	
enum timer0_compare_output_mode{
	T0_OC0_DISCONNECTED,//0
	T0_TOGGLE_OC0,//1
	T0_CLEAR_OC0,//2
	T0_SET_OC0//3
	};
	
enum timer0_clock_select{
	T0_NO_CLOCK_SOURCE,//0
	T0_CLK_NO_PRESCALE,//1
	T0_CLK_8,//2
	T0_CLK_64,//3
	T0_CLK_256,//4
	T0_CLK_1024,//5
	T0_EXTERNAL_CLK_FALLING,//6
	T0_EXTERNAL_CLK_RISING//7
	};

enum timer0_interrupts{
	T0_INTERRUPT_OVF,			//0
	T0_INTERRUPT_OCR,			//1
	T0_INTERRUPT_OVF_AND_OCR	//2
	};

//config struct
typedef struct timer0_configuration_struct{
	enum timer0_PWM_mode pwm_mode;
	enum timer0_mode_of_operation mode_of_operation;
	enum timer0_compare_output_mode compare_output_mode;
	enum timer0_clock_select clock_select;
	enum timer0_interrupts interrupt_mode;
	INT8U U8_TIMER0_COMPARE_OUTPUT_REGISTER_value;
	INT8U U8_TIMER0_COUNTER_REGISTER_value;
	}timer0_configuration_struct;

volatile timer0_configuration_struct STRUCT_V_G_T0_config;// struct variable created in stack and initialized in the file calling this driver
#if ATMEGA == 32
	#define     TIMER0_CONTROL_REGISTER                    TCCR0
	#define     WAVEFORM_GENERATION_MODE_BIT_ZERO          WGM00
	#define     WAVEFORM_GENERATION_MODE_BIT_ONE           WGM01
	#define     COMPARE_OUTPUT_MODE_BIT_ZERO               COM00
	#define     COMPARE_OUTPUT_MODE_BIT_ONE                COM01
	#define     TIMER0_INTERRUPT_MASK_REGISTER             TIMSK
	#define     TIMER0_OVERFLOW_INTERRUPT                  TOIE0
	#define     TIMER0_COMPARE_INTERRUPT                   OCIE0
	#define     TIMER0_CLOCK_SELECT_BIT_ZERO               CS00
	#define     TIMER0_CLOCK_SELECT_BIT_ONE                CS01
	#define     TIMER0_CLOCK_SELECT_BIT_TWO                CS02
	#define     TIMER0_COUNTER_REGISTER                    TCNT0
	#define     TIMER0_COMPARE_OUTPUT_REGISTER             OCR0
	#define     TIMER0_INTERRUPT_FLAG_REGISTER             TIFR
	#define     TIMER0_OUTPUT_COMPARE_INTERRUPT_FLAG       OCF0
	#define     TIMER0_OVERFLOW_INTERRUPT_FLAG             TOV0
	#define     TIMER0_SPECIAL_FUNCTION_IO_REGISTER        SFIOR
	#define     TIMER0_PRESCALER_RESET                     PSR10
#elif ATMEGA == 128
	#define     TIMER0_CONTROL_REGISTER                    TCCR0
	#define     WAVEFORM_GENERATION_MODE_BIT_ZERO          WGM00
	#define     WAVEFORM_GENERATION_MODE_BIT_ONE           WGM01
	#define     COMPARE_OUTPUT_MODE_BIT_ZERO               COM00
	#define     COMPARE_OUTPUT_MODE_BIT_ONE                COM01
	#define     TIMER0_INTERRUPT_MASK_REGISTER             TIMSK
	#define     TIMER0_OVERFLOW_INTERRUPT                  TOIE0
	#define     TIMER0_COMPARE_INTERRUPT                   OCIE0
	#define     TIMER0_CLOCK_SELECT_BIT_ZERO               CS00
	#define     TIMER0_CLOCK_SELECT_BIT_ONE                CS01
	#define     TIMER0_CLOCK_SELECT_BIT_TWO                CS02
	#define     TIMER0_COUNTER_REGISTER                    TCNT0
	#define     TIMER0_COMPARE_OUTPUT_REGISTER             OCR0
	#define     TIMER0_INTERRUPT_FLAG_REGISTER             TIFR
	#define     TIMER0_OUTPUT_COMPARE_INTERRUPT_FLAG       OCF0
	#define     TIMER0_OVERFLOW_INTERRUPT_FLAG             TOV0
	#define     TIMER0_SPECIAL_FUNCTION_IO_REGISTER        SFIOR
	#define     TIMER0_PRESCALER_RESET                     0//PSR0

#endif

void TIMER0_Init(timer0_configuration_struct);	//This function initialize the timer0 with a predefinied configuration struct...				e.g. TIMER0_Init(STRUCT_V_G_T0_config);

void TIMER0_Start(void);	//This function starts the timer0 by enabling the clock with the predefinied setting in the configuration struct...	e.g. TIMER0_Start();
void TIMER0_Stop(void);		//This function stops the timer0 by disabling the clock ...															e.g. TIMER0_Stop();
void TIMER0_Clear(void);	//This function clears the counters of timer0 by setting the counter to its initial value...						e.g. TIMER0_Clear();
void TIMER0_Reset(void);	//This function starts the timer0 by enabling the clock with the predefinied setting in the configuration struct...	e.g. TIMER0_Reset();

void TIMER0_Time_To_OVF(double t_ovf);	//This function calulate the needed configuration to meet the desired overflow time passed to it...					e.g. TIMER0_Time_To_OVF(0.0020); "20us"
void TIMER0_Set_TIMER0_COMPARE_OUTPUT_REGISTER_Val(INT8U val);	//This function sets the timer0 compare output register with a new value and updating it in the configuration struct...	e.g. TIMER0_Set_Timer0_COMPARE_OUTPUT_REGISTER_Val( new_val_of_compare_register);
void TIMER0_Set_TIMER0_COUNTER_REGISTER_Val(INT8U val);	//This function sets the timer0 counter register with a new value and updating it in the configuration struct...	e.g. TIMER0_Set_Timer0_COUNTER_REGISTER_Val( new_val_of_counter);
void TIMER0_Enable_OVF_INT();	//This function enable the timer0 overflow interrupt by setting the enable bit to 1 ...					e.g. TIMER0_Enable_OVF_INT();
void TIMER0_Enable_OCR_INT();	//This function ensable the timer0 output compare match interrupt by setting the enable bit to 1 ...	e.g. TIMER0_Enable_OCR_INT();
void TIMER0_Disable_OVF_INT();	//This function disable the timer0 overflow  interrupt by clearing the enable bit to 0 ...				e.g. TIMER0_Disable_OVF_INT();
void TIMER0_Disable_OCR_INT();	//This function disable the timer0 output compare match interrupt by clearing the enable bit to 0 ...	e.g. TIMER0_Disable_OCR_INT();
#endif /* TIMER0_H_ */
