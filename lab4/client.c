#include<stdio.h>
#include<sys/types.h>
#include<sys/socket.h>
#include<netinet/in.h>
#include<arpa/inet.h>
#include<fcntl.h>
#include<string.h>

int main() {
	int i, sock, flag=0;
	struct sockaddr_in server;

	sock = socket(AF_INET,SOCK_STREAM,0);
	server.sin_family = AF_INET;
	server.sin_addr.s_addr = inet_addr("127.0.0.1");
	server.sin_port = 60018;

	connect(sock, (struct sockaddr *)&server, sizeof(server));

	int n1, n2, ans;
	printf("Number 1: ");
	scanf("%d", &n1);
	printf("Number 2: ");
	scanf("%d", &n2);
	send(sock, &n1, sizeof(n1), 0);
	send(sock, &n2, sizeof(n2), 0);
	recv(sock, &ans, sizeof(ans), 0);
	printf("Server sent: %d\n", ans);

	return 0;
}
