#include "main.h"

int main() {
    
    string argv[] = {"who"}, argv2[] = {"wc"};
    LogManager *logManager = new LogManager();
    logManager->PrintLogInfo("main", "main", "logging test");
    ExecuteManager *manager = new ExecuteManager(*logManager);
    manager->SetOrder(argv);
    manager->Execute();
    manager->SetOrder(argv2);
    manager->Execute();
    delete manager;
    delete logManager;
    return 0;
}

