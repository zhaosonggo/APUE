#include<apue.h>


int main()
{
	FILE *fp = fopen("./tmp.txt", "w");
	if(fp == NULL)
		err_exit("fopen");
	fprintf(fp, "hahahah");
	
	pid_t pid = fork();
	
	if(pid == 0)
	{
		sleep(3);
	}
	else
	{
		sleep(2);
	}
	return 0;
}



