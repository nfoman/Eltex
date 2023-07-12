#include <termios.h>
#include <sys/ioctl.h> //для обработки сигналов
#include <signal.h> //для соединения сигнала и функции-обработчика
#include <stdlib.h>
#include <ncurses.h> //ncurses
#include <dirent.h> //для просмотра каталогов и файлов
#include <string.h>
#include <sys/types.h>
#include <malloc.h>
#include <sys/dir.h>
#include<unistd.h>
#include<sys/wait.h>

#define _BSD_SOURCE  1
#define _SVID_SOURCE 1
#define _GNU_SOURCE

int main()
{
    pid_t check;
    pid_t checkpapa2;
    int status;
    check=fork();
    if(check==0){
        printf("PIDchild1 %d Myfather %d\n",getpid(),getppid());
        sync();
        checkpapa2=fork();
        if(checkpapa2==0){
            printf("PIDchild2 %d Myfather %d\n",getpid(),getppid());
            exit(2);
        }
        checkpapa2=fork();
        wait(&status);
        // printf("status = %d\n",WEXITSTATUS(status2));
        if(checkpapa2==0){
            printf("PIDchild3 %d Myfather %d\n",getpid(),getppid());
            exit(3);
        }
        wait(&status);
        // printf("status = %d\n",WEXITSTATUS(status2));
        exit(1);
    }
        else{
            printf("PAPAPID0: %d\n",getpid());
            wait(&status);
            // printf("status = %d\n",WEXITSTATUS(status));
            check=fork();
            if(check==0){
                printf("PIDchild4 %d Myfather %d\n",getpid(),getppid());
                check=fork();
                if(check==0){
                    printf("PIDchild5 %d Myfather %d\n",getpid(),getppid());
                    exit(5);
                }
                wait(&status);
                // printf("status = %d\n",WEXITSTATUS(status2));
                exit(4);
            }
            wait(&status);
            
            // printf("status = %d\n",WEXITSTATUS(status));
        }
}
// checkpapa2=fork();
// if(checkpapa2==0||check==0){
//     printf("PIDchild3: %d ",getpid());
//     sync();
//     exit(7);
   
    
// }
// if(checkpapa2!=0){
//     printf("PAPAPID4: %d ",getpid());
//     wait(&status2);
//     printf("status = %d\n",WEXITSTATUS(status2));

// }


