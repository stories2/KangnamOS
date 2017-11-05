#include "main.h"

int main() {
    cout << "Hello, goorm!" << endl;
    
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
     }*/
     
    
    ExecuteManager *manager = new ExecuteManager();
    manager->SetOrder(argv);
    manager->Execute();
    delete manager;
    /*
    
    char *argvTest[] ={"ls", "-al"};
    int test = execvp(argvTest[0], argvTest);
    cout << "execvp: " << test << endl;*/
    return 0;
}

