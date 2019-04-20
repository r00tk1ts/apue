/**
 * @file 测试getchar和putchar
 *
 * apue示例程序 - getcharbug.c
 * https://stackoverflow.com/questions/10720821/im-trying-to-understand-getchar-eof
 *
 * @author Steve & r00tk1t
 *
 */        
#include <stdio.h>

int main(void)
{
	char c;

	while ((c = getchar()) != EOF)
		putchar(c);
	
	return 0;
}