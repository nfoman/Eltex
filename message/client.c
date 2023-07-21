#include <stdio.h>
#include <string.h>
#include <mqueue.h>
#include <stdlib.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <pthread.h>
#include <time.h>
#include <unistd.h>
#include <sys/ipc.h>
#include <sys/msg.h>
#include <malloc.h>

#define MYPATH "myrandomtestik"
struct msgbuf
{
    long mtype;
    char mtext[100];

};
struct msgbuf getmessage;
struct msgbuf get2message;
void* rcv(){
	key_t poluch=ftok(".",'s');
	int id =msgget(poluch,(0666));
	
	while (1)
	{

		msgrcv(id,&getmessage,100,2,0);
		printf("%s\n",getmessage.mtext);
		continue;
		
	}
	
	
}

int main(){
	
	
	struct msgbuf sendmessage;
	int check;
	int login=0;
	int c =0;
	char name[100];
	pthread_t thread;    
    pthread_create(&thread,NULL,rcv,NULL); 

	key_t otpravka=ftok(".",'m');
	
	int id2 =msgget(otpravka,(IPC_CREAT | 0660));

	if (id2==-1)
	{
		perror("error in msgget()"); 
		exit(EXIT_FAILURE);
	}
	
	
	while (1)
	{
		if(login==0){
			
			sendmessage.mtype=1;
			
			scanf("%s",sendmessage.mtext);
			strcpy(name,sendmessage.mtext);
			strcat(sendmessage.mtext," - join");
			
			
			if (msgsnd(id2,&sendmessage,strlen(sendmessage.mtext)+1, 0) == -1) {
				perror("error in msgsnd()");
				exit(EXIT_FAILURE);
		}
			login=login+1;
			
			// bytes2=msgrcv(id,&get2message,100,2,0);
		}
		if(login==1){
			sendmessage.mtype=2;
			scanf("%s",sendmessage.mtext);
			strcat(sendmessage.mtext,"-");
			strcat(sendmessage.mtext,name);
			
			if (msgsnd(id2,&sendmessage,strlen(sendmessage.mtext)+1, 0) == -1) {
				perror("error in msgsnd()");
				exit(EXIT_FAILURE);
			}


		}

		


		// if(check==0){

		// 	msgrcv(id,&getmessage,100,1,0);
		// 	printf("%s",getmessage.mtext);
	}

	pthread_join(thread, NULL);
	


}