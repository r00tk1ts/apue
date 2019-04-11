/**
 * @file 模拟cat命令
 *
 * apue示例程序 - mycat.c
 *
 * @author Steve & r00tk1t
 *
 */
#include "apue.h"

#define BUFSIZE 4096

int main()
{
    int n;
    char buf[BUFSIZE];

    while((n = read(STDIN_FILENO, buf, BUFSIZE)) > 0)
        if(write(STDOUT_FILENO, buf, n) != n)
            err_sys("write error");

    if(n < 0)
        err_sys("read error");

    return 0;
}