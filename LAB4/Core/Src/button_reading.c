/*
 * button_reading.c
 *
 *  Created on: Nov 28, 2023
 *      Author: TrongAnh
 */

#include "button_reading.h"
#include "main.h"

struct button {
	int keyget1;
	int keyget2;
	int keyget3;
	int oldState;
	int flag;
	int timePress;
};

struct button button1 = {RELEASE, RELEASE, RELEASE, RELEASE, 0, KEY_PRESS_TIME};


void getKey1(){
	button1.keyget1 = button1.keyget2;
	button1.keyget2 = button1.keyget3;
	button1.keyget3 = HAL_GPIO_ReadPin(BUTTON_1_GPIO_Port, BUTTON_1_Pin);
	if (button1.keyget1 == button1.keyget2 && button1.keyget2 == button1.keyget3) {
			if (button1.oldState != button1.keyget3) {
				button1.oldState = button1.keyget3;
				if (button1.keyget3 == PRESSED) {
					button1.flag = 1;
					button1.timePress = KEY_PRESS_TIME/TIME_CYCLE;
				}
			}
			else if (button1.keyget3 == PRESSED){
				button1.timePress--;
				if (button1.timePress == 0) {
					button1.oldState = RELEASE;
				}
			}
		}
}


int isButton1Press(){
	if (button1.flag == 1){
		button1.flag = 0;
		return 1;
	}
	return 0;
}

void getButtonValue(){
	getKey1();
}
