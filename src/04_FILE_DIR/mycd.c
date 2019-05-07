/**
 * @file 测试chdir
 *
 * apue示例程序 - mycd.c
 *
 * @author Steve & r00tk1t
 *
 */
#include "apue.h"

int main()
{
	char buf[128];
	printf("%s\n", getcwd(buf, sizeof(buf)));
	if (chdir("/tmp") < 0)
		err_sys("chdir failed");
	printf("chdir to /tmp succeeded\n");
	printf("%s\n", getcwd(buf, sizeof(buf)));
	return 0;
}