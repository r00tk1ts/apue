/**
 * @file 低速系统调用打断测试
 *
 * apue示例程序 - read1.c
 *
 * @author Steve & r00tk1t
 *
 */
#include "apue.h"

static void	sig_alrm(int);

int main()
{
	int		n;
	char	line[MAXLINE];

	if (signal(SIGALRM, sig_alrm) == SIG_ERR)
		err_sys("signal(SIGALRM) error");

	/*
	 * 1.alarm和read不是原子的，中间可能会被调度出去，如果调度出去的时间超过了定时器的时间，
	 *   那么read就可能永久阻塞，alarm定时器无法达到停止read的效果
	 * 2.如果read实现是自动重启的，SIGALRM中断程序返回是不会打断read的
	 */
	alarm(5);
	if ((n = read(STDIN_FILENO, line, MAXLINE)) < 0)
		err_sys("read error");
	alarm(0);

	write(STDOUT_FILENO, line, n);
	exit(0);
}

static void sig_alrm(int signo)
{
	/* nothing to do, just return to interrupt the read */
}
