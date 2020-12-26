/**
 * @file 创建管道
 *
 * apue示例程序 - pipe1.c
 *
 * @author Steve & r00tk1t
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
    } else if (pid > 0) {		/* parent */
        close(fd[0]);
        write(fd[1], "hello world\n", 12);
    } else {					/* child */
        close(fd[1]);
        n = read(fd[0], line, MAXLINE);
        write(STDOUT_FILENO, line, n);
    }
    return 0;
}
