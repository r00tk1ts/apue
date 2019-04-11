/**
 * @file 测试getc和putc
 *
 * apue示例程序 - getcputc.c
 *
 * @author Steve & r00tk1t
 *
 */
#include "apue.h"

int main()
{
    int c;

    while((c = getc(stdin)) != EOF)
        if(putc(c, stdout) == EOF)
            err_sys("output error");

    if(ferror(stdin))
        err_sys("input error");

    return 0;
}