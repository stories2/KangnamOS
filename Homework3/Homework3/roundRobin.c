//
//  roundRobin.c
//  Homework3
//
//  Created by 김현우 on 2017. 12. 2..
//  Copyright © 2017년 김현우. All rights reserved.
//

#include "main.h"

void SimulateRoundRobin(int processTestData[PROCESS_NUM][PROCESS_INFO]) {
    struct Queue *front = NULL, *rear = NULL, *runner = NULL;
    int processCheck[PROCESS_NUM] = {NOT_LAUNCHED, };
    int timer = 0, i, cpuCoolTime = 0, cpuCoolTimeLimit = 1;
    
    while(IsAllProcessLunched(processCheck) == NOT_LAUNCHED) {
        for(i = 0; i < PROCESS_NUM; i += 1) {
            if(timer == processTestData[i][ARRIVE_TIME]) {
                if(front == NULL) {
                    front = malloc(sizeof(struct Queue));
                    front->arriveTime = processTestData[i][ARRIVE_TIME];
                    front->serviceTime = processTestData[i][SERVICE_TIME];
                    front->id = i;
                    front->nextQueue = NULL;
                    front->beforeQueue = NULL;
                    
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
                    newIndex->beforeQueue = front;
                    front->nextQueue = newIndex;
                    front = newIndex;
                }
            }
        }
        
        if(rear != NULL) {
            if(rear->serviceTime <= 0 || cpuCoolTime >= cpuCoolTimeLimit) {
                if(rear != front && rear->serviceTime > 0) {
                    struct Queue *temp = rear->nextQueue;
                    rear->beforeQueue = front;
                    rear->nextQueue = NULL;
                    front->nextQueue = rear;
                    front = rear;
                    rear = temp;
                }
                else if(rear != front) {
                    rear = rear->nextQueue;
                }
                cpuCoolTimeLimit = 0;
            }
            runner = rear;
            if(runner->serviceTime > 1) {
                runner->serviceTime -=1;
                cpuCoolTime += 1;
            }
            else {
                processCheck[runner->id] = LAUNCHED;
                //            runner = NULL;
                runner->serviceTime -= 1;
            }
        }
        IncreaseWaitTime(rear);
        PrintStatus(processCheck, rear, timer);
        timer += 1;
    }
    printf("all time: %d\n", timer);
}
