/*
 * MACROS.h
 *
 * Created: 1/12/2017 8:30:51 PM
 *  Author: oody
 */ 


#ifndef STD_Macros_H_
#define STD_Macros_H_
                                          /**************************************************************************/
                                                           /*THIS FILE MUST BE INCLUDED 3RD*/
                                          /**************************************************************************/
#define SET_PORT(REG)	(PortREG|=0xff)
#define CLR_PORT(REG)	(REG&=(0x00))										  
#define SET_BIT(REG,INDEX) (REG|=(1<<INDEX))

#define CLR_BIT(REG,INDEX) (REG&=(~(1<<INDEX)))
#define CLEAR_BIT(REG,INDEX) (REG&=(~(1<<INDEX)))

#define GET_BIT(REG,INDEX) ((REG>>INDEX)&0x01)
#define TOGGLE_BIT(REG,INDEX) (REG^=(1<<INDEX))
#define BIT_IS_SET(REG,INDEX) (REG&(1<<INDEX))
#define BIT_IS_CLR(REG,INDEX) (!(REG&(1<<INDEX)))
#define SET_LOWER_NIBBLE(REG) (REG|=0x0f)
#define CLR_LOWER_NIBBLE(REG) (REG&=0xf0)
#define SET_HIGHER_NIBBLE(REG) (REG|=0xf0)
#define CLR_HIGHER_NIBBLE(REG) (REG&=0x0f)


#endif /* STD_Macros_H_ */
