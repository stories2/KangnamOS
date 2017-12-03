//
//  main.h
//  Homework3
//
//  Created by 김현우 on 2017. 12. 2..
//  Copyright © 2017년 김현우. All rights reserved.
//

#ifndef main_h

#include <stdio.h>

#define main_h
#define PROCESS_NUM 5
#define PROCESS_INFO 2
#define NOT_LAUNCHED 0
#define LAUNCHED 1
#define ARRIVE_TIME 0
#define SERVICE_TIME 1
#define ENABLE 1
#define DISABLE 0

struct Queue{
    int arriveTime, serviceTime, id, waitingTime;
    struct Queue *nextQueue, *beforeQueue;
};

void SimulateFCFS(int [PROCESS_NUM][PROCESS_INFO]);
void SimulateRoundRobin(int [PROCESS_NUM][PROCESS_INFO]);
void SimulateSPN(int [PROCESS_NUM][PROCESS_INFO]);
void SimulateSRT(int [PROCESS_NUM][PROCESS_INFO]);
void SimulateHRRN(int [PROCESS_NUM][PROCESS_INFO]);
void SimulateFeedback(int [PROCESS_NUM][PROCESS_INFO]);
int IsAllProcessLunched(int [PROCESS_NUM]);
void PrintStatus(int [PROCESS_NUM], struct Queue *, int );
void IncreaseWaitTime(struct Queue *);

#endif /* main_h */
