/**
 * @file 练习dup/dup2
 *
 * apue示例程序 - dup.c
 *
 * @author r00tk1t
 *
 */
#include "apue.h"

int main()
{
    int fd = dup(0);   //复制stdin，理应返回3
    if(-1 == fd)
        err_sys("dup stdin failed!");
    printf("fd:%d\n",fd);

    int result = dup2(100, fd);   // 理应atomic{close(fd) + fcntl(100, F_DUPFD, fd)}，但100是未打开的fd
    if(-1 == fd)
        err_sys("dup2 100 failed!");
    printf("fd:%d\n", fd);

    return 0;
}