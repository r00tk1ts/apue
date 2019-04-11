/**
 * @file 异常处理包裹函数，源于libapue
 *
 * 该文件封装了一众错误处理函数
 *
 * @author Steve & r00tk1t
 *
 */
#include "apue.h"
#include <errno.h>		/* errno定义 */
#include <stdarg.h>		/* ISO C 变量参数 */

static void err_doit(int, int, const char *, va_list);

/**
 * @brief 打印消息并返回
 * 
 * 可在系统调用遇到非严重错误时调用
 * 
 * @param fmt	格式化字符串
 */
void
err_ret(const char *fmt, ...)
{
	va_list ap;
	
	va_start(ap, fmt);
	err_doit(1, errno, fmt, ap);
	va_end(ap);
}

/**
 * @brief 打印消息并终止进程
 * 
 * 可在系统调用遇到严重错误时调用。这意味着应用程序理应终止，继续下去则行为是未预测的
 * 
 * @param fmt	格式化字符串
 */
void 
err_sys(const char *fmt, ...)
{
	va_list ap;
	
	va_start(ap, fmt);
	err_doit(1, errno, fmt, ap);
	va_end(ap);
	exit(1);	// 进程退出码是硬编码的1
}

/**
 * @brief 打印消息并返回
 * 
 * 可在系统调用遇到非严重错误时调用，该函数与err_ret的区别在于其显式地传入errno
 * 
 * @param error	传入的errno
 * @param fmt	格式化字符串
 */
void 
err_cont(int error, const char *fmt, ...)
{
	va_list ap;
	
	va_start(ap, fmt);
	err_doit(1, error, fmt, ap);
	va_end(ap);
}

/**
 * @brief 打印消息并终止进程
 * 
 * 可在系统调用遇到严重错误时调用，该函数与err_sys的区别在于其显式地传入errno
 * 
 * @param error	传入的errno
 * @param fmt	格式化字符串
 */
void 
err_exit(int error, const char *fmt, ...)
{
	va_list ap;
	
	va_start(ap, fmt);
	err_doit(1, error, fmt, ap);
	va_end(ap);
	exit(1);
}

/**
 * @brief 打印消息、完成核心转储(core dump)，并终止进程
 * 
 * 可在系统调用遇到严重错误时调用，该函数会调用abort()
 * 
 * @param fmt	格式化字符串
 */
void 
err_dump(const char *fmt, ...)
{
	va_list ap;
	
	va_start(ap, fmt);
	err_doit(1, errno, fmt, ap);
	va_end(ap);
	abort();	// 核心转储并终止
	exit(1);	// abort()不会返回，所以不该走到这里，这里只是上了个保险
}

/**
 * @brief 打印消息并返回
 * 
 * 可在系统调用遇到非严重错误时调用，该函数不会传递errno
 * 
 * @param fmt	格式化字符串
 */
void 
err_msg(const char *fmt, ...)
{
	va_list ap;
	
	va_start(ap, fmt);
	err_doit(0, 0, fmt, ap);
	va_end(ap);
}

/**
 * @brief 打印消息并终止进程
 * 
 * 可在系统调用遇到严重错误时调用，该函数不会传递errno
 * 
 * @param fmt	格式化字符串
 */
void 
err_quit(const char *fmt, ...)
{
	va_list ap;
	
	va_start(ap, fmt);
	err_doit(0, 0, fmt, ap);
	va_end(ap);
	exit(1);
}

/**
 * @brief 打印消息并返回
 *
 * 由调用者指定"errnoflag", 一众错误处理函数的核心
 *
 * @param errnoflag 是否传入有效的errno
 * @param error		传入的errno值
 * @param fmt		待输出格式化字符串
 * @param ap		可变格式化参数列表
 */
static void 
err_doit(int errnoflag, int error, const char *fmt, va_list ap)
{
	char buf[MAXLINE];

	vsnprintf(buf, MAXLINE-1, fmt, ap);
	if(errnoflag)
		snprintf(buf+strlen(buf), MAXLINE-strlen(buf)-1, ": %s", strerror(error));
	strcat(buf, "\n");
	fflush(stdout);	// 处理stdout和stderr相同的情景 
	fputs(buf, stderr);
	fflush(NULL);	// 刷新所有stdio输出流
}