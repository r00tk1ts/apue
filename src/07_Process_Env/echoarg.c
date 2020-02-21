/**
 * @file 遍历argv参数
 *
 * apue示例程序 - echoarg.c
 *
 * @author Steve & r00tk1t
 *
 */
#include "apue.h"

int main(int argc, char *argv[], char *env[])
{
	int	i;

	for (i = 0; i < argc; i++)		/* echo all command-line args */
		printf("argv[%d]: %s\n", i, argv[i]);

    for (i=0; ;++i)
    {
        if(env[i] == NULL)
            break;
        printf("env[%d]:%s\n", i, env[i]);
    }
	exit(0);
}
