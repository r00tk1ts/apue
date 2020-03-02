/**
 * @file 自定义system测试
 *
 * apue示例程序 - systest2.c
 *
 * @author Steve & r00tk1t
 *
 */
#include "apue.h"

static void sig_int(int signo)
{
	printf("caught SIGINT\n");
}

static void sig_chld(int signo)
{
	printf("caught SIGCHLD\n");
}

int main(void)
{
	if (signal(SIGINT, sig_int) == SIG_ERR)
		err_sys("signal(SIGINT) error");
	if (signal(SIGCHLD, sig_chld) == SIG_ERR)
		err_sys("signal(SIGCHLD) error");
	if (system("/bin/ed") < 0)
		err_sys("system() error");
	exit(0);
}
