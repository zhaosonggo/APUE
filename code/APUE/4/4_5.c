#include<apue.h>


int main()
{
	int ret = link("/home/zhaosong/WorkSpace/APUE/4/sl", "/home/zhaosong/WorkSpace/APUE/4/sll");
	if(ret == -1)
	{
		err_exit("link");
	}
	else
	{
		printf("link success\n");
	}
	return 0;
}



