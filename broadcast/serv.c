#include"server.h"




int main(){
    struct sockaddr_in serv;
    char bufik[100];
    serv.sin_family = AF_INET;
    serv.sin_port=htons(7000);
    int fd;
    fd=socket(AF_INET,SOCK_DGRAM,0);
    if (fd == -1) {
        perror("error in socket()");
        exit(EXIT_FAILURE);
    }
    inet_pton(AF_INET, "255.255.255.255", &(serv.sin_addr));
    int ret =bind(fd,(const struct sockaddr*)&serv,sizeof(serv));
    if (ret == -1) {
        perror("error in bind()");
        exit(EXIT_FAILURE);
    }
    socklen_t size=sizeof(serv);


    recvfrom(fd,bufik,100,0,(struct sockaddr*)&serv,&size);
    printf("%s\n", bufik);
   
    


}