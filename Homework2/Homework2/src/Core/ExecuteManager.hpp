
#include <iostream>
#include <string>
#include <unistd.h>
#include <sys/wait.h>
#include <cstring>
#include "../Utils/LogManager.hpp"
#ifndef CUSTOM_SHELL
#define CUSTOM_SHELL
#define CHILD_PROCESS 0
#endif
using namespace std;


class ExecuteManager {
    string *orderArray;
    LogManager logManager;
public:
    ExecuteManager(LogManager &);
    ExecuteManager(LogManager &, string orderArray[]);
    ~ExecuteManager();
    void SetOrder(string orderArray[]);
    void Execute();
    char** ConvertStringArray2CharArray(string orderArray[]);
    void DeleteConvertedCharArray(char **orderArray);
};

