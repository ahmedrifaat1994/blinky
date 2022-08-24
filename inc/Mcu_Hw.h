#ifndef MCU_HW_H
#define MCU_HW_H
/***********************************************************************
* FILE DESCRITION
* --------------------------------------------------------------------*/
/**          \file Mcu_Hw.h
*           \brief MC Memory Map Registers
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
#define BIT0                (0)
#define BIT1                (1)
#define BIT2                (2)
#define BIT3                (3)
#define BIT4                (4)
#define BIT5                (5)
#define BIT6                (6)
#define BIT7                (7)

#define BYTE0               (0)
#define BYTE1               (1)
#define BYTE2               (2)
#define BYTE3               (3)

#define BIT_MASK0           (0x04)
#define BIT_MASK1           (0x08)
#define BIT_MASK2           (0x10)
#define BIT_MASK3           (0x20)
#define BIT_MASK4           (0x40)
#define BIT_MASK5           (0x80)
#define BIT_MASK6           (0x100)
#define BIT_MASK7           (0x200)

#define BIT_MASK0_SET           (0x01)
#define BIT_MASK1_SET           (0x02)
#define BIT_MASK2_SET           (0x04)
#define BIT_MASK3_SET           (0x08)
#define BIT_MASK4_SET           (0x10)
#define BIT_MASK5_SET           (0x20)
#define BIT_MASK6_SET           (0x40)
#define BIT_MASK7_SET           (0x80)

#define BM_SET                  (0xFF)
#define BM_CLEAR                (0x00)

#define PERIPHERAL_BIT_BAND_ALIAS      (0x42000000)

#define PORTA_APB           (0x40004000)
#define PORTA_AHB           (0x40058000)
#define PORTB_APB           (0x40005000)
#define PORTB_AHB           (0x40059000)
#define PORTC_APB           (0x40006000)
#define PORTC_AHB           (0x4005A000)
#define PORTD_APB           (0x40007000)
#define PORTD_AHB           (0x4005B000)
#define PORTE_APB           (0x40024000)
#define PORTE_AHB           (0x4005C000)
#define PORTF_APB           (0x40025000)
#define PORTF_AHB           (0x4005D000)

#define PORTA           (0)
#define PORTB           (1)
#define PORTC           (2)
#define PORTD           (3)
#define PORTE           (4)
#define PORTF           (5)

#define GPIODATA            (0x000)
#define GPIODIR             (0x400)
#define GPIOIS              (0x404)
#define GPIOIBE             (0x408)
#define GPIOIEV             (0x40C)
#define GPIOIM              (0x410)
#define GPIORIS             (0x414)
#define GPIOMIS             (0x418)
#define GPIOICR             (0x41C)
#define GPIOAFSEL           (0x420)
#define GPIODR2R            (0x500)
#define GPIODR4R            (0x504)
#define GPIODR8R            (0x508)
#define GPIOODR             (0x50C)
#define GPIOPUR             (0x510)
#define GPIOPDR             (0x514)
#define GPIOSLR             (0x518
#define GPIODEN             (0x51C)
#define GPIOLOCK            (0x520)
#define GPIOCR              (0x524)
#define GPIOAMSEL           (0x528)
#define GPIOPCTL            (0x52C)

#define RCGC2               (0x400FE108)

#define TIMER0              (0x40030000)

#define GPTMCTL             (0x00C)
#define GPTMCFG             (0x000)
#define GPTMTAMR            (0x004)
#define GPTMTAILR           (0x028)
#define GPTMIMR             (0x018)
#define GPTMICR             (0x024)
#define GPTMTAPR            (0x038)
#define GPTMTAR             (0x048)
#define GPTMTAV             (0x050)
#define GPTMTAPS            (0x05C)
#define GPTMRIS             (0x01C)

#define RCGCTIMER           (0x400FE000+0x604)

/***********************************************************************
* GLOBAL FUNCTION MACROS
***********************************************************************/
#define SET_CLK(PORT)                        ((*((volatile unsigned long *)(RCGC2))) =  (0x01 << PORT))
#define SET_TIMER_CLK(TIMER)                 ((*((volatile unsigned long *)(RCGCTIMER))) =  (0x01 << TIMER))
#define ADDR(PORT, REG)                      (*((volatile unsigned long *)(PORT+REG)))
#define BB_ADDR(PORT, REG, BYTE, PIN)        (*((volatile unsigned long*)(PERIPHERAL_BIT_BAND_ALIAS+(((PORT+REG)-0x40000000)*32)+(PIN*4))))
#define BM_ADDR(PORT, REG, PIN)              (*((volatile unsigned long *)(PORT+REG+PIN)))
/***********************************************************************
* GLOBAL DATATYPES & STRUCTURES
***********************************************************************/

/***********************************************************************
* GLOBAL DATA PROTOTYPES
***********************************************************************/

#endif
/***********************************************************************
* END OF FILE: Mcu_Hw.h
***********************************************************************/
