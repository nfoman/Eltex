#include <fcntl.h>
#include <sys/stat.h>
#include <termios.h>
#include <sys/ioctl.h> 
#include <signal.h> /
#include <stdlib.h>
#include <sys/types.h>
#include <malloc.h>
#include <sys/dir.h>
#include<sys/wait.h>
#include <sys/types.h>
#include <stdio.h>
#include <unistd.h>
#include <string.h>




int main(){
    pid_t check;
    char *path=malloc(500);
    char *bufik=malloc(200);
    strcpy(path,"testik");
    mkfifo(path,0400|0200);
    int fd=open(path,O_RDWR);
    free(path);
    strcpy(path,"testik2");
    mkfifo(path,0400|0200);
    int fb=open(path,O_RDWR);
    check=fork();
    
    
    if(check==0){
        
        read(fd,bufik,100); 
        printf("%s\n",bufik);
        free(bufik);
        strcpy(bufik,"я сына");
        write(fb,bufik,100);
        _exit(EXIT_SUCCESS);
        
       
    }
    else{

        strcpy(bufik,"я папа ты кто?");
        write(fd,bufik,100);
        read(fb,bufik,100);
        printf("%s\n",bufik);
        free(bufik);
        wait(NULL);                /* Ожидание потомка */
        exit(EXIT_SUCCESS);
    }
}