//
//  LogManager.hpp
//  Homework2
//
//  Created by 김현우 on 2017. 11. 6..
//  Copyright © 2017년 김현우. All rights reserved.
//
#include <iostream>
#include <string>
#include <cstring>

#ifndef LogManager_hpp
#define LogManager_hpp


#define LOG_LEVEL_INFO 0
#define LOG_LEVEL_WARN 1
#define LOG_LEVEL_ERROR 2
#define DEBUG_MODE 1
#define DISABLE 0


class LogManager {
    char *className, *methodName, *msg;
    int logLevel;
public:
    LogManager();
    LogManager(LogManager &);
    void PrintLogInfo(char *, char *, char *);
    void PrintLogWarn(char *, char *, char *);
    void PrintLogError(char *, char *, char *);
    void PrintLog();
    ~LogManager();
};
#endif /* LogManager_hpp */
using namespace std;
