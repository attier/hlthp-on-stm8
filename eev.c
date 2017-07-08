#include "eev.h"
#include "stdio.h"
#include "math.h"

uchar delaytime;
void eevdriver(int x)
{uint8_t stepx=0;
if(x){
stepx=STEP[stepcount++];
GPIO_Write(GPIOD, stepx); 
if(stepcount==8)
	stepcount=0;
}
else 
{stepx=STEP[stepcount--];
GPIO_Write(GPIOD, stepx); 
if(stepcount==-1)
	stepcount=7;
}
}


void eevinit()
{int i=1;
  GPIO_Write(GPIOD, STEP[0]);
  delay16ms(25);
  while(i<250)
{eevdriver(1);
  i++;
    delay16ms(1);
}
while(i<560)
{eevdriver(0);
  i++;
    delay16ms(1);
}
GPIO_Write(GPIOD, STEP[stepcount]);
  delay16ms(25);
  i=0;
while(i<250)
{eevdriver(1);
  i++;
    delay16ms(1);
}
GPIO_Write(GPIOD, STEP[stepcount]);
  delay16ms(30);
GPIO_Write(GPIOD, 0x00);


}
void delay16ms(uchar time)
{
  delaytime=1;
  while(delaytime<(time+1));
    
 delaytime=0;  
  
}
void DriveEEV()
{
if((EEVSTEP>150)&&(EEVSTEP<400))
{ int x=T[7]-T[2]-5;
  if(x>0)
  {for(;x;x--)
    { eevdriver(1);
    delay16ms(1);}}
  else if(T[1]<105)
  {for(;x;x++)
    { eevdriver(0);
    delay16ms(1);}}
GPIO_Write(GPIOD, STEP[stepcount]);

delay16ms(30);
GPIO_Write(GPIOD, 0x00);
EEVSTEP+=x;
}
}