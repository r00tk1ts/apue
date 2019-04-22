/**
 * @file 测试access
 *
 * apue示例程序 - access.c
 *
 * @author Steve & r00tk1t
 *
 */
#include "apue.h"
#include <fcntl.h>

int main(int argc, char *argv[])
{
	if (argc != 2)
		err_quit("usage: %s <pathname>", argv[0]);
	if (access(argv[1], R_OK) < 0)
		err_ret("access error for %s", argv[1]);
	else
		printf("read access OK\n");
	if (open(argv[1], O_RDONLY) < 0)
		err_ret("open error for %s", argv[1]);
	else
		printf("open for reading OK\n");
	return 0;
}