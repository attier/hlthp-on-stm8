
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
*/
extern void IO_Init(IO_TypeDef x);
extern void IO_DeInit(void);

#endif
