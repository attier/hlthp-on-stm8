#include "Timer4.h"
void Timer4_Init(u8 Count)
{
	TIM4_DeInit();  	
    TIM4_TimeBaseInit(TIM4_PRESCALER_128,Count);
     
	TIM4_ITConfig(TIM4_IT_UPDATE, ENABLE);
	TIM4_Cmd(ENABLE);
}