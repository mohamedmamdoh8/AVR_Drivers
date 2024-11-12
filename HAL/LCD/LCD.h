/*
 * LCD.h
 *
 *  Created on: May 19, 2022
 *      Author: Mohamed Mamdoh
 */

#ifndef HAL_LCD_LCD_H_
#define HAL_LCD_LCD_H_

#define OUTPUT_PORT     255
#define LCD_PortData    DIO_PORTC
#define LCD_PortCtr     DIO_PORTB

#define LCD_RS          DIO_PIN0
#define LCD_RW          DIO_PIN1
#define LCD_E           DIO_PIN2

#define MAX_IDX_OF_ROWS 1
#define MAX_IDX_OF_COL  15
#define FIRST_ROW_IDX   0
#define FIRST_ROW_START 0x00
#define SEC_ROW_START   0x40
#define SET_AC_MASK     0x80

void HLCD_voidsendcom(u8 A_command);

void HLCD_voidsenddata(u8 A_data);

void HLCD_voidinit(void);

void HLCD_voidsendstrings(/*u8*/);

void HLCD_voidsendstring(u8 *PA_U8string);

void HLCD_voidWriteCGRAM ( u8 A_u8PatternIdx, u8 *A_u8PatternValue);

#endif /* HAL_LCD_LCD_H_ */
