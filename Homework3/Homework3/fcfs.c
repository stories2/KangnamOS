//
//  fcfs.c
//  Homework3
//
//  Created by 김현우 on 2017. 12. 2..
//  Copyright © 2017년 김현우. All rights reserved.
//

#include "main.h"

void SimulateFCFS(int processTestData[PROCESS_NUM][PROCESS_INFO]) {
    struct Queue *front = NULL, *rear = NULL;
    int processCheck[PROCESS_NUM] = {NOT_LAUNCHED, };
    int timer = 0, i;
    
    while(IsAllProcessLunched(processCheck) == NOT_LAUNCHED) {
        for(i = 0; i < PROCESS_NUM; i += 1) {
            if(timer == processTestData[i][ARRIVE_TIME]) {
                if(front == NULL) {
                    front = malloc(sizeof(struct Queue));
                    front->arriveTime = processTestData[i][ARRIVE_TIME];
                    front->serviceTime = processTestData[i][SERVICE_TIME];
                    front->id = i;
                    front->nextQueue = NULL;
                    
                    if(rear == NULL) {
                        rear = front;
                    }
                }
                else {
                    struct Queue *newIndex = malloc(sizeof(struct Queue));
                    newIndex->arriveTime = processTestData[i][ARRIVE_TIME];
                    newIndex->serviceTime = processTestData[i][SERVICE_TIME];
                    newIndex->nextQueue = NULL;
                    newIndex->id = i;
                    front->nextQueue = newIndex;
                    front = newIndex;
                }
            }
        }
        if(rear != NULL) {
            if(rear->serviceTime > 1) {
                rear->serviceTime -= 1;
            }
            else {
                processCheck[rear->id] = LAUNCHED;
                if(rear->nextQueue != NULL) {
                    rear = rear->nextQueue;
                }
            }
        }
        PrintStatus(processCheck, rear, timer);
        timer += 1;
    }
    printf("all time: %d\n", timer);
}
