/**
 * @file 共享存储FIFO实现
 *
 * apue示例程序 - shm_fifo.c
 *
 * @author r00tk1t
 *
 */
#include "shm_fifo.h"
#include "apue.h"

typedef union semun{
    int val;
}semun;

// 初始化
shmfifo_t* shmfifo_init(key_t key, int blocks, int blksz)
{
    shmfifo_t *p = malloc(sizeof(shmfifo_t));

    int shmid = shmget(key, 0, 0);
    int len = sizeof(shmhead_t) + blocks * blksz; //共享内存段大小

    if(shmid == -1 )  // 内存段不存在，创建
    {
        shmid = shmget(key, len, IPC_CREAT|0644);
        if ( shmid == -1) err_sys("shmget");

        // 初始化内存段头
        p->p_head = shmat(shmid, NULL, 0); //将开出的内存段挂载到进程地址空间
        p->p_head->rd_idx = 0;
        p->p_head->wr_idx = 0;
        p->p_head->blocks = blocks;
        p->p_head->blksz  = blksz;
        //初始化后段
        p->p_payload = (char*)(p->p_head+1);
        p->shmid = shmid;
        p->sem_mutex = semget(key,   1, IPC_CREAT|0644);
        p->sem_empty = semget(key+1, 1, IPC_CREAT|0644);
        p->sem_full  = semget(key+2, 1, IPC_CREAT|0644);

        semun su = {1}; //设置互斥信号量初值为1
        semctl(p->sem_mutex, 0, SETVAL, su);

        su.val = blocks;
        semctl(p->sem_empty, 0, SETVAL, su);

        su.val = 0; //初始不能消费
        semctl(p->sem_full, 0, SETVAL, su);
    }
    else   //内存段存在 ,打开
    {
        p->p_head = shmat(shmid, NULL, 0);
        p->p_payload = (char*)(p->p_head+1);
        p->shmid = shmid;
        p->sem_mutex = semget(key,   0, 0);
        p->sem_empty = semget(key+1, 0, 0);
        p->sem_full  = semget(key+2, 0, 0);
    }
    return p;
}

static void P(int id)
{
    struct sembuf sb[1] = {0,-1, 0};
    semop(id, sb, 1);
}

static void V(int id)
{
    struct sembuf sb[1] = {0, 1, 0};
    semop(id, sb, 1);
}

// 放入数据
void shmfifo_put(shmfifo_t *fifo, const void *buf)
{
    P(fifo->sem_empty);  // 确保有空位生产
    P(fifo->sem_mutex);  // 保证进程互斥
    memcpy(fifo->p_payload + fifo->p_head->wr_idx * fifo->p_head->blksz, // 寻址到写入位置
           buf,
           fifo->p_head->blksz);  // 写入数据长度保护

    fifo->p_head->wr_idx = (fifo->p_head->wr_idx+1) % fifo->p_head->blocks;  // 循环数组

    V(fifo->sem_full);
    V(fifo->sem_mutex);
}

// 取得数据
void shmfifo_get(shmfifo_t* pFifo, void *buf)
{
    P(pFifo->sem_full);  //确保有数据可取
    P(pFifo->sem_mutex);
    //从内存段读取，拷入buf中
    memcpy(buf,
           pFifo->p_payload + pFifo->p_head->rd_idx* pFifo->p_head->blksz,
           pFifo->p_head->blksz);

    pFifo->p_head->rd_idx = (pFifo->p_head->rd_idx+1)
                            %pFifo->p_head->blocks;  //取模，保证数据存满时，转从payload处取数据

    V(pFifo->sem_empty);
    V(pFifo->sem_mutex);
}

// 销毁
void shmfifo_destroy(shmfifo_t* pFifo)
{
    shmdt(pFifo->p_head);  //取消内存段挂载
    shmctl(pFifo->shmid, IPC_RMID, 0); //释放掉该内存段
    //删除信号量
    semctl(pFifo->sem_mutex, 0, IPC_RMID, 0);
    semctl(pFifo->sem_empty, 0, IPC_RMID, 0);
    semctl(pFifo->sem_full, 0, IPC_RMID, 0);

    free(pFifo);
}