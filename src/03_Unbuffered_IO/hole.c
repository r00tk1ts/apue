/**
 * @file 生成空洞文件
 *
 * apue示例程序 - hole.c
 *
 * @author Steve & r00tk1t
 *
 */
#include "apue.h"
#include <fcntl.h>

char buf1[] = "abcdefghij";
char buf2[] = "ABCDEFGHIJ";

int main(void)
{
    int fd, fd2;
    int count = 0;

    if((fd = creat("file.hole", FILE_MODE)) < 0)
        err_sys("creat error");
    
    if(write(fd, buf1, 10) != 10)
        err_sys("buf1 write error");
    /* offset now = 10 */

    if(lseek(fd, 16384, SEEK_SET) == -1)
        err_sys("lseek error");
    /* offset now = 16384 */

    if(write(fd, buf2, 10) != 10)
        err_sys("buf2 write error");
    /* offset now = 16394 */
    // abcdefghij ......... ABCDEFGHIJ
    
    if((fd2 = creat("file.nohole", FILE_MODE)) < 0)
        err_sys("creat error");

    while(count < 16390)
    {
        if(write(fd2, buf1, 10) != 10)
            err_sys("buf1 write error");
        count += 10;
    }
        
    return 0;
}