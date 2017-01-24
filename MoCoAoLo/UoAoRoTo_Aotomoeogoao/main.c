/*
 * UART_Atmega128.c
 *
 * Created: 04/01/2017 03:13:45 م
 *  Author: DELL
 */ 



#include "UART.h"
#include <util/delay.h>

int main(void)
{ 
   usart_config_struct.baud_rate = rate_9600;
   usart_config_struct.characture_size= ch_8_bits;
   usart_config_struct.parity_mode = no_parity;
   usart_config_struct.stop_bits_select =  one_stop_bit;
   usart_config_struct.transmit_or_receive_enable = tx_and_rx;
   usart_config_struct.operation_mode = asynch_normal;
   usart_config_struct.interrupt_mode_select = uart_Tx_and_Rx_Complete_Interrupt_Enable;
     
	char str[50]; 
   USART_Init(usart_config_struct);
   USART_Transmit('s');
   USART_Transmit('t');
   USART_Transmit('a');
   USART_Transmit('r');
   USART_Transmit('t');
   USART_Transmit(' ');
   
   USART_Transmit_String("Mohanad !\n");
   
    while(1)
    {
		 
		USART_Receive_String(str);
		_delay_ms(1000);
		USART_Transmit_String(str);
		
		
	}//end while
	return 0;
}
