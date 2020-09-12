#include<apue.h>

volatile sig_atomic_t quitflag;

static void
sig_int(int signo)
{
    if(signo == SIGINT)
        printf("\ninterrupt\n");
    else
    {
        if(signo == SIGQUIT)
            quitflag = 1;
    }
}

int 
main(void)
{
    sigset_t newmask, oldmask, zeromask;
    if(signal(SIGINT, sig_int) == SIG_ERR)
        err_exit("signal sigint");
    if(signal(SIGQUIT, sig_int) == SIG_ERR)
        err_exit("signal sigquit");
    sigemptyset(&zeromask);
    sigemptyset(&oldmask);
    sigaddset(&newmask, SIGQUIT);
    if(sigprocmask(SIG_BLOCK, &newmask, &oldmask) < 0)
        err_exit("sigblock error");

    while(quitflag == 0)
        sigsuspend(&zeromask);
    quitflag = 0;
    if(sigprocmask(SIG_SETMASK, &oldmask, NULL) < 0)
        err_exit("SIG_SETMASK");

    exit(0);
}








