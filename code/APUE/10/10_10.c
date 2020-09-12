#include<apue.h>

int main()
{
    sigset_t myset;
    sigemptyset(&myset);
    sigaddset(&myset, SIGABRT);
    sigprocmask(SIG_BLOCK, &myset, NULL);
    print_mask("set mask");
    print_block("before while");
    while(1)
    {
        sleep(3);
        print_block("in while");
    }
    return 0;
}