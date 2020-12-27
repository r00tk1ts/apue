/**
 * @file 写FIFO
 *
 * apue示例程序 - write_fifo.c
 *
 * @author r00tk1t
 *
 */
#include<stdio.h>
#include<sys/types.h>
#include<sys/stat.h>
#include<unistd.h>
#include<fcntl.h>

int main()
{
    int fd;
    char buf[] = "6666";
    fd = open("my_fifo", O_WRONLY);

    while(1)
    {
        write(fd, buf, sizeof(buf));
        sleep(1);
    }
    return 0;
}