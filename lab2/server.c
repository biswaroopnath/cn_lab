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
	struct sockaddr_in servaddr, cliaddr;
		
	if ( (sockfd = socket(AF_INET, SOCK_DGRAM, 0)) < 0 ) {
		perror("socket creation failed");
		exit(EXIT_FAILURE);
	}
		
	memset(&servaddr, 0, sizeof(servaddr));
	memset(&cliaddr, 0, sizeof(cliaddr));
	servaddr.sin_family = AF_INET;
	servaddr.sin_addr.s_addr = INADDR_ANY;
	servaddr.sin_port = htons(PORT);
		
	if ( bind(sockfd, (const struct sockaddr *)&servaddr, sizeof(servaddr)) < 0 ) {
		perror("bind failed");
		exit(EXIT_FAILURE);
	}
		
    while(1) {
        int len, n;
        len = sizeof(cliaddr);
	
	    n = recvfrom(sockfd, (char *)buffer, MAXLINE, MSG_WAITALL, ( struct sockaddr*) &cliaddr, &len);
	    buffer[n] = '\0';
	    printf("Client : %s", buffer);
        if (strncmp("exit", buffer, 4) == 0) {
            printf("Server Exit...\n");
            break;
        }
		bzero(buffer, MAXLINE);
        n = 0;
        printf("To client: ");
        while ((buffer[n++] = getchar()) != '\n')
            ;
        sendto(sockfd, buffer, strlen(buffer),
        MSG_CONFIRM, (const struct sockaddr *)&cliaddr, len);
        if (strncmp("exit", buffer, 4) == 0) {
            printf("Server Exit...\n");
            break;
        }
        bzero(buffer, MAXLINE);
        n = 0;
    }
    close(sockfd);
    return 0;
}
