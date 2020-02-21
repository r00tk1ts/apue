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