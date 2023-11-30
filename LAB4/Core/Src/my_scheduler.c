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
	int ID;
}sTask;

sTask listTask[MAX_TASK];

/*
 * @brief:	Initialize all task in the array
 * @para:	none
 * @retval:	none
 * */
void SCH_Init(void){
	for (int i = 0; i < MAX_TASK; i++){
//		listTask[i].pTask = 0x0000;
		listTask[i].ID = -1;
		listTask[i].Delay = 0;
		listTask[i].Period = 0;
		listTask[i].Runme = 0;
	}
}

/*
 * @brief:	Update the delay of the task
 * @para:	none
 * @retval:	none
 * */
void SCH_Update(void){
	for (int i = 0; i < MAX_TASK; i++){
		if (listTask[i].ID != -1){
			if(listTask[i].Delay == 0){
				listTask[i].Runme = 1;
				listTask[i].Delay = listTask[i].Period;
			}
			else{
				listTask[i].Delay--;
			}
		}
	}
}
/*
 * @brief:	Find the task that need to be run and update delay | delete task
 * @para:	none
 * @retval:	none
 * */
void SCH_Dispatch_Tasks(void){
	for (int i = 0; i < MAX_TASK; i++){
		if(listTask[i].ID != -1 && listTask[i].Runme > 0){
			(*listTask[i].pTask)();
			listTask[i].Runme--;
			if(listTask[i].Runme <= 0 && listTask[i].Period == 0){
				SCH_Delete_Task(listTask[i].ID);
			}
		}
	}
}
/*
 * @brief:	Add the task to the array
 * @para:	pFunction: 	Pointer that point to the function need to run
 * 			DELAY:		the Delay value of the task
 * 			PERIOD:		the Period value of the task
 * @retval:	-1		-	Cannot add to the array
 * 			TaskID	-	Add successfully and return the ID of the task
 * */
uint32_t SCH_Add_Task(void (* pFunction)(), uint32_t DELAY, uint32_t PERIOD){
	static unsigned int GLOBAL_ID = 0;
	int done = 0;
	uint32_t Return_val = -1;
	for (int i = 0; i < MAX_TASK && (done == 0); i++){
		if (listTask[i].ID == -1){
			listTask[i].pTask = pFunction;
			listTask[i].Delay = DELAY;
			listTask[i].Period = PERIOD;
			listTask[i].Runme = 0;
			listTask[i].ID = GLOBAL_ID++;
			Return_val = listTask[i].ID;
			done = 1;
		}
	}
	return Return_val;
}
/*
 * @brief:	Delete the task in array
 * @para:	ID of the task
 * @retval:	1	-	delete successfully
 * 			0	-	cannot delete
 * */
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
