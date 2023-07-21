#include <sys/types.h>
#include <sys/ipc.h>
#include <sys/msg.h>
#include <stdio.h>
#include <malloc.h>
#include <stdlib.h>
#include <string.h>
struct msgbuf
{
    long mtype;
    char mtext[100];

};


int main(){
    
    key_t key=ftok(".",'m');
    int id =msgget(key,(IPC_CREAT | 0660));
    struct msgbuf getmessage;
    if(id!=-1){
        
        
        msgrcv(id,&getmessage,100,1,0);

    }
    printf("%s",getmessage.mtext);
    
    
    struct msgbuf sendmessage;
    sendmessage.mtype=2;
    strcpy(sendmessage.mtext,"hi");
    msgsnd(id,&sendmessage,strlen(sendmessage.mtext)+1, 0);
   
    
}