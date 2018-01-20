#include <stdio.h>
#include <arpa/inet.h>
#include <fcntl.h>
#include <unistd.h>
#include <string.h>

int main()
{
    int welcome, new_soc, fd, n;
    char buffer[1024], fname[50];
    struct sockaddr_in addr;

    welcome = socket(AF_INET, SOCK_STREAM, 0);

    addr.sin_family = AF_INET;
    addr.sin_port = htons(7891);
    addr.sin_addr.s_addr = inet_addr("127.0.0.1");

    bind(welcome, (struct sockaddr *) &addr, sizeof(addr));
    printf("\nServer is Online");
    /*  listen for connections from the socket */
    listen(welcome, 5);
    /*  accept a connection, we get a file descriptor */
    new_soc = accept(welcome, NULL, NULL);
char receive[30];
int bytes_received,i=1;
while(1)
{
bytes_received=recv(new_soc,receive,20,0);
receive[bytes_received]='\0';
if(strcmp(receive,"exit")==0)
{
close(welcome);
break;
}
else
{
if(strlen(receive)<10)
{
printf("\nFrame %d data %s received\n",i,receive);
send(new_soc,receive,strlen(receive),0);
}
else
{
send(new_soc,"negative",10,0);
}
i++;
}
}

    
    close(welcome);

    return 0;
}
