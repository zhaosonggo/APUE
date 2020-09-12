#include<apue.h>


int main()
{
	int ret = write(3, "this is zhaosong", strlen("this is zhaosong"));
	printf("ret : %d\n", ret);
	return 0;
}




