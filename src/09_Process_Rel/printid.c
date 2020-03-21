/**
 * @file 打印相关id
 *
 * apue示例程序 - printid.c
 *
 * @author  r00tk1t
 *
 */
#include "apue.h"
#include <sys/wait.h>

void pr_ids(char *name)
{
    printf("%s: pid = %ld, ppid = %ld, pgrp = %ld, tpgrp = %ld\n",
           name, (long)getpid(), (long)getppid(), (long)getpgrp(),
           (long)tcgetpgrp(STDIN_FILENO));
}

int main()
{
    pid_t	pid;
    int     status;

    pr_ids("parent");
    if ((pid = fork()) < 0) {
        err_sys("fork error");
    } else if (pid > 0) {	/* parent */
        if (wait(&status) != pid)		/* wait for child */
            err_sys("wait error");
    } else {			/* child */
        pr_ids("child");
    }
    return 0;
}