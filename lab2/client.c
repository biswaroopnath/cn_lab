#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>
#include <sys/types.h>
#include <sys/socket.h>
#include <arpa/inet.h>
#include <netinet/in.h>
#define PORT 8080
#define MAXLINE 100
	
int main() {
	int sockfd;
	char buffer[MAXLINE];
	struct sockaddr_in servaddr;
	
	if ( (sockfd = socket(AF_INET, SOCK_DGRAM, 0)) < 0 ) {
		perror("socket creation failed");
		exit(EXIT_FAILURE);
	}
	
	memset(&servaddr, 0, sizeof(servaddr));
	servaddr.sin_family = AF_INET;
	servaddr.sin_port = htons(PORT);
	servaddr.sin_addr.s_addr = INADDR_ANY;
		
    while(1) {
        int n, len;
		bzero(buffer, MAXLINE);
		printf("To server: ");
		n = 0;
		while ((buffer[n++] = getchar()) != '\n')
			;

		sendto(sockfd, buffer, strlen(buffer), MSG_CONFIRM, (const struct sockaddr*)&servaddr, sizeof(servaddr));
		if (strncmp("exit", buffer, 4) == 0) {
            printf("Server Exit...\n");
            break;
        }
		n = 0;
		bzero(buffer, MAXLINE);
		n = recvfrom(sockfd, (char *)buffer, MAXLINE, MSG_WAITALL, (struct sockaddr*)&servaddr, &len);
		buffer[n] = '\0';
	    printf("Server : %s", buffer);
		if (strncmp("exit", buffer, 4) == 0) {
            printf("Server Exit...\n");
            break;
        }
		bzero(buffer, MAXLINE);
    }    
	
	close(sockfd);
	return 0;
}
