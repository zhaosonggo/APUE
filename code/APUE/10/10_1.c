#include<apue.h>
#include<signal.h>

void sig_pipe(int signo)
{
	printf("signo: %d catched\n", signo);
}

int main(void)
{
	print_frog();
	sighandler p = signal(SIGPIPE, sig_pipe);
	if(p == SIG_ERR)
	{
		err_exit("signal");
	}
	else
	{
		char buff[1024];
		int n;
		if((n = read(STDIN_FILENO, buff, 1024)) < 0)
		{
			if(errno == EINTR)
				printf("read end by signal");
		}
		else
			printf("%s\n", buff);
	}
	return 0;
}




