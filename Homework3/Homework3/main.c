//
//  main.c
//  Homework3
//
//  Created by 김현우 on 2017. 11. 27..
//  Copyright © 2017년 김현우. All rights reserved.
//

#include "main.h"

int main(int argc, const char * argv[]) {
    // insert code here...
    int processTestData[PROCESS_NUM][PROCESS_INFO] = {
        {0, 3},
        {2, 6},
        {4, 4},
        {6, 5},
        {8, 2}
    };
    int i;
    for(i = 0; i < PROCESS_NUM; i += 1) {
        processTestData[i][ARRIVE_TIME] = rand() % PROCESS_NUM;
        processTestData[i][SERVICE_TIME] = rand() % PROCESS_NUM;
    }
    SimulateFCFS(processTestData);
    SimulateRoundRobin(processTestData);
    SimulateSPN(processTestData);
    SimulateSRT(processTestData);
    SimulateHRRN(processTestData);
    SimulateFeedback(processTestData);
    return 0;
}
