/*
 * Pb_int.h
 *
 *  Created on: May 25, 2022
 *      Author: Mohamed Mamdoh
 */

#ifndef HAL_BTN_BTN_INT_H_
#define HAL_BTN_BTN_INT_H_


#include "Pb_private.h"
#include "Pb_conf.h"


/*
	Function Name        : HPushBotton_voidPbInt
	Function Returns     : void
	Function Arguments   : u8 A_u8PbID
	Function Description : Define the PushBotton as INTPUT
*/
void HPushBotton_voidPbInt (u8 A_u8PbID) ;


/*
	Function Name        : HPushBotton_u8PbStatus
	Function Returns     : u8
	Function Arguments   : u8 A_u8PbID
	Function Description : read the status of push button (Pressed / not pressed)
*/
u8 HPushBotton_u8PbStatus (u8 A_u8PbID) ;

#endif /* HAL_BTN_BTN_INT_H_ */
