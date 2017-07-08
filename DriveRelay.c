#include "DriveRelay.h"
#include "IO.h"
IO_TypeDef o_COMP={GPIOE,GPIO_PIN_3};       
IO_TypeDef o_PUMP={GPIOG,GPIO_PIN_1};        
IO_TypeDef o_4WAY={GPIOC,GPIO_PIN_6};     
IO_TypeDef o_HFAN={GPIOB,GPIO_PIN_5}; 

IO_TypeDef o_LED1={GPIOA,GPIO_PIN_5};
IO_TypeDef o_LED2={GPIOA,GPIO_PIN_4};
IO_TypeDef o_LED3={GPIOA,GPIO_PIN_3};

//´íµÄÀëÆ×
IO_TypeDef i_HiP={GPIOB,GPIO_PIN_3}; 
IO_TypeDef i_LoP={GPIOD,GPIO_PIN_7}; 
IO_TypeDef i_S  ={GPIOD,GPIO_PIN_7}; 


void DriveRelay(void)
{
     if (RelayS.Com) {SET_BIT(o_COMP);}
     else            {CLR_BIT(o_COMP);}
     if (RelayS.Pump){SET_BIT(o_PUMP);}
     else            {CLR_BIT(o_PUMP);}
     if (RelayS.Fan) {SET_BIT(o_HFAN);}
     else            {CLR_BIT(o_HFAN);}
     if (RelayS.Fway){SET_BIT(o_4WAY);}
     else            {CLR_BIT(o_4WAY);}
    
}
void SET_BIT(IO_TypeDef p)
{
  
  GPIO_WriteHigh(p.PORT, p.PIN);
  
  
  
  
  
}
void CLR_BIT(IO_TypeDef p)
{
  
  
  GPIO_WriteLow(p.PORT, p.PIN);
  
  
  
  
}