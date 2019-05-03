/**
 * @file 测试uname/gethostname
 *
 * apue示例程序 - uname.c
 *
 * @author r00tk1t
 *
 */
#include"apue.h"
#include<sys/utsname.h>
#include<unistd.h>

int main(void)
{
	int ret;
	struct utsname myuname;
	if((ret = uname(&myuname)) < 0)
		err_sys("uname error");
	else
		printf("%s\t%s\t%s\t%s\t%s\n", myuname.sysname, myuname.nodename, myuname.version, myuname.release, myuname.machine);

	char buf[64];
	if((gethostname(&buf,strlen(buf))<0)
		err_sys("gethostname error");
	printf("hostname:%s\n", buf);

	return 0;
}