#include "DriveTime.h"
#include "include.h"
uchar InterTimes=61;
uchar Clock   = 60;
uchar Minutes = 20;
extern union JudgeFlag Judge;
void CountClk(void)
{
     if (0<TM.EVHRun<150)   {TM.EVHRun++;}
     if (0<TM.EVCRun<150)   {TM.EVCRun++;}
     if (0<TM.EVWRun<150)   {TM.EVWRun++;}
     if ((0<TM.PumpRun)&&(TM.PumpRun<30))   {TM.PumpRun++;}
     if ((0<TM.PumpStop)&&(TM.PumpStop<360)) {TM.PumpStop++;}
     if ((0<TM.ComRun)&&(TM.ComRun<120))  {TM.ComRun++;}
     if ((0<TM.ComStop)&&(TM.ComStop<180))  {TM.ComStop++;}
     if (0<TM.WtOff<10)     {TM.WtOff++;}
     if (0<TM.HpOff<10)     {TM.HpOff++;}
     if ((0<TM.DefogStop)&&(TM.DefogStop<30)) {TM.DefogStop++;}
     if ((0<TM.Defoging)&&(TM.Defoging<4800)){TM.DefogStop++;}
}
void CountMin(void)
{
     if (0<TM.HWRun<40) {TM.HWRun++;}
     if (0<TM.HRun<40)  {TM.HWRun++;}
     if (0<TM.CRun<40)  {TM.HWRun++;}
     if (0<TM.E7<30)    {TM.E7++;}
     if (0<TM.E6<30)    {TM.E6++;}
     if (0<TM.E5<30)    {TM.E5++;}
     if (0<TM.HTScan<15){TM.HTScan++;}
     if ((0<TM.DefogScan)&&(TM.DefogScan<40)) {TM.DefogScan++;}
}
void DriveTime(void)
{
     if (Judge.Interrupt)
     {
        Judge.Interrupt=0;
        //InterTimes--;
        if(RelayS.Com&&(InterTimes==31))
	{
	    GPIO_WriteReverse(GPIOA, GPIO_PIN_3);
	   
        }
        else if(!RelayS.Com)GPIO_WriteHigh(GPIOA, GPIO_PIN_3);
        if(SysErr.P6)
	{
          if(InterTimes==30)
	{
	     GPIO_WriteReverse(GPIOA, GPIO_PIN_5);
        }   //i=0;
        }
        if (!InterTimes)
        {
          InterTimes=61;
           Clock--;
           GPIO_WriteReverse(GPIOA, GPIO_PIN_5);
           CountClk();//所有秒计时的变量非0时开始计时
         //   if(SysErr.P6)
  //  GPIO_WriteReverse(GPIOA, GPIO_PIN_4);
           
           if (!Clock)
           {
              Clock = 60;Minutes--;
              CountMin();//所有分计时的变量非0时开始计时
             //  CountClk();//所有秒计时的变量非0时开始计时
              if (!Minutes)
              {
                  Minutes = 60;   
                //   CountMin();//所有分计时的变量非0时开始计时
	      }
	    }
           else if(Clock==30)
           {  if(RelayS.Com)
             DriveEEV();}
	}
     }
}
