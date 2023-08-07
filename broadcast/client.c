#include"server.h"


int main(){
    struct sockaddr_in serv;
    int fd;
    int flag =1;    
    char bufik[100];
    serv.sin_family = AF_INET;
    serv.sin_port=htons(7000);
    inet_pton(AF_INET, "255.255.255.255", &(serv.sin_addr));
    fd=socket(AF_INET,SOCK_DGRAM,0);
    if (fd == -1) {
		perror("error in socket()");
		exit(EXIT_FAILURE);
	}
    setsockopt(fd,SOL_SOCKET,SO_BROADCAST,&flag,sizeof(flag));
    
    scanf("%s",bufik);
    socklen_t size = sizeof(serv);
   
    if(sendto(fd, bufik, strlen(bufik), 0, (struct sockaddr *)&serv, sizeof(serv))==-1){
        perror("sendto error()");
		exit(EXIT_FAILURE);
    }
   


    


}