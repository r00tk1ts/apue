/**
 * @file sleep模拟实现1
 *
 * apue示例程序 - sleep1.c
 *
 * @author Steve & r00tk1t
 *
 */
#include	<signal.h>
#include	<unistd.h>

static void sig_alrm(int signo)
{
	/* nothing to do, just return to wake up the pause */
}

unsigned int sleep1(unsigned int seconds)
{
	if (signal(SIGALRM, sig_alrm) == SIG_ERR)
		return(seconds);
	/*
	 * 1. alarm和pause非原子，如果alarm后被调度出去，seconds后才会来调用pause，则可能会永久阻塞
	 * 2. 如果用户设置过定时器，会破坏现状，sig_alrm也被内部消化掉了，外部不知这一事实
	 */
	alarm(seconds);		/* start the timer */
	pause();			/* next caught signal wakes us up */
	return(alarm(0));	/* turn off timer, return unslept time */
}
