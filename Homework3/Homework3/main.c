//
//  main.c
//  Homework3
//
//  Created by 김현우 on 2017. 11. 27..
//  Copyright © 2017년 김현우. All rights reserved.
//

#include <stdio.h>

#define PROCESS_NUM 5
#define PROCESS_INFO 2

void SimulateFCFS(int [PROCESS_NUM][PROCESS_INFO]);
void SimulateRoundRobin(int [PROCESS_NUM][PROCESS_INFO]);
void SimulateSPN(int [PROCESS_NUM][PROCESS_INFO]);
void SimulateSRT(int [PROCESS_NUM][PROCESS_INFO]);
void SimulateHRRN(int [PROCESS_NUM][PROCESS_INFO]);
void SimulateFeedback(int [PROCESS_NUM][PROCESS_INFO]);

int main(int argc, const char * argv[]) {
    // insert code here...
    int processTestData[PROCESS_NUM][PROCESS_INFO] = {
        {0, 3},
        {2, 6},
        {4, 4},
        {6, 5},
        {8, 2}
    };
    SimulateFCFS(processTestData);
    return 0;
}

void SimulateFCFS(int processTestData[PROCESS_NUM][PROCESS_INFO]) {
    
}

void SimulateRoundRobin(int processTestData[PROCESS_NUM][PROCESS_INFO]) {
    
}

void SimulateSPN(int processTestData[PROCESS_NUM][PROCESS_INFO]) {
    
}

void SimulateSRT(int processTestData[PROCESS_NUM][PROCESS_INFO]) {
    
}

void SimulateHRRN(int processTestData[PROCESS_NUM][PROCESS_INFO]) {
    
}

void SimulateFeedback(int processTestData[PROCESS_NUM][PROCESS_INFO]) {
    
}
