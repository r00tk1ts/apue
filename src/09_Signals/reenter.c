/**
 * @file 测试中断调用不可重入函数引起的负面效果
 *
 * apue示例程序 - reenter.c
 *
 * @author Steve & r00tk1t
 *
 */
#include "apue.h"
#include <pwd.h>

static void my_alarm(int signo)
{
	struct passwd	*rootptr;

	printf("in signal handler\n");
	// ubuntu x64 16.04会死锁
	if ((rootptr = getpwnam("root")) == NULL)
			err_sys("getpwnam(root) error");
	printf("finish");
    alarm(1);
}

int main(void)
{
	struct passwd	*ptr;

	signal(SIGALRM, my_alarm);
	alarm(1);
	for ( ; ; ) {
		if ((ptr = getpwnam("r00tk1t")) == NULL)
			err_sys("getpwnam error");
		if (strcmp(ptr->pw_name, "r00tk1t") != 0)
			printf("return value corrupted!, pw_name = %s\n",
					ptr->pw_name);
	}
}
