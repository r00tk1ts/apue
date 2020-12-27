//
// Created by r00tk1t on 2020/12/27.
//

#ifndef APUE_MQ_COMMON_H
#define APUE_MQ_COMMON_H

#define MQ_KEY 11111

struct msgbuf{
    long channel;
    char mtext[100];
};

#endif //APUE_MQ_COMMON_H
