/**********************************************************************************************************************
 *  FILE DESCRIPTION
 *  -----------------------------------------------------------------------------------------------------------------*/
/**        \file  Port.c
 *        \brief  General perpose input output driver Driver
 *
 *      \details  The Driver Configure All MCU pins
 *                Enable Port pin
 *								Read and Write on Port pin
 *
 *********************************************************************************************************************/

/**********************************************************************************************************************
 *  INCLUDES
 *********************************************************************************************************************/
#include "Std_Types.h"
#include "Macros.h"
#include "Port.h"
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


/******************************************************************************
* \Syntax          : void Port_Init(const Port_ConfigType*ConfigPtr)                                      
* \Description     : Initializes the Port Driver module.                                    
*                                                                             
* \Sync\Async      : Synchronous                                               
* \Reentrancy      : Reentrant                                             
* \Parameters (in) : ConfigPtr: pointer to user configurations                     
* \Parameters (out): None                                                      
* \Return value:   : None
*******************************************************************************/
void Port_Init(const Port_ConfigType* ConfigPtr)
{
	/*Enable Clocking for the Port*/
	SET_BIT(SYSCTL->RCGCGPIO,(ConfigPtr->Channel.Port));

	/*TODO:add interrupt handling if needed*/
	switch (ConfigPtr->Channel.Port) {
	case (PORTA):
		/*Setting Direction*/
		if (ConfigPtr->Direction)
			SET_BIT(GPIOA->DIR,ConfigPtr->Channel.Pin);
		else CLEAR_BIT(GPIOA->DIR,ConfigPtr->Channel.Pin);

		/*Setting Alternate Function*/
		if(ConfigPtr->Mode)
			SET_BIT(GPIOA->AFSEL,ConfigPtr->Mode);
		
		/*Setting Attach Output Current*/
		if(ConfigPtr->Current == R2R)
			SET_BIT(GPIOA->DR2R,ConfigPtr->Channel.Pin);
		else if(ConfigPtr->Current == R4R)
			SET_BIT(GPIOA->DR4R,ConfigPtr->Channel.Pin);
		else if(ConfigPtr->Current == R8R)
			SET_BIT(GPIOA->DR8R,ConfigPtr->Channel.Pin);
		
		/*Setting Attach Resistor*/
		if(ConfigPtr->Attach == PULL_DOWN)
			SET_BIT(GPIOA->PDR,ConfigPtr->Channel.Pin);
		else if(ConfigPtr->Attach == PULL_UP)
			SET_BIT(GPIOA->PUR,ConfigPtr->Channel.Pin);
		else if((ConfigPtr->Attach) == OPEN_DRAIN)
			SET_BIT(GPIOA->ODR,ConfigPtr->Channel.Pin);		

		/* Enable Port */
		SET_BIT(GPIOA->DEN,ConfigPtr->Channel.Pin);
		break;
	case (PORTB):
		/*Setting Direction*/
		if (ConfigPtr->Direction)
			SET_BIT(GPIOB->DIR,ConfigPtr->Channel.Pin);
		else CLEAR_BIT(GPIOB->DIR,ConfigPtr->Channel.Pin);

		/*Setting Alternate Function*/
		if(ConfigPtr->Mode)
			SET_BIT(GPIOB->AFSEL,ConfigPtr->Mode);
		
		/*Setting Attach Output Current*/
		if(ConfigPtr->Current == R2R)
			SET_BIT(GPIOB->DR2R,ConfigPtr->Channel.Pin);
		else if(ConfigPtr->Current == R4R)
			SET_BIT(GPIOB->DR4R,ConfigPtr->Channel.Pin);
		else if(ConfigPtr->Current == R8R)
			SET_BIT(GPIOB->DR8R,ConfigPtr->Channel.Pin);
		
		/*Setting Attach Resistor*/
		if(ConfigPtr->Attach == PULL_DOWN)
			SET_BIT(GPIOB->PDR,ConfigPtr->Channel.Pin);
		else if(ConfigPtr->Attach == PULL_UP)
			SET_BIT(GPIOB->PUR,ConfigPtr->Channel.Pin);
		else if((ConfigPtr->Attach) == OPEN_DRAIN)
			SET_BIT(GPIOB->ODR,ConfigPtr->Channel.Pin);		

		/* Enable Port */
		SET_BIT(GPIOB->DEN,ConfigPtr->Channel.Pin);
		break;
	case (PORTC):
		/*Setting Direction*/
		if (ConfigPtr->Direction)
			SET_BIT(GPIOC->DIR,ConfigPtr->Channel.Pin);
		else CLEAR_BIT(GPIOC->DIR,ConfigPtr->Channel.Pin);

		/*Setting Alternate Function*/
		if(ConfigPtr->Mode)
			SET_BIT(GPIOC->AFSEL,ConfigPtr->Mode);
		
		/*Setting Attach Output Current*/
		if(ConfigPtr->Current == R2R)
			SET_BIT(GPIOC->DR2R,ConfigPtr->Channel.Pin);
		else if(ConfigPtr->Current == R4R)
			SET_BIT(GPIOC->DR4R,ConfigPtr->Channel.Pin);
		else if(ConfigPtr->Current == R8R)
			SET_BIT(GPIOC->DR8R,ConfigPtr->Channel.Pin);
		
		/*Setting Attach Resistor*/
		if(ConfigPtr->Attach == PULL_DOWN)
			SET_BIT(GPIOC->PDR,ConfigPtr->Channel.Pin);
		else if(ConfigPtr->Attach == PULL_UP)
			SET_BIT(GPIOC->PUR,ConfigPtr->Channel.Pin);
		else if((ConfigPtr->Attach) == OPEN_DRAIN)
			SET_BIT(GPIOC->ODR,ConfigPtr->Channel.Pin);		

		/* Enable Port */
		SET_BIT(GPIOC->DEN,ConfigPtr->Channel.Pin);
		break;
	case (PORTD):
		/*Setting Direction*/
		if (ConfigPtr->Direction)
			SET_BIT(GPIOD->DIR,ConfigPtr->Channel.Pin);
		else CLEAR_BIT(GPIOD->DIR,ConfigPtr->Channel.Pin);

		/*Setting Alternate Function*/
		if(ConfigPtr->Mode)
			SET_BIT(GPIOD->AFSEL,ConfigPtr->Mode);
		
		/*Setting Attach Output Current*/
		if(ConfigPtr->Current == R2R)
			SET_BIT(GPIOD->DR2R,ConfigPtr->Channel.Pin);
		else if(ConfigPtr->Current == R4R)
			SET_BIT(GPIOD->DR4R,ConfigPtr->Channel.Pin);
		else if(ConfigPtr->Current == R8R)
			SET_BIT(GPIOD->DR8R,ConfigPtr->Channel.Pin);
		
		/*Setting Attach Resistor*/
		if(ConfigPtr->Attach == PULL_DOWN)
			SET_BIT(GPIOD->PDR,ConfigPtr->Channel.Pin);
		else if(ConfigPtr->Attach == PULL_UP)
			SET_BIT(GPIOD->PUR,ConfigPtr->Channel.Pin);
		else if((ConfigPtr->Attach) == OPEN_DRAIN)
			SET_BIT(GPIOD->ODR,ConfigPtr->Channel.Pin);		

		/* Enable Port */
		SET_BIT(GPIOD->DEN,ConfigPtr->Channel.Pin);
		break;
	case (PORTE):
		/*Setting Direction*/
		if (ConfigPtr->Direction)
			SET_BIT(GPIOE->DIR,ConfigPtr->Channel.Pin);
		else CLEAR_BIT(GPIOE->DIR,ConfigPtr->Channel.Pin);

		/*Setting Alternate Function*/
		if(ConfigPtr->Mode)
			SET_BIT(GPIOE->AFSEL,ConfigPtr->Mode);
		
		/*Setting Attach Output Current*/
		if(ConfigPtr->Current == R2R)
			SET_BIT(GPIOE->DR2R,ConfigPtr->Channel.Pin);
		else if(ConfigPtr->Current == R4R)
			SET_BIT(GPIOE->DR4R,ConfigPtr->Channel.Pin);
		else if(ConfigPtr->Current == R8R)
			SET_BIT(GPIOE->DR8R,ConfigPtr->Channel.Pin);
		
		/*Setting Attach Resistor*/
		if(ConfigPtr->Attach == PULL_DOWN)
			SET_BIT(GPIOE->PDR,ConfigPtr->Channel.Pin);
		else if(ConfigPtr->Attach == PULL_UP)
			SET_BIT(GPIOE->PUR,ConfigPtr->Channel.Pin);
		else if((ConfigPtr->Attach) == OPEN_DRAIN)
			SET_BIT(GPIOE->ODR,ConfigPtr->Channel.Pin);		

		/* Enable Port */
		SET_BIT(GPIOE->DEN,ConfigPtr->Channel.Pin);
		break;
		case (PORTF):
		/*Setting Direction*/
		if (ConfigPtr->Direction)
			SET_BIT(GPIOF->DIR,ConfigPtr->Channel.Pin);
		else CLEAR_BIT(GPIOF->DIR,ConfigPtr->Channel.Pin);

		/*Setting Alternate Function*/
		if(ConfigPtr->Mode)
			SET_BIT(GPIOF->AFSEL,ConfigPtr->Mode);
		
		/*Setting Attach Output Current*/
		if(ConfigPtr->Current == R2R)
			SET_BIT(GPIOF->DR2R,ConfigPtr->Channel.Pin);
		else if(ConfigPtr->Current == R4R)
			SET_BIT(GPIOF->DR4R,ConfigPtr->Channel.Pin);
		else if(ConfigPtr->Current == R8R)
			SET_BIT(GPIOF->DR8R,ConfigPtr->Channel.Pin);
		
		/*Setting Attach Resistor*/
		if(ConfigPtr->Attach == PULL_DOWN)
			SET_BIT(GPIOF->PDR,ConfigPtr->Channel.Pin);
		else if(ConfigPtr->Attach == PULL_UP)
			SET_BIT(GPIOF->PUR,ConfigPtr->Channel.Pin);
		else if((ConfigPtr->Attach) == OPEN_DRAIN)
			SET_BIT(GPIOF->ODR,ConfigPtr->Channel.Pin);		

		/* Enable Port */
		SET_BIT(GPIOF->DEN,ConfigPtr->Channel.Pin);
		break;
	}
}

/**********************************************************************************************************************
 *  END OF FILE: Port.c
 *********************************************************************************************************************/