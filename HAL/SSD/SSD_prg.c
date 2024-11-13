/*
 * SSD_prg.c
 *
 *  Created on: May 30, 2022
 *      Author: Mohamed Mamdoh
 */
#include "../../LIB/STD_TYPES.h"
#include "../../MCAL/DIO/DIO_int.h"

#include "SSD_int.h"

#define SSD1_PORT	DIO_PORTD
#define SSD2_PORT	DIO_PORTD

#define SSD1EN_PORT DIO_PORTA
#define SSD1EN_PIN	DIO_PIN0

#define SSD2EN_PORT DIO_PORTA
#define SSD2EN_PIN	DIO_PIN1

static u8 G_u8SsdDecToSeg[10] = {
		0b00111111,   /* 0 */
		0b00000110,   /* 1 */
		0b01011011,   /* 2 */
		0b01001111,   /* 3 */
		0b01100110,   /* 4 */
		0b01101101,   /* 5 */
		0b01111101,   /* 6 */
		0b00000111,   /* 7 */
		0b01111111,   /* 8 */
		0b01101111    /* 9 */
};

void HSSD_vInit(u8 A_u8SsdId){
	switch (A_u8SsdId){
		case SSD1_ID:
			MDIO_vSetPortDir(SSD1_PORT, 0xFF);
			MDIO_vWrtPinDir(SSD1EN_PORT, SSD1EN_PIN, DIO_OUTPUT);
			break;
		case SSD2_ID:
			MDIO_vSetPortDir(SSD2_PORT, 0xFF);
			MDIO_vWrtPinDir(SSD2EN_PORT, SSD2EN_PIN, DIO_OUTPUT);
			break;
	}
}

#define COMMON_ANODE  1
#define COMMON_CATHOD 2

#define SSD_TYPE COMMON_CATHOD

void HSSD_vTurnOff(u8 A_u8SsdId){
	/* Common anode will be set to DIO_LOW instead of DIO_HIGH */
#if SSD_TYPE == COMMON_CATHOD
	switch (A_u8SsdId){
		case SSD1_ID:MDIO_vWrtPinVal(SSD1EN_PORT, SSD1EN_PIN, DIO_HIGH); break;
		case SSD2_ID:MDIO_vWrtPinVal(SSD2EN_PORT, SSD2EN_PIN, DIO_HIGH); break;
	}
#else
	switch (A_u8SsdId){
	case SSD1_ID:MDIO_vWrtPinVal(SSD1EN_PORT, SSD1EN_PIN, DIO_LOW); break;
	case SSD2_ID:MDIO_vWrtPinVal(SSD2EN_PORT, SSD2EN_PIN, DIO_LOW); break;
	}
#endif
}

void HSSD_vDispNum(u8 A_u8SsdId, u8 A_u8Num){
	/* Common anode will be set to ~G_u8SsdDecToSeg[A_u8Num] instead of G_u8SsdDecToSeg[A_u8Num]*/
#if SSD_TYPE == COMMON_CATHOD
	switch (A_u8SsdId){
		case SSD1_ID:
			MDIO_vWrtPinVal(SSD1EN_PORT, SSD1EN_PIN, DIO_LOW);
			MDIO_vWrtPortVal(SSD1_PORT, G_u8SsdDecToSeg[A_u8Num]);
			break;
		case SSD2_ID:
			MDIO_vWrtPinVal(SSD2EN_PORT, SSD2EN_PIN, DIO_LOW);
			MDIO_vWrtPortVal(SSD2_PORT, G_u8SsdDecToSeg[A_u8Num]);
			break;
	}
#else
	switch (A_u8SsdId){
		case SSD1_ID:
			MDIO_vWrtPinVal(SSD1EN_PORT, SSD1EN_PIN, DIO_HIGH);
			MDIO_vWrtPortVal(SSD1_PORT, ~G_u8SsdDecToSeg[A_u8Num]);
			break;
		case SSD2_ID:
			MDIO_vWrtPinVal(SSD2EN_PORT, SSD2EN_PIN, DIO_HIGH);
			MDIO_vWrtPortVal(SSD2_PORT, ~G_u8SsdDecToSeg[A_u8Num]);
			break;
	}
#endif
}

