/**
 * @file 创建FIFO
 *
 * apue示例程序 - fifo.c
 *
 * @author r00tk1t
 *
 */
#include <stdio.h>
#include <sys/stat.h>
#include <stdlib.h>
#include <unistd.h>
#include <fcntl.h>
#include "apue.h"

int main()
{
    if(mkfifo("my_fifo", 0777) == -1)
    {
        err_sys("mkfifo");
    }
    return 0;
}