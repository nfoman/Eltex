#include <fcntl.h> //для open()
#include <unistd.h> //для read(), sync()
#include <stdio.h>
#include <string.h>
#include <malloc.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <termios.h>
#include <sys/ioctl.h>
#include <signal.h>
#include <stdlib.h>
#include <ncurses.h>



WINDOW *b;
WINDOW *bb;
void sig_winch(int signo)
{
	struct winsize size;
	ioctl(fileno(stdout), TIOCGWINSZ, (char *) &size);
	resizeterm(size.ws_row, size.ws_col);
}

struct stat buf; 

void readfile(int fd,char *str,long int bytes){
    
    
    wprintw(bb,"%ld",bytes);
    lseek(fd,1,SEEK_SET);
    str=realloc(str,(bytes));
    read(fd,str,bytes);
    sync();
    for (int i = 0; i < bytes-1; i++)
    {
        wprintw(bb,"%c",str[i]);
        wrefresh;
            
    }
    free(str);
    
}

void writefile(int fd,char *str,long int bytes){
    signal(SIGWINCH, sig_winch);
    wprintw(bb,"\n");
    wrefresh(bb);
    wgetnstr(bb,str,50);
    lseek(fd,1,SEEK_END);
    str=realloc(str,strlen(str));
    write(fd,str,strlen(str));
    sync();
    free(str);
}


int main(){
    
    int a;
    char namefile[50];
    int fd;
    long int bytes;
    initscr();
    signal(SIGWINCH, sig_winch);
    cbreak();
    curs_set(TRUE);
    start_color();
    init_pair(1,COLOR_BLACK,COLOR_BLUE);
    refresh();
    b = newwin(40, 100, 1, 15);
    box(b,'|','-');
    wbkgd(b, COLOR_PAIR(1));
    wrefresh(b);
    bb=derwin(b, 30, 90, 1, 1);
    wattron(bb,COLOR_PAIR(1));
    wprintw(bb,"enter namefile: ");
    wrefresh(bb);
    wgetnstr(bb,namefile,50);
    wrefresh(bb);
    keypad(stdscr, true); 
    fd=open(namefile,O_RDWR);
    
    if (fd!=-1){
        while(a!=3){
            char *str=malloc(bytes+20);
            wprintw(bb,"\nup-Write, down-read, left-close: ");
            wrefresh(bb);
            switch (getch())
            {
                case KEY_UP:
                    stat("./text.txt", &buf);
                    bytes = buf.st_size;
                    writefile(fd,str,bytes);
                    break;
                case KEY_DOWN:
                    stat("./text.txt", &buf);
                    bytes = buf.st_size;
                    readfile(fd,str,bytes);
                    break;
                case KEY_LEFT:
                    close(fd);
                    endwin();
	                exit(EXIT_SUCCESS);
                    break;
                    
                default:
                    wprintw(bb,"Try more\n");
                    break;
            }
        }   
    }
    else{
        printf("ERORR: can't open file text.txt\n");
    }
}