#include<apue.h>

extern char **environ;

int main(int argc, char **argv)
{
	printf("%p\n", environ);
	putenv("zhaosong=limiaomiao");
	printf("%p\n", environ);
	int i=0;
	while(environ[i]!=NULL)
		printf("%p\n", environ[i++]);
	return 0;
}


