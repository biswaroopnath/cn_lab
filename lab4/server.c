#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <errno.h>
#include <string.h>
#include <sys/types.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <arpa/inet.h>
#include <netdb.h>
#define SERVERPORT 4952 // the port users will be connecting to
int main()
{
    int sockfd;
    struct sockaddr_in their_addr; // connector's address information
    // struct hostent *he;
    int numbytes;
char arg[30];
    if ((sockfd = socket(AF_INET, SOCK_DGRAM, 0)) == -1)
    {
        perror("socket");
        exit(1);
    }
    their_addr.sin_family = AF_INET;                     // host byte order
    their_addr.sin_port = htons(SERVERPORT);             // short, network byte order
    their_addr.sin_addr.s_addr = inet_addr("127.0.0.1"); // Insert UDP Server IP Address
    // memset(their_addr.sin_zero, '\0', sizeof their_addr.sin_zero);
    printf("Enter the number 1 and num 2  : ");
    scanf("%s", arg);
    if ((numbytes = sendto(sockfd, arg, sizeof(arg), 0, (struct sockaddr *)&their_addr, sizeof their_addr)) == -1)
    {
        perror("sendto");
        exit(1);
    }

    printf("\n The Result Is As Follows: %s\n", arg);
    close(sockfd);
return 0;
}char arg[30];
    if ((sockfd = socket(AF_INET, SOCK_DGRAM, 0)) == -1)
    {
        perror("socket");
        exit(1);
    }
    their_addr.sin_family = AF_INET;                     // host byte order
    their_addr.sin_port = htons(SERVERPORT);             // short, network byte order
    their_addr.sin_addr.s_addr = inet_addr("127.0.0.1"); // Insert UDP Server IP Address
    // memset(their_addr.sin_zero, '\0', sizeof their_addr.sin_zero);
    printf("Enter the number 1 and num 2  : ");
    scanf("%s", arg);
    if ((numbytes = sendto(sockfd, arg, sizeof(arg), 0, (struct sockaddr *)&their_addr, sizeof their_addr)) == -1)
    {
        perror("sendto");
        exit(1);
    }

    printf("\n The Result Is As Follows: %s\n", arg);
    close(sockfd);
return 0;
}