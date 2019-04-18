/**
 * @file 测试lseek
 *
 * apue示例程序 - seek.c
 *
 * @author Steve & r00tk1t
 *
 */
#include "apue.h"

int main()
{
    if(lseek(STDIN_FILENO, 0, SEEK_CUR) == -1)
        printf("cannot seek\n");
    else
        printf("seek OK\n");
    
    return 0;
}