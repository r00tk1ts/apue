/**
 * @file 初始态置为detach的线程创建demo
 *
 * apue示例程序 - detach.c
 *
 * @author Steve & r00tk1t
 *
 */
#include "apue.h"
#include <pthread.h>

int makethread(void *(*fn)(void *), void *arg)
{
    int				err;
    pthread_t		tid;
    pthread_attr_t	attr;

    err = pthread_attr_init(&attr);
    if (err != 0)
        return(err);
    err = pthread_attr_setdetachstate(&attr, PTHREAD_CREATE_DETACHED);
    if (err == 0)
        err = pthread_create(&tid, &attr, fn, arg);
    pthread_attr_destroy(&attr);
    return(err);
}
