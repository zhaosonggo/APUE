#include<apue.h>

void print_id(const char *str)
{
	printf("%s: my pid: %d, my gid: %d, my sid: %d\n", str, getpid(), getpgid(0), getsid(0));
}


int main()
{
	print_id("parent");
	pid_t pid = fork();
	if(pid == 0)
	{
		print_id("before setsid");
		pid = setsid();
		printf("pid = %d\n", pid);
		print_id("after setsid");
	}
	else
	{
		sleep(5);
	}
	return 0;
}



