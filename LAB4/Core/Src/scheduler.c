/*
 * scheduler.c
 *
 *  Created on: Nov 20, 2023
 *      Author: TrongAnh
 */

#include "scheduler.h"


typedef struct {
	void (*pTask)();
	int Delay;
	int Period;
	int Runme;
	int TaskID;
}sTask;
sTask listTask[MAX_TASK];



void Timer_init(){

}
//void Watchdog_init();

void SCH_Init(void){
	for (int i = 0; i < MAX_TASK; i++){
		listTask[i].TaskID = -1;
	}
//	Timer_init();
}


void SCH_Update(void){
	for (int i = 0; i < MAX_TASK; i++){
		if (listTask[i].TaskID  != -1){
			if(listTask[i].Delay == 0){
				listTask[i].Runme++;
				listTask[i].Delay = listTask[i].Period;
			}
			else{
				listTask[i].Delay--;
			}
		}
	}
}

void SCH_Add(void (*pFunction)(), int DELAY, int PERIOD){
	int i = 0;
	int done = 0;
	static int ID = 0;
	for (i = 0; i < MAX_TASK && !done; i++){
		if (listTask[i].TaskID == -1){
			listTask[i].pTask = pFunction;
			listTask[i].Delay = DELAY;
			listTask[i].Period = PERIOD;
			listTask[i].Runme = 0;
			listTask[i].TaskID = ID++;
			done = 1;
		}
	}
}


void SCH_Dispatch(void){
	int i;
	for (i = 0; i < MAX_TASK; i++){
		if (listTask[i].Runme > 0){
			(*listTask[i].pTask)();
			listTask[i].Runme--;
			if (listTask[i].Period == 0){
				SCH_Delete(listTask[i].TaskID);
			}
		}
	}
}

void SCH_Delete(uint32_t TASK_ID){
	if (listTask[TASK_ID].TaskID == TASK_ID){
		listTask[TASK_ID].pTask = 0;
		listTask[TASK_ID].Delay = 0;
		listTask[TASK_ID].Period = 0;
		listTask[TASK_ID].Runme = 0;
		listTask[TASK_ID].TaskID = -1;
	}
}

