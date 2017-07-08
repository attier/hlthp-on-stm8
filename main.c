#include "include.h" 
union JudgeFlag Judge; 
union RelayFlag1 RelayS; 
union TimeCount TM; 
union ErrFlag SysErr;
static void InitAdc1HW(int);

int T[8];             //温度
//int x;




int main( void )
{CLK_HSECmd(DISABLE);
//CLK_PeripheralClockConfig(CLK_PERIPHERAL_TIMER4, ENABLE);
  IO_DeInit();
  Timer4_Init(0xff);
//TM.EVHRun=1;
  enableInterrupts();
  IO_Init(o_LED1);
  
  IO_Init(o_LED2);
  IO_Init(o_LED3);
 
  IO_Init(o_COMP);
  IO_Init(o_HFAN);
  IO_Init(o_PUMP);
  IO_Init(o_4WAY);
    
  GPIO_WriteLow(GPIOA, GPIO_PIN_5);
  GPIO_WriteLow(GPIOA, GPIO_PIN_4);
  GPIO_WriteHigh(GPIOA, GPIO_PIN_3);
  //机组开关、高压、低压、机组开关
  GPIO_Init(GPIOC, GPIO_PIN_5, GPIO_MODE_IN_FL_NO_IT);
  GPIO_Init(GPIOC, GPIO_PIN_4, GPIO_MODE_IN_FL_NO_IT);
  GPIO_Init(GPIOC, GPIO_PIN_3, GPIO_MODE_IN_FL_NO_IT);
  //按键
  GPIO_Init(GPIOE, GPIO_PIN_1, GPIO_MODE_IN_FL_NO_IT);
  //eev
  GPIO_Init(GPIOD, GPIO_PIN_2, GPIO_MODE_OUT_PP_LOW_FAST);
  GPIO_Init(GPIOD, GPIO_PIN_3, GPIO_MODE_OUT_PP_LOW_FAST);
  GPIO_Init(GPIOD, GPIO_PIN_4, GPIO_MODE_OUT_PP_LOW_FAST);
  GPIO_Init(GPIOD, GPIO_PIN_7, GPIO_MODE_OUT_PP_LOW_FAST);
  eevinit();
  while(1)
  {
    
    
      if((!GPIO_ReadInputPin(GPIOC, GPIO_PIN_3))||(!GPIO_ReadInputPin(GPIOC, GPIO_PIN_4)))
    
     {
       if(TM.ComRun>=120)
    SysErr.P6=0x1;
   //GPIO_WriteLow(GPIOA, GPIO_PIN_5);
     }
     else {SysErr.P6=0x0;
     
     }
     
   if(GPIO_ReadInputPin(GPIOC, GPIO_PIN_5)!=0)
     {//x= GPIO_ReadInputPin(GPIOC, GPIO_PIN_5);
 
    GPIO_WriteLow(GPIOA, GPIO_PIN_4);}
   else GPIO_WriteHigh(GPIOA, GPIO_PIN_4);
    
    DriveTime();
    HPSystem();
   // if(TM.EVHRun>1)
    //  RelayS.Fan=1;
    DriveRelay();
    //if(TM.ComRun>120)
      
    
    for( int i=0;i<=3;i++)
				{   InitAdc1HW(i);
				ADC_Task(i);
			}
    
     InitAdc1HW(8);
  ADC_Task(7);
  }
  
 
  
  
  
  
  
  return 0;
}

static void InitAdc1HW(int ADC1_Channel_X)
{
    //Set ADC1 to default setting
    ADC1_DeInit();
    ADC1_Init(ADC1_CONVERSIONMODE_SINGLE,               //Single mode
              (ADC1_Channel_TypeDef)ADC1_Channel_X,     //Use channel X
              ADC1_PRESSEL_FCPU_D2,                     //Pre-12
              ADC1_EXTTRIG_TIM, DISABLE,                //Don't use external trigger
              ADC1_ALIGN_RIGHT,                         //Align to right
             (ADC1_SchmittTrigg_TypeDef)ADC1_Channel_X, ENABLE);  //not use schmitter
			  
    		  
			  
    //ADC1_ClearFlag(ADC1_FLAG_AWS3);
    ADC1_Cmd(ENABLE);
	
}