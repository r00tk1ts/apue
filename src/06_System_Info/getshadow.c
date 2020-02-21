/**
 * @file 从shadow文件中获取r00tk1t用户的信息
 *
 * apue示例程序 - getshadow.c
 * 需要root权限
 *
 * @author r00tk1t
 *
 */
#include"apue.h"
#include<shadow.h>

int main()
{
	struct spwd *ptr;
	if((ptr=getspnam("r00tk1t"))==NULL)
		err_sys("getspnam error");
	printf("sp_pwdp=%s\n", (ptr->sp_pwdp == NULL || ptr->sp_pwdp[0] == '\0') 
        ? "(null)" : ptr->sp_pwdp);

	return 0;
}