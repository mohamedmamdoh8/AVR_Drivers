/*
 * DC_prg.c
 *
 *  Created on: May 28, 2022
 *      Author: Mohamed Mamdoh
 */
#include <util/delay.h>
#include "../../LIB/STD_TYPES.h"
#include "../../LIB/BIT_MATH.h"
#include "../../MCAL/DIO/DIO_int.h"

void HDC_vInit(void){
	 MDIO_vWrtPinDir(DIO_DDRA , DIO_PIN0 , DIO_OUTPUT);
	 MDIO_vWrtPinDir(DIO_DDRA , DIO_PIN1 , DIO_OUTPUT);
}
void HDC_vRoCw (void){
	 MDIO_vWrtPinVal(DIO_PORTA, DIO_PIN1, DIO_LOW);
	 MDIO_vWrtPinVal(DIO_PORTA, DIO_PIN0, DIO_HIGH);
}
void HDC_vRoCcw(void){
	 MDIO_vWrtPinVal(DIO_PORTA, DIO_PIN0, DIO_LOW);
	 MDIO_vWrtPinVal(DIO_PORTA, DIO_PIN1, DIO_HIGH);
}
void HDC_vStop (void){
	 MDIO_vWrtPinVal(DIO_PORTA, DIO_PIN0, DIO_LOW);
	 MDIO_vWrtPinVal(DIO_PORTA, DIO_PIN1, DIO_LOW);
}


