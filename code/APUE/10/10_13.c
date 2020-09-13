#include<apue.h>

pid_t pid;
void sig_alrm(int signo)
{
   kill(pid, SIGCONT); 
}

int main()
{
    pid = fork();
    if(pid == 0)
    {
        sigset_t set;
        sigemptyset(&set);
        sigaddset(&set, SIGCONT);
        sigprocmask(SIG_BLOCK, &set, NULL);
        while(1)
        {
            print_block("child");
            sleep(1);
        }
    }
    else
    {
        struct sigaction myaction;
        myaction.sa_handler = sig_alrm;
        myaction.sa_flags = 0;
        sigemptyset(&myaction.sa_mask);

        sigaction(SIGALRM, &myaction, NULL);
        printf("sleep(3), i will send a SIGSTOP to child\n");
        sleep(3);
        kill(pid, SIGSTOP);
        while(1)
        {

        }
    }
    
    return 0;
}




