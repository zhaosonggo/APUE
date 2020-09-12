#include<apue.h>
#include<sys/sysmacros.h>
int main()
{
	struct stat mystat;
	
	stat("./4_7.c", &mystat);
	
	printf("dev=%d/%d\n", major(mystat.st_dev), minor(mystat.st_dev));
	return 0;
}



