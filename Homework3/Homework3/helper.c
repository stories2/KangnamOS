//
//  helper.c
//  Homework3
//
//  Created by 김현우 on 2017. 12. 2..
//  Copyright © 2017년 김현우. All rights reserved.
//

#include "main.h"

int IsAllProcessLunched(int processCheck[PROCESS_NUM]) {
    int i;
    for(i = 0; i < PROCESS_NUM; i += 1) {
        if(processCheck[i] == NOT_LAUNCHED) {
            return NOT_LAUNCHED;
        }
    }
    return LAUNCHED;
}

void PrintStatus(int processCheck[PROCESS_NUM], struct Queue *rear, int timer) {
//    int i;
//    
//    printf("------time %2d------\n", timer);
//    
//    printf("------process lunched checker------\n");
//    for(i = 0; i < PROCESS_NUM; i += 1) {
//        printf("#%2d -> %d\n", i, processCheck[i]);
//    }
//    
//    if(rear == NULL)
//        return;
//    printf("------cpu running------\n");
//    printf("#%2d arrive: %2d service remain: %2d wait: %2d\n", rear->id, rear->arriveTime, rear->serviceTime, rear->waitingTime);
//    
//    rear = rear->nextQueue;
//    
//    printf("------queue------\n");
//    while(rear != NULL) {
//        printf("#%2d arrive: %2d service remain: %2d wait: %2d\n", rear->id, rear->arriveTime, rear->serviceTime, rear->waitingTime);
//        rear = rear->nextQueue;
//    }
}

void IncreaseWaitTime(struct Queue *rear) {
    if(rear != NULL) {
        rear = rear->nextQueue;
        while(rear != NULL) {
            rear->waitingTime += 1;
            rear = rear->nextQueue;
        }
    }
}

void IncreaseWaitTimeFeedback(struct Queue *running, struct FeedbackQueue *feedbackQueueRoot) {
    struct FeedbackQueue *indexOfFeedbackLevel = feedbackQueueRoot;
    struct Queue *indexOfQueue = NULL;
    while(indexOfFeedbackLevel != NULL) {
        indexOfQueue = indexOfFeedbackLevel->firstIndex;
        while(indexOfQueue != NULL) {
            if(indexOfQueue != running) {
                indexOfQueue->waitingTime += 1;
            }
            indexOfQueue = indexOfQueue->nextQueue;
        }
        indexOfFeedbackLevel = indexOfFeedbackLevel->nextLevelQueue;
    }
}

void PrintEndOfSchedule(int processNum, int startTime, int endTime, char *processType) {
    printf("[%10s] All process num: %d start time: %d end time: %d\n", processType, processNum, startTime, endTime);
}

void PrintScheduleResult(int delayTimeSum, int serviceTimeSum) {
    double averageReturnTime = (double)(delayTimeSum + serviceTimeSum) / PROCESS_NUM,
    averageDelayTime = (double)(delayTimeSum) / PROCESS_NUM,
    sqrtReturnTime = sqrt(pow(((delayTimeSum + serviceTimeSum) - averageReturnTime), 2) / (PROCESS_NUM - 1)),
    sqrtDelayTime = sqrt(pow((delayTimeSum - averageDelayTime), 2) / (PROCESS_NUM - 1));
    
    printf("[Return] average: %.2lf Standard Deviation: %.2lf\n[Delay] average: %.2lf Standard Deviation: %.2lf\n",
           averageReturnTime, sqrtReturnTime, averageDelayTime, sqrtDelayTime);
}
