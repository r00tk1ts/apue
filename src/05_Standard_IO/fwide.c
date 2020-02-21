/**
 * @file 测试fwide
 *
 * apue示例程序 - fwide.c
 *
 * @author r00tk1t
 *
 */
#include "apue.h"
#include <wchar.h>

int fwide_help(FILE *fp, int mode)
{
    if(!fp) 
        return 0;

    int result = fwide(fp, mode);
    if(result > 0)
        printf("fp(%p) is wide-byte-flow\n", fp);
    else if(result < 0)
        printf("fp(%p) is byte-flow\n", fp);
    else
        printf("fp(%p) is unordered\n", fp);

    return result; 
}

int main()
{
    fwide_help(stdin, 0);   // 打印stdin/stdout/stderr的流向
    fwide_help(stdout, 0);
    fwide_help(stderr, 0);

    FILE *fp = fopen("Makefile", "r");
    if(fp != NULL)
    {
        fwide_help(fp, 0);
        fwide_help(fp, -1); // 修改为字节流
		fwide_help(fp, 1);	// 尝试修改为宽字节流，但不会成功，因为一旦指定了流向就不能再改变
    }
    return 0;
}