#include "main.h"

int main() {
	cout << "Hello, goorm!" << endl;
	
	char *argv[] ={"ls", "-al", NULL};
	/*
	cout << "make child process" << endl;
	pid_t pid = fork();
	if(pid == CHILD_PROCESS) {
		cout << "child " << pid << endl;
		execvp(argv[0], argv);
	}
	else if(pid > CHILD_PROCESS) {
		cout << "parent " << pid << endl;
	}
	else {
		cout << "error" << endl;
	}
	*/
	ExecuteManager manager;
	manager.SetOrder(argv);
	manager.Execute();
	return 0;
}