#include<apue.h>


static void sig_quit(int signo)
{
	static int i = 0;
	int j = 0;
	while(j<5)
	{
		printf("%d ", i);
		sleep(1);
		++j;
	}
	++i;
	printf("\n");
}



int main()
{
	sigset_t mask;
	sigemptyset(&mask);
	struct sigaction myact;
	myact.sa_mask = mask;
	myact.sa_handler = sig_quit;
	myact.sa_flags = 0;
	
	sigaction(SIGQUIT, &myact, NULL);
	while(1)
	{
		
	}
	return 0;
}


