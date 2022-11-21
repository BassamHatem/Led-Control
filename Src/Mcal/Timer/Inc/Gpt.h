/**********************************************************************************************************************
 *  FILE DESCRIPTION
 *  -------------------------------------------------------------------------------------------------------------------
 *         File:  TIMER.h
 *       Module:  TIMER
 *
 *  Description:  header file for TIMER Module    
 *  
 *********************************************************************************************************************/
#ifndef GPT_H
#define GPT_H

/**********************************************************************************************************************
 * INCLUDES
 *********************************************************************************************************************/
#include "Std_Types.h"
#include "Gpt_Types.h"

/**********************************************************************************************************************
 *  GLOBAL CONSTANT MACROS
 *********************************************************************************************************************/
#define GPT_OFFSET(x)														*((volatile uint32*)(x<8?(0x40030000UL+(x)*0x1000):(0x4004C000UL+(x-8)*0x1000)))
#define GPT_BASE(x)															((TIMER0_Type*)(GPT_OFFSET(x)))

/**********************************************************************************************************************
 *  GLOBAL FUNCTION MACROS
 *********************************************************************************************************************/


/**********************************************************************************************************************
 *  GLOBAL DATA TYPES AND STRUCTURES
 *********************************************************************************************************************/


/**********************************************************************************************************************
 *  GLOBAL DATA PROTOTYPES
 *********************************************************************************************************************/

 
/**********************************************************************************************************************
 *  GLOBAL FUNCTION PROTOTYPES
 *********************************************************************************************************************/
 
/******************************************************************************
* \Syntax          : void Gpt_Init(void)                                      
* \Description     :                                    
*                                                                             
* \Sync\Async      : Synchronous                                               
* \Reentrancy      : Non Reentrant                                             
* \Parameters (in) : None                     
* \Parameters (out): None                                                      
* \Return value:   : None
*******************************************************************************/
void Gpt_Init(const Gpt_ConfigType*ConfigPtr);
void Gpt_DisableNotification(Gpt_ChannelType Channel);
void Gpt_EnableNotification(Gpt_ChannelType Channel);
void Gpt_CallbackRegister(Gpt_ChannelType Channel,void (*InterruptHandler)(void));
void Gpt_StartTimer(Gpt_ChannelType Channel,Gpt_ValueType Value);
void Gpt_StopTimer(Gpt_ChannelType Channel);
Gpt_ValueType Gpt_GetTimeElapsed(Gpt_ChannelType Channel);
Gpt_ValueType Gpt_GetTimeRemaining(Gpt_ChannelType Channel);
//Std_ReturnType Gpt_GetPredefTimerValue(Gpt_PredefTimerType PredefTimer,uint32*TimeValuePtr);
Std_ReturnType Gpt_PollTimer(Gpt_ChannelType Channel);
void Gpt_ClrFlag(Gpt_ChannelType Channel);

void TIMER0A_Handler(void);
void TIMER1A_Handler(void);
void TIMER2A_Handler(void);
void TIMER3A_Handler(void);
void TIMER4A_Handler(void);
void TIMER5A_Handler(void);
void WTIMER0A_Handler(void);
void WTIMER1A_Handler(void);
void WTIMER2A_Handler(void);
void WTIMER3A_Handler(void);
void WTIMER4A_Handler(void);
void WTIMER5A_Handler(void);

#endif  /* GPT_H */

/**********************************************************************************************************************
 *  END OF FILE: GPT.h
 *********************************************************************************************************************/