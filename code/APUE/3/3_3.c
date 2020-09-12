#include<apue.h>


int main()
{
	int fd = open("./tmp.txt", O_RDWR);
	pid_t pid = fcntl(fd, F_GETOWN);
	printf("pid: %d\n", pid);
	return 0;
}


