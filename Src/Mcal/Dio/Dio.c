/**********************************************************************************************************************
 *  FILE DESCRIPTION
 *  -----------------------------------------------------------------------------------------------------------------*/
/**        \file  Dio.c
 *        \brief  INPUT OUTPUT Driver
 *		\details: no configuration is needed for this driver as it is used to read and write from and to Dio oin
 *        
 *
 *********************************************************************************************************************/

/**********************************************************************************************************************
 *  INCLUDES
 *********************************************************************************************************************/
#include "Std_Types.h"
#include "Macros.h"
#include "Dio.h"
#include "Mcu_Hw.h"

/**********************************************************************************************************************
*  LOCAL MACROS CONSTANT\FUNCTION
*********************************************************************************************************************/	

/**********************************************************************************************************************
 *  LOCAL DATA 
 *********************************************************************************************************************/

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
Dio_LevelType Dio_ReadChannel(Port_ChannelType ChannelId)
{	
switch (ChannelId.Port) {
	case (PORTA):
		return (Dio_LevelType)GET_BIT(GPIOA->DATA,ChannelId.Pin);
		break;
	case (PORTB):
		return (Dio_LevelType)GET_BIT(GPIOB->DATA,ChannelId.Pin);
		break;
	case (PORTC):
		return (Dio_LevelType)GET_BIT(GPIOC->DATA,ChannelId.Pin);
		break;
	case (PORTD):
		return (Dio_LevelType)GET_BIT(GPIOD->DATA,ChannelId.Pin);
		break;
	case (PORTE):
		return (Dio_LevelType)GET_BIT(GPIOE->DATA,ChannelId.Pin);
		break;
	case (PORTF):
		return (Dio_LevelType)GET_BIT(GPIOF->DATA,ChannelId.Pin);
		break;
	}
}

void Dio_WriteChannel(Port_ChannelType ChannelId,Dio_LevelType Level){
	switch (ChannelId.Port) {
	case (PORTA):
		if (Level)
			SET_BIT(GPIOA->DATA,ChannelId.Pin);
		else CLEAR_BIT(GPIOA->DATA,ChannelId.Pin);
		break;
	case (PORTB):
		if (Level)
			SET_BIT(GPIOB->DATA,ChannelId.Pin);
		else CLEAR_BIT(GPIOB->DATA,ChannelId.Pin);
		break;
	case (PORTC):
		if (Level)
			SET_BIT(GPIOC->DATA,ChannelId.Pin);
		else CLEAR_BIT(GPIOC->DATA,ChannelId.Pin);
		break;
	case (PORTD):
		if (Level)
			SET_BIT(GPIOD->DATA,ChannelId.Pin);
		else CLEAR_BIT(GPIOD->DATA,ChannelId.Pin);
		break;
	case (PORTE):
		if (Level)
			SET_BIT(GPIOE->DATA,ChannelId.Pin);
		else CLEAR_BIT(GPIOE->DATA,ChannelId.Pin);
		break;
	case (PORTF):
		if (Level)
			SET_BIT(GPIOF->DATA,ChannelId.Pin);
		else CLEAR_BIT(GPIOF->DATA,ChannelId.Pin);
		break;
	}
}

Dio_PortLevelType Dio_ReadPort(Dio_PortType PortId){
	switch (PortId) {
	case (PORTA):
		return (Dio_PortLevelType)GPIOA->DATA;
		break;
	case (PORTB):
		return (Dio_PortLevelType)GPIOB->DATA;
		break;
	case (PORTC):
		return (Dio_PortLevelType)GPIOC->DATA;
		break;
	case (PORTD):
		return (Dio_PortLevelType)GPIOD->DATA;
		break;
	case (PORTE):
		return (Dio_PortLevelType)GPIOE->DATA;
		break;
	case (PORTF):
		return (Dio_PortLevelType)GPIOF->DATA;
		break;
	}
}

void Dio_WritePort(Dio_PortType PortId,Dio_PortLevelType Level){
	switch (PortId) {
	case (PORTA):
		GPIOA->DATA=Level;
		break;
	case (PORTB):
		GPIOB->DATA=Level;
		break;
	case (PORTC):
		GPIOC->DATA=Level;
		break;
	case (PORTD):
		GPIOD->DATA=Level;
		break;
	case (PORTE):
		GPIOE->DATA=Level;
		break;
	case (PORTF):
		GPIOF->DATA=Level;
		break;
	}
}

Dio_LevelType Dio_FlipChannel(Port_ChannelType ChannelId){
	switch (ChannelId.Port) {
	case (PORTA):
		Toggle_BIT(GPIOA->DATA,ChannelId.Pin);
		return GET_BIT(GPIOA->DATA,ChannelId.Pin);
		break;
	case (PORTB):
		Toggle_BIT(GPIOB->DATA,ChannelId.Pin);
		return GET_BIT(GPIOB->DATA,ChannelId.Pin);
		break;
	case (PORTC):
		Toggle_BIT(GPIOC->DATA,ChannelId.Pin);
		return GET_BIT(GPIOC->DATA,ChannelId.Pin);
		break;
	case (PORTD):
		Toggle_BIT(GPIOD->DATA,ChannelId.Pin);
		return GET_BIT(GPIOD->DATA,ChannelId.Pin);
		break;
	case (PORTE):
		Toggle_BIT(GPIOD->DATA,ChannelId.Pin);
		return GET_BIT(GPIOD->DATA,ChannelId.Pin);
		break;
	case (PORTF):
		Toggle_BIT(GPIOD->DATA,ChannelId.Pin);
		return GET_BIT(GPIOD->DATA,ChannelId.Pin);
		break;
	}
}

/**********************************************************************************************************************
 *  END OF FILE: Dio.c
 *********************************************************************************************************************/
