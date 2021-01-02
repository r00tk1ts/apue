//
// Created by r00tk1t on 2020/12/27.
//

#ifndef APUE_MQ_COMMON_H
#define APUE_MQ_COMMON_H

#define MQ_KEY 11111

typedef struct msg_buf{
    long channel;
    char mtext[100];
}msgbuf_t;

#endif //APUE_MQ_COMMON_H
