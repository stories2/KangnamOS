#include <cstdio>
#include <unistd.h>
#include <wait.h>

int main()
{
	int pid;
    printf("hello from Homework1!\n");

	pid = fork();

	wait(NULL);
	printf("my pid: %d\n", pid);
    return 0;
}