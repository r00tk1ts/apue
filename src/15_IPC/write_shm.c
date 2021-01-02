/**
 * @file 写共享存储
 *
 * apue示例程序 - write_shm.c
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
   Student s;
   strcpy(s.name, "Jack");

   int id = shmget(SHM_ID, 8, IPC_CREAT|0644);
   if (id == -1) err_sys("shmget");

   Student *p = (Student*)shmat(id, NULL, 0);

   int i = 0;
   while(1) {
       s.age = i++;
       memcpy(p, &s, sizeof(Student));
       sleep(2);
   }
   return 0;
}