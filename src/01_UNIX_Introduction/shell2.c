/**
 * @file 模拟shell，处理SIGINT信号
 *
 * apue示例程序 - shell2.c
 *
 * @author Steve & r00tk1t
 *
 */
#include "apue.h"
#include <sys/wait.h>

static void sig_int(int);   // SIGINT catching handler

int main()
{
    char buf[MAXLINE];  
    pid_t pid;
    int status;

    if(signal(SIGINT, sig_int) == SIG_ERR)
        err_sys("signal error");

    printf("%% ");  // 提示符
    while(fgets(buf, MAXLINE, stdin) != NULL) {
        if(buf[strlen(buf)-1] == '\n')
            buf[strlen(buf)-1] = 0; 
        
        if((pid = fork()) < 0) {
            err_sys("fork error");
        } else if(pid == 0) {   // child
            execlp(buf, buf, (char *)0);
            err_ret("couldn't execute: %s", buf);
            exit(127);
        }

        // parent
        if(pid = waitpid(pid, &status, 0) < 0)
            err_sys("waitpid error");
        printf("%% ");
    }
    return 0;
}

void sig_int(int signo)
{
    printf("interrupt\n%% ");
}