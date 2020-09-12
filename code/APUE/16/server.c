#include<apue.h>
#include<arpa/inet.h>
#include<sys/socket.h>

#define SERV_IP "127.0.0.1"
#define SERV_PORT 9999


int main()
{
	int sockfd = socket(AF_INET, SOCK_STREAM, 0);
	struct sockaddr_in serv_addr, tmp_addr;
	memset(&serv_addr, sizeof(serv_addr), 0);
	
	serv_addr.sin_family = AF_INET;
	serv_addr.sin_port = htons(SERV_PORT);
	inet_pton(AF_INET, SERV_IP, &serv_addr.sin_addr.s_addr);
	
	int ret = bind(sockfd, (struct sockaddr *)&serv_addr, sizeof(serv_addr));
	
	if(ret == -1)
	{
		perror("bind");
		exit(EXIT_FAILURE);
	}
	
	if(listen(sockfd, 128) == -1)
	{
		perror("listen");
		exit(EXIT_FAILURE);
	}
	socklen_t len = sizeof(tmp_addr);
	getsockname(sockfd, (struct sockaddr *)&tmp_addr, &len);
	char buff[2014];
	printf("bind IP: %s, PORT: %d\n", inet_ntop(AF_INET, &tmp_addr.sin_addr.s_addr, buff, sizeof(buff)), ntohs(tmp_addr.sin_port));
	sleep(5);
	while(1)
	{
		int fd = accept(sockfd, NULL, NULL);
	}
}








