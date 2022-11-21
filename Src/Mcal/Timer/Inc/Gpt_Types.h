/**********************************************************************************************************************
 *  FILE DESCRIPTION
 *  -------------------------------------------------------------------------------------------------------------------
 *         File:  GPT_Types.h
 *       Module:  -
 *
 *  Description:  <Write File DESCRIPTION here>     
 *  
 *********************************************************************************************************************/
#ifndef GPT_TYPES_H
#define GPT_TYPES_H

/**********************************************************************************************************************
 * INCLUDES
 *********************************************************************************************************************/
#include "Std_Types.h"

/**********************************************************************************************************************
 *  GLOBAL CONSTANT MACROS
 *********************************************************************************************************************/
#define Gpt_ValueType			uint32

/**********************************************************************************************************************
 *  GLOBAL FUNCTION MACROS
 *********************************************************************************************************************/


/**********************************************************************************************************************
 *  GLOBAL DATA TYPES AND STRUCTURES
 *********************************************************************************************************************/
typedef enum {
	TIMER_0,
	TIMER_1,
	TIMER_2,
	TIMER_3,
	TIMER_4,
	TIMER_5,
	W_TIMER_0,
	W_TIMER_1,
	W_TIMER_2,
	W_TIMER_3,
	W_TIMER_4,
	W_TIMER_5
}Gpt_ChannelType;

typedef enum {
	COUNT_DOWN, COUNT_UP
}Gpt_CountDir;

typedef enum {
	CONT_MODE, ONE_SHOT_MODE
}Gpt_ModeType;

typedef enum {
	PREDEF_TIMER_1US_16BIT = 0x00,
	PREDEF_TIMER_1US_24BIT,
	PREDEF_TIMER_1US_32BIT,
	PREDEF_TIMER_100US_32BIT
}Gpt_PredefTimerType;

typedef struct {
	Gpt_ChannelType GptChannelId;
	uint32 GptChannelTickFrequency;
	uint32 GptChannelTickValueMax;
	Gpt_ModeType Mode;
}Gpt_ConfigType;

#endif  /* GPT_TYPES_H */

/**********************************************************************************************************************
 *  END OF FILE: GPT_Types.h
 *********************************************************************************************************************/