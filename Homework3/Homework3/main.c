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
//    SimulateFCFS(processTestData);
//    SimulateRoundRobin(processTestData);
    SimulateSPN(processTestData);
    return 0;
}
