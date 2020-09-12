#ifndef __APUE_H__
#define __APUE_H__

//include file
#include<stdio.h>
#include<stdlib.h>
#include<unistd.h>
#include<string.h>
#include<sys/types.h>
#include<sys/stat.h>
#include<fcntl.h>
#include<errno.h>
#include<dirent.h>
#include<signal.h>
//类型定义
typedef void (*sighandler)(int);

//出错相关
void err_exit(const char *err);
void err_warn(const char *err);

//文件属性相关
void set_fl(int fd, int flags);
void clr_fl(int fd, int flags);

//网络相关
#include<sys/socket.h>
#include<arpa/inet.h>

uint32_t iptonum(const char *IP);
int connect_retry(int sockfd, const struct sockaddr *addr, socklen_t alen);
int connect_retry_t(int domain, int type, int protocal, const struct sockaddr *addr, socklen_t alen);
int initserver(int type, const struct sockaddr *addr, socklen_t alen, int qlen);


//打印
void print_frog(void);
void print_mask(const char *str);
void print_block(const char *str);
#endif
