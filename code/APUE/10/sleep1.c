#include<apue.h>
#include<signal.h>

static void sig_alrm(int signo)
{
	//...
}

unsigned int sleep_1(unsigned int seconds)
{
	sighandler fp =  signal(SIGALRM, sig_alrm);
	if(fp == SIG_ERR)
		return seconds;
	alarm(seconds);
	pause();
	signal(SIGALRM, fp);
	return (alarm(0));
}


int main(void)
{
	sleep_1(5);
	while(1)
	{
		printf("C++ \n");
		sleep_1(1);
	}
	return 0;
}


