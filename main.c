
#include "inc\Mcu_Hw.h"
#include "inc\Dio.h"
#include "inc\Port.h"
#include "inc\Timer.h"
#include "inc\IntCtrl.h"

/**
 * main.c
 */
int main(void)
{

    Port_ConfigType Port_cfg;
    Gpt_ConfigType  Timer_cfg;

    Port_cfg.Port_Instance = PORTF;
    Port_cfg.Port_Pin = PIN1;
    Port_cfg.PortPinMode = DIO;
    Port_cfg.PortPinLevelValue = LOW;
    Port_cfg.PortPinDirection = OUTPUT;

    Timer_cfg.Mode = GPT_CH_MODE_CONTINUOUSE;
    Timer_cfg.GptPrescaler = 16000; /* 16000000/16000 = 1000*/
    Timer_cfg.InterruptStatus = ENABLE;

    Port_Init(&Port_cfg);
    Gpt_Init(&Timer_cfg);
    IntCtrl_Init();
    Gpt_StartTimer(500-1); /*Interrupt every 500ms*/

    while(1){

    }

}
