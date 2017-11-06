#include <stdio.h>
#include <string.h>
#include <sys/types.h>
#include <unistd.h>
#define MAXARG 7
#define MAXIMUM_BUFFER_SIZE 256
#define SHELL_TYPE "/bin/sh"
#define SHELL_OPTION "-c"
#define SHELL_TYPE_SAVED_POINT 0
#define SHELL_OPTION_SAVED_POINT 1
#define SHELL_COMMAND_SAVED_POINT 2
#define END_OF_COMMAND_SAVED_POINT 3

int main()
{
    char *arg[MAXARG];
    int pid, status;
    arg[SHELL_TYPE_SAVED_POINT] = SHELL_TYPE;
    arg[SHELL_OPTION_SAVED_POINT] = SHELL_OPTION;

    while(1) {
        char buf[MAXIMUM_BUFFER_SIZE] = {'\0', };
        printf("myshell$ ");
        gets(buf);
        arg[SHELL_COMMAND_SAVED_POINT] = buf;
        arg[END_OF_COMMAND_SAVED_POINT] = (char *)0;
        
        if (!strcmp(arg[SHELL_COMMAND_SAVED_POINT], "quit"))
            break;
        
        if ((pid=fork()) == -1)
            perror("fork failed");
        else if (pid != 0) {
            pid = wait(&status);
        } else {
            execvp(arg[SHELL_TYPE_SAVED_POINT], arg);
        }
    }
    exit(0);
    return 0;
}

