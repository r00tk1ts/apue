/**
 * @file 管道模拟`ls -l|wc -l`
 *
 * apue示例程序 - pipe3.c
 *
 * @author r00tk1t
 *
 */
#include "apue.h"

int main(int argc, char *argv[])
{
    int		n;
    int		fd[2];
    pid_t	pid;
    char	line[MAXLINE];

    if (pipe(fd) < 0)
        err_sys("pipe error");
    if ((pid = fork()) < 0) {
        err_sys("fork error");
    } else if (pid == 0) {		/* child */
        close(fd[0]);
        if (dup2(fd[1], STDOUT_FILENO) != STDOUT_FILENO)
            err_sys("dup2 error to stdout");
        execlp("ls", "ls", "-l", NULL);
        close(fd[1]);
        exit(127);
    } else {					/* parent */
        close(fd[1]);
        if (dup2(fd[0], STDIN_FILENO) != STDIN_FILENO)
            err_sys("dup2 error to stdin");
        execlp("wc", "wc", "-l", NULL);
        close(fd[0]);
        exit(127);
    }
    return 0;
}
