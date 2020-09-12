#include<apue.h>

int main()
{
	FILE *fp = fopen("./tmp.txt", "r+");
	fprintf(fp, "zhaosong");
	fseek(fp, 0, SEEK_END);
	fprintf(fp, "songzhao");
	return 0;
}




