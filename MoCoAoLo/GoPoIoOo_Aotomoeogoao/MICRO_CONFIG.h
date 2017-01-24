/*
 * CONTROLER_.h
 *
 * Created: 1/12/2017 7:47:45 PM
 *  Author: oody
 */ 


#ifndef MICRO_CONFIG_H_
#define MICRO_CONFIG_H_  
                                            /**************************************************************************/
                                                             /*THIS FILE MUST BE INCLUDED 1ST BEFOR ANYTHING*/
                                           /**************************************************************************/                       
#include <avr/io.h>
#define F_CPU 8000000UL
#include <util/delay.h>
#include <avr/interrupt.h>

                                          /***************************************************************************/
															 /*OUTER HARD WARE PORTS & PINS*/
										  /***************************************************************************/
										  
										  /********************SEVEN SEGGMENTS PORT & PINS****************************/						 
			                    
#define SEVEN_SEGGMENT_PORT 'A'
#define SEVEN_SEGGMENT_PIN0  0
#define SEVEN_SEGGMENT_PIN1  1
#define SEVEN_SEGGMENT_PIN2  2
#define SEVEN_SEGGMENT_PIN3  3
                                        /************************SWITCH PORT AND PINS********************************/
#define SWITCH_PORT 'B'
#define SWITCH_PIN   0			
                                      /*************************PULSE WIDTH MODULATION PORT & PINS*****************/ 	
#define PWM0_PORT   'B'
#define PWM0_PIN     3 										  				 
#endif /* MICRO_CONFIG_H_ */
