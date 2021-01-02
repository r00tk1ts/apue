/**
 * @file POSIX信号量-互斥锁实现
 *
 * apue示例程序 - slock.h
 *
 * @author Steve & r00tk1t
 *
 */
#include <semaphore.h>
#include <fcntl.h>
#include <limits.h>
#include <sys/stat.h>

struct slock {
	sem_t *semp;
	char name[_POSIX_NAME_MAX];
};

struct slock * s_alloc();
void s_free(struct slock *);
int s_lock(struct slock *);
int s_trylock(struct slock *);
int s_unlock(struct slock *);
