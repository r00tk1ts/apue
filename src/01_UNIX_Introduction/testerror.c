/**
 * @file 测试errno,strerror
 *
 * apue示例程序 - testerror.c
 *
 * @author Steve & r00tk1t
 *
 */
#include "apue.h"
#include <errno.h>

int main(int argc, char *argv[])
{
    fprintf(stderr, "EACCES: %s\n", strerror(EACCES));
    errno = ENOENT;
    perror(argv[0]);
    exit(0);
}