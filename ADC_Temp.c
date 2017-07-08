//******************************************************************************
//* FILE NAME: ADC_Temp.c
//*
//* DESCRIPTION: HP STM8 ADC
//*
//* ORIGINATOR: HHN
//*
//* DATE: 2015-12-12
//*
//******************************************************************************

#include "ADC_Temp.h"

//#include "stm8s_adc1.h"
//#include "tempc.c"
#define ADC_DIGITAL_MAX  1023    //2^10 - 1
#define ADC_VDD_X100     500    //5V * 100
#define ADC_MAX_BRI_VOLTS    500     //3.2V * 100
#define ADC_MIN_BRI_VOLTS      22   //0.08 * 100
 int  fkTempTab[]={ //22-252
-38,
-37,
-36,
-34,
-33,
-32,
-31,
-30,
-29,
-28,
-27,
-26,
-25,
-24,
-23,
-22,
-21,
-21,
-20,
-19,
-18,
-17,
-17,
-16,
-15,
-15,
-14,
-13,
-13,
-12,
-11,
-11,
-10,
-9,
-9,
-8,
-8,
-7,
-6,
-6,
-5,
-5,
-4,
-4,
-3,
-3,
-2,
-2,
-1,
-1,
0,
0,
1,
1,
2,
2,
3,
3,
4,
4,
5,
5,
6,
6,
7,
7,
8,
8,
8,
9,
9,
10,
10,
11,
11,
11,
12,
12,
13,
13,
14,
14,
14,
15,
15,
16,
16,
17,
17,
17,
18,
18,
19,
19,
19,
20,
20,
21,
21,
21,
22,
22,
23,
23,
23,
24,
24,
25,
25,
25,
26,
26,
27,
27,
27,
28,
28,
29,
29,
29,
30,
30,
31,
31,
31,
32,
32,
33,
33,
33,
34,
34,
35,
35,
36,
36,
36,
37,
37,
38,
38,
39,
39,
39,
40,
40,
41,
41,
42,
42,
42,
43,
43,
44,
44,
45,
45,
46,
46,
47,
47,
48,
48,
49,
49,
50,
50,
51,
51,
52,
52,
53,
53,
54,
54,
55,
55,
56,
56,
57,
58,
58,
59,
59,
60,
61,
61,
62,
63,
63,
64,
65,
65,
66,
67,
67,
68,
69,
70,
71,
71,
72,
73,
74,
75,
76,
77,
78,
79,
80,
81,
82,
83,
84,
86,
87,
88,
90,
91,
93,
94,
96,
98,
100,
102,
105,
107,
110,
113,
116,
121,
125,
131,
};

//int T[8]; //temp volt 
extern int T[8];
 
uint16_t ADC_Brightness = 0;

void ADC_Task(int temp)
{
    static uint16_t uwAdcSample = 0;
    
    //Start a conversion
    ADC1_StartConversion();
    //Wait until conversion finish
    while(!ADC1_GetFlagStatus(ADC1_FLAG_EOC));
    
    uwAdcSample = ADC1_GetConversionValue()  ;
    
    ADC1_ClearFlag(ADC1_FLAG_EOC);
     if(temp==1)
       {long temmmp;
     temmmp=uwAdcSample;
     
     uwAdcSample=(temmmp*10230/(9*temmmp+1023));
       T[temp]=fkTempTab[(int)(uwAdcSample/4-20)];
     }
   else
     T[temp]=fkTempTab[(int)(uwAdcSample/4-20)]; //load volt temp
    //Convert it to voltage * 100
    ADC_Brightness = (uint16_t)((uint32_t)uwAdcSample * (uint32_t)ADC_VDD_X100 / (uint32_t)ADC_DIGITAL_MAX);
   /* 
    if(ADC_Brightness < ADC_MIN_BRI_VOLTS)
    {
        ADC_Brightness = ADC_MIN_BRI_VOLTS;
    }   
    
    if(ADC_Brightness > ADC_MAX_BRI_VOLTS)
    {
        ADC_Brightness = ADC_MAX_BRI_VOLTS;
		
    }
    
	
    //Convert it to brightness
    ADC_Brightness = (ADC_Brightness * 100 ) / (ADC_MAX_BRI_VOLTS - ADC_MIN_BRI_VOLTS);
    
    if(ADC_Brightness > 100)
    {
        ADC_Brightness = 100;
    }
    
    ADC_Brightness = 100 - ADC_Brightness;
  */
}