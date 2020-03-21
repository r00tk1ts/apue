/**
 * @file 孤儿进程组SIGHUP|SIGCONT
 *
 * apue示例程序 - orphan3.c
 *
 * @author Steve & r00tk1t
 *
 */
#include "apue.h"
#include <errno.h>

static void sig_hup(int signo)
{
	printf("SIGHUP received, pid = %ld\n", (long)getpid());
}

static void pr_ids(char *name)
{
	printf("%s: pid = %ld, ppid = %ld, pgrp = %ld, tpgrp = %ld\n",
	    name, (long)getpid(), (long)getppid(), (long)getpgrp(),
	    (long)tcgetpgrp(STDIN_FILENO));
	fflush(stdout);
}

static void sig_cont(int signo)
{
    printf("SIGCONT received, pid = %ld\n", (long)getpid());
}

int main(void)
{
	char	c;
	pid_t	pid;

	pr_ids("parent");
	if ((pid = fork()) < 0) {
		err_sys("fork error");
	} else if (pid > 0) {	/* parent */
		sleep(5);		/* sleep to let child stop itself */
	} else {			/* child */
		pr_ids("child");
		signal(SIGHUP, sig_hup);	/* establish signal handler */
		//signal(SIGCONT, sig_cont);
		kill(getpid(), SIGTSTP);	/* stop ourself */
		pr_ids("child");	/* prints only if we're continued */
		if (read(STDIN_FILENO, &c, 1) != 1)
			printf("read error %d on controlling TTY\n", errno);
	}
	return 0;
}
