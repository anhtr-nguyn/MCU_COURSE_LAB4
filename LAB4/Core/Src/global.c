/*
 * global.c
 *
 *  Created on: Nov 20, 2023
 *      Author: TrongAnh
 */


#include "global.h"
#include "main.h"
//5 LED
//5 Delay (cycle khac nhau)
/*
 * LED1 one shot (delay tu chon) -> Task Delete
 * 4LEDs with different cycle
 * */

void led1()
{
	HAL_GPIO_TogglePin(GPIOA, LED_1_Pin);
}

void led2()
{
	HAL_GPIO_TogglePin(GPIOA, LED_2_Pin);
}

void led3()
{
	HAL_GPIO_TogglePin(GPIOA, LED_3_Pin);
}

void led4()
{
	HAL_GPIO_TogglePin(GPIOA, LED_4_Pin);
}

void led5()
{
	HAL_GPIO_TogglePin(GPIOA, LED_5_Pin);
}

