#include <stdio.h>
#include <string.h>
#include <sys/types.h>
#include <unistd.h>
#define MAXARG 7

main()
{
    char *arg[MAXARG];
    char *s;
    char *save;
    int argv;
    /* ∞¯πÈ, ≈«, ∞≥«‡¿∏∑Œ ¿Ã∑ÁæÓ¡¯ ±∏∫–¿⁄ º±æ */
    static const char delim[] = " \t\n";
    int pid, status;
    arg[0] = "/bin/bash";
    arg[1] = "-c";
    /* π´«— π›∫π */
    while(1) {
        char buf[256] = {'\0', };
        /* «¡∑“«¡∆Æ √‚∑¬ */
        printf("myshell$ ");
        gets(buf);
        arg[2] = buf;
//        argv = 0;
        /* πÆ¿⁄ø≠ø°º≠ delim¿ª ±‚¡ÿ¿∏∑Œ ¥‹æÓ∏¶ ¿ﬂ∂Û≥ø */
//        s = strtok_r(buf, delim, &save);
//        while(s) {
//            arg[argv++] = s;
//            s = strtok_r(NULL, delim, &save);
//        }
        /* ¿Œºˆ∞° ¥ı æ¯¿Ω¿ª ¿«πÃ«œ¥¬ πÆ¿⁄ √ﬂ∞° */
        arg[3] = (char *)0;
        
        /* «¡∑“«¡∆Æ∑Œ ¿‘∑¬ πﬁ¿∫ √π π¯¬∞ ¥‹æÓ∞° °Æquit°Ø¿Ã∏È while πÆ π˛æÓ≥≤ */
        if (!strcmp(arg[2], "quit"))
            break;
        
        if ((pid=fork()) == -1)   /* fork »£√‚ø° Ω«∆–«œ∏È */
            perror("fork failed");
        /* ∫Œ∏ «¡∑ŒººΩ∫¥¬ ¿⁄Ωƒ «¡∑ŒººΩ∫∞° ¡æ∑·µ«±‚∏¶ ±‚¥Ÿ∏≤ */
        else if (pid != 0) {
            pid = wait(&status);
            /* ¿⁄Ωƒ «¡∑ŒººΩ∫¥¬ execvp∏¶ ¿ÃøÎ«œø© arg[0] Ω««‡ */
        } else {
            execvp(arg[0], arg);
        }
    }
    exit(0);
}

