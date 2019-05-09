/**
 * @file 获取时间并格式化打印字符串
 *
 * apue示例程序 - strftime.c
 *
 * @author Steve & r00tk1t
 *
 */
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main()
{
	time_t t;
	struct tm *tmp;
	char buf1[16];
	char buf2[64];

	time(&t);
	tmp = localtime(&t);
	if (strftime(buf1, 16, "time and date: %r, %a %b %d, %Y", tmp) == 0)
		printf("buffer length 16 is too small\n");
	else
		printf("%s\n", buf1);
	if (strftime(buf2, 64, "time and date: %r, %a %b %d, %Y", tmp) == 0)
		printf("buffer length 64 is too small\n");
	else
		printf("%s\n", buf2);
	return 0;
}
