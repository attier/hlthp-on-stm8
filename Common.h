/*
FileName:common file
Author:
Data:2015
Version:V1.0
Description:
Function:
History:
*/
#ifndef _COMMON_H_
#define _COMMON_H_

#define ON 1
#define OFF 0
#define TURE 1
#define FALSE 0
#define uchar unsigned char
#define uint  unsigned int
#define NOP  (__no_operation())
#define DI  (__disable_interrupt())
#define EI (__enable_interrupt())

enum {NoWork,WorkHW,WorkH,WorkC};
 union JudgeFlag{
      struct {
      uchar Interrupt:1;
      uchar Debug:1;
      uchar Working:3;
      uchar SwOnOff:1;
      uchar AutoMode:1;
      uchar EVW:1;
      uchar EVH:1;
      uchar EVC:1;
      uchar Defog:1;
      uchar Defoging:1;
      uchar DefogStop:1;
             };uint All;
            };
extern union JudgeFlag Judge;
union ErrFlag{
      struct {
      uchar TW:1;
      uchar TH:1;
      uchar TC:1;
      uchar TI:1;
      uchar TIP:1;
      uchar TUP:1;
      uchar TE:1;
      uchar TCP:1;
      uchar E7:1;
      uchar E6:1;
      uchar E5:1;
      uchar E4:1;//??α???
      uchar E3:1;
      uchar E2:1;
      uchar E1:1;
      uchar E0:1;//ͨ????
      uchar P7:1;//???????
      uchar P6:1;//???????
      uchar P5:1;//??????
      uchar P4:1;//??????
      uchar P3:1;
      uchar P2:1;//????????
      uchar P1:1;//һ??????
      uchar P0:1;
             };uint All;
            };
extern union ErrFlag SysErr;
union TimeCount{
      struct {
      // CountClk 
      uchar EVWRun:8;//150
      uchar EVHRun:8;//150
      uchar EVCRun:8;//150
      uchar PumpRun:5;//30
      uint  PumpStop:9;//360
      uchar ComRun:7;//120
      uchar ComStop:8;//180
      uchar WtOff:4;//10
      uchar HpOff:4;//10
      uchar DefogStop:4;//30
      uint  Defoging:16;//4800
      // CountMin          
      uchar HWRun:6;//40
      uchar HRun:6;//40
      uchar CRun:6;//40
      uchar E7:5;//30
      uchar E6:5;//30
      uchar E5:5;//30
      uchar DefogScan:6;//40
      uchar HTScan:4;//15
             };uchar All;
            };
extern union TimeCount TM;
union RelayFlag1{
      struct {
      uchar Com:1;
      uchar Pump:1;
      uchar Fan:1;
      uchar Fway:1;
             };uchar All;
            };
extern union RelayFlag1 RelayS;
union RelayFlag2{
      struct {
      uchar EVW:1;
      uchar EVH:1;
      uchar EVC:1;
      uchar HTW:1;
      uchar HTH:1;
      uchar HTS:1;
      uchar Pump:1;
             };uchar All;
            };
extern union RelayFlag2 RelayEx;
union SWFlag{
      struct {
      uchar IP:1;
      uchar IWT:1;
      uchar IH:1;
      uchar IC:1;
      uchar IHP:1;
      uchar I6:1;
      uchar I7:1;
      uchar I8:1;
      uchar I9:1;
      uchar I10:1;
      uchar I11:1;
             };uint All;
            };
extern union SWFlag SW;
enum {E,CP,UP,W,XIX,XUX,XCX,CS};
//????????????????ܣ???ˮ???XX,XX,XX,???????ˮ??         
extern int T[8];  //RoomTemp??ipeTime?ļ?

#endif