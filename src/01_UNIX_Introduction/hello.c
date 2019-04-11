/**
 * @file 打印当前进程pid
 *
 * apue示例程序 - hello.c
 *
 * @author Steve & r00tk1t
 *
 */
#include "apue.h"

int main()
{
    printf("hello world from process ID %ld\n", (long)getpid());
    exit(0);
}