#include<apue.h>

void print_id(const char *str)
{
	printf("%s: My pid: %d, My ppid: %d, My gid: %d\n", str, getpid(), getppid(), getpgid(0));
}

int main()
{
	print_id("parent");
	pid_t pid = fork();
	if(pid == 0)
	{
		print_id("first child before");
		sleep(2);
		print_id("first child after");
		pid = fork();
		if(pid == 0)
		{
			print_id("second child before");
			sleep(2);
			print_id("second child after");
		}
		else
		{
			sleep(1);
			setpgid(pid, 0);
			sleep(3);
		}
	}
	else
	{
		sleep(1);
		setpgid(pid, 0);
		sleep(10);
	}
	return 0;
}




