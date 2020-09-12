#include<apue.h>
#include<sys/wait.h>

int main()
{
	int ret = wait(NULL);
	printf("%d\n", ret);
	return 0;
}



