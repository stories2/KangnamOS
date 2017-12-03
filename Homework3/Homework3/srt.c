//
//  srt.c
//  Homework3
//
//  Created by 김현우 on 2017. 12. 2..
//  Copyright © 2017년 김현우. All rights reserved.
//

#include "main.h"

void SimulateSRT(int processTestData[PROCESS_NUM][PROCESS_INFO]) {
    struct Queue *front = NULL, *rear = NULL, *runner = NULL;
    int processCheck[PROCESS_NUM] = {NOT_LAUNCHED, };
    int timer = 0, i, swapFlag = DISABLE, minServiceTime = 0;
    
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
                    swapFlag = ENABLE;
                }
            }
        }
        
        if(swapFlag == ENABLE) {
            swapFlag = DISABLE;
            minServiceTime = 987654321;
            if(rear->serviceTime <= 0) {
                rear = rear->nextQueue;
            }
            if(rear != front) {
                struct Queue *indexFinder = rear, *minServiceTimeProcess = NULL;
                while(indexFinder != NULL) {
                    if(indexFinder->serviceTime < minServiceTime) {
                        minServiceTimeProcess = indexFinder;
                        minServiceTime = indexFinder->serviceTime;
                    }
                    indexFinder = indexFinder->nextQueue;
                }
                if(minServiceTimeProcess != rear) {
                    if(minServiceTimeProcess == front) {
                        front = minServiceTimeProcess->beforeQueue;
                    }
                    if(minServiceTimeProcess->beforeQueue != NULL) {
                        minServiceTimeProcess->beforeQueue->nextQueue = minServiceTimeProcess->nextQueue;
                    }
                    if(minServiceTimeProcess->nextQueue != NULL) {
                        minServiceTimeProcess->nextQueue->beforeQueue = minServiceTimeProcess->beforeQueue;
                    }
                    minServiceTimeProcess->beforeQueue = NULL;
                    minServiceTimeProcess->nextQueue = rear;
                    rear = minServiceTimeProcess;
                }
            }
        }
        
        if(rear != NULL) {
            runner = rear;
        }
        
        if(runner->serviceTime > 1) {
            runner->serviceTime -= 1;
        }
        else {
            runner->serviceTime -= 1;
            processCheck[runner->id] = LAUNCHED;
            swapFlag = ENABLE;
        }
        IncreaseWaitTime(rear);
        PrintStatus(processCheck, rear, timer);
        timer += 1;
    }
    printf("all time: %d\n", timer);
}
