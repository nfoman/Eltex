#include"server.h"


int main(){
    struct sockaddr_in serv;
    int fd;
    char bufik[100];
    serv.sin_family = AF_INET;
    serv.sin_port=htons(7000);
    serv.sin_addr.s_addr = htonl(INADDR_ANY);
    fd=socket(AF_INET,SOCK_STREAM,0);
    if (fd == -1) {
		perror("error in socket()");
		exit(EXIT_FAILURE);
	}
    int check =connect(fd,(const struct sockaddr *) &serv,sizeof(serv));
    while (1)
    {
        
        scanf("%s",bufik);
        if(check==-1){
            perror("error in connect()");
            exit(EXIT_FAILURE);
        }

        int ret = send(fd, bufik, strlen(bufik), 0);
    
        if (ret == -1) {
            perror("error in send()");
            exit(EXIT_FAILURE);
        }
    }
}