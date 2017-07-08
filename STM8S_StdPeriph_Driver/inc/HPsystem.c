#include "HPSystem.h"
//#include "HPProtect.h"
//#include "HPNeed.h"
//#include "HPInUnit.h"
//#include "HPOuUnit.h"


void HPstart(void)
{
  if(GPIO_ReadInputPin(GPIOC, GPIO_PIN_5)&&(T[3]<=63))
  {
      //RelayS.Pump=1;
     // TM.PumpRun=1;
  if(SysErr.P6)
    Judge.Working=NoWork;
    else if(T[3]<=59) Judge.Working=WorkH;
  }
  else  {Judge.Working=NoWork;}
  }
  
  


void delay(int x)
{
  for(int w=0;w<=x;w++)
    for(int t=0;t<100;t++)
asm("nop"); 
}

void HPOuUnit(void)
{
if (Judge.Working==NoWork)
     {HPShut();}
     else if (Judge.Working)
     {
          //除霜过程
          if (Judge.Defog)
          {
             //除霜结束
             if (Judge.DefogStop)
             {
                 if (TM.DefogStop>=30)
                 {
                     Judge.DefogStop=0;Judge.Defog=0;
                     TM.DefogStop=0;RelayS.Com=1;
                 }
                 else if (TM.DefogStop>=25)
                 {RelayS.Fway=0;} 
                 else {RelayS.Com=0;RelayS.Fan=1;}
             }
             //除霜判断结束
             else if (TM.Defoging>1200)
             {Judge.DefogStop=1;TM.DefogStop=1;}
             else if ((TM.Defoging>120)&&(T[UP]>10))
             {Judge.DefogStop=1;TM.DefogStop=1;}
             //除霜开始
             else if (TM.Defoging>60)
             {//RelayS.Fway=1;
              RelayS.Com=1;}
             else if (TM.Defoging>30)
             {RelayS.Fway=1;}
             else {RelayS.Com=0;RelayS.Fan=0;}
         }
         //正常制热非除霜
          else if((TM.ComStop>=180)||(!TM.ComStop))
         {
             RelayS.Fway=0;
             if (TM.DefogScan>=40)
             {
                 if ((T[UP]<0)&&(T[E]<4))//后期再改
                 {Judge.Defog=1;TM.Defoging=1;}
             }
             else if (TM.PumpRun>=30)
             {
                RelayS.Com=1;
                if(!TM.ComRun)
                    TM.ComRun=1;
                TM.ComStop=0;
                if(!TM.DefogScan) 
                  TM.DefogScan=1;
             }
             else if (TM.PumpRun>=25)
             {RelayS.Fan=1;}
             else 
             {
                  RelayS.Pump=1;
                  TM.PumpStop=0;
                  if (!TM.PumpRun)
                  {TM.PumpRun=1;}
             }
         }
    }
}
void HPShut(void)
{
     if (TM.PumpStop>=359)
     {
       //循环保温
       if (T[E]>1)
        {TM.PumpStop=1;RelayS.Pump=0;}
        else
        {
           RelayS.Pump=1;
           if (!TM.PumpRun)
           {TM.PumpRun=1;}
           else if (TM.PumpRun>=30)
           {TM.PumpRun=0;TM.PumpStop=1;
           RelayS.Pump=0;}
        }
     }
     else if(TM.ComRun>=120)
     {
       // RelayEx.HTS=0;RelayEx.HTH=0;
       // RelayEx.HTW=0;
       RelayS.Com=0;TM.ComRun=0;
       TM.DefogScan=0;
        if (!TM.ComStop)
        {TM.ComStop=1;}
        //else if (TM.ComStop>=20)
     }
        
     
      else if (TM.ComStop>=35||(TM.ComRun==0&&TM.ComStop==0)) // delay 35S;
       {  RelayS.Pump=0;TM.PumpRun=0;
             if (!TM.PumpStop)
             {TM.PumpStop=1;}
             if (TM.ComStop>=40||(TM.ComRun==0&&TM.ComStop==0))
               {
                RelayS.Fan=0;
                }
       }
     }


void HPSystem(void)
{
    // HPProtect();
    // HPNeed()；
    // HPInUnit();
     HPstart();
     HPOuUnit();
     
}