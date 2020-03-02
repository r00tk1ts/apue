/**
 * @file 测试sigint
 *
 * apue示例程序 - sigint.c
 *
 * @author Steve & r00tk1t
 *
 */
#include "apue.h"

static void sig_int(int signo)
{
    printf("caught SIGINT\n");
}

static void sig_quit()
{
    printf("caught SIGQUIT\n");
}

int main(void)
{
    if (signal(SIGINT, sig_int) == SIG_ERR)
        err_sys("signal(SIGINT) error");
    if (signal(SIGQUIT, sig_quit) == SIG_ERR)
        err_sys("signal(SIGQUIT) error");
    while(1);
    return 0;
}