/**
 * @file 测试chown，需root权限
 *
 * apue示例程序 - changeown.c
 *
 * @author r00tk1t
 *
 */
#include "apue.h"
#include <sys/stat.h>

int main()
{
	struct stat		statbuf;

	if (stat("foo", &statbuf) < 0)
		err_sys("stat error for foo");
	if (chown("foo", 1000, 1000) < 0)
		err_sys("chown error for foo");

	return 0;
}