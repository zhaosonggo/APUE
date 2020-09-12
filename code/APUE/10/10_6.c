#include<apue.h>




int main()
{
	signal(SIGCHLD, SIG_IGN);
	pid_t pid = fork();
	
	if(pid == 0)
	{
		exit(0);
	}else
	{
		while(1)
		{
		
		}
	}
	return 0;
}


