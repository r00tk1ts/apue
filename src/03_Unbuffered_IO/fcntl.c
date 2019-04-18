/**
 * @file 测试fcntl
 * 
 * apue示例程序 - fcntl.c
 *
 * @author r00tk1t
 *
 */
#include "apue.h"
#include <fcntl.h>

int fcntl_dupfd(int fd, int arg, int cloexec_flag)
{
    int result;

    if(cloexec_flag == 0)
        result = fcntl(fd, F_DUPFD, arg);
    else
        result = fcntl(fd, F_DUPFD_CLOEXEC, arg);
    
    if(result == -1)
    {
        err_ret("fcntl_dupfd failed, param fd:%d\targ:%d", fd, arg);
        return -1;
    }
    return result;
}

int fcntl_getfd(int fd)
{
    int result = fcntl(fd, F_GETFD);
    if(result == -1)
    {
        err_ret("fcntl_getfd failed, param fd:%d", fd);
        return -1;
    }
    return result;
}

int fcntl_setfd(int fd, int arg)
{
    int result = fcntl(fd, F_SETFD, arg);
    if(result == -1)
    {
        err_ret("fcntl_setfl failed, param fd:%d\targ:%d", fd, arg);
        return -1;
    }
    return result;
}

int main()
{
    int fd = fcntl_dupfd(STDIN_FILENO, 10, 0);

    if(fd != -1)
    {
        printf("Duplicated fd %d from stdin\n", fd);
        fcntl_setfd(fd, fcntl_getfd(fd));
    }
    
    return 0;
}