#include"server.h"


int main(){
    struct sockaddr_in serv;
    int fd,new_fd;
    char bufik[100];
    serv.sin_family = AF_INET;
    serv.sin_port=htons(7000);
    serv.sin_addr.s_addr=htonl(INADDR_ANY);
    fd=socket(AF_INET,SOCK_DGRAM,0);
    if (fd == -1) {
		perror("error in socket()");
		exit(EXIT_FAILURE);
	}
    
    
    scanf("%s",bufik);
    new_fd= connect(fd,(const struct sockaddr *) &serv,sizeof(serv));
    if(new_fd==-1){
        perror("error in connect()");
		exit(EXIT_FAILURE);
    }
    socklen_t size = sizeof(serv);
   
    if(sendto(fd, bufik, strlen(bufik), 0, (struct sockaddr *)&serv, sizeof(serv))==-1){
        perror("sendto error()");
		exit(EXIT_FAILURE);
    }
    if(recvfrom(fd,bufik,100,0,(struct sockaddr*)&serv,&size)==-1){
        perror("sendto error()");
        exit(EXIT_FAILURE);
    }
       
    printf("%s\n", bufik);   

    


}