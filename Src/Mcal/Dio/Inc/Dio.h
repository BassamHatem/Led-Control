/**********************************************************************************************************************
 *  FILE DESCRIPTION
 *  -------------------------------------------------------------------------------------------------------------------
 *         File:  Dio.h
 *       Module:  -
 *
 *  Description:  <Write File DESCRIPTION here>     
 *  
 *********************************************************************************************************************/
#ifndef DIO_H
#define DIO_H

/**********************************************************************************************************************
 * INCLUDES
 *********************************************************************************************************************/
#include "Std_Types.h"
#include "Dio_Types.h"
#include "Port_Types.h"

/**********************************************************************************************************************
 *  GLOBAL CONSTANT MACROS
 *********************************************************************************************************************/
extern const Port_ConfigType Dio_Config;

/**********************************************************************************************************************
 *  GLOBAL FUNCTION MACROS
 *********************************************************************************************************************/
#define SYSCTL_RCGCGPIO							*((volatile uint32*)0x400FE608)
/* GPIO DIGITAL ENABLE REGISTERS*/
#define GPIO_PORTA_DEN							*((volatile uint32*)0x4000451C)
#define GPIO_PORTB_DEN							*((volatile uint32*)0x4000551C)
#define GPIO_PORTC_DEN							*((volatile uint32*)0x4000651C)
#define GPIO_PORTD_DEN							*((volatile uint32*)0x4000751C)
#define GPIO_PORTE_DEN							*((volatile uint32*)0x4002451C)
#define GPIO_PORTF_DEN							*((volatile uint32*)0x4002551C)


/**********************************************************************************************************************
 *  GLOBAL DATA TYPES AND STRUCTURES
 *********************************************************************************************************************/
Dio_LevelType Dio_ReadChannel(Port_ChannelType ChannelId);
void Dio_WriteChannel(Port_ChannelType ChannelId,Dio_LevelType Level);
Dio_PortLevelType Dio_ReadPort(Dio_PortType PortId);
void Dio_WritePort(Dio_PortType PortId,Dio_PortLevelType Level);
Dio_LevelType Dio_FlipChannel(Port_ChannelType ChannelId);


#endif  /* DIO_H */

/**********************************************************************************************************************
 *  END OF FILE: DIO.h
 *********************************************************************************************************************/
 