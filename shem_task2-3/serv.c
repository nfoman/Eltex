#include"server.h"


#define MAXCLIENT 30
int id;
struct msgbuf
{
    long mtype;
    int fd;

};
struct msgbuf clientdis;

void *handler(void*arg){
    key_t poluch=ftok(".",'m');
    int id =msgget(poluch,(IPC_CREAT | 0660));
    msgrcv(id,&clientdis,100,1,0);
    int fdpthread=clientdis.fd;
     
    while (1)
    {
        
        char bufik[100];
        int check=0;
        
        // printf("%d %d\n",arrfd[i], i);
        check = recv(fdpthread,bufik,256,0);

        if (check==-1){
            perror("error in recv thread()");
            exit(EXIT_FAILURE);
        }

        printf("%s\n",bufik);
    }
}


int main(){
    
    key_t poluch=ftok(".",'m');
    struct sockaddr_in serv;
    int i;
    pthread_t clients[MAXCLIENT];
    char bufik[100];
    serv.sin_family = AF_INET;
    serv.sin_port=htons(7000);
    serv.sin_addr.s_addr=htonl(INADDR_ANY);
    int fd;
    id =msgget(poluch,(IPC_CREAT | 0660));
    for (int i = 0; i < MAXCLIENT; i++)
    {
        pthread_create(&clients[i],NULL,handler,NULL);
    }
    
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
        clientdis.mtype=1;
        clientdis.fd=accept(fd,NULL,NULL);
        msgsnd(id,&clientdis,sizeof(clientdis.fd)+1,0); 
    }
}


