#include<sys/types.h>
#include<sys/socket.h>
#include<netinet/in.h>
#include<arpa/inet.h>
#include<netdb.h>
#include<stdio.h>
#include<string.h>
#include <stdlib.h>
void error(char *);
int main(int argc, char *argv[])
{
int sock, length, n;
struct sockaddr_in server, from;
struct hostent *hp;
char buffer[256];

sock= socket(AF_INET, SOCK_DGRAM, 0);

server.sin_family=AF_INET;

server.sin_addr.s_addr = inet_addr("127.0.0.1");
server.sin_port = htons(7842);

length=sizeof(struct sockaddr_in);
printf("Please enter the message: ");
bzero(buffer,256);
fgets(buffer,255,stdin);

n=sendto(sock,buffer,strlen(buffer),0,(struct sockaddr *)&server,length);
if (n < 0)
{
error("Sendto");
}
n = recvfrom(sock,buffer,256,0,(struct sockaddr *)&from, &length);
if (n < 0)
{
error("recvfrom");
}
write(1,"Got an ack: ",12);
write(1,buffer,n);
}
void error(char *msg)
{
perror(msg);
exit(0);
}
