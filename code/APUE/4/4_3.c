#include<apue.h>


int main()
{
	struct stat mystat;
	stat("./4_3.c", &mystat);
	printf("%ld\n", mystat.st_blksize);
	return 0;
}


