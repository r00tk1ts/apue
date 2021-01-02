/**
 * @file 共享存储FIFO-GET端
 *
 * apue示例程序 - shm_get.c
 *
 * @author r00tk1t
 *
 */
#include "shm_fifo.h"
#include <unistd.h>

typedef struct Products{
    int id;
    char pro_name[10];
}Pro;

int main()
{
    shmfifo_t* fifo = shmfifo_init(12345, 3, sizeof(Pro));
    Pro p;

    for(int i=0; i<20; i++) {
        memset(&p, 0x00, sizeof(p));
        shmfifo_get(fifo, &p);
        printf("id:%d, 产品名：%s\n", p.id, p.pro_name);
        sleep(1);
    }
    shmfifo_destroy(fifo);
    return 0;
}