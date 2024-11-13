/*
 * SSD_int.h
 *
 *  Created on: May 30, 2022
 *      Author: Mohamed Mamdoh
 */

#ifndef HAL_SSD_SSD_INT_H_
#define HAL_SSD_SSD_INT_H_

#define SSD1_ID 1
#define SSD2_ID 2

void HSSD_vInit(u8 A_u8SsdId);

void HSSD_vDispNum(u8 A_u8SsdId, u8 A_u8Num);

void HSSD_vTurnOff(u8 A_u8SsdId);

#endif /* HAL_SSD_SSD_INT_H_ */
