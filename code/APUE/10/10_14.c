#include<apue.h>
int main()
{
    int i = 1;
    while(_sys_siglist[i] != NULL)
        printf("%d: %s\n", i-1, _sys_siglist[i++]);
    return 0;
}