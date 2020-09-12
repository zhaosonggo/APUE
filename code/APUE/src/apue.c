#include<apue.h>
void err_exit(const char *err)
{
	perror(err);
	exit(EXIT_FAILURE);
}
void err_warn(const char *err)
{
	perror(err);
}
void err(const char *str)
{
	printf("%s\n", str);
}
void set_fl(int fd, int flags)
{
	int val;
	if((val = fcntl(fd, F_GETFL, 0)) < 0)
		err_exit("set_fl");
	val |= flags;
	
	if(fcntl(fd, F_SETFL, val) < 0)
		err_exit("set_fl");
}
void clr_fl(int fd, int flags)
{
	int val;
	if((val = fcntl(fd, F_GETFL, 0)) < 0)
		err_exit("clr_fl");
	val &= ~flags;
	
	if(fcntl(fd, F_SETFL, val) < 0)
		err_exit("clr_fl");
}

// 将字符串的IP转化成主机存储的32位无符号整数
uint32_t iptonum(const char *IP)
{
	uint32_t bs = 256*256*256;
	uint32_t re = 0;
	
	size_t len = strlen(IP);  //得到IP字符串的长度
	const char *p, *q;
	p = IP;
	q = IP;
	while(1)
	{
		if(*q != '.' && *q != 0)
			q += 1;
		else
		{
			const char *x = q-1;
			int num = 0;
			int de = 1;
			while(x >= p)
			{
				num += (*x - '0') * de;
				de *= 10;
				x -= 1;
			}
			++q;
			p = q;
			printf("num :%d\n", num);
			re += num * bs;
			bs = bs / 256;
			if(bs == 0)
				break;
		}
	}
	return re;
}

#define MAXSLEEP 128
//不兼容，有的平台，在connect出错后，套接字会变成未定义状态
int connect_retry(int sockfd, const struct sockaddr *addr, socklen_t alen)
{
	int numsec;
	for(numsec = 1;numsec <= MAXSLEEP; numsec <<= 1)
	{
		if(connect(sockfd, addr, alen) == 0)
		{
			return 0;
		}
		if(numsec <= MAXSLEEP/2)
			sleep(numsec);
	}
	return -1;
}
//兼容的版本
int connect_retry_t(int domain, int type, int protocal, const struct sockaddr *addr, socklen_t alen)
{
	int numsec, fd;
	for(numsec = 1; numsec <= MAXSLEEP; numsec <<= 1)
	{
		if((fd = socket(domain, type, protocal)) < 0)
			return -1;
		if(connect(fd, addr, alen) == 0)
			return fd;
		close(fd);
		if(numsec <= MAXSLEEP/2)
			sleep(numsec);
	}
	return -1;
}
int initserver(int type, const struct sockaddr *addr, socklen_t alen, int qlen)
{
	int fd;
	int err = 0;
	if((fd = socket(addr->sa_family, type, 0)) < 0)
		return -1;
	if(bind(fd, addr, alen) < 0)
		goto errout;
	if(type == SOCK_STREAM || type == SOCK_SEQPACKET)
	{
		if(listen(fd, qlen) < 0)
			goto errout;
	}
	return fd;

errout:
	err = errno;
	close(fd);
	errno = err;
	return -1;
}

//打印一只青蛙
#define F_BUF 128
void print_frog(void)
{
	const char *pathname = "/home/zhaosong/WorkSpace/APUE/file/frog";
	int fd = open(pathname, O_RDWR);	
	if(fd == -1)
		err_exit("open");
	else
	{
		int n;
		char buf[F_BUF];
		while((n = read(fd, buf, F_BUF)) > 0)
			write(STDOUT_FILENO, buf, n);
		if(n < 0)
			err_exit("read");
	}
}

void print_mask(const char *str)
{
	sigset_t set;
	printf("%s mask:\n\t", str);
	if(sigprocmask(0, NULL, &set) < 0)
		err("sigprocmask error");
	else
	{
		for(int i = 1;i<32;++i)
		{
			if(sigismember(&set, i))
			printf("%d", 1);
			else
			printf("%d", 0);
			if(i%5 == 0)
				printf(" ");
		}
		printf("\n");
	}
}
void print_block(const char *str)
{
	sigset_t set;
	printf("%s block:\n\t", str);
	if(sigpending(&set) < 0)
		err("sigpending error");
	else
	{
		for(int i = 1;i<32;++i)
		{
			if(sigismember(&set, i))
			printf("%d", 1);
			else
			printf("%d", 0);
			if(i%5 == 0)
				printf(" ");
		}
		printf("\n");
	}
}




