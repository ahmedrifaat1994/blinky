#ifndef PORT_H
#define PORT_H
/***********************************************************************
* FILE DESCRITION
* --------------------------------------------------------------------*/
/**          \file Port.h
*           \brief Port Driver
*
*         \details
*
***********************************************************************/

/***********************************************************************
* INCLUDES
***********************************************************************/
#include "Dio.h"
/***********************************************************************
* GLOBAL CONSTANT MACROS
***********************************************************************/
#define Port_InstanceType unsigned long
/***********************************************************************
* GLOBAL FUNCTION MACROS
***********************************************************************/
/***********************************************************************
* GLOBAL DATA TYPES & STRUCTURES
***********************************************************************/


typedef enum{
	PIN0,
	PIN1,
	PIN2,
	PIN3,
	PIN4,
	PIN5,
	PIN6,
	PIN7
}Port_PinType;

typedef enum{
	DIO
}Port_PinModeType;

typedef enum{
	INPUT,
	OUTPUT
}Port_PinDirectionType;

typedef enum{
	LOW = 0x00,
	HIGH = 0xFF
}PortPinLevelValueType;

typedef enum{
	PU,
	PD
}Port_PinInternalAttachType;

typedef enum{
	C_2_MA,
	C_4_MA,
	C_8_MA
}Port_PinOutputCurrentType;


typedef struct{
    Port_InstanceType               Port_Instance;
	Port_PinType                    Port_Pin;
	Port_PinModeType                PortPinMode;
	PortPinLevelValueType           PortPinLevelValue;
	Port_PinDirectionType           PortPinDirection;
	Port_PinInternalAttachType      Port_PinInternalAttach;
	/*Port_PinOutputCurrentType       Port_PinOutputCurrent;*/
}Port_ConfigType;
/***********************************************************************
* GLOBAL DATA PROTOTYPES
***********************************************************************/
/***********************************************************************
* GLOBAL FUNCTIONS PROTOTYPES
***********************************************************************/

/******************************************************
* \Syntax          : void Port_Init(const Port_ConfigType* ConfigPtr)
* \Discription     : Initilaize a specific port
*
* \Sync\Async      : Async
* \Reentrancy      :
* \Parameters (in) : const Port_ConfigType* ConfigPtr
* \Parameters (out): None
* \Return value    : None
******************************************************/
void Port_Init(const Port_ConfigType* ConfigPtr);

#endif
/***********************************************************************
* END OF FILE: Port.h
***********************************************************************/
