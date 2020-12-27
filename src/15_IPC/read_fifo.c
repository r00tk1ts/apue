/**
 * @file 读FIFO
 *
 * apue示例程序 - read_fifo.c
 *
 * @author r00tk1t
 *
 */
#include<stdio.h>
#include<sys/types.h>
#include<sys/stat.h>
#include<unistd.h>
#include<fcntl.h>
#include "apue.h"

int main()
{
    int fd;
    char buf[MAXLINE];
    fd = open("my_fifo", O_RDONLY);

    while(1)
    {
        read(fd, buf, sizeof(buf));
        printf("%s\n", buf);
        sleep(1);
    }
    return 0;
}