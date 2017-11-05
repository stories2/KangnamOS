#include "ExecuteManager.hpp"

ExecuteManager::ExecuteManager(){
    
}

ExecuteManager::ExecuteManager(string orderArray[]) {
    int len = orderArray->length(), i;
    this->orderArray = new string[len + 1];
    for(i = 0; i <= len; i++) {
        this->orderArray[i] = orderArray[i];
    }
}

void ExecuteManager::SetOrder(string orderArray[]) {
    int len = orderArray->length(), i;
    this->orderArray = new string[len + 1];
    for(i = 0; i <= len; i++) {
        this->orderArray[i] = orderArray[i];
    }
}

void ExecuteManager::Execute() {
    char **orderArrayChar = ConvertStringArray2CharArray(this->orderArray);
    pid_t pid = fork();
    if(pid == CHILD_PROCESS) {
        cout << "child " << pid << endl;
        cout << "order: " << orderArrayChar[0] << endl;
        execvp(orderArrayChar[0], orderArrayChar);
    }
    else if(pid > CHILD_PROCESS) {
        cout << "parent " << pid << endl;
        wait(NULL);
    }
    else {
        cout << "error" << endl;
    }
}

char** ExecuteManager::ConvertStringArray2CharArray(string *target) {
    int len = target->length(), i;
    char **convertArray = NULL;
    
    convertArray = new char *[len];
    for(i = 0; i < len; i ++) {
        int subStrLen = target[i].length();
        cout << "#" << i << ": " << target[i] << " len: " << subStrLen << endl;
        convertArray[i] = new char[subStrLen + 1];
        strncpy(convertArray[i], target[i].c_str(), sizeof(convertArray[i]));
    }
    return convertArray;
}

ExecuteManager::~ExecuteManager() {
    delete [] orderArray;
}

