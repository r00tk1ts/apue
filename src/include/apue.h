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

#define MAXLINE 4096    // 最大行尺寸

void err_msg(const char *, ...);
void err_dump(const char *, ...) __attribute__((noreturn));
void err_quit(const char *, ...) __attribute__((noreturn));
void err_cont(int, const char *, ...);
void err_exit(int, const char *, ...) __attribute__((noreturn));
void err_ret(const char *, ...);
void err_sys(const char *, ...) __attribute__((noreturn));

#endif /* _APUE_H */