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
void SCH_Dispatch(void);

void SCH_Add(void (*pFunction)(), int DELAY, int PERIOD);
void SCH_Delete(int ID);


#endif /* INC_MY_SCHEDULER_H_ */
