#include<apue.h>
#include<sys/socket.h>
#include<arpa/inet.h>

#define SERV_IP "127.0.0.1"
#define SERV_PORT 9999


int main()
{
	int sockfd = socket(AF_INET, SOCK_STREAM, 0);  //tcp
	struct sockaddr_in serv_addr, conn_addr;
	memset(&serv_addr, sizeof(struct sockaddr_in), 0);
	memset(&conn_addr, sizeof(struct sockaddr_in), 0);
	serv_addr.sin_family = AF_INET;
	serv_addr.sin_port = htons(SERV_PORT);
	int i = inet_pton(AF_INET, SERV_IP, &serv_addr.sin_addr.s_addr);
	printf("i%d\n", i);
	
	int ret = connect(sockfd, (struct sockaddr *)&serv_addr, sizeof(serv_addr));
	if(ret == -1)
	{
		perror("connect");
		exit(EXIT_FAILURE);
	}
	socklen_t len = sizeof(conn_addr);
	if(getpeername(sockfd, (struct sockaddr *)&conn_addr, &len) == -1)
	{
		perror("getpeername");
		exit(EXIT_FAILURE);
	}
	char buff[1024];
	printf("connect IP: %s, PORT: %d\n", inet_ntop(AF_INET, &conn_addr.sin_addr.s_addr, buff, sizeof(buff)), ntohs(conn_addr.sin_port));
	sleep(5);
	return 0;
}





