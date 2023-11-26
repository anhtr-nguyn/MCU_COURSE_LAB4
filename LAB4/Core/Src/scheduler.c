/*
 * scheduler.c
 *
 *  Created on: Nov 20, 2023
 *      Author: TrongAnh
 */

#include "scheduler.h"


pTask Proc[MAX_TASK];

void SCH_Init(){
	for (int i = 0; i < MAX_TASK; ++i){
		Proc[i].ID = -1;
	}
}

void SCH_Add(void(*pFunction), int delay, int period, int ID) {
	int done = 0;
	for (int i = 0; i < MAX_TASK && !done; ++i) {
		if (Proc[i].ID == -1) {
			Proc[i].Delay = delay;
			Proc[i].Function = pFunction;
			Proc[i].ID = ID;
			Proc[i].RunMe = 0;
			done = 1;
		}
	}
}

void SCH_Update() {
	for (int i = 0; i < MAX_TASK; ++i) {
		if (Proc[i].Delay > 0) {
			Proc[i].Delay--;
		}
		else {
			Proc[i].Delay = Proc[i].Period;
			Proc[i].RunMe++;
		}
	}
}

void SCH_Dispatch() {
	for (int i = 0; i < MAX_TASK; ++i) {
		if (Proc[i].ID != -1 && Proc[i].RunMe > 0) {
			Proc[i].Function();
			Proc[i].RunMe--;
			if(Proc[i].Period == 0){
				SCH_Delete(Proc[i].ID);
			}
		}
	}
}

void SCH_Delete(int ID) {
	int done = 0;
	for (int i = 0; i < MAX_TASK && !done; ++i) {
		if (Proc[i].ID == ID) {
			Proc[i].ID = -1;
			done = 1;
		}
	}
}
