#include<apue.h>
#include<setjmp.h>
#include<time.h>

static void sig_usr1(int);
static void sig_alrm(int);

static sigjmp_buf jmpbuf;
static volatile sig_atomic_t canjump;


int main(void)
{
    if(signal(SIGUSR1, sig_usr1) == SIG_ERR)
        err_exit("signal SIGUSR1 error");
    if(signal(SIGALRM, sig_alrm) == SIG_ERR)
        err_exit("signal SIGALRM error:");

    print_mask("starting main");
    if(sigsetjmp(jmpbuf, 1))  //直接使用返回0， 从longjmp返回返回longjmp设置的值
    {
        print_mask("ending main");
        exit(0);
    }
    canjump = 1;
    for(;;)
        pause();
    return 0;
}

static void sig_usr1(int signo)
{
        time_t starttime;
        if(canjump == 0)
            return;
        print_mask("starting sig_usr1");
        alarm(3);
        starttime = time(NULL);
        for(;;)
            if(time(NULL) > starttime + 5)
                break;
        print_mask("finishing sig_usr1");
        canjump = 0;
        siglongjmp(jmpbuf, 1);
}

static void sig_alrm(int signo)
{
    print_mask("in sig_alrm");
}


