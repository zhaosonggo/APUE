#include<apue.h>
static void charatatime(const char *str)
{
	char *ptr;
	int c;
	setbuf(stdout, NULL);
	for(ptr=str; (c=*ptr++)!= 0;)
	{
		putc(c, stdout);
	}
}


int main()
{
	pid_t pid;
	if((pid = fork()) < 0)
		err_exit("fork");
	else
	{
		if(pid == 0)
		{
			charatatime("output for child\n");
		}
		else
		{
			charatatime("output for parent\n");
		}
	}
	exit(0);
	return 0;
}



