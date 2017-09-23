#include "DeathWing.h"

int main()
{
	int pid, programCounter = 0, i;
    printf("hello from Homework1!\n");
	for (i = 0; i < 10; i += 1) {
		programCounter += 1;
		pid = fork();
		if (pid == 0) {
			break;
		}
	}

	wait(NULL);
	printf("my pid: %d prog: %d\n", pid, programCounter);
    return 0;
}