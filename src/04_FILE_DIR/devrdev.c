/**
 * @file 测试字符设备和块设备文件
 *
 * apue示例程序 - devrdev.c
 *
 * @author Steve & r00tk1t
 *
 */
#include "apue.h"
#ifdef SOLARIS
#include <sys/mkdev.h>
#endif
#include <sys/stat.h>

int main(int argc, char *argv[])
{
	int			i;
	struct stat	buf;

	for (i = 1; i < argc; i++) {
		printf("%s: ", argv[i]);
		if (stat(argv[i], &buf) < 0) {
			err_ret("stat error");
			continue;
		}

		printf("dev = %d/%d", major(buf.st_dev),  minor(buf.st_dev));

		if (S_ISCHR(buf.st_mode) || S_ISBLK(buf.st_mode)) {
			printf(" (%s) rdev = %d/%d",
					(S_ISCHR(buf.st_mode)) ? "character" : "block",
					major(buf.st_rdev), minor(buf.st_rdev));
		}
		printf("\n");
	}

	return 0;
}