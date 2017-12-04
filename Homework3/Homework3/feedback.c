//
//  feedback.c
//  Homework3
//
//  Created by 김현우 on 2017. 12. 2..
//  Copyright © 2017년 김현우. All rights reserved.
//

#include "main.h"

void SimulateFeedback(int processTestData[PROCESS_NUM][PROCESS_INFO]) {
    struct FeedbackQueue *feedbackQueue = NULL, *indexOfFeedbackQueue;
    struct Queue *running = NULL;
    int processCheck[PROCESS_NUM] = {NOT_LAUNCHED, };
    int timer = 0, swapFlag = DISABLE, i, lastProcessedLevel = 0, processTimeGap = 2, processTimeLimit = 0, processTime = 0;
    
    feedbackQueue = malloc(sizeof(feedbackQueue));
    feedbackQueue->firstIndex = NULL;
    feedbackQueue->nextLevelQueue = NULL;
    feedbackQueue->timeLevel = 0;
    
    while(IsAllProcessLunched(processCheck) == NOT_LAUNCHED) {
        for(i = 0; i < PROCESS_NUM; i += 1) {
            if(timer == processTestData[i][ARRIVE_TIME]) {
                struct Queue *newProcess = malloc(sizeof(struct Queue));
                newProcess->arriveTime = processTestData[i][ARRIVE_TIME];
                newProcess->serviceTime = processTestData[i][SERVICE_TIME];
                newProcess->id = i;
                newProcess->waitingTime = 0;
                newProcess->beforeQueue = NULL;
                newProcess->nextQueue = NULL;
                if(feedbackQueue->firstIndex == NULL) {
                    feedbackQueue->firstIndex = newProcess;
                }
                else {
                    struct Queue *indexOfProcess = feedbackQueue->firstIndex;
                    while(indexOfProcess->nextQueue != NULL) {
                        indexOfProcess = indexOfProcess->nextQueue;
                    }
                    indexOfProcess->nextQueue = newProcess;
                    newProcess->beforeQueue = indexOfProcess;
                }
            }
        }
        
        if(running == NULL) {
            swapFlag = ENABLE;
        }
        
        if(swapFlag == ENABLE) {
            swapFlag = DISABLE;
            //move to another queue
            indexOfFeedbackQueue = feedbackQueue;
            if(running != NULL) {
                for(i = 0; i < lastProcessedLevel; i += 1) {
                    indexOfFeedbackQueue = indexOfFeedbackQueue->nextLevelQueue;
                }
                if(running->serviceTime <= 0) {
                    indexOfFeedbackQueue->firstIndex = running->nextQueue;
                    running = NULL;
                }
                else {
                    struct FeedbackQueue *nextLevelQueue = NULL;
                    if(indexOfFeedbackQueue->nextLevelQueue == NULL) {
                        nextLevelQueue = malloc(sizeof(struct FeedbackQueue));
                        nextLevelQueue->firstIndex = NULL;
                        nextLevelQueue->nextLevelQueue = NULL;
                        nextLevelQueue->timeLevel = i + 1;
                        indexOfFeedbackQueue->nextLevelQueue = nextLevelQueue;
                    }
                    nextLevelQueue = indexOfFeedbackQueue->nextLevelQueue;
                    struct Queue *indexOfQueue = NULL;
                    if(nextLevelQueue->firstIndex != NULL) {
                        indexOfQueue = nextLevelQueue->firstIndex;
                        while(indexOfQueue->nextQueue != NULL) {
                            indexOfQueue = indexOfQueue->nextQueue;
                        }
                        indexOfQueue->nextQueue = running;
                        indexOfFeedbackQueue->firstIndex = indexOfFeedbackQueue->firstIndex->nextQueue;
                        running->beforeQueue = indexOfQueue;
                        if(running->nextQueue != NULL) {
                            running->nextQueue->beforeQueue = NULL;
                        }
                        running->nextQueue = NULL;
                    }
                    else {
                        nextLevelQueue->firstIndex = running;
                        struct Queue *lastSwitchPlaceFinder = NULL;
                        struct FeedbackQueue *indexOfFeedbackQueueFinder = feedbackQueue;
                        int stop = DISABLE;
                        while(indexOfFeedbackQueueFinder != NULL && stop == DISABLE) {
                            lastSwitchPlaceFinder = indexOfFeedbackQueueFinder->firstIndex;
                            while(lastSwitchPlaceFinder != NULL) {
                                if(lastSwitchPlaceFinder == running) {
                                    if(running == indexOfFeedbackQueueFinder->firstIndex) {
                                        indexOfFeedbackQueueFinder->firstIndex = running->nextQueue;
                                    }
                                    if(running->beforeQueue != NULL) {
                                        running->beforeQueue->nextQueue = running->nextQueue;
                                    }
                                    if(running->nextQueue != NULL) {
                                        running->nextQueue->beforeQueue = running->beforeQueue;
                                    }
                                    running->beforeQueue = NULL;
                                    running->nextQueue = NULL;
                                    stop = ENABLE;
                                    break;
                                }
                                lastSwitchPlaceFinder = lastSwitchPlaceFinder->nextQueue;
                            }
                            indexOfFeedbackQueueFinder = indexOfFeedbackQueueFinder->nextLevelQueue;
                        }
                    }
                }
            }
            //find rdy process from queue
            indexOfFeedbackQueue = feedbackQueue;
            lastProcessedLevel = 0;
            while(indexOfFeedbackQueue != NULL) {
                if(indexOfFeedbackQueue->firstIndex != NULL) {
                    running = indexOfFeedbackQueue->firstIndex;
                    break;
                }
                indexOfFeedbackQueue = indexOfFeedbackQueue->nextLevelQueue;
                lastProcessedLevel = lastProcessedLevel + 1;
            }
            processTimeLimit = pow(processTimeGap, lastProcessedLevel);
            processTime = 0;
        }
        
        if(running != NULL) {
            processTime += 1;
            if(running->serviceTime > 1) {
                running->serviceTime = running->serviceTime - 1;
            }
            else {
                processCheck[running->id] = LAUNCHED;
                running->serviceTime = running->serviceTime - 1;
                swapFlag = ENABLE;
            }
            if(processTime >= processTimeLimit) {
                swapFlag = ENABLE;
            }
        }
        
        timer += 1;
    }
    printf("all time: %d\n", timer);
}
