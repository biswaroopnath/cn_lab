#include<stdio.h>
#include<sys/types.h>
#include<sys/socket.h>
#include<netinet/in.h>
#include<arpa/inet.h>
#include<fcntl.h>
#include<string.h>

// Driver code
int main()
{
	int socket_desc, client_sock1, client_sock2, length, i, flag=0;
	char buf1[100], buf2[100], mes[100]; /* We will use this buffer for communication */
	struct sockaddr_in server, client;

	// Driver code
	socket_desc = socket(AF_INET,SOCK_STREAM,0);

	// Prepare the sockaddr_in structure
	server.sin_family=AF_INET;
	server.sin_addr.s_addr=INADDR_ANY;
	server.sin_port=60018;

	// Bind the socket
	i=bind(socket_desc, (struct sockaddr *)&server, sizeof(server));
	printf("test %d%d\n",socket_desc, i);

	// listen to the socket
	listen(socket_desc, 5);

	length=sizeof(socket_desc);
	
	// accept connection from an incoming client
	client_sock1 = accept(socket_desc, (struct sockaddr *) &client, &length);
	client_sock2 = accept(socket_desc, (struct sockaddr *) &client, &length);

	for(i=0; i < 100; i++) 
	{
		buf1[i] ='\0';
		buf2[i] = '\0';
		mes[i] ='\0';
	}
	strcpy(mes,"logoff");

	while(flag == 0)
	{
		for(i=0; i < 100; i++){
			buf1[i] = '\0';
			buf2[i] = '\0';
		}
		
		// Receive a message from client
		recv(client_sock1, buf1, 100, 0);
		recv(client_sock2, buf2, 100, 0);
		printf("Client 1 sent: %s\n", buf1);
		printf("Client 2 sent: %s\n", buf2);
			
		//Sending message to the client	
		send(client_sock1, buf2, 100, 0);
		send(client_sock2, buf1, 100, 0);
		
		if((strcmp(buf1, mes) == 0) || (strcmp(buf2, mes) == 0)) {
		 	flag = 1;
		 	break;
		}
	}
	close(client_sock1);
	close(client_sock2);
	return 0;
}

