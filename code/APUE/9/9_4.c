#include<apue.h>

static void pr_ids(char *name)
{
	printf("%s: pid = %ld, ppid = %ld, pgrp = %ld, tpgrp = %ld\n", name, (long)getpid(), (long)getppid(), (long)getpgrp(), (long)tcgetpgrp(STDIN_FILENO));
	fflush(stdout);
}
int main()
{
	pid_t pid = fork();
	{
		if(pid == 0)
		{
			pr_ids("before");
			sleep(3);
			pr_ids("after");
		}
	}
}

