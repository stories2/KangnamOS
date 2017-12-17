//
//  main.h
//  Homework3
//
//  Created by 김현우 on 2017. 12. 2..
//  Copyright © 2017년 김현우. All rights reserved.
//

#ifndef main_h

#include <stdio.h>
#include <math.h>
#include <stdlib.h>
#include <time.h>

#define main_h
#define PROCESS_NUM 100
#define PROCESS_INFO 2
#define NOT_LAUNCHED 0
#define LAUNCHED 1
#define ARRIVE_TIME 0
#define SERVICE_TIME 1
#define ENABLE 1
#define DISABLE 0
#define NOT_AVAILABLE -1

struct Queue{
    int arriveTime, serviceTime, id, waitingTime;
    struct Queue *nextQueue, *beforeQueue;
};

struct FeedbackQueue {
    int timeLevel;
    struct Queue *firstIndex;
    struct FeedbackQueue *nextLevelQueue;
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
void IncreaseWaitTimeFeedback(struct Queue *, struct FeedbackQueue *);
void PrintEndOfSchedule(int , int , int , char *);
void PrintScheduleResult(int , int );

#endif /* main_h */
