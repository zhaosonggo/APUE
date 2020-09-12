// 主要考察在未决信号集中的信号，如果设置其处理方式位SIG_IGN, 那么其会被会从未决信号集中去除

#include<apue.h>
#include<signal.h>

static void sig_alarm(int signo)
{
	sigset_t oldset;
	static int count = 0;
	count++;
	sigpending(&oldset);
	if(sigismember(&oldset, SIGPIPE))
	{
		printf("sigpipe in the set\n");
	}
	else
	{
		printf("sigpipe not in the set\n");
	}
#ifdef Q
	if(count%5 == 0)   
	{
		printf("count == 5, i will set the SIG_IGN\n");
		siganl(SIGPIPE, SIG_IGN);
	}
#endif
}
int main()
{
	sigset_t myset, oldset;
	sigemptyset(&myset);
	
	sigaddset(&myset, SIGPIPE);
	
	sigprocmask(SIG_BLOCK, &myset, &oldset);
#ifdef W
	signal(SIGPIPE, SIG_IGN);
#endif
	signal(SIGALRM, sig_alarm);
	
	while(1){
		
	}
	return 0;
}


