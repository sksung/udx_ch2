/*
 *  Copyright 2012 by Texas Instruments Incorporated.
 *
 */

/*
 *  ======== syscalls.c ========
 *  Minimal implementation of newlib syscall stub functions.
 *
 */

#include <sys/stat.h>
#include <errno.h>

#undef errno
extern int errno;

char *__env[1] = { 0 };
char **environ = __env;

/*
 *  ======== _close ========
 */
int _close(int file) 
{
    return -1;
}

/*
 *  ======== execve ========
 */
int execve(char *name, char **argv, char **env) 
{
    errno = ENOMEM;
    return -1;
}

/*
 *  ======== _exit ========
 */
void _exit(int code) 
{
    asm(" .global C$$EXIT");
    asm("C$$EXIT:");
    while(1){};
}

/*
 *  ======== _fork ========
 */
int fork(void) 
{
    errno = EAGAIN;
    return -1;
}

/*
 *  ======== _fstat ========
 */
int _fstat(int file, struct stat *st) 
{
    st->st_mode = S_IFCHR;
    return 0;
}

/*
 *  ======== _getpid ========
 */
int _getpid(void) 
{
    return 1;
}

/*
 *  ======== _isatty ========
 */
int _isatty(int file) 
{
    return 1;
}

/*
 *  ======== _kill ========
 */
int _kill(int pid, int sig) 
{
    errno = EINVAL;
    return -1;
}

/*
 *  ======== link ========
 */
int link(char *old, char *new) 
{
    errno = EMLINK;
    return -1;
}

/*
 *  ======== _lseek ========
 */
int _lseek(int file, int ptr, int dir) 
{
    return 0;
}

/*
 *  ======== open ========
 */
int open(const char *name, int flags, int mode) 
{
    return (-1);
}

/*
 *  ======== _read ========
 */
int _read(int file, char *ptr, int len) 
{
    return (0);
}

extern unsigned int __heap_start__;
extern unsigned int __heap_end__;

/*
 *  ======== _sbrk ========
 */
int _sbrk(int incr) 
{
    static int heap_size = 0;
    static char * heap_start;
    static char * heap_end;
    unsigned char * prev_heap_end;

    /* init pointers on first call */
    if (heap_size == 0) {
        heap_start = (char *) & __heap_start__;
        heap_end = heap_start;
        heap_size = ((char *) & __heap_end__) - heap_start;
    }
     
    prev_heap_end = heap_end;

    /* check if not enough remaining heap for request */
    if (heap_end + incr - heap_start > heap_size) {
        errno = ENOMEM;
        return(-1);
    }

    heap_end += incr;

    return ((int)prev_heap_end);
}

/*
 *  ======== times ========
 */
int times(void  *buf) 
{
    return (-1);
}

/*
 *  ======== unlink ========
 */
int unlink(char *name) 
{
    errno = ENOENT;
    return (-1);
}

/*
 *  ======== wait ========
 */
int wait(int *status) 
{
    errno = ECHILD;
    return (-1);
}

/*
 *  ======== _write ========
 */
int _write(int file, char *ptr, int len) 
{
    return (-1);
}

/*
 *  @(#) gnu.targets.arm.rtsv7M; 1, 0, 0, 0,25; 4-27-2012 17:31:34; /db/ztree/library/trees/xdctargets/xdctargets-f21x/src/ xlibrary

 */

