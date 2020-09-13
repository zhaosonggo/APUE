#include<apue.h>

typedef void (*fp)(const char *);

void show_1(const char *str)
{
    printf("show1: %s\n", str);
}

void show_2(const char *str)
{
    printf("show2: %s\n", str);
}


void sig_alrm(int signo, siginfo_t *info, void *p)
{
    ((fp)(info->si_value.sival_ptr))("get signal");
}


int main(void)
{
    struct sigaction newact;
    newact.sa_sigaction = sig_alrm;
    sigemptyset(&newact.sa_mask);
    newact.sa_flags = SA_SIGINFO;
    sigaction(SIGRTMIN, &newact, NULL);

    union sigval sv1, sv2;
    sv1.sival_ptr = show_1;
    sv2.sival_ptr = show_2;
    sigset_t set, oset;
    sigemptyset(&set);
    sigaddset(&set, SIGRTMIN);
    sigprocmask(SIG_BLOCK, &set, &oset);
    sigqueue(getpid(), SIGRTMIN, sv2);
    sigqueue(getpid(), SIGRTMIN, sv1);
    sigprocmask(SIG_SETMASK, &oset, NULL);
    return 0;
}






