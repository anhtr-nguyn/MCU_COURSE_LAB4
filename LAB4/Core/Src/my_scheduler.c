/*
 * my_scheduler.c
 *
 *  Created on: Nov 28, 2023
 *      Author: TrongAnh
 */


#include "my_scheduler.h"

typedef struct {
	void (*pTask)();
	int Delay;
	int Period;
	int Runme;
	int ID; // still don't use currently, may be useful in the future
}sTask;

sTask listTask[MAX_TASK];

void SCH_Init(void){
	for (int i = 0; i < MAX_TASK; i++){
//		listTask[i].pTask = 0x0000;
		listTask[i].ID = -1;
		listTask[i].Delay = 0;
		listTask[i].Period = 0;
		listTask[i].Runme = 0;
	}
}


void SCH_Update(void){
	if (listTask[0].pTask != 0 && listTask[0].Runme > 0){
		if(listTask[0].Delay){
			listTask[0].Delay -= 1;
		}
		else{
			listTask[0].Runme +=1;
		}
	}
}

void SCH_Dispatch_Tasks(void){
	for (int i = 0; i < MAX_TASK; i++){
		if(listTask[i].ID != -1 && listTask[i].Runme > 0){
			(*listTask[i].pTask)();
			listTask[i].Runme--;
			if(listTask[i].Runme == 0 && listTask[i].Period == 0){
				SCH_Delete(listTask[i].ID);
			}
		}
	}
}

uint32_t SCH_Add_Task(void (* pFunction)(), uint32_t DELAY, uint32_t PERIOD){
	static unsigned int GLOBAL_ID = 0;
	int done = 0;
	uint32_t Return_val = -1;
	for (int i = 0; i < MAX_TASK && !done; i++){
		if (listTask[i].ID == -1){
			listTask[i].pTask = pFunction;
			listTask[i].Delay = DELAY;
			listTask[i].Period = PERIOD;
			listTask[i].Runme = 0;
			listTask[i].ID = GLOBAL_ID++;
			done = 1;
			Return_val = listTask[i].ID;
		}
	}
	return Return_val;
}

uint8_t SCH_Delete_Task(uint32_t taskID){
	int done = 0;
	uint8_t Return_val = 0;
	for (int i = 0; i < MAX_TASK && !done; i++){
		if(listTask[i].ID == taskID){
			listTask[i].ID = -1;
			done = 1;
			Return_val = 1;
		}
	}
	return Return_val;
}
