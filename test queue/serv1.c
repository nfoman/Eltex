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
    
    
    key_t key = ftok(".",'m');
    int id= msgget(key,(IPC_CREAT | 0660));
    struct msgbuf sendmessage;
    if (id!=-1)
    {   
        sendmessage.mtype=1;
        strcpy(sendmessage.mtext,"hello");
        
        // int check = 
        msgsnd(id,&sendmessage,strlen(sendmessage.mtext)+1, 0);
        // if(check!=-1){
        //     msgrcv(id,(struct msgbuf *)&message.mtext,150,-1,0);
        //     printf("message %s\n",message.mtext);
        // }
    }
    struct msgbuf getmessage;
    if(id!=-1){
        
        
        msgrcv(id,&getmessage,100,2,0);

    }
    printf("%s",getmessage.mtext);    


    
    exit(EXIT_SUCCESS);
}


