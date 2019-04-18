/**
 * @file 测试open
 *
 * apue示例程序 - open.c
 *
 * @author r00tk1t
 *
 */
#include "apue.h"
#include <fcntl.h>

int main(int argc, char *argv[])
{
    int result;

    if(argc != 2)
        err_sys("usage: %s <filepath>", argv[0]);

    result = open(argv[1], O_RDWR);
    if(result == -1)
        err_sys("open %s failed\n", argv[1]);
    
    result = open(argv[1], O_RDWR, S_IRUSR | S_IWUSR);
    if(result == -1)
        err_sys("open %s with mode S_IRUSR|S_IWUSR failed\n", argv[1]);

    return 0;   
}