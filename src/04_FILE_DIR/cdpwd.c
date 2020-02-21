/**
 * @file 测试chdir&getcwd
 *
 * apue示例程序 - cdpwd.c
 *
 * @author Steve & r00tk1t
 *
 */ 
#include "apue.h"

int main()
{
	char	*ptr;
	size_t		size;

	if (chdir("/usr/spool/uucppublic") < 0)
		err_sys("chdir failed");

	ptr = path_alloc(&size);	/* our own function */
	if (getcwd(ptr, size) == NULL)
		err_sys("getcwd failed");

	printf("cwd = %s\n", ptr);
	return 0;
}