#include <iostream>
#include <string>
#include <unistd.h>
#include <sys/wait.h>

using namespace std;

#ifndef CUSTOM_SHELL
#define CUSTOM_SHELL
#define CHILD_PROCESS 0
#endif

class ExecuteManager {
    string *orderArray;
public:
    ExecuteManager();
    ExecuteManager(string orderArray[]);
    ~ExecuteManager();
    void SetOrder(string orderArray[]);
    void Execute();
};

