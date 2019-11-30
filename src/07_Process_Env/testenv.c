/**
 * @file 测试环境变量
 *
 * apue示例程序 - testenv.c
 *
 * @author r00tk1t
 *
 */
#include <stdlib.h>
#include <stdio.h>

int main()
{
	char *p;
    if(p = getenv("USER"))
        printf("USER=%s\n", p);
	// overwrite
	if(setenv("USER", "test", 1) != 0)
		err_sys("setenv error");
	if(p = getenv("USER"))
		printf("USER=%s\n", p);
	if(putenv("USER=root") != 0)
		err_sys("putenv error");
	if(p = getenv("USER"))
		printf("USER=%s\n", p);
    return 0;
}