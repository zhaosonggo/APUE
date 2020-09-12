#include<apue.h>


int main()
{
	printf("时钟滴答/s: %ld\n", sysconf(_SC_CLK_TCK));
}







