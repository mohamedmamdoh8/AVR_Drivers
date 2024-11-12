/*
 * LCD.c
 *
 *  Created on: May 20, 2022
 *      Author: Mohamed Mamdoh
 */
#include"../../LIB/STD_TYPES.h"
#include"../../LIB/BIT_MATH.h"
#include"../../MCAL/DIO/DIO_int.h"
#include <util/delay.h>
#include"LCD.h"
void HLCD_voidsendcom(u8 A_command) {

	/*select the RS*/
	 MDIO_vWrtPinVal(LCD_PortCtr,LCD_RS,DIO_LOW);
	/*select the RW*/
	 MDIO_vWrtPinVal(LCD_PortCtr,LCD_RW,DIO_LOW);
    /*SEND COMM*/
	 DIO_VoidSetPortValue( LCD_PortData,A_command);
	/*SELECT THE E*/
	 MDIO_vWrtPinVal(LCD_PortCtr,LCD_E,DIO_HIGH);
	/*DELAY*/
	_delay_ms(1);
	/*SELECT THE E*/
	 MDIO_vWrtPinVal(LCD_PortCtr,LCD_E,DIO_LOW);
	_delay_ms(1);
}
void HLCD_voidsenddata(u8 A_data){

	/*select the RS*/
	 MDIO_vWrtPinVal(LCD_PortCtr,LCD_RS,DIO_HIGH);
	/*select the RW*/
	 MDIO_vWrtPinVal(LCD_PortCtr,LCD_RW,DIO_LOW);
    /*SEND data*/
	 DIO_VoidSetPortValue(LCD_PortData ,A_data);
	/*SELECT THE E*/
	 MDIO_vWrtPinVal(LCD_PortCtr,LCD_E,DIO_HIGH);
	/*DELAY*/
	_delay_ms(1);
	/*SELECT THE E*/
	MDIO_vWrtPinVal(LCD_PortCtr,LCD_E,DIO_LOW);
	_delay_ms(1);
}
void HLCD_voidinit(void)
{
	DIO_VoidSetPortDir (LCD_PortData ,OUTPUT_PORT);
	MDIO_vWrtPinDir (LCD_PortCtr,LCD_RS,DIO_OUTPUT);
	MDIO_vWrtPinDir (LCD_PortCtr,LCD_RW,DIO_OUTPUT);
	MDIO_vWrtPinDir (LCD_PortCtr,LCD_E ,DIO_OUTPUT);
	/*Init 8 bit*/
_delay_ms(40);
HLCD_voidsendcom(0b00111000);//function set
_delay_ms(1);
HLCD_voidsendcom(0b00001111);//display
_delay_ms(1);
HLCD_voidsendcom(0b00000001);//clear
_delay_ms(2);
HLCD_voidsendcom(0b00000010);//entry mode
_delay_ms(15);
}
void HLCD_voidsendstring(u8 *PA_U8string)
{

	u8 Local_Counter=0;
	while(PA_U8string[Local_Counter]!='\0'){
		HLCD_voidsenddata(PA_U8string[Local_Counter]);
		Local_Counter++;
	}

}



