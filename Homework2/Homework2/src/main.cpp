#include "main.h"

int main() {
    
    string argv[] = {"/bin/sh", "-c", "echo hello > output.txt"}, argv2[] = {"wc"};
    LogManager *logManager = new LogManager();
    logManager->PrintLogInfo("main", "main", "logging test");
    ExecuteManager *manager = new ExecuteManager(*logManager);
    manager->SetOrder(argv);
    manager->Execute();
    delete manager;
    delete logManager;
    return 0;
}

