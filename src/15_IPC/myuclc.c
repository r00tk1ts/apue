/**
 * @file popen测试辅助过滤程序
 *
 * apue示例程序 - myuclc.c
 *
 * @author Steve & r00tk1t
 *
 */
#include "apue.h"
#include <ctype.h>

int main(int argc, char *argv[])
{
	int		c;

	while ((c = getchar()) != EOF) {
		if (isupper(c))
			c = tolower(c);
		if (putchar(c) == EOF)
			err_sys("output error");
		if (c == '\n')
			fflush(stdout);
	}
	return 0;
}
