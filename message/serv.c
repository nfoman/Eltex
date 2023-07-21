#include <stdio.h>
#include <string.h>
#include <mqueue.h>
#include <stdlib.h>
#include <sys/types.h>
#include <sys/stat.h>
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


int main(){
	int bytes;
	int clientbase=0;
	char namelist[10][30];
	struct msgbuf getmessage;
	struct msgbuf chatmessage;
	key_t poluch=ftok(".",'m');
	key_t otpravka=ftok(".",'s');
	int id =msgget(poluch,(IPC_CREAT | 0660));
	int id2 =msgget(otpravka,(IPC_CREAT | 0660));
	while (1)
	{	if(clientbase<2){
		bytes=msgrcv(id,&getmessage,100,1,0);
	}
		
		
		if(bytes>0){
			
			// namelist=realloc(namelist,size*clientbase);
			getmessage.mtype=1;
			strcpy(namelist[clientbase],getmessage.mtext);			
			
			// strcpy(get2message.mtext,namelist[clientbase-1]);
			msgsnd(id2,&getmessage,strlen(getmessage.mtext)+1, 0);
			clientbase++;

		}
		
		msgrcv(id,&chatmessage,100,2,0);
		chatmessage.mtype=2;
		msgsnd(id2,&chatmessage,strlen(chatmessage.mtext)+1, 0);

	}

}