/*
 * main.c
 *
 * Created: Tuesday-24-Jan 2:36:45 AM
 *  Author: mohanad1
 */ 

#include "Servo_Motor_Atmega32.h"
#define F_CPU 8000000UL

int main(void)
{	
	sei();
	Servo_Motor_Init();
	
	usart_config_struct.baud_rate = rate_9600;
	usart_config_struct.characture_size= ch_8_bits;
	usart_config_struct.parity_mode = no_parity;
	usart_config_struct.stop_bits_select =  one_stop_bit;
	usart_config_struct.transmit_or_receive_enable = tx_and_rx;
	usart_config_struct.operation_mode = asynch_normal;
	usart_config_struct.interrupt_mode_select = uart_Tx_and_Rx_Complete_Interrupt_Enable;
	USART_Init(usart_config_struct);
		
	USART_Print_Debug_Message((INT8U*)__FUNCTION__,"debug message");
	
	while(1)
	{
		Servo_Motor_Get_Angle_From_Uart();
	}
return 0;
}