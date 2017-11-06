//
//  LogManager.cpp
//  Homework2
//
//  Created by 김현우 on 2017. 11. 6..
//  Copyright © 2017년 김현우. All rights reserved.
//

#include "LogManager.hpp"

LogManager::LogManager() {
    
}

LogManager::LogManager(LogManager &logManager) {
    int len;
    len = strlen(logManager.className);
    this->className = new char [len + 1];
    strcpy(this->className, logManager.className);
    
    len = strlen(logManager.methodName);
    this->methodName = new char [len + 1];
    strcpy(this->methodName, logManager.methodName);
    
    len = strlen(logManager.msg);
    this->msg = new char [len + 1];
    strcpy(this->msg, logManager.msg);
}

void LogManager::PrintLogInfo(char *className, char *methodName, char *msg) {
    int len;
    len = strlen(className);
    this->className = new char [len + 1];
    strcpy(this->className, className);
    
    len = strlen(methodName);
    this->methodName = new char [len + 1];
    strcpy(this->methodName, methodName);
    
    len = strlen(msg);
    this->msg = new char [len + 1];
    strcpy(this->msg, msg);
    
    logLevel = LOG_LEVEL_INFO;
    PrintLog();
}

void LogManager::PrintLogWarn(char *className, char *methodName, char *msg) {
    int len;
    len = strlen(className);
    this->className = new char [len + 1];
    strcpy(this->className, className);
    
    len = strlen(methodName);
    this->methodName = new char [len + 1];
    strcpy(this->methodName, methodName);
    
    len = strlen(msg);
    this->msg = new char [len + 1];
    strcpy(this->msg, msg);
    
    logLevel = LOG_LEVEL_WARN;
    PrintLog();
}

void LogManager::PrintLogError(char *className, char *methodName, char *msg) {
    int len;
    len = strlen(className);
    this->className = new char [len + 1];
    strcpy(this->className, className);
    
    len = strlen(methodName);
    this->methodName = new char [len + 1];
    strcpy(this->methodName, methodName);
    
    len = strlen(msg);
    this->msg = new char [len + 1];
    strcpy(this->msg, msg);
    
    logLevel = LOG_LEVEL_ERROR;
    PrintLog();
}

void LogManager::PrintLog() {
    switch (logLevel) {
        case LOG_LEVEL_INFO:
            cout << "I: ";
            break;
        case LOG_LEVEL_WARN:
            cout << "W: ";
            break;
        case LOG_LEVEL_ERROR:
            cout << "E: ";
            break;
            
        default:
            break;
    }
    cout << "[" << className << "] {" << methodName << "} (" << msg << ")" << endl;
}

LogManager::~LogManager() {
    delete [] className;
    delete [] methodName;
    delete [] msg;
}
