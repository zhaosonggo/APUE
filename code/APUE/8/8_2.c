#include<apue.h>


int main()
{
	int fd = open("tmp.txt", O_RDWR);
	if(fd == -1)
		err_exit("open");
	
	pid_t pid = fork();
	
	if(pid == 0)
	{
		write(fd, "&&&", 3);
	}
	else
	{
		sleep(2);
		write(fd, "---", 3);
	}
	return 0;
}



