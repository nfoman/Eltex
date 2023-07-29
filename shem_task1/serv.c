#include"server.h"


#define MAXCLIENT 30
int arrfd[MAXCLIENT];
int i;
void *handler(void*arg){
int *fd = (int*)arg;
char bufik[100];
int check=0;
    while(1){
    send(*fd,"echo",5,0);
    check = recv(*fd,bufik,256,0);
    if (check==-1){
        perror("error in recv thread()");
        exit(EXIT_FAILURE);
    }
    
    printf("%s\n",bufik);
    
    }

}


int main(){
    struct sockaddr_in serv;
    pthread_t clients[MAXCLIENT];
    char bufik[100];
    int arrfd[MAXCLIENT];
    serv.sin_family = AF_INET;
    serv.sin_port=htons(7000);
    serv.sin_addr.s_addr=htonl(INADDR_ANY);
    int fd;
    fd=socket(AF_INET,SOCK_STREAM,0);
    if (fd == -1) {
        perror("error in socket()");
        exit(EXIT_FAILURE);
    }
    int ret =bind(fd,(const struct sockaddr*)&serv,sizeof(serv));
    if (ret == -1) {
        perror("error in bind()");
        exit(EXIT_FAILURE);
    }
    listen(fd,100);
    for (int i=0; i < MAXCLIENT; i++)
    {  
        printf("accept...\n");
        arrfd[i]=accept(fd,NULL,NULL);
        if (arrfd[i]==-1)
        {
            perror("error in socket()");
            exit(EXIT_FAILURE);
        }
        void *arg = (void *)&arrfd[i];
        pthread_create(&clients[i],NULL,handler,arg);
        
    }
}
