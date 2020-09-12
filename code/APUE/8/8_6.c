#include<apue.h>

extern char **environ;
int main()
{
	//1.
	int ret = execl("/bin/ls", "ls", "-l", "-a", NULL);
	if(-1 == ret)
		err_exit("execl");		
	//2.
	char *argv[] = {"ls", "-l", "-a", NULL};
	int ret = execv("/bin/ls", argv);
	if(-1 == ret)
		err_exit("execv");
	//3
	int ret = execle("/bin/ls", "ls", "-l", "-a", NULL, environ);
	if(-1 == ret)
		err_exit("execle");
	//4
	char *argv[] = {"ls", "-l", "-a", NULL};
	int ret = execve("/bin/ls", argv, environ);
	if(-1 == ret)
		err_exit("execve");
	//5
	int ret = execlp("ls", "ls", "-l", "-a", NULL);
	if(-1 == ret)
		err_exit("execlp");
	//6
	char *argv[] = {"ls", "-l", "-a", NULL};
	int ret = execvp("ls", argv);
	if(ret == -1)
		err_exit("execvp");
	return 0;
}



