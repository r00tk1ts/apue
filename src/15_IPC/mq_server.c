/**
 * @file MQ-Server
 *
 * apue示例程序 - mq_server.c
 *
 * @author r00tk1t
 *
 */
#include <stdio.h>
#include <stdlib.h>
#include <sys/ipc.h>
#include <sys/msg.h>
#include <string.h>
#include <unistd.h>
#include "mq_common.h"
#include "apue.h"

int main()
{
    int id = msgget(MQ_KEY, IPC_CREAT|0600); //创建消息队列
    if(id == -1) err_sys("msgrcv");

    while(1) {
        struct msgbuf mb;
        memset(&mb, 0x00, sizeof(mb));
        if(msgrcv(id ,&mb, 100,1, 0) == -1)
            err_sys("msgrcv");

        printf("Get from Client:%s\n", mb.mtext+ sizeof(long));
        mb.channel = *(long*)(mb.mtext);
        msgsnd(id, &mb, strlen(mb.mtext+sizeof(long)) + sizeof(long), 0);
    }
    return 0;
 }