#include<apue.h>


int main()
{
	printf("NZERO: %ld\n", sysconf(_SC_NZERO));
	errno = 0;
	int rv = nice(1);
	if(rv == -1 && errno != 0)
	{
		perror("nice");
	}
	printf("%d\n", rv);
	
	return 0;
}



