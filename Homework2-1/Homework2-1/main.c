#include <stdio.h>
#include <string.h>
#include <sys/types.h>
#include <unistd.h>
#define MAXARG 7

int main()
{
    int pid, status;
    char *arg[] = {"/bin/sh", "-c", "echo hello > output.txt", '\0'};
    if ((pid=fork()) == -1)   /* fork »£√‚ø° Ω«∆–«œ∏È */
        perror("fork failed\n");
    /* ∫Œ∏ «¡∑ŒººΩ∫¥¬ ¿⁄Ωƒ «¡∑ŒººΩ∫∞° ¡æ∑·µ«±‚∏¶ ±‚¥Ÿ∏≤ */
    else if (pid != 0) {
        pid = wait(&status);
        /* ¿⁄Ωƒ «¡∑ŒººΩ∫¥¬ execvp∏¶ ¿ÃøÎ«œø© arg[0] Ω««‡ */
    } else {
        execvp(arg[0], arg);
        printf("execvp failed\n");
    }
    exit(0);
    return 0;
}

