/**
 * @file exec测试用例1
 *
 * apue示例程序 - exec1.c
 *
 * @author Steve & r00tk1t
 *
 */
#include "apue.h"
#include <sys/wait.h>

char* env_init[] = { "USER=unknown", "PATH=/tmp", NULL };

int main(void)
{
	pid_t	pid;

	if ((pid = fork()) < 0) {
		err_sys("fork error");
	} else if (pid == 0) {	/* specify pathname, specify environment */
		if (execle("/home/r00tk1t/apue/src/07_Process_Env/echoall", "echoall", "myarg1",
				"MY ARG2", (char *)0, env_init) < 0)
			err_sys("execle error");
	}

	if (waitpid(pid, NULL, 0) < 0)
		err_sys("wait error");

	if ((pid = fork()) < 0) {
		err_sys("fork error");
	} else if (pid == 0) {	/* specify filename, inherit environment */
		if (execlp("/home/r00tk1t/apue/src/07_Process_Env/echoall", "echoall", "only 1 arg", (char *)0) < 0)
			err_sys("execlp error");
	}

	exit(0);
}
