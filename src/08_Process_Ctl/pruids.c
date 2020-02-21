/**
 * @file 获取实际用户id和有效用户id
 *
 * apue示例程序 - pruids.c
 *
 * @author Steve & r00tk1t
 *
 */
#include "apue.h"

int main(void)
{
	printf("real uid = %d, effective uid = %d\n", getuid(), geteuid());
	exit(0);
}
