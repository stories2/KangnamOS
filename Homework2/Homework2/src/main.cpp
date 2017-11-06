#include "main.h"

int main() {
    
//    char *argv[] ={"ls", "-al"};
    string argv[] = {"ls", "-al"};
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
    LogManager *logManager = new LogManager();
    logManager->PrintLogInfo("main", "main", "logging test");
    delete logManager;
    ExecuteManager *manager = new ExecuteManager(*logManager);
    manager->SetOrder(argv);
    manager->Execute();
    delete manager;
    return 0;
}

