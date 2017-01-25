/*
 * UART.h
 *
 * Created: 04/01/2017 03:14:12 م
 *  Author: Mohanad Darwish
 */ 

#ifndef UART_H_
#define UART_H_

	#include <avr/io.h>
	#include "STD_Data_Types.h"
	#include "STD_Macros.h"
	#define F_CPU 8000000UL // frequency
	#define  ATMEGA  32
////////////////////////////////////////////////////////////////
	typedef enum USART_Tx_Or_Rx
	{
		tx_only,
		rx_only,
		tx_and_rx
	}USART_Tx_Or_Rx;
////////////////////////////////////////////////////////////////
	typedef enum USART_Selected
	{
		uart_0,
		uart_1	
	}USART_Selected;
////////////////////////////////////////////////////////////////
	typedef enum USART_Operation
	{
		synch,
		asynch_normal,
		asynch_double_speed
	}USART_Operation;
////////////////////////////////////////////////////////////////
	typedef enum USART_No_Of_Stop_Bits
	{
		one_stop_bit,
		two_stop_bits
	}USART_No_Of_Stop_Bits;
////////////////////////////////////////////////////////////////
	typedef enum USART_Baud_Rate
	{
		rate_2400=2400,
		rate_3200=3200,
		rate_4800=4800,
		rate_9600=9600,
		rate_14400=14400,
		rate_19200=19200
	}USART_Baud_Rate;
////////////////////////////////////////////////////////////////	
	typedef enum USART_Character_Size
	{
		ch_5_bits,
		ch_6_bits,
		ch_7_bits,
		ch_8_bits//9 bits not implemented
	}USART_Character_Size;
////////////////////////////////////////////////////////////////
	typedef enum USART_Parity
	{
		no_parity,
		odd_parity,
		even_parity	
	}USART_Parity;
////////////////////////////////////////////////////////////////
	typedef enum USART_Received_data_Status
	{
		correct_data,
		parity_error,
		data_overrun_error,
		frame_error
	}USART_received_data_Status;
////////////////////////////////////////////////////////////////
	typedef enum USART_Interrupt_Mode
	{
		uart_Transmit_Complete_Interrupt_Enable,
		uart_Receive_Complete_Interrupt_Enable,
		uart_Tx_and_Rx_Complete_Interrupt_Enable
	}USART_Interrupt_Mode;	
////////////////////////////////////////////////////////////////
	typedef struct config_struct
	{
		//enum USART_selected selected_uart;
		USART_Operation operation_mode;
		USART_Tx_Or_Rx transmit_or_receive_enable;
		USART_Baud_Rate baud_rate;
		USART_Character_Size characture_size;
		USART_Parity parity_mode;
		USART_No_Of_Stop_Bits stop_bits_select;
		USART_Interrupt_Mode interrupt_mode_select;
		//enum USART_clk_polarity clk_polarity; //0: tx on rising edge, 1:tx on falling edge
	}config_struct;
	
	volatile config_struct usart_config_struct;//global struct variable for the user to initialize it.
////////////////////////////////////////////////////////////////
	typedef struct received_data_struct
	{
		USART_received_data_Status error_type;
		INT8U data;		
	}received_data_struct;
	
	volatile received_data_struct usart_recieved_data_struct;//global struct variable (received data) for the user to read from it.
////////////////////////////////////////////////////////////////
	#if ATMEGA == 128
		#define   USART_DATA_REGISTER                         UDR0
		#define   USART_DATA_REGISTER_FLAG                    UDRE0
		#define   USART_CONTROL_REGISTER_A                    UCSR0A
		#define   USART_CONTROL_REGISTER_B                    UCSR0B
		#define   USART_CONTROL_REGISTER_C                    UCSR0C
		#define   USART_MODE_SELECT                           UMSEL0
		#define   USART_TRANSMISSION_SPEED                    U2X0
		#define   USART_BAUD_RATE_REGISTER_LOW                UBRR0L
		#define   USART_BAUD_RATE_REGISTER_HIGH               UBRR0H
		#define   USART_PARITY_MODE_ZERO                      UPM00
		#define   USART_PARITY_MODE_ONE                       UPM01
		#define   USART_STOP_BIT                              USBS0
		#define   USART_CHARACTER_SIZE_BIT_ZERO               UCSZ00
		#define   USART_CHARACTER_SIZE_BIT_ONE                UCSZ01
		#define   USART_CHARACTER_SIZE_BIT_TWO                UCSZ02   
		#define   USART_TRANSMITTER_ENABLE                    TXEN0
		#define   USART_RECEIVER_ENABLE                       RXEN0  
		#define   USART_TRASMITTER_INTERRUPT_ENABLE           TXCIE0  
		#define   USART_RECEIVER_INTERRUPT_ENABLE             RXCIE0
		#define   USART_TRANSMIT_COMPLETE                     TXC0
		#define   USART_RECEIVE_COMPLETE                      RXC0
		#define   USART_FRAME_ERROR                           FE0
		#define   USART_PARITY_ERROR                          UPE0
		#define   USART_DATA_OVERRUN                          DOR0
		#define   USART_REGISTER_SELECT                       7//URSEL //reserved in atmega128
	#elif ATMEGA == 32
		#define   USART_DATA_REGISTER                         UDR
		#define   USART_DATA_REGISTER_FLAG                    UDRE
		#define   USART_CONTROL_REGISTER_A                    UCSRA
		#define   USART_CONTROL_REGISTER_B                    UCSRB
		#define   USART_CONTROL_REGISTER_C                    UCSRC
		#define   USART_MODE_SELECT                           UMSEL
		#define   USART_TRANSMISSION_SPEED                    U2X
		#define   USART_BAUD_RATE_REGISTER_LOW                UBRRL
		#define   USART_BAUD_RATE_REGISTER_HIGH               UBRRH
		#define   USART_PARITY_MODE_ZERO                      UPM0
		#define   USART_PARITY_MODE_ONE                       UPM1
		#define   USART_STOP_BIT                              USBS
		#define   USART_CHARACTER_SIZE_BIT_ZERO               UCSZ0
		#define   USART_CHARACTER_SIZE_BIT_ONE                UCSZ1
		#define   USART_CHARACTER_SIZE_BIT_TWO                UCSZ2   
		#define   USART_TRANSMITTER_ENABLE                    TXEN
		#define   USART_RECEIVER_ENABLE                       RXEN  
		#define   USART_TRASMITTER_INTERRUPT_ENABLE           TXCIE  
		#define   USART_RECEIVER_INTERRUPT_ENABLE             RXCIE
		#define   USART_TRANSMIT_COMPLETE                     TXC
		#define   USART_RECEIVE_COMPLETE                      RXC
		#define   USART_FRAME_ERROR                           FE
		#define   USART_PARITY_ERROR                          2//PE
		#define   USART_DATA_OVERRUN                          DOR
		#define   USART_REGISTER_SELECT                       URSEL
	#endif
////////////////////////////////////////////////////////////////
	void USART_Init(config_struct uart_config_struct);
	received_data_struct USART_Receive(void);
	void USART_Transmit (INT8U data);
	void USART_disable (void);
	void USART_Receive_Complete_Interrupt_Enable(void);
	void USART_Transmit_Complete_Interrupt_Enable(void);
	void USART_Receive_Complete_Interrupt_Disable(void);
	void USART_Transmit_Complete_Interrupt_Disable(void);
	void USART_Transmit_String(INT8U* );
	void USART_Receive_String(INT8U* );

	void USART_DBG_Print_Debug_Message(INT8U*,INT8U*); //This function used to print on UART-terminal the current control flow position(time+function name)+ a "message of your choice"... e.g. USART_DBG_Print_Debug_Message((INT8U*)__FUNCTION__,"debug message");
	void USART_DBG_Trace_Control_Flow(INT8U*); //This function used to print on UART-terminal the current control flow position(time+function name).. e.g. USART_DBG_Trace_Control_Flow((INT8U*)__FUNCTION__);
////////////////////////////////////////////////////////////////

#endif /* UART_H_ */
