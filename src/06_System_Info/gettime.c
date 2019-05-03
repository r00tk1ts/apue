/**
 * @file 获取时间并格式化打印字符串.c
 *
 * apue示例程序 - gettime.c
 *
 * @author r00tk1t
 *
 */
#include<stdio.h>
#include<stdlib.h>
#include<time.h>

int main(void)
{
	time_t t;
	struct tm* mytime;
	char buf[16];
	char buff[64];

	time(&t);
	mytime = localtime(&t);
	if(strftime(buf,16,"time and date : %r ,%a %b %d, %Y", mytime)==0)
		printf("bufer length is too small\n");
	else
		printf("%s\n", buf);

	if(strftime(buff,64,"time and date : %r ,%a %b %d, %Y", mytime) == 0)
		printf("bufer length is too small\n");
	else
		printf("%s\n",buff);
    
	return 0;
}
