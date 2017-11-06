#include "main.h"

int main() {
    
    string argv[] = {"/bin/sh", "-c", "who | wc"};
    string messageVar;
    LogManager *logManager = new LogManager();
    logManager->PrintLogInfo("main", "main", "logging test");
    ExecuteManager *manager = new ExecuteManager(*logManager);
    while(1) {
        cout << "myshell$ ";
//        cin.ignore();
        getline(cin, messageVar, '\n');
        cin.clear();
        argv[2] = messageVar;
        if(argv[2] != "") {
            manager->SetOrder(argv);
            manager->Execute();
        }
    }
    delete manager;
    delete logManager;
    return 0;
}

