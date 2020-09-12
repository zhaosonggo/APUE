#include<apue.h>
#include<time.h>
#include<sys/time.h>

int main()
{
/*	struct timespec mtime;*/
/*	int ret = clock_getres(CLOCK_REALTIME, &mtime);*/
/*	printf("精度:  %lds,  %ldns\n", mtime.tv_sec, mtime.tv_nsec);*/

	time_t t;
	struct tm *tmp;
	char buf1[16];
	char buf2[64];
	
	time(&t);
	
	tmp = localtime(&t);
	if(strftime(buf1, 16, "time and date:%r, %a, %b, %d, %Y", tmp) == 0)
		printf("too small\n");
	if(strftime(buf2, 64, "time and date:%r, %a, %b, %d, %Y", tmp) == 0)
		printf("too small\n");
	else
		printf("%s\n", buf2);
	return 0;
}




