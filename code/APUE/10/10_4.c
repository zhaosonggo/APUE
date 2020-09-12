#include<apue.h>
#include<signal.h>


int main()
{
	sigset_t myset, oldset;
	sigemptyset(&myset);
	
	sigaddset(&myset, SIGPIPE);
	
	sigprocmask(SIG_BLOCK, &myset, &oldset);
	int ret = kill(getpid(), SIGPIPE);
	printf("ret = %d\n", ret);
	return 0;
}
