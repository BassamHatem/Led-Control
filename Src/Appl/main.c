/**********************************************************************************************************************
 *  FILE DESCRIPTION
 *  -----------------------------------------------------------------------------------------------------------------*/
/**        \file  BlinkLed.c
 *        \brief  App
 *		\details: this file contains the implementaion of BlinkLed app
 *        
 *********************************************************************************************************************/

/**********************************************************************************************************************
 *  INCLUDES
 *********************************************************************************************************************/

#include "system_TM4C123.h"
#include "IntCtrl.h"
#include "Port.h"
#include "Dio.h"
#include "Gpt.h"
#include "Gpt_Cfg.h"
#include "IntCtrl_Cfg.h"
#include "Dio_Cfg.h"

/**********************************************************************************************************************
*  LOCAL MACROS CONSTANT\FUNCTION
*********************************************************************************************************************/	

/**********************************************************************************************************************
 *  LOCAL DATA 
 *********************************************************************************************************************/
volatile static uint8 flag = FALSE;
static uint32 OnTime = 0;
static uint32 OffTime = 0;

/**********************************************************************************************************************
 *  GLOBAL DATA
 *********************************************************************************************************************/
extern  Port_ConfigType Channels[DIO_CONFIGURED_CHANNLES];

/**********************************************************************************************************************
 *  LOCAL FUNCTION PROTOTYPES
 *********************************************************************************************************************/

/**********************************************************************************************************************
 *  GLOBAL DATA TYPES AND STRUCTURES
 *********************************************************************************************************************/
typedef enum {
	LED_OFF, LED_ON, STOP
}LedState;

/**********************************************************************************************************************
 *  LOCAL FUNCTIONS
 *********************************************************************************************************************/

/**********************************************************************************************************************
 *  GLOBAL FUNCTIONS
 *********************************************************************************************************************/
void BlinkLed_Init(void)
{
	Gpt_Init(&Gpt_Cfg);
	Gpt_EnableNotification(TIMER0);
	Gpt_CallbackRegister(TIMER0,Timer0_Handler);
}

void BlinkLed_SetOnTime(uint32_t Time)
{
	OnTime = Time;
}

void BlinkLed_SetOffTime(uint32_t Time)
{
	OffTime = Time;
}

void BlinkLed_Start(void)
{
	Gpt_StartTimer(TIMER0,1); 
}

void BlinkLed_Stop(void)
{
	Gpt_StopTimer(TIMER0);
}

void Timer0_Handler(void)
{
	flag = TRUE;
}

void BlinkLed_Run(void)
{	
	static uint32 ms_Counter = 0;
	static uint32 s_Counter = 0;
	static volatile uint8 state;
	uint32 period = OnTime + OffTime;
	if(flag) {
		flag = FALSE;
		ms_Counter++;
	}
	if(ms_Counter == 1000)
	{
		ms_Counter = 0;
		s_Counter++;
	}
	if(s_Counter < OnTime)
	{
		state = LED_ON;
	}
	else if((s_Counter >= OnTime) && (s_Counter < OnTime+OffTime))
	{
		state = LED_OFF;
	}
	else if(s_Counter >= OnTime+OffTime)
	{
		s_Counter = 0;
		state = STOP;
	}
	switch(state)
	{
		case LED_OFF:
			Dio_WriteChannel(Channels[1].Channel,STD_LOW);
			break;
		case LED_ON:
			Dio_WriteChannel(Channels[1].Channel,STD_HIGH);
			break;
		case STOP:
			break;
		default:
			break;
	}
}

int main(void)
{
	SystemInit();
	for (uint8 i=0;i<INT_CONFIGURED;i++)
		IntCtrl_Init(&ISRs[i]);
	for (uint8 j=0;i<DIO_CONFIGURED_CHANNLES;i++)
		Port_Init(&Channels[j]);
	BlinkLed_Init();
	BlinkLed_SetOnTime(4); 
	BlinkLed_SetOffTime(2);
	BlinkLed_Start();
	while(1)
		BlinkLed_Run();
	return 0;
}