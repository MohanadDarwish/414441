/*
 * STD_Macros.h
 *
 * Created: Wednesday-11-Jan 6:22:32 PM
 *  Author: mohanad1
 */ 


#ifndef STD_MACROS_H_
#define STD_MACROS_H_

#define SET_BIT(REG,PIN_NUM)	( REG |= (1<<PIN_NUM) )

#define CLEAR_BIT(REG,PIN_NUM)	( REG &= ~(1<<PIN_NUM) )

#define TOGGLE_BIT(REG,PIN_NUM)	( REG ^= (1<<PIN_NUM) )

#define GET_BIT(REG,PIN_NUM)	( (REG>>PIN_NUM) & 0x01 )



#endif /* STD_MACROS_H_ */
