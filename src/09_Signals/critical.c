/**
 * @file SIGQUIT捕获测试
 *
 * apue示例程序 - critical.c
 *
 * @author Steve & r00tk1t
 *
 */
#include "apue.h"

static void	sig_quit(int);

int main()
{
	sigset_t	newmask, oldmask, pendmask;

	if (signal(SIGQUIT, sig_quit) == SIG_ERR)
		err_sys("can't catch SIGQUIT");

	/*
	 * Block SIGQUIT and save current signal mask.
	 */
	sigemptyset(&newmask);
	sigaddset(&newmask, SIGQUIT);
	if (sigprocmask(SIG_BLOCK, &newmask, &oldmask) < 0)
		err_sys("SIG_BLOCK error");

	sleep(5);	/* SIGQUIT here will remain pending */

	if (sigpending(&pendmask) < 0)
		err_sys("sigpending error");
	if (sigismember(&pendmask, SIGQUIT))
		printf("\nSIGQUIT pending\n");

	/*
	 * Restore signal mask which unblocks SIGQUIT.
	 */
	if (sigprocmask(SIG_SETMASK, &oldmask, NULL) < 0)
		err_sys("SIG_SETMASK error");
	printf("SIGQUIT unblocked\n");

	sleep(5);	/* SIGQUIT here will terminate with core file */
	exit(0);
}

static void sig_quit(int signo)
{
	printf("caught SIGQUIT\n");
	if (signal(SIGQUIT, SIG_DFL) == SIG_ERR)
		err_sys("can't reset SIGQUIT");
}
