#include<stdio.h>
#include<sys/types.h>
#include<sys/socket.h>
#include<netinet/in.h>
#include<arpa/inet.h>
#include<fcntl.h>
#include<string.h>

int main() {
	int socket_desc, client_sock1, length, i, flag=0;
    struct sockaddr_in server, client;

    socket_desc = socket(AF_INET,SOCK_STREAM,0);
	server.sin_family=AF_INET;
	server.sin_addr.s_addr=INADDR_ANY;
	server.sin_port=60018;

	i = bind(socket_desc, (struct sockaddr *)&server, sizeof(server));
	printf("test %d %d\n",socket_desc, i);
	listen(socket_desc, 2);
	length = sizeof(socket_desc);
	
	client_sock1 = accept(socket_desc, (struct sockaddr *) &client, &length);

	int n1, n2, ans;
	recv(client_sock1, &n1, sizeof(n1), 0);
	recv(client_sock1, &n2, sizeof(n2), 0);
	printf("Client number 1: %d\n", n1);
	printf("Client number 2: %d\n", n2);
	ans = n1 * n2;
	send(client_sock1, &ans, sizeof(ans), 0);

	close(client_sock1);
	return 0;
}
