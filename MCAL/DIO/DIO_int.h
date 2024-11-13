/*
 * DIO_int.h
 *
 *  Created on: May 18, 2022
 *      Author: Mohamed Mamdoh
 */

#ifndef MCAL_DIO_DIO_INT_H_
#define MCAL_DIO_DIO_INT_H_

#define DIO_PORTA 0
#define DIO_PORTB 1
#define DIO_PORTC 2
#define DIO_PORTD 3

#define DIO_DDRA  0
#define DIO_DDRB  1
#define DIO_DDRC  2
#define DIO_DDRD  3

#define DIO_PIN0  0
#define DIO_PIN1  1
#define DIO_PIN2  2
#define DIO_PIN3  3
#define DIO_PIN4  4
#define DIO_PIN5  5
#define DIO_PIN6  6
#define DIO_PIN7  7

#define DIO_INPUT  0
#define DIO_OUTPUT 1

#define DIO_HIGH   1
#define DIO_LOW    0

/*#define PORTA   0x3B
#define PORTB   0X38
#define PORTC   0X35
#define PORTD   0X32
*/

void MDIO_vWrtPinDir(u8 A_u8PortNo, u8 A_u8PinNo, u8 A_u8PinDir);

void MDIO_vWrtPinVal(u8 A_u8PortNo, u8 A_u8PinNo, u8 A_u8PinVal);

u8 MDIO_u8GetPinVal(u8 A_u8PortNo, u8 A_u8PinNo);

void MDIO_vSetPortValue( u8 A_u8PortNo,u8 A_u8PortVal);

void MDIO_vSetPortDir( u8 A_u8PortNo,u8 A_u8PortVal);

void MDIO_vTogPinVal(u8 A_u8PortNo, u8 A_u8PinNo);

#endif /* MCAL_DIO_DIO_INT_H_ */
