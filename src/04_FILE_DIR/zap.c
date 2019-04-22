/**
 * @file 测试futimens
 *
 * apue示例程序 - zap.c
 *
 * @author Steve & r00tk1t
 *
 */  
#include "apue.h"
#include <fcntl.h>
#include <sys/stat.h>

int main(int argc, char *argv[])
{
	int				i, fd;
	struct stat		statbuf;
	struct timespec	times[2];

	for (i = 1; i < argc; i++) {
		if (stat(argv[i], &statbuf) < 0) {	/* fetch current times */
			err_ret("%s: stat error", argv[i]);
			continue;
		}
		if ((fd = open(argv[i], O_RDWR | O_TRUNC)) < 0) { /* truncate */
			err_ret("%s: open error", argv[i]);
			continue;
		}
#ifdef __USE_XOPEN2K8
		times[0] = statbuf.st_atim;
		times[1] = statbuf.st_mtim;
#else
        times[0].tv_sec = statbuf.st_atime;
        times[0].tv_nsec = statbuf.st_atimensec;
		times[1].tv_sec = statbuf.st_mtime;
        times[1].tv_nsec = statbuf.st_mtimensec;
#endif
		if (futimens(fd, times) < 0)		/* reset times */
			err_ret("%s: futimens error", argv[i]);
		close(fd);
	}
	exit(0);
}