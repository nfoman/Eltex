#include"server.h"



#define MAXCLIENT 30
struct sockaddr_in client;
struct protocol 
{
    int fd;
    int check;
};
struct protocol id;
void *handler(void*arg){
    int *fd = (int*)arg;
    char bufik[100];
    int check=0;
    socklen_t size=sizeof(client);
    // printf("%d %d\n",arrfd[i], i);
    while (1)
    {

        if(id.check==0){
        check = recvfrom(id.fd,bufik,255,0,(struct sockaddr*)&client,&size);
        if (check==-1){
            perror("error in recv thread()");
            exit(EXIT_FAILURE);
        }
        printf("%s\n",bufik);
        }
        if(id.check==1){
        check = recv(id.fd,bufik,100,0);
        if (check==-1){
            perror("error in recv thread()");
            exit(EXIT_FAILURE);
        }
        printf("%s\n",bufik);
        }
       
    }

}

int main(){
    struct sockaddr_in serv;
    int arrfd[MAXCLIENT];
    int i,fdudp,fdtcp;
    pthread_t clients[MAXCLIENT];
    char bufik[100];
    
    serv.sin_family = AF_INET;
    serv.sin_port=htons(7000);
    serv.sin_addr.s_addr=htonl(INADDR_ANY);
    
    fdudp=socket(AF_INET,SOCK_DGRAM,0);
    if (fdudp == -1) {
        perror("error in socket()");
        exit(EXIT_FAILURE);
    }
    int ret =bind(fdudp,(const struct sockaddr*)&serv,sizeof(serv));
    if (ret == -1) {
        perror("error in bind()");
        exit(EXIT_FAILURE);
    }
      fdtcp=socket(AF_INET,SOCK_STREAM,0);
    if (fdudp == -1) {
        perror("error in socket()");
        exit(EXIT_FAILURE);
    }
    ret =bind(fdtcp,(const struct sockaddr*)&serv,sizeof(serv));
    if (ret == -1) {
        perror("error in bind()");
        exit(EXIT_FAILURE);
    }

    listen(fdtcp,100);
    struct pollfd fd[2];
    fd[0].fd = fdudp; 
    fd[0].events = POLLIN;
    fd[1].fd = fdtcp; 
    fd[1].events = POLLIN;
    while (1)
    {
        int ret = poll(fd, 2, -1);
		if (ret == -1) {
			perror("error in poll()");
			exit(EXIT_FAILURE);
		}

        if(fd[0].revents&POLLIN){
            // printf("udp\n");
            id.fd=fdudp;
            id.check=0;
            void *arg = (void *)&fdudp;
            pthread_create(&clients[i],NULL,handler,arg);
        }
         if(fd[1].revents&POLLIN){
            printf("tcp\n");
            int newfd = accept(fdtcp, NULL, NULL);
            id.fd=newfd;
            id.check=1;
            void *arg = (void *)&fdtcp;
            pthread_create(&clients[i],NULL,handler,arg);
        }

    }

}
