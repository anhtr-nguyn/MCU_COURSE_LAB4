/*
 * scheduler.h
 *
 *  Created on: Nov 20, 2023
 *      Author: TrongAnh
 */

#ifndef INC_SCHEDULER_H_
#define INC_SCHEDULER_H_

#include <stdint.h>

#define MAX_TASK 5


void SCH_Init(void);
void SCH_Update(void);
void SCH_Dispatch(void);
void SCH_Add(void (*pFunction)(), int DELAY, int PERIOD);
void SCH_Delete(uint32_t TASK_ID);



#endif /* INC_SCHEDULER_H_ */
