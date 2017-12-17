//
//  main.c
//  Homework5
//
//  Created by 김현우 on 2017. 12. 17..
//  Copyright © 2017년 김현우. All rights reserved.
//

#include <stdio.h>

#define MAXARG 7
#define MAXIMUM_BUFFER_SIZE 256
#define SHELL_TYPE "/bin/sh"
#define SHELL_OPTION "-c"
#define SHELL_TYPE_SAVED_POINT 0
#define SHELL_OPTION_SAVED_POINT 1
#define SHELL_COMMAND_SAVED_POINT 2
#define END_OF_COMMAND_SAVED_POINT 3

int main(int argc, const char * argv[]) {
    // insert code here...
//    printf("Hello, World!\n");
    int pid, status;
    char *arg[MAXARG];
    char buf[MAXIMUM_BUFFER_SIZE] = {'\0', }, orderBuf[MAXIMUM_BUFFER_SIZE] = {'\0', };
    
    arg[SHELL_TYPE_SAVED_POINT] = SHELL_TYPE;
    arg[SHELL_OPTION_SAVED_POINT] = SHELL_OPTION;
    
    printf("input path: ");
    scanf("%s", buf);
    sprintf(orderBuf, "du -h %s", buf);
    printf("process %s\n", orderBuf);
    arg[SHELL_COMMAND_SAVED_POINT] = orderBuf;
    arg[END_OF_COMMAND_SAVED_POINT] = (char *)0;
    
    if ((pid=fork()) == -1)
        perror("fork failed");
    else if (pid != 0) {
        pid = wait(&status);
    } else {
        execvp(arg[SHELL_TYPE_SAVED_POINT], arg);
    }
    
    return 0;
}
