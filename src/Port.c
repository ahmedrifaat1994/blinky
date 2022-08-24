/***********************************************************************
* FILE DESCRITION
* --------------------------------------------------------------------*/
/**          \file Port.c
*           \brief Port Driver
*
*         \details
*
***********************************************************************/
/***********************************************************************
* INCLUDES
***********************************************************************/
#include "Mcu_Hw.h"
#include "Dio.h"
#include "Port.h"
/***********************************************************************
* GLOBAL CONSTANT MACROS
***********************************************************************/
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
* \Syntax          : void Port_Init(const Port_ConfigType* ConfigPtr)
* \Discription     : Initilaize a specific port
*
* \Sync\Async      : Async
* \Reentrancy      :
* \Parameters (in) : const Port_ConfigType* ConfigPtr
* \Parameters (out): None
* \Return value    : None
******************************************************/
void Port_Init(const Port_ConfigType* ConfigPtr){

    static unsigned long instance = PORTA_APB; /*PORTA_APB by default*/

    /*choose the right instance*/
    if(ConfigPtr->Port_Instance == PORTA){
        instance = PORTA_APB;
    }
    else if(ConfigPtr->Port_Instance == PORTB){
        instance = PORTB_APB;
    }
    else if(ConfigPtr->Port_Instance == PORTC){
        instance = PORTC_APB;
    }
    else if(ConfigPtr->Port_Instance == PORTD){
        instance = PORTD_APB;
    }
    else if(ConfigPtr->Port_Instance == PORTE){
        instance = PORTE_APB;
    }
    else if(ConfigPtr->Port_Instance == PORTF){
        instance = PORTF_APB;
    }

	/*Enable Clock for Port*/
    SET_CLK(ConfigPtr->Port_Instance);
	
	/*Disable Analog*/
	BB_ADDR(instance, GPIOAMSEL, BYTE0, ConfigPtr->Port_Pin) = BM_CLEAR;
	
	/*Select IO Operations*/
	ADDR(instance, GPIOPCTL) &= (0xFFFFFFFF & (0x0F << (ConfigPtr->Port_Pin*4)));
	
	/*Choose Direction*/
	BB_ADDR(instance, GPIODIR, BYTE0, ConfigPtr->Port_Pin) = ConfigPtr->PortPinDirection;
	
	/*Enable\Disable Alternative*/
	BB_ADDR(instance, GPIOAFSEL, BYTE0, ConfigPtr->Port_Pin) = ConfigPtr->PortPinMode;
	
	/*Choose Pull up\Pull Down*/
	if(ConfigPtr->PortPinDirection == INPUT){
        if(ConfigPtr->Port_PinInternalAttach == PU){
            BB_ADDR(instance, GPIODEN, BYTE0, ConfigPtr->Port_Pin) = BM_SET;
        }
        else if(ConfigPtr->Port_PinInternalAttach == PD){
            BB_ADDR(instance, GPIODEN, BYTE0, ConfigPtr->Port_Pin) = BM_SET;
        }
	}
	
	/*Enable Digital*/
	BB_ADDR(instance, GPIODEN, BYTE0, ConfigPtr->Port_Pin) = BM_SET;
	
	/*Set Output Value*/
	if(ConfigPtr->PortPinDirection == OUTPUT){
	    unsigned long pin = (0x01 << (ConfigPtr->Port_Pin + 2));

	    BM_ADDR(instance, GPIODATA, pin) = ConfigPtr->PortPinLevelValue;
	}
/*
	//Choose PWR
	if(ConfigPtr->Port_PinOutputCurrent == C_2_MA){
		BB_ADDR(ConfigPtr->Port_Instance, GPIODR2R, BYTE0, ConfigPtr->Port_Pin) = 1;
	}
	else if(ConfigPtr->Port_PinOutputCurrent == C_4_MA){
		BB_ADDR(ConfigPtr->Port_Instance, GPIODR4R, BYTE0, ConfigPtr->Port_Pin) = 1;
	}
	else if(ConfigPtr->Port_PinOutputCurrent == C_8_MA){
		BB_ADDR(ConfigPtr->Port_Instance, GPIODR8R, BYTE0, ConfigPtr->Port_Pin) = 1;
	}*/
}

/***********************************************************************
* END OF FILE: Port.c
***********************************************************************/
