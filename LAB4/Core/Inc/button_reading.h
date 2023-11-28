/*
 * button_reading.h
 *
 *  Created on: Nov 28, 2023
 *      Author: TrongAnh
 */

#ifndef INC_BUTTON_READING_H_
#define INC_BUTTON_READING_H_

#define PRESSED	0
#define RELEASE	1

#define KEY_PRESS_TIME	1000
#define TIME_CYCLE		10
void getButtonValue();

int isButton1Press();


#endif /* INC_BUTTON_READING_H_ */
