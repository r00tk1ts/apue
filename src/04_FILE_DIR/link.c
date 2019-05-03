/**
 * @file 测试link
 *
 * apue示例程序 - link.c
 * 创建硬链接
 *
 * @author r00tk1t
 *
 */  
#include "apue.h"
#include <fcntl.h>

int main()
{
    int fd;
    char buf[] = "hello world";
	if ((fd = open("tempfile", O_RDWR | O_CREAT)) < 0)
		err_sys("open error");
    if (write(fd, buf, strlen(buf)+1) != strlen(buf)+1)
        err_sys("write error");
    if (link("tempfile", "tempfile2") < 0)
        err_sys("link error");
	if (unlink("tempfile") < 0)
		err_sys("unlink error");
	return 0;
}