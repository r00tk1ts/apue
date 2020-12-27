/**
 * @file popen读取测试
 *
 * apue示例程序 - popen1.c
 *
 * @author Steve & r00tk1t
 *
 */
#include "apue.h"
#include <sys/wait.h>

int main(int argc, char *argv[])
{
	char	line[MAXLINE];
	FILE	*fpin;

	if ((fpin = popen("./myuclc", "r")) == NULL)
		err_sys("popen error");
	for ( ; ; ) {
		fputs("prompt> ", stdout);
		fflush(stdout);
		if (fgets(line, MAXLINE, fpin) == NULL)	/* read from pipe */
			break;
		if (fputs(line, stdout) == EOF)
			err_sys("fputs error to pipe");
	}
	if (pclose(fpin) == -1)
		err_sys("pclose error");
	putchar('\n');
	return 0;
}
