/*
 * global.c
 *
 *  Created on: Nov 20, 2023
 *      Author: TrongAnh
 */


#include "global.h"
#include "main.h"
#include "button_reading.h"


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

void led6(){
	HAL_GPIO_TogglePin(GPIOA, LED_6_Pin);
}
void test_input_output(){
	if(isButton1Press()){
		HAL_GPIO_TogglePin(LED_7_GPIO_Port, LED_7_Pin);
	}
}
