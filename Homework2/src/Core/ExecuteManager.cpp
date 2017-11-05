#include "ExecuteManager.h"

ExecuteManager::ExecuteManager(){
	
}

ExecuteManager::ExecuteManager(char **orderArray) {
	int len = sizeof(orderArray) / sizeof(orderArray[0]);
	int i, indexOfLen;
	this->orderArray = new char *[len + 1];
	for(i = 0; i <= len; i++) {
		indexOfLen = strlen(orderArray[i]);
		this->orderArray[i] = new char[indexOfLen + 1];
		strcpy(this->orderArray[i], orderArray[i]);
	}
}

void ExecuteManager::SetOrder(char **orderArray) {
	int len = sizeof(orderArray) / sizeof(orderArray[0]);
	int i, indexOfLen;
	cout << "array row len: " << len << endl;
	this->orderArray = new char *[len + 1];
	for(i = 0; i <= len; i++) {
		indexOfLen = strlen(orderArray[i]);
		this->orderArray[i] = new char[indexOfLen + 1];
		strcpy(this->orderArray[i], orderArray[i]);
		cout << "#" << i << ": " << this->orderArray[i] << " added" << endl;
	}
}

void ExecuteManager::Execute() {
	pid_t pid = fork();
	if(pid == CHILD_PROCESS) {
		cout << "child " << pid << endl;
		execvp(orderArray[0], orderArray);
	}
	else if(pid > CHILD_PROCESS) {
		cout << "parent " << pid << endl;
		wait();
	}
	else {
		cout << "error" << endl;
	}
}

ExecuteManager::~ExecuteManager() {
	int len = sizeof(orderArray) / sizeof(orderArray[0]), i;
	for(i = 0; i <= len; i ++) {
		delete [] orderArray[i];
	}
}