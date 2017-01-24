/*
 * UART.c
 *
 * Created: 04/01/2017 03:14:29 م
 *  Author: DELL
 */ 

#include "UART.h"


void USART_Init(config_struct uart_config_struct){
	INT16U UBRR;	// 2 bytes 
	//mode select UMSEL bit =0 for Async in UCSRmC
	switch(uart_config_struct.operation_mode){
		case synch:
			SET_BIT( USART_CONTROL_REGISTER_C , USART_MODE_SELECT );		//1
			break;
		case asynch_normal:
			CLEAR_BIT( USART_CONTROL_REGISTER_C , USART_MODE_SELECT );	//0
			CLEAR_BIT(USART_CONTROL_REGISTER_A,USART_TRANSMISSION_SPEED);
			//set baud rate
			UBRR = (F_CPU/(16UL* uart_config_struct.baud_rate)-1); // Calc. the value of UBRR Async. Normal mode (USART_TRANSMISSION_SPEED=0)
			//UBRR=0x0033;
			USART_BAUD_RATE_REGISTER_HIGH = (INT8U)(UBRR>>8);
			USART_BAUD_RATE_REGISTER_LOW = (INT8U)(UBRR);			//0
			//USART_BAUD_RATE_REGISTER_HIGH = (INT8U)0;
			//USART_BAUD_RATE_REGISTER_LOW = (INT8U)51;
			break;
		case asynch_double_speed:
			CLEAR_BIT( USART_CONTROL_REGISTER_C , USART_MODE_SELECT );	//0
			SET_BIT(USART_CONTROL_REGISTER_A,USART_TRANSMISSION_SPEED);			//1
			//set baud rate
			UBRR = 2*(F_CPU/(16* uart_config_struct.baud_rate)-1); // Calc. the value of UBRR Async. Normal mode (USART_TRANSMISSION_SPEED=0)
			USART_BAUD_RATE_REGISTER_HIGH = (INT8U)(UBRR>>8);
			USART_BAUD_RATE_REGISTER_LOW = (INT8U)(UBRR);
			break;	
	}
	
	//set parity mode
	switch (uart_config_struct.parity_mode){
		case no_parity:
			CLEAR_BIT(USART_CONTROL_REGISTER_C,USART_PARITY_MODE_ONE);//USART_PARITY_MODE_ONE =0
			CLEAR_BIT(USART_CONTROL_REGISTER_C,USART_PARITY_MODE_ZERO);//USART_PARITY_MODE_ZERO =0
			break;
		case even_parity:
			SET_BIT(USART_CONTROL_REGISTER_C,USART_PARITY_MODE_ONE);	//USART_PARITY_MODE_ONE	=1
			CLEAR_BIT(USART_CONTROL_REGISTER_C,USART_PARITY_MODE_ZERO);//USART_PARITY_MODE_ZERO =0
			break;
		case odd_parity:
			SET_BIT(USART_CONTROL_REGISTER_C,USART_PARITY_MODE_ONE);	//USART_PARITY_MODE_ONE =1
			SET_BIT(USART_CONTROL_REGISTER_C,USART_PARITY_MODE_ZERO);	//USART_PARITY_MODE_ZERO =1
			break;
	}
	
	//set stop bit number 1 or 2
	switch (uart_config_struct.stop_bits_select){
		case one_stop_bit:
			CLEAR_BIT(USART_CONTROL_REGISTER_C ,USART_STOP_BIT);	//USART_STOP_BIT =0	(1-bit)
			break;
		case two_stop_bits:
			SET_BIT(USART_CONTROL_REGISTER_C,USART_STOP_BIT);		//USART_STOP_BIT =1	(2-bit)
			break;
	}
	//char size
	switch (uart_config_struct.characture_size){
		case ch_5_bits:	 
			CLEAR_BIT(USART_CONTROL_REGISTER_B,USART_CHARACTER_SIZE_BIT_TWO);	//0
			CLEAR_BIT(USART_CONTROL_REGISTER_C,USART_CHARACTER_SIZE_BIT_ONE);	//0
			CLEAR_BIT(USART_CONTROL_REGISTER_C,USART_CHARACTER_SIZE_BIT_ZERO);	//0
			break;
		case ch_6_bits:	
			CLEAR_BIT(USART_CONTROL_REGISTER_B,USART_CHARACTER_SIZE_BIT_TWO);	//0
			CLEAR_BIT(USART_CONTROL_REGISTER_C,USART_CHARACTER_SIZE_BIT_ONE);	//0
			SET_BIT(USART_CONTROL_REGISTER_C,USART_CHARACTER_SIZE_BIT_ZERO);		//1
			break;
		case ch_7_bits:	
			CLEAR_BIT(USART_CONTROL_REGISTER_B,USART_CHARACTER_SIZE_BIT_TWO);	//0
			SET_BIT(USART_CONTROL_REGISTER_C,USART_CHARACTER_SIZE_BIT_ONE);		//1
			CLEAR_BIT(USART_CONTROL_REGISTER_C,USART_CHARACTER_SIZE_BIT_ZERO);	//0
			break;
		case ch_8_bits:	
			CLEAR_BIT(USART_CONTROL_REGISTER_B,USART_CHARACTER_SIZE_BIT_TWO);	//0
			SET_BIT(USART_CONTROL_REGISTER_C,USART_CHARACTER_SIZE_BIT_ONE);		//1
			SET_BIT(USART_CONTROL_REGISTER_C,USART_CHARACTER_SIZE_BIT_ZERO);		//1
			break;
	}
	//enable transmitter receiver 
	switch(uart_config_struct.transmit_or_receive_enable){
		case tx_only:
			SET_BIT(USART_CONTROL_REGISTER_B,USART_TRANSMITTER_ENABLE);	//Tx Enabled
			CLEAR_BIT(USART_CONTROL_REGISTER_B,USART_RECEIVER_ENABLE);//Rx Disabled
			break;
		case rx_only:
			CLEAR_BIT(USART_CONTROL_REGISTER_B,USART_TRANSMITTER_ENABLE);//Tx Disabled
			SET_BIT(USART_CONTROL_REGISTER_B,USART_RECEIVER_ENABLE);	//Rx Enabled
			break;
		case tx_and_rx:
			SET_BIT(USART_CONTROL_REGISTER_B,USART_TRANSMITTER_ENABLE);//Tx Enabled
			SET_BIT(USART_CONTROL_REGISTER_B,USART_RECEIVER_ENABLE);//Tx Disabled
			break;
	}
	switch(uart_config_struct.interrupt_mode_select)
	{
		case uart_Receive_Complete_Interrupt_Enable:
			SET_BIT(USART_CONTROL_REGISTER_B,USART_RECEIVER_INTERRUPT_ENABLE);		//enable	Rx
			CLEAR_BIT(USART_CONTROL_REGISTER_B,USART_TRASMITTER_INTERRUPT_ENABLE);	//disable	Tx
			break;
		case uart_Transmit_Complete_Interrupt_Enable:
			CLEAR_BIT(USART_CONTROL_REGISTER_B,USART_RECEIVER_INTERRUPT_ENABLE);	//disable	Rx
			SET_BIT(USART_CONTROL_REGISTER_B,USART_TRASMITTER_INTERRUPT_ENABLE);		//enable	Tx
			break;
		case  uart_Tx_and_Rx_Complete_Interrupt_Enable:
			SET_BIT(USART_CONTROL_REGISTER_B,USART_RECEIVER_INTERRUPT_ENABLE);		//enable	Rx
			SET_BIT(USART_CONTROL_REGISTER_B,USART_TRASMITTER_INTERRUPT_ENABLE);		//enable	Tx
			break;
		default:
			CLEAR_BIT(USART_CONTROL_REGISTER_B,USART_RECEIVER_INTERRUPT_ENABLE);	//disable	Rx
			CLEAR_BIT(USART_CONTROL_REGISTER_B,USART_TRASMITTER_INTERRUPT_ENABLE);	//disable	Tx
	}
	return;
}
//
void USART_Transmit (INT8U data){
	/****** if we try to clear transmit flag in atmega 32 , there will be data corruption or data will not be transmitted correctly *******/
	//SET_BIT(USART_CONTROL_REGISTER_A,USART_TRANSMIT_COMPLETE);//to clear interrupt flag only --- (we clear the bit by setting it to 1 XOR)
	
	while( ! (USART_CONTROL_REGISTER_A & (1<<USART_DATA_REGISTER_FLAG)) );// polling for empty transmission buffer
	USART_DATA_REGISTER=data;//put data into buffer
	while(! (USART_CONTROL_REGISTER_A & (1<<USART_TRANSMIT_COMPLETE)) );//USART_TRANSMIT_COMPLETE: USART Transmit Complete flag
	
	//SET_BIT(USART_CONTROL_REGISTER_A,USART_TRANSMIT_COMPLETE);//to clear interrupt flag only --- (we clear the bit by setting it to 1 XOR)
	return;
}

received_data_struct USART_Receive(void){
	while( !(USART_CONTROL_REGISTER_A &(1<<USART_RECEIVE_COMPLETE)) ); //polling on Receive complete flag
	usart_recieved_data_struct.data=USART_DATA_REGISTER;
	if ( ( (GET_BIT(USART_CONTROL_REGISTER_A,USART_FRAME_ERROR)) | (GET_BIT(USART_CONTROL_REGISTER_A,USART_PARITY_ERROR)) | (GET_BIT(USART_CONTROL_REGISTER_A,USART_DATA_OVERRUN)) )==0)
		{
			usart_recieved_data_struct.error_type = correct_data;
		}
	else if ( (GET_BIT(USART_CONTROL_REGISTER_A,USART_FRAME_ERROR))!=0)
		{
			usart_recieved_data_struct.error_type = frame_error;
		}
	else if ( (GET_BIT(USART_CONTROL_REGISTER_A,USART_PARITY_ERROR))!=0)
		{
			usart_recieved_data_struct.error_type = parity_error;
		}
	else if ( (GET_BIT(USART_CONTROL_REGISTER_A,USART_DATA_OVERRUN))!=0)
		{
			usart_recieved_data_struct.error_type = data_overrun_error;
		}
	return usart_recieved_data_struct;
}

void USART_disable (){
	//disable the transmitter and the receiver in usart module 0
	CLEAR_BIT(USART_CONTROL_REGISTER_B,USART_RECEIVER_ENABLE);//Receive Disabled
	CLEAR_BIT(USART_CONTROL_REGISTER_B,USART_TRANSMITTER_ENABLE);//Transmit Disabled
	return;
}
void USART_Receive_Complete_Interrupt_Enable(void)
{
	SET_BIT(USART_CONTROL_REGISTER_B,USART_RECEIVER_INTERRUPT_ENABLE);
}
void USART_Transmit_Complete_Interrupt_Enable(void)
{
	SET_BIT(USART_CONTROL_REGISTER_B,USART_TRASMITTER_INTERRUPT_ENABLE);
}
void USART_Receive_Complete_Interrupt_Disable(void)
{
	CLEAR_BIT(USART_CONTROL_REGISTER_B,USART_RECEIVER_INTERRUPT_ENABLE);
}
void USART_Transmit_Complete_Interrupt_Disable(void)
{
	CLEAR_BIT(USART_CONTROL_REGISTER_B,USART_TRASMITTER_INTERRUPT_ENABLE);
}
void USART_Transmit_String(char* str){
	while (*str != '\0')
	{
		USART_Transmit(*str );
		str++;
	}
	return;
}
void USART_Receive_String(char* str ){
	received_data_struct r;
	do{
		r=USART_Receive();
		*str=r.data;
		str++;
	}while(r.data != '#');
		
	*(--str)='\0';
	
	return;
}
