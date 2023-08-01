#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/ipc.h>
#include <sys/sem.h>
#include <sys/shm.h>
#include <sys/stat.h>
#include <sys/types.h>
#include <sys/socket.h>
#include <sys/un.h>
#include <arpa/inet.h>
#include <netinet/in.h>

int main(){
    int a =0;
    char buf[1000];
    struct sockaddr_in serv;
    serv.sin_family = AF_INET;
    serv.sin_port=htons(7000);
    serv.sin_addr.s_addr=htonl(INADDR_ANY);
    int fd=socket(AF_INET,SOCK_RAW,IPPROTO_UDP);
    
    while (1)
    {   
        recvfrom(fd,buf,1000,0,(struct sockaddr *)&serv,0);
        a++;
        printf("%d\n",a);

    }
    
}