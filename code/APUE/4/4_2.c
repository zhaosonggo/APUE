#include<apue.h>

int main()
{
	printf("%ld\n", pathconf("/home/zhaosong", _PC_CHOWN_RESTRICTED));
	return 0;
}



