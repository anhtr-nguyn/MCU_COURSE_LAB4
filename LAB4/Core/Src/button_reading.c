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
	int long_press;
	int timePress;
};

struct button button1 = {RELEASE, RELEASE, RELEASE, RELEASE, 0, 0, KEY_PRESS_TIME};


void getKey1(){
	button1.keyget1 = button1.keyget2;
	button1.keyget2 = button1.keyget3;
	button1.keyget3 = HAL_GPIO_ReadPin(BUTTON_1_GPIO_Port, BUTTON_1_Pin);
	if(button1.keyget1 == button1.keyget2 && button1.keyget2 == button1.keyget3){

	}
}


int isButton1Press(){
	return button1.flag;
}

void getButtonValue(){
	getKey1();
}
