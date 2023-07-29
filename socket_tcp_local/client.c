#include"server.h"


int main(){
    struct sockaddr_un serv;
    int fd,new_fd;
    char bufik[100];
    serv.sun_family = AF_LOCAL;
    strcpy(serv.sun_path,FILENAME_SOCK);
    fd=socket(AF_LOCAL,SOCK_STREAM,0);
    if (fd == -1) {
		perror("error in socket()");
		exit(EXIT_FAILURE);
	}
    
    scanf("%s",bufik);
    new_fd= connect(fd,(const struct sockaddr *) &serv,sizeof(struct sockaddr_un));
    if(new_fd==-1){
        perror("error in connect()");
		exit(EXIT_FAILURE);
    }
   
    send(fd,bufik,strlen(bufik),0);
    recv(fd,bufik,100,0);
    printf("%s\n",bufik);
        

    


}