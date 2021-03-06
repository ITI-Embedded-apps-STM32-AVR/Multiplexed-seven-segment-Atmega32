#include "STD_TYPES.h"
#include "BIT_MATH.h"
#include "DIO_interface.h"
#include "SevenSeg_config.h"
#include "SevenSeg_interface.h"
#include "SevenSeg_private.h"

u8 LastNumber=SEVENSEG_INTIAL_VALUE;
u8 SEVENSEG_Enable_Ports[2]={SEVENSEG_Enable_one_PORT,SEVENSEG_Enable_Two_PORT};
u8 SEVENSEG_Enable_PINs[2]={SEVENSEG_Enable_one_PIN,SEVENSEG_Enable_Two_PIN};
u8 counter;

void SEVENSEG_SetNumber(u8 Number)
{
	u8 SEVENSEG_Number[]={
			0b00111111,
			0b00000110,
			0b01011011,
			0b01001111,
			0b01100110,
			0b01101101,
			0b01111101,
			0b00000111,
			0b01111111,
			0b01101111,
			/*adding snake*/
			0b00000001, //10
			0b00000010, //11
			0b00000100, //12
			0b00001000, //13
			0b00010000, //14
			0b00100000, //15
			0b01000000, //16

	};
	#if SEVENSEG_MODE ==1
		SetPinValue(SEVENSEG_PIN_A_PORT,SEVENSEG_PIN_A_NUMBER,GET_BIT(SEVENSEG_Number[Number],0));
		SetPinValue(SEVENSEG_PIN_B_PORT,SEVENSEG_PIN_B_NUMBER,GET_BIT(SEVENSEG_Number[Number],1));
		SetPinValue(SEVENSEG_PIN_C_PORT,SEVENSEG_PIN_C_NUMBER,GET_BIT(SEVENSEG_Number[Number],2));
		SetPinValue(SEVENSEG_PIN_D_PORT,SEVENSEG_PIN_D_NUMBER,GET_BIT(SEVENSEG_Number[Number],3));
		SetPinValue(SEVENSEG_PIN_E_PORT,SEVENSEG_PIN_E_NUMBER,GET_BIT(SEVENSEG_Number[Number],4));
		SetPinValue(SEVENSEG_PIN_F_PORT,SEVENSEG_PIN_F_NUMBER,GET_BIT(SEVENSEG_Number[Number],5));
		SetPinValue(SEVENSEG_PIN_G_PORT,SEVENSEG_PIN_G_NUMBER,GET_BIT(SEVENSEG_Number[Number],6));
		//SetPinValue(SEVENSEG_PIN_H_PORT,SEVENSEG_PIN_H_NUMBER,GET_BIT(SEVENSEG_Number[Number],7));
	#elif SEVENSEG_MODE ==0
		SetPinValue(SEVENSEG_PIN_A_PORT,SEVENSEG_PIN_A_NUMBER,GET_BIT(SEVENSEG_Number[Number],0)^0x01);
		SetPinValue(SEVENSEG_PIN_B_PORT,SEVENSEG_PIN_B_NUMBER,GET_BIT(SEVENSEG_Number[Number],1)^0x01);
		SetPinValue(SEVENSEG_PIN_C_PORT,SEVENSEG_PIN_C_NUMBER,GET_BIT(SEVENSEG_Number[Number],2)^0x01);
		SetPinValue(SEVENSEG_PIN_D_PORT,SEVENSEG_PIN_D_NUMBER,GET_BIT(SEVENSEG_Number[Number],3)^0x01);
		SetPinValue(SEVENSEG_PIN_E_PORT,SEVENSEG_PIN_E_NUMBER,GET_BIT(SEVENSEG_Number[Number],4)^0x01);
		SetPinValue(SEVENSEG_PIN_F_PORT,SEVENSEG_PIN_F_NUMBER,GET_BIT(SEVENSEG_Number[Number],5)^0x01);
		SetPinValue(SEVENSEG_PIN_G_PORT,SEVENSEG_PIN_G_NUMBER,GET_BIT(SEVENSEG_Number[Number],6)^0x01);
		//SetPinValue(SEVENSEG_PIN_H_PORT,SEVENSEG_PIN_H_NUMBER,GET_BIT(SEVENSEG_Number[Number],7)^0x01);
	#endif	
	LastNumber=Number;
}
/*void SEVENSEG_Enable(void)
{
	#if SEVENSEG_MODE ==1
		SetPinValue(SEVENSEG_Enable_PORT,SEVENSEG_Enable_PIN,0);
	#elif SEVENSEG_MODE ==0
		SetPinValue(SEVENSEG_Enable_PORT,SEVENSEG_Enable_PIN,1);
	#endif	
	SEVENSEG_SetNumber(LastNumber);
}*/

void SEVENSEG_Disable(u8 SEVENSEG_Num)
{
#if SEVENSEG_MODE ==1
		SetPinValue(SEVENSEG_Enable_Ports[SEVENSEG_Num],SEVENSEG_Enable_PINs[SEVENSEG_Num],1);
	#elif SEVENSEG_MODE ==0
		SetPinValue(SEVENSEG_Enable_Ports[SEVENSEG_Num],SEVENSEG_Enable_PINs[SEVENSEG_Num],0);
	#endif	
	SEVENSEG_SetNumber(LastNumber);
	
}
void SEVENSEG_Enable(u8 SEVENSEG_Num)
{
	#if SEVENSEG_MODE ==1
		SetPinValue(SEVENSEG_Enable_Ports[SEVENSEG_Num],SEVENSEG_Enable_PINs[SEVENSEG_Num],0);
	#elif SEVENSEG_MODE ==0
		SetPinValue(SEVENSEG_Enable_Ports[SEVENSEG_Num],SEVENSEG_Enable_PINs[SEVENSEG_Num],1);
	#endif	
	SEVENSEG_SetNumber(LastNumber);	
}
