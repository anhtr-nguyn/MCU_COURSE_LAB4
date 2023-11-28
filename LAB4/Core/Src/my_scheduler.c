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
	for (int i = 0; i < MAX_TASK; i++){
		if (listTask[i].ID != -1){
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

void SCH_Dispatch(void){
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

void SCH_Add(void (*pFunction)(), int DELAY, int PERIOD){
	static unsigned int GLOBAL_ID = 0;
	int done = 0;
	for (int i = 0; i < MAX_TASK && !done; i++){
		if (listTask[i].ID == -1){
			listTask[i].pTask = pFunction;
			listTask[i].Delay = DELAY;
			listTask[i].Period = PERIOD;
			listTask[i].Runme = 0;
			listTask[i].ID = GLOBAL_ID++;
			done = 1;
		}
	}
}

void SCH_Delete(int ID){
	int done = 0;
	for (int i = 0; i < MAX_TASK && !done; i++){
		if(listTask[i].ID == ID){
			listTask[i].ID = -1;
			done = 1;
		}
	}
}
