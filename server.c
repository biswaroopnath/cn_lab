#include<stdio.h>
#include<string.h>
#include<sys/types.h>
#include<sys/socket.h>
#define MYPORT 8000

struct in_addr{
    unsigned long s_addr;
};
struct sockaddr_in
{
    short int sin_family;
    unsigned short sin_port;
    struct in_addr sin_addr;
    unsigned char sin_zero[8];
};


int main(){
int sockfd ,sockfd2;
struct sockaddr_in my_addr;
sockfd=socket(AF_INET,SOCK_STREAM,0);
my_addr.sin_family = AF_INET;
my_addr.sin_port= htons(MYPORT);
my_addr.sin_addr.s_addr = inet_addr("10.0.0.1");
memset(&(my_addr.sin_zero),'\0',8);

int p = bind(sockfd,(struct sockaddr*)&my_addr,sizeof(struct sockaddr));
printf("Return of Bind functions: %d\n",p);
return 0;
}
