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
    int pipefd[2];
    int pipefd2[2];
    char *bufik=malloc(200);

    pipe(pipefd);
    pipe(pipefd2);
    check=fork();
    if(check==0){
        close(pipefd[1]);
        read(pipefd[0],bufik,100);
        if(strcmp(bufik,"privet")==0){
            printf("%s\n",bufik);
            close(pipefd2[0]);
            free(bufik);
            strcpy(bufik,"salam brat");
            write(pipefd2[1],bufik,100);
        
        }
        
        _exit(EXIT_SUCCESS);
        

    }
    else{
        close(pipefd[0]);
        strcpy(bufik,"privet");
        write(pipefd[1],bufik,100);
        read(pipefd2[0],bufik,100);
        printf("%s\n",bufik);
        wait(NULL);                /* Ожидание потомка */
        exit(EXIT_SUCCESS);
    }
    





}