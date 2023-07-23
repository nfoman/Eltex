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
#include<pthread.h>
#include"server.h"
#define PUSTO 0
#define PIWI 1
#define SIGNAL 2
#define SIZE 1000


int main(){

    key_t key;
    int id;
    struct message *msg;
    char name[30];
    int shmid;
    shmid = shmget(SHM_ID, 1, 0);
   
    key = ftok("serv.c",'m');
    id =shmget (key,SIZE,0);
    msg = (struct message *)shmat(id, NULL, 0);
    char str[100];
    printf("Enter your name :");
    scanf("%s",name);
    strcpy(msg->name,name);
    msg->type=SIGNAL;
    while (1)
    {


        
        scanf("%s",str);
        strcat(str," - ");
        strcat(str,name);
        // strcat(msg->string," ");
        strcpy(msg->string,str);
        msg->type=PIWI;
       
       
        
        
    }




}









// #include <sys/types.h>
// #include <sys/ipc.h>
// #include <sys/shm.h>
// #include <stdio.h>
// #include <string.h>
// #include <mqueue.h>
// #include <stdlib.h>
// #include <sys/stat.h>
// #include <time.h>
// #include <unistd.h>
// #include <sys/msg.h>
// #include <malloc.h>
// #include<pthread.h>

// struct vse
// {
    
//     char mtext[100];

// };
// struct msgbuf getmessage;
// struct msgbuf get2message;
// void* rcv(){
//     struct vse sendmessage;
//     struct vse *ptr = &sendmessage;
// 	key_t vse=ftok(".",'s');
// 	int id2 =shmget(vse,10000,(IPC_CREAT | 0660));
//     ptr=shmat(id2,NULL,0);
	
// 	while (1)
// 	{

// 		strcmp(sendmessage.mtext,"check")
// 		continue;
		
// 	}
	
	
// }

// int main(){
	
	
// 	struct vse sendmessage;
//     struct vse *ptr = &sendmessage;
    
// 	int check;
// 	int login=0;
// 	int c =0;
// 	char name[100];
// 	pthread_t thread;    
//     pthread_create(&thread,NULL,rcv,NULL); 

// 	key_t vse=ftok(".",'m');
	
// 	int id2 =shmget(vse,10000,(IPC_CREAT | 0660));
//     ptr=shmat(id2,NULL,0);


// 	if (id2==-1)
// 	{
// 		perror("error in msgget()"); 
// 		exit(EXIT_FAILURE);
// 	}
	
	
// 	while (1)
// 	{
// 		if(login==0){
			
// 			sendmessage.mtype=1;
			
// 			scanf("%s",sendmessage.mtext);
// 			strcpy(name,sendmessage.mtext);
// 			strcat(sendmessage.mtext," - join");
			
			
// 			if (msgsnd(id2,&sendmessage,strlen(sendmessage.mtext)+1, 0) == -1) {
// 				perror("error in msgsnd()");
// 				exit(EXIT_FAILURE);
// 		}
// 			login=login+1;
			
// 			// bytes2=msgrcv(id,&get2message,100,2,0);
// 		}
// 		if(login==1){
// 			sendmessage.mtype=2;
// 			scanf("%s",sendmessage.mtext);
// 			strcat(sendmessage.mtext,"-");
// 			strcat(sendmessage.mtext,name);
			
// 			if (msgsnd(id2,&sendmessage,strlen(sendmessage.mtext)+1, 0) == -1) {
// 				perror("error in msgsnd()");
// 				exit(EXIT_FAILURE);
// 			}


// 		}

		


// 		// if(check==0){

// 		// 	msgrcv(id,&getmessage,100,1,0);
// 		// 	printf("%s",getmessage.mtext);
// 	}

// 	pthread_join(thread, NULL);
	


// }