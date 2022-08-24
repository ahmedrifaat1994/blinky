#ifndef DIO_H
#define DIO_H
/***********************************************************************
* FILE DESCRITION
* --------------------------------------------------------------------*/
/**          \file Dio.h
*           \brief Digitl Input\Output Driver
*
*         \details
*
***********************************************************************/

/***********************************************************************
* INCLUDES
***********************************************************************/


/***********************************************************************
* GLOBAL CONSTANT MACROS
***********************************************************************/
#define Dio_ChannelType             unsigned char
#define Dio_PortType                unsigned long
#define Dio_LevelType               unsigned char
#define Dio_PortLevelType           unsigned char

/***********************************************************************
* GLOBAL FUNCTION MACROS
***********************************************************************/


/***********************************************************************
* GLOBAL DATA TYPES & STRUCTURES
***********************************************************************/


/***********************************************************************
* GLOBAL DATA PROTOTYPES
***********************************************************************/


/***********************************************************************
* GLOBAL FUNCTIONS PROTOTYPES
***********************************************************************/

/******************************************************
* \Syntax          : Dio_LevelType Dio_ReadChannel(Dio_PortType PortId, Dio_ChannelType ChannelId)
* \Discription     : Reads a channel
*
* \Sync\Async      : Async
* \Reentrancy      : Reentrant
* \Parameters (in) : ChannelId
* \Parameters (out): None
* \Return value    : Dio_LevelType
******************************************************/
Dio_LevelType Dio_ReadChannel(Dio_PortType PortId, Dio_ChannelType ChannelId);
/******************************************************
* \Syntax          : void Dio_WriteChannel(Dio_PortType PortId, Dio_ChannelType ChannelId, Dio_LevelType Level)
* \Discription     : Writes a channel
*
* \Sync\Async      : Async
* \Reentrancy      : Reentrant
* \Parameters (in) : ChannelId, Level
* \Parameters (out): None
* \Return value    : None
******************************************************/
void Dio_WriteChannel(Dio_PortType PortId, Dio_ChannelType ChannelId, Dio_LevelType Level);
/******************************************************
* \Syntax          : Dio_PortLevelType Dio_ReadPort(Dio_PortType PortId)
* \Discription     : Reads Port
*
* \Sync\Async      : Async
* \Reentrancy      : Reentrant
* \Parameters (in) : PortId
* \Parameters (out): None
* \Return value    :Dio_PortLevelType
******************************************************/
Dio_PortLevelType Dio_ReadPort(Dio_PortType PortId);
/******************************************************
* \Syntax          : void Dio_WritePort(Dio_PortType PortId, Dio_PortLevelType Level)
* \Discription     : Writes Port
*
* \Sync\Async      : Async
* \Reentrancy      : Reentrant
* \Parameters (in) : PortId, Level
* \Parameters (out): None
* \Return value    : None
******************************************************/
void Dio_WritePort(Dio_PortType PortId, Dio_PortLevelType Level);
/******************************************************
* \Syntax          : Dio_LevelType Dio_FlipChannel(Dio_PortType PortId, Dio_ChannelType ChannelId)
* \Discription     : Flips Specific Channel
*
* \Sync\Async      : Async
* \Reentrancy      : Reentrant
* \Parameters (in) : ChannelId
* \Parameters (out): None
* \Return value    : Dio_LevelType
******************************************************/
Dio_LevelType Dio_FlipChannel(Dio_PortType PortId, Dio_ChannelType ChannelId);

#endif
/***********************************************************************
* END OF FILE: Dio.h
***********************************************************************/
