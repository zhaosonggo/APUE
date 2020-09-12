#include<apue.h>



int main()
{
	int fd = open("./block", O_RDWR|O_CREAT, 0644);
	struct stat mystat;
	
	if(fd == -1)
		err_exit("open");
	fstat(fd, &mystat);
	printf("%ld\n", mystat.st_size);
	off_t off = lseek(fd, 10000000, SEEK_END);
	printf("off:%ld\n", off);
	write(fd, "0", 1);
	printf("%ld\n", mystat.st_size);
	off = lseek(fd, 0, SEEK_SET);
	printf("off:%ld\n", off);
	printf("%ld\n", mystat.st_size);
	
	
	char buf[4096];
	
	int ret = read(fd, buf, 100);
	printf("ret: %d\n", ret);
	printf("%s\n", buf);
	printf("%c\n", 0);
	return 0;
}



