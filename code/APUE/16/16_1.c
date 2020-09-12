#include<apue.h>





int main()
{
	uint32_t re = iptonum("192.168.0.1");
	printf("re: %u\n", re);
	struct sockaddr_in saddr;
	memset(&saddr, sizeof(struct sockaddr_in), 0);
	uint32_t ret = inet_pton(AF_INET, "192.168.0.1", &saddr.sin_addr.s_addr);
	printf("ret: %u\n", re);
	uint32_t nn = ntohl(saddr.sin_addr.s_addr);
	printf("nn: %u\n", nn);
	return 0;
}




