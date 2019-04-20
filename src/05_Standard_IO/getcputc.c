/**
 * @file 测试putc和getc
 *
 * apue示例程序 - getcputc.c
 *
 * @author Steve & r00tk1t
 *
 */    
#include "apue.h"

int
main(void)
{
	int		c;

	while ((c = getc(stdin)) != EOF)
		if (putc(c, stdout) == EOF)
			err_sys("output error");

	if (ferror(stdin))
		err_sys("input error");

	exit(0);
}