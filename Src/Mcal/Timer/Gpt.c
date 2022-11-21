/**********************************************************************************************************************
 *  FILE DESCRIPTION
 *  -----------------------------------------------------------------------------------------------------------------*/
/**        \file  Gpt.c
 *        \brief  General porpose timer Driver
 *
 *      \details  The Driver Configure All MCU timers
 *
 *********************************************************************************************************************/

/**********************************************************************************************************************
 *  INCLUDES
 *********************************************************************************************************************/
#include "Std_Types.h"
#include "Macros.h"
#include "Gpt.h"
#include "Mcu_Hw.h"

/**********************************************************************************************************************
*  LOCAL MACROS CONSTANT\FUNCTION
*********************************************************************************************************************/	
#define	MCU_CLK							16000000UL

/**********************************************************************************************************************
 *  LOCAL DATA 
 *********************************************************************************************************************/
typedef void (*CallBack)(void);
static CallBack GptCallbackFunction[12] = {NULL_PTR};
static uint32 NumOfTicksPerUserTick[12] = {0};
/**********************************************************************************************************************
 *  GLOBAL DATA
 *********************************************************************************************************************/

/**********************************************************************************************************************
 *  LOCAL FUNCTION PROTOTYPES
 *********************************************************************************************************************/

/**********************************************************************************************************************
 *  LOCAL FUNCTIONS
 *********************************************************************************************************************/

/**********************************************************************************************************************
 *  GLOBAL FUNCTIONS
 *********************************************************************************************************************/
void Gpt_Init(const Gpt_ConfigType*ConfigPtr)
{
	//Enable CLK for Timer module
	SET_BIT(SYSCTL->RCGCTIMER,ConfigPtr->GptChannelId);

	//Ensure the timer is disabled (GPTMCTL)
	CLEAR_BIT(GPT_BASE(ConfigPtr->GptChannelId)->CTL,0);

	//Write the GPTM Configuration with a value of 0x0000.0000.
	GPT_BASE(ConfigPtr->GptChannelId)->CFG = 0x00000000;

	//Configure the TnMR in (GPTMTnMR):One-Shot/Periodic
	if(ONE_SHOT_MODE == ConfigPtr->Mode)
		SET_BIT(GPT_BASE(ConfigPtr->GptChannelId)->TAMR,0);
	else if(CONT_MODE == ConfigPtr->Mode)
		SET_BIT(GPT_BASE(ConfigPtr->GptChannelId)->TAMR,1);
	
	//Calculate Timer Period
	NumOfTicksPerUserTick[ConfigPtr->GptChannelId] = MCU_CLK/(ConfigPtr->GptChannelTickFrequency);
	uint32 ActualMaxTicks = NumOfTicksPerUserTick[ConfigPtr->GptChannelId]*(ConfigPtr->GptChannelTickValueMax); 
	GPT_BASE(ConfigPtr->GptChannelId)->TAILR = ActualMaxTicks;
	
	//clear timeout flag by writing a 1 to the TATOCINT bit in the GPTMICR register.
	SET_BIT(GPT_BASE(ConfigPtr->GptChannelId)->ICR,0);
	
	//to enable timerA stall for debug
	SET_BIT(GPT_BASE(ConfigPtr->GptChannelId)->CTL, 1);
		
	//If interrupts are required, set the appropriate bits in the GPTM Interrupt Mask Register(GPTMIMR).
	
}

Gpt_ValueType Gpt_GetTimeElapsed(Gpt_ChannelType Channel) {
	return GPT_BASE(Channel)->TAR/NumOfTicksPerUserTick[Channel];	 
}

Gpt_ValueType Gpt_GetTimeRemaining(Gpt_ChannelType Channel) {
	return (GPT_BASE(Channel)->TAILR -GPT_BASE(Channel)->TAR)/NumOfTicksPerUserTick[Channel];	 
}

void Gpt_StartTimer(Gpt_ChannelType Channel,Gpt_ValueType Value)
{
	uint32 ActualMaxTicks = NumOfTicksPerUserTick[Channel] * Value; 
	GPT_BASE(Channel)->TAILR = ActualMaxTicks;
	SET_BIT(GPT_BASE(Channel)->CTL,0);
}

void Gpt_StopTimer(Gpt_ChannelType Channel) {
	CLEAR_BIT(GPT_BASE(Channel)->CTL,0);
}

void Gpt_EnableNotification(Gpt_ChannelType Channel) {
	SET_BIT(GPT_BASE(Channel)->IMR,0);
}

void Gpt_DisableNotification(Gpt_ChannelType Channel) {
	CLEAR_BIT(GPT_BASE(Channel)->IMR,0);
}

void Gpt_CallbackRegister(Gpt_ChannelType Channel,void (*InterruptHandler)(void)) {
	GptCallbackFunction[Channel] = InterruptHandler;
}

Std_ReturnType Gpt_PollTimer(Gpt_ChannelType Channel) {
	return GET_BIT(GPT_BASE(Channel)->RIS,0);
}

void Gpt_ClrFlag(Gpt_ChannelType Channel)
{
	uint32 status = GPT_BASE(Channel)->MIS;
	SET_BIT(GPT_BASE(Channel)->ICR,status>>1);
}

void TIMER0A_Handler(void) {
	Gpt_ClrFlag(0);
	if(NULL_PTR != GptCallbackFunction[0])
		GptCallbackFunction[0]();
}

void TIMER1A_Handler(void) {
	Gpt_ClrFlag(1);
	if(NULL_PTR == GptCallbackFunction[1])
		GptCallbackFunction[1]();
}

void TIMER2A_Handler(void) {
	Gpt_ClrFlag(2);
	if(NULL_PTR == GptCallbackFunction[2])
		GptCallbackFunction[2]();
}

void TIMER3A_Handler(void) {
	Gpt_ClrFlag(3);
	if(NULL_PTR == GptCallbackFunction[3])
		GptCallbackFunction[3]();
}

void TIMER4A_Handler(void) {
	Gpt_ClrFlag(4);
	if(NULL_PTR == GptCallbackFunction[4])
		GptCallbackFunction[4]();
}

void TIMER5A_Handler(void) {
	Gpt_ClrFlag(5);
	if(NULL_PTR == GptCallbackFunction[5])
		GptCallbackFunction[5]();
}

void WTIMER0A_Handler(void) {
	Gpt_ClrFlag(6);
	if(NULL_PTR == GptCallbackFunction[6])
		GptCallbackFunction[6]();
}

void WTIMER1A_Handler(void) {
	Gpt_ClrFlag(0);
	if(NULL_PTR == GptCallbackFunction[0])
		GptCallbackFunction[0]();
}

void WTIMER2A_Handler(void) {
	Gpt_ClrFlag(0);
	if(NULL_PTR == GptCallbackFunction[0])
		GptCallbackFunction[0]();
}

void WTIMER3A_Handler(void) {
	Gpt_ClrFlag(0);
	if(NULL_PTR == GptCallbackFunction[0])
		GptCallbackFunction[0]();
}
	
void WTIMER4A_Handler(void) {
	Gpt_ClrFlag(0);
	if(NULL_PTR == GptCallbackFunction[0])
		GptCallbackFunction[0]();
}

void WTIMER5A_Handler(void) {
	Gpt_ClrFlag(0);
	if(NULL_PTR == GptCallbackFunction[0])
		GptCallbackFunction[0]();
}
/**********************************************************************************************************************
 *  END OF FILE: Gpt.c
 *********************************************************************************************************************/