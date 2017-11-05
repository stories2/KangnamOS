#include "ExecuteManager.hpp"

ExecuteManager::ExecuteManager(){
    
}

ExecuteManager::ExecuteManager(string orderArray[]) {
    int len = orderArray->length();
    int i, indexOfLen;
    this->orderArray = new string[len + 1];
    for(i = 0; i <= len; i++) {
        indexOfLen = orderArray[i].length();
        this->orderArray[i] = orderArray[i];
    }
}

void ExecuteManager::SetOrder(string orderArray[]) {
    int len = orderArray->length();
    int i, indexOfLen;
    this->orderArray = new string[len + 1];
    for(i = 0; i <= len; i++) {
        indexOfLen = orderArray[i].length();
        this->orderArray[i] = orderArray[i];
    }
}

void ExecuteManager::Execute() {
    pid_t pid = fork();
    if(pid == CHILD_PROCESS) {
        cout << "child " << pid << endl;
//        execvp(orderArray[0], orderArray);
    }
    else if(pid > CHILD_PROCESS) {
        cout << "parent " << pid << endl;
        wait(NULL);
    }
    else {
        cout << "error" << endl;
    }
}

ExecuteManager::~ExecuteManager() {
    delete [] orderArray;
}

