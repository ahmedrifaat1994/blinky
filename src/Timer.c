/***********************************************************************
* FILE DESCRITION
* --------------------------------------------------------------------*/
/**          \file Timer.c
*           \brief Timer Driver
*
*         \details
*
***********************************************************************/
/***********************************************************************
* INCLUDES
***********************************************************************/
#include "Mcu_Hw.h"
#include "Timer.h"
#include "IntCtrl.h"

/***********************************************************************
* GLOBAL DATA PROTOTYPES
***********************************************************************/

/***********************************************************************
* GLOBAL FUNCTIONS PROTOTYPES
***********************************************************************/

/******************************************************
* \Syntax          : void Gpt_Init(const Gpt_ConfigType* ConfigPtr)
* \Discription     : initialize the timer
*
* \Sync\Async      : 
* \Reentrancy      : 
* \Parameters (in) : ConfigPtr
* \Parameters (out): None
* \Return value    : None
******************************************************/
void Gpt_Init(const Gpt_ConfigType* ConfigPtr){
    /*Enable Timer0 Clock*/
    SET_TIMER_CLK(0);
	/*Ensure the timer is disabled*/
	BB_ADDR(TIMER0, GPTMCTL, BYTE0, BIT0) = 0;
	
	/*Only 16 bit wide timer in 16\32, and 32 in 32\64*/
	ADDR(TIMER0, GPTMCFG) = 0x04;
	
	/*Choose mode*/
	if(ConfigPtr->Mode == GPT_CH_MODE_CONTINUOUSE){
		/*hoose Periodic*/
		ADDR(TIMER0, GPTMTAMR) = 0x2;
	}
	else if(ConfigPtr->Mode == GPT_CH_MODE_ONESHOT){
		/*Choose Oneshot*/
		ADDR(TIMER0, GPTMTAMR) = 0x1;
	}

	/*Choose Count up*/
	BB_ADDR(TIMER0, GPTMTAMR, BYTE0, BIT4) = 1;
	
	/*reload Value on the next cycle*/
/*	BB_ADDR(TIMER0, GPTMTAMR, BYTE1, BIT0) = 0;*/
	
	/*Prescaler*/
	ADDR(TIMER0, GPTMTAPR) = ConfigPtr->GptPrescaler;
	
	if(ConfigPtr->InterruptStatus == ENABLE){

	    /*set priority to 2*/
	    PRI16 = PRI16 | 0x40000000;

	    /*Enable Timer0 interrupt in NVIC*/
	    EN0 = EN0 | 0x80000;

	    /*Enable global Interrupt*/
	    /*Enable_Interrupts();

	    Enable_Exceptions();
*/
	    /*Enable\Disable Timer0 Interrupt*/
	    BB_ADDR(TIMER0, GPTMIMR, BYTE0, BIT0) = ConfigPtr->InterruptStatus;

	    /*Reset flag*/
	    Gpt_ClearFlag();
	}

}
/******************************************************
* \Syntax          : void Gpt_StartTimer(Gpt_ValueType Value)
* \Discription     : Starts the timer
*
* \Sync\Async      : 
* \Reentrancy      : Reentrant
* \Parameters (in) : Value
* \Parameters (out): None
* \Return value    : None
******************************************************/
void Gpt_StartTimer(Gpt_ValueType Value){
	/*Load Value*/
	ADDR(TIMER0, GPTMTAILR) = Value;
	
	/*Start Timer*/
	BB_ADDR(TIMER0, GPTMCTL, BYTE0, BIT0) = 1;
}
/******************************************************
* \Syntax          : void Gpt_StopTimer(void)
* \Discription     : Stops the timer
*
* \Sync\Async      : 
* \Reentrancy      : Reentrant
* \Parameters (in) : None
* \Parameters (out): None
* \Return value    : None
******************************************************/
void Gpt_StopTimer(void){
	/*Stop Timer*/
	BB_ADDR(TIMER0, GPTMCTL, BYTE0, BIT0) = 0;
}
/******************************************************
* \Syntax          : unsigned long Gpt_ReadFlag(void)
* \Discription     : Reads Interrupt Flag
*
* \Sync\Async      : Sync
* \Reentrancy      : Reentrant
* \Parameters (in) : None
* \Parameters (out): None
* \Return value    : unsigned long
******************************************************/
unsigned long Gpt_ReadFlag(void){
    unsigned long status = 0;

    status = BB_ADDR(TIMER0, GPTMRIS, BYTE0, BIT0);

    return status;
}
/******************************************************
* \Syntax          : void Gpt_ClearFlag(void)
* \Discription     : Clears interrupt Flag
*
* \Sync\Async      : Sync
* \Reentrancy      : Reentrant
* \Parameters (in) : None
* \Parameters (out): None
* \Return value    : None
******************************************************/
void Gpt_ClearFlag(void){
    BB_ADDR(TIMER0, GPTMICR, BYTE0, BIT0) = 1;
}
/***********************************************************************
* END OF FILE: Timer.c
***********************************************************************/
