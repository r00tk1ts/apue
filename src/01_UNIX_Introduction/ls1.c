/**
 * @file 模拟ls命令
 *
 * apue示例程序 - ls1.c
 *
 * @author Steve & r00tk1t
 *
 */
#include "apue.h"
#include <dirent.h>

int main(int argc, char *argv[])
{
    DIR *dp;
    struct dirent *dirp;

    if(argc != 2)
        err_quit("usage: %s directory_name", argv[0]);
    
    if((dp = opendir(argv[1])) == NULL)
        err_sys("can't open %s", argv[1]);
    
    while((dirp = readdir(dp)) != NULL)
        printf("%s\n", dirp->d_name);

    closedir(dp);
    return 0;
}