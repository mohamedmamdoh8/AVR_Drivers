/*
 * KPD_prg.c
 *
 *  Created on: May 25, 2022
 *      Author: Mohamed Mamdoh
 */
#include <util/delay.h>
#include "../../LIB/STD_TYPES.h"
#include "../../LIB/BIT_MATH.h"

#include "../../MCAL/DIO/DIO_int.h"

#include "KPD_int.h"

#define KPD_PORT    DIO_PORTC	  /* Keypad HW Connection */

#define COL_START   DIO_PIN0      /* First Column is PIN0 */
#define COL_END     DIO_PIN3      /* Last  Column is PIN3 */
#define ROW_START   DIO_PIN4      /* First Row    is PIN4 */
#define ROW_END     DIO_PIN7      /* Last  Row    is PIN7 */

#define ROW_SIZE 4
#define COL_SIZE 4

static const u8 global_Au8_SwitchVal[ROW_SIZE][COL_SIZE] =
{
	{
		0x07, /* Row 0 Column 0 */
		0x04, /* Row 1 Column 0 */
		0x01, /* Row 2 Column 0 */
		0x0A  /* Row 3 Column 0 */
	},
	{
		0x08, /* Row 0 Column 1 */
		0x05, /* Row 1 Column 1 */
		0x02, /* Row 2 Column 1 */
		0x00  /* Row 4 Column 1 */
	},
	{
		0x09, /* Row 0 Column 2 */
		0x06, /* Row 1 Column 2 */
		0x03, /* Row 2 Column 2 */
		0x0B  /* Row 3 Column 2 */
	},
	{
		0x01, /* Row 0 Column 3 */
		0x05, /* Row 1 Column 3 */
		0x09, /* Row 2 Column 3 */
		0x0D  /* Row 3 Column 3 */
	}
};

void HKPD_vInit(){
	/* Set Columns as Output & High */
	for (u8 local_u8_PinID = COL_START; local_u8_PinID <= COL_END; local_u8_PinID++) {
		MDIO_vWrtPinDir(KPD_PORT, local_u8_PinID, DIO_OUTPUT);
		MDIO_vWrtPinVal(KPD_PORT, local_u8_PinID, DIO_HIGH);
	}
	/* Set Rows as Inputs & Pulled up */
	for (u8 local_u8_PinID = ROW_START; local_u8_PinID <= ROW_END; local_u8_PinID++) {
		MDIO_vWrtPinDir(KPD_PORT, local_u8_PinID, DIO_INPUT);
		MDIO_vWrtPinVal(KPD_PORT, local_u8_PinID, DIO_HIGH);
	}
}

u8 HKPD_u8GetPressedKey(){
	u8 local_u8_Column, local_u8_Row, local_u8_PinVal;

	/* A- Initialize the switch status to NOT Pressed as a default value */
	u8 local_u8_PressedKey = KPD_NOT_PRESSED;

	/* B- Looping on columns of the Key Pad */
	for (local_u8_Column = COL_START; local_u8_Column <= COL_END; local_u8_Column++) {
		/* 1- Activate the Column */
		MDIO_vWrtPinVal(KPD_PORT, local_u8_Column, DIO_LOW);

		/* 2- Loop on the rows of the Key Pad */
		for (local_u8_Row = ROW_START; local_u8_Row <= ROW_END; local_u8_Row++) {
			/* Check the status of the switch */
			local_u8_PinVal = MDIO_u8GetPinVal(KPD_PORT, local_u8_Row);
			if (local_u8_PinVal == 0) {
				/* a- Get the value of the currently pressed switch */
				local_u8_PressedKey = global_Au8_SwitchVal[local_u8_Column - COL_START][local_u8_Row - ROW_START];

				/* b- Wait until the switch is released (Single Press) */
				while (local_u8_PinVal == 0) {
					local_u8_PinVal = MDIO_u8GetPinVal(KPD_PORT, local_u8_Row);
				}

				/* c- Delay to avoid bouncing */
				_delay_ms(20);
			}
		}

		/* 3- Deactivate the Column */
		MDIO_vWrtPinVal(KPD_PORT, local_u8_Column, DIO_HIGH);
	}

	/* C- Returning the value */
	return local_u8_PressedKey;
}

