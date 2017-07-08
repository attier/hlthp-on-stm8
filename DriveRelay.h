#ifndef __DRIVERELAY_H_
#define __DRIVERELAY_H_
#include "include.h"
void DriveRelay(void);
typedef struct IOPNP
{
GPIO_TypeDef* PORT;
GPIO_Pin_TypeDef PIN;
}IO_TypeDef;

extern IO_TypeDef o_COMP;       
extern IO_TypeDef o_PUMP;        
extern IO_TypeDef o_4WAY;     
extern IO_TypeDef o_HFAN; 
extern IO_TypeDef o_LED1; 
extern IO_TypeDef o_LED2;
extern IO_TypeDef o_LED3;

extern IO_TypeDef i_HiP; 

extern IO_TypeDef i_LoP; 


extern IO_TypeDef i_S;


//extern void IO_Init(IO_TypeDef x); 
extern void SET_BIT(IO_TypeDef p);
extern void CLR_BIT(IO_TypeDef p);
#endif
