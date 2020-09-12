#include<apue.h>
#include<sys/wait.h>


int main(void)
{
	pid_t pid;
	
	if((pid = fork()) < 0)
	{
		err_exit("fork");
	}
	else
	{
		if(pid == 0)
		{
			if(execl("/home/zhaosong/WorkSpace/APUE/8/testinterp", "testinterp", "my1", "my2", (char*)0) < 0)
				err_exit("execl");
		}
	}
	if(waitpid(pid, NULL, 0) < 0)
		err_exit("waitpid");
	return 0;
}






