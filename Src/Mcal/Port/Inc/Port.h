/**********************************************************************************************************************
 *  FILE DESCRIPTION
 *  -------------------------------------------------------------------------------------------------------------------
 *         File:  Port.h
 *       Module:  Port
 *
 *  Description:  header file for Port Module    
 *  
 *********************************************************************************************************************/
#ifndef PORT_H
#define PORT_H

/**********************************************************************************************************************
 * INCLUDES
 *********************************************************************************************************************/
#include "Std_Types.h"
#include "Port_Types.h"
#include "Dio_Cfg.h"

/**********************************************************************************************************************
 *  GLOBAL CONSTANT MACROS
 *********************************************************************************************************************/
#define Port_APB	1

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
void Port_Init(const Port_ConfigType* ConfigPtr);

#endif  /* PORT_H */

/**********************************************************************************************************************
 *  END OF FILE: PORT_H.h
 *********************************************************************************************************************/