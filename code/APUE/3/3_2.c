#include<apue.h>



int main()
{
	int fd = open("./tmp.txt", O_RDWR|O_APPEND);
	
/*	int ret = fcntl(fd, F_DUPFD, fd);*/
	int ret = dup2(fd, 3);
	if(ret == -1)
		err_exit("fcntl");
	printf("ret: %d\n", ret);
	pid_t pid = fork();
	
	if(pid == 0)
	{
		execl("./out", "", NULL);
	}
	else
	{
		sleep(5);
	}
	
	
	return 0;
}



