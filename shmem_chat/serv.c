#include <sys/types.h>
#include <sys/ipc.h>
#include <sys/shm.h>
#include <stdio.h>
#include <string.h>
#include <mqueue.h>
#include <stdlib.h>
#include <sys/stat.h>
#include <time.h>
#include <unistd.h>
#include <sys/msg.h>
#include <malloc.h>
#include <sys/wait.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include"server.h"
#define PUSTO 0
#define PIWI 1
#define SIGNAL 2
#define SIZE 1000


int main(){
    
    key_t key;
    int id;
    // struct chat *chatik;
    
    message *msg;
    
    key = ftok("serv.c",'m');
    
    id =shmget (key,SIZE, IPC_CREAT | 0666);
    // char *arr;
    // arr=malloc(SIZE);
    msg = (struct message *)shmat(id, NULL, 0);
    
    msg->type=PUSTO;
    while (1)
    {
        if (msg->type==SIGNAL)
        {   
            printf("%s-JOIN\n",msg->name);
            msg->type=PUSTO;
        }

        if (msg->type==PIWI)
        {   
            printf("%s\n",msg->string);
            msg->type=PUSTO;
        }
        


    }
    
   


}
