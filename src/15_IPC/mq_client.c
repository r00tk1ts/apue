/**
 * @file MQ-Client
 *
 * apue示例程序 - mq_client.c
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
    int id = msgget(MQ_KEY, 0);
    if(id == -1) err_sys("msgget");
    while(1) {
        msgbuf_t mb,rcv;
        memset(&mb, 0x00, sizeof(mb));
        while(fgets(mb.mtext+sizeof(long), 100- sizeof(long), stdin) != NULL) {
            *(long*)mb.mtext = getpid();
            mb.channel = 1;

            msgsnd(id, &mb, strlen(mb.mtext+ sizeof(long))+sizeof(long), 0);
            printf("send ok!\n");

            memset(&rcv, 0x00, sizeof(rcv));
            if(msgrcv(id, &rcv, 100, (long)getpid(), 0) == -1) {
                err_sys("msgrcv");
            }
            printf("Message back: %s\n", rcv.mtext + sizeof(long));
        }
    }
    return 0;
}
