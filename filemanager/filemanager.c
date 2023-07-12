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

WINDOW *b;
void sig_winch(int signo)
{
	struct winsize size;
	ioctl(fileno(stdout), TIOCGWINSZ, (char *) &size);
	resizeterm(size.ws_row, size.ws_col);
}
struct dirent **namelist;
void printdir2(char *path){
    clear();
    int n;
    n = scandir(path, &namelist, 0,alphasort);
    if (n < 0)
        perror("scandir");
    else {
        for (int i = 0; i < n; i++)
        {
            printw("%s\n", namelist[i]->d_name);

        }
        
    }
    printw("~~~~~~~~~~~~~~~~~~~~~~~\n%s\n",path);
    move(0,0);
}

int main(){
    initscr();
    int c;
    pid_t jopa;
    int y=1;
    int x=1;
    int size=255;
    char *path=malloc(size);
    strcpy(path,".");
    keypad(stdscr,1);
    signal(SIGWINCH, sig_winch);
    cbreak();
    curs_set(2);
    start_color();
    init_pair(1,COLOR_BLACK,COLOR_BLUE);
    bkgd(COLOR_PAIR(1));
    refresh();
    printdir2(path);
       
    while ((c=getch())!=27){
        clear();
        refresh();
        printdir2(path);
        if(c==KEY_UP){
            y--;
            wmove(stdscr,y,x);
        }
        if(c==KEY_DOWN){
            y++;
            wmove(stdscr,y,x);
        } 
        if(c=='\n'||c==KEY_ENTER){
            if (namelist[y]->d_type==DT_DIR)
            {
                size=size+strlen(namelist[y]->d_name)+1;
                path=realloc(path,size);
                strcat(path,"/");
                strcat(path,namelist[y]->d_name);
                printdir2(path);
                y=0;
                x=0;
            }
            else{
                clear();
                getch();
                
                pid_t type;
                int status;
                type=fork();
                if(type==0){
                    if(execl(namelist[y]->d_name, namelist[y]->d_name, NULL)==-1){
                        path=realloc(path,size);
                        strcat(path,"/");
                        strcat(path,namelist[y]->d_name);
                        execl("/usr/share/code/code", "code",path, NULL);
                        exit(1);
                        getch();
                    }
                    else{
                        execl(namelist[y]->d_name, namelist[y]->d_name, NULL);
                        exit(2);
                        getch();
                    }
                    
                }
                wait(&status);
            }
        }
    }
       endwin(); 
}
    

    
    
    
    
    
    
    
    
    
    
    // if(c==KEY_LEFT){
        //     x--;
        //     wmove(stdscr,y,x);
        // }
        // if(c==KEY_RIGHT){
        //     x++;
        //     wmove(stdscr,y,x);
        // }
        