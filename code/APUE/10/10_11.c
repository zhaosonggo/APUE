#include<apue.h>

void myabort(void)
{
    sigset_t mask;
    struct sigaction action;
    /*信号的处理方式不可以设置为忽略，如果是，就设置为默认动作*/
    sigaction(SIGABRT, NULL, &action);
    if(action.sa_handler == SIG_IGN)
    {
        action.sa_handler = SIG_DFL;
        sigaction(SIGABRT, &action, NULL);
    }
    if(action.sa_handler == SIG_DFL)
        fflush(NULL);
    
    /*该信号不可以被阻塞*/
    sigfillset(&mask);
    sigdelset(&mask, SIGABRT);
    sigprocmask(SIG_SETMASK, &mask, NULL);
    kill(getpid(), SIGABRT); //raise(SIGABRT)
    //如果设置了捕获函数，这里将会被捕获函数捕捉，如果没有设置，则会执行默认动作，终止进程

    fflush(NULL);  //可以到达这里，说明设置了捕捉函数，且捕捉函数没有退出进程
    action.sa_handler = SIG_DFL;
    sigaction(SIGABRT, &action, NULL);
    sigprocmask(SIG_SETMASK, &mask, NULL);  //just in case
    kill(getpid(), SIGABRT);
    exit(1); //this should never be executed
}
