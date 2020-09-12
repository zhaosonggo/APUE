#include<apue.h>


int main()
{
	FILE *fp = fopen("./log.txt", "w");
	char buff[100];
	
	while(1)
	{
		int len = fprintf(fp, "pid: %d, gid: %d\n", getpid(), getpgid(0));
		fflush(fp);
		sleep(1);
	}
	return 0;
}



