#include"server.h"




int main(){
    struct sockaddr_un serv;
    char bufik[100];
    serv.sun_family = AF_LOCAL;
    strcpy(serv.sun_path,FILENAME_SOCK);
    int fd,new_fd;
    fd=socket(AF_LOCAL,SOCK_STREAM,0);
    if (fd == -1) {
		perror("error in socket()");
		exit(EXIT_FAILURE);
	}
    int ret =bind(fd,(const struct sockaddr*)&serv,sizeof(struct sockaddr_un));
    if (ret == -1) {
		perror("error in bind()");
		exit(EXIT_FAILURE);
	}
    listen(fd,100);
    new_fd=accept(fd,NULL,NULL);
    if (new_fd == -1) {
		perror("error in accept()");
		exit(EXIT_FAILURE);
	}
   
    recv(new_fd,bufik,100,0);
    printf("%s\n",bufik);
    printf("piwi sam\n");
    scanf("%s",bufik);
    send(new_fd,bufik,strlen(bufik),0);
        

   
    


}