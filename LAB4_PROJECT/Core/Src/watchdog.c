/*
 * watchdog.c
 *
 *  Created on: Nov 25, 2023
 *      Author: thao2
 */


#include "main.h"
#include "watchdog.h"

IWDG_HandleTypeDef hiwdg;
static uint32_t counter_for_watchdog = 0;

void Watchdog_Refresh(void){
	HAL_IWDG_Refresh(&hiwdg);
}

unsigned char Is_Watchdog_Reset(void){
	if(counter_for_watchdog > 3){
		return 1;
	}
	return 0;
}

void Watchdog_Counting(void){
	counter_for_watchdog++;
}

void Reset_Watchdog_Counting(void){
	counter_for_watchdog = 0;
}
