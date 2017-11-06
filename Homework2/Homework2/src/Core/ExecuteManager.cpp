#include "ExecuteManager.hpp"

ExecuteManager::ExecuteManager(LogManager &logManager){
    this->logManager = logManager;
}

ExecuteManager::ExecuteManager(LogManager &logManager, string orderArray[]) {
    int len = orderArray->length(), i;
    this->logManager = logManager;
    this->orderArray = new string[len];
    for(i = 0; i < len; i++) {
        this->orderArray[i] = orderArray[i];
    }
}

void ExecuteManager::SetOrder(string orderArray[]) {
    int len = orderArray->length(), i;
    this->orderArray = new string[len];
    for(i = 0; i < len; i++) {
        this->orderArray[i] = orderArray[i];
    }
}

void ExecuteManager::Execute() {
    char **orderArrayChar = ConvertStringArray2CharArray(this->orderArray);
    pid_t pid = fork();
    if(pid == CHILD_PROCESS) {
        char buffer[200];
        sprintf(buffer, "child: %d", pid);
        logManager.PrintLogInfo("ExecuteManager", "Execute", buffer);
        sprintf(buffer, "order: %s", orderArrayChar[0]);
        logManager.PrintLogInfo("ExecuteManager", "Execute", buffer);
        int status = execvp(*orderArrayChar, orderArrayChar);
        if (status < 0) {
            sprintf(buffer, "order exec failed with: %d", status);
            logManager.PrintLogWarn("ExecuteManager", "Execute", buffer);
            exit(1);
        }
    }
    else if(pid > CHILD_PROCESS) {
        char buffer[200];
        sprintf(buffer, "parent: %d", pid);
        logManager.PrintLogInfo("ExecuteManager", "Execute", buffer);
        wait(NULL);
    }
    else {
        logManager.PrintLogError("ExecuteManager", "Execute", "fork error");
    }
}

char** ExecuteManager::ConvertStringArray2CharArray(string *target) {
    int len = target->length(), i;
    char **convertArray = NULL;
    
    convertArray = new char *[len];
    for(i = 0; i < len; i ++) {
        int subStrLen = target[i].length();
        convertArray[i] = new char[subStrLen + 1];
        strncpy(convertArray[i], target[i].c_str(), sizeof(convertArray[i]));
    }
    return convertArray;
}

ExecuteManager::~ExecuteManager() {
    delete [] orderArray;
}

