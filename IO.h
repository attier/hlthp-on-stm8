
//include "DriveRelay.h"#
#ifndef _gpio_h_
#define _gpio_h_
/*******************************************************************************
****hp2
****HLT
****版本:V0.1
****日期:2015.12.26
****说明:主芯片STM8S005C6
********************************************************************************/



/*typedef enum
{
  o_COMP,
    o_PUMP,
    o_4WAY,
    o_HFAN,
    o_LED1,
      o_LED2,
        o_LED3,
}o_enum;


//定义IO接口
#define o_COMP_GPIO_PORT  (GPIOE)
#define o_COMP_GPIO_PINS  (GPIO_PIN_3)

#define o_PUMP_GPIO_PORT  (GPIOG)
#define o_PUMP_GPIO_PINS  (GPIO_PIN_0)

#define o_4WAY_GPIO_PORT  (GPIOC)
#define o_4WAY_GPIO_PINS  (GPIO_PIN_6)

#define o_HFAN_GPIO_PORT  (GPIOB)
#define o_HFAN_GPIO_PINS  (GPIO_PIN_5)

#define i_HiP_GPIO_PORT  (GPIOB)
#define i_HiP_GPIO_PINS  (GPIO_PIN_3)

#define i_LoP_GPIO_PORT  (GPIOD)
#define i_LoP_GPIO_PINS  (GPIO_PIN_3)

#define i_S_GPIO_PORT  (GPIOD)
#define i_S_GPIO_PINS  (GPIO_PIN_7)
*/
//声明功能函数
//extern void IO_Init(IO_TypeDef x);
extern void LED_Off(u8 LedNum);
extern void LED_Toggle(u8 LedNum);
extern void IO_DeInit(void);

#endif
/******************* (C) COPYRIGHT 2014 LENCHIMCU.TAOBAO.COM ******************/