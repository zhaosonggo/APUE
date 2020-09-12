#include<apue.h>

#include<sys/wait.h>


char *env_init[] = {"USER=赵松", "PATH=/root/", NULL};



int main(void)
{
	pid_t pid;
	if((pid = fork()) < 0)
		err_exit("fork");
	else if(pid == 0)
	{
		if(execle("/home/zhaosong/WorkSpace/APUE/8/echoall", "echoll", "argv1", "argv2", (char*)0, env_init) < 0)
			err_exit("execle");
	}
	if(waitpid(pid, NULL, 0) < 0)
		err_exit("waitpid");
		
	if((pid = fork()) < 0)
		err_exit("fork");
	else if(pid == 0)
	{
		if(execl("/home/zhaosong/WorkSpace/APUE/8/echoall", "echoll", "argv1", "argv2",(char*)0) < 0)
			err_exit("execl");
	}
	if(waitpid(pid, NULL, 0) < 0)
		err_exit("waitpid");
		
	return 0;
}




