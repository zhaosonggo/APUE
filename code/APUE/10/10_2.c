// 古老版本的，在古老的版本中，当进入一个信号捕捉函数的时候，信号的处理动作会被重置为默认

#include<apue.h>
#include<signal.h>
#include<sys/wait.h>
static void sig_chld(int);
int main()
{
	pid_t pid;
	if(signal(SIGCHLD, sig_chld) == SIG_ERR)
		perror("signal");
	if((pid = fork()) < 0)
		perror("fork");
	else if(pid == 0)
	{
		sleep(2);
		_exit(0);
	}
	pause();
	exit(0);
}



static void sig_chld(int signo)
{
	pid_t pid;
	int status;
	
	printf("SIGCHLD received\n");
	
	if(signal(SIGCHLD, sig_chld) == SIG_ERR)
		perror("signal");
	if((pid = wait(&status)) < 0)
		perror("wait");
		
	printf("pid = %d\n", pid);
}



