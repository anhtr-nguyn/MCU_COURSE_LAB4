/*
 * my_scheduler.h
 *
 *  Created on: Nov 26, 2023
 *      Author: TrongAnh
 */

#ifndef INC_MY_SCHEDULER_H_
#define INC_MY_SCHEDULER_H_

#include <stdint.h>

#define MAX_TASK	7


void SCH_Init(void);

void SCH_Update(void);
void SCH_Dispatch_Tasks(void);

uint32_t SCH_Add_Task(void (* pFunction)(), uint32_t DELAY, uint32_t PERIOD);
uint8_t SCH_Delete_Task(uint32_t taskID);


#endif /* INC_MY_SCHEDULER_H_ */
