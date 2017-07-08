#include "IO.h"
#include "DriveRelay.h"


void IO_DeInit(void)
{
   GPIO_DeInit(GPIOA);
   GPIO_DeInit(GPIOB);
   GPIO_DeInit(GPIOC);
   GPIO_DeInit(GPIOD);
   GPIO_DeInit(GPIOE);
   GPIO_DeInit(GPIOF);
   GPIO_DeInit(GPIOG);  
}



void IO_Init(IO_TypeDef x)
{
   GPIO_Init(x.PORT, x.PIN, GPIO_MODE_OUT_PP_LOW_FAST);
   }

/