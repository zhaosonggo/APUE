#include<apue.h>


int main()
{
	printf("start\n");
	pid_t pid = vfork();
	
	if(pid == 0)
	{
		printf("child\n");
		fclose(stdout);
		exit(0);
	}
	else
	{
		sleep(2);
		printf("father\n");
	}
	return 0;
}


