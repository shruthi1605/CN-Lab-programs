#include <stdio.h>
#include <arpa/inet.h>
#include <fcntl.h>
#include <unistd.h>
#include <string.h>

int main()
{
    int soc, n;
    char buffer[1024], fname[50];
    struct sockaddr_in addr;

    /*  socket creates an endpoint for communication and returns a file descriptor */
    soc = socket(AF_INET, SOCK_STREAM, 0);
	bzero((char*)&addr,sizeof(addr));
    /*
     * sockaddr_in is used for ip manipulation
     * we define the port and IP for the connection.
     */
    addr.sin_family = AF_INET;
    addr.sin_port = htons(7891);
    addr.sin_addr.s_addr = inet_addr("127.0.0.1");

	

    /*  keep trying to esatablish connection with server */
    while(connect(soc, (struct sockaddr *) &addr, sizeof(addr))) ;
    printf("\nClient is connected to Server");
char data[1024],fr[30]=" ";
int i=1;
    while(strcmp(fr,"exit")!=0)
{
printf("Enter Data Frame %d:(Enter exit for End):",i);
scanf("%s",fr);
send(soc,fr,strlen(fr),0);  
bzero(data,1024);
recv(soc,data,1024,0);
if(strlen(data)!=0)
{

printf("I got an acknowledgment : %s\n",data);
}
i++;
}
    
close(soc);
    return 0;
}
