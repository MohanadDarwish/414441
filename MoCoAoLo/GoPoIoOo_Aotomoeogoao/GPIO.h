#ifndef _GPIO_H_
#define _GPIO_H_

#include "MICRO_CONFIG.h"
#include "STD_TYP.h"
#include "STD_Macros.h"
                                            /***************************************************************/
					    /******************GENERAL_PARPOUS_INPUT_OUTPUT*****************/
					    /***************************************************************/
#define INPUT 0
#define OUTPUT 1

#define LOWER_NIBBLE 0
#define HIGHER_NIBBLE 1

void GPIO_Init_Port(INT8U por,INT8U direction); // function used to initiate a given port.....  ex:- fun(LCD_PORT,INPUT)

void GPIO_Init_Nibble(INT8U por,INT8U nibble,INT8U direction); // function to initiate nibble in a given port.....  ex:- fun(SEVEN_SEGGMENT_PORT,LOWER_NIBBLE,OUTPUT)

void GPIO_Init_Pin(INT8U por, INT8U pin, INT8U direction); // function used to initiate a single pin in a given register.....ex:- fun(KEY_BAD_PORT,6,INPUT)

unsigned char GPIO_Read_Port(INT8U por); // function returns port state.....  ex:- fun(LCD_PORT)

void GPIO_Write_Port(INT8U por,INT8U DATA); // function to write data to given port.....  ex:- fun(LCD_PORT,99)

unsigned char GPIO_Read_Pin(INT8U por, INT8U pin); // function that returns the value of a pin in a register.....  ex:- fun(LCD_PORT,LCD_RS_PIN)

void GPIO_Write_Pin(INT8U por,INT8U pin,INT8U direction); // function used to.....  ex:- fun(LCD_PORT,LCD_ENABLE_PIN,INPUT) 

#endif // _GPIO_H_
