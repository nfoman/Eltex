#include"server.h"
#define SIZE 200



int main(){
    struct sockaddr_in serv,client;
    char packet[SIZE];
    serv.sin_family = AF_INET;
    serv.sin_port=htons(PORTIK);
    int fd;
    serv.sin_addr.s_addr=htonl(INADDR_ANY);
    fd=socket(AF_INET,SOCK_DGRAM,IPPROTO_UDP);
    if (fd == -1) {
        perror("error in socket()");
        exit(EXIT_FAILURE);
    }
    int ret =bind(fd,(const struct sockaddr*)&serv,sizeof(serv));
    if (ret == -1) {
        perror("error in bind()");
        exit(EXIT_FAILURE);
    }
    socklen_t size=sizeof(struct sockaddr_in);

    while (1)
    {
       recvfrom(fd,packet,SIZE,0,(struct sockaddr*)&client,&size);
    printf("client ip = %s, port = %d\n", 
	inet_ntoa(client.sin_addr), ntohs(client.sin_port));
	printf("bytes: %s\n",packet);
    strcat(packet," echo\0");
    printf("%d\n",htons(serv.sin_port));
    sendto(fd,packet,strlen(packet),0,(struct sockaddr*)&client,size);
    }
    
    
        
    
    
    


   
    


}