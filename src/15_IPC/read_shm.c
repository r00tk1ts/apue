/**
 * @file 读共享存储
 *
 * apue示例程序 - read_shm.c
 *
 * @author r00tk1t
 *
 */
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>
#include <sys/ipc.h>
#include <sys/shm.h>
#include "common_shm.h"

int main()
{
    int id = shmget(SHM_ID, 8, 0);
    if (id == -1) err_sys("shmget");

    Student *p = (Student*)shmat(id, NULL, 0);
    while(1) {
        printf(" age=%d, name=%s\n", p->age, p->name);
        sleep(2);
    }
    return 0;
}