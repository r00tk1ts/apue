/**
 * @file libapue的通用头文件
 *
 * 如果使用libapue，请在包含标准系统头文件之前，优先包含该头文件
 *
 * @author Steve & r00tk1t
 *
 */
#ifndef _APUE_H
#define _APUE_H

#include <stdio.h>      // for convenience
#include <stdlib.h>     // for convenience
#include <stddef.h>     // for offsetof
#include <string.h>     // for convenience
#include <unistd.h>     // for convenience
#include <time.h>       // for convenience
#include <sys/stat.h>   // for STAT related
#include <sys/types.h>	// some systems still require this
#include <signal.h>		/* for SIG_ERR */

#define MAXLINE 4096    // 最大行尺寸

// 新文件使用的默认文件权限(644)
#define FILE_MODE (S_IRUSR | S_IWUSR | S_IRGRP | S_IROTH)

// 新目录使用的默认目录权限(755)
#define DIR_MODE (FILE_MODE | S_IXUSR | S_IXGRP | S_IXOTH)

#define	min(a,b)	((a) < (b) ? (a) : (b))
#define	max(a,b)	((a) > (b) ? (a) : (b))

/*
 * Prototypes for our own functions.
 */
char	*path_alloc(size_t *);				/* {Prog pathalloc} */

int		 set_cloexec(int);					/* {Prog setfd} */
void	 clr_fl(int, int);
void	 set_fl(int, int);					/* {Prog setfl} */
void	 pr_exit(int);						/* {Prog prexit} */

void	 pr_mask(const char *);				/* {Prog prmask} */

ssize_t	 readn(int, void *, size_t);		/* {Prog readn_writen} */
ssize_t	 writen(int, const void *, size_t);	/* {Prog readn_writen} */

int		lock_reg(int, int, int, off_t, int, off_t); /* {Prog lockreg} */

#define	read_lock(fd, offset, whence, len) \
			lock_reg((fd), F_SETLK, F_RDLCK, (offset), (whence), (len))
#define	readw_lock(fd, offset, whence, len) \
			lock_reg((fd), F_SETLKW, F_RDLCK, (offset), (whence), (len))
#define	write_lock(fd, offset, whence, len) \
			lock_reg((fd), F_SETLK, F_WRLCK, (offset), (whence), (len))
#define	writew_lock(fd, offset, whence, len) \
			lock_reg((fd), F_SETLKW, F_WRLCK, (offset), (whence), (len))
#define	un_lock(fd, offset, whence, len) \
			lock_reg((fd), F_SETLK, F_UNLCK, (offset), (whence), (len))

pid_t	lock_test(int, int, off_t, int, off_t);		/* {Prog locktest} */

#define	is_read_lockable(fd, offset, whence, len) \
			(lock_test((fd), F_RDLCK, (offset), (whence), (len)) == 0)
#define	is_write_lockable(fd, offset, whence, len) \
			(lock_test((fd), F_WRLCK, (offset), (whence), (len)) == 0)

void err_msg(const char *, ...);
void err_dump(const char *, ...) __attribute__((noreturn));
void err_quit(const char *, ...) __attribute__((noreturn));
void err_cont(int, const char *, ...);
void err_exit(int, const char *, ...) __attribute__((noreturn));
void err_ret(const char *, ...);
void err_sys(const char *, ...) __attribute__((noreturn));

void	TELL_WAIT(void);		/* parent/child from {Sec race_conditions} */
void	TELL_PARENT(pid_t);
void	TELL_CHILD(pid_t);
void	WAIT_PARENT(void);
void	WAIT_CHILD(void);
#endif /* _APUE_H */