#include "main.h"

int main() {
    
    string argv[] = {"/bin/sh", "-c", "who | wc"};
    string messageVar;
    while(1) {
        LogManager *logManager = new LogManager();
        logManager->PrintLogInfo("main", "main", "logging test");
        ExecuteManager *manager = new ExecuteManager(*logManager);
        cout << "myshell$ ";
//        cin.ignore();
        getline(cin, messageVar, '\n');
        argv[2] = messageVar;
        manager->SetOrder(argv);
        manager->Execute();
        delete manager;
        delete logManager;
    }
    return 0;
}

