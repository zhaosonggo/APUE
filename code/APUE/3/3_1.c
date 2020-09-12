#include<apue.h>


int main()
{
	//测试一下路径和文件名长度限制
	printf("path_max: %ld\n", pathconf("/", _PC_PATH_MAX));
	printf("name_max: %ld\n", pathconf("/", _PC_NAME_MAX));
	
	//测试creat可不可以创建已经存在的文件
/*	int fd1 = creat("./tmp.txt", 0777);*/
/*	int fd2 = creat("./tmp.txt", 0777);*/
/*	printf("fd1: %d, fd2: %d\n", fd1, fd2);*/
	
	//测试一下read会不会自动添加字符串结束标志:不会
/*	char buf[4] = {1, 1, 1, 1};*/
/*	int i = 0;*/
/*	while(i<4)*/
/*	{*/
/*		printf("%d ", buf[i++]);*/
/*	}*/
/*	printf("\n");*/
/*	i = 0;*/
/*	read(STDIN_FILENO, buf, 1);*/
/*	while(i<4)*/
/*	{*/
/*		printf("%d ", buf[i++]);*/
/*	}*/
/*	printf("\n");*/
/*	printf("%s\n", buf);*/
	
	//测试O_APPEND打开一个文件后的读行为:每次写之后，指针都会指向末尾，此时读不到任何东西
	int fd1 = open("./tmp.txt", O_RDWR|O_APPEND);
	if(fd1 == -1)
		err_exit("open");
	char buf[12];
	int ret;
	ret = lseek(fd1, 0, SEEK_CUR);
	printf("ret: %d\n", ret);
	ret = write(fd1, "nihao", strlen("nihao"));
	if(ret < strlen("nihao"))
		err_exit("write");
	ret = lseek(fd1, 0, SEEK_CUR);
	printf("ret: %d\n", ret);
	ret = read(fd1, buf, 3);
	printf("%d: %s\n", ret, buf);
	return 0;
}




