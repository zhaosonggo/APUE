#include<apue.h>
#include<signal.h>
#include<setjmp.h>


static jmp_buf env_alrm;

static void sig_alrm(int signo)
{
	longjmp(env_alrm, 1);
}

unsigned int sleep2(unsigned int seconds)
{
	if(signal(SIGALRM, sig_alrm) == SIG_ERR)
		return seconds;
	if(setjmp(env_alrm) == 0)
	{
		alarm(seconds);
		pause();
	}	
	return alarm(0);
}
int main(void)
{
	print_mask("main");
	print_block("main");
	
	sigset_t set;
	sigemptyset(&set);
	sigaddset(&set, SIGALRM);
	sigaddset(&set, SIGPIPE);
	sigprocmask(SIG_SETMASK, &set, NULL);
	
	print_mask("main");
	print_block("main");
	
	kill(getpid(), SIGALRM);
	print_mask("main");
	print_block("main");
	kill(getpid(), SIGPIPE);
	print_mask("main");
	print_block("main");
	signal(SIGALRM, SIG_IGN);
	print_mask("main");
	print_block("main");
	kill(getpid(), SIGALRM);
	print_mask("main");
	print_block("main");
	return 0;
}







