/*
 * user_temp.c
 *
 *  Created on: 2018年11月17日
 *      Author: lenovo
 */

#include "user_common.h"
#include "esp_common.h"


UINT uiTempAdcValue = 0;


/*
	温度                                   电阻                             AD
 ----------------------------------
	-10   		44.12
	-9    		42.11
	-8    		40.21
	-7    		38.39
	-6    		36.67
	-5    		35.03
	-4   		33.48
	-3		    32   
	-2    		30.6 
	-1    		29.27
	 0    		28.01 
	 1    		26.82 
	 2    		25.69 
	 3    		24.62 
	 4   		23.61 
	 5    		22.65 
	 6    		21.75 
	 7    		20.89 
	 8    		20.07 
	 9    		19.29 
	10    		18.56
	11    		18.48
	12    		18.14
	13    		17.63
	14    		16.99
	15    		16.27
	16    		15.53
	17    		14.78
	18    		14.05
	19    		13.35
	20    		12.69
	21    		12.06
	22    		11.49
	23    		10.95
	24    		10.45
	25    		10   
	26    		9.57 
	27    		9.18 
	28    		8.81 
	29    		8.47 
	30    		8.16 
	31    		7.86 
	32    		7.57 
	33    		7.31 
	34    		7.05 
	35    		6.81 
	36    		6.58 
	37    		6.35 
	38    		6.14 
	39    		5.93 
	40    		5.73 
	41    		5.54 
	42    		5.35 
	43    		5.17 
	44    		4.99 
	45    		4.82 
	46    		4.66 
	47    		4.5  
	48    		4.35 
	49    		4.2  
	50    		4.06 
	51    		3.92 
	52    		3.79 
	53    		3.66 
	54    		3.53 
	55    		3.41 
	56    		3.29 
	57    		3.17 
	58   		3.05 
	59    		2.94 
	60    		2.82 
	61    		2.77 
	62    		2.71 
	63    		2.65 
	64    		2.58 
	65    		2.5  
	66    		2.43 
	67    		2.35 
	68    		2.28 
	69    		2.2  
	70    		2.13 
	71    		2.06 
	72   		2   
	73    		1.93 
	74    		1.87 
	75    		1.82 
	76    		1.76 
	77    		1.71 
	78    		1.67 
	79    		1.62 
	80    		1.58 



    R      AD
  ----- = -----
  R热 + R   1024

=>
       AD * R
 R热 = --------- - R
        1024
=>
 R = 1时

       1024
 R热  = -------  -  1
        AD


 */


VOID TEMP_TempCallBack( VOID )
{
	STATIC UINT uiLastAdc = 0;
	UINT uiCurAdc = 0;

	if ( uiLastAdc == 0 )
	{
		uiLastAdc = system_adc_read();
	}

	uiCurAdc = system_adc_read();
	uiTempAdcValue = ( uiLastAdc * 0.8 +  uiCurAdc * 0.2 );

	uiLastAdc = uiTempAdcValue;
}


float TEMP_GetTemperature( VOID )
{
	return (float)(1024.0 / uiTempAdcValue - 1);
}





