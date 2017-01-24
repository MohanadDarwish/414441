/*
 * External_Interrupts_ATmega32.c
 *
 * Created: Friday-06-Jan 9:34:57 PM
 *  Author: mohanad1
 */ 

#include "C:\Users\mohanad1\Desktop\Omar_and_Mohand\External_Interrupts_ATmega32\External_Interrupts_ATmega32\IO_Macros.h"
#define F_CPU 8000000
#include <avr/io.h>
#include <util/delay.h>
#include <avr/interrupt.h>

volatile unsigned char number=0;
volatile unsigned char i=0;
volatile unsigned char direction=1;//0=up 1=down
volatile unsigned char j=0;

ISR(INT0_vect){
	j=0;
	while(j<5)
	{
		PORTA=0xff;
		_delay_ms(500);
		PORTA=0x00;
		_delay_ms(500);
		j++;
	}
}

ISR(INT1_vect){
	direction^=1;
}
ISR(INT2_vect){
	
	PORTC+=1;
	if(PORTC==16){
		PORTC=0;
	}
}

void RESET_Init(void){
	cli();	//Clear global interrupt Enable
	//RESET interrupt triggered when a low voltage 0V is applied to reset pin.
	//This cause the ATmega32 to reset, that is reboot.
	sei();	//Set global interrupt Enable
}

void INT0_Init(void){
	cli();//Clear global interrupt Enable
	SET_BIT(GICR,6);//INT0 enable bit=1
	//INT0 triggered on rising
	SET_BIT(MCUCR,0);//ISC00=1
	SET_BIT(MCUCR,1);//ISC01=1
	sei();//Set global interrupt Enable
}

void INT1_Init(void){
	cli();//Clear global interrupt Enable
	SET_BIT(GICR,7);//INT1 enable bit=1
	//INT1 triggered on rising
	SET_BIT(MCUCR,2);//ISC10=1
	SET_BIT(MCUCR,3);//ISC11=1
	sei();//Set global interrupt Enable
}

void INT2_Init(void){
	cli();//Clear global interrupt Enable
	SET_BIT(GICR,5);//INT2 enable bit=1
	SET_BIT(MCUCSR,6);//ISC2=1 //INT2 triggered on rising
	sei();//Set global interrupt Enable
}


int main(void)
{
	DDRA=0xff;//output
	DDRC=0x0f;//output 4 pins for the 7-Seg
	
	CLEAR_BIT(DDRD,2);// button input
	SET_BIT(PORTD,2);//pull up resistor
	
	CLEAR_BIT(DDRD,3);// button input
	SET_BIT(PORTD,3);//pull up resistor
	
	CLEAR_BIT(DDRB,2);// button input
	SET_BIT(PORTB,2);//pull up resistor
	
	RESET_Init();
	INT0_Init();
	INT1_Init();
	INT2_Init();	
    while(1)
    {
			if( (i <8) && (direction==1) )
			{
				number=(1<<i);
				PORTA=number;
				_delay_ms(200);
				i++;
				if(i==7)
				{
					direction=0;//direc. => up
				}
			}
			else if( (i >0) && (direction==0) )
			{
				number=(1<<i);
				PORTA=number;
				_delay_ms(200);
				i--;
				if(i==0)
				{
					direction=1;//direc. => down
				}
			}
	}
	return 0;
}
