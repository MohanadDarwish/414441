#include "GPIO.h"
/*
void GPIO_Init_Port(INT8U por,INT8U direction)
{
	if(direction==INPUT)
	{
		CLR_PORT(por);
	}
	else if(direction==OUTPUT)
	{
		SET_PORT(por);
	}
}
*/
void GPIO_Init_Port(INT8U por,INT8U direction)
{
    switch(por)
    {
    case 'A':
        if(direction==0){DDRA=0x00;}else{DDRA=0xFF;}
        break;

    case 'B':
        if(direction==0){DDRB=0x00;}else{DDRB=0xFF;}
        break;

    case 'C':
        if(direction==0){DDRC=0x00;}else{DDRC=0xFF;}
        break;

    case 'D':
        if(direction==0){DDRD=0x00;}else{DDRD=0xFF;}
        break;

    default :
        break;
    }
}
*/
void GPIO_Init_Nibble(INT8U por,INT8U nibble,INT8U direction)
{
	switch(por)
	{
	case 'A': if (nibble==LOWER_NIBBLE)
               {
	             if(direction==INPUT)
				 {
					 CLR_LOWER_NIBBLE(DDRA);
				 }
				 else if(direction==OUTPUT)
				 {
					 SET_LOWER_NIBBLE(DDRA);
				 }					 					 
			   }
			   else if(nibble==HIGHER_NIBBLE)
			   {
				      if(direction==INPUT)
				      {
					      CLR_HIGHER_NIBBLE(DDRA);
				      }
				      else if(direction==OUTPUT)
				      {
					      SET_HIGHER_NIBBLE(DDRA);
				      }
			   }				   
	          break;

    case 'B': if (nibble==LOWER_NIBBLE)
			  {
					if(direction==INPUT)
					{
						CLR_LOWER_NIBBLE(DDRB);
					}
					else if(direction==OUTPUT)
					{
						SET_LOWER_NIBBLE(DDRB);
					}
			  }
			else if(nibble==HIGHER_NIBBLE)
			{
					if(direction==INPUT)
					{
						CLR_HIGHER_NIBBLE(DDRB);
					}
					else if(direction==OUTPUT)
					{
						SET_HIGHER_NIBBLE(DDRB);
					}
			}
              break;

    case 'C':  if (nibble==LOWER_NIBBLE)
	         {
		         if(direction==INPUT)
		         {
			         CLR_LOWER_NIBBLE(DDRC);
		         }
		         else if(direction==OUTPUT)
		         {
			         SET_LOWER_NIBBLE(DDRC);
		         }
	         }
	         else if(nibble==HIGHER_NIBBLE)
	         {
		         if(direction==INPUT)
		         {
			         CLR_HIGHER_NIBBLE(DDRC);
		         }
		         else if(direction==OUTPUT)
		         {
			         SET_HIGHER_NIBBLE(DDRC);
		         }
	         }
              break;

    case 'D': if (nibble==LOWER_NIBBLE)
	          {
		          if(direction==INPUT)
		          {
			          CLR_LOWER_NIBBLE(DDRD);
		          }
		          else if(direction==OUTPUT)
		          {
			          SET_LOWER_NIBBLE(DDRD);
		          }
	          }
	          else if(nibble==HIGHER_NIBBLE)
	          {
		          if(direction==INPUT)
		          {
			          CLR_HIGHER_NIBBLE(DDRD);
		          }
		          else if(direction==OUTPUT)
		          {
			          SET_HIGHER_NIBBLE(DDRD);
		          }
	          }
			  break;

    default :
              break;
    }
}

void GPIO_Init_Pin(INT8U por, INT8U pin, INT8U direction)
{
    switch(por)
    {
    case 'A': if(direction==0){CLR_BIT(DDRA,pin);}else{SET_BIT(DDRA,pin);}
              break;

    case 'B': if(direction==0){CLR_BIT(DDRB,pin);}else{SET_BIT(DDRB,pin);}
              break;

    case 'C': if(direction==0){CLR_BIT(DDRC,pin);}else{SET_BIT(DDRC,pin);}
              break;

    case 'D': if(direction==0){CLR_BIT(DDRD,pin);}else{SET_BIT(DDRD,pin);}
			  break;

    default :
              break;
    }
}

INT8U GPIO_Read_Port(INT8U por)
{
    switch(por)
    {
    case 'A': return PORTA;
              break;

    case 'B': return PORTB;
              break;

    case 'C': return PORTC;
              break;

    case 'D': return PORTD;
			  break;

    default : return 0;
              break;
    }
}

void GPIO_Write_Port(INT8U por,INT8U DATA)
{
    switch(por)
    {
    case 'A': PORTA=DATA;
			  break;

    case 'B': PORTB=DATA;
              break;

    case 'C': PORTC=DATA;
              break;

    case 'D': PORTD=DATA;
              break;

    default :
              break;
    }
}
unsigned char GPIO_Read_Pin(INT8U por, INT8U pin)
{
    switch(por)
    {
    case 'A': return GET_BIT(PINA,pin);
              break;

    case 'B': return GET_BIT(PINB,pin);
			  break;

    case 'C': return GET_BIT(PINC,pin);
              break;

    case 'D': return GET_BIT(PIND,pin);
              break;

    default : return 0;
              break;
    }
}

void GPIO_Write_Pin(INT8U por,INT8U pin,INT8U direction)
{
    switch(por)
    {
    case 'A': if(direction==0){CLR_BIT(PORTA,pin);}else{SET_BIT(PORTA,pin);}
              break;

    case 'B': if(direction==0){CLR_BIT(PORTB,pin);}else{SET_BIT(PORTB,pin);}
              break;

    case 'C': if(direction==0){CLR_BIT(PORTC,pin);}else{SET_BIT(PORTC,pin);}
              break;

    case 'D': if(direction==0){CLR_BIT(PORTD,pin);}else{SET_BIT(PORTD,pin);}
              break;

    default :
              break;
    }
}
