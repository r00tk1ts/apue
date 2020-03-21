/**
 * @file 测试sleep2.c模拟实现的sleep
 *
 * apue示例程序 - tsleep.c
 *
 * @author Steve & r00tk1t
 *
 */
#include "apue.h"

unsigned int	sleep2(unsigned int);
static void		sig_int(int);

int main()
{
	unsigned int	unslept;

	if (signal(SIGINT, sig_int) == SIG_ERR)
		err_sys("signal(SIGINT) error");
	unslept = sleep2(5);
	printf("sleep2 returned: %u\n", unslept);
	exit(0);
}

static void sig_int(int signo)
{
	int				i, j;
	volatile int	k;

	/*
	 * Tune these loops to run for more than 5 seconds
	 * on whatever system this test program is run.
	 */
	printf("\nsig_int starting\n");
	for (i = 0; i < 300000; i++)
		for (j = 0; j < 4000; j++)
			k += i * j;
	printf("sig_int finished\n");
}
