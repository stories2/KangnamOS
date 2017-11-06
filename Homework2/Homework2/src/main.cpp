#include "main.h"

int main() {
    
    string argv[] = {"ls", "-al"};
    LogManager *logManager = new LogManager();
    logManager->PrintLogInfo("main", "main", "logging test");
    ExecuteManager *manager = new ExecuteManager(*logManager);
    manager->SetOrder(argv);
    manager->Execute();
    delete manager;
    delete logManager;
    return 0;
}

