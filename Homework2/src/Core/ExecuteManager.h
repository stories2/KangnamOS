#include <iostream>
#include <string.h>
#include <unistd.h>

using namespace std;

#ifndef CUSTOM_SHELL
#define CUSTOM_SHELL
#define CHILD_PROCESS 0
#endif

class ExecuteManager {
	char **orderArray;
public:
	ExecuteManager();
	ExecuteManager(char **orderArray);
	~ExecuteManager();
	void SetOrder(char **orderArray);
	void Execute();
};