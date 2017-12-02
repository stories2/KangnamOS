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
    int i;
    
    printf("------time %2d------\n", timer);
    
    printf("------process lunched checker------\n");
    for(i = 0; i < PROCESS_NUM; i += 1) {
        printf("#%2d -> %d\n", i, processCheck[i]);
    }
    
    if(rear == NULL)
        return;
    printf("------cpu running------\n");
    printf("#%2d arrive: %2d service remain: %2d\n", rear->id, rear->arriveTime, rear->serviceTime);
    
    rear = rear->nextQueue;
    
    printf("------queue------\n");
    while(rear != NULL) {
        printf("#%2d arrive: %2d service remain: %2d\n", rear->id, rear->arriveTime, rear->serviceTime);
        rear = rear->nextQueue;
    }
}
